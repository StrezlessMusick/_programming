function mm=left_mas(m,a)
%[smth] left_mas([smth] mas, int a)
%�������� ������ ����� �� a
%���� a>0 ����� ����� ����������
%���� a<0 ������ ����� ����� �������� �� �����
if(a>=1)
    for i=a:length(m)
        mm(i-a+1)=m(i);
    end;
else
    a=1-a;
    for i=1:length(m)
        mm(i+a-1)=m(i);
    end;
end;
end
