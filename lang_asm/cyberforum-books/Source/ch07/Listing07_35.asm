.model small
.data
  tbl    DB "0123456789"   ; ������� ��������������
  res    DB 2 dup (' ')    ; ������� ������ ��� ����������
         DB '$'
.code
  start:
   mov    AX, @data
   mov    DS, AX
   lea    BX, tbl            ; ��������� ����� ������� � ������� BX
   lea    SI, res            ; ����� ���������� -> SI
   mov    DX, SI             ; ��������� ����� ���������� � �������� DX
   mov    AL, 19             ; ���������� ����� ��� �������������� -> AL
   cbw                       ; ����������� ���� � �����
   mov    CL, 10             ; �������� -> CL
   div    CL                 ; ����� ����� 19 �� 10
                             ; � ����������: AL = 1, AH = 9 (�������)
   xlat                      ; ������������� AL � ������
   mov    byte ptr [SI], AL  ; ��������� � ������ �������� ������
   xchg   AH, AL             ; �������� �����
   xlat                      ; ������������� � ������
   mov    byte ptr [SI]+1, AL ; ��������� AL �� ������ �������� ������
   mov    AH, 9h             ; ������� ��������� �� �����
   int    21h
   mov    AX, 4c00h
   int    21h
   end    start
   end
