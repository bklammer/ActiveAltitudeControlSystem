function Main_Menu()
clc;
disp(sprintf('//******************************************//'));
disp(sprintf('//******************************************//'));
disp(sprintf('\n\n***ROCKET FLIGHT SIMULATOR***'));
disp(sprintf('\n\nMAIN MENU'));
disp(sprintf('1. Set Rocket Parameters'));
disp(sprintf('2. Simulate a Rocket Flight'));
disp(sprintf('3. Exit Rocket Simulator'));

stop = false;
while stop == false
    disp(sprintf('\nPlease enter the number of an option from the main menu and press return'));

    MMs = input(':>','s');
    MM = str2num(MMs);
    MM = uint8(MM);
    
    if (~isempty(MM) && MM>=1 && MM<=3)
        stop = true;
    else
        disp(sprintf(['!! Sorry ',MMs,' is not a recognised menu item please try again']));
    end
end

if MM==1
    ParametersMenu();
elseif MM==2
    FlyRocketMenu();
elseif MM==3
    clc;
else
    disp(sprintf('Something went wrong with the main menu selection'));
end

        

