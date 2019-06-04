%Cambridge Rocketry Simulator
%Template for encoding a rocket design from a RockSim file
%S.Box 15 June 2008

function TemplateRSim();
  
  filename='CLV-1.rkt';  %Specify the filename of the RockSim file
  load engK660;          %Load the rocket motor data file into 'Motor'  
  X=1.43;                %distance from the rocket nose tip to the foremost part of the motor 
  
  [INTAB,Pout]=readrsim(filename,Motor,X); %Generate a rocket data file from the rocksim file
  
  save 'intab_RsimTemplate.mat' INTAB; %Save the rocket data file  
  
