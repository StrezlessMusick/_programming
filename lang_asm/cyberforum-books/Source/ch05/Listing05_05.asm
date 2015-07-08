.586
.model flat
option casemap: none
.data
 a1  DD 312, -45, 91, -16, -377  ; ����������� ������
 len EQU $-a1                    ; ������ ������� � ������
.code
_loopd_ex proc
  mov   ECX, len                 ; ������ ������� � ������ -> ECX
  shr   ECX, 2                   ; ������������� ������ � ������� �����
  lea   ESI, a1                  ; ����� ������� �������� -> ESI
  mov   EAX, -100                ; ������ ��� ��������� -> EAX
next:
  cmp   EAX, [ESI]               ; �������� ������� �������
                                 ; � ���������� �������� EAX
  jge   found                    ; ����� � ������� ������ -100,
                                 ; ��������� ���������
  add   ESI, 4                   ; ����� ������ -100, �������
                                 ; � ���������� �������� �������
  loopd next                     ; ��������� ��������
  jmp   not_found                ; ������ ��������, ����� ������ -100 ���
found:  
  mov   EAX, [ESI]               ; �������� �������� ������� -> EAX
  jmp   exit                     ; ����� �� ��������� 
not_found:
  mov   EAX, 0                   ; ��� ��������� ������ � ������� EAX
                                 ; ���������� 0
exit:
  ret
 _loopd_ex endp
 end
