%Cambridge Rocketry Simulator
%Template for encoding a rocket design
%S.Box 15 June 2008

function TemplateRocketDesign();
  
  %Nosecone%%%%%%%%%%%%%%%%%%%
  name='nose';      %Part type
  shape='conical';  %Nose shape
  L=0.120;          %Length of nosecone 
  d=0.045;          %Diameter of nosecone at base
  M=0.025;          %Mass of nosecone
  X=0;              %Position
  
  N1={name,shape,L,d,M,X};
  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%

  %Bodytube%%%%%%%%%%%%%%%%%%%%
  name='tube';      %Part type
  body='yes';       %Does this tube fom part of the rocket body?
  L=0.4;            %Tube length
  Id=0.041;         %Tube inner diameter
  Od=0.045;         %Tube outer diameter
  M=0.060;          %Tube mass
  X=0.12;           %Distance from the nose tip to the foremost part of the tube 

  B1={name,body,L,Id,Od,M,X};
  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  
  %Parachute%%%%%%%%%%%%%%%%%%% 
  name='parachute'; %Part type
  Cd=1.2;           %Parachute drag coefficient
  Ap=0.25;          %Paracute area
  M=0.015;          %Parachute mass
  X=0.18;           %Distance from the node tip to the location of the parachute in the rocket

  P1={name,Cd,Ap,M,X};
  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  
  %point mass%%%%%%%%%%%%%%%%%%
  name='pm';        %Part type
  M=0.3;            %Mass  
  Xr=0;             %Radial postion in the rocket
  Xl=0.27;          %Distance from nose tip to the mass
  
  Pm1={name,M,Xr,Xl};
  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%


  %motor mount ring%%%%%%%%%%%%
  name='tube';      %Part type
  body='no';        %Does this tube fom part of the rocket body?
  L=0.005;          %Tube length
  Id=0.038;         %Tube inner diameter
  Od=0.041;         %Tube outer diameter
  M=0.007;          %Tube mass
  X=0.445;          %Distance from the nose tip to the foremost part of the tube 

  B2={name,body,L,Id,Od,M,X};
  %%%%%%%%%%%%%%%%%%%%%%%%%%%%

  %Boattail%%%%%%%%%%%%%%%%%%%
  name='cone_trans'; %Part type
  body='yes';        %Does this conical transition form part of the rocket body?
  Ud=0.045;          %Upstream diameter
  Dd=0.038;          %Downstream diameter
  dr=0.045;          %Max diameter of rocket body
  L=0.02;            %Length of  the transitiom
  M=0.02;            %Mass of the transition  
  X=0.52;            %Distance from the nose tip to the foremost part of the conical transition

  C1={name,body,Ud,Dd,dr,L,M,X};
  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%

  %Finset%%%%%%%%%%%%%%%%%%%%%%
  name='finset';     %Part type
  n=3;               %Number of fins (3 or 4)
  a=0.09;            %Length of the fin root
  b=0.02;            %Length of the fin tip
  m=0.07;            %Length of the fin sweep
  s=0.05;            %Length of the fin span
  t=0.003;           %Fin thickness   
  M=0.016;           %Mass of the finset
  d=0.045;           %Diameter of the body tube at the fins
  dr=0.045;          %Maximum body tube diameter
  X=0.42;            %Distance from the nose tip to the foremost part of the finset

  F1={name,n,a,b,m,s,t,M,d,dr,X};
  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%

  %Motor%%%%%%%%%%%%%%%%%%%%%%%
  load engH153;      %Load the Cesaroni H153 rocket motor
  Motor{6}=0.432;    %Distance from the nose tip to the foremost part of the rocket motor
  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  
  INTAB=intab_builder(N1,B1,P1,Pm1,B2,C1,F1,Motor); %Build the rocket desigh data variable "INTAB"
  
  save 'intab_DesignTemplate.mat' INTAB; %Save the rocket design data file

  
