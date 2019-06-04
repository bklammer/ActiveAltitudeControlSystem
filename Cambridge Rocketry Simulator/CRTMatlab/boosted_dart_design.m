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

%## boosted_dart_design.m

%## Author: S.Box
%## Created: 2008-05-27

%boosted dart design

function [INTAB_US,INTAB_BS,INTAB_TR]=boosted_dart_design()

%Total Rocket*************************************************************
name='nose';
shape='ogive';
L=0.25;
d=0.042;
M=1.583;
X=0;
N_TR={name,shape,L,d,M,X};

name='cylinder';
body='no';
L=0.03;
d=0.039;
M=0.307;
X=0.25;

CY1_TR={name,body,L,d,M,X};

%Bodytube
name='tube';
body='yes';
L=0.82;
Id=0.039;
Od=0.042;
M=0.2995;
X=0.25;

B1_TR={name,body,L,Id,Od,M,X};

%Bodytube
name='tube';
body='no';
L=0.08;
Id=0.039;
Od=0.042;
M=0.0296;
X=1.07;

B2_TR={name,body,L,Id,Od,M,X};

%Coupler tube;

name='tube';
body='no';
L=0.30;
Id=0.036;
Od=0.039;
M=0.101446;
X=0.37;

B3_TR={name,body,L,Id,Od,M,X};

%point mass

%point mass
name='pm';
M=0.150;
Xr=0;
Xl=0.55;

Pm1_TR={name,M,Xr,Xl};

%Drogue 
name='parachute';
type='drogue';
apogeedep='yes';
Cd=0.6;
Ap=0.0447;
Altdep=0;
M=0;
X=0;

P1_TR={name,Cd,Ap,M,X};

%Main Parachute 
name='parachute';
type='main';
Cd=1.2;
Ap=1;
Altdep=335;
M=0.01492;
X=0.7558;

P2_TR={name,Cd,Ap,M,X};

%Finset;
name='finset';
n=3;
a=0.10;
b=0.03;
m=0.06;
s=0.035;
t=0.00318;
M=0.0415;
d=0.042;
dr=0.042;
X=0.97;

F1_TR={name,n,a,b,m,s,t,M,d,dr,X};

%Boattail;
name='cone_trans';
body='no';
Ud=0.042;
Dd=0.005;
dr=0.042;
L=0.2;
M=0.2826;
X=1.15;

C1_TR={name,body,Ud,Dd,dr,L,M,X};

%Transition;
name='cone_trans';
body='yes';
Ud=0.042;
Dd=0.079;
dr=0.042;
L=0.08;
M=0.250;
X=1.07;

C2_TR={name,body,Ud,Dd,dr,L,M,X};

%Bodytube
name='tube';
body='yes';
L=1.49;
Id=0.076;
Od=0.079;
M=0.979;
X=1.15;

B4_TR={name,body,L,Id,Od,M,X};

%coupler
name='tube';
body='no';
L=0.08;
Id=0.073;
Od=0.076;
M=0.0393;
X=1.31;

B5_TR={name,body,L,Id,Od,M,X};

%coupler
name='tube';
body='no';
L=0.2;
Id=0.073;
Od=0.076;
M=0.098;
X=1.48;

B6_TR={name,body,L,Id,Od,M,X};

%coupler
name='tube';
body='no';
L=0.08;
Id=0.073;
Od=0.076;
M=0.0393;
X=1.88;

B7_TR={name,body,L,Id,Od,M,X};

%point mass
name='pm';
M=0.200;
Xr=0;
Xl=1.58;

Pm2_TR={name,M,Xr,Xl};

%Bulkplate
name='cylinder';
body='no';
L=0.003;
d=0.076;
M=0.02449;
X=1.35;

CY2_TR={name,body,L,d,M,X};

%Bulkplate
name='cylinder';
body='no';
L=0.003;
d=0.076;
M=0.02449;
X=1.477;

CY3_TR={name,body,L,d,M,X};

%Bulkplate
name='cylinder';
body='no';
L=0.003;
d=0.076;
M=0.02449;
X=1.677;

CY4_TR={name,body,L,d,M,X};

%Finset;
name='finset';
n=3;
a=0.20;
b=0.06;
m=0.12;
s=0.07;
t=0.00476;
M=0.2339;
d=0.079;
dr=0.042;
X=2.42;

F2_TR={name,n,a,b,m,s,t,M,d,dr,X};

%Main Parachute 
name='parachute';
type='main';
Cd=1.2;
Ap=1;
Altdep=335;
M=0.0314;
X=1.83;

P3_TR={name,Cd,Ap,M,X};

%Motor
load engL1115;
Motor{6}=2.02;

INTAB_TR=intab_builder(N_TR,CY1_TR,B1_TR,B2_TR,B3_TR,Pm1_TR,P1_TR,P2_TR,C1_TR,C2_TR,B4_TR,B5_TR,B6_TR,B7_TR,Pm2_TR,CY2_TR,CY3_TR,CY4_TR,P3_TR,F1_TR,F2_TR,Motor);

%**************************************************************************

%Dart**********************************************************************
N_DT=N_TR;
CY1_DT=CY1_TR;

%Bodytube
name='tube';
body='yes';
L=0.90;
Id=0.039;
Od=0.042;
M=0.2590;
X=0.25;

B1_DT={name,body,L,Id,Od,M,X};

B2_DT=B3_TR;

Pm1_DT=Pm1_TR;
P1_DT=P1_TR;
P2_DT=P2_TR;
F1_DT=F1_TR;

%Boattail;
name='cone_trans';
body='yes';
Ud=0.042;
Dd=0.0234;%HACK to estimate base drag correctly;
dr=0.042;
L=0.1;
M=0.2826;
X=1.15;

C1_DT={name,body,Ud,Dd,dr,L,M,X};

INTAB_US=intab_builder(N_DT,CY1_DT,B1_DT,B2_DT,Pm1_DT,P1_DT,P2_DT,F1_DT,C1_DT);

%**************************************************************************

%Booster*******************************************************************

%Transition;
name='cone_trans';
body='yes';
Ud=0.042;
Dd=0.079;
dr=0.079;
L=0.08;
M=0.346;
X=0;

C1_BO={name,body,Ud,Dd,dr,L,M,X};

%Bodytube
name='tube';
body='yes';
L=1.49;
Id=0.076;
Od=0.079;
M=0.979;
X=0.08;

B1_BO={name,body,L,Id,Od,M,X};

%coupler
name='tube';
body='no';
L=0.08;
Id=0.073;
Od=0.076;
M=0.0393;
X=0.24;

B2_BO={name,body,L,Id,Od,M,X};

%coupler
name='tube';
body='no';
L=0.2;
Id=0.073;
Od=0.076;
M=0.098;
X=0.41;

B3_BO={name,body,L,Id,Od,M,X};

%coupler
name='tube';
body='no';
L=0.08;
Id=0.073;
Od=0.076;
M=0.0393;
X=0.81;

B4_BO={name,body,L,Id,Od,M,X};

%point mass
name='pm';
M=0.200;
Xr=0;
Xl=0.51;

Pm1_BO={name,M,Xr,Xl};

%Bulkplate
name='cylinder';
body='no';
L=0.003;
d=0.076;
M=0.02449;
X=0.28;

CY1_BO={name,body,L,d,M,X};

%Bulkplate
name='cylinder';
body='no';
L=0.003;
d=0.076;
M=0.02449;
X=0.407;

CY2_BO={name,body,L,d,M,X};

%Bulkplate
name='cylinder';
body='no';
L=0.003;
d=0.076;
M=0.02449;
X=0.607;

CY3_BO={name,body,L,d,M,X};

%Finset;
name='finset';
n=3;
a=0.20;
b=0.06;
m=0.12;
s=0.07;
t=0.00476;
M=0.2004;
d=0.079;
dr=0.042;
X=1.35;

F1_BO={name,n,a,b,m,s,t,M,d,dr,X};

%Drogue 
name='parachute';
type='drogue';
apogeedep='yes';
Cd=0.6;
Ap=0.0447;
Altdep=0;
M=0;
X=0;

P1_BO={name,Cd,Ap,M,X};

%Main Parachute 
name='parachute';
type='main';
Cd=1.2;
Ap=1;
Altdep=335;
M=0.0314;
X=0.76;

P2_BO={name,Cd,Ap,M,X};

%burntout motor
name='cylinder';
body='no';
L=0.621;
d=0.075;
M=1.646;
X=0.949;

CY4_BO={name,body,L,d,M,X};

INTAB_BS=intab_builder(C1_BO,B1_BO,B2_BO,B3_BO,B4_BO,Pm1_BO,CY1_BO,CY2_BO,CY3_BO,CY4_BO,F1_BO,P1_BO,P2_BO);

%intab_BO{2}(2:10,2:25)=intab_BO{2}(2:10,2:25)*1.5; %????
















