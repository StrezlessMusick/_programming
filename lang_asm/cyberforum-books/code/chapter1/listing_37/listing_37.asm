.586P
.MODEL FLAT,STDCALL
includelib f:\masm32\lib\user32.lib
EXTERN MessageBoxA@16:NEAR
;------------------------------------------------
_DATA SEGMENT
TEXT1 DB '� � �����!',0
TEXT2 DB '��������� �� �����',0
_DATA ENDS
_TEXT SEGMENT 
START:
;������� ���������
CALL PROC1
RETN
PROC1 PROC
PUSH 0
PUSH OFFSET TEXT2
PUSH OFFSET TEXT1
PUSH 0
CALL MessageBoxA@16 
RETN
PROC1 ENDP
_TEXT ENDS
END START
