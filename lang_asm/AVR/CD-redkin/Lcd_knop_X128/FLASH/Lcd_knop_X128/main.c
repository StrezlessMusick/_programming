//-------------------------------------------------------------------------
// �������� ���������    (AT91SAM7X128)
//-------------------------------------------------------------------------

#include "Board.h"

//����� ������� ������
volatile extern U8 flagn_kn1, flagn_kn2, flagn_kn3, flagn_kn4, flagn_kn5;

static U8 led1_old_state=0;  //-----------------------------------
static U8 led2_old_state=0;  // ���������� ��������� �����������
static U8 led3_old_state=0;  //
static U8 led4_old_state=0;  //-----------------------------------

//������ �������� ���������
void main(void)
{
  CPUinit();         //������������� �������
  timer_init();      //������������� ��������-���������
  LCDinit_clear();   //��� ������������� � ����� ���

  // ����� �� ��� ��������� ��������
  lcd_pro_data('L', 0);
  lcd_tek_data('c');
  lcd_tek_data('d');
  lcd_tek_data('_');
  lcd_tek_data('k');
  lcd_tek_data('n');
  lcd_tek_data('o');
  lcd_tek_data('p');
  lcd_tek_data('_');
  lcd_tek_data('X');
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
                     AT91F_PIO_ClearOutput( AT91C_BASE_PIOB, LED1); // ������ �������� 1
                     led1_old_state=ON;
                     }
            else
                     {
                     AT91F_PIO_SetOutput( AT91C_BASE_PIOB, LED1); // �������� ��������� 1
                     led1_old_state=OFF;
                     }

            // ����� �� ��� �����  "Privet!"
            lcd_pro_data('P',64);
            lcd_tek_data('r');
            lcd_tek_data('i');
            lcd_tek_data('v');
            lcd_tek_data('e');
            lcd_tek_data('t');
            lcd_tek_data('!');
            }

     if  (flagn_kn2==1)    // ���������� �� ������ 2
	    {
	    flagn_kn2=0;    //��, �������� ���� �������

           //����� ��������� ������ ���������� LED2
           if (led2_old_state==OFF)
                     {
                     AT91F_PIO_ClearOutput( AT91C_BASE_PIOB, LED2); // ������ �������� 2
                     led2_old_state=ON;
                     }
            else
                     {
                     AT91F_PIO_SetOutput( AT91C_BASE_PIOB, LED2); // �������� ��������� 2
                     led2_old_state=OFF;
                     }

           // ����� �� ��� �������� - �����  "������!"
           lcd_pro_data(rus_P, 72);
           lcd_tek_data('p');
           lcd_tek_data(rus_i);
           lcd_tek_data(rus_v);
           lcd_tek_data('e');
           lcd_tek_data(rus_t);
           lcd_tek_data('!');
           }

     if  (flagn_kn3==1)    // ���������� �� ������ 3
	    {
	    flagn_kn3=0;    //��, �������� ���� �������

           //����� ��������� ������ ���������� LED3
           if (led3_old_state==OFF)
                     {
                     AT91F_PIO_ClearOutput( AT91C_BASE_PIOB, LED3); // ������ �������� 3
                     led3_old_state=ON;
                     }
            else
                     {
                     AT91F_PIO_SetOutput( AT91C_BASE_PIOB, LED3); // �������� ��������� 3
                     led3_old_state=OFF;
                     }

            lcd_clear();          //������� ���
            }

     if  (flagn_kn4==1)    // ���������� �� ������ 4
	    {
	    flagn_kn4=0;    //��, �������� ���� �������

           //����� ��������� ������ ���������� LED4
           if (led4_old_state==OFF)
                     {
                     AT91F_PIO_ClearOutput( AT91C_BASE_PIOB, LED4); // ������ �������� 4
                     led4_old_state=ON;
                     }
            else
                     {
                     AT91F_PIO_SetOutput( AT91C_BASE_PIOB, LED4); // �������� ��������� 4
                     led4_old_state=OFF;
                     }
            // ����� �� ��� �����  "Privet!"
            lcd_pro_data('P',72);
            lcd_tek_data('r');
            lcd_tek_data('i');
            lcd_tek_data('v');
            lcd_tek_data('e');
            lcd_tek_data('t');
            lcd_tek_data('!');
            }

       if  (flagn_kn5==1)    // ���������� �� ������ 5
	    {
	    flagn_kn5=0;    //��, �������� ���� �������

           //����� ��������� ������ ���������� LED4
           if (led4_old_state==OFF)
                     {
                     AT91F_PIO_ClearOutput( AT91C_BASE_PIOB, LED4); // ������ �������� 4
                     led4_old_state=ON;
                     }
            else
                     {
                     AT91F_PIO_SetOutput( AT91C_BASE_PIOB, LED4); // �������� ��������� 4
                     led4_old_state=OFF;
                     }
            lcd_init();           //������������� ���
            }
      }
}




