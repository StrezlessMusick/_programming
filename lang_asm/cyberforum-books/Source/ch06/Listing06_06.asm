.model large
data segment
 tbl label  dword
     DD subr1                       ; ������� ����� ��������� subr1
     DD subr2                       ; ������� ����� ��������� subr2
     DD subr3                       ; ������� ����� ��������� subr3
 s1  DB 0dh, 0ah, "FAR INDIRECT CALL subr1 DEMO !$"
 s2  DB 0dh, 0ah, "FAR INDIRECT CALL subr2 DEMO !$"
 s3  DB 0dh, 0ah, "FAR INDIRECT CALL subr3 DEMO !$"
data ends
code0 segment
assume CS:code0, DS:data
 main proc
  mov  AX, data
  mov  DS, AX
  lea  SI, tbl                    ; ����� ������� ������� �������� -> SI
  push SI                         ; �������� ��� �����������
                                  ; �������������
; ��������� ������� ������� ��� ������ �� �������� subr1, subr2 � subr3
  mov  word ptr [SI], offset subr1 ; �������� ��������� subr1 �> ������
                                   ; ����� ����������� ������ ������
  mov  AX, code1                   ; ����� ��������, ��� ���������
                                   ; ��������� subr1 �> AX
  mov  word ptr [SI+2], AX         ; ���������� AX -> ������ �����
; ������� � ���������� �������� ������� � ���������� �������� ������
; ��������� subr2 �� ������ ������� �����
  add  SI, 4
  mov  word ptr [SI], offset subr2
  mov  AX, code2
  mov  word ptr [SI+2], AX
; ������� � ���������� �������� ������� � ���������� �������� ������
; ��������� subr3 � ������� ������� �����
  add  SI, 4
  mov  word ptr [SI], offset subr3
  mov  AX, code3
  mov  word ptr [SI+2], AX
  pop  SI                          ; ��������������� ��������� �����
                                   ; ������� tbl
  xor  BX, BX                      ; �������������� ������� BX, �������
                                   ; ����� ����������� ��� ����������
                                   ; �������
  mov  CX, 3                       ; �������� �������� -> CX
next:
  call dword ptr [BX][SI]          ; ������� ��������� ����� ��������
                                   ; subr1, subr2 � subr3
  add  BX, 4                       ; ������� � ������ ��������� ���������
                                   ; � ������� tbl
  dec  CX                          ; ��������� ������� �� 1
  jnz  next                        ; ��������� ��������, ����
                                   ; CX �� ����� 0
  mov  AX, 4C00h
  int  21h
 main  endp
code1  segment
assume CS:code1
subr1  proc far                    ; ���������� ��������� subr1
  lea  DX, s1
  mov  AH, 9h
  int  21h
  ret
subr1  endp
code1  ends
code2  segment
assume CS:code2
subr2  proc far                    ; ���������� ��������� subr2
  lea  DX, s2
  mov  AH, 9h
  int  21h
  ret
subr2  endp
code2  ends
code3  segment
assume CS:code3
subr3  proc far                     ; ���������� ��������� subr3
  lea  DX, s3
  mov  AH, 9h
  int  21h
  ret
subr3  endp
code3  ends
end main
end
