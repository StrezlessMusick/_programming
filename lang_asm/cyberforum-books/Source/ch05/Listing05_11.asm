. . .
.data
  src  DD 345, -65, 12, 99, 369, 267
  len  EQU $-src
  dst  DD 6 DUP (?)
.code
. . .
  mov ESI, src     ; ����� ��������� src�> ESI
  mov EDI, dst     ; ����� ��������� dst -> EDI
  mov ECX, len     ; �������� �������� ���� -> ECX
  shr ECX, 2       ; ��������� �������� ��������
                   ; � ������� �����
L1:
  mov EAX, [ESI]
  add ESI, 4
  mov [EDI], EAX
  add EDI, 4
  dec ECX
  jnz L1
. . .
