function [steps] = controller(Cd_error, state)
%CONTROLLER Transfer function from drag coefficient error to air brake position
% Air brake deployment angle is zero when closed, increases with increasing area

A_ref = state.A_ref; % [m^2] reference area

Cd_flat_plate = 1.28; % https://www.grc.nasa.gov/www/k-12/airplane/shaped.html
step_size = 1.8*pi/180; % [rad] 1.8 degree step size
r_motor_gear = 0.03175; % From inertia spreadsheet
r_flap_gear = 0.0127; % From inertia spreadsheet
TF = 1/(3.888e-3); % Linear fit of area to angle from Solidworks data

% Physics-based proportional control
A_diff = A_ref/Cd_flat_plate * Cd_error; % Calculate necessary change in area
theta_flap_diff = TF * A_diff; % Calculate change in flap angle
theta_motor = r_flap_gear/r_motor_gear * theta_flap_diff; % Calculate change in motor angle

steps = round(theta_motor/step_size); % Calculate number of steps necessary

end

