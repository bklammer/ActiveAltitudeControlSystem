
%DRAG_PREDICTOR calculates the optimal drag coefficient based on current state

% in.alt = alt; % [m] rocket's current altitude
% in.vel = vel; % [m/s] rocket's current velocity
% in.rho = rho; % [kg/m^3] density of air
% in.m = m; % [kg] mass of rocket after burnout

target = 3048;
CdA = 0.007;
alt = 3500;
vel = 200;
rho = 1;
m = 13;

options = optimset('TolX', 1e-7);
[CdA_opt,~,exitflag] = fzero(@apogeeerror, CdA, options);

if exitflag==1
    CdA = CdA_opt;
end

a = m/rho;
b = 2*9.81/vel^2;
c = target - alt;
CdA1 = (-a*lambertw(-1,(-b*c*exp(-b*c)))-a*b*c)/c;

c1 = a/CdA1*log(CdA1/(a*b)+1);

    function apogee = apogeeerror(CdA) % Finds the difference between the estimated and actual apogee
        x = log( complex(CdA*1/(2*13*9.81)*200^2 + 1) );
        if isreal(x)
            apogee = 2500 + 13/(CdA*1) * x - 3048;
        else
            apogee = 1e9;
        end
    end

    
% 
% try
%     CdA_opt = secant(@apogeeerror, CdA, in); % Might want to use a more robust solver in the future
%     if CdA_opt > 0.001 && CdA_opt < 0.01 % Set upper and lower bounds on CdA (m^2)
%         CdA = CdA_opt;
%     end % Otherwise keep estimated term for CdA
% catch
% end
%     
% 
%     function [x] = secant(fun, x1, in)
%     %SECANT is a zero-finding function based on the secant method
%     %   'fun' is the function handle for which the zero is desired
%     %   'x1' is the initial guess
%     %   'in' is a struct containing any additional inputs 'fun' might require
%     %   'x' is the value of the zero
%         x_eps = x1*0.005; % Set the tolerance to be 0.5% of initial guess
%         x2 = x1-x1*0.01; % Set a second point 1% away from the original guess
%         F1 = fun(x1, in); % Evaluate function at x1
%         F2 = fun(x2, in); % Evaluate function at x2
%         kk = 1; % Set up counter
%         kk_max = 100;
%         while abs(x2-x1)>=x_eps && kk<kk_max % While error is too large and counter is less than max
%             x3 = x2 - F2*(x2-x1)/(F2-F1);
%             x1 = x2; % Move everything forward
%             x2 = x3;
%             F1 = F2;
%             F2 = fun(x2, in);
%             kk = kk+1;
%         end
%         x = x2;
%     end
% 
%     function apogee = apogeeerror(CdA, in) % Finds the difference between the estimated and actual apogee
% %         if CdA*in.rho/(2*in.m*9.81) * in.vel^2 + 1 <= 0
% %             sup = 0;
% %         end
%         apogee = in.alt + in.m/(CdA*in.rho) * log( CdA*in.rho/(2*in.m*9.81) * in.vel^2 + 1 ) - target;
%     end


