% For initial air brake trajectory analysis
clear all

load('MVP1_PostFlight.mat');
figure;
hold on;

for i=1:5
    air_brake_fraction(i) = (i-1)/4;
    [state{i}] = suborbit_airbrake_prelim(air_brake_fraction(i));
    apogee(i) = state{i}.apogee;
    
    t = linspace(0,state{i}.time,length(state{i}.alt));
    yyaxis left
    plot(t, state{i}.air_brake_drag)
    yyaxis right
    plot(t, state{i}.alt)
    
    legend_entry{i} = [num2str(air_brake_fraction(i)*100), '%'];
end

yyaxis left
% ylabel('Impulse Created by Additional Drag (Ns)');
ylabel('Additional Drag Force (N)');
yyaxis right
ylabel('Altitude (m)');
xlabel('Time (s)');
title('Effects of Increased Drag on Altitude')
legend([legend_entry, legend_entry], 'Location', 'northwest')
hold off
