.model small
.data
 src        DB  "STRING 11", 0
 dst        DB  "STRING 117", 0
 s_eq       DB "Strings are equal$"
 s_ne       DB "Strings are not equal$"
 size_diff  DB "Strings have different size !$"
.code
start:
  mov  AX, @data
  mov  DS, AX
  mov  ES, AX
  lea  SI, src       ; ��������� ����� ������-��������� -> SI
  mov  DX, SI        ; ��������� ��������� ����� � �������� DX
  mov  AL, 0         ; ������ ��� ��������� -> AL
src_again:
  cmp  AL, [SI]      ; ��������� ����� ������?
  je   check_dst     ; ��, ��������� ������-��������
  inc  SI            ; ���, ����� ������ �� ���������, �������
                     ; � ���������� ������
  jmp  src_again
check_dst:
  lea  DI, dst       ; ��������� ����� ������-��������� -> DI
  mov  BX, DI        ; ��������� ��������� ����� � �������� BX
dst_again:
  cmp  AL, [DI]      ; ��������� ����� ������?
  je   check_size    ; ��, �������� ������� �����
  inc  DI            ; ���, ����� ������ �� ���������, �������
                     ; � ���������� ������
  jmp  dst_again
check_size:
  mov  CX, SI        ; �������� ����� ������-��������� -> CX
  sub  CX, DX        ; ��������� ������ ������-��������� ��� ��������
                     ; ��������� � ���������� �������
  mov  AX, DI        ; �������� ����� ������-��������� -> AX
  sub  AX, BX        ; ��������� ������ ������-��������� ��� ��������
  sub  AX, BX        ; ��������� � ���������� �������
  cmp  AX, CX        ; ������� ����� �����?
  je   compare       ; ��, ������� ������
  lea  DX, size_diff ; ���, ���������� ���������
  jmp  show
compare:
  cld                ; ���������� ���� ����������� ��� ���������� �������
  mov  SI, DX        ; ��������� ����� ������-��������� -> SI
  mov  DI, BX        ; ��������� ����� ������-��������� -> DI
  repe cmpsb         ; �������� ������
  je   equal         ; ������ �����?
  lea  DX, s_ne      ; ���, ���������� ��������������� ���������
  jmp  show
equal:
  lea  DX, s_eq      ; ��, ���������� ��������������� ���������
show:
  mov  AH, 9h
  int  21h
  mov  AX, 4c00h
  int  21h
  end start
  end
