function Ttab = EasySenseConvert(Path)
%Path = 'C:\Documents and Settings\sb4p07\Desktop\WFlight01.csv';


Ttab = csvread(Path);

Ttab(:,1)=Ttab(:,1)./1000;

Div = mean([Ttab(1,2),Ttab(end,2)]);

Ttab(:,2)=(Ttab(:,2)-Div).*(-1);

Ttab(1,2)=0;
Ttab(end,2)=0;

for i = 1:length(Ttab(:,2))
    if Ttab(i,2) < 0
        Ttab(i,2)=0;
    end
end

stop = false;
i=2;
while stop == false;
    if Ttab(i,2)==0
        Ttab(2:end,1)=Ttab(2:end,1)-Ttab(i,1);
        Ttab=[Ttab(1,:);Ttab(3:end,:)];
    else
        stop=true;
    end
end

stop = false;
i=2;
while stop == false;
    if Ttab(i,1)==0
        Ttab=Ttab(2:end,:);
    else
        stop=true;
    end
end

P=polyfit(Ttab(:,1),Ttab(:,2),8);
F=polyval(P,Ttab(:,1));

F(1)=0;
F(end)=0;
plot(Ttab(:,1),Ttab(:,2),Ttab(:,1),F);
Ttab=[Ttab(:,1),F];



