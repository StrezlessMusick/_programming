#include <idc.idc>
static main()
{
	auto ad,i,j;
	ad=0x401cfe;
	while(ad<=0x401d41)
	{
		ad=NextHead(ad,BADADDR);
//������� ����� ����������
		Message("%10x ",ad);
		i=GetFlags(ad);
		if(i & FF_LABL)
		{
			Message("%s \n",GetTrueName(ad));
			MakeComm(ad,"�����!");	
		} else Message("\n");
	}
}

