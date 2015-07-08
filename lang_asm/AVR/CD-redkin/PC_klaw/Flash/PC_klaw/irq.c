//-------------------------------------------------------------------------
// �� ������������ PC-���������� � ������� �������� ����������
//-------------------------------------------------------------------------

#include "Board.h"

#define IRQ1_INTERRUPT_LEVEL	2

volatile U8 st_bit  = 0; //������� ����� � ����������� ����� �� PC-����������
static U8 DATA  = 0; //����������� ���� �� PC-����������
volatile U8 DATA_KB = 0; //�������� ���� �� PC-����������
volatile  U8 flag_rd_kb=0; // ���� "������ ���� �� PC-����������"
volatile extern U8 DEL_ST_KL; //�������� ������� ��������� ������ ������ PC-����������

//��������� ����� �������� ���������� IRQ1
#define IRQ_1 	(1<<30)	 // PA30  ���� ������������� �� PC-����������

//��������� ����� ������ �� PC-����������
#define IN_DATA_PC (1<<4)  // PA4  ���� ������ �� PC-����������

// ������� ������������� ������� ���������� IRQ ��� ������ � PC-�����������
void irq_pio_init ( void )
{
        // ���������������� ����� �������� ���������� IRQ
   	AT91F_PIO_CfgInput(AT91C_BASE_PIOA,IRQ_1);
        AT91F_PIO_CfgPeriph(AT91C_BASE_PIOA,IRQ_1,0);
   	// ���������������� � ���������� �������� ���������� IRQ1 �� �����
       AT91F_AIC_ConfigureIt (AT91C_BASE_AIC, AT91C_ID_IRQ1, IRQ1_INTERRUPT_LEVEL,
                              AT91C_AIC_SRCTYPE_EXT_NEGATIVE_EDGE,
                              at91_IRQ1_handler);
       AT91F_AIC_EnableIt (AT91C_BASE_AIC, AT91C_ID_IRQ1);

       //���������������� ����� ������ �� PC-����������
       AT91F_PIO_CfgInput( AT91C_BASE_PIOA,IN_DATA_PC) ;
}


// �������-���������� ������ �� PC-���������� � ������� �������� ���������� IRQ1
void at91_IRQ1_handler ( void )
{
  U32 dum=0;

  st_bit++; //��������� �������� �����

  if (st_bit == 11) //�� �������� �� ����� �����?
      {
       st_bit = 0; //�������� ������� �����
       flag_rd_kb=1; //��� ���� "������ ���� �� ����������"
       DATA_KB = DATA; //���������� �������� ���� � ���������� ��������
       DEL_ST_KL = 0;//�������� �������� ������� ��������� ������ ������
       goto  RET;
      }
  if (st_bit == 10)   goto  RET; //���� ��� ���  ��������, ������ �� ������
  if (st_bit == 1)    goto  RET; //���� ��� ��������� ���, ������ �� ������

  //�����, ���� ��� ��� ������, ���������� ���
  if ((AT91F_PIO_GetInput(AT91C_BASE_PIOA) & IN_DATA_PC)==0)
    {  BIT_CLEAR(DATA,(st_bit-2)); }
  else   { BIT_SET(DATA,(st_bit-2));}

  RET:
  //��������� ��������� ���������� IRQ1
  dum =AT91C_BASE_PIOA->PIO_ISR;
  dum =dum; //����� �� �������������� ��������� � ��������� ����������
}
