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
	PUSH OFFSET 0
	PUSH OFFSET TEXT2
	PUSH OFFSET TEXT1
	PUSH 0
	CALL MessageBoxA@16
	RETN
_TEXT ENDS
END START
