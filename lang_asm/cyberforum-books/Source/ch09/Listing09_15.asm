.686
.model flat
option casemap:none
.data
  coeff DD 57.32           ; ����������� ��� �������� ��������
                           ; ���� �� ������ � �������
                           ; � �������� ������ 180/pi
  res   DD 0
.code
 _arctg_demo proc
   push  EBP
   mov   EBP, ESP
   finit
   fld   dword ptr [EBP+8] ; �������� �������� ����
   fld1                    ; ��������� 1
; ����� ���������� ���� ������ ������� st(0) �������� 1,
; � ������� st(1) � �������� �������� �������� ����
   fpatan                  ; ��������� ����
   fmul  dword ptr coeff   ; ��������� �������� ���� � �������
   fstp  dword ptr res     ; ��������� ��������� � ���������� res
                           ; � ���������� ���������� �� ������� �����
   lea   EAX, res          ; ����� ���������� -> EAX
   pop   EBP
   ret
 _arctg_demo endp
 end
