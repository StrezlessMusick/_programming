#define FF_COMM 0x00000800L	// Has comment?
				// �����������
#define FF_REF  0x00001000L	// has references?
				// ������������ ������
#define FF_LINE 0x00002000L	// Has next or prev cmt lines ?
				// ������ �������������� �����������
#define FF_NAME 0x00004000L	// Has user-defined name ?
				// ���������������� ����� (���)
#define FF_LABL 0x00008000L	// Has dummy name?
				// ����� (���)
#define FF_FLOW 0x00010000L	// Exec flow from prev instruction?
				// ������������ ����� � ���������� ����������
#define FF_VAR  0x00080000L	// Is byte variable ?
				// ���������� (����� ��� �������)
