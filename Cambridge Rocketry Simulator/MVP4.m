%Cambridge Rocketry Simulator
%Template for a single stage rocket simulation
%S.Box 15 June 2008

function MVP4()
%%% Define rocket

% Nosecone definition
L = 0.339; % [m] length of nosecone
d = 0.117; % [m] diameter at base of nosecone
M = 0; % [kg] mass of nosecone
X = 0; % [m] distance of front of nose cone from front of rocket
n1 = {'nose','ogive',L,d,M,X};

% Body definition
L = 2.138; % [m] length of body
d = 0.117; % [m] diameter of tube
M = 0; % [kg] mass of body
X = 0.339; % [m] distance of front of tube from nosecone tip
c1 = {'cylinder','yes',L,d,M,X};

% Centre of gravity definition
M = 11.6; % [kg] mass of rocket (unloaded)
Xr = 0; % [m] radial position of point mass
Xl = 1.06; % [m] longitudinal position of point mass
pm1 = {'pm', M, Xr, Xl};

% Fin definition
n = 3; % number of fins
a = ; % [m] root chord
b = ; % [m] tip chord
m = ; % [m] sweep length
s = ; % [m] span
t = ; % [m] thickness
M = 0; % [kg] mass of the fins
d = 0.117; % [m] body diameter at fin location
dr = 0.117; % [m] maximum body diameter
X = ; % [m] position of the fins
f1 = {'finset',n,a,b,m,s,t,M,d,dr,X};

% Motor definition
Ttable = load('L1685');
Ttable = Ttable(2:end,:); % remove header data
length = ; % [m] length of motor
diameter = ; % [m] diameter of motor
X = ; % [m] position of motor
Motor = {'motor','L1685',Ttable,length,diameter,X};

% Input table builder
INTAB = intab_builder(n1,c1,pm1,f1,Motor);

load 'intab_CLV2s1_K660.mat'; %Loads the rocket data into a variable called INTAB
load 'intab4_2006100809.mat'; %Loads the atmospheric data into a variable called INTAB4

Parachute2Alt=300; %Altitude at which the rocket's second parachute will deploy in meters
RailLength=2;      %Length of the launching rail in meters
RailDeclination=6; %Angle of declination of the launching rail in degrees
RailBearing=0;     %Bearing of the launching rail in degrees from true north

figure

%%% Run the rocket flight simulator %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

[AscentData,DescentData,Landing,Apogee]=rocketflightAIRBRAKE(INTAB,INTAB4,Parachute2Alt,RailLength,RailDeclination,RailBearing);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


