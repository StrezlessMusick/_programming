.model small
.data
  num1 DB '9'
  num2 DB '5'
  sum  DB 2 DUP (' ')
.code
start:
  mov  AX, @data
  mov  DS, AX
  clc                   ; ������� ����� �������� � �������� AX
  xor  AX, AX
  mov  AL, num1         ; ������� ������ ����� � AL
  adc  AL, num2         ; �������� � num2 � ������ ��������
  aaa                   ; ��������� ����������
  or   AX, 3030h        ; �������������� � ���������� �������������
  xchg AH, AL           ; ����� ������� ��� ���������� ������ �� �����
  mov  word ptr sum, AX ; ���������� ���������� � ���������� sum
; ����� ���������� �� �����
  mov CX, 2             ; �������� ����� ��������� ���� � ������� CX
  mov AH, 6h
  lea SI, sum           ; �������� ����� ���������� sum � SI
 next:
  mov DL, byte ptr [SI] ; �������� ��������� ���� � ������� DL
  int 21h               ; ����� �� �����
  inc SI                ; ������� ����� ���������� ������� � SI
  loop next             ; ������ �����
  mov ax, 4c00h
  int 21h
end start
end
