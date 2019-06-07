function EnterThrustData()
clc;
disp(sprintf('//******************************************//'));
disp(sprintf('//******************************************//'));
disp(sprintf('\n\n***ROCKET FLIGHT SIMULATOR***'));
disp(sprintf('\n\nENTER THRUST DATA'));


stop = false;
while stop == false
    disp(sprintf('\nPlease enter the full path and filename (including extension) of a thrust data file.'));
    disp(sprintf('Or enter "D" to use default data.'));

    fPATH = input(':>','s');
    
    if (strcmp(lower(fPATH),'d')~=1)
        [fid,message] = fopen(fPATH);
        
        if (fid == -1)
            disp(sprintf(['\n!! Sorry there was a problem reading the file: ',fPATH]));
            disp(sprintf(['System Message: ',message]));
        else
            stop=true;
        end
    else
        stop=true;
    end       
end

if (strcmp(lower(fPATH),'d')==1)
    disp(sprintf('\nYou have selected to use the default thrust data'));
else
    %%Add stuff here to read thrust data using the fid;
    %Ttab=EasySenseConvert(fPATH);
    Ttab=SIDread(fPATH);
    load 'Rock_Param';
    Rock_Param{1}=Ttab;
    Rock_Param{5}=fPATH;
    disp(sprintf('\nTrust data from file: %s has been loaded',fPATH));
    
    stop = false;
    while stop == false
        disp(sprintf('\nPlease now enter the Volume of water in litres added to the rocket'));

        Wmasss = input(':>','s');
        Wmass = str2double(Wmasss);

        if (~isempty(Wmass) && Wmass>=0)
            stop = true;
        elseif(Wmass<0)
            disp(sprintf(['!! Sorry negative masses are not accepted']));
        else
            disp(sprintf(['!! Sorry ',Wmasss,' is not a recognized as a valid number']));
        end
    end
    Rock_Param{6}=Wmass;
    save 'Rock_Param' Rock_Param;
    disp(sprintf('\nThe volume of water added to the rocket is %s litres',Wmasss));
end

disp(sprintf('\nPress return to go back to the parameters menu'));
A=input(':>','s');
ParametersMenu();

    

