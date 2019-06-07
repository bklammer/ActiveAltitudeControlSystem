%Cambridge Rocketry Simulator
%Template for a two stage rocket flight simulation using a boosted dart
%S.Box 15 June 2008

function Template2st();
  
  load 'intab_camdart_plus_booster.mat'; %Loads the rocket data for the complete rocket into INTAB_TR
  load 'intab_camdart.mat';              %Loads the rocket data for the dart into INTAB_US
  load 'intab_cambooster.mat';           %Loads the rocket data for the booster stage into INTAB_BS 

  load 'intab4_2006100809.mat';          %Loads the atmospheric data into a variable called INTAB4
  
  tsep=4.49;     %Time of stage separation (seconds after launch)
  ig_delay=4.49; %Time of second stage ignition (seconds after launch)
  Para2AltU=300; %Altitude at which the upper stage second parachute will deploy in meters  
  Para2AltB=300; %Altitude at which the booster stage second parachute will deploy in meters  
  RailLength=2;      %Length of the launching rail in meters
  RailDeclination=0; %Angle of declination of the launching rail in degrees
  RailBearing=0;     %Bearing of the launching rail in degrees from true north
  
  
  %%Run the rocket flight simulator%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  
  [AscDat1,AscDat2,AscDat3,DesDat1,DesDat2,Land1,Land2,Apo1,Apo2]=rocketflight_2_stage(INTAB_TR,INTAB_BS,INTAB_US,INTAB4,tsep,ig_delay,Para2AltU,Para2AltB,RailLength,RailDeclination,RailBearing);
  
  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  
