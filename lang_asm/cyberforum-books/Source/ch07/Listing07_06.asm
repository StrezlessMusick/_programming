.686
.model flat
option casemap: none
.MMX
.code
_copy_movq proc
  push EBP
  mov  EBP, ESP
  mov  ESI, dword ptr [EBP+8]     ; ����� �������-��������� -> ESI
  mov  EDI, dword ptr [EBP+12]    ; ����� �������-��������� -> EDI
  mov  EAX, dword ptr [EBP+16]    ; ������ �������-��������� � �������
                                  ; ������ -> EAX
  xor  EDX, EDX                   ; ������� EDX ��������� � ��������
                                  ; �������, ������� �������� ���
  mov  EBX, 2
  div  EBX                        ; ��������, ������� ������������ ����
                                  ; ���������� � �������-���������
  mov  ECX, EAX                   ; ����� �������: EAX = �������,
                                  ; EDX = �������. ����������
                                  ; ������������ ���� -> ECX (�������
                                  ; �����)
next:
  movq MM0, [ESI]                 ; ���������� 8-�������� �������
                                  ; �� �������-��������� � ������� MM0
  movq [EDI], MM0                 ; ���������� 8-�������� ������� ��
                                  ; �������� MM0 � ������-��������
  add  ESI, 8                     ; ����� ���������� 8-��������� ��������
                                  ; �������-��������� -> ESI
  add  EDI, 8                     ; ����� ���������� 8-��������� ��������
                                  ; �������-��������� -> EDI
  dec  ECX                        ; ��������� ������� ����� �� 1
  jnz  next                       ; ������� � ��������� ��������
  cmp  EDX, 0                     ; �������� �� � �������-���������
                                  ; �������������� ������� �����?
  je   exit                       ; ���, ����� �� ���������
  mov  ECX, EDX                   ; ��, ��������� ���� ��� ������� ����
  cld                             ; ���� ����������� -> ����������
                                  ; �������
next_remainder:
  movsd                           ; ����������� ������� ����� ��
                                  ; �������-��������� � ��������
  dec  ECX                        ; ��������� �������� �����
  jnz  next_remainder             ; ���� �� ����� 0, �� ���������
                                  ; ��������
exit:
  pop  EBP
  ret
_copy_movq endp
end
