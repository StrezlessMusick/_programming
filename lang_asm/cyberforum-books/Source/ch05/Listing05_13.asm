. . .
.data
  iarray DD 10 dup (0)
  len  EQU $-iarray
.code
. . .
  mov  ECX, len            ; ����� ��������� ������� (� ������) -> ECX
  lea  ESI, i1             ; ����� ������� �������� ������� -> ESI
  mov  EBX, 2              ; �������� �������� 2 � ������� EBX ���
                           ; �����������, ������ ��� �������� �������
next:
  mov  EAX, ECX            ; ������� ��������� -> EAX
  div  EBX                 ; ����������, ������ ��� ��������
                           ; ���������� ����� � �������� �������
  cmp  EDX, 0
  jne  store_1             ; ���� ��������, ����������� ��������
                           ; �������� 1
  mov  DWORD PTR [ESI], 0  ; ���� ������, ����������� �������� �������� 0
  jmp  next_addr
store_1:
  mov  DWORD PTR [ESI], 1
next_addr:                 ; ����� ���������� �������� �������
  add  ESI, 4
  loop next
  . . .
