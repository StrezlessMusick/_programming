//-------------------------------------------------------------------------
// �� ������������ USART
//-------------------------------------------------------------------------

#include "usart.h"

#define USART_INTERRUPT_LEVEL		1

//������� ������������� USART0 �� ��������� ������ [����/�]
void InitUSART0(U32 baudrate)
{
  //���������� ������������ ������ ����� PIO
  AT91C_BASE_PIOA->PIO_PDR = BIT5 | BIT6 | BIT21 | BIT22; //
  AT91C_BASE_PIOA->PIO_ASR = BIT5 | BIT6 | BIT21 | BIT22; //
  AT91C_BASE_PIOA->PIO_BSR = 0;                           //

  //���������� ������������� USART0
  AT91C_BASE_PMC->PMC_PCER = 1<<AT91C_ID_US0;

  //������� ������ USART0 (����������), �������� ������� USART0 - MCK, 1 �������� ���
  //8 ��� � �����,
  AT91C_BASE_US0->US_MR = AT91C_US_USMODE_NORMAL | AT91C_US_CLKS_CLOCK |
                        AT91C_US_CHRL_8_BITS | AT91C_US_NBSTOP_1_BIT;

  //������� �������� ������ USART0
  //(�������� ������ [����/�] = MCK/(16*US_BRGR))
  AT91C_BASE_US0->US_BRGR = MCK/(baudrate*16);

  //������ � ������� Timeguard
  AT91C_BASE_US0->US_TTGR = 0;

  //���������� RX � TX USART0
  AT91C_BASE_US0->US_CR = 0x50; // 1010000

  //���������� ���������� �� USART0
    AT91F_AIC_ConfigureIt (AT91C_BASE_AIC, AT91C_ID_US0, USART_INTERRUPT_LEVEL,
                           AT91C_AIC_SRCTYPE_INT_HIGH_LEVEL, Usart_c_irq_handler);

  //���������� ���������� ��� ������ �������  USART0
  AT91C_BASE_US0->US_IER = (0x1 <<  0);

  AT91F_AIC_EnableIt (AT91C_BASE_AIC, AT91C_ID_US0);
}


//���������� ���������� �� USART0
void Usart_c_irq_handler(void)
{
	U8 status;
	//��������� �������� ��������� USART0 � ������ ��������� ����������
	status = AT91C_BASE_US0 -> US_CSR ;
        status &= AT91C_BASE_US0 -> US_IMR;
        //���� ��� ���������� ��� ������ �������  USART0, �� ���������� ���
	if (status & AT91C_US_RXRDY)
           {
            //��������� ��������� ����� USART0 �������
	    lcd_pro_data(read_char_USART0(),15);
           }
}

//������� �������� ������� ����� USART0
void write_char_USART0(U8 ch)
{
  while (!(AT91C_BASE_US0->US_CSR&AT91C_US_TXRDY)==1);
  AT91C_BASE_US0->US_THR = ((ch & 0x1FF));
}

//������� ������ ������� ����� USART0
U8 read_char_USART0(void)
{
  while (!(AT91C_BASE_US0->US_CSR&AT91C_US_RXRDY)==1);
  return((AT91C_BASE_US0->US_RHR) & 0x1FF);
}

//������� �������� ������ ����� USART0
void write_str_USART0(char *buff)
 {
  U8 i = 0x0;

  while(buff[i] != '\0')
   {
    write_char_USART0(buff[i]);
    i++;
   }
 }



