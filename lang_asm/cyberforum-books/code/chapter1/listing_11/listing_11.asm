.586P
.MODEL FLAT,STDCALL
TEXT SEGMENT 
START:
;����� �����
	CALL PR1
	LEA  EAX,PR1
;��������� �����
	CALL EAX
	PUSH OFFSET L1
;����� �������� � �����
	JMP  EAX
L1:	
	PUSH OFFSET L2
	PUSH EAX
;������ �� ������� ����� ��� ��� ����� ���������,
;� ��������� � ����� ����� ����� �������� �� ���������
	RETN ;����� ��� ������ RET
L2:	
	RETN   
PR1 PROC
	RETN	
PR1 ENDP  
TEXT ENDS
END START
