#include <windows.h>
char * s="Example of console program.\n\0";
char buf[100];
DWORD d;
void main()
{
//���������� �������, ���� ��� ������������
	FreeConsole();
//������� �������
	AllocConsole();
//�������� ���������� ������ �� �������
	HANDLE ho=GetStdHandle(STD_OUTPUT_HANDLE);	
//�������� ���������� ����� � �������
	HANDLE hi=GetStdHandle(STD_INPUT_HANDLE);	
//������� ������ �� �������
	WriteConsole(ho,s,lstrlen(s),&d,NULL);
//������������ ReadConsole ��� ��������� ������ �������
	ReadConsole(hi,(void*)buf,100,&d,NULL);
//������� �����������
	CloseHandle(ho);
	CloseHandle(hi);
//���������� �������
	FreeConsole();
}
