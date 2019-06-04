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

%## CLV2s1build.m

%## Author: S.Box
%## Created: 2008-05-27

%Rocket design CLV2s1 with L730;

function INTAB=CLV2s1build()

  %Nosecone
  name='nose';
  shape='conical';
  L=0.470;
  d=0.075;
  M=0.025537;
  X=0;
  N1={name,shape,L,d,M,X};

  %Bodytube
  name='tube';
  body='yes';
  L=1.65;
  Id=0.073;
  Od=0.076;
  M=0.074224;
  X=0.470;

  B1={name,body,L,Id,Od,M,X};


  %motor mount tube;
  name='tube';
  body='no';
  L=0.35;
  Id=0.054;
  Od=0.056;
  M=0.007746;
  X=1.77;

  B2={name,body,L,Id,Od,M,X};

  %Boattail;
  name='cone_trans';
  body='yes';
  Ud=0.075;
  Dd=0.056;
  dr=0.075;
  L=0.035;
  M=0;
  X=2.085;

  C1={name,body,Ud,Dd,dr,L,M,X};

  %point mass
  name='pm';
  M=0.473499;
  Xr=0;
  Xl=0.25;

  Pm1={name,M,Xr,Xl};

  %point mass
  name='pm';
  M=0.936699;
  Xr=0;
  Xl=0.724;

  Pm2={name,M,Xr,Xl};

  %point mass
  name='pm';
  M=1;
  Xr=0;
  Xl=1.835;

  Pm3={name,M,Xr,Xl};

  %point mass
  name='pm';
  M=0.75;
  Xr=0;
  Xl=1.09;

  Pm4={name,M,Xr,Xl};

  %point mass
  name='pm';
  M=0.46;
  Xr=0;
  Xl=1.372;

  Pm5={name,M,Xr,Xl};

  %Finset;
  name='finset';
  n=3;
  a=0.14;
  b=0.08;
  m=0.03;
  s=0.08;
  t=0.00476;
  M=0.0161;
  d=0.075;
  dr=0.075;
  X=1.86;

  F1={name,n,a,b,m,s,t,M,d,dr,X};

  %Motor
  load engL730;
  Motor{6}=1.471;

  %Drogue 
  name='parachute';
  Cd=0.6;
  Ap=0.1447;
  M=0;
  X=0;

  P1={name,Cd,Ap,M,X};

  %Main Parachute 
  name='parachute';
  Cd=1.2;
  Ap=1.766;
  M=0;
  X=0;

  P2={name,Cd,Ap,M,X};




  INTAB=intab_builder(N1,B1,B2,C1,Pm1,Pm2,Pm3,Pm4,Pm5,F1,Motor,P1,P2);

