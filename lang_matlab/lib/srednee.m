function [sr,c]=srednee(mas);
%[float sr, c] srednee([float])
%��������� ������� � ����������� ����������
%�� ���������� ������ �����
%(���, ��� ��� ���� ����� �� ������ �����)
l=length(mas);
sr=0;
for i=1:l
    sr=sr+mas(i);
end;
sr=sr/l;
D=0;
for i=1:l
    D=D+(mas(i)-sr)^2;
end;
D=D/l;
c=D^0.5;
end