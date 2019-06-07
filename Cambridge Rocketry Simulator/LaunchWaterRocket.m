%Cambridge Rocketry Simulator
%Water Bottle Launch Function
%S.Box 8 July 2008

function AscentData=LaunchWaterRocket(Ttab,ws,wb,NM,WM);
  
  %t=[0:0.004:0.12];
  %T=[0 0 0 0 380 440 460 340 290 250 230 200 180 175 150 145 130 110 100 80 75 60 45 40 35 20 10 5 0 0 0];
  %Ttab=[t',T'];
 
  DFF=2.0;
  INTAB=WaterRocketDesign(Ttab,NM,WM);
  INTAB{2}(2:end,2:end)=INTAB{2}(2:end,2:end)*DFF;
  
  %Stochastic bit%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  Ra = randn*5;
  Rb = rand*360;
  ws = ws+randn*2;
  wb = wb+randn*20;
  %Ra = 0;
  %Rb =0;
  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  
  wbx=bearing_to_vector(wb);
  wbx=vectornorm(wbx);
  wbx=wbx*ws;
  
  INTAB4=[0 wbx(1) wbx(2) wbx(3) 1.2 285;
      10000 wbx(1) wbx(2) wbx(3) 1.2 285];
  
  %Run the rocket flight simulator%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  
  [AscentData,DescentData,Landing,Apogee]=waterrocketflight(INTAB,INTAB4,0,0.01,Ra,Rb,'ballisticfailure');
  %[headers,RDT]=flight_variables('FlightData01',AscentData,INTAB,INTAB4,0,0.01,0,0);
  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
      
