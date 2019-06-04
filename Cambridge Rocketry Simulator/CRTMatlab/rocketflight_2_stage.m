%## Copyright (C) 2008 S.Box
%## 
%## This program is free software; you can redistribute it and/or modify
%## it under the terms of the GNU General Public License as published by
%## the Free Software Foundation; either version 2 of the License, or
%## (at your option) any later version.
%## 
%## This program is distributed in the hope that it will be useful,
%## but WITHOUT ANY WARRANTY; without even the implied warranty of
%## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
%## GNU General Public License for more details.
%## 
%## You should have received a copy of the GNU General Public License
%## along with this program; if not, write to the Free Software
%## Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA

%## rocketflight_2_stage.m

%## Author: S.Box
%## Created: 2008-05-27


function varargout=rocketflight_2_stage(varargin);

warning off;
tic

%Input tables for the total rocket
INTAB_TR1=varargin{1}{1};
INTAB_TR2=varargin{1}{2};
INTAB_TR3=varargin{1}{3};
landa_TR=varargin{1}{4};

%Input tables for the booster stage
INTAB_BS1=varargin{2}{1};
INTAB_BS2=varargin{2}{2};
INTAB_BS3=varargin{2}{3};
landa_BS=varargin{2}{4};
paratab_BS=varargin{2}{5};

%Input tables for the Upper stage
INTAB_US1=varargin{3}{1};
INTAB_US2=varargin{3}{2};
INTAB_US3=varargin{3}{3};
landa_US=varargin{3}{4};
paratab_US=varargin{3}{5};

INTAB4=varargin{4};

tsep=varargin{5};
ig_delay=varargin{6};
altpd1=varargin{7};
altpd2=varargin{8};
RL=varargin{9}; %Launch rail length (m);
Ra=varargin{10}; %Launch rail angle(degrees) from vetical 0<Ra<90;
Rbearing=varargin{11}; %Launch rail bearing (degrees) from north 0<Rbearing<360;

label='nofail';

if nargin==12
label=varargin{12};
end

mu=1.8e-5; % kinematic viscosity of air (Ns/m^2);
G=6.6742E-11;% Gravitational constant

ttspan_TR=[0 tsep];
ttspan_BS=[0 10000];
ttspan_US=[0 10000];
ttspan_de=[0 10000];


Xt=[0;0;0];%Rocket initial position (m);

YA0=[1;0;0];%Reference Yaw axis
PA0=[0;1;0];%Reference Pitch axis
RA0=[0;0;1];%Reference Roll axis



%INITIAL QUATERNION************************************************
Ra=Ra*pi/180;
Raxb=Rbearing-90;
Rax=bearing_to_vector(Raxb);


Q1=[cos(Ra/2) sin(Ra/2)*Rax(1) sin(Ra/2)*Rax(2) sin(Ra/2)*Rax(3)];

%Runge Kutta integration of rocket equations of motion*************

%Initial stage: lift off to separation

z_TR0=[Xt(1) Xt(2) Xt(3) Q1(1) Q1(2) Q1(3) Q1(4) 0 0 0 0 0 0];

[tt_TR,z_TR]=ascentcalc(ttspan_TR,z_TR0,YA0,PA0,RA0,INTAB_TR1,INTAB_TR2,INTAB_TR3,INTAB4,landa_TR(2),RL,Ra,mu,landa_TR(1),G,label);

%Obtain the final velocity vectors
M_TRe=INTAB_TR1(end,3);
Ut=z_TR(end,8:10)./M_TRe;

qt=z_TR(end,4:7);
Rt=quaternion_to_matrix(qt);

Ixxi=INTAB_TR1(end,4);
Iyyi=INTAB_TR1(end,5);
Izzi=INTAB_TR1(end,6);
Ixyi=INTAB_TR1(end,7);
Ixzi=INTAB_TR1(end,8);
Iyzi=INTAB_TR1(end,9);

Lt_TR=z_TR(end,11:13)';

Ibody_TR=[Ixxi Ixyi Ixzi;Ixyi Iyyi Iyzi;Ixzi Iyzi Izzi];%Inertia tensor

Ibodyinv_TR=inv(Ibody_TR);
Itinv_TR=Rt*Ibodyinv_TR*Rt';
omegat=Itinv_TR*Lt_TR;%Angular velocity vector


%Upper stage flight to apogee

%Calculate initial momentum vectors.
M_US=INTAB_US1(1,3);
P_US=Ut*M_US;
Ibody_US=diag(INTAB_US1(1,4:6));
Ibodyinv_US=inv(Ibody_US);
Itinv_US=Rt*Ibodyinv_US*Rt';

L_US=inv(Itinv_US)*omegat;

z_US0=[z_TR(end,1:7),P_US(1),P_US(2),P_US(3),L_US(1),L_US(2),L_US(3)];

[tt_US,z_US]=ascentcalc(ttspan_US,z_US0,YA0,PA0,RA0,INTAB_US1,INTAB_US2,INTAB_US3,INTAB4,landa_US(2),RL,Ra,mu,landa_US(1),G,label,ig_delay);

%Upper stage descent;

z_USD0=[z_US(end,1) z_US(end,2) z_US(end,3) z_US(end,8) z_US(end,9) z_US(end,10)];

[tt_USD,z_USD]=descentcalc(ttspan_de,z_USD0,INTAB4,INTAB_US1,paratab_US,altpd1,G);

%Booster stage flight to apogee
M_BS=INTAB_BS1(1,3);
P_BS=Ut*M_BS;


Ibody_BS=diag(INTAB_BS1(1,4:6));
Ibodyinv_BS=inv(Ibody_BS);
Itinv_BS=Rt*Ibodyinv_BS*Rt';

L_BS=inv(Itinv_BS)*omegat;

z_BS0=[z_TR(end,1:7),P_BS(1),P_BS(2),P_BS(3),L_BS(1),L_BS(2),L_BS(3)];

[tt_BS,z_BS]=ascentcalc(ttspan_BS,z_BS0,YA0,PA0,RA0,INTAB_BS1,INTAB_BS2,INTAB_BS3,INTAB4,landa_BS(2),RL,Ra,mu,landa_BS(1),G,label);

%Booster stage descent;
z_BSD0=[z_BS(end,1) z_BS(end,2) z_BS(end,3) z_BS(end,8) z_BS(end,9) z_BS(end,10)];

[tt_BSD,z_BSD]=descentcalc(ttspan_de,z_BSD0,INTAB4,INTAB_BS1,paratab_BS,altpd2,G);



%find apogees and landings
[Aval_US Aht_US]=max(z_US(:,3));
[Aval_BS Aht_BS]=max(z_BS(:,3));
apogee_US(1:3)=z_US(Aht_US,1:3);
apogee_BS(1:3)=z_BS(Aht_BS,1:3);

Landing_US(1)=interp1(z_USD(:,3),z_USD(:,1),0.2,'linear','extrap');
Landing_US(2)=interp1(z_USD(:,3),z_USD(:,2),0.2,'linear','extrap');

Landing_BS(1)=interp1(z_BSD(:,3),z_BSD(:,1),0.2,'linear','extrap');
Landing_BS(2)=interp1(z_BSD(:,3),z_BSD(:,2),0.2,'linear','extrap');

%Plot flight paths

sz_US=size(z_US);
sz_USD=size(z_USD);
zp_US=zeros((sz_US(1)+sz_USD(1)),3);
zp_US(1:sz_US(1),1:3)=z_US(:,1:3);
zp_US((sz_US(1)+1):(sz_US(1)+sz_USD(1)),1:3)=z_USD(:,1:3);

sz_BS=size(z_BS);
sz_BSD=size(z_BSD);
zp_BS=zeros((sz_BS(1)+sz_BSD(1)),3);
zp_BS(1:sz_BS(1),1:3)=z_BS(:,1:3);
zp_BS((sz_BS(1)+1):(sz_BS(1)+sz_BSD(1)),1:3)=z_BSD(:,1:3);

figure;
hold on;
plot3(z_TR(:,1),z_TR(:,2),z_TR(:,3),'g');
plot3(zp_US(:,1),zp_US(:,2),zp_US(:,3),'b');
plot3(zp_BS(:,1),zp_BS(:,2),zp_BS(:,3),'r');
set(gca,'zlim',[0 (max(zp_US(:,3))+100)]);
axis equal;
xlabel('East (m)');
ylabel('North (m)');
zlabel('Altitude (m)');
set(gca,'XGrid','on') 
set(gca,'YGrid','on') 
set(gca,'ZGrid','on') 

Asc_TR=[tt_TR,z_TR];
Asc_US=[tt_US,z_US];
Asc_BS=[tt_BS,z_BS];
Des_US=[tt_USD,z_USD];
Des_BS=[tt_BSD,z_BSD];

varargout={Asc_TR,Asc_BS,Asc_US,Des_BS,Des_US,apogee_BS,apogee_US,Landing_BS,Landing_US};

%%Output Display%%%%
disp(sprintf('\n\nCambridge Rocketry Simulator\n'))
disp(sprintf('Simulation complete at: %s',datestr(now)))
toc
disp(sprintf('\n**Upper stage data**:'))
disp(sprintf('Apogee data:'))
disp(sprintf('Apogee reached %d seconds after launch',(tt_TR(end)+tt_US(end))))
if (apogee_US(1)<0)
  Easting='West';
else
  Easting='East';
end

if (apogee_US(2)<0)
  Northing='South';
else
  Northing='North';
end
disp(sprintf(['Apogee location is %dm ',Easting,' and %dm ',Northing,' of launch location'],abs(apogee_US(1)),abs(apogee_US(2))))
disp(sprintf('Apogee altitude is %dm\n',apogee_US(3)))
disp(sprintf('Landing data:'))
disp(sprintf('Landing occurred %d seconds after launch',(tt_TR(end)+tt_US(end)+tt_USD(end))))
if (Landing_US(1)<0)
  Easting='West';
else
  Easting='East';
end

if (Landing_US(2)<0)
  Northing='South';
else
  Northing='North';
end
disp(sprintf(['Landing location is %dm ',Easting,' and %dm ',Northing,' of launch location\n'],abs(Landing_US(1)),abs(Landing_US(2))))

disp(sprintf('\n**Booster stage data**:'))
disp(sprintf('\nApogee data:'))
disp(sprintf('Apogee reached %d seconds after launch',(tt_TR(end)+tt_BS(end))))
if (apogee_BS(1)<0)
  Easting='West';
else
  Easting='East';
end

if (apogee_BS(2)<0)
  Northing='South';
else
  Northing='North';
end
disp(sprintf(['Apogee location is %dm ',Easting,' and %dm ',Northing,' of launch location'],abs(apogee_BS(1)),abs(apogee_BS(2))))
disp(sprintf('Apogee altitude is %dm\n',apogee_BS(3)))
disp(sprintf('Landing data:'))
disp(sprintf('Landing occurred %d seconds after launch',(tt_TR(end)+tt_BS(end)+tt_BSD(end))))
if (Landing_BS(1)<0)
  Easting='West';
else
  Easting='East';
end

if (Landing_BS(2)<0)
  Northing='South';
else
  Northing='North';
end
disp(sprintf(['Landing location is %dm ',Easting,' and %dm ',Northing,' of launch location\n'],abs(Landing_BS(1)),abs(Landing_BS(2))))
%%%%%%%%%%%%%%%%%%%%

