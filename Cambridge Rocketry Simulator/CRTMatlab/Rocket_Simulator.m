clear all;

%define default values....
%t=[0:0.004:0.12];
%T=[0 0 0 0 380 440 460 340 290 250 230 200 180 175 150 145 130 110 100 80 75 60 45 40 35 20 10 5 0 0 0];
%Ttab=[t',T'];
Ttab=SIDread('Test1Short.SID');

Nm=0.05;
WM=1;
ws=4;
wb=0;
Rock_Param={Ttab,Nm,ws,wb,'Default',WM};
save 'Rock_Param' Rock_Param;
Main_Menu();

