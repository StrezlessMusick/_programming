//-------------------------------------------------------------------------
// �������� ��������� ������������ PWM
//-------------------------------------------------------------------------

#include "Board.h"
#include "lib_pwm.h"

static U16 PERIOD_SIZE = 10000;  //��� �������� ������� PWM
static U16 DUTY_SIZE = 2000; //��� �������� ���� �������� (�������� �����) PWM
static U8 DIVID = 48;      //��� �������� �������� PWM

//����� ������� ������
volatile extern U8 flagn_kn1, flagn_kn2, flagn_kn3, flagn_kn4;

static U8 led1_old_state=0;  //-----------------------------------
static U8 led2_old_state=0;  // ���������� ��������� �����������
static U8 led3_old_state=0;  //
static U8 led4_old_state=0;  //-----------------------------------

//������ �������� ���������
void main(void)
{
  CPUinit();         //������������� �������
  timer_init();      //������������� ��������-���������
  AT91F_PWM_Open(MCK_toPWM, DIVID);   //������������� PWM
  AT91F_Set_PWM_Channel0(PERIOD_SIZE, DUTY_SIZE); //��������� ������ 0 PWM
  LCDinit_clear();   //��� ������������� � ����� ���
  Ind_DIVID(DIVID);//��������� �������� �������� ������������� PWM
  Ind_PERIOD(PERIOD_SIZE); //��������� �������� ������� PWM
  Ind_DUTY(DUTY_SIZE);   //��������� �������� �������� ����� PWM

  // ����� �� ��� ��������� ��������
  lcd_pro_data('P', 0);
  lcd_tek_data('W');
  lcd_tek_data('M');
  lcd_tek_data('_');
  lcd_tek_data('F');
  lcd_tek_data('L');
  lcd_tek_data('A');
  lcd_tek_data('S');
  lcd_tek_data('H');

    //������ ��������� �����
    for (;;)
    {
      if  (flagn_kn1==1)    // ���������� �� ������ 1
     	    {
            flagn_kn1=0;    //��, �������� ���� �������

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
            DIVID = DIVID + 1;     //��������� �������� ������������� PWM
            if (DIVID == 255)  DIVID = 1;
            AT91F_PWM_Open(MCK_toPWM, DIVID);   //������������� PWM
            AT91F_Set_PWM_Channel0(PERIOD_SIZE, DUTY_SIZE); //��������� ������ 0 PWM
            Ind_DIVID(DIVID);//��������� �������� �������� ������������� PWM
           }

     if  (flagn_kn2==1)    // ���������� �� ������ 2
	    {
	    flagn_kn2=0;    //��, �������� ���� �������

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
            PERIOD_SIZE = PERIOD_SIZE + 1000;     //��������� ������� PWM
            if (PERIOD_SIZE > 65000)  PERIOD_SIZE = 1000;
            AT91F_Set_PWM_Channel0_period(PERIOD_SIZE); //���������� ��������� ������� PWM
            Ind_PERIOD(PERIOD_SIZE); //��������� �������� ������� PWM
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
            DUTY_SIZE = DUTY_SIZE + 100;     //��������� �������� ����� PWM
            if (DUTY_SIZE > 20000)  DUTY_SIZE = 100;
            AT91F_Set_PWM_Channel0_duty(DUTY_SIZE); //���������� ��������� �������� ����� PWM
            Ind_DUTY(DUTY_SIZE);   //��������� �������� �������� ����� PWM
            }

     if  (flagn_kn4==1)    // ���������� �� ������ 4
	    {
	    flagn_kn4=0;    //��, �������� ���� �������

           //����� ��������� ������ ���������� LED4
           if (led4_old_state==OFF)
                     {
                     AT91F_PIO_ClearOutput( AT91C_BASE_PIOA, LED4); // ������ �������� 4
                     led4_old_state=ON;
                     }
            else
                     {
                     AT91F_PIO_SetOutput( AT91C_BASE_PIOA, LED4); // �������� ��������� 4
                     led4_old_state=OFF;
                     }
            lcd_clear();          //������� ���
            }
    }
}




