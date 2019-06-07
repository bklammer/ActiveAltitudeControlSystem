%Cambridge Rocketry Simulator
%Template for a single stage rocket simulation with monte carlo
%S.Box 15 June 2008

function Template1StMonte()
  
  load 'intab_CLV2s1_K660.mat'; %Loads the rocket data into a variable called INTAB
  load 'intab4_2006100809.mat'; %Loads the atmospheric data into a variable called INTAB4
  
  Parachute2Alt=300; %Altitude at which the rocket's second parachute will deploy in meters
  RailLength=2;      %Length of the launching rail in meters
  RailDeclination=0; %Angle of declination of the launching rail in degrees
  RailBearing=0;     %Bearing of the launching rail in degrees from true north
  noi=50;             %Number of monte carlo iterations to be performed
  
  %%Run the rocket flight simulator%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  
  [AscDat,DesDat,Land,Apo]=rocketflight_monte(INTAB,INTAB4,Parachute2Alt,RailLength,RailDeclination,RailBearing,noi);
  
  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  
  
