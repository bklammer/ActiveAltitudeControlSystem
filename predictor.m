function [alt] = predictor(pos, vel, C_a, C_n, C_p, mass, I, Aref, T0, P0)
%PREDICTOR Takes the current state and returns the predicted apogee
% 3-DOF trajectory simulation

% INPUTS:
%   pos - 2x1 vector holding altitude [m] and angle [rad] from vertical
%   vel - 3x1 vector holding axial, normal [m/s], and angular velocities [rad/s]
%   C_a - scalar holding axial force coefficient
%   C_n - scalar holding normal force coefficient [1/rad]
%   C_p - scalar holding center of pressure measured from Cg [m]
%   mass - scalar holding rocket mass [kg]
%   I - scalar holding the moment of inertia of the rocket [kg*m^2]
%   Aref - scalar holding rocket reference area [m^2]
%   T0 - scalar holding current ambient temperature [K]
%   P0 - scalar holding current ambient pressure [Pa]

% ASSUMPTIONS:
%   Aerodynamics (idealized subsonic flight)
%       - Constant drag coefficient
%       - Constant center of pressure
%       - Air is still (no lift forces)
%   Rocket Dynamics (after motor burnout)
%       - No thrust
%       - Constant mass
%       - Constant center of gravity

% Initializations
alt = pos(1); % [m] altitude AMSL
theta = pos(2); % [rad] angle of rocket axis from vertical
vel_a = vel(1); % [m/s] axial velocity
vel_n = vel(2); % [m/s] normal velocity
omega = vel(3); % [rad/s] rocket angular velocity

% Convert velocities to x and y
vel_x = vel_a*sin(theta) + vel_n*cos(theta);
vel_y = vel_a*cos(theta) - vel_n*sin(theta);

% Constants
t = 0; % [s] time
dt = 0.01; % [s] time step
epsilon = 0; % [m/s] velocity end condition
g = 9.80665; % [m/s^2] acceleration due to gravity
k = 1.4; % [] specific heat ratio for dry air
R = 287.0531; % [J/kgK] gas constant for dry air
lapseRate = 0.00649; % [K/m] temperature lapse rate with altitude (ISA)
heightTroposphere = 11000; % [m] ISA
heightTropopause = 20000; % [m] ISA
rho0 = P0/(R*T0); % [kg/m^3] initial density (ideal gas law)
alt0 = pos(1); % [m] altitude AMSL

ii = 1;
while vel_y > -1000 %epsilon % While velocity is larger than some small value
    
    
    % Aerodynamic Force Calculations
    alpha_attack = atan(vel_n/vel_a); % [rad] angle of attack (assuming no wind)
    [~, ~, ~, rho] = atmos(alt-alt0); % [kg/m^3] density of air
    F_a = -C_a*Aref*rho*(vel_a^2 + vel_n^2)/2; % [N] axial force
    F_n = C_n*alpha_attack*Aref*rho*(vel_a^2 + vel_n^2)/2; % [N] normal force
    F_x = F_a*sin(theta) + F_n*cos(theta); % [N] force in x
    F_y = F_a*cos(theta) - F_n*sin(theta); % [N] force in y
    
    
    % Force balance
    a_x = F_x/mass; % [m/s^2] lateral acceleration
    a_y = F_y/mass - g; % [m/s^2] vertical acceleration
    alpha = -F_n*C_p/I; % [rad/s^2] angular acceleration
    
    % Numerical integration for velocity
    vel_x = a_x*dt + vel_x; % [m/s] lateral velocity
    vel_y = a_y*dt + vel_y; % [m/s] vertical velocity
    omega = alpha*dt + omega; % [rad/s] angular velocity
    
    % Numerical integration for position
    alt = vel_y*dt + alt; % [m] altitude
    theta = omega*dt + theta; % [rad] angle from vertical
    
    % Convert velocities to normal and axial
    vel_a = vel_x*sin(theta) + vel_y*cos(theta); % [m/s] axial velocity
    vel_n = vel_x*cos(theta) - vel_y*sin(theta); % [m/s] normal velocity
    
    % Counters
    t = t + dt;
    ii = ii + 1;
    
    % Saving vectors
    alt_v(ii,:) = [t, alt];
    theta_v(ii,:) = [t, theta];
    vel_x_v(ii,:) = [t, vel_x];
    F_n_v(ii,:) = [t, F_n];
    alpha_attack_v(ii,:) = [t, alpha_attack];
end

figure
plot(F_n_v(:,1), F_n_v(:,2))
ii = 0;

% Atmospheric model
function [T, a, P, rho] = atmos(height)
    % Doesn't seem to be calculating density properly
    [T, a, P, rho] = atmoslapse(height, g, k, R, lapseRate, ...
        heightTroposphere, heightTropopause, rho0, P0, T0, alt0);
end

end


