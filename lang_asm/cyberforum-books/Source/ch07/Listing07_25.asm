.model small
option casemap:none
.data
  s1    DB " test string 1 "
  len   EQU $-s1
        DB  '$'
.code
start:
  mov   AX, @data
  mov   DS, AX
  mov   ES, AX
  cld             ; ���������� ���� ����������� � ������� ����������
                  ; �������
  mov   CX, len   ; ������ ������ s1 -> CX
  lea   SI, s1    ; ����� ������� �������� ������ �> SI
  mov   DI, SI    ; ��� �� ����� -> DI
next:
  lodsb           ; ��������� ������ ������ s1 � ������� AL
  cmp   AL, 97    ; AL < �a�?
  jb    skip      ; ���, ��� ���������, ����������
  cmp   AL, 122   ; AL > �z�?
  ja    skip      ; ���, ��� ���������, ����������
  sub   AL, 32    ; ������������� ������ �� ��������� �a� � �z�
                  ; � ������ �� ��������� �A� � �Z�
skip:
  stosb           ; ��������� ������ �� ���� �� ������
  loop  next      ; ������� � ���������� �������
  jmp   exit
exit:
 lea    DX, s1    ; ���������� ��������������� ������
 mov    AH, 9h
 int    21h
 mov    AX, 4C00h
 int    21h
end     start
