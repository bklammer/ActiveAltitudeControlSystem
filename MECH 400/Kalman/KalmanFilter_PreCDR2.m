% import trajectory data, initialization
load("Flight_w_Gyro_Data.mat");
load("Actual_Flight_Data_2016.mat");
V_Act = Coarse_Flight_Data(:,5);
Z_Act = Coarse_Flight_Data(:,4);

%imported simulation data
Pr = Airpressurembar(1:516)*100;
Z = Altitudem(1:516); 
Y = PositionNorthoflaunchm(1:516);
X = PositionEastoflaunchm(1:516);
phi_dot = Rollraters(1:516);
theta_dot = Pitchraters(1:516);
psi_dot = Yawraters(1:516);
Cd = Dragcoefficient(1:516);
AZ = Verticalaccelerationms(1:516);
AY = Lateralaccelerationms(1:516);
AX = sqrt((Totalaccelerationms.^2)-(Lateralaccelerationms.^2));
AX = AX(1:516);
VZ = Verticalvelocityms(1:516);
VY = Lateralvelocityms(1:516);
VX = sqrt((Totalvelocityms.^2)-(Lateralvelocityms.^2));
VX = VX(1:516);
Ar = 160/100000; 
t = Times(1:516);

T_import = AirtemperatureC(1:516) + 273;
size = 516;
g = 9.81;
Ix = 14;
Iy = 14;
Iz = 0.06;
m = 15.5;
L = -0.0065;
ho = 1200;
To = 287;
Po = 87500;
rate = 0.002;
Rconst = 287.058;
rho = Pr./(Rconst.*T_import);
psi = zeros(1,size);
theta = zeros(1,size);
phi = zeros(1,size);

%perturbed sensor data
% rng('shuffle');
% phi_dot_P = phi_dot+ (20*rand() - 10);
% theta_dot_P = theta_dot + (20*rand() - 10);
% psi_dot_P = psi_dot + (20*rand() - 10);
% AZ_P = AZ + (20*rand() - 10);
% AY_P = AY + (20*rand() - 10);
% AX_P = AX + (20*rand() - 10);
% Pr_P = Pr + (20*rand() - 10);
AZ_P = Coarse_Flight_Data(:,2);
Pr_P = Coarse_Flight_Data(:,3);

%Kalman Filter initialization
Rot = eye(3);
Q = 100.*eye(14);
R = 5;
P = 100.*eye(14);
A = zeros(14);
%H = zeros(7,15);
H = [0,0,0,0,0,1,0,0,0,0,0,0,0,0];
% H = [0,1,0,0,0,0,0,0,0,0,0,0,0,0;
%      0,0,0,1,0,0,0,0,0,0,0,0,0,0;
%      0,0,0,0,0,1,0,0,0,0,0,0,0,0;
%      0,0,0,0,0,0,0,1,0,0,0,0,0,0;
%      0,0,0,0,0,0,0,0,0,1,0,0,0,0;
%      0,0,0,0,0,0,0,0,0,0,0,1,0,0];
%      0,0,0,0,0,0,0,0,0,0,0,0,0,1,0];
 
 for index = 2:size %Rot is empty
%     psi(i) = trapz([psi_dot(i-1) psi_dot(i)]).*(t(i) - t(1));
%     theta(i) = trapz([theta_dot(i-1) theta_dot(i)]).*(t(i) - t(1));
%     phi(i) = trapz([phi_dot(i-1) phi_dot(i)]).*(t(i) - t(1));
    
%     psi(index) = psi(index-1) + rate*psi_dot(index);
%     theta(index) = theta(index-1) + rate*theta_dot(index);
%     phi(index) = phi(index-1) + rate*phi_dot(index);

    psi(index) = 0;
    theta(index) = 0;
    phi(index) = 0;
    
    Rot(1,1) = cosd(phi(index))*cosd(theta(index));
    Rot(1,2) = -sind(phi(index))*cosd(psi(index))+cosd(phi(index))*sind(theta(index))*sind(psi(index));
    Rot(1,3) = sind(phi(index))*sind(psi(index))+cosd(phi(index))*sind(theta(index))*cosd(psi(index));
    Rot(2,1) = sind(phi(index))*cosd(theta(index));
    Rot(2,2) = cosd(phi(index))*cosd(psi(index))+sind(phi(index))*sind(theta(index))*sind(psi(index));
    Rot(2,3) = -cosd(phi(index))*sind(psi(index))+sind(phi(index))*sind(theta(index))*cosd(psi(index));
    Rot(3,1) = -sind(theta(index));
    Rot(3,2) = cosd(theta(index))*sind(psi(index));
    Rot(3,3) = cosd(theta(index))*cosd(psi(index));
    
    body_xyz(:,index) = Rot*[X(index);Y(index);Z(index)];  
    body_vxyz(:,index) = Rot*[VX(index);VY(index);VZ(index)];
 end
 
 x_nom = [body_xyz(1,:);
          body_vxyz(1,:);
          body_xyz(2,:);
          body_vxyz(2,:);
          body_xyz(3,:)+1200;
          body_vxyz(3,:);
          psi;
          psi_dot';
          theta;
          theta_dot';
          phi;
          phi_dot';
          Cd'
          %rho';
          Ar*ones(1,size)];
      
 %x = [0,0,0,0,0,16,0,0,0,0,0,0,0.43,1200,Ar]';
 x = [0,0,0,0,0,0,0,0,0,0,0,0,0,0]';
 Cd_hat = zeros(1,size);
 Z_hat = zeros(1,size);
 V_hat = zeros(1,size);
 Ar_hat = zeros(1,size);
 Vx_P = zeros(1,size);
 Vy_P = zeros(1,size);
 Vz_P = zeros(1,size);
 psi_P = zeros(1,size);
 theta_P = zeros(1,size);
 phi_P = zeros(1,size);
 x_out = zeros(14,size);
 h_prime = zeros(1,size);
 h = zeros(1,size);
%  gamma = 5*10^3;
%  gamma_max = gamma;
%  tau = 0.0000001;
%  h(1) = ho;
 
for index=2:size
%     psi_P(i) = trapz([psi_dot_P(i-1) psi_dot_P(i)]).*(t(i) - t(1));
%     theta_P(i) = trapz([theta_dot_P(i-1) theta_dot_P(i)]).*(t(i) - t(1));
%     phi_P(i) = trapz([phi_dot_P(i-1) phi_dot_P(i)]).*(t(i) - t(1));
    
%     psi_P(index) = psi_P(index-1) + rate*psi_dot_P(index);
%     theta_P(index) = theta_P(index-1) + rate*theta_dot_P(index);
%     phi_P(index) = phi_P(index-1) + rate*phi_dot_P(index);

    psi_P(index) = 0;
    theta_P(index) = 0;
    phi_P(index) = 0;
    
    Rot(1,1) = cosd(phi_P(index))*cosd(theta_P(index));
    Rot(1,2) = -sind(phi_P(index))*cosd(psi_P(index))+cosd(phi_P(index))*sind(theta_P(index))*sind(psi_P(index));
    Rot(1,3) = sind(phi_P(index))*sind(psi_P(index))+cosd(phi_P(index))*sind(theta_P(index))*cosd(psi_P(index));
    Rot(2,1) = sind(phi_P(index))*cosd(theta_P(index));
    Rot(2,2) = cosd(phi_P(index))*cosd(psi_P(index))+sind(phi_P(index))*sind(theta_P(index))*sind(psi_P(index));
    Rot(2,3) = -cosd(phi_P(index))*sind(psi_P(index))+sind(phi_P(index))*sind(theta_P(index))*cosd(psi_P(index));
    Rot(3,1) = -sind(theta_P(index));
    Rot(3,2) = cosd(theta_P(index))*sind(psi_P(index));
    Rot(3,3) = cosd(theta_P(index))*cosd(psi_P(index));
    
%     a = Rot*[AX_P(index);AY_P(index);AZ_P(index)];
%     Ax_P(index) = a(1);
%     Ay_P(index) = a(2);
%     Az_P(index) = a(3);
    
%     V0 = Rot*[0;0;16]; 
    
%     Vx_P(i) = trapz([Ax_P(i-1) Ax_P(i)]).*(t(i) - t(1))+Vx_P(i-1);
%     Vy_P(i) = trapz([Ay_P(i-1) Ay_P(i)]).*(t(i) - t(1))+Vy_P(i-1);
%     Vz_P(i) = trapz([Az_P(i-1) Az_P(i)]).*(t(i) - t(1))+Vz_P(i-1);

%       Vx_P(index) = Vx_P(index-1) + rate*Ax_P(index);
%       Vy_P(index) = Vy_P(index-1) + rate*Ay_P(index);
%       Vz_P(index) = Vz_P(index-1) + rate*Az_P(index);
        Vz_P(index) = Vz_P(index-1) + rate*AZ_P(index);
    
%     h_prime(i) = trapz([AZ_P(i-1) AZ_P(i)]).*(t(i) - t(1))+16;
%     h = trapz([h_prime(i-1) h_prime(i)]).*(t(i) - t(1))+ho;
%     h_prime(i) = h_prime(i-1) + rate*AZ_P(i);
%     h(i)       = h(i-1) + rate*h_prime(i);
      temp = Rot\[x_out(1,index-1);x_out(3,index-1);x_out(5,index-1)];
      h(index) = temp(3);
    T = L*(h(index)-ho)+To;
%     Pr = Po*(To/T).^(g/(L*Rconst));
    rho_c(index) = Pr_P(index)/(Rconst*T);
     y = [Vz_P(index)];  
    %y = [Vx_P(index);Vy_P(index);Vz_P(index);psi_dot_P(index);theta_dot_P(index);phi_dot_P(index)];
    %;rho_c(i)];
    
%     H(1,7) = -g*(cosd(x_nom(7,i))*sind(x_nom(11,i))+sind(x_nom(7,i))*sind(x_nom(9,i))*cosd(x_nom(11,i)));
%     H(1,9) = g*cosd(x_nom(7,i))*cosd(x_nom(9,i))*cosd(x_nom(11,i));
%     H(1,11) = -g*(sind(x_nom(7,i))*cosd(x_nom(11,i))+cosd(x_nom(7,i))*sind(x_nom(9,i))*cosd(x_nom(11,i)));
%     H(2,7) = g*(cosd(x_nom(7,i))*cosd(x_nom(11,i))+sind(x_nom(7,i))*sind(x_nom(9,i))*sind(x_nom(11,i)));
%     H(2,9) = -g*cosd(x_nom(7,i))*cosd(x_nom(9,i))*sind(x_nom(11,i));
%     H(2,11) = -g*(sind(x_nom(7,i))*sind(x_nom(11,i))+cosd(x_nom(7,i))*sind(x_nom(9,i))*cosd(x_nom(11,i)));
%     H(3,6) = -x_nom(13,i)*x_nom(14,i)*x_nom(15,i)*x_nom(6,i)/m;
%     H(3,7) = g*sind(x_nom(7,i))*cosd(x_nom(9,i));
%     H(3,9) = g*cosd(x_nom(7,i))*sind(x_nom(9,i));
%     H(3,13) = x_nom(14,i)*x_nom(15,i)*(x_nom(6,i)^2)/(2*m);
%     H(3,14) = x_nom(13,i)*x_nom(15,i)*(x_nom(6,i)^2)/(2*m);
%     H(3,15) = x_nom(13,i)*x_nom(14,i)*(x_nom(6,i)^2)/(2*m);
%     H(4,10) = ((Iy-Iz)/Ix)*x_nom(12,i);
%     H(4,12) = ((Iy-Iz)/Ix)*x_nom(10,i);
%     H(5,8) = ((Iz-Ix)/Iy)*x_nom(12,i);
%     H(5,12) = ((Iy-Iz)/Ix)*x_nom(8,i);
%     H(5,8) = ((Ix-Iy)/Iz)*x_nom(10,i);
%     H(5,10) = ((Ix-Iy)/Iz)*x_nom(8,i);
%     H(6,13) = 1;
%     H(7,14) = 1;
    %H(8,15) = 1;
    
    k = P*H'/(H*P*H' + R)
    P = (eye(14)-k*H)*P;
%     P = (eye(14) - k*H)*P*(eye(14)-k*H)' + (k*R*k')/gamma;
    x = x + k*(y-H*x);
%     gamma = 1 + (gamma_max - 1)*exp(-rate*index/tau);
    
    A(1,2) = 1;
    A(2,7) = -g*(cosd(x_nom(7,index))*sind(x_nom(11,index))+sind(x_nom(7,index))*sind(x_nom(9,index))*cosd(x_nom(11,index)));
    A(2,9) = g*cosd(x_nom(7,index))*cosd(x_nom(9,index))*cosd(x_nom(11,index));
    A(2,11) = -g*(sind(x_nom(7,index))*cosd(x_nom(11,index))+cosd(x_nom(7,index))*sind(x_nom(9,index))*cosd(x_nom(11,index)));
    A(3,4) = 1;
    A(4,7) = g*(cosd(x_nom(7,index))*cosd(x_nom(11,index))+sind(x_nom(7,index))*sind(x_nom(9,index))*sind(x_nom(11,index)));
    A(4,9) = -g*cosd(x_nom(7,index))*cosd(x_nom(9,index))*sind(x_nom(11,index));
    A(4,11) = -g*(sind(x_nom(7,index))*sind(x_nom(11,index))+cosd(x_nom(7,index))*sind(x_nom(9,index))*cosd(x_nom(11,index)));
    A(5,6) = 1;
    A(6,6) = -x_nom(13,index)*x_nom(14,index)*rho_c(index)*x_nom(6,index)/m;
    A(6,7) = g*sind(x_nom(7,index))*cosd(x_nom(9,index));
    A(6,9) = g*cosd(x_nom(7,index))*sind(x_nom(9,index));
    A(6,13) = x_nom(14,index)*rho_c(index)*(x_nom(6,index)^2)/(2*m);
    A(6,14) = x_nom(13,index)*rho_c(index)*(x_nom(6,index)^2)/(2*m);
    %A(6,15) = x_nom(13,index)*x_nom(14,index)*(x_nom(6,index)^2)/(2*m);
    A(7,8) = 1;
    A(8,10) = ((Iy-Iz)/Ix)*x_nom(12,index);
    A(8,12) = ((Iy-Iz)/Ix)*x_nom(10,index);
    A(9,10) = 1;
    A(10,8) = ((Iz-Ix)/Iy)*x_nom(12,index);
    A(10,12) = ((Iy-Iz)/Ix)*x_nom(8,index);
    A(11,12) = 1;
    A(12,8) = ((Ix-Iy)/Iz)*x_nom(10,index);
    A(12,10) = ((Ix-Iy)/Iz)*x_nom(8,index);
    A(13,13) = 1;
    A(14,14) = 1;
    %A(15,15) = 1;
   
    
    P = A*P*A'+Q;
    x = A*x;
    x_out(:,index) = x + x_nom(:,index);
    Cd_hat(index)  = x_out(13,index);
    Ar_hat(index) = x_out(14,index);
    temp       = Rot\[x_out(1,index);x_out(3,index);x_out(5,index)];
    Z_hat(index)   = temp(3);
    temp       = Rot\[x_out(2,index);x_out(4,index);x_out(6,index)];       
    V_hat(index)   = temp(3);
    
    

end
Ar = Ar*ones(1,size);
plot(t,Cd_hat,t,Cd);
legend("Estimated Drag Coefficient","Actual Drag Coefficient");
xlabel("Time [s]");
ylabel("Drag Coefficient");

figure()
plot(t,rho,t,rho_c);
legend("Actual Density","Calculated Density");
xlabel("Time [s]");
ylabel("Air Density");

figure()
plot(t,Z_hat,t,Z_Act);
legend("Estimated Altitude","Actual Altitude");
xlabel("Time [s]");
ylabel("Altitude");

figure()
plot(t,V_hat,t,V_Act);
legend("Estimated Velocity","Actual Velocity");
xlabel("Time [s]");
ylabel("Vertical Velocity");

figure()
plot(t,Ar_hat,t,Ar);
legend("Estimated Area","Actual Area");
xlabel("Time [s]");
ylabel("Area");


% err = Cd_hat - Cd';
% figure();
% plot(t,err)
% xlabel("Time [s]");
% ylabel("error [-]");

