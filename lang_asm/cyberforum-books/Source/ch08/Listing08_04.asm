. . .
.data
op1     dw 1407      ; ������ �������
op2     dw 9119      ; ������ �������
carry   db 0      ; ����� ������������ ���� ��������
sum     dw 0      ; ����� �������� ��������� ��������
.code
addw_unsigned proc
  clc             ; ������� ����� �������� ����� ���������
  mov AX, op1
  add AX, op2
  jnc exit        ; �������� �� ������������
  add carry,1     ; ��������� ���� ��������
exit:
  mov  sum, AX
  ret
addw_unsigned endp
