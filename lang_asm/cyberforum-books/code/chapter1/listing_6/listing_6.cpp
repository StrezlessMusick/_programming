#include <windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	char cname[]="Class";
	char title[]="������� ������� ����������";
	MSG msg;

	//��������� ��� ����������� ������ ����
	WNDCLASS wc;
	wc.style		=0;
	wc.lpfnWndProc		=(WNDPROC)WndProc;
	wc.cbClsExtra		=0;
	wc.cbWndExtra		=0;
	wc.hInstance		=hInstance;
	wc.hIcon		=LoadIcon(hInstance, (LPCTSTR)IDI_APPLICATION);
	wc.hCursor		=LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground	=(HBRUSH)(COLOR_WINDOW+1);
	wc.lpszMenuName	=0;
	wc.lpszClassName	=cname;
	//������������ �����
	if(!RegisterClass(&wc)) return 0;
	//������� ����
	HWND  hWnd = CreateWindow(
		cname, //�����
		title, //���������
		WS_OVERLAPPEDWINDOW,  //����� ���� 
		0,   //���������� X
		0,   //���������� Y
		500, //������ ����
		300, //������ ���� 
		NULL, //���������� ����-��������
		NULL, //���������� ���� 
		hInstance,  //������������� ����������
		NULL);   //��������� �� ���������, ���������� 
				//�� ��������� WM_CREATE
	//��������, ��������� �� ����
	if (!hWnd)    return 0;
	//�������� ����
	ShowWindow(hWnd, nCmdShow);
	//�������� ���������� ����
	UpdateWindow(hWnd);

	//���� ��������� ���������
	while (GetMessage(&msg, NULL, 0, 0)) 
	{
	//������������� ���� ����������� ������ � ASCII-����
		TranslateMessage(&msg);
	//����������� ��������� ��������� ����
		DispatchMessage(&msg);
	}

	return 0;
};

//��������� ����
LRESULT CALLBACK WndProc(HWND hWnd, 
UINT message, 
WPARAM wParam, 
LPARAM lParam)
{
	switch(message)
	{
//��������� ��� �������� ����
	case WM_CREATE:
		break;
//��������� ��� �������� ����
	case WM_DESTROY:
//���������� ���  ������ �� ����� ��������� ���������
		PostQuitMessage(0);
		break;
//��������� ���������� ��� ����������� ����
	case WM_PAINT:
		break;
//������� �� ������������ ���������
		default:
	return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
