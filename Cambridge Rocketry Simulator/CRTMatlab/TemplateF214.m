%Cambridge Rocketry Simulator
%Template for a two stage rocket simulation
%S.Box 15 June 2008

function TemplateF214()
  
  F214=[24 330 25 -28;
        18 330 20 -17;
        10 280 10 -04;
        05 240 02 +03;
        02 330 10 +08;
        01 340 10 +12;
        00 340 00 +12];%Populate an array with the f214 data
  
  INTAB4=f214read(F214); %Convert the f214 array into the atmospheric data variable
  
  save 'intab4_5230N0230W.mat' INTAB4; %Save the atmospheric data file  
  
