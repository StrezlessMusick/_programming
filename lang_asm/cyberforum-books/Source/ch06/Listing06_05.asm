.model small
data segment
 tbl label  word
     DW subr1           ; �������� ��������� subr1
     DW subr2           ; �������� ��������� subr2
     DW subr3           ; �������� ��������� subr3
 s1  DB 0dh, 0ah, "Near indirect call subr1 demo 2 !$"
 s2  DB 0dh, 0ah, "Near indirect call subr2 demo 2 !$"
 s3  DB 0dh, 0ah, "Near indirect call subr3 demo 2 !$"
data ends
code segment
assume CS:code, DS:data
main proc
 mov   AX, data
 mov   DS, AX
 lea   SI, tbl           ; ����� ������� �������� -> SI
 xor   BX, BX            ; ��������� �������� -> BX
 mov   CX, 3             ; �������� �������� -> CX
next:
 call  word ptr [BX][SI] ; ����� ����� �� ��������
 add   BX, 2             ; ������ ��������� �� ��������� �������
                         ; � ������� �������� ��������
 dec   CX                ; ��������� ���������� �������� �� 1
 jnz   next              ; ��������� ��������
 mov   Ax, 4C00h
 int   21h
 main  endp
subr1  proc              ; ���������� ��������� subr1
 lea   DX, s1
 mov   AH, 9h
 int   21h
 ret
subr1  endp
subr2  proc              ; ���������� ��������� subr2
 lea   DX, s2
 mov   AH, 9h
 int   21h
 ret
subr2  endp
subr3  proc              ; ���������� ��������� subr3
 lea   DX, s3
 mov   AH, 9h
 int   21h
 ret
subr3  endp
end    main
code   ends
end
