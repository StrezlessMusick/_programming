.model small
.data
 src        DB "ADDED CHARACHTERS$"   ; ������ src, ������� �����
                                      ; ��������� � dst
 len_src    EQU $-src                 ; ������ ������ src
 dst        DB "ORIGINAL CHARACHTERS" ; ������-��������, � ����� �������
                                      ; ����� ���������
                                      ; ������� ������ src
 len_dst    EQU $-dst                 ; ������ ������ dst
 suppl      DB len_src+1 DUP(' ')     ; ����������������� ������� ������
                                      ; ��� ���������� �������� �� ������
                                      ; src � ������� ������� ���
                                      ; ���������� �����
.code
  start:
   mov    AX, @data
   mov    DS, AX
   mov    ES, AX
   cld
   lea    SI, src
   lea    DI, dst+len_dst+1
   mov    CX, len_src
   rep    movsb
   lea    DX, dst
   mov    AH, 9h
   int    21h
   mov    AX, 4c00h
   int    21h
   end    start
   end
