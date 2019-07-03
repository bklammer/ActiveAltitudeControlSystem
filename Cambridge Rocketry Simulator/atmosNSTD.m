%atmosNSTD calculates atmospheric properties

% Inputs/Constants
T0 = 309; % [K] MVP-2 data
P0 = 86037; % [Pa] MVP-2 data
g = 9.80665; % [m/s^2] acceleration due to gravity
k = 1.4; % [] specific heat ratio for dry air
R = 287.0531; % [J/kgK] gas constant for dry air
lapseRate = -0.00649; % [K/m] temperature lapse rate with altitude (ISA)

% Calculations
% Assumes you don't make it to the stratosphere
% Based on equations from "US Standard Atmosphere 1976"
T = T0 + lapseRate.*alt;
a = sqrt(k.*R.*T);
P = P0.*(T0./T).^(g./R./lapseRate);
rho = P./(R.*T);


