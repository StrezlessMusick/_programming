function [a sa b sb]=mnk_lin_s(x,y,sy)
%[a sa b sb]=mnk_lin_s(x,y,sy)
%y=ax+b
%see also my_lib_help

if(length(x)~=length(y) | length(y)~=length(sy) | length(y)<2)
    error('bad size of x or y or sy');
end;
sxs=sum(x./sy.^2);      %disp('sxs:');disp(sxs);
sys=sum(y./sy.^2);      %disp('sys:');disp(sys);
sx2s=sum(x.^2./sy.^2);  %disp('sx2s:');disp(sx2s);
sy2s=sum(y.^2./sy.^2);  %disp('sy2s:');disp(sy2s);
sxys=sum(x.*y./sy.^2);  %disp('sxys:');disp(sxys);
s2s=sum(1./sy.^2);      %disp('s2s:');disp(s2s);
D=sx2s*s2s-sxs^2;       %disp('D:');disp(D);
Da=sxys*s2s-sxs*sys;    %disp('Da:');disp(Da);
Db=sx2s*sys-sxs*sxys;   %disp('Db:');disp(Db);
a=Da/D;                 %disp('a:');disp(a);
b=Db/D;                 %disp('b:');disp(b);
sa=(s2s/D).^0.5;        %disp('sa:');disp(sa);
sb=(sx2s/D).^0.5;       %disp('sb:');disp(sb);
end
