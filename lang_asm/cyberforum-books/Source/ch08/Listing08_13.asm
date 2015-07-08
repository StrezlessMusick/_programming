.686
.model flat
option casemap:none
.data
  op1  DD 32267  ; |������� ����� = b |������� ����� = a |
  op2  DD 17904  ; |������� ����� = d |������� ����� = c |
  res  DQ 0
.code
 _mul_multibytes proc
   lea  ESI, op1     ; �������� ����� op1 � ESI
   lea  EDI, op2     ; �������� ����� op2 � EDI
;   ��������� ��������� ������������ b * d
   clc
   mov   AX, word ptr [ESI] ; �������� b � AX
   push  EAX                ; ��������� EAX
   mov   BX, word ptr [EDI] ; �������� d � BX
   mul   BX                 ; ��������� AX * BX
   mov   word ptr res, AX   ; ��������� ������� ����� ����������
   mov   word ptr res+2, DX ; ��������� ������� ����� ����������
   pop   EAX         ; ��������� EAX ��� ���������� ������� ������������
;   ��������� ��������� ������������ b * c
   mov   BX, word ptr [EDI]+2 ; �������� c � BX
   mul   BX                   ; ��������� AX * BX
   add   word ptr res+2, AX   ;�������� ��������� ������������ b * d � b * c
   adc   word ptr res+4, DX   ; ������ �������
   jnc   next                 ; ������ �������?
   inc   word ptr res+6       ; ��, ����� ��� ������ � ������� �����
 next:
;   ��������� ��������� ������������ a * d
   mov   AX, word ptr [ESI]+2 ; �������� a � AX
   push  EAX                  ; ��������� EAX
   mov   BX, word ptr [EDI]   ; �������� d  � BX
   mul   BX                   ; ��������� AX * BX
   add   word ptr res+2, AX   ; ���������� a * d � ������� ������������
   adc   word ptr res+4, DX   ; ������ �������
   pop   EAX      ; ��������� EAX ��� ���������� ���������� ������������
   jnc   hi                   ; ������ �������
   inc   word ptr res+6       ; ��, ����� ��� ������ � ������� �����
hi:
;   ��������� ��������� ������������ a * c 
   mov   BX, word ptr [EDI]+2 ; �������� c � BX
   mul   BX                   ; ��������� AX * BX
   add   word ptr res+4, AX   ; ���������� a * c � ������� ������������
   adc   word ptr res+6, DX   ; ������ �������
   lea   EAX, res             ; ��������� � EAX ����� ������������
   ret
 _mul_multibytes endp
 end
