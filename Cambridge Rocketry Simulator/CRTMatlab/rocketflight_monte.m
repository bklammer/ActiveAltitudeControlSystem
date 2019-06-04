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

%## rocketflight_monte.m

%## Author: S. Box
%## Created: 2008-05-08


function varargout=rocketflight_monte(varargin);
warning off;
tic

%UNPACK INPUT TABLES****************************************************
INTAB1=varargin{1}{1};%TIME DEPENDANT INPUTS
INTAB2=varargin{1}{2};%DRAG TABLE
INTAB3=varargin{1}{3};%NORMAL FORCE TABLE
INTAB4=varargin{2};%ALTITUDE DEPENDANT INPUTS

landa=varargin{1}{4};%ROCKET LENGTH AND AREA
paratab=varargin{1}{5};%PARACHUTE VARIABLES TABLE


RBL=landa(1);%Rocket body length (m)
Ar=landa(2); %Rocket reference area (m^2);
altpd=varargin{3};
RL=varargin{4}; %Launch rail length (m);
Ra=varargin{5}; %Launch rail angle(degrees) from vetical 0<Ra<90;
Rbearing=varargin{6}; %Launch rail bearing (degrees) from north 0<Rbearing<360;

noi=varargin{7};

argmin=7;
label='nofail';
if nargin>argmin;
    if varargin{8}=='ballisticfailure';
        label=varargin{8};
        argmin=8;
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
        %error 'invalid number of arguments';
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
                Cdpms=varargin{argmin+j};
            case 'CDDmult'
                Cddms=varargin{argmin+j};
            case 'MU'
                MU=varargin{argmin+j};
            case 'SIGMA'
                SIGMA=varargin{argmin+j};
        end
    end
end
%END OF INPUTS***********************************************************

%SPECIFY SOME CONSTANTS AT ROCKETS INITIAL POSITION**********************
mu=1.8e-5; % kinematic viscosity of air (Ns/m^2);
G=6.6742E-11;% Gravitational constant

Xt=[0;0;0];%Rocket initial position (m);

ttspan=[0 10000];

YA0=[1;0;0];%Reference Yaw axis
PA0=[0;1;0];%Reference Pitch axis
RA0=[0;0;1];%Reference Roll axis

ttspan2=[0 10000];


%RUN THE CODE FOR THE MEAN POSITION*************************************
%INITIAL QUATERNION************************************************
Ra=Ra*pi/180;
Raxb=Rbearing-90;
Rax=bearing_to_vector(Raxb);


Q1=[cos(Ra/2) sin(Ra/2)*Rax(1) sin(Ra/2)*Rax(2) sin(Ra/2)*Rax(3)];

%Runge Kutta integration of rocket equations of motion*************

%Ascent
z0=[Xt(1) Xt(2) Xt(3) Q1(1) Q1(2) Q1(3) Q1(4) 0 0 0 0 0 0];

[tt,z]=ascentcalc(ttspan,z0,YA0,PA0,RA0,INTAB1,INTAB2,INTAB3,INTAB4,Ar,RL,Ra,mu,RBL,G,label);

%Descent
z02=[z(end,1) z(end,2) z(end,3) z(end,8) z(end,9) z(end,10)];

[tt2,z2]=descentcalc(ttspan2,z02,INTAB4,INTAB1,paratab,altpd,G);

sz=size(z);
sz2=size(z2);
zp=zeros((sz(1)+sz2(1)),3);
zp(1:sz(1),1:3)=z(:,1:3);
zp((sz(1)+1):(sz(1)+sz2(1)),1:3)=z2(:,1:3);

zpbig{1}=zp;
Ascbig{1}=[tt,z];
Desbig{1}=[tt2,z2];

Landing(1)=interp1(z2(:,3),z2(:,1),0.2,'linear','extrap');
Landing(2)=interp1(z2(:,3),z2(:,2),0.2,'linear','extrap');

[Aval Aht]=max(z(:,3));
apogee(1:3)=z(Aht,1:3);



%RUN THE CODE USING MONTE CARLO*******************************************
INTAB1pc=INTAB1;
INTAB2pc=INTAB2;
INTAB3pc=INTAB3;
INTAB4pc=INTAB4;
paratabpc=paratab;

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

    sit2=size(INTAB2pc);
    INTAB2(2:sit2(1),2:sit2(2))=INTAB2pc(2:sit2(1),2:sit2(2))*Cdm;

    INTAB3(:,1)=INTAB3pc(:,1)*CNm;

    INTAB3(:,2)=INTAB3pc(:,2)+Cpm;

    INTAB4(:,2)=INTAB4pc(:,2)+Xdw;
    INTAB4(:,3)=INTAB4pc(:,3)+Ydw;


    paratab(1)=paratabpc(1)*Cddm;
    if length(paratab)==4;
        paratab(3)=paratabpc(3)*Cdpm;
    end

    %RUN THE CODE WITH THE NEW INPUT TABLES******************************

    %INITIAL QUATERNION************************************************
    Ra=Ra*pi/180;
    Raxb=Rbearing-90;
    Rax=bearing_to_vector(Raxb);


    Q1=[cos(Ra/2) sin(Ra/2)*Rax(1) sin(Ra/2)*Rax(2) sin(Ra/2)*Rax(3)];

    %Runge Kutta integration of rocket equations of motion*************

    %Ascent
    z0=[Xt(1) Xt(2) Xt(3) Q1(1) Q1(2) Q1(3) Q1(4) 0 0 0 0 0 0];

    [tt,z]=ascentcalc(ttspan,z0,YA0,PA0,RA0,INTAB1,INTAB2,INTAB3,INTAB4,Ar,RL,Ra,mu,RBL,G,label);

    %Descent
    z02=[z(end,1) z(end,2) z(end,3) z(end,8) z(end,9) z(end,10)];

    [tt2,z2]=descentcalc(ttspan2,z02,INTAB4,INTAB1,paratab,altpd,G);

    sz=size(z);
    sz2=size(z2);
    zp=zeros((sz(1)+sz2(1)),3);
    zp(1:sz(1),1:3)=z(:,1:3);
    zp((sz(1)+1):(sz(1)+sz2(1)),1:3)=z2(:,1:3);


    Ascbig{monte}=[tt,z];
    Desbig{monte}=[tt2,z2];

    Landing(monte,1)=interp1(z2(:,3),z2(:,1),0.2,'linear','extrap');
    Landing(monte,2)=interp1(z2(:,3),z2(:,2),0.2,'linear','extrap');

    [Aval Aht]=max(z(:,3));
    apogee(monte,:)=z(Aht,1:3);

    

end

%%Output Display%%%%
disp(sprintf('\n\nCambridge Rocketry Simulator\n'))
disp(sprintf('Simulation complete at: %s',datestr(now)))
toc
disp(sprintf('\nMean flight data:'))
disp(sprintf('Mean Apogee data:'))
disp(sprintf('Apogee reached %d seconds after launch',Ascbig{1}(end,1)))
if (apogee(1,1)<0)
  Easting='West';
else
  Easting='East';
end

if (apogee(1,2)<0)
  Northing='South';
else
  Northing='North';
end
disp(sprintf(['Apogee location is %dm ',Easting,' and %dm ',Northing,' of launch location'],abs(apogee(1,1)),abs(apogee(1,2))))
disp(sprintf('Apogee altitude is %dm\n',apogee(1,3)))
disp(sprintf('Mean Landing data:'))
disp(sprintf('Landing occurred %d seconds after launch',(Ascbig{1}(end,1)+Desbig{1}(end,1))))
if (Landing(1,1)<0)
  Easting='West';
else
  Easting='East';
end

if (Landing(1,2)<0)
  Northing='South';
else
  Northing='North';
end
disp(sprintf(['Landing location is %dm ',Easting,' and %dm ',Northing,' of launch location\n'],abs(Landing(1,1)),abs(Landing(1,2))))
disp(sprintf('Landing location is %dm East and %dm North of launch location\n',Landing(1,1),Landing(1,2)))
%%%%%%%%%%%%%%%%%%%%

figure
hold on
gauss_ellipse(mean(Landing),cov(Landing),1,'r');
gauss_ellipse(mean(Landing),cov(Landing),2,'g');
plot3(zpbig{1}(:,1),zpbig{1}(:,2),zpbig{1}(:,3),'Linewidth',2);
set(gca,'zlim',[0 (max(zpbig{1}(:,3))+100)]);
axis equal
xlabel('East (m)');
ylabel('North (m)');
zlabel('Altitude (m)');
title('Mean flight path and Gaussian uncertainty in the landing position (1 & 2 standard deviations) ');
set(gca,'XGrid','on')
set(gca,'YGrid','on')
set(gca,'ZGrid','on')


figure
hold on
gauss_ellipse(mean(Landing),cov(Landing),1,'r');
gauss_ellipse(mean(Landing),cov(Landing),2,'g');
plot(0,0,'rx',Landing(:,1),Landing(:,2),'b.');
axis equal;
xlabel('East (m)');
ylabel('North (m)');
title('Splash pattern and Gaussian elipses showing 1 and 2 standard deviations probability');

figure
plot3(0,0,0,'bx',apogee(:,1),apogee(:,2),apogee(:,3),'r.');
set(gca,'zlim',[0 (max(apogee(:,3))+100)]);
axis equal;
xlabel('East (m)');
ylabel('North (m)');
zlabel('Altitude (m)');
set(gca,'XGrid','on')
set(gca,'YGrid','on')
set(gca,'ZGrid','on')
title('apogee scatter pattern');

varargout={Ascbig,Desbig,Landing,apogee};
