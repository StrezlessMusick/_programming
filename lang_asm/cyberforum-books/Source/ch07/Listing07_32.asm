.model small
.data
   s1   DB "ABCDEFG$"
   len  EQU $-s1-1         ; � ��������� len �� ����������� ���������
                           ; ������� (�$�), ��������� �� �������� ��
                           ; �����
.code
 start:
  mov    AX, @data
  mov    DS, AX
  mov    ES, AX
  lea    SI, s1            ; ����� �������
                           ; �������� -> SI (������ ���������)
  lea    DI, s1+len-1      ; ����� ������� �G� -> DI (��������
                           ; ���������)
next:
  mov    AL, byte ptr [SI] ; ����� ����������� ����� ��������� ������,
  xchg   AL, byte ptr [DI] ; ����������� � ������� ������ � ��������
  mov    byte ptr [SI], AL ; � ��������� SI � DI
  inc    SI                ; ���������� ������ ������ ���������
  dec    DI                ; ��������� �������� ���������
  cmp    SI, DI            ; �������� ������
  jb     next              ; ����� � SI ��� ��� ������ ������ � DI
                           ; ��������� ����
  lea    DX, s1            ; �������������� ���������, ����� ����������
  mov    AH, 9h
  int    21h
  mov    AX, 4C00h
  int    21h
  end    start
  end
