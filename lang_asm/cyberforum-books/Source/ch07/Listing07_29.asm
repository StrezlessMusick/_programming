.model small
.stack 100h
.data
  s1       DB 0dh, 0ah, "String s1$"  ; ���������� ������ s1
  s2       DB 0dh, 0ah, "String s2$"  ; ���������� ������ s2
  s3       DB 0dh, 0ah, "String s3$"  ; ���������� ������ s3
  saddr   label dword                 ; ����� ������� ����� saddr
           DW  s1                     ; ����� ������ s1
           DW  s2                     ; ����� ������ s2
           DW  s3                     ; ����� ������ s3
  num      DW  0                      ; ��������� �������� ��������
.code
 start:
  mov   AX, @data
  mov   DS, AX
  mov   ES, AX
  mov   CX, 3
again:
  xor   SI, SI                        ; ����������� ��������� ������� SI
  add   SI,  num                      ; num -> SI
  shl   SI, 1                         ; ��������� ��������
                                      ; � ������� saddr
  mov   DX, word ptr saddr[SI]        ; ��������� � DX ����� ������
                                      ; � ������� �� �� �����
  mov   AH, 9h
  int   21h
  inc   num                           ; ��������� �������� ��� �������� �
                                      ; ��������� ������
  loop  again                         ; ��������� ��������
exit:
  mov   AX, 4c00h
  int   21h
  end start
  end
