.model small
.data
  num1    DB '8'
  num2    DB '3'
.code
start:
  mov  AX, @data
  mov  DS, AX
  clc             ; ������� ����� ��������
  mov  AL, num1   ; ������ ����� � AL
  sbb  AL, num2   ; ������� ������ � ������ ���������� �����
  aas             ; ��������� ����������
  or   AL, 30h    ; ������������� ��������� � ���������� �������������
; ����� �� �����
  mov  DL, AL
  mov AH, 6h
  int 21h
  mov ax, 4c00h
  int 21h
end start
end
