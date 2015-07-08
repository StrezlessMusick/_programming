.586
.model flat
option casemap: none
.data
 iarray DD 45, -78, 34, 9, 231, 45, -12
 len    EQU $-iarray
 maxval DD 0
.code
 _max proc
  lea  ESI, iarray  ; ����� ������� �������� -> ESI
  mov  ECX, len     ; ������ ������� -> ECX
  shr  ECX, 2       ; ��������������� ������
  mov  EAX, [ESI]   ; ��������� ������ ������� ������� � EAX
                    ; � ������� ��� � �������� ���������
next:
  cmp  EAX, [ESI+4] ; �������� �� ��������� ��������� �������
  jl   change       ; ���� EAX ������, �������� ���
go_loop:
  add  ESI, 4       ; ������� � ���������� ��������
  loop next
  jmp  exit
change:
  mov  EAX, [ESI+4]
  jmp  go_loop
exit:
  mov  max, EAX
  lea  EAX, maxval
  ret
 _max  endp
  end
