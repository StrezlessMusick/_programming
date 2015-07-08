//-------------------------------------------------------------------------
// �������� ��������� ������������ USART
//-------------------------------------------------------------------------

#include "Board.h"
#include "usart.h"

//����� ������� ������
volatile extern U8 flagn_kn1, flagn_kn2, flagn_kn3, flagn_kn4;

static U8 led1_old_state=0;  //-----------------------------------
static U8 led2_old_state=0;  // ���������� ��������� �����������
static U8 led3_old_state=0;  //
static U8 led4_old_state=0;  //-----------------------------------

U8 ch0 = '!';     //���������� ��� �������� � USART
char stroka[] = "ABCDEFGHIJKL"; //���������� ������ ��� �������� � USART

//������ �������� ���������
void main(void)
{
  CPUinit();         //������������� �������
  timer_init();      //������������� ��������-���������
  LCDinit_clear();   //��� ������������� � ����� ���
  InitUSART0(115200);    //������������� USART0 �� ��������� ������ 115200 ����/�

  // ����� �� ��� ��������� ��������
  lcd_pro_data('U', 0);
  lcd_tek_data('S');
  lcd_tek_data('A');
  lcd_tek_data('R');
  lcd_tek_data('T');
  lcd_tek_data('_');
  lcd_tek_data('S');
  lcd_tek_data('R');
  lcd_tek_data('A');
  lcd_tek_data('M');

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
            //����� �������� ��� �������� � USART
            ch0++;
            if (ch0 == 'z')  ch0 = '!';
            lcd_pro_data(ch0, 64); //��������� �������, ����������� ��������
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
            write_char_USART0(ch0); //�������� ������� ����� USART0
            lcd_pro_data(ch0, 66); //��������� ����������� �������
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

             write_str_USART0(stroka); //�������� � USART0 ������ ������
            //��������� ���������� ������
            U8 i = 0x0;
            while(stroka[i] != '\0')
                     {
                   lcd_pro_data(stroka[i], 68+i); //��������� ����������� ������� ������
                   i++;
                     }
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




