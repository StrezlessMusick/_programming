. . .
.data
op1           db ?      ; ������ �������
op2           db ?      ; ������ �������
carry         db 0      ; ����� ������������ ���� ��������
substract     db 0      ; ����� �������� ��������� ���������
.code
sub_bytes proc
  clc             ; ������� ����� �������� ����� ���������
  mov AL, op1
  sub AL, op2
  jnc exit        ; �������� �� ������������
  add carry,0     ; ��������� ���� ��������
exit:
  mov  substract, AL
  ret
sub_bytes endp
