.686
.model flat
option casemap: none
.data
  s1  DB "Test STRING"  ; ������ ������
  len EQU $-s1          ; ������ ������
  s2  DB "TEST STRING"  ; ������ ������
  dst DB 11 DUP(' '),0  ; �������������� ������
.code
 _eq_bytes proc
   push   EBX
   lea    ESI, s1            ; ����� ������ ������ -> ESI
   lea    EDI, s2            ; ����� ������ ������ -> EDI
   lea    EDX, dst           ; ����� �������������� ������ -> EDX
   mov    ECX, len           ; ������ ������ -> ECX
 next:
   mov    BL, '-'            ; �������� �������� -> BL (������
                             ; ������� �-� ����� ����� ������)
   mov    AL, [ESI]          ; ������ �� ������-��������� -> AL
   cmp    AL, [EDI]          ; �������� � �������� � ��� �� �������
                             ; ������-���������
   cmove  EBX, EAX           ; ���� ������� �����, ��������� � ������� BL
                             ; ������ �� AL
   mov    byte ptr [EDX], BL ; ��������� ������ �� ���������������
                             ; ������� � �������������� ������
   inc    ESI                ; ����� ���������� ������� ��������� -> ESI
   inc    EDI                ; ����� ���������� ������� ��������� -> EDI
   inc    EDX                ; ����� ���������� �������
                             ; ������ ���������� -> EDX
   loop   next               ; ������� � ��������� ��������
   lea    EAX, dst           ; ����� �������������� ������ -> EAX
   pop    EBX
   ret
  _eq_bytes endp
  end
