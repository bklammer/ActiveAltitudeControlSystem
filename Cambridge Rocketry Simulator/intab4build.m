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

%## intab4build.m

%## Author: S.Box
%## Created: 2008-05-27

%build intab4 from netcdf data;
% Simon Box
% 14 July 2006

function [INTAB4]=intab4build(uwind,vwind,prho,ptheta,psurf,temp,Year,Month,Day,hour,Lat,Long);

% %Inputs***************************************************************
% %Date and time
% Year=2006; %Format 'XXXX' eg 2006
% Month=06;  %Format 'XX' eg 05
% Day=10;    %Format 'XX' eg 06 
% hour=18;   %Format 'XX' options: 00, 06, 12, 18.
% 
% %Lat and Long
% Lat=52.9748;  %decimal format;
% Long=-0.3131; %decimal format; 
%********************************************************************

Uncdf=netcdf(uwind);
Vncdf=netcdf(vwind);
%Wncdf=netcdf(['C:\Documents and Settings\t-simonb\Desktop\EARS_OCT\wwind2']);
Prhoncdf=netcdf(prho);
Pthetancdf=netcdf(ptheta);
Psurfncdf=netcdf(psurf);
Tncdf=netcdf(temp);


%Time and Date********************************************************

%get time origin
timelong=Uncdf{'t'}.time_origin(:);
timeshrt=timelong(1:11);
time_0=datenum(timeshrt,'dd-mmm-yyyy');

%get time of simulation
time_n=datenum([Year Month Day]);

date=time_n-time_0;
hournum=hour/24;

time=date+hournum;
%*********************************************************************

%Convert lat and long to model co-ordinates***************************
[Y,X]=lltoeq(Lat,Long,37.5,177.5);%Valid for UK ONLY!!!!

if X<100;
    X=360+X;
end



%Retrive height scales************************************************
ht_rho_s=Uncdf{'hybrid_ht'}(:);
ht_rho(1)=0;
ht_rho(2:39,1)=ht_rho_s;
ht_theta_s=Tncdf{'hybrid_ht'}(:);
ht_theta(1)=0;
ht_theta(2:39,1)=ht_theta_s;

%Retrive U wind data at location**************************************
xtab=Uncdf{'x'}(:);
xupp=find(xtab>X,1,'first');
xlow=xupp-1;
xlim=[xtab(xlow),xtab(xupp)];

ytab=Uncdf{'y'}(:);
yupp=find(ytab>Y,1,'first');
ylow=yupp-1;
ylim=[ytab(ylow),ytab(yupp)];

timetab=Uncdf{'t'}(:);
timecell=find(timetab==time);

Udat(1,1,:)=Uncdf{'x-wind'}(timecell,:,ylow,xlow);
Udat(1,2,:)=Uncdf{'x-wind'}(timecell,:,ylow,xupp);
Udat(2,1,:)=Uncdf{'x-wind'}(timecell,:,yupp,xlow);
Udat(2,2,:)=Uncdf{'x-wind'}(timecell,:,yupp,xupp);

U1=interp3(ylim,xlim,ht_rho_s,Udat,Y,X,ht_rho_s);
U(1)=0;
U(2:39,1)=U1(1,1,1:38);

%Retrive V wind data at location***************************************
xtab=Vncdf{'x'}(:);
xupp=find(xtab>X,1,'first');
xlow=xupp-1;
xlim=[xtab(xlow),xtab(xupp)];

ytab=Vncdf{'y'}(:);
yupp=find(ytab>Y,1,'first');
ylow=yupp-1;
ylim=[ytab(ylow),ytab(yupp)];

Vdat(1,1,:)=Vncdf{'y-wind'}(timecell,:,ylow,xlow);
Vdat(1,2,:)=Vncdf{'y-wind'}(timecell,:,ylow,xupp);
Vdat(2,1,:)=Vncdf{'y-wind'}(timecell,:,yupp,xlow);
Vdat(2,2,:)=Vncdf{'y-wind'}(timecell,:,yupp,xupp);

V1=interp3(ylim,xlim,ht_rho_s,Vdat,Y,X,ht_rho_s);
V(1)=0;
V(2:39,1)=V1(1,1,1:38);


%Retrive P_surfdata*****************************************************
xtab=Psurfncdf{'x'}(:);
xupp=find(xtab>X,1,'first');
xlow=xupp-1;
xlim=[xtab(xlow),xtab(xupp)];

ytab=Psurfncdf{'y'}(:);
yupp=find(ytab>Y,1,'first');
ylow=yupp-1;
ylim=[ytab(ylow),ytab(yupp)];

P_surfdat(1,1)=Psurfncdf{'p'}(timecell,:,ylow,xlow);
P_surfdat(1,2)=Psurfncdf{'p'}(timecell,:,ylow,xupp);
P_surfdat(2,1)=Psurfncdf{'p'}(timecell,:,yupp,xlow);
P_surfdat(2,2)=Psurfncdf{'p'}(timecell,:,yupp,xupp);

P_surf=interp2(ylim,xlim,P_surfdat,Y,X);


%Retrive P_rho data at Location****************************************
xtab=Prhoncdf{'x'}(:);
xupp=find(xtab>X,1,'first');
xlow=xupp-1;
xlim=[xtab(xlow),xtab(xupp)];

ytab=Prhoncdf{'y'}(:);
yupp=find(ytab>Y,1,'first');
ylow=yupp-1;
ylim=[ytab(ylow),ytab(yupp)];

P_rhodat(1,1,:)=Prhoncdf{'p'}(timecell,1:38,ylow,xlow);
P_rhodat(1,2,:)=Prhoncdf{'p'}(timecell,1:38,ylow,xupp);
P_rhodat(2,1,:)=Prhoncdf{'p'}(timecell,1:38,yupp,xlow);
P_rhodat(2,2,:)=Prhoncdf{'p'}(timecell,1:38,yupp,xupp);

P_rho1=interp3(ylim,xlim,ht_rho_s,P_rhodat,Y,X,ht_rho_s);
P_rho(1)=P_surf;
P_rho(2:39,1)=P_rho1(1,1,1:38);

%Retrive P_theta data at location**************************************
xtab=Pthetancdf{'x'}(:);
xupp=find(xtab>X,1,'first');
xlow=xupp-1;
xlim=[xtab(xlow),xtab(xupp)];

ytab=Pthetancdf{'y'}(:);
yupp=find(ytab>Y,1,'first');
ylow=yupp-1;
ylim=[ytab(ylow),ytab(yupp)];

P_thetadat(1,1,:)=Pthetancdf{'p'}(timecell,1:38,ylow,xlow);
P_thetadat(1,2,:)=Pthetancdf{'p'}(timecell,1:38,ylow,xupp);
P_thetadat(2,1,:)=Pthetancdf{'p'}(timecell,1:38,yupp,xlow);
P_thetadat(2,2,:)=Pthetancdf{'p'}(timecell,1:38,yupp,xupp);

P_theta1=interp3(ylim,xlim,ht_theta_s,P_thetadat,Y,X,ht_theta_s);
P_theta(1)=P_surf;
P_theta(2:39,1)=P_theta1(1,1,1:38);

%Retrive T data at location********************************************
xtab=Tncdf{'x'}(:);
xupp=find(xtab>X,1,'first');
xlow=xupp-1;
xlim=[xtab(xlow),xtab(xupp)];

ytab=Tncdf{'y'}(:);
yupp=find(ytab>Y,1,'first');
ylow=yupp-1;
ylim=[ytab(ylow),ytab(yupp)];

Tdat(1,1,:)=Tncdf{'temp'}(timecell,1:38,ylow,xlow);
Tdat(1,2,:)=Tncdf{'temp'}(timecell,1:38,ylow,xupp);
Tdat(2,1,:)=Tncdf{'temp'}(timecell,1:38,yupp,xlow);
Tdat(2,2,:)=Tncdf{'temp'}(timecell,1:38,yupp,xupp);

T1=interp3(ylim,xlim,ht_theta_s,Tdat,Y,X,ht_theta_s);
T2(1:38,1)=T1(1,1,1:38);

T=interp1(ht_theta_s,T2,ht_theta,'linear','extrap');



%Interpolate Temp to ht_rho values****************************************

T_rho=interp1(ht_theta,T,ht_rho,'linear','extrap');

%calculate density rho at ht_rho levels using ideal gas law***************

rho=P_rho./(287*T_rho);

%Build Input table********************************************************
INTAB4(:,1)=ht_rho;
INTAB4(:,2)=-U;
INTAB4(:,3)=-V;
INTAB4(:,4)=zeros(39,1);
INTAB4(:,5)=rho;
INTAB4(:,6)=T_rho;

%Alternative height calculation******************************************
ht_alt=(288.15/0.0065).*(1-(P_rho./P_surf).^(287*0.0065/9.81));
