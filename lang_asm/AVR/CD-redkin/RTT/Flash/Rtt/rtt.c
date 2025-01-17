//----------------------------------------------------------------------------
// �� ������������ ������� ��������� ������� RTT
//----------------------------------------------------------------------------

#include "Board.h"
#include "rtt.h"

U8 r1000000=0;//-----------------------------------
U8 r100000=0; //
U8 r10000=0;  //
U8 r1000=0;   //  ������� ����������� �����
U8 r100=0;    //
U8 r10=0;     //
U8 r1=0;      //-----------------------------------
U32 val=0;    //���������� ������ ������� � ������������ RTT

// ������� ������������� � �������� RTT
void RTTC_init_res (U32 per_RTTC)
{
        //���������������� PMC ��� ������������ RTT
        AT91F_RTTC_CfgPMC();
        //������� RTT
        AT91C_BASE_RTTC->RTTC_RTMR = AT91C_RTTC_RTTRST ;
        //������� �������� ������������ RTT
        AT91C_BASE_RTTC->RTTC_RTMR =  (AT91C_RTTC_RTPRES & per_RTTC);
}

// ������� ������������� RTT
void RTTC_init (U32 per_RTTC)
{
        //������� �������� ������������ RTT
        AT91C_BASE_RTTC->RTTC_RTMR =  (AT91C_RTTC_RTPRES & per_RTTC);
}

//������� ��������� �������� �������� ������� RTT
void RTTC_Time_ind (void)
{
  val = AT91C_BASE_RTTC->RTTC_RTVR;  //������ �������� ���� ������� RTT ��� ���������
  r1000000 = val / 1000000; //------------------------------------------
  val = val % 1000000;      //
  r100000 = val / 100000;   //      ��������������
  val = val % 100000;       //  �������� ���� ������� RTT
  r10000 = val / 10000;     //   � ���������� �������������
  val = val % 10000;        //
  r1000 = val / 1000;       //
  val = val % 1000;         //
  r100 = val / 100;         //
  val = val % 100;          //
  r10 = val / 10;           //
  r1 = val % 10;            //-----------------------------------------
  lcd_pro_data(r1000000,64);//-----------------------------------------
  lcd_tek_data(r100000);    //        ���������
  lcd_tek_data(r10000);     //  �������� ���� ������� RTT
  lcd_tek_data(r1000);      //  � ���������� ����
  lcd_tek_data(r100);       //
  lcd_tek_data(r10);        //
  lcd_tek_data(r1);         //-----------------------------------------
}

//������� ��������� �������� �������� ������� ������� RTT
void RTTC_Time_pres_ind (U32 per_RTTC)
{
  val = per_RTTC;
  r1000000 = val / 1000000; //------------------------------------------
  val = val % 1000000;      //
  r100000 = val / 100000;   //      ��������������
  val = val % 100000;       //  �������� ���� ������� ������� RTT
  r10000 = val / 10000;     //   � ���������� �������������
  val = val % 10000;        //
  r1000 = val / 1000;       //
  val = val % 1000;         //
  r100 = val / 100;         //
  val = val % 100;          //
  r10 = val / 10;           //
  r1 = val % 10;            //-----------------------------------------
  lcd_pro_data(r1000000,72);//-----------------------------------------
  lcd_tek_data(r100000);    //        ���������
  lcd_tek_data(r10000);     //  �������� ���� ������� ������� RTT
  lcd_tek_data(r1000);      //  � ���������� ����
  lcd_tek_data(r100);       //
  lcd_tek_data(r10);        //
  lcd_tek_data(r1);         //-----------------------------------------
}
