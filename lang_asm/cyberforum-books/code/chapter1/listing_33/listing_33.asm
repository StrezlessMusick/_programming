.586P
.MODEL FLAT,STDCALL
includelib f:\masm32\lib\user32.lib
EXTERN	MessageBoxA@16:NEAR
;������� ������
_DATA SEGMENT
TEXT1 DB 'No problem!',0
TEXT2 DB 'Message',0
_DATA ENDS
;������� ����
_TEXT SEGMENT 
START:
	MOV  EBX,OFFSET l1
	PUSH OFFSET START
	PUSH OFFSET 0
	PUSH OFFSET TEXT2
	PUSH OFFSET TEXT1
	PUSH 0
	CALL MessageBoxA@16
	POP  EDX
	ADD  EDX,l1-START
	CALL EDX
	RETN
	DB 50
l1:
        RETN
_TEXT ENDS
END START
