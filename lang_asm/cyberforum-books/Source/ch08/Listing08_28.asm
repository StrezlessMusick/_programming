.586
.model flat
option casemap: none
.data
  iarray  DQ  9234764129, -16097233481, -7565902112, 39094647921
  len     EQU $-iarray
  sum     DQ  0
.code
 _sum_64 proc
   mov ECX, len    ; ������ ������� iarray (� ������) -> ECX
   shr ECX, 3      ; ������������� ������ � ���������� ������������ ����
   lea ESI, iarray ; ����� ������� -> ESI
   lea EDI, sum    ; ����� ���������� sum -> EDI
   clc
 next:
   mov EAX, dword ptr [ESI]    ; ������� ������� ����� ��������
                               ; �������-> EAX
   add dword ptr [EDI],EAX     ; ��������� � �������� �������� �����
                               ; ����� �����
   mov EDX, dword ptr [ESI+4]  ; ������� ������� ����� ��������
                               ; ������� -> EDX
   adc dword ptr [EDI+4], EDX  ; ��������� � �������� �������� �����
                               ; ����� ����� � ������ ��������
   add ESI, 8                  ; ������� � ���������� �������� �������
   clc                         ; �������� ���� ��������
   loop next                   ; ��������� ��������
   lea  EAX, sum               ; ����� ���������� sum -> EAX
   ret
 _sum_64 endp
  end
