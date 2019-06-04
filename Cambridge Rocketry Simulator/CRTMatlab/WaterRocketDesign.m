%Cambridge Rocketry Simulator
%Encoding for  Water Rocket design
%S.Box 8 July 2008

function INTAB=WaterRocketDesign(Ttab,NoseMass,WaterVolume);

WaterMass=WaterVolume;%I know this is silly from a computer science point of view but i am an engineer!
  
  %point mass%%%%%%%%%%%%%%%%%%
  name='pm';
  M=NoseMass;
  Xr=0;
  Xl=0;

  Pm1={name,M,Xr,Xl};
  %%%%%%%%%%%%%%%%%%%%%%%%%%%%

  %Nosecone%%%%%%%%%%%%%%%%%%%
  name='nose';      %Part type
  shape='parabolic';  %Nose shape
  L=0.04;          %Length of nosecone 
  d=0.0985;          %Diameter of nosecone at base
  M=0.010;          %Mass of nosecone
  X=0;              %Position
  
  N1={name,shape,L,d,M,X};
  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%

  %Bodytube%%%%%%%%%%%%%%%%%%%%
  name='tube';      %Part type
  body='yes';       %Does this tube fom part of the rocket body?
  L=0.230;            %Tube length
  Id=0.0975;         %Tube inner diameter
  Od=0.0985;         %Tube outer diameter
  M=0.020;          %Tube mass
  X=0.04;           %Distance from the nose tip to the foremost part of the tube 

  B1={name,body,L,Id,Od,M,X};
  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%

  %Boattail%%%%%%%%%%%%%%%%%%%
  name='cone_trans'; %Part type
  body='yes';        %Does this conical transition form part of the rocket body?
  Ud=0.0985;          %Upstream diameter
  Dd=0.031;          %Downstream diameter
  dr=0.0985;          %Max diameter of rocket body
  L=0.055;            %Length of  the transitiom
  M=0.010;            %Mass of the transition  
  X=0.27;            %Distance from the nose tip to the foremost part of the conical transition

  C1={name,body,Ud,Dd,dr,L,M,X};
  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  
  %Bodytube%%%%%%%%%%%%%%%%%%%%
  name='tube';      %Part type
  body='yes';       %Does this tube fom part of the rocket body?
  L=0.031;            %Tube length
  Id=0.020;         %Tube inner diameter
  Od=0.031;         %Tube outer diameter
  M=0.010;          %Tube mass
  X=0.325;           %Distance from the nose tip to the foremost part of the tube 

  B2={name,body,L,Id,Od,M,X};
  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  
  %Bodytube%%%%%%%%%%%%%%%%%%%%
  name='tube';      %Part type
  body='yes';       %Does this tube fom part of the rocket body?
  L=0.009;            %Tube length
  Id=0.010;         %Tube inner diameter
  Od=0.017;         %Tube outer diameter
  M=0.0046;          %Tube mass
  X=0.346;           %Distance from the nose tip to the foremost part of the tube 

  B3={name,body,L,Id,Od,M,X};
  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  
  %Finset%%%%%%%%%%%%%%%%%%%%%%
  name='finset';     %Part type
  n=3;               %Number of fins (3 or 4)
  a=0.105;            %Length of the fin root
  b=0.019;            %Length of the fin tip
  m=0.102;            %Length of the fin sweep
  s=0.068;            %Length of the fin span
  t=0.003;           %Fin thickness   
  M=0.01388;           %Mass of the finset
  d=0.031;           %Diameter of the body tube at the fins
  dr=0.0985;          %Maximum body tube diameter
  X=0.334;            %Distance from the nose tip to the foremost part of the finset

  F1={name,n,a,b,m,s,t,M,d,dr,X};
  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%

  %Motor%%%%%%%%%%%%%%%%%%%%%%%
  Mtab=impulse_and_mass(Ttab(:,1),Ttab(:,2),WaterMass);%Calculate the variation of mass with thrust assuming 1 kg of water is in the rocket
  MotD=0.0975; %Diameter of Motor
  Xmotb=0.2925; %Distance to motor base
  MotL=(WaterVolume*4)/(pi*MotD^2*1000);
  Xmot=Xmotb-MotL;
  Motor={'motor','Water',[Ttab,Mtab'],MotL,MotD,Xmot};
  
  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  
  %Parachute%%%%%%%%%%%%%%%%%%% 
  name='parachute'; %Part type
  Cd=0.5;           %Parachute drag coefficient
  Ap=0.01;          %Paracute area
  M=0.00;          %Parachute mass
  X=0.18;           %Distance from the node tip to the location of the parachute in the rocket

  P1={name,Cd,Ap,M,X};
  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  
  INTAB=intab_builder(Pm1,N1,B1,C1,B2,B3,F1,P1,Motor); %Build the rocket desigh data variable "INTAB"
  

  
