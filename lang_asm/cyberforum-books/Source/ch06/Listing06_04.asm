.model small
.data
  s1     DB 0dh, 0ah, "Near indirect call of subr1 !$"
  s2     DB 0dh, 0ah, "Near indirect call of subr2 !$"
  addr1  DW subr1
  addr2  DW subr2
.code
 start:
  mov    AX, @data
  mov    DS, AX
  call   DS:addr1    ; ����� ������������ subr1 �� ��������,
                     ; �������������� � ���������� addr1
  call   DS:addr2    ; ����� ������������ subr2 �� ��������,
                     ; �������������� � ���������� addr2
  mov    AH, 1h
  int    21h
  mov    AX, 4C00h
  int    21h
 subr1   proc
   lea   DX, s1
   mov   AH, 9h
   int   21h
   ret
 subr1   endp
 subr2   proc
   lea   DX, s2
   mov   AH, 9h
   int   21h
   ret
 subr2   endp
 end     start
 end
