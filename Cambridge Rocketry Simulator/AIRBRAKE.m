function [Cd] = AIRBRAKE(state)
%AIRBRAKE models the entire air brake system

if state.thrust == 0 && state.tt > 1 % Need a better way to detect_burnout
    % state = filter(state); % Filters incoming data and returns observed state
    Cd_opt = drag_predictor(state.Cd, state.vel, state.alt, state); % Determines the optimal drag coefficient
    Cd_error = Cd_opt - state.Cd; % Calculate the drag coefficient error
    signal = controller(Cd_error, state); % Calculates control signal for airbrake actuation
    % Cd = system(signal); % High fidelity model that converts the control command to drag coefficient value
    Cd = Cd_opt;
    
else
    Cd = state.Cd;
    signal = 0;
end

% if rem(state.plot, 50) == 0
%     scatter(state.tt, signal)
%     hold on
% end

end

