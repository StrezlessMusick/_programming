#include <idc.idc>
static main()
{
	auto ad,i,j;
	ad=0x401000;
	while(ad<=0x401042)
	{
//�������� ����������� � ����������������� ����
		OpHex(ad,-1);
//������� ����� ����������
		Message("%10x ",ad);
//�������� ���� ���������
		i=GetOpType(ad,0);
		j=GetOpType(ad,1);
//������� ��� ����������
		Message("%s ",GetMnem(ad));
		if(i>0)
		{
//������� ������ ������� (���� �� ����)
			Message("%s",GetOpnd(ad,0));
			if(j>0)
			{
//������� ������ ������� (���� �� ����)
				Message(",%s \n",GetOpnd(ad,1));
			}else 
				Message("\n");
		}else 
			Message("\n");
//������� � ������ ��������� ����������
		ad=NextHead(ad,BADADDR);
	}
}
