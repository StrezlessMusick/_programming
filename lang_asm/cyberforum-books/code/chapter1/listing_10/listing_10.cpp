//����������� ������
#include <windows.h>
MSG msg;

int DWndProc(HWND,UINT,WPARAM,LPARAM);

__stdcall WinMain(HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nCmdShow
)
{
//�� ��������� ���������� ����
	HWND hdlg=CreateDialog(hInstance,"DIALOG",NULL,(DLGPROC)DWndProc);
//���� ��������� ���������
	while (GetMessage(&msg, NULL, 0, 0)) 
	{
		IsDialogMessage(hdlg,&msg);
	}

//������� ����������
	ExitProcess(0);
};
//������� ������������ ����
int DWndProc(HWND hwndDlg,UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
	switch(uMsg)
	{
//���������, ���������� ��� �������� ����������� ����
	case WM_INITDIALOG:
		break;
//���������, ���������� ��� ������� ������� ����
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_CLOSE:
		DestroyWindow(hwndDlg);
		return TRUE;
//��������� �� ��������� ����������
	case WM_COMMAND:
		break;
	};

		return FALSE;
	};
