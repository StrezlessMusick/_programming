.686
.model flat
option casemap:none
.data
  num1  DB '0037'
  len1  EQU $-num1
  num2  DB '0986'
  sum   DB 4 DUP (' ')    ; ����������� ������ ��� ����������
.code
 _add_asc proc
   mov  ECX, len1         ; �������� ������ ��������� (� ������) � ECX
   clc                    ; ������� ����� ��������
; ���������� �������� � �����
 again:
   mov  AL, byte ptr num1[ECX-1] ; �������� ������� ���� num1 � AL
   adc  AL, byte ptr num2[ECX-1] ; �������� � ����� �� ������ � num2
   aaa                           ; ��������� ����������
   mov  byte ptr sum[ECX-1], AL  ; ���������� ���������� �
                                 ; ��������������� ����� ����������
                                 ; sum
   loop again
   adc  byte ptr sum[ECX-1], 0   ; ��������� ����������
   or   dword ptr sum, 30303030h ; �������������� � ���������� ���
   lea  EAX, sum                 ; �������� ����� ���������� � ��������
                                 ; EAX
   ret
 _add_asc endp
 end
