.586
.model flat
option casemap: none
.data
  a1  DD 12, -345, -49, 91
  a2  DD -48, 199, -812, 32
  len EQU $-a2
  sum DD 4 DUP (0)
.code
 _sum_ints proc
   mov ECX, len     ; ������ �������� (� ������) -> ECX
   shr ECX, 2       ; ��������� ECX ��� �������� � �������� �������
                    ;(������� �� 4)
   lea ESI, a1      ; ����� ������� �������� ������� a1 -> ESI
   lea EDI, a2      ; ����� ������� �������� ������� a2 -> EDI
   lea EBX, sum     ; ����� ������� �������� ������� sum -> EBX
 next:
   clc
   xor EAX, EAX     ; ����� ����������� �������� ������� ������� EAX
   mov EAX, [ESI]   ; ������� ������� a1 -> EAX
   adc EAX, [EDI]   ; ������� � ��������������� ��������� ������� a2
   mov [EBX], EAX   ; �������� ����� ��������� �� ��������������� �������
                    ; � ������� sum
   add ESI, 4       ; ������� � ������ ���������� �������� � ������� a1
   add EDI, 4       ; ������� � ������ ���������� �������� � ������� a2
   add EBX, 4       ; ������� � ������ ���������� �������� � ������� sum
   loop next        ; ��������� ��������
   lea  EAX, sum    ; ����� ������� sum -> EAX
   ret
 _sum_ints endp
  end
