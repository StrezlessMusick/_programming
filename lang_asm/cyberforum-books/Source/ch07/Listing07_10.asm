.586
.model flat
option casemap:none
.data
 not_equal DB "NOT equal"
           DB 0
 equal     DB "Equal"
           DB 0
.code
 _compare_strings proc
   push EBP
   mov  EBP, ESP
   mov  EDI, dword ptr [EBP+16] ; ����� ������ ������ -> EDI
   mov  ESI, dword ptr [EBP+12] ; ����� ������ ������ -> ESI
   mov  ECX, dword ptr [EBP+8]  ; ������ ������ -> ECX 
   cld                          ; ���������� ���� �����������
                                ; ��� ���������� �������
   repe cmpsb                   ; ��������� ��������� �����
   je   s_equals
   lea  EAX, not_equal
   jmp  exit
 s_equals:
   lea  EAX, equal
 exit:
   pop  EBP
   ret
  _compare_strings endp
  end
