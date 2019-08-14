function [state] = suborbit_airbrake()
%-------------------------------------------------------------------------%
% suborbit function
% Michael Pearson - 2016
%
% Modified by Ben Klammer for air brake calculations
%
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
% model inputs
%-------------------------------------------------------------------------%

TC1 = evalin('base','M1160'); TC1(1,3) = TC1(1,3)/1000; % Rocket motor
mass1 = 20.6;   % (kg) Liftoff mass
dia = 0.117;    % (m) Rocket diameter
nozzle_exit_dia = 0.038; % (m) Nozzle exit diameter
CdA1 = evalin('base','MVP2_RASAeroII'); % Rocket drag

air_brake_on = 1;
air_brake_area = 0.003722573;   % (m^2) from CAD
Cd_air_brake = 1.28; % for flat plate perpendicular to flow (https://www.grc.nasa.gov/WWW/k-12/airplane/shaped.html)

rail_length = 3.7;  % (m) Length between top launch lug and top of rail (assumes 5.2m launch rail and top lug 1.5m from bottom of rocket)
launchAlt = 1332;   % Launch altitude in meters (Spaceport America)
p_amb = 101325;     % (Pa) Ambient pressure during motor test (assume 1atm)


%-------------------------------------------------------------------------%
% initializations
%-------------------------------------------------------------------------%
area = pi*(dia/2)^2;            % Reference area from RASAero II
A_exit = pi*(nozzle_exit_dia/2)^2; % Nozzle exit area for thrust correction
time = 0;           % time accounting
dt = 0;             % time delta
gravloss = 0;       % determines total drag loss to delta-v

onpower = 0;        % for plot to show when engine is firing
stagesep = 0;       % for plot to show when rocket is staging

%-------------------------------------------------------------------------%
% model calculations
%-------------------------------------------------------------------------%
mass = mass1; %+TC1(1,3);   % comment out TC1 if mass includes motor
[alt1,vel1,accel1] = power(launchAlt,0,0,TC1,CdA1);
[alt2,vel2,accel2] = coast(alt1(end),vel1(end),accel1(end),CdA1);

if air_brake_on 
    air_brake_impulse = cumtrapz(air_brake_drag)*dt;
    air_brake_impulse = [NaN(size(alt1));air_brake_impulse];
    air_brake_drag(1) = NaN;
    air_brake_drag = [NaN(size(alt1));air_brake_drag];
end

alt = [alt1;alt2]; vel = [vel1;vel2]; accel = [accel1;accel2];
alt = alt-launchAlt;

%-------------------------------------------------------------------------%
% Post processing for data output
%-------------------------------------------------------------------------%
% onpower(onpower == 0) = NaN; onpower(length(alt),1) = NaN;
% stagesep(stagesep == 0) = NaN; stagesep(length(alt),1) = NaN;
% % SOoutput(alt,vel,accel,onpower,stagesep,time);
% aeroloss = (TC1(end,1)+TC2(end,1)+TC3(end,1))*9.80665;
% data(1,:) = cellstr(['m/s  ';'m/s  ';'m/s  ';'m/s  ']);
% data(2,:) = num2cell([aeroloss,gravloss,aeroloss+gravloss,...
%     aeroloss+gravloss+max(vel)]);


si = find(alt ~= 0, 1, 'first'); % First index that is not zero
ei = find(alt > rail_length, 1, 'first'); % First index that is greater than off-the-rail velocity
vel_off_rail = interp1(alt(si:ei), vel(si:ei), rail_length); % Calculate off-the-rail velocity

% 
% t = linspace(0,time,length(alt))';
% alt = [t, alt];
% vel = [t, vel];
% accel = [t, accel];

state.Itot = TC1(1,1);
state.liftoff_mass = mass1;
state.alt = max(alt);
state.vel = max(vel);
state.acc = max(accel);
state.apogee_time = time;
state.vel_off_rail = vel_off_rail;

% if air_brake_on
%     state.air_brake_drag = air_brake_drag;
%     state.apogee = max(alt);
%     state.air_brake_impulse = air_brake_impulse;
% end



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
            [~,a,p_act,rho] = atmosphere(alt(i));
            
            %%% calculate drag force %%% 
            M = vel(i)/a;
            [~,index] = min(abs(CdA(:,1)-M));
            drag = CdA(index,2)*area*0.5*rho*vel(i)^2;
            
            %%% calculate gravitational acceleration %%%
            g = grav(alt(i)); % must take into account
            
            %%% correction for sea-level thrust curves %%%
            Thrust(i,1) = TCurve(i+1,2) + (p_amb - p_act)*A_exit;
            
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
            if air_brake_on
                air_brake_drag(i+1,1) = Cd_air_brake*air_brake_area*0.5*rho*vel(i)^2;
                drag = drag + air_brake_drag(i+1,1);
            end
            
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