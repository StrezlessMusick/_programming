. . .
.data
op1     db ?      ; ������ �������
op2     db ?      ; ������ �������
carry   db 0      ; ����� ������������ ���� ��������
sum     db 0      ; ����� �������� ��������� ��������
.code
addb_unsigned proc
  clc             ; ������� ����� �������� ����� ���������
  mov AL, op1
  add AL, op2
  jnc exit        ; �������� �� ������������
  add carry,1     ; ��������� ���� ��������
exit:
  mov  sum, AL
  ret
addb_unsigned endp
