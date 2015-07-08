.586
.model flat
option casemap: none
.data
  a1        DD 123, -96, -17, 403
  len       EQU $-a1
  res       label dword
  sum_plus  DD 0
  sum_minus DD 0
.code
 _sum_plus_minus proc
   mov ECX, len   ; �������� ������ ������� a1 � ������� ECX
   shr ECX, 2     ; ������������ ������� ��� ������� ����
   lea EBX, a1    ; ����� ������� a1 �> EBX
next:
   xor EAX, EAX
   mov EAX, dword ptr [EBX] ; ��������� ������� -> EAX
   cmp EAX, 0               ; �������� � �����
   jl  plus                 ; ���� ����� ������ 0, ��������� ���
                            ; � sum_plus
   add sum_plus, EAX
   jmp continue
 plus:
   adc sum_minus, EAX       ; ����� ������ 0, ��������� ���
                            ; � sum_minus
 continue:
   add EBX, 4               ; ������� � ���������� �������� �������
   loop next                ; ��������� ��������
   lea  EAX, res            ; ����� ���������� -> EAX
   ret
 _sum_plus_minus endp
  end
