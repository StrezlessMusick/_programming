#define FUNC_NORET	0x00000001L	// function doesn't return
			//�� ���������� ���������� �������� ret
#define FUNC_FAR	0x00000002L	// far function
			//������� ���������� ���������� ����������� retf
#define FUNC_LIB	0x00000004L	// library function
			//������������ �������
#define FUNC_STATIC	0x00000008L	// static function
			//����������� �������
#define FUNC_FRAME	0x00000010L	// function uses frame pointer (BP)
			//������� ���������� ��� ������� EBP ��� ��������� 
			//�� ��������� ���������� � ���������	
#define FUNC_USERFAR	0x00000020L	// user has specified far-ness
			//���������� ������������� ��� ������� (far)
#define FUNC_HIDDEN	0x00000040L	// a hidden function
			//������� (���������) �������	
#define FUNC_THUNK	0x00000080L	// thunk (jump) function
			//������� � ����������, ���������� ������ 
			//���������� jmp
#define FUNC_BOTTOMBP	0x00000100L	// BP points to the bottom 
//of the stack frame
//������� EBP ��������� �� ����
//��������� ������			
