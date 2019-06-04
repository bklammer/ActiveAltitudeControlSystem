function EnterNoseMass()
clc;
disp(sprintf('//******************************************//'));
disp(sprintf('//******************************************//'));
disp(sprintf('\n\n***ROCKET FLIGHT SIMULATOR***'));
disp(sprintf('\n\nENTER NOSE MASS'));


stop = false;
while stop == false
    disp(sprintf('\nPlease enter the mass in grams to be added to the rocket nose'));

    Nmasss = input(':>','s');
    Nmass = str2double(Nmasss);
    
    if (~isempty(Nmass) && Nmass>=0)
        stop = true;
    elseif(Nmass<0)
        disp(sprintf(['!! Sorry negative masses are not accepted']));
    else
        disp(sprintf(['!! Sorry ',Nmasss,' is not a recognized as a valid number']));
    end
end

load 'Rock_Param';
Rock_Param{2}=(Nmass/1000);
save 'Rock_Param' Rock_Param;

disp(sprintf(['\nA mass of ',num2str(Nmass),'g has been added to the rocket nose']));

disp(sprintf('\nPress return to go back to the parameters menu'));
A=input(':>','s');
ParametersMenu();
