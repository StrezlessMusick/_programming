.586P
.MODEL FLAT, stdcall
;���������
STD_OUTPUT_HANDLE equ -11
INVALID_HANDLE_VALUE  equ -1
;��������� ������� ��������
EXTERN  GetStdHandle@4:NEAR
EXTERN  WriteConsoleA@20:NEAR
EXTERN  ExitProcess@4:NEAR
;��������� ������������ ��� ����������� ���������
includelib f:\masm32\lib\user32.lib
includelib f:\masm32\lib\kernel32.lib
;------------------------------------------------
;������� ������
_DATA SEGMENT 
BUF DB  "������ ��� ������",0 
	LENS DWORD ? ;���������� ���������� ��������
HANDL DWORD ?
_DATA ENDS
;������� ����
_TEXT SEGMENT 
START:
;�������� HANDLE ������
	PUSH STD_OUTPUT_HANDLE
	CALL GetStdHandle@4
	CMP EAX,INVALID_HANDLE_VALUE
	JNE _EX
	MOV HANDL,EAX
;����� ������
	PUSH 0
	PUSH OFFSET LENS
	PUSH 17
	PUSH OFFSET BUF
	PUSH HANDL
	CALL WriteConsoleA@20
_EX:
	PUSH 0
	CALL ExitProcess@4
_TEXT ENDS
END START
