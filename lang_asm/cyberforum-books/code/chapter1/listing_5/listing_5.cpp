#include <windows.h>

BOOL WINAPI handler(DWORD);
void inputcons();
void print(char *);

HANDLE h1,h2;
char * s1 = "Error input!\n";
char s2[35];
char * s4 = "CTRL+C\n";
char * s5 = "CTRL+BREAK\n";
char * s6 = "CLOSE\n";
char * s7 = "LOGOFF\n";
char * s8 = "SHUTDOWN\n";
char * s9 = "CTRL\n";
char * s10="ALT\n";
char * s11="SHIFT\n";
char * s12=" \n";
char * s13="Code %d \n";
char * s14="CAPSLOCK \n";
char * s15="NUMLOCK \n";
char * s16="SCROLLOCK \n";
char * s17="Enhanced key (virtual code) %d \n";
char * s18="Function key (virtual code) %d \n";
char * s19="Left mouse button\n";
char * s20="Right mouse button\n";
char * s21="Double click\n";
char * s22="Wheel was rolled\n";
char * s23="Character '%c' \n";
char * s24="Location of cursor x=%d y=%d\n";

void main()
{
//������������� �������
	FreeConsole();
	AllocConsole();
//�������� ���������� ������
	h1=GetStdHandle(STD_OUTPUT_HANDLE);
//�������� ���������� �����
	h2=GetStdHandle(STD_INPUT_HANDLE);
//���������� ���������� �������
	SetConsoleCtrlHandler(handler,TRUE);
//������� ������� � ������ ��������� ���������
	inputcons();
//������� ����������
	SetConsoleCtrlHandler(handler,FALSE);
//������� �����������
	CloseHandle(h1); CloseHandle(h2);
//���������� �������
	FreeConsole();
//����� �� ���������
	ExitProcess(0);
};

//���������� �������
BOOL WINAPI handler(DWORD ct)
{
//������� CTRL+C?
	if(ct==CTRL_C_EVENT) print(s4);
//������� CTRL+BREAK?
	if(ct==CTRL_BREAK_EVENT) print(s5);
//�������� �������?
	if(ct==CTRL_CLOSE_EVENT) 
	{
		print(s6);
		Sleep(2000);
		ExitProcess(0);
	};
//���������� ������?
	if(ct==CTRL_LOGOFF_EVENT) 
	{
		print(s7);
		Sleep(2000);
		ExitProcess(0);
	};
//���������� ������?
	if(ct==CTRL_SHUTDOWN_EVENT) 
	{
		print(s8);
		Sleep(2000);
		ExitProcess(0);
	};
	return TRUE;
};
//������� � ������ ��������� ��������� �������
void inputcons()
{
	DWORD n;
	INPUT_RECORD ir;
	while(ReadConsoleInput(h2,&ir,1,&n))
	{
//����� ��������� ������� ����
		if(ir.EventType==MOUSE_EVENT)
		{
//������� ������
			if(ir.Event.MouseEvent.dwEventFlags==DOUBLE_CLICK)
				print(s21);
//�������� ���� �� �������
			if(ir.Event.MouseEvent.dwEventFlags==MOUSE_MOVED)
			{
				wsprintf(s2,s24,ir.Event.MouseEvent.dwMousePosition.X,
					ir.Event.MouseEvent.dwMousePosition.Y);
				print(s2);
			};
//�������� ����
			if(ir.Event.MouseEvent.dwEventFlags==MOUSE_WHEELED)
				print(s22);
//����� ������
if(ir.Event.MouseEvent.dwButtonState==FROM_LEFT_1ST_BUTTON_PRESSED)
		print(s19);
//������ ������
			if(ir.Event.MouseEvent.dwButtonState==RIGHTMOST_BUTTON_PRESSED)
				print(s20);
		};
		if(ir.EventType==KEY_EVENT)
		{
			if(ir.Event.KeyEvent.bKeyDown!=1)continue;
//����������� ����������
			if(ir.Event.KeyEvent.dwControlKeyState==ENHANCED_KEY)
			{
				wsprintf(s2,s17,ir.Event.KeyEvent.wVirtualKeyCode);
				print(s2);
			};
//������� CAPS LOCK?
			if(ir.Event.KeyEvent.dwControlKeyState==CAPSLOCK_ON)
				print(s14);
//����� ALT?
			if(ir.Event.KeyEvent.dwControlKeyState==LEFT_ALT_PRESSED)
				print(s10);
//������ ALT?
			if(ir.Event.KeyEvent.dwControlKeyState==RIGHT_ALT_PRESSED)
				print(s10);
//����� CTRL?
			if(ir.Event.KeyEvent.dwControlKeyState==LEFT_CTRL_PRESSED)
				print(s9);
//������ CTRL?
			if(ir.Event.KeyEvent.dwControlKeyState==RIGHT_CTRL_PRESSED)
				print(s9);
//������� SHIFT?
			if(ir.Event.KeyEvent.dwControlKeyState==SHIFT_PRESSED)
				print(s11);
//������� NUM LOCK
			if(ir.Event.KeyEvent.dwControlKeyState==NUMLOCK_ON)
				print(s15);
//������� SCROLL LOCK
			if(ir.Event.KeyEvent.dwControlKeyState==SCROLLLOCK_ON)
				print(s16);
//��������� ������� ������
			if(ir.Event.KeyEvent.uChar.AsciiChar>=32)
			{
				wsprintf(s2,s23,ir.Event.KeyEvent.uChar.AsciiChar);
				print(s2);
			}else
			{
				if(ir.Event.KeyEvent.uChar.AsciiChar>0)
				{
//����� ������� � ����� >0 � <32
					wsprintf(s2,s13,ir.Event.KeyEvent.uChar.AsciiChar);
					print(s2);
				}else
				{
//������� ��� ������� ���������������
					wsprintf(s2,s18,ir.Event.KeyEvent.wVirtualKeyCode);
					print(s2);
				};
			};
		};
	};
//��������� �� ������
	print(s1);
	Sleep(5000);
};
//������� ������ �� �������
void print(char *s)
{
	DWORD n;
	WriteConsole(h1,s,lstrlen(s),&n,NULL);
};
