//------------------------------------------------------------------------
//��������� � ����������� �� ������������ TWI
//------------------------------------------------------------------------

#define AT91C_TWI_CLOCK 	8000

//���������� ������� ������������� TWI
extern void AT91F_TWI_Open(void);

//���������� ������� ������ ����� ������ � ������� ���������� TWI
extern int AT91F_TWI_WriteByte (const AT91PS_TWI,int, int, char *, int);

//���������� ������� ������ ����� ������ �� �������� ���������� TWI
extern int AT91F_TWI_ReadByte  (const AT91PS_TWI,int, int, char *, int );

//���������� ������� ������������� ����������� ������ ��������
//� ��� ��� � ��� ���������
void Preobr_ind_int_addr(int);
