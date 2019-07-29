hline = plot(nan);
for ii=1:1000
    temp(ii) = readVoltage(adc,0);
    
    xlim([0 1000])
    
    xlabel('readings')
    ylabel('test')
    grid on
    set(hline, 'YData',temp,'Marker', 'o')
    drawnow
end

    