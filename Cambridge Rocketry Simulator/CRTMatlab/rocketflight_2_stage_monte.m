%## Copyright (C) 2008 S. Box
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

%## rocketflight_2_stage_monte.m

%## Author: S. Box
%## Created: 2008-05-08

function varargout=rocketflight_2_stage_monte(varargin);
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

noi=varargin{12};
argmin=12;
label='nofail';
if nargin>argmin;
    if varargin{13}=='ballisticfailure';
        label=varargin{13};
        argmin=13;
    end
end

%DEFAULT COEFFICIENTS FOR MONTE CARLO SOLUTION
Cdms=0.2;% Rand multiplier for drag coeficient;
Cpms=0.1;% Rand multiplier for centre of pressure
CNms=0.1;% Rand multiplier for Normal force coefficient;
Cdpms=0.1;% Rand multiplier for parachute drag coeficient;
Cddms=0.1;% Rand multiplier for drogue drag coefficient;
MU=zeros(15,1);%Mean values for wind profile machine learning;
load SIGMA;%Covariance for wind profile machine learning;

%LOOK FOR USER SPECIFIED MONTE CARLO COEFFICIENTS**********************
if nargin==argmin;
elseif nargin>argmin;
    exarg=nargin-argmin;
    if rem(exarg,2)~=0;
        error('invalid number of arguments');
    end
    for i=1:exarg/2;
        j=i*2;
        label2=varargin{argmin+j-1};

        switch label2

            case 'CDmult'
                Cdms=varargin{argmin+j};
            case 'CPmult'
                Cpms=varargin{argmin+j};
            case 'CNmult'
                CNms=varargin{argmin+j};
            case 'CDPmult'
                Cdpms=varargin{argmin+j}
            case 'CDDmult'
                Cddms=varargin{argmin+j}
            case 'MU'
                MU=varargin{argmin+j}
            case 'SIGMA'
                SIGMA=varargin{argmin+j}
        end
    end
end
%END OF INPUTS***********************************************************

%SPECIFY SOME CONSTANTS AT ROCKETS INITIAL POSITION**********************
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


%RUN THE CODE FOR THE MEAN POSITION*************************************
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

qt=z_TR(end,4:7);
Rt=quaternion_to_matrix(qt);

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



z_TRbig{1}=z_TR;
zp_USbig{1}=zp_US;
zp_BSbig{1}=zp_BS;

Ascbig_TR{1}=[tt_TR,z_TR];
Ascbig_BS{1}=[tt_BS,z_BS];
Ascbig_US{1}=[tt_US,z_US];

Desbig_BS{1}=[tt_BSD,z_BSD];
Desbig_US{1}=[tt_USD,z_USD];


%%RUN THE CODE USING MONTE CARLO******************************************
INTAB_TR1pc=INTAB_TR1;
INTAB_TR2pc=INTAB_TR2;
INTAB_TR3pc=INTAB_TR3;

INTAB_US1pc=INTAB_US1;
INTAB_US2pc=INTAB_US2;
INTAB_US3pc=INTAB_US3;
paratab_USpc=paratab_US;

INTAB_BS1pc=INTAB_BS1;
INTAB_BS2pc=INTAB_BS2;
INTAB_BS3pc=INTAB_BS3;
paratab_BSpc=paratab_BS;

INTAB4pc=INTAB4;


H_scale=[0,10:100:12000];
location=[0:1000:13000]; %Scaling for the basis functions
scale=1000;

L=length(location)+1;
J=length(H_scale);
%epsilon=1E-2;
%Build Basis function matrix.
for i=1:L;
    for j=1:J;
        if i==1
            PHI(j,i)=1;
        else
            PHI(j,i)=exp(-(H_scale(j)-location(i-1)).^2./(2*scale^2));
        end
    end
end

for monte=2:noi;

    %CREATE VARIABLES FOR THIS RUN***************************************

    Cdm=abs((randn*Cdms)+1);
    Cpm=(randn*Cpms);
    CNm=(randn*CNms)+1;
    Cdpm=(randn*Cdpms)+1;
    Cddm=(randn*Cddms)+1;

    %Machine learning bit with weather data
    Wx=gsamp(MU,SIGMA,1);
    Wy=gsamp(MU,SIGMA,1);

    for j=1:J;
        X(j)=sum(Wx*PHI(j,:)');
        Y(j)=sum(Wy*PHI(j,:)');
    end

    Wdat=INTAB4pc(:,1:3);
    Xdw=interp1(H_scale,X,Wdat(:,1),'linear','extrap');
    Ydw=interp1(H_scale,Y,Wdat(:,1),'linear','extrap');

    %APPLY VARIABLES TO THE INPUT TABLES

    sit_TR2=size(INTAB_TR2pc);
    INTAB_TR2(2:sit_TR2(1),2:sit_TR2(2))=INTAB_TR2pc(2:sit_TR2(1),2:sit_TR2(2))*Cdm;
    sit_US2=size(INTAB_US2pc);
    INTAB_US2(2:sit_US2(1),2:sit_US2(2))=INTAB_US2pc(2:sit_US2(1),2:sit_US2(2))*Cdm;
    sit_BS2=size(INTAB_BS2pc);
    INTAB_BS2(2:sit_BS2(1),2:sit_BS2(2))=INTAB_BS2pc(2:sit_BS2(1),2:sit_BS2(2))*Cdm;

    INTAB_TR3(:,1)=INTAB_TR3pc(:,1)*CNm;
    INTAB_US3(:,1)=INTAB_US3pc(:,1)*CNm;
    INTAB_BS3(:,1)=INTAB_BS3pc(:,1)*CNm;

    INTAB_TR3(:,2)=INTAB_TR3pc(:,2)+Cpm;
    INTAB_US3(:,2)=INTAB_US3pc(:,2)+Cpm;
    INTAB_BS3(:,2)=INTAB_BS3pc(:,2)+Cpm;

    INTAB4(:,2)=INTAB4pc(:,2)+Xdw;
    INTAB4(:,3)=INTAB4pc(:,3)+Ydw;


    paratab_US(2)=paratab_USpc(2)*Cddm;
    if length(paratab_US)==4;
        paratab_US(4)=paratab_USpc(4)*Cdpm;
    end

    paratab_BS(2)=paratab_BSpc(2)*Cddm;
    if length(paratab_BS)==4;
        paratab_BS(4)=paratab_BSpc(4)*Cdpm;
    end

    %RUN THE CODE WITH THE NEW INPUT TABLES******************************


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

    qt=z_TR(end,4:7);
    Rt=quaternion_to_matrix(qt);

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
    apogee_US(monte,1:3)=z_US(Aht_US,1:3);
    apogee_BS(monte,1:3)=z_BS(Aht_BS,1:3);

    Landing_US(monte,1)=interp1(z_USD(:,3),z_USD(:,1),0.2,'linear','extrap');
    Landing_US(monte,2)=interp1(z_USD(:,3),z_USD(:,2),0.2,'linear','extrap');

    Landing_BS(monte,1)=interp1(z_BSD(:,3),z_BSD(:,1),0.2,'linear','extrap');
    Landing_BS(monte,2)=interp1(z_BSD(:,3),z_BSD(:,2),0.2,'linear','extrap');

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

    Ascbig_TR{monte}=[tt_TR,z_TR];
    Ascbig_BS{monte}=[tt_BS,z_BS];
    Ascbig_US{monte}=[tt_US,z_US];

    Desbig_BS{monte}=[tt_BSD,z_BSD];
    Desbig_US{monte}=[tt_USD,z_USD];
    
    monte


end
figure
hold on
gauss_ellipse(mean(Landing_US),cov(Landing_US),1,'r');
gauss_ellipse(mean(Landing_US),cov(Landing_US),2,'g');
gauss_ellipse(mean(Landing_BS),cov(Landing_BS),1,'c');
gauss_ellipse(mean(Landing_BS),cov(Landing_BS),2,'y');
plot3(z_TRbig{1}(:,1),z_TRbig{1}(:,2),z_TRbig{1}(:,3),'g');
plot3(zp_USbig{1}(:,1),zp_USbig{1}(:,2),zp_USbig{1}(:,3),'b');
plot3(zp_BSbig{1}(:,1),zp_BSbig{1}(:,2),zp_BSbig{1}(:,3),'r');
set(gca,'zlim',[0 (max(zp_USbig{1}(:,3))+100)]);
axis equal;
xlabel('East (m)');
ylabel('North (m)');
zlabel('Altitude (m)');
title('Mean flight path and Gaussian uncertainty in the landing position (1 & 2 standard deviations) ');
set(gca,'XGrid','on')
set(gca,'YGrid','on')
set(gca,'ZGrid','on')

figure
hold on
gauss_ellipse(mean(Landing_US),cov(Landing_US),1,'r');
gauss_ellipse(mean(Landing_US),cov(Landing_US),2,'g');
gauss_ellipse(mean(Landing_BS),cov(Landing_BS),1,'c');
gauss_ellipse(mean(Landing_BS),cov(Landing_BS),2,'y');
plot(0,0,'rx',Landing_US(:,1),Landing_US(:,2),'b.',Landing_BS(:,1),Landing_BS(:,2),'r.');
axis equal
xlabel('East (m)');
ylabel('North (m)');
title('Splash pattern and Gaussian elipses showing 1 and 2 standard deviations probability');

figure
plot3(0,0,0,'rx',apogee_US(:,1),apogee_US(:,2),apogee_US(:,3),'b.',apogee_BS(:,1),apogee_BS(:,2),apogee_BS(:,3),'r.');
set(gca,'zlim',[0 (max(apogee_US(:,3))+100)]);
axis equal;
xlabel('East (m)');
ylabel('North (m)');
zlabel('Altitude (m)');
set(gca,'XGrid','on')
set(gca,'YGrid','on')
set(gca,'ZGrid','on')
title('apogee scatter pattern');

varargout={Ascbig_TR,Ascbig_BS,Ascbig_US,Desbig_BS,Desbig_US,apogee_BS,apogee_US,Landing_BS,Landing_US};

%%Output Display%%%%
disp(sprintf('\n\nCambridge Rocketry Simulator\n'))
disp(sprintf('Simulation complete at: %s',datestr(now)))
toc
disp(sprintf('\n**Mean upper stage data**:'))
disp(sprintf('Apogee data:'))
disp(sprintf('Apogee reached %d seconds after launch',(Ascbig_TR{1}(:,1)(end)+Ascbig_US{1}(:,1)(end))))
if (apogee_US(1,1)<0)
  Easting='West';
else
  Easting='East';
end

if (apogee_US(1,2)<0)
  Northing='South';
else
  Northing='North';
end
disp(sprintf(['Apogee location is %dm ',Easting,' and %dm ',Northing,' of launch location'],abs(apogee_US(1,1)),abs(apogee_US(1,2))))
disp(sprintf('Apogee altitude is %dm\n',apogee_US(1,3)))
disp(sprintf('Landing data:'))
disp(sprintf('Landing occurred %d seconds after launch',(Ascbig_TR{1}(:,1)(end)+Ascbig_US{1}(:,1)(end)+Desbig_US{1}(:,1)(end))))
if (Landing_US(1,1)<0)
  Easting='West';
else
  Easting='East';
end

if (Landing_US(1,2)<0)
  Northing='South';
else
  Northing='North';
end
disp(sprintf(['Landing location is %dm ',Easting,' and %dm ',Northing,' of launch location\n'],abs(Landing_US(1,1)),abs(Landing_US(1,2))))

disp(sprintf('\n**Mean booster stage data**:'))
disp(sprintf('Apogee data:'))
disp(sprintf('Apogee reached %d seconds after launch',(Ascbig_TR{1}(:,1)(end)+Ascbig_BS{1}(:,1)(end))))
if (apogee_BS(1,1)<0)
  Easting='West';
else
  Easting='East';
end

if (apogee_BS(1,2)<0)
  Northing='South';
else
  Northing='North';
end
disp(sprintf(['Apogee location is %dm ',Easting,' and %dm ',Northing,' of launch location'],abs(apogee_BS(1,1)),abs(apogee_BS(1,2))))
disp(sprintf('Apogee altitude is %dm\n',apogee_BS(1,3)))
disp(sprintf('Landing data:'))
disp(sprintf('Landing occurred %d seconds after launch',(Ascbig_TR{1}(:,1)(end)+Ascbig_BS{1}(:,1)(end)+Desbig_BS{1}(:,1)(end))))
if (Landing_BS(1,1)<0)
  Easting='West';
else
  Easting='East';
end

if (Landing_BS(1,2)<0)
  Northing='South';
else
  Northing='North';
end
disp(sprintf(['Landing location is %dm ',Easting,' and %dm ',Northing,' of launch location\n'],abs(Landing_BS(1,1)),abs(Landing_BS(1,2))))
%%%%%%%%%%%%%%%%%%%%