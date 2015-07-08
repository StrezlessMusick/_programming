%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%������ - �����, ������ ������, ��� ����� ��� ����� � ��������� goto
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%(c)FeelUs

function brlinsky_kurs;
disp('----------------------------------');%�������
hold on;%��������� �������� ����� �������� �� �����
grid on;%�������� ������������ �����

%{
%����� ������������ ��������� �� ������ �����
for re=-400:100:400
    for im=-400:100:400
        paint(re+im*1i);
    end;
end;
%}
paint(1+1i);

%{
%2-� ������������ ���������
%bl=0.002
[z,ap,a]=integrate(1,0,1000,780);
plot3(z,real(a),imag(a));
plot3(z,real(ap),imag(ap),'r');
[z,ap,a]=integrate(1,0,1000,540);
plot3(z,real(a),imag(a));
plot3(z,real(ap),imag(ap),'r');
%}

%{
%����� �������� �� ������ �����
for re=-400:100:400
    for im=-400:100:400
        [z,ap,a]=integrate(1,0,1000,re+im*1i);
        plot3(z,real(a),imag(a));
    end;
end;
view([90 0]);
%}
%([���� �� �����������, ���� �� ���������])
hold off;
end%of function

%�� ��������� ������� ���� ������������ ���������
%������� ���� ��� z==0 � ����� ���������
%�� � ���� ��� ���������
%� ����� ������� - ��������� �������
function paint(Astart);
%���������� ��������� ������
R=0.95;%0.7*exp(0.8i);    %0.36844;%
ApStart=1000;
%��������� ��������� � ������������
maloe=0.001;
numSovp=100;
%�.�. ������ ������������ ����� � ������� maloe
%������ ��������������� ��������� NumSovp �����
%----------------------------
i=1;
A(i)=Astart;
z(i)=0;%������ ��� �������
i=i+1;
count=1;
flag=1;
while(i<100000 & flag)
    [zz,Ap,AA]=integrate(0,0,ApStart,A(end));%end==i-1
    %�������� �������� ����� AA �� ��������� (��� ������ ��������) A(end)
    A(i)=AA*R;
    z(i)=0;
    i=i+1;
    %��������� ��������� � ������������
    if(abs(A(end)-A(end-count))<maloe)
        if(count==numSovp)
            flag=0;
        else
            count=count+1;
        end;
    else
        if(count>1)
            count=1;
        end;
    end;
end;
%���� ������ � ������������, �� flag==0
%����� �������� 10000 ����� � �� ������ � ����==1
disp(i);%������� ����� ��������
%, ��������������� ��� ��������� � ������������ ���������

plot3(z,real(A),imag(A),'.-');
%���������� ���� � �������������
if(~flag)
    [z,Ap,A]=integrate(1,0,ApStart,A(end));
    %�������� ������ ������������� ���������
    plot3(z,real(A),imag(A));
    %���������� A
    plot3(z,real(Ap),imag(Ap),'r');
    %���������� Ap
    disp('A(0)');
    disp(A(1));
    disp('A(1)');
    disp(A(end));
    disp('Ap(0)');
    disp(Ap(1));
    disp('Ap(1)');
    disp(Ap(end));
else
    disp('�� ������');
end;

end%of function


%����� ��������� �����
%���� ����!=0, ���������� ������ ��� �������
%����� ���������� ������ �������� �����
function [z,Ap,A]=integrate(flag,zStart,ApStart,Astart);
%��������� z
dz=0.002;%��������� ��� ��������������
lengthz=0.99999;%������� �� �����
numz=lengthz/dz;%����� ����� ��������������
NumPaintPoint=100;%����� �����, ��������� �� ������� ��� ����� �����
PaintNum=fix(numz/NumPaintPoint);%fix - ����� ����� �����
if(PaintNum==0)
    PaintNum=1;
end;
%��������� ���������%
bl=0.000052;
bpl=bl;%0.001;
%----------------------
if(flag)
    %���������� � ������ ��������� �����
    countmas=1;
    z(countmas)=zStart;
    Ap(countmas)=ApStart;
    A(countmas)=Astart;
    %�������������� ������� (cur)
    zcur=0;
    Apcur=ApStart;
    Acur=Astart;
    for i=1:numz
        dA= dz* bl*Apcur*conj(Acur) ;%conj - ����������� ����������
        dAp=dz* (-bpl)*Acur^2;
        Acur=Acur+dA;
        Apcur=Apcur+dAp;
            %disp(Acur);
        zcur=zcur+dz;%� ������ ��-� ����� ������ ��� ��������
        if(mod(i,PaintNum)==0)    %mod - ������� �� ������� i/PaintNum
            %�� ���������� � ������
            countmas=countmas+1;
            z(countmas)=zcur;
            Ap(countmas)=Apcur;
            A(countmas)=Acur;
        end;
    end;
    %��������� ����� ���� ����������
    countmas=countmas+1;
    z(countmas)=zcur;
    Ap(countmas)=Apcur;
    A(countmas)=Acur;
else
    %�������������� ������� (cur)
    zcur=0;
    Apcur=ApStart;
    Acur=Astart;
    for i=1:numz
        dA= dz* bl*Apcur*conj(Acur) ;%conj - ����������� ����������
        dAp=dz* (-bpl)*Acur^2;
        Acur=Acur+dA;
        Apcur=Apcur+dAp;
    end;
    %��������� ����� ��� �� ����������
    z=dz*numz;
    Ap=Apcur;
    A=Acur;
end;    
end%of function
