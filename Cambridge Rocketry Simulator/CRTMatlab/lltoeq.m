% subroutine lltoeq-------------------------------------------------
%   written by a. dickinson 11/8/89 in FORTRAN 77
%   reviewed by r. swinbank 19/01/90
%   purpose:
%             calculates latitude and longitude on equatorial
%             latitude-longitude (eq) grid used in regional
%             models from input arrays of latitude and
%             longitude on standard grid. both input and output
%             latitudes and longitudes are in degrees.
%   documentation:
%             the transformation formulae are described in
%             unified model on-line documentation paper s1.
%   -----------------------------------------------------------------
%   Re-written by Changgui Wang 22/2/2003 in FORTRAN 90

%   Re-written by Simon Box 10 July 2006 in MATLAB

function [phi_eq,lambda_eq]=lltoeq(phi,lambda,polelat,polelong);

%Convert to radians********
lambda_r=lambda*pi/180;
phi_r=phi*pi/180;
polelat_r=polelat*pi/180;
polelong_r=polelong*pi/180;
%**************************

lambda_zero=polelong+180;
sin_bplat=sin(polelat_r);
cos_bplat=cos(polelat_r);

a_lambda=lambda-lambda_zero;

if a_lambda >180;
    a_lambda=a_lambda-360;
elseif a_lambda <=-180;
    a_lambda=a_lambda+360;
end

a_lambda=a_lambda*pi/180;
a_phi=phi*pi/180;

arg=-cos_bplat*cos(a_lambda)*cos(a_phi)+sin(a_phi)*sin_bplat;
arg=min(arg,1);
arg=max(arg,-1);
e_phi=asin(arg);
phi_eq=e_phi*180/pi;

term1=(cos(a_phi)*cos(a_lambda)*sin_bplat+sin(a_phi)*cos_bplat);
term2=cos(e_phi);

if term1< 0.000000001;
    e_lambda=0;
else
    arg=term1/term2;
    arg=min(arg,1.0);
    arg=max(arg,-1.0);
    e_lambda=acos(arg);
    e_lambda=e_lambda*180/pi;
    
    e_lambda=e_lambda*sign(a_lambda);
end

if e_lambda >= 360;
    e_lambda=e_lambda-360;
elseif e_lambda<0;
    e_lambda=e_lambda+360;
end
lambda_eq=e_lambda;



       