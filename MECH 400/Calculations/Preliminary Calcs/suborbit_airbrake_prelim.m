function [state] = suborbit_airbrake_prelim(air_brake_fraction, varargin) % [alt, vel, acc]
%-------------------------------------------------------------------------%
% suborbit function
% Michael Pearson - 2016
%-------------------------------------------------------------------------%
% Function Description
%-------------------------------------------------------------------------%
% Calculates the altitude, velocity and acceleration of a rocket.  Basic
% inputs are stages, which can be used alone, and the thrust curves and
% masses.  These can be specified in the function call using varargin, or
% by not using varargin and instead specifying them below in the if
% statement at the start.
%----
% Function call using varargin input as follows: where 1,2,3 are the stages
%    suborbit(stages,diameter,motor1,mass1,motor2,mass2,motor3,mass3)
% where stages = 1,2,3; diameter in meters; mass in kg; motor from variable
%----
% TCurve contains burn time in column 1, thrust data in column 2, and mass
% in column 3.  The first row contains total impulse in column 1, average 
% thrust in column 2, total mass including propellant and case in column 3.
%----
% The drag coefficient format has Mach number in column 1, coefficient of
% drag with power on in column 2, and coefficient of drag with power off in
% column 3.
%-------------------------------------------------------------------------%
%                                  _
%                                 / \
%                                 | |
%                                 | |
%                                 | |
%                                /| |\
%                               / | | \
%                               |/| |\|
%                               ' *** '
%                                  *
%-------------------------------------------------------------------------%
% assign drag values for each stage and choose staging time
%-------------------------------------------------------------------------%
% CdA1 = evalin('base','Cdavg');    % drag coefficient for full rocket
% CdA2 = evalin('base','CdA');    % drag coeff for 2nd or 2nd&3rd stage
% CdA3 = evalin('base','CdA');    % drag coeff for 3rd stage

stgt = 5;                       % time to stage vehicle in seconds

%-------------------------------------------------------------------------%
% specify motor and mass data in case varargin is empty
%-------------------------------------------------------------------------%
if isempty(varargin)
    % Post flight trajectory analysis
    stages = 1; % Only one stage
    TC1 = evalin('base','M1830'); TC1(1,3) = TC1(1,3)/1000; % Rocket motor
    mass1 = 17.1;   % (kg) stage 1 mass without motor
    dia = 0.117;    % (m) rocket diameter
    CdA1 = evalin('base','MVP1_RASAeroII'); % Rocket drag
%     air_brake_fraction = 0; % Fraction that drag is increased by air brakes
else
    dia = varargin{1};  % if varargin is not empty, first index is diameter    
end

%-------------------------------------------------------------------------%
% Variability check for software validation
%-------------------------------------------------------------------------%
% In case of there being a 4th varargin, knows it is validating
if length(varargin) == 4
    TC1 = evalin('base',varargin{2});TC1(1,3) = TC1(1,3)/1000;
    % Below accounts for 4% variability in motor delivered impulse
    if strcmp(varargin{4},'Cdverylow')   
        TC1 = TC1*1.04;
    else
        TC1 = TC1*0.9615;
    end
    mass1 = varargin{3};
    CdA1 = evalin('base',varargin{4});
end

%-------------------------------------------------------------------------%
% create variables and 
%-------------------------------------------------------------------------%
% area = pi*(1.05*dia/2)^2;       % factor of 1.1 accounts for fins
area = pi*(dia/2)^2;            % Reference area from RASAero II
time = 0;           % time accounting
dt = 0;             % time delta
gravloss = 0;       % determines total drag loss to delta-v

onpower = 0;        % for plot to show when engine is firing
stagesep = 0;       % for plot to show when rocket is staging

launchAlt = 1400;   % Launch altitude in meters (Spaceport America)

switch stages
    case 1  % one stage
        if length(varargin) == 3
            TC1 = evalin('base',varargin{2});TC1(1,3) = TC1(1,3)/1000;
            mass1 = varargin{3};
        end
        mass = mass1+TC1(1,3);   % comment out TC1 if mass includes motor
        [alt1,vel1,accel1] = power(launchAlt,0,0,TC1,CdA1);
        [alt2,vel2,accel2] = coast(alt1(end),vel1(end),accel1(end),CdA1);
        
        air_brake_impulse = cumtrapz(air_brake_drag)*dt;
        air_brake_impulse = [NaN(size(alt1));air_brake_impulse];
        air_brake_drag(1) = NaN;
        air_brake_drag = [NaN(size(alt1));air_brake_drag];
        alt = [alt1;alt2]; vel = [vel1;vel2]; accel = [accel1;accel2];
        alt = alt-launchAlt;
        TC2 = 0; TC3 = 0;
    case 2  % two stages
        if length(varargin) == 5
            TC1 = evalin('base',varargin{2});TC1(1,3) = TC1(1,3)/1000;
            TC2 = evalin('base',varargin{4});TC2(1,3) = TC2(1,3)/1000;
            mass1 = varargin{3};
            mass2 = varargin{5};
        end
        mass = mass1+mass2+TC1(1,3)+TC2(1,3);
        [alt1,vel1,accel1] = power(launchAlt,0,0,TC1,CdA1);
        mass = mass2+TC2(1,3);
        [alt2,vel2,accel2] = staging(alt1(end),vel1(end),accel1(end),CdA1);
        [alt3,vel3,accel3] = power(alt2(end),vel2(end),accel2(end),...
            TC2,CdA2);
        [alt4,vel4,accel4] = coast(alt3(end),vel3(end),accel3(end),CdA2);
        
        alt = [alt1;alt2;alt3;alt4]; vel = [vel1;vel2;vel3;vel4];
        accel = [accel1;accel2;accel3;accel4];
        TC3 = 0;
    case 3  % three stages
        if length(varargin) == 7
            TC1 = evalin('base',varargin{2});TC1(1,3) = TC1(1,3)/1000;
            TC2 = evalin('base',varargin{4});TC2(1,3) = TC2(1,3)/1000;
            TC3 = evalin('base',varargin{6});TC3(1,3) = TC3(1,3)/1000;
            mass1 = varargin{3};
            mass2 = varargin{5};
            mass3 = varargin{7};
        end
        mass = mass1+mass2+mass3+TC1(1,3)+TC2(1,3)+TC3(1,3);
        [alt1,vel1,accel1] = power(launchAlt,0,0,TC1,CdA1);
        mass = mass2+mass3+TC2(1,3)+TC3(1,3);
        [alt2,vel2,accel2] = staging(alt1(end),vel1(end),accel1(end),CdA1);
        [alt3,vel3,accel3] = power(alt2(end),vel2(end),accel2(end),...
            TC2,CdA2);
        mass = mass3+TC3(1,3);
        [alt4,vel4,accel4] = staging(alt3(end),vel3(end),accel3(end),CdA2);
        [alt5,vel5,accel5] = power(alt4(end),vel4(end),accel4(end),...
            TC3,CdA2);
        [alt6,vel6,accel6] = coast(alt5(end),vel5(end),accel5(end),CdA3);
        
        alt = [alt1;alt2;alt3;alt4;alt5;alt6];
        vel = [vel1;vel2;vel3;vel4;vel5;vel6];
        accel = [accel1;accel2;accel3;accel4;accel5;accel6];
    otherwise
        error('Please pick 1 to 3 stages');
end

%-------------------------------------------------------------------------%
% Post processing for data output
%-------------------------------------------------------------------------%
onpower(onpower == 0) = NaN; onpower(length(alt),1) = NaN;
stagesep(stagesep == 0) = NaN; stagesep(length(alt),1) = NaN;
% SOoutput(alt,vel,accel,onpower,stagesep,time);
aeroloss = (TC1(end,1)+TC2(end,1)+TC3(end,1))*9.80665;
data(1,:) = cellstr(['m/s  ';'m/s  ';'m/s  ';'m/s  ']);
data(2,:) = num2cell([aeroloss,gravloss,aeroloss+gravloss,...
    aeroloss+gravloss+max(vel)]);

% air_brake_impulse = cumtrapz(air_brake_drag(~isnan(air_brake_drag)))*dt;

state.time = time;
state.alt = alt;
state.vel = vel;
state.acc = accel;
state.air_brake_drag = air_brake_drag;
state.apogee = max(alt);
state.air_brake_impulse = air_brake_impulse;



% *** To output delta-v data table, uncomment this section ***
% array2table(data,'VariableNames'...
%         ,{'AeroLoss' 'GravityLoss' 'TotalLoss' 'TotalDeltaV'},...
%         'RowNames',{'Units','Value'})

    
%-------------------------------------------------------------------------%
%-------------------------------------------------------------------------%
%                               /  |  
% Sub Functions         ,------'   '-------..
%                      (____________________-+    	
%-------------------------------------------------------------------------%
%-------------------------------------------------------------------------%
    
%-------------------------------------------------------------------------%
% Rocket motor producing thrust
%-------------------------------------------------------------------------%
    function [alt,vel,accel] = power(alt,vel,accel,TCurve,CdA)
        dt = TCurve(end,1)/length(TCurve);
        plen = length(onpower);
        
        for i=1:(length(TCurve)-2)
            %%% calculate atmospheric conditions %%%
            [~,a,~,rho] = atmosphere(alt(i));
            
            %%% calculate drag force %%% 
            M = vel(i)/a;
            [~,index] = min(abs(CdA(:,1)-M));
            drag = CdA(index,2)*area*0.5*rho*vel(i)^2;
            
            %%% calculate gravitational acceleration %%%
            g = grav(alt(i)); % must take into account
            
            %%% correction for sea-level thrust curves %%%
            Thrust(i,1) = TCurve(i+1,2); % + (p_amb - p_act)*A_exit;
            
            %%% calculate acceleration, velocity and altitude %%%
            accel(i+1,1) = (Thrust(i)-drag)/mass-g;
            vel(i+1,1) = accel(i)*dt+vel(i); 
            alt(i+1,1) = vel(i)*dt+((accel(i)*dt^2)/2) +alt(i);
            
            if alt(i+1,1) < launchAlt   % check if hit ground
                alt(i+1,1) = launchAlt;
                vel(i+1,1) = 0;
                accel(i,1) = 0;
            end
            
            onpower(i+plen+1,1) = alt(i+1,1);       % for plotting
            stagesep(i+plen+1,1) = NaN;             % for plotting
            
            mass = mass - (TCurve(i+1,3)-TCurve(i+2,3))/1000;
            time = time + dt;
            gravloss = gravloss + (drag*dt/mass);
        end
    end % end power

%-------------------------------------------------------------------------%
% Rocket Coasting to apogee
%-------------------------------------------------------------------------%
    function [alt,vel,accel] = coast(alt,vel,accel,CdA)
        i = 1;
        plen = length(onpower);
        air_brake_drag(1) = 0;
        
        while vel(i) > 0
            %%% calculate atmospheric conditions %%%
            [~,a,~,rho] = atmosphere(alt(i));
            
            %%% calculate drag force %%% 
            M = vel(i)/a;
            [~,index] = min(abs(CdA(:,1)-M));
            drag = CdA(index,3)*area*0.5*rho*vel(i)^2;
            
            %%% Air brake stuff %%%
            air_brake_drag(i+1,1) = drag*air_brake_fraction;
            drag = drag + air_brake_drag(i+1,1);
            
            %%% calculate gravitational acceleration %%%
            g = grav(alt(i)); % must take into account
            
            %%% calculate acceleration, velocity and altitude %%%
            accel(i+1,1) = -drag/mass-g;
            vel(i+1,1) = accel(i)*dt+vel(i);
            alt(i+1,1) = vel(i)*dt+((accel(i)*dt^2)/2) +alt(i);
            
            if alt(i+1,1) < launchAlt   % check if hit ground
                alt(i+1,1) = launchAlt;
                vel(i+1,1) = 0;
                accel(i+1,1) = 0;
            end
            
            onpower(i+plen,1) = NaN;          % for plotting
            stagesep(i+plen,1) = NaN;         % for plotting
            
            i = i + 1;
            time = time + dt;
            gravloss = gravloss + (drag*dt/mass);
        end
    end % end coast

%-------------------------------------------------------------------------%
% Rocket staging - differenct from coast, but includes coast period
%-------------------------------------------------------------------------%
    function [alt,vel,accel] = staging(alt,vel,accel,CdA)
        st = 0;             
        i = 1;
        plen = length(onpower);
        
        while st <= stgt      
            %%% calculate atmospheric conditions %%%
            [~,a,~,rho] = atmosphere(alt(i));
            
            %%% calculate drag force %%% 
            M = vel(i)/a;
            [~,index] = min(abs(CdA(:,1)-M));
            drag = CdA(index,2)*area*0.5*rho*vel(i)^2;
            
            %%% calculate gravitational acceleration %%%
            g = grav(alt(i)); % must take into account
            
            %%% calculate acceleration, velocity and altitude %%%
            accel(i+1,1) = -drag/mass-g;
            vel(i+1,1) = accel(i+1)*dt+vel(i); 
            alt(i+1,1) = vel(i+1)*dt+((accel(i+1)*dt^2)/2)+alt(i);
            
            if alt(i+1,1) < launchAlt   % check if hit ground
                alt(i+1,1) = launchAlt;
                vel(i+1,1) = 0;
                accel(i+1,1) = 0;
            end
            
            onpower(i+plen,1) = NaN;                % for plotting
            stagesep(i+plen,1) = alt(i+1,1);        % for plotting
            
            i = i + 1;
            time = time + dt;
            st = st + dt;
            gravloss = gravloss + (drag*dt/mass);
        end
    end % end staging

end % end main program
%-------------------------------------------------------------------------%
%-------------------------------------------------------------------------%

%% Calculates the atmosperic conditions at altitude using atmostnonstd
function [T,a,P,rho] = atmosphere(alt)
[T,a,P,rho] = atmosisa(alt);
% alt(alt < 1) = 1;
% altextreme = 10*ceil(alt/10000); altextreme(altextreme > 40) = 40;
% alt(alt > 79000) = 79000;
% [T,a,P,rho]...      % index 3 = air pressure in Pascals
%     = atmosnonstd(alt,'Profile','High density','1%',altextreme);
% P(P<0) = 1e-10;
end

%% Calculates gravitational acceleration at altitude
function g = grav(alt)
g = (6.67408e-11*5.972e24)/(6.371e6+alt)^2;   
end

%% Outputs data and creates plots
function SOoutput(alt,vel,accel,onpower,stagesep,time)
data(1,:) = cellstr(['m    ';'m/s  ';'m/s^2';'s    ']);
data(2,:) = num2cell([max(alt),max(vel),max(accel),time]);

% *** To output performance table, uncomment this section ***
array2table(data,'VariableNames'...
        ,{'Apogee' 'Vmax' 'Accelmax' 'TimeToApogee'},'RowNames'...
        ,{'Units','Value'})

t = linspace(0,time,length(alt));
plot(t,vel,t,accel);
xlim([0,t(end)]);
ylim([-500,max(alt)*1.1]);
xlabel('Time (s)');
ylabel('Altitude (m)');
hold on
% comet(t,alt)
plot(t,alt)
plot([0,t(end)],[100000,100000],':')
plot(t,onpower,'Linewidth',2)
plot(t,stagesep,'c','Linewidth',2)
hold off

end