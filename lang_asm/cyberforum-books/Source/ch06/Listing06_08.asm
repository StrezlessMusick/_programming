. . .
.data
  i1      DD 34
  i2      DD 17
  min_val DD ?
  abs_val DD ?
. . .
.code
. . .
 mov    EAX, i1
 mov    E��, i2
 call   minint
; ������� ���� ����� i1 � i2 ��������� � �������� EAX. �������� ���
; �������� � ���������� min_val � ������ ���������� ��������
 mov    min_val, EAX
 call   minabs
; �������� ������ ����� � ���������� abs_val
 mov    abs_val, EAX
  . . .
; ����� ����������� ��������� minint � minabs
minint  proc
 cmp    E��,E��
 jl     exit
 mov    E��,E��
exit:
 ret
minint  endp
minabs  proc
 mov    EAX, min_val
 cmp    EAX, 0
 jge    quit
 neg    EAX
quit:
 ret
minabs  endp
. . .
