function FlyRocketMenu()
clc;
disp(sprintf('//******************************************//'));
disp(sprintf('//******************************************//'));
disp(sprintf('\n\n***ROCKET FLIGHT SIMULATOR***'));
disp(sprintf('\n\nROCKET LAUNCHER'));

load 'Rock_Param';
disp(sprintf('\nThe rocket will be launched with the following parameters:'));
if (strcmp(Rock_Param{5},'Default')==1)
    disp(sprintf('\nThe default thrust data will be used.'));
else
    disp(sprintf('Thrust data are read from: %s.',Rock_Param{5}));
end
disp(sprintf('The volume of water in the rocket is %s l.',(num2str(Rock_Param{6}))));
disp(sprintf('The nose weight added to the rocket is %d g.',(Rock_Param{2}*1000)));
disp(sprintf('The wind speed is %d m/s.',Rock_Param{3}));
disp(sprintf('The wind bearing is %d degrees.',Rock_Param{4}));

disp(sprintf('\nTo alter any of the above parameters go back to the main menu \nand select the \"Set Rocket Parameters\" option.'));

stop = false;
while stop == false
    disp(sprintf('\nEnter \"L\" to launch the rocket or \"M\" to return to the main menu.'));

    Ucode = input(':>','s');
    Ucode = lower(Ucode);
    
    if (strcmp(Ucode,'l')==1 || strcmp(Ucode,'m')==1)
        stop = true;
    else
        disp(sprintf(['!! Sorry the command you entered was not recognized please try again.']));
    end
end

if (strcmp(Ucode,'l')==1)
    disp(sprintf('\nFlight simulation in progress...'));
    AD=LaunchWaterRocket(Rock_Param{1},Rock_Param{3},Rock_Param{4},Rock_Param{2},Rock_Param{6});
    disp(sprintf('\nPOST SIMULATION MENU'));
    disp(sprintf('\n1. Watch an animation of the rocket flight.'));
    disp(sprintf('2. Run the simulation again.'));
    disp(sprintf('3. Return to the main menu.'));
    stop=false;
    while stop == false
        disp(sprintf('\nPlease enter the number of an option from the post simulation menu and press return'));

        Ucodes = input(':>','s');
        Ucode = str2num(Ucodes);
        Ucode = uint8(Ucode);

        if (~isempty(Ucode) && Ucode>=1 && Ucode<=3)
            stop = true;
        else
            disp(sprintf(['!! Sorry ',Ucodes,' is not a recognized menu item please try again']));
        end
    end
    
    if (Ucode==1)
        AnimateRocket(AD);
    elseif (Ucode==2)
        FlyRocketMenu();
    elseif (Ucode==3)
        Main_Menu();
    else
        disp(sprintf('Something went wrong with the post simulation menu selection'));
    end
    
else
    Main_Menu();
end
    

