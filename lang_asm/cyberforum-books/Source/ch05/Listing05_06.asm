.686
.model flat
option casemap: none
.data
  a1   DD 34, -53, 88, 13, 67
  len  EQU $-a1
.code
 find_num  proc
  lea   ESI, a1               ; ����� ������� -> ESI
  mov   ECX, len              ; ������ ������� � ������ -> ECX
  shr   ECX, 2                ; ������������� � ���������� ������� ����
next:
  cmp   dword ptr [ESI], 100  ; ������� ������� ������ ��� ����� 100 ?
  jle   next1                 ; ��, �������� ��������� ��������
  jmp   next_addr             ; ����� ������ 100, �������
                              ; � ���������� ������
next1:
  cmp   dword ptr [ESI], 50   ; ������� ������� ������ ��� ����� 50 ?
  jge   found                 ; ��, ������� ���������, ��������� ��� �
                              ; ������� EAX � ����� �� ���������
next_addr:                    ; ������� � ���������� �������� �������
  add   ESI, 4
  dec   ECX                   ; ��������� ��������
  jnz   next                  ; ���� ���������� ECX �� ����� 0,
                              ; ������� � ��������� �������� 
  mov   EAX, 0                ; ���� ��������, ��������� �������
                              ; �����������, �������� � EAX �������� 0
  jmp   exit
found:
  mov   EAX, [ESI]            ; ��������� ������� -> EAX
exit:
  ret 
find_num endp  
end
