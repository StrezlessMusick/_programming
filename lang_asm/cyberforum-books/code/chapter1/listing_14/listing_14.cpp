#include <windows.h>
#include <stdio.h>
HANDLE openf(char * );
HANDLE hf;
IMAGE_DOS_HEADER id;
IMAGE_NT_HEADERS iw; 
//������� ������� 
int main(int argc, char* argv[])
{
	DWORD n;
	int er=0;
	LARGE_INTEGER l;
//�������� ������� ����������
	if(argc<2){printf("No parameters!\n");er=1; goto _exit;};
//������ � ������ - ��� �����
	if((hf=openf(argv[1]))==INVALID_HANDLE_VALUE)
	{
		printf("No file!\n"); 
		er=2; 
		goto _exit;};
//��������� ����� �����
	GetFileSizeEx(hf,&l);
//��������� ��������� DOS
	if(!ReadFile(hf,&id,sizeof(id),&n,NULL))
	{
		printf("Read DOS_HEADER error 1!\n"); 
		er=3; 
		goto _exit;};
	if(n<sizeof(id))
	{
		printf("Read DOS_HEADER error 2!\n"); 
		er=4; 
		goto _exit;};
//��������� ��������� DOS ('MZ')		
	if(id.e_magic!=IMAGE_DOS_SIGNATURE)
	{
		printf("No DOS signature!\n");
		er=5; 
		goto _exit;}
	printf("DOS signature is OK!\n");
	if(id.e_lfanew>l.QuadPart)
	{
		printf("No NT signature!\n");
		er=6;
		goto _exit;};
//� ������ ���������� ���������
	SetFilePointer(hf,id.e_lfanew,NULL,FILE_BEGIN);
//��������� ��������� NT
	if(!ReadFile(hf,&iw,sizeof(iw),&n,NULL))
	{
		printf("Read NT_HEADER error 1!\n"); 
		er=7; 
		goto _exit;};
	if(n<sizeof(iw))
	{
		printf("Read NT_HEADER error 2!\n"); 
		er=8; 
		goto _exit;};
//��������� ��������� NT ('PE')
	if(iw.Signature!=IMAGE_NT_SIGNATURE)
	{
		printf("No NT signature!\n");
		er=9; 
		goto _exit;}
	printf("NT signature is OK!\n");
//������� ���������� �����
_exit:
	CloseHandle(hf);
	return er;
};
//������� ��������� ���� ��� ������
HANDLE openf(char * nf)
{	
	return CreateFile(nf,
		GENERIC_READ,
		FILE_SHARE_WRITE | FILE_SHARE_READ,
		NULL,
		OPEN_EXISTING,
		NULL,
		NULL);
};
