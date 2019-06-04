% For initial air brake trajectory analysis
clear all

load('MVP1_PostFlight.mat');
figure;
hold on;

for i=1:10
%     mass_change(i) = (i-1);
%     [state{i}] = suborbit_masschange_prelim(mass_change(i), 0);
%     apogee(i) = state{i}.apogee;
%     
%     t = linspace(0,state{i}.time,length(state{i}.alt));
%     plot(t, state{i}.alt)
%     
%     legend_entry{i} = [num2str(mass_change(i)), ' kg'];
    
    time(i) = (i-1)*1;
    [state{i}] = suborbit_masschange_prelim(2.5, time(i));
    apogee(i) = state{i}.apogee;
    
    t = linspace(0,state{i}.time,length(state{i}.alt));
    plot(t, state{i}.alt)
    
    legend_entry{i} = [num2str(time(i)), ' s'];
end

ylabel('Altitude (m)');
xlabel('Time (s)');
title('Effects of 2.5 kg Mass Decrease at Various Times on Altitude')
legend(legend_entry, 'Location', 'southeast')
hold off
