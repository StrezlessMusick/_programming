.model small
.data
  s1  DB " TEST STRING$"
  len EQU $-s1
.code
  start:
   mov   AX, @data
   mov   DS, AX
   mov   ES, AX
   cld            ; ���������� ���� �������� ��� ���������� ������
   mov  AL, 'X'   ; ������-����������� -> AL
   lea  DI, s1    ; ����� ������-���������
   mov  CX, len-1 ; ������ ������ ��� ����� ���������� ������� -> CX
   rep  stosb     ; ��������� ������� ������ �������� �X�
   lea  DX, s1    ; ����� ����������� ������ �� �����
   mov  AH, 9h
   int  21h
   mov  AX, 4c00h
   int  21h
   end  start
   end
