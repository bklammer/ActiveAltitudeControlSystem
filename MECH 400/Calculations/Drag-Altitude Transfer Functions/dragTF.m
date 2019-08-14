% Drag effects on altitude
%   tryinhg to figure out a nice transfer function


for i = 1:21
   CdA(i) = (i-1)*0.05;
   apogee(i) = suborbit_dragTF(CdA(i));
end

figure
plot(CdA, apogee)
xlabel('Drag Coefficient')
ylabel('Apogee (m)')
title('Transfer Function for Constant Drag Coefficient')