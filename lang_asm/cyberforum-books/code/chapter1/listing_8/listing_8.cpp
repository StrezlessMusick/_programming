
//����������� ������
#include <windows.h>

int DWndProc(HWND,UINT,WPARAM,LPARAM);

__stdcall WinMain(HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nCmdShow
)
{
//������� ����������� ���������� ����
DialogBoxParam(hInstance,"DIALOG",NULL,(DLGPROC)DWndProc,0);
//������� ����������
ExitProcess(0);
};
//������� ��������� ��������� ���������� ����
int DWndProc(HWND hwndDlg,UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
	switch(uMsg)
	{
//���������, ���������� ��� �������� ����������� ����
	case WM_INITDIALOG:
		break;
//���������, ���������� ��� ������� ������� ����
	case WM_CLOSE:
		EndDialog(hwndDlg,0);
		return TRUE;
//��������� �� ��������� ����������
	case WM_COMMAND:
		break;
	};
		return FALSE;
	};
