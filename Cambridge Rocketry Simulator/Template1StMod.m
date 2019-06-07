%Cambridge Rocketry Simulator
%Template for a single stage rocket simulation
%S.Box 15 June 2008

%function Template1StMod()
  
  load 'intab_CLV2s1_K660.mat'; %Loads the rocket data into a variable called INTAB
  load 'intab4_2006100809.mat'; %Loads the atmospheric data into a variable called INTAB4
  
  Parachute2Alt=300; %Altitude at which the rocket's second parachute will deploy in meters
  RailLength=2;      %Length of the launching rail in meters
  RailDeclination=0; %Angle of declination of the launching rail in degrees
  RailBearing=0;     %Bearing of the launching rail in degrees from true north
  
  
  %%Run the rocket flight simulator%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  
  [AscentData,DescentData,Landing,Apogee]=rocketflight(INTAB,INTAB4,Parachute2Alt,RailLength,RailDeclination,RailBearing);
  AscentData=AscentData(2184,:);
  q=AscentData(5:8);
  s=q(1);
  v=q(2:4);
  theta = acos(s)*2;
  sinthetab2 = sin(theta/2);
  vx = v./sinthetab2;
  
  figure;
  for i = 1:360
      theta=theta+2*pi/360;
      AscentData(1+i,:)=AscentData(i,:);
      q2=[cos(theta/2),sin(theta/2)*vx];
      AscentData(1+i,5:8)=q2;
      R=quaternion_to_matrix(q2);
      vpl=R*[0 0 1]';
      vpl=[0 0 0;vpl'];
      hold on;
      plot3(vpl(:,1),vpl(:,2),vpl(:,3));
      
  end
  
  [headers,RDT]=flight_variables('FlightData01',AscentData,INTAB,INTAB4,Parachute2Alt,RailLength,RailDeclination,RailBearing);
  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  
  FT=sqrt(RDT(:,39).^2+RDT(:,40).^2);
  figure
  polar([0:(2*pi/360):(2*pi)]',RDT(:,39));
  
  figure
  polar([0:(2*pi/360):(2*pi)]',RDT(:,40),'r');
  figure
  polar([0:(2*pi/360):(2*pi)]',FT,'r');
  
  figure
  plot([0:1:360]',RDT(:,39));
  
  figure
  plot([0:1:360]',RDT(:,40),'r');
  
  figure
  plot([0:1:360]',FT,'r');
