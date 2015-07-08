//-------------------------------------------------------------------------
// �������� ��������� ������������ PC-����������
//-------------------------------------------------------------------------

#include "Board.h"

//����� ������� ������
volatile extern U8 flagn_kn1, flagn_kn2, flagn_kn3, flagn_kn4;

volatile extern U8 DATA_KB; //�������� ���� �� PC-����������
volatile extern U8 flag_rd_kb; // ���� "������ ���� �� PC-����������"

static  U8 J=0;            //����� � ��� ��� (����� ��������� �������)


//������ �������� ���������
void main(void)
{
  CPUinit();         //������������� �������
  timer_init();      //������������� ��������-���������
  irq_pio_init();    // ������������� ������� ����������
  LCDinit_clear();   //��� ������������� � ����� ���

  // ����� �� ��� ��������� ��������
  lcd_pro_data('P', 0);
  lcd_tek_data('C');
  lcd_tek_data('_');
  lcd_tek_data('k');
  lcd_tek_data('l');
  lcd_tek_data('a');
  lcd_tek_data('w');
  lcd_tek_data('_');
  lcd_tek_data('S');
  lcd_tek_data('R');
  lcd_tek_data('A');
  lcd_tek_data('M');

    //������ ��������� �����
    for (;;)
    {

    // ���� ������ ���� �� PC-����������, �� ���������� ��� �����
    if  (flag_rd_kb==1)
           {
           flag_rd_kb = 0; // �������� ���� "������ ���� �� ���������"

           lcd_pro_data(DATA_KB,J); //������������ �������� ����

           J++;
           if (J == 16) J = 64;
           if (J == 80)
              {
              J = 0;
              lcd_clear();  //������� ������ ���
              }

          //�������  3  4  PC-����������
          if (DATA_KB == 0x26) AT91F_PIO_ClearOutput( AT91C_BASE_PIOA, LED4); // ������ �������� 4
          if (DATA_KB == 0x25)   AT91F_PIO_SetOutput( AT91C_BASE_PIOA, LED4); // �������� ��������� 4
          //�������  5  6  PC-����������
          if (DATA_KB == 0x2E) AT91F_PIO_ClearOutput( AT91C_BASE_PIOA, LED3); // ������ �������� 3
          if (DATA_KB == 0x36)   AT91F_PIO_SetOutput( AT91C_BASE_PIOA, LED3); // �������� ��������� 3
          //�������  7  8  PC-����������
          if (DATA_KB == 0x3D) AT91F_PIO_ClearOutput( AT91C_BASE_PIOA, LED2); // ������ �������� 2
          if (DATA_KB == 0x3E)   AT91F_PIO_SetOutput( AT91C_BASE_PIOA, LED2); // �������� ��������� 2
          //�������  9  0  PC-����������
          if (DATA_KB == 0x46) AT91F_PIO_ClearOutput( AT91C_BASE_PIOA, LED1); // ������ �������� 1
          if (DATA_KB == 0x45)   AT91F_PIO_SetOutput( AT91C_BASE_PIOA, LED1); // �������� ��������� 1
          DATA_KB = 0;
          }

      if  (flagn_kn1==1)    // ���������� �� ������ 1
     	    {
            flagn_kn1=0;    //��, �������� ���� �������
            AT91F_PIO_ClearOutput( AT91C_BASE_PIOA, LED4); // ������ �������� 4
            }

     if  (flagn_kn2==1)    // ���������� �� ������ 2
	    {
	    flagn_kn2=0;    //��, �������� ���� �������
            AT91F_PIO_ClearOutput( AT91C_BASE_PIOA, LED3); // ������ �������� 3
            }

     if  (flagn_kn3==1)    // ���������� �� ������ 3
	    {
	    flagn_kn3=0;    //��, �������� ���� �������
            AT91F_PIO_ClearOutput( AT91C_BASE_PIOA, LED2); // ������ �������� 2
            }

     if  (flagn_kn4==1)    // ���������� �� ������ 4
	    {
	    flagn_kn4=0;    //��, �������� ���� �������
            AT91F_PIO_ClearOutput( AT91C_BASE_PIOA, LED1); // ������ �������� 1
            }
    }
}




