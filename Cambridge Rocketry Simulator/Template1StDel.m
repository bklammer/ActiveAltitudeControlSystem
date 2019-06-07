%Cambridge Rocketry Simulator
%Template for a single stage rocket simulation with launch rail angle optimization
%S.Box 15 June 2008

function Template1StDel();
  
  load 'intab_CLV2s1_K660.mat'; %Loads the rocket data into a variable called INTAB
  load 'intab4_2006100809.mat'; %Loads the atmospheric data into a variable called INTAB4
  
  Parachute2Alt=300; %Altitude at which the rocket's second parachute will deploy in meters
  RailLength=2;      %Length of the launching rail in meters
  Address=[0,0];     %Desired landing location [East of launchpad (m), North of launchpad (m)]  
  AccuracyR=20;     %Acceptable radius of accuraccy (m)
  iMax=10;           %Maximum number of iterations to perform
  
  %%Run the rocket flight simulator%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  
  [Declination,Bearing,AscDat,DesDat,Land,Apo]=rocketflight_delivery(INTAB,INTAB4,Parachute2Alt,RailLength,Address,AccuracyR,iMax);
  
  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  
