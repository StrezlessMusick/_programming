.586P
.MODEL FLAT,STDCALL
PROCESS_VM_OPERATION	=	0008H  
PROCESS_VM_WRITE	=	0020H  
PROCESS_VM_OW	=     PROCESS_VM_OPERATION OR PROCESS_VM_WRITE
PAGE_WRITECOPY		= 8
PAGE_EXECUTE		= 10h
includelib f:\masm32\lib\user32.lib
includelib f:\masm32\lib\kernel32.lib
;������������� �������
EXTERN OpenProcess@12:NEAR
EXTERN FlushInstructionCache@12:NEAR
EXTERN VirtualProtectEx@20:NEAR
EXTERN GetCurrentProcessId@0:NEAR
;------------------------------------------------
_DATA SEGMENT
HANDLE  DD ?
NN      DD ?
_DATA ENDS
_TEXT SEGMENT 
START:
	CALL GetCurrentProcessId@0 	
;������� ������� �������
	PUSH EAX
	PUSH 1
	PUSH PROCESS_VM_OW
	CALL OpenProcess@12
;��������� ����������� ����� �� ������ RETE
	MOV  HANDLE,EAX
	PUSH OFFSET NN
	PUSH PAGE_WRITECOPY
	PUSH 1
	PUSH OFFSET RETE 
	PUSH EAX
	CALL VirtualProtectEx@20
;�������� ���� �� ������ RETE
	LEA  EAX,RETE
	MOV  BYTE PTR [EAX],0C3H	
;���������� ����� �������������� �������
	PUSH OFFSET NN
	PUSH PAGE_EXECUTE
	PUSH 1
	PUSH OFFSET RETE 
	PUSH HANDLE
	CALL VirtualProtectEx@20
;���������� ���
	PUSH 1
	PUSH OFFSET RETE
	PUSH HANDLE
	CALL FlushInstructionCache@12
RETE:
	JMP  RETE		
	RETN
_TEXT ENDS
END START
