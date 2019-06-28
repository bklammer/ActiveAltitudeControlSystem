function [apogee] = predictor1DOF(alt, vel, Cd, state)
%PREDICTOR Takes the current state and returns the predicted apogee
% 3-DOF trajectory simulation

% INPUTS:
%   alt - altitude [m]
%   vel - vertical velocity [m/s]
%   Cd  - drag coefficient
%   state - struct holding the following fields
%       mass - scalar holding rocket mass [kg]
%       Aref - scalar holding rocket reference area [m^2]
%       T0 - scalar holding current ambient temperature [K]
%       P0 - scalar holding current ambient pressure [Pa]

% Constants
T0 = state.T0;
P0 = state.P0;
g = 9.80665; % [m/s^2] acceleration due to gravity
k = 1.4; % [] specific heat ratio for dry air
R = 287.0531; % [J/kgK] gas constant for dry air
lapseRate = -0.00649; % [K/m] temperature lapse rate with altitude (ISA)
alt0 = pos(1); % [m] altitude AMSL

% Calculations
[~, ~, ~, rho] = atmos(alt); % [kg/m^3] density of air
apogee = alt + state.m/(Cd*state.Aref*rho) * ln( Cd*state.A*state.rho/(2*state.m*g) * vel^2 + 1 );

% figure
% plot(theta_v(:,1), theta_v(:,2))
% figure
% plot(alpha_attack_v(:,1), alpha_attack_v(:,2))
% figure
% plot(F_n_v(:,1), F_n_v(:,2))
% ii = 0;

% Atmospheric model
function [T, a, P, rho] = atmos(height)
    % Assumes you don't make it to the stratosphere
    % Based on equations from "US Standard Atmosphere 1976"
    
    T = T0 + lapseRate*(height-alt0);
    a = sqrt(k*R*T);
    P = P0*(T0/T)^(g/R/lapseRate);
    rho = P/(R*T);
end

end


