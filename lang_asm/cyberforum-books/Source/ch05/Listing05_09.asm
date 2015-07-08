.686
.model flat
option casemap:none
.data
  iarray  DD -73, 931, -89, 92, -5, 67, 30
  len     EQU $-iarray
.code
 _set0 proc
   lea   ESI, iarray        ; ����� ������� -> ESI
   mov   EDX, len           ; ������ ������� (� ������) -> EDX
   shr   EDX, 2             ; ������������� � ���������� ������� ����
next:
   cmp   dword ptr [ESI], 0 ; �������� ������� ������� � �����
   jge   no_change          ; ���� ������ ����, �������� ��� ���������
   mov   dword ptr [ESI], 0 ; ���� ������ ����, �������� �� 0
no_change:
   add   ESI, 4             ; ������� � ���������� �������� 
   dec   EDX                ; ��������� ������� ����� �� 1
   jnz   next               ; ������� � ��������� ��������
   lea   EAX, iarray        ; ����� ������� -> EAX
   ret
  _set0 endp
  end
