.686
.model flat
option casemap:none
.data
  iarray DD 23, -49, 65, 98, 133, 82 ; �������� �������� ���������
                                     ; �������
  len    DD $-iarray                 ; ������ ������� � ������
.code
_scas_dd proc
 mov    ECX, len                     ; ������ ������� -> ECX
 shr    ECX, 2                       ; ������������� � ����������
                                     ; ������� ����
 lea    EDI, iarray                  ; ����� ������� -> EDI
 mov    EAX, 100                     ; ������ ��� ��������� -> EAX
 xor    EDX, EDX                     ; ���������� �������� EDX
 cld                                 ; ���������� ���� �����������
                                     ; ��� ���������� ������
next:
 mov    EBX, dword ptr [EDI]         ; ������� ������� -> EBX
 scasd                               ; �������� EAX � ��������� �������
 cmovl  EBX, EDX                     ; ���� ������� ������� ������ 100,
 mov    dword ptr [EDI-4], EBX       ; �������� ���. ��������� ���������
                                     ; ������ ����� ���������� �������
                                     ; scasd ����������� �� 4, ����������
                                     ; ��� ������ � ������� mov
 loop  next
exit:
 lea   EAX, iarray                   ; ����� ������� -> EAX
 ret
_scas_dd endp
end
