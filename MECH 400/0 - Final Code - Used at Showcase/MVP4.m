%%%% Manual Rocket Definition for MVP-4

%%% ROCKET DEFINITION
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
M = 13.5; % [kg] mass of rocket (unloaded)
Xr = 0; % [m] radial position of point mass
Xl = 1.06; % [m] longitudinal position of point mass
pm1 = {'pm', M, Xr, Xl};

% Fin definition
n = 3; % number of fins
a = 0.279; % [m] root chord
b = 0.06; % [m] tip chord
m = 0.15; % [m] sweep length
s = 0.115; % [m] span
t = 0.0075; % [m] thickness
M = 0; % [kg] mass of the fins
d = 0.117; % [m] body diameter at fin location
dr = 0.117; % [m] maximum body diameter
X = 2.213; % [m] position of the fins
f1 = {'finset',n,a,b,m,s,t,M,d,dr,X};

% Motor definition
load('SolidMotors');
Ttable = L1685(2:end,:); % remove header data
Ttable(:,3) = (L1685(2:end,3) + (L1685(1,3)-L1685(2,3)))./1000; % Convert to total mass and [kg]
l = 0.757; % [m] length of motor
diameter = 0.075; % [m] diameter of motor
X = 1.72; % [m] position of motor
Motor = {'motor','L1685',Ttable,l,diameter,X};

% Input table builder
INTAB = intab_builder(n1,c1,pm1,f1,Motor);
INTAB1 = INTAB{1};
INTAB3 = INTAB{3};


%%% ATMOSPHERE MODEL
% Generate atmospheric data based on ISA and current T, P
T0 = 318; % [K] Temperature at launch site (MVP-2 data)
P0 = 86037; % [Pa] Pressure at launch site (MVP-2 data)
g = 9.80665; % [m/s^2] acceleration due to gravity
R = 287.0531; % [J/kgK] gas constant for dry air
lapseRate = -0.00649; % [K/m] temperature lapse rate with altitude (ISA)

% Atmosphere Calculations
height = 0:100:11000;
T = T0 + lapseRate.*(height);
P = P0.*(T0./T).^(g/R/lapseRate);
rho = P./(R.*T);

% Input table generation
INTAB4 = zeros(length(height), 6);
INTAB4(:,1) = height;
INTAB4(:,5) = rho;
INTAB4(:,6) = T;
