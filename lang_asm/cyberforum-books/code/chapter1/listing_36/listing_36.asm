.586P
.MODEL FLAT,STDCALL
includelib f:\masm32\lib\user32.lib
EXTERN	MessageBoxA@16:NEAR
_DATA SEGMENT
;����� �������� ������ �����
mem1  DD OFFSET l2	
TEXT1 DB 'No problem!',0
TEXT2 DB 'Message',0
_DATA ENDS
_TEXT SEGMENT 
START:
	MOV  EAX,mem1
;��� ��������� ������� ������������ ������ JMP l2
PUSH EAX
RETN
l1:
RETN
l2:
	PUSH OFFSET 0
	PUSH OFFSET TEXT2
	PUSH OFFSET TEXT1
	PUSH 0
	CALL MessageBoxA@16
	RETN
_TEXT ENDS
END START
