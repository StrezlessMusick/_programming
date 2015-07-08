.model small
option casemap:none
.data
  s1  DB  " TEST: first word     second word    third     word OK    !  "
  len EQU $-s1
  msg DB  "Number of words = "
  cnt DB  0
      DB  '$'
.code
start:
  mov   AX, @data
  mov   DS, AX
  mov   ES, AX
  mov   CX, len    ; ������ ������ -> CX
  lea   DI, s1     ; ����� ������� �������� ������ -> DI
  mov   AL, ' '    ; ������-����������� -> AX
  cld              ; ��������� ������ ��� ����������� ��������
next:
  repe  scasb      ; ���������� �������
  je    exit       ; ����� �������� ������ ��� � ��������� ������
                   ; ���������
  inc   cnt        ; ���������� ����� � ��������� ������� ����
  repne scasb      ; ���� ����� �����, ������ ������ ���� �������
  jne   exit       ; ������ ����������� � ����� �� ���������
  jmp   next       ; ����� ���������� �����
exit:
 or     cnt, 30h   ; ������������� ������������ �����
                   ; � ���������� ASCII-������
 lea    DX, msg    ; ���������� ���������
 mov    AH, 9h
 int    21h
 mov    AX, 4C00h  ; ��������� ���������
 int    21h
end     start
end
