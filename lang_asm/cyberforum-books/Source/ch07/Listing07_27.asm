.model small
.data
  src   DB "123 456 789$"  ; ������, ������� ����� �������������
   len  EQU $-src-1        ; ������ ������ �� ������� �$�
   tmp  DB 11 DUP (20h)    ; ��������� ����� ��� �������� ������
.code
  start:
    mov   AX, @data
    mov   DS, AX
    mov   ES, AX
    mov   CX, len
    std                     ; ���� DF �> 1, ���������� ������ src
    lea   SI, src           ; ����� ������������� ������ -> SI
    add   SI, len-1         ; ���������� ��������� �� ����� ����������
                            ; �������� ������ src
    lea   DI, tmp           ; ����� ���������� ������ ������ -> DI
next:
    lodsb                   ; ������� ������ src -> AL
    mov   byte ptr [DI], AL ; ��������� ������ � ������ tmp
    inc   DI                ; ������� � ���������� ������ �
                            ; ������ tmp (��������� ������)
    loop  next              ; ��������� ��������
    cld                     ; ���������� ���� DF � 0 ���
                            ; ���������� �������
    mov   CX, len           ; ������ ������ src �> CX
    lea   SI, tmp           ; ����� ������-��������� -> SI
    lea   DI, src           ; ����� ������-��������� -> DI
    rep   movsb             ; ����������� �� tmp � src 
    lea   DX, src           ; ����� ���������� �� �����
    mov   AH, 9h
    int   21h
    mov   AX, 4c00h
    int   21h
    end   start
    end
