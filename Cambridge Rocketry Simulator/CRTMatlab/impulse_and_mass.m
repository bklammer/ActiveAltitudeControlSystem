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

%## impulse_and_mass.m

%## Author: S.Box
%## Created: 2008-05-27

function [M,I]=impulse_and_mass(t,T,m);

warning off;
  
  EM1=[];
  EM2=[];

I=quadl(@tcurve,t(1),t(end),EM1,EM2,t,T);
mult=m/I;



for i=1:length(t);
    Ii=quadl(@tcurve,t(1),t(i),EM1,EM2,t,T);
    M(i)=m-(mult*Ii);
end


    function y=tcurve(x,varargin);
        t=varargin{1};
        T=varargin{2};
        y=interp1(t,T,x);
    end

end