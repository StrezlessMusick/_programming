//-------------------------------------------------------------------------
// �������� ��������� ������������ ������� ��������� ������� RTT
//-------------------------------------------------------------------------

#include "Board.h"
#include "rtt.h"

//����� ������� ������
volatile extern U8 flagn_kn1, flagn_kn2, flagn_kn3, flagn_kn4;

static U8 led1_old_state=0;  //-----------------------------------
static U8 led2_old_state=0;  // ���������� ��������� �����������
static U8 led3_old_state=0;  //
static U8 led4_old_state=0;  //------------------------------------

static U32 period_RTTC  = 1500; //��� �������� ������� ������������ ������� RTT

//������ �������� ���������
void main(void)
{
  CPUinit();         //������������� �������
  timer_init();      //������������� ��������-���������
  RTTC_init_res (period_RTTC);   //�������������  � ������� RTT
  LCDinit_clear();   //��� ������������� � ����� ���

  // ����� �� ��� ��������� ��������
  lcd_pro_data('R', 0);
  lcd_tek_data('T');
  lcd_tek_data('T');
  lcd_tek_data('_');
  lcd_tek_data('F');
  lcd_tek_data('L');
  lcd_tek_data('A');
  lcd_tek_data('S');
  lcd_tek_data('H');

  RTTC_Time_pres_ind (period_RTTC); //��������� �������� �������� ������� ������� RTT

    //������ ��������� �����
    for (;;)
    {
    delay(50000);
    RTTC_Time_ind (); //�������� �������� �������� ������� RTT


      if  (flagn_kn1==1)    // ���������� �� ������ 1
     	    {
            flagn_kn1=0;    //��, �������� ���� �������

            period_RTTC  = period_RTTC  + 1000;
            if (period_RTTC > 65000)   period_RTTC  = 1500;
            RTTC_Time_pres_ind (period_RTTC); //��������� �������� �������� ������� ������� RTT
            RTTC_init (period_RTTC);   //�������������  RTT

            //����� ��������� ������ ���������� LED1
            if (led1_old_state==OFF)
                     {
                     AT91F_PIO_ClearOutput( AT91C_BASE_PIOA, LED1); // ������ �������� 1
                     led1_old_state=ON;
                     }
            else
                     {
                     AT91F_PIO_SetOutput( AT91C_BASE_PIOA, LED1); // �������� ��������� 1
                     led1_old_state=OFF;
                     }
            }

     if  (flagn_kn2==1)    // ���������� �� ������ 2
	    {
	    flagn_kn2=0;    //��, �������� ���� �������

            period_RTTC  = period_RTTC  - 1000;
            if (period_RTTC < 1500)   period_RTTC  = 65000;
            RTTC_Time_pres_ind (period_RTTC); //��������� �������� �������� ������� ������� RTT
            RTTC_init (period_RTTC);   //�������������  RTT

           //����� ��������� ������ ���������� LED2
           if (led2_old_state==OFF)
                     {
                     AT91F_PIO_ClearOutput( AT91C_BASE_PIOA, LED2); // ������ �������� 2
                     led2_old_state=ON;
                     }
            else
                     {
                     AT91F_PIO_SetOutput( AT91C_BASE_PIOA, LED2); // �������� ��������� 2
                     led2_old_state=OFF;
                     }
           }

     if  (flagn_kn3==1)    // ���������� �� ������ 3
	    {
	    flagn_kn3=0;    //��, �������� ���� �������

           //����� ��������� ������ ���������� LED3
           if (led3_old_state==OFF)
                     {
                     AT91F_PIO_ClearOutput( AT91C_BASE_PIOA, LED3); // ������ �������� 3
                     led3_old_state=ON;
                     }
            else
                     {
                     AT91F_PIO_SetOutput( AT91C_BASE_PIOA, LED3); // �������� ��������� 3
                     led3_old_state=OFF;
                     }

            period_RTTC = 0x8000;
            RTTC_init (period_RTTC);   //�������������  RTT ���������, ����� ������� 1 ��
            RTTC_Time_pres_ind (period_RTTC); //��������� �������� �������� ������� ������� RTT
            }

     if  (flagn_kn4==1)    // ���������� �� ������ 4
	    {
	    flagn_kn4=0;    //��, �������� ���� �������

            //����� ��������� ������ ���������� LED4
           if (led4_old_state==OFF)
                     {
                     AT91F_PIO_ClearOutput( AT91C_BASE_PIOA, LED4); // ������ �������� 3
                     led4_old_state=ON;
                     }
            else
                     {
                     AT91F_PIO_SetOutput( AT91C_BASE_PIOA, LED4); // �������� ��������� 3
                     led4_old_state=OFF;
                     }

            period_RTTC = 0x8000;
            RTTC_init_res (period_RTTC);   //�������������  � ������� RTT
                                      //���������, ����� ������� 1 ��
            RTTC_Time_pres_ind (period_RTTC); //��������� �������� �������� ������� ������� RTT
            }
    }
}




