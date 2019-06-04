function EnterWindData()
clc;
disp(sprintf('//******************************************//'));
disp(sprintf('//******************************************//'));
disp(sprintf('\n\n***ROCKET FLIGHT SIMULATOR***'));
disp(sprintf('\n\nENTER WIND DATA'));


stop = false;
while stop == false
    disp(sprintf('\nPlease enter the wind speed in m/s'));

    Vws = input(':>','s');
    Vw = str2double(Vws);
    
    if (~isempty(Vw) && Vw>=0)
        stop = true;
    elseif(Vw<0)
        disp(sprintf(['!! Sorry negative wind speeds are not accepted']));
    else
        disp(sprintf(['!! Sorry ',Vws,' is not a recognized as a valid number']));
    end
end

stop = false;
while stop == false
    disp(sprintf('\nPlease enter the wind bearing in degrees from true North'));

    Bws = input(':>','s');
    Bw = str2double(Bws);
    
    if (~isempty(Bw) && Bw>=0 &&Bw<=360)
        stop = true;
    elseif(Bw<0 || Bw>360)
        disp(sprintf(['!! Sorry the wind bearing must be between 0 and 360 degrees']));
    else
        disp(sprintf(['!! Sorry ',Bws,' is not a recognized as a valid number']));
    end
end

load 'Rock_Param';
Rock_Param{3}=(Vw);
Rock_Param{4}=(Bw);
save 'Rock_Param' Rock_Param;
disp(sprintf(['\nA You have selected a wind speed of ',num2str(Vw),' m/s and a bearing of ',num2str(Bw),' degrees']));

disp(sprintf('\nPress return to go back to the parameters menu'));
A=input(':>','s');
ParametersMenu();