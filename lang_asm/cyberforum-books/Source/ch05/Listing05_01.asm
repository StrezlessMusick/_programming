.model small
.stack 100h
.data
  s1  DB 0dh, 0ah, "String 1$" 
  s2  DB 0dh, 0ah, "String 2$"
  s3  DB 0dh, 0ah, "String 3$"

  sarray   label word          ; ������, � ������� �������� ������ �����
      DW s1                    ; s1 � s2
      DW s2
      DW s3 
  num DW 0                     ; ������ � ������ �������� ������� jmp
  label_array label word       ; ������ ������� �����
      DW L1                    ; ����� ����� L1
      DW L2                    ; ����� ����� L2
      DW L3                    ; ����� ����� L3
.code
 start:
  mov   AX, @data
  mov   DS, AX
  mov   ES, AX
  ;
  mov   CX, 3                  ; ������� ����� -> CX
  lea   DI, label_array        ; ����� ������� �����
next:
  mov   SI, DI
  mov   BX, num                ; ������ �������� -> BX
  shl   BX, 1                  ; �������� �� 2 ��� ���������� ���������
                               ; ����� � ������� label_array 
  add   SI, BX                 ; ������������ ����� ��������
                               ; ��� ������� jmp 
  jmp   word ptr [SI]          ; ������� �� ������, ������������
                               ; � �������� SI (L1 ��� L2)
wedge:
  inc   num                    ; ��������� ������� ���������
  loop  next                   ; ��������� ����
  ;
 L1:                           ; �������� ���� ��� �������� �� ����� L1
  lea  DX, s1
  mov  AH, 9h
  int  21h
  jmp  wedge                   ; ��������� � ����
 L2:                           ; �������� ���� ��� �������� �� ����� L2
  lea  DX, s2
  mov  AH, 9h
  int  21h
  jmp  wedge
 L3:                           ; �������� ���� ��� �������� �� ����� L3
  lea  DX, s3
  mov  AH, 9h
  int  21h
  ;
  mov  AH, 1h                  ; ������� ����� ������ �������
  int  21h
  ;
  mov  AX, 4c00h               ; ���������� ���������
  int  21h
  end  start
  end
