.model small
.data
  src   DB    "COPIED TEST STRING"
  len   EQU $-src
  dst   DB    len DUP (' ')
        DB    '$'
.code
start:
   mov  AX, @data  ; ������������� ���������� ���������
   mov  DS, AX
   mov  ES, AX
   cld             ; ��������� ���� ����������� DF ��� ����������
   lea  SI, src    ; ����� ��������� -> DS:SI
   lea  DI, dst    ; ����� ��������� -> ES:DI
   mov  CX, len    ; ���������� ���������� �������� -> CX
   rep  movsb      ; ����������� ��������
   lea  DX, dst    ; ���������� ������������� ������ �� ������
   mov  AH, 9h
   int  21h
   mov  AX, 4c00h
   int  21h
   end  start
   end
