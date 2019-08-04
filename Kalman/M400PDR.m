% import trajectory data, initialization
load("Extracted Data.mat");
rho = 1;
Drag = Drag(318:end-8);
Alt = Alt(318:end-8);
Vel = Vel(318:end-8);
Acc = Acc(318:end-8);
t = t(318:end-8);
Cd = (2.*Drag)./(0.0108.*rho.*(Vel.^2)); 
PAcc = Acc + (1*rand() - 0.5); %perturbed acceleration data

%Kalman Filter
Q = 0.0000000001;
R = 0.2;
P = 0.0000000001;
x = 0.5;
Vo = 235; 
for i=2:1778
    %V = trapz([t(i-1) t(i)],[PAcc(i-1) PAcc(i)])+V;
    V = trapz([PAcc(i-1) PAcc(i)]).*(t(i) - t(1))+Vo;
    H = (0.0108.*rho.*(V.^2))./20;
    k = P*H*(H*P*H + R)^-1;
    P = (1-k*H)*P;
    P = 1*P*1+Q;
    x = 1*x;
    x = x+k*(PAcc-H*x);
end
plot(t,x,t,Cd);
legend("Estimated Drag Coefficient","Actual Drag Coefficient");
xlabel("Time [s]");
ylabel("Drag Coefficient");

