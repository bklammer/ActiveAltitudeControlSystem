%## Copyright (C) 2008 S. Box
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

%## vector_to_bearing.m

%## Author: S. Box
%## Created: 2008-05-08

%Convert a Vector to a bearing and range
%Simon Box
%7 June 2006

function [bea,range]=vector_to_bearing(vec);

x=vec(1);
y=vec(2);

[t,r]=cart2pol(x,y);

range=r;

tb=t*180/pi;

if tb>=0 && tb<=90;
    bea=90-tb;
elseif tb>90 && tb<=180;
    bea=450-tb;
elseif tb<0 && tb>-180;
    bea=(-1*tb)+90;
end
    
    