.586
.model flat
option casemap:none
.code
_scas_dd proc
 push   EBP
 mov    EBP, ESP
 mov    ECX, dword ptr [EBP+12] ; ������ ������� -> ECX
 mov    EDI, dword ptr [EBP+8]  ; ����� ������� �������� -> EDI
 mov    EAX, 100                ; ������������ ��������
 cld                            ; ���������� ���� ����������� � �������
                                ; ���������� �������
next:
 scasd                          ; ���������� �������� ������� �
                                ; ���������� EAX
 jg    change                   ; ����� � EAX ������ �������� ��������?
                                ; ���� ���, ��������� ��������
 loop  next
 jmp   exit
change:                         ; ������� ������� ������ ����� � EAX
 mov   dword ptr [EDI-4], 0     ; �������� ���������� ������ ������ �� 0
 dec   ECX                      ; ��������� ��������
 jmp   next
exit:
 pop   EBP
 ret
_scas_dd endp
end
