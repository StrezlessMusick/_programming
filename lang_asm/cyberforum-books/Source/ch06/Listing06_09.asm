.686
.model flat
.stack 100h
option casemap: none
  extern _add2:proc
  extern _sub1:proc
  public a1, a2, b3
.data
  a1    DD  12
  a2    DD  17
  b3    DD  34
.code
 _add_sub proc
   clc           ; ������� ���� ��������
   call _add2    ; ��������� ����� a1 + a2
   push  EAX     ; ������������� ��������� �������� � ����,
                 ; ��������� �� ����� ��������������
                 ; ���������� _sub1
   call _sub1    ; ��������� �������� ���������� ����� (a1 + a2)
                 ; � ����� b3. ��������� ������������ � ��������
                 ; ��������� ����� ������� EAX
   ret
 _add_sub endp
 end

