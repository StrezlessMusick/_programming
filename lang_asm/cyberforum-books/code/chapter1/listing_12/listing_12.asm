PUSH CS
;������� ������ ��������� � ��������� ����
POP DS		
MOV DX,OFFSET MSG
MOV AH,9
;����� ��������� ������ MSG
INT 21H		
MOV AX,4C01H
;����� �� ��������� � ����� 1
INT 21H		
MSG DB ? This program cannot be run in DOS mode $?
