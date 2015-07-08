.model large
data segment
  s1   DB 0dh, 0ah, "Direct far call of subr1 demo !$"
  s2   DB 0dh, 0ah, "Direct far call of subr2 demo !$"
data ends
code1 segment
assume CS:code1
 main proc            ; ����� ����� � �������� ���������
  mov  AX, @data
  mov  DS, AX
  call far ptr subr1  ; ������� ����� ������������ subr1
  call far ptr subr2  ; ������� ����� ������������ subr2
                      ; ��� ������� call � �����
                      ; �������: 9� <��������> <�������>
  mov  AH, 1h
  int  21h
  mov  Ax, 4C00h
  int  21h
 main  endp
code1  ends
code2 segment
assume CS:code2
subr1 proc far        ; ���������� ������� ������������ subr1
   lea DX, s1
   mov AH, 9h
   int 21h
   ret                ; ������� ret ����� ��� 0��h (������� �� �������
                      ; ������������)
subr1 endp
subr2 proc far        ; ���������� ������� ������������ subr2
   lea DX, s2
   mov AH, 9h
   int 21h
   ret                ; ������� ret ����� ��� 0��h (������� �� �������
                      ; ������������)
subr2 endp
code2 ends

