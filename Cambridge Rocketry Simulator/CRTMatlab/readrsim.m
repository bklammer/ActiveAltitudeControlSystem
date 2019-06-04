%## Copyright (C) 2008 S.Box
%## 
%## This program is free software; you can redistribute it and/or modify
%## it under the terms of the GNU General Public License as published by
%## the Free Software Foundation; either version 2 of the License, or
%## (at your option) any later version.
%## 
%## This program is distributed in the hope that it will be useful,
%## but WITHOUT ANY WARRANTY; without even the implied warranty of
%## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
%## GNU General Public License for more details.
%## 
%## You should have received a copy of the GNU General Public License
%## along with this program; if not, write to the Free Software
%## Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA

%## readrsim.m

%## Author: S.Box
%## Created: 2008-05-27

function [INTAB,Pout]=readrsim(varargin);

if nargin==3;
Motor=varargin{2};
Lmot=varargin{3}
Motor{6}=Lmot;
end

fid=fopen(varargin{1},'rt');


endtrigger=0;
i=0;
readlines='off';
part='nopart';
partnum=[1 0 0 0 0];
level=1;
while endtrigger==0;
    tline=fgetl(fid);

    match1=findstr(tline,'<Stage3Parts>');
    match2=findstr(tline,'</Stage3Parts>');

    if length(match1)>0;
        readlines='on';
    elseif length(match2)>0;
        readlines='off';
        endtrigger=1;
    end

    switch readlines;
        case 'on';
            

            match3=findstr(tline,'<AttachedParts>');
            match4=findstr(tline,'</AttachedParts>');
            if length(match3)>0;
                partnum(level+1)=partnum(level+1)+1;
                level=level+1;
            elseif length(match4)>0;
                partnum(level)=0;
                partnum(level-1)=partnum(level-1)+1;
                level=level-1;
            end

            match5=findstr(tline,'<NoseCone>');
            match6=findstr(tline,'<BodyTube>');
            match7=findstr(tline,'<Ring>');
            match8=findstr(tline,'<MassObject>');
            match9=findstr(tline,'<LaunchLug>');
            match10=findstr(tline,'<Parachute>');
            match11=findstr(tline,'<FinSet>');
            match12=findstr(tline,'<Streamer>');
            match13=findstr(tline,'<Transition>');
            match14=findstr(tline,'<CustomFinSet>');

            if length(match5)>0;
                i=i+1;
                part='NoseCone';
            elseif length(match6)>0;
                i=i+1;
                part='BodyTube';
            elseif length(match7)>0;
                i=i+1;
                part='Ring';
            elseif length(match8)>0;
                i=i+1;
                part='MassObject';
            elseif length(match9)>0;
                i=i+1;
                part='LaunchLug';
            elseif length(match10)>0;
                i=i+1;
                part='Parachute';
            elseif length(match11)>0;
                i=i+1;
                part='FinSet';
            elseif length(match12)>0;
                i=i+1;
                part='Streamer';
            elseif length(match13)>0;
                i=i+1;
                part='Transition';
            elseif length(match14)>0;
                i=i+1;
                part='FinSet';
            end



            switch part
                case 'NoseCone';

                    matchp1=findstr(tline,'<KnownMass>');
                    matchp2=findstr(tline,'</KnownMass>');

                    if length(matchp1)>0;
                        KMstr=tline((matchp1+11):(matchp2-1));
                        KM=str2num(KMstr);
                    end

                    matchp3=findstr(tline,'<Xb>');
                    matchp4=findstr(tline,'</Xb>');

                    if length(matchp3)>0;
                        Xstr=tline((matchp3+4):(matchp4-1));
                        X=str2num(Xstr);
                    end

                    matchp5=findstr(tline,'<CalcMass>');
                    matchp6=findstr(tline,'</CalcMass>');

                    if length(matchp5)>0;
                        CMstr=tline((matchp5+10):(matchp6-1));
                        CM=str2num(CMstr);
                    end

                    matchp7=findstr(tline,'<LocationMode>');
                    matchp8=findstr(tline,'</LocationMode>');

                    if length(matchp7)>0;
                        LocMstr=tline((matchp7+14):(matchp8-1));
                        LocM=str2num(LocMstr);
                    end

                    matchp9=findstr(tline,'<Len>');
                    matchp10=findstr(tline,'</Len>');

                    if length(matchp9)>0;
                        Lstr=tline((matchp9+5):(matchp10-1));
                        L=str2num(Lstr);
                    end

                    matchp11=findstr(tline,'<BaseDia>');
                    matchp12=findstr(tline,'</BaseDia>');

                    if length(matchp11)>0;
                        dstr=tline((matchp11+9):(matchp12-1));
                        d=str2num(dstr);
                    end

                    matchp13=findstr(tline,'<ShapeCode>');
                    matchp14=findstr(tline,'</ShapeCode>');

                    if length(matchp13)>0;
                        SCstr=tline((matchp13+11):(matchp14-1));
                        SC=str2num(SCstr);
                    end

                    %****************************************

                    matchp14=findstr(tline,'<CoreLen>');

                    if length(matchp14)>0;
                        PARTS{i}{1}=partnum;
                        PARTS{i}{2}='nose';
                        if SC==0;
                            PARTS{i}{3}='conical';
                        elseif SC==1;
                            PARTS{i}{3}='ogive';
                        elseif SC==2;
                            PARTS{i}{3}='parabolic';
                        else
                            PARTS{i}{3}='ogive';
                        end

                        PARTS{i}{4}=L/1000;
                        PARTS{i}{5}=d/1000;
                        if CM>0;
                            PARTS{i}{6}=CM/1000;
                        else
                            PARTS{i}{6}=KM/1000;
                        end

                        PARTS{i}{7}=X/1000;
                        PARTS{i}{8}=LocM;
                        PARTS{i}{9}=L/1000;
                    end
                    
                case {'BodyTube','Ring'};
                    
                    matchp1=findstr(tline,'<KnownMass>');
                    matchp2=findstr(tline,'</KnownMass>');

                    if length(matchp1)>0;
                        KMstr=tline((matchp1+11):(matchp2-1));
                        KM=str2num(KMstr);
                    end

                    matchp3=findstr(tline,'<Xb>');
                    matchp4=findstr(tline,'</Xb>');

                    if length(matchp3)>0;
                        Xstr=tline((matchp3+4):(matchp4-1));
                        X=str2num(Xstr);
                    end

                    matchp5=findstr(tline,'<CalcMass>');
                    matchp6=findstr(tline,'</CalcMass>');

                    if length(matchp5)>0;
                        CMstr=tline((matchp5+10):(matchp6-1));
                        CM=str2num(CMstr);
                    end
                    
                    matchp7=findstr(tline,'<LocationMode>');
                    matchp8=findstr(tline,'</LocationMode>');

                    if length(matchp7)>0;
                        LocMstr=tline((matchp7+14):(matchp8-1));
                        LocM=str2num(LocMstr);
                    end
                    
                    matchp9=findstr(tline,'<OD>');
                    matchp10=findstr(tline,'</OD>');

                    if length(matchp9)>0;
                        ODstr=tline((matchp9+4):(matchp10-1));
                        OD=str2num(ODstr);
                    end
                    
                    matchp11=findstr(tline,'<ID>');
                    matchp12=findstr(tline,'</ID>');

                    if length(matchp11)>0;
                        IDstr=tline((matchp11+4):(matchp12-1));
                        ID=str2num(IDstr);
                    end
                    
                    matchp13=findstr(tline,'<Len>');
                    matchp14=findstr(tline,'</Len>');

                    if length(matchp13)>0;
                        Lstr=tline((matchp13+5):(matchp14-1));
                        L=str2num(Lstr);
                    end
                    
                    %****************************************

                    matchp15=findstr(tline,'<FinishCode>');

                    if length(matchp15)>0;
                        PARTS{i}{1}=partnum;
                        PARTS{i}{2}='tube';
                        if partnum(2)==0;
                            PARTS{i}{3}='yes';
                        else
                            PARTS{i}{3}='no';
                        end
                        
                        PARTS{i}{4}=L/1000;
                        PARTS{i}{5}=ID/1000;
                        PARTS{i}{6}=OD/1000;
                        if CM==0;
                            PARTS{i}{7}=KM/1000;
                        else
                           PARTS{i}{7}=CM/1000;
                        end
                        
                        PARTS{i}{8}=X/1000;
                        PARTS{i}{9}=LocM;
                        PARTS{i}{10}=L/1000;
                    end
                    
                case {'MassObject','LaunchLug'};
                    matchp1=findstr(tline,'<KnownMass>');
                    matchp2=findstr(tline,'</KnownMass>');

                    if length(matchp1)>0;
                        KMstr=tline((matchp1+11):(matchp2-1));
                        KM=str2num(KMstr);
                    end

                    matchp3=findstr(tline,'<Xb>');
                    matchp4=findstr(tline,'</Xb>');

                    if length(matchp3)>0;
                        Xstr=tline((matchp3+4):(matchp4-1));
                        X=str2num(Xstr);
                    end

                    matchp5=findstr(tline,'<CalcMass>');
                    matchp6=findstr(tline,'</CalcMass>');
                    
                    if length(matchp5)>0;
                        CMstr=tline((matchp5+10):(matchp6-1));
                        CM=str2num(CMstr);
                    end
                    
                    matchp7=findstr(tline,'<RadialLoc>');
                    matchp8=findstr(tline,'</RadialLoc>');
                    
                    if length(matchp7)>0;
                        XRstr=tline((matchp7+11):(matchp8-1));
                        XR=str2num(XRstr);
                    end

                    matchp9=findstr(tline,'<LocationMode>');
                    matchp10=findstr(tline,'</LocationMode>');

                    if length(matchp9)>0;
                        LocMstr=tline((matchp9+14):(matchp10-1));
                        LocM=str2num(LocMstr);
                    end
                    
                    matchp11=findstr(tline,'<Color>');

                    if length(matchp11)>0;
                        PARTS{i}{1}=partnum;
                        PARTS{i}{2}='pm';
                        if CM==0;
                            PARTS{i}{3}=KM/1000;
                        else
                            PARTS{i}{3}=CM/1000;
                        end
                        PARTS{i}{4}=XR/1000;
                        PARTS{i}{5}=X/1000;
                        PARTS{i}{6}=LocM;
                        PARTS{i}{7}=0;
                    end
                case 'Transition'
                    matchp1=findstr(tline,'<KnownMass>');
                    matchp2=findstr(tline,'</KnownMass>');

                    if length(matchp1)>0;
                        KMstr=tline((matchp1+11):(matchp2-1));
                        KM=str2num(KMstr);
                    end

                    matchp3=findstr(tline,'<Xb>');
                    matchp4=findstr(tline,'</Xb>');

                    if length(matchp3)>0;
                        Xstr=tline((matchp3+4):(matchp4-1));
                        X=str2num(Xstr);
                    end

                    matchp5=findstr(tline,'<CalcMass>');
                    matchp6=findstr(tline,'</CalcMass>');

                    if length(matchp5)>0;
                        CMstr=tline((matchp5+10):(matchp6-1));
                        CM=str2num(CMstr);
                    end
                    
                    matchp7=findstr(tline,'<LocationMode>');
                    matchp8=findstr(tline,'</LocationMode>');

                    if length(matchp7)>0;
                        LocMstr=tline((matchp7+14):(matchp8-1));
                        LocM=str2num(LocMstr);
                    end
                    
                    matchp9=findstr(tline,'<FrontDia>');
                    matchp10=findstr(tline,'</FrontDia>');

                    if length(matchp9)>0;
                        UDstr=tline((matchp9+10):(matchp10-1));
                        UD=str2num(UDstr);
                    end
                    
                    matchp11=findstr(tline,'<RearDia>');
                    matchp12=findstr(tline,'</RearDia>');

                    if length(matchp11)>0;
                        DDstr=tline((matchp11+9):(matchp12-1));
                        DD=str2num(DDstr);
                    end
                    
                    matchp13=findstr(tline,'<Len>');
                    matchp14=findstr(tline,'</Len>');

                    if length(matchp13)>0;
                        Lstr=tline((matchp13+5):(matchp14-1));
                        L=str2num(Lstr);
                    end

                    %******************************************
                    matchp15=findstr(tline,'<FinishCode>');

                    if length(matchp15)>0;
                        
                        PARTS{i}{1}=partnum;
                        PARTS{i}{2}='cone_trans';
                        if partnum(2)==0;
                            PARTS{i}{3}='yes';
                        else
                            PARTS{i}{3}='no';
                        end
                        
                        PARTS{i}{4}=UD/1000;
                        PARTS{i}{5}=DD/1000;
                        PARTS{i}{6}=0;
                        PARTS{i}{7}=L/1000;
                        if CM==0;
                        PARTS{i}{8}=KM/1000;
                        else
                            PARTS{i}{8}=CM/1000;
                        end
                        PARTS{i}{9}=X;
                        PARTS{i}{10}=LocM;
                        PARTS{i}{11}=L/1000;
                    end
                    
                case 'FinSet';
                    matchp1=findstr(tline,'<KnownMass>');
                    matchp2=findstr(tline,'</KnownMass>');

                    if length(matchp1)>0;
                        KMstr=tline((matchp1+11):(matchp2-1));
                        KM=str2num(KMstr);
                    end

                    matchp3=findstr(tline,'<Xb>');
                    matchp4=findstr(tline,'</Xb>');

                    if length(matchp3)>0;
                        Xstr=tline((matchp3+4):(matchp4-1));
                        X=str2num(Xstr);
                    end

                    matchp5=findstr(tline,'<CalcMass>');
                    matchp6=findstr(tline,'</CalcMass>');

                    if length(matchp5)>0;
                        CMstr=tline((matchp5+10):(matchp6-1));
                        CM=str2num(CMstr);
                    end
                    
                    matchp7=findstr(tline,'<LocationMode>');
                    matchp8=findstr(tline,'</LocationMode>');

                    if length(matchp7)>0;
                        LocMstr=tline((matchp7+14):(matchp8-1));
                        LocM=str2num(LocMstr);
                    end
                    
                    matchp9=findstr(tline,'<FinCount>');
                    matchp10=findstr(tline,'</FinCount>');

                    if length(matchp9)>0;
                        nstr=tline((matchp9+10):(matchp10-1));
                        n=str2num(nstr);
                    end
                    
                    matchp11=findstr(tline,'<RootChord>');
                    matchp12=findstr(tline,'</RootChord>');

                    if length(matchp11)>0;
                        astr=tline((matchp11+11):(matchp12-1));
                        a=str2num(astr);
                    end
                    
                    matchp13=findstr(tline,'<TipChord>');
                    matchp14=findstr(tline,'</TipChord>');

                    if length(matchp13)>0;
                        bstr=tline((matchp13+10):(matchp14-1));
                        b=str2num(bstr);
                    end
                    
                    matchp15=findstr(tline,'<SemiSpan>');
                    matchp16=findstr(tline,'</SemiSpan>');

                    if length(matchp15)>0;
                        sstr=tline((matchp15+10):(matchp16-1));
                        s=str2num(sstr);
                    end
                    
                    matchp17=findstr(tline,'<SweepDistance>');
                    matchp18=findstr(tline,'</SweepDistance>');

                    if length(matchp17)>0;
                        mstr=tline((matchp17+15):(matchp18-1));
                        m=str2num(mstr);
                    end
                    
                    matchp19=findstr(tline,'<Thickness>');
                    matchp20=findstr(tline,'</Thickness>');

                    if length(matchp19)>0;
                        tstr=tline((matchp19+11):(matchp20-1));
                        t=str2num(tstr);
                    end

                    %******************************************
                    matchp21=findstr(tline,'<FinishCode>');

                    if length(matchp21)>0;
                        PARTS{i}{1}=partnum;
                        PARTS{i}{2}='finset';
                        PARTS{i}{3}=n;
                        PARTS{i}{4}=a/1000;
                        PARTS{i}{5}=b/1000;
                        PARTS{i}{6}=m/1000;
                        PARTS{i}{7}=s/1000;
                        PARTS{i}{8}=t/1000;
                        if CM==0;
                            PARTS{i}{9}=KM/1000;
                        else
                            PARTS{i}{9}=CM/1000;
                        end
                        PARTS{i}{10}=0;
                        PARTS{i}{11}=0;
                        PARTS{i}{12}=X/1000;
                        PARTS{i}{13}=LocM;
                        PARTS{i}{14}=a/1000;
                    end
                    
                case 'Parachute'
                    matchp1=findstr(tline,'<KnownMass>');
                    matchp2=findstr(tline,'</KnownMass>');

                    if length(matchp1)>0;
                        KMstr=tline((matchp1+11):(matchp2-1));
                        KM=str2num(KMstr);
                    end

                    matchp3=findstr(tline,'<Xb>');
                    matchp4=findstr(tline,'</Xb>');

                    if length(matchp3)>0;
                        Xstr=tline((matchp3+4):(matchp4-1));
                        X=str2num(Xstr);
                    end

                    matchp5=findstr(tline,'<CalcMass>');
                    matchp6=findstr(tline,'</CalcMass>');

                    if length(matchp5)>0;
                        CMstr=tline((matchp5+10):(matchp6-1));
                        CM=str2num(CMstr);
                    end
                    
                    matchp7=findstr(tline,'<LocationMode>');
                    matchp8=findstr(tline,'</LocationMode>');

                    if length(matchp7)>0;
                        LocMstr=tline((matchp7+14):(matchp8-1));
                        LocM=str2num(LocMstr);
                    end
                    
                    matchp9=findstr(tline,'<Dia>');
                    matchp10=findstr(tline,'</Dia>');

                    if length(matchp9)>0;
                        Dpstr=tline((matchp9+5):(matchp10-1));
                        Dp=str2num(Dpstr);
                    end
                    
                    matchp11=findstr(tline,'<SpillHoleDia>');
                    matchp12=findstr(tline,'</SpillHoleDia>');

                    if length(matchp11)>0;
                        Dhstr=tline((matchp11+14):(matchp12-1));
                        Dh=str2num(Dhstr);
                    end
                    
                    matchp13=findstr(tline,'<DragCoefficient>');
                    matchp14=findstr(tline,'</DragCoefficient>');

                    if length(matchp13)>0;
                        Cdstr=tline((matchp13+17):(matchp14-1));
                        Cd=str2num(Cdstr);
                    end
                    
                    %***********************************************
                    if length(matchp13)>0;
                        Ap=(Dp/1000)^2*pi/4;
                        Ah=(Dh/1000)^2*pi/4;
                        A=Ap-Ah;
                        
                        
                        PARTS{i}{1}=partnum;
                        PARTS{i}{2}='parachute';
                        PARTS{i}{3}=Cd;
                        PARTS{i}{4}=A;
                        if CM==0;
                        PARTS{i}{5}=KM/1000;
                        else
                            PARTS{i}{5}=CM/1000;
                        end
                        PARTS{i}{6}=X/1000;
                        PARTS{i}{7}=LocM;
                        PARTS{i}{8}=0;
                    end
                    
                case 'Streamer';
                    matchp1=findstr(tline,'<KnownMass>');
                    matchp2=findstr(tline,'</KnownMass>');

                    if length(matchp1)>0;
                        KMstr=tline((matchp1+11):(matchp2-1));
                        KM=str2num(KMstr);
                    end

                    matchp3=findstr(tline,'<Xb>');
                    matchp4=findstr(tline,'</Xb>');

                    if length(matchp3)>0;
                        Xstr=tline((matchp3+4):(matchp4-1));
                        X=str2num(Xstr);
                    end

                    matchp5=findstr(tline,'<CalcMass>');
                    matchp6=findstr(tline,'</CalcMass>');

                    if length(matchp5)>0;
                        CMstr=tline((matchp5+10):(matchp6-1));
                        CM=str2num(CMstr);
                    end
                    
                    matchp7=findstr(tline,'<LocationMode>');
                    matchp8=findstr(tline,'</LocationMode>');

                    if length(matchp7)>0;
                        LocMstr=tline((matchp7+14):(matchp8-1));
                        LocM=str2num(LocMstr);
                    end
                    
                    matchp9=findstr(tline,'<Len>');
                    matchp10=findstr(tline,'</Len>');

                    if length(matchp9)>0;
                        Lstr=tline((matchp9+5):(matchp10-1));
                        L=str2num(Lstr);
                    end
                    
                    matchp11=findstr(tline,'<Width>');
                    matchp12=findstr(tline,'</Width>');

                    if length(matchp11)>0;
                        Wstr=tline((matchp11+8):(matchp12-1));
                        W=str2num(Wstr);
                    end
                    
                    matchp13=findstr(tline,'<DragCoefficient>');
                    matchp14=findstr(tline,'</DragCoefficient>');

                    if length(matchp13)>0;
                        Cdstr=tline((matchp13+17):(matchp14-1));
                        Cd=str2num(Cdstr);
                    end
                    
                    %***********************************************
                    if length(matchp13)>0;
                        A=(L/1000)*(W/1000);
                        
                        PARTS{i}{1}=partnum;
                        PARTS{i}{2}='parachute';
                        PARTS{i}{3}=Cd;
                        PARTS{i}{4}=A;
                        if CM==0;
                        PARTS{i}{5}=KM/1000;
                        else
                            PARTS{i}{5}=CM/1000;
                        end
                        PARTS{i}{6}=X/1000;
                        PARTS{i}{7}=LocM;
                        PARTS{i}{8}=0;
                    end
            end
    end
end

%CALCULATE LENGTHS********************************************************



 for i=1:length(PARTS);
     pnum=PARTS{i}{1};
     Lnum=find(pnum);
     Level=length(Lnum);
     X=PARTS{i}{end-2};
     Loc=PARTS{i}{end-1};
     L=PARTS{i}{end};
     
     Stab(i,:)=[pnum(1:end),X,Loc,L,0];
     
     if Level==1;
         if pnum(1)==1;
             Stab(i,end)=0;
         else
             sStab=size(Stab);   
             for i2=1:sStab(1)
                 if Stab(i2,1)==pnum(1)-1 && Stab(i2,2)==0;
                     Stab(i,end)=Stab(i2,8)+Stab(i2,9);
                 end
             end
         end
     end
     
     if Level==2;
         sStab=size(Stab); 
         for i2=1:sStab(1);
             if Stab(i2,1)==pnum(1) && Stab(i2,2)==0;
                 if Loc==0;
                 Stab(i,end)=Stab(i2,end)+X;
                 elseif Loc==1;
                     Stab(i,end)=X;
                 elseif Loc==2;
                     Stab(i,end)=Stab(i2,8)+Stab(i2,9)-X-L;
                 end
             end
         end
     end
     
     if Level==3;
         sStab=size(Stab); 
         for i2=1:sStab(1);
             if Stab(i2,1)==pnum(1) && Stab(i2,2)==pnum(2) && Stab(i2,3)==0;
                 if Loc==0;
                 Stab(i,end)=Stab(i2,end)+X;
                 elseif Loc==1;
                     Stab(i,end)=X;
                 elseif Loc==2;
                     Stab(i,end)=Stab(i2,8)+Stab(i2,9)-X-L;
                 end
             end
         end
     end

     if Level==4;
         sStab=size(Stab); 
         for i2=1:sStab(1);
             if Stab(i2,1)==pnum(1) && Stab(i2,2)==pnum(2) && Stab(i2,3)==pnum(3) && Stab(i2,4)==0;
                 if Loc==0;
                 Stab(i,end)=Stab(i2,end)+X;
                 elseif Loc==1;
                     Stab(i,end)=X;
                 elseif Loc==2;
                     Stab(i,end)=Stab(i2,8)+Stab(i2,9)-X-L;
                 end
             end
         end
     end
     
     if Level==5;
         sStab=size(Stab); 
         for i2=1:sStab(1);
             if Stab(i2,1)==pnum(1) && Stab(i2,2)==pnum(2) && Stab(i2,3)==pnum(3) && Stab(i2,4)==pnum(4) && Stab(i2,5)==0;;
                 if Loc==0;
                 Stab(i,end)=Stab(i2,end)+X;
                 elseif Loc==1;
                     Stab(i,end)=X;
                 elseif Loc==2;
                     Stab(i,end)=Stab(i2,8)+Stab(i2,9)-X-L;
                 end
             end
         end
     end
 end

 
%build output***********************************************************

for i=1:length(PARTS);
    
    lp=length(PARTS{i});
    for i2=1:lp-4;
        Pout{i}{i2}=PARTS{i}{i2+1};
    end
    Pout{i}{end+1}=Stab(i,end);
end

for i=1:length(Pout);
    if i==1;
        switch Pout{1}{1};
            case 'nose';
                dr=Pout{1}{4};
            case 'cone_trans';
                diamsz=[Pout{1}{3} Pout{1}{4}];
                srtdiamsz=sort(diamsz);
                dr=srtdiamsz(2);
            case 'tube';
                dr=Pout{1}{5};
        end
    end
    
    switch Pout{i}{1};
        case 'tube'
            switch Pout{i}{2};
                case 'yes';
                    dtn=Pout{i}{5};
            end
        case 'cone_trans'
            switch Pout{i}{2};
                case 'yes';
                    dtn=((Pout{i}{3}+Pout{i}{4})/2);
            end
    end
    
    switch Pout{i}{1};
        case 'cone_trans';
            Pout{i}{5}=dr;
        case 'finset';
            Pout{i}{9}=dtn;
            Pout{i}{10}=dr;
    end
end

%INTAB=Pout;
if nargin==3;
  INTAB=intab_builder(Pout{:},Motor);
elseif nargin==1;
  INTAB=intab_builder(Pout{:});
end


