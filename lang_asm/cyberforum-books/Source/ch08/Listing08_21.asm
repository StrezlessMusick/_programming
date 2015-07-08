.model small
.data
  num1    DB '18'
  num2    DB '2'
  res     DB  ?
.code
start:
  mov  AX, @data
  mov  DS, AX
  clc
  mov  AX, word ptr num1  ; ��������� ������� � AX
  xchg AH, AL             ; ���������� ���������� ������� ������
  and  AX, 0F0Fh          ; ������������� ����� � AX � �������������
                          ; �������-���������� (AX = 0306h)
  mov  CL, num2           ; ��������� ������ ����� � CL
  and  CL, 0Fh            ; ������������� ����� � CX � �������������
                          ; �������-���������� (CL = 02h)
  aad                     ; ��������� ��������� AX ����� ��������
                          ; (AX = 1Ch)
  div  CL
  or   AL, 30h            ; ������������� ��������� � ����������
                          ; ASCII-������������� (AL = 34h)
  mov  DL, AL             ; ����� ������� �� �����
                          ; (� DL � ��������� ������)
  mov AH, 2h
  int 21h
  mov ax, 4c00h
  int 21h
end start
end
