.686
.model flat
option casemap: none
.data
memo  label qword 
 memo1  DD 9.18      ; ������ �����
 memo2  DD 1.05      ; ������ �����
.code
 fxch_demo proc
   finit
   fld  memo1        ; ��������� �������� ����������
                     ; memo1 � ����   
   fld  memo2        ; ��������� memo2 � ����
   fxch st(1)        ; �������� �������� � st(0) � st(1)
   fstp memo2        ; ��������� ���������� ������� ����� � memo2
   fstp memo1        ; ��������� ���������� ������� ����� � memo1
   lea  EAX, memo    ; ������� ����� ������� ������ � �������� EAX
   ret
 fxch_demo endp
 end
