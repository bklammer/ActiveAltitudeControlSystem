function ParametersMenu()
clc;
disp(sprintf('//******************************************//'));
disp(sprintf('//******************************************//'));
disp(sprintf('\n\n***ROCKET FLIGHT SIMULATOR***'));
disp(sprintf('\n\nPARAMETERS MENU'));
disp(sprintf('1. Enter thrust data file'));
disp(sprintf('2. Set the amount of added nose mass'));
disp(sprintf('3. Set the wind speed and direction'));
disp(sprintf('4. Return to the Main Menu'));

stop = false;
while stop == false
    disp(sprintf('\nPlease enter the number of an option from the parameters menu and press return'));

    PMs = input(':>','s');
    PM = str2num(PMs);
    PM = uint8(PM);
    
    if (~isempty(PM) && PM>=1 && PM<=4)
        stop = true;
    else
        disp(sprintf(['!! Sorry ',PMs,' is not a recognised menu item please try again']));
    end
end

if PM==1
    EnterThrustData();
elseif PM==2
    EnterNoseMass();
elseif PM==3
    EnterWindData();
elseif PM==4
    Main_Menu();
else
    disp(sprintf('Something went wrong with the parameters menu selection'));
end
