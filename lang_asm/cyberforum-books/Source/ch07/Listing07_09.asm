.model small
.stack
.data
  src     DB    "FIRST sTRING 1"
  lsrc    EQU   $-src
  dst     DB    "FIRST STRING 1"
  equal   DB    "Strings are equal", '$'
  non_eq  DB    "Strings are not equal", '$'
.code
start:
   mov  AX, @data   ; ������������� ���������� ���������
   mov  DS, AX
   mov  ES, AX
   cld              ; ��������� ����� ���������� DF ���
                    ; ���������� �������
   lea  SI, src     ; ����� ��������� -> DS:SI
   lea  DI, dst     ; ����� ��������� -> ES:DI
   mov  CX, lsrc    ; ���������� ������������ ������ -> CX
   repe cmpsb       ; �������� ��������� ������ 
   je   yes         ; ������ ���������?
   lea  DX, non_eq  ; ���, ���������� ��������������� ���������
   jmp  output
yes:                ; ��, ���������� ���������
   lea  DX, equal
output:
   mov  AH, 9h
   int  21h
   mov  AX, 4c00h
   int  21h
   end  start
   end
