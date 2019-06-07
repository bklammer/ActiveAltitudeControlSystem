function Ttab = SIDread(Path)
warning off;
%Path = '/home/simon/Desktop/Test1sid.SID';
Path2 = [Path(1:(length(Path)-3)),'csv'];

delete(Path2);

fid = fopen(Path,'r');
fid2 = fopen(Path2,'w');
while feof(fid) ==0
    tline = fgetl(fid);
    if (tline(1)~='%')
        fprintf(fid2,[tline,'\n']);
    end
end

fclose(fid);
fclose(fid2);


Ttab = csvread(Path2);
Ttab = [Ttab(:,1),Ttab(:,3)];

%Ttab(:,1)=Ttab(:,1)./1000;

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
X=[0:0.005:Ttab(end,1)]';
F=polyval(P,X);

F(1)=0;
F(end)=0;
%plot(Ttab(:,1),Ttab(:,2),X,F);
F=F*0.9;
Ttab=[X,F];
for i = 1:length(Ttab(:,2))
    if Ttab(i,2) < 0
        Ttab(i,2)=0;
    end
end



