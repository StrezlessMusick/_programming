.686
.model flat
option casemap: none
.data
 i_asc   DB  '5749'
 len     EQU $-i_asc        ; ���������� ������ ASCII-����� � ������
 i_bin   DD 3772
.code
 _asc_bin proc
   clc                      ; ������� ����� ��������
   lea   ESI, i_asc         ; �������� ����� i_asc � ESI
   mov   ECX, len           ; ��������� ������ ����� � ECX
   xor   EAX, EAX
   mov   BX,  10            ; �������� ��������� � ������� BX
 again:
   mul   BX                 ; AX * BX
   mov   DL, byte ptr [ESI] ; ��������� ��������� ����� ASCII-����� � DL
   and   DL, 0Fh            ; ������� ����� ��������
   movzx DX, DL             ; ��������� DL �� DX ��� ������������
                            ; ��������
   add   AX, DX             ; �������� ��������� ����� � ���������������
                            ; ASCII-�����
   inc   ESI                ; ������� � ���������� ����� ASCII-�����
   loop  again              ; ��������� ��������
   movzx EAX, AX            ; ���������� AX �� EAX ��� ����������
                            ; 32-���������� ��������
   add   EAX, i_bin         ; ���������� ����� i_asc + i_bin
                            ; � ���������� �� EAX
   ret
 _asc_bin endp
  end
