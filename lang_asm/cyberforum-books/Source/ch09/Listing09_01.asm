.686
.model flat
option casemap: none
.data
 src  DD 13.49, -71.01, -8.15, 33.39, 765.11
 len  EQU $-src
 dst  DD len DUP(0)
.code
 move_float proc
   finit
   mov  ECX, len         ; ���������� ���� ������� src �> ECX
   shr  ECX, 2           ; �������� � ����������� �������� �����
   lea  ESI, src         ; ����� ������� src -> ESI
   lea  EDI, dst         ; ����� ������� dst -> EDI
next:
   fld  dword ptr [ESI]  ; ��������� � ������� ����� ������� ������� src
   fstp dword ptr [EDI]  ; ��������� � ������ dst �������
                         ; �� ������� �����
   add  ESI, 4           ; ������� � ���������� �������� � src
   add  EDI, 4           ; ������� � ���������� �������� � dst
   dec  ECX              ; ��������� ��������
   jnz  next             ; ���� �� ����� 0, �������
                         ; � ��������� ��������
   lea  EAX, dst         ; ������� � �������� EAX ����� ������� dst
   ret
 move_float endp
 end
