//----------------------------------------------------------------------------------
// �������, ����������� � �������
//----------------------------------------------------------------------------------

#include "Board.h"

//������������� �������� ����� �������
void CPUinit()
  {
  //������������ EFC (Flash-������)
  AT91C_BASE_MC->MC_FMR = AT91C_MC_FWS_1FWS ; // 1 ����� �� ������, 3 ����� �� ������
  //��������� �������� ������
  //��������� � ������� ������� ������� ��������� ����������
  AT91C_BASE_PMC->PMC_MOR = (( AT91C_CKGR_OSCOUNT & (0x40 <<8) | AT91C_CKGR_MOSCEN ));
  // �������� ������������ ������� ��������� ����������
  while(!(AT91C_BASE_PMC->PMC_SR & AT91C_PMC_MOSCS));
  //�������  ������� PLL  96,109 ��� � ���� ������� UDP 48,058 ���
  AT91C_BASE_PMC->PMC_PLLR = AT91C_CKGR_USBDIV_1|(16 << 8) |
                               (AT91C_CKGR_MUL & (72 << 16)) |
                               (AT91C_CKGR_DIV & 14);
  //�������� ������������ PLL
  while( !(AT91C_BASE_PMC->PMC_SR & AT91C_PMC_LOCK) );
    // �������� ������������ �������� ������� �� PLL
  while( !(AT91C_BASE_PMC->PMC_SR & AT91C_PMC_MCKRDY) );
  //������� �������� ������� � ������� ���������� PLL/2=48 ���
  //������� PMC_MCKR �� ������ ���������������� ����� ��������� ������
  AT91C_BASE_PMC->PMC_MCKR = AT91C_PMC_PRES_CLK_2;
  // �������� ������������ �������� �������
  while( !(AT91C_BASE_PMC->PMC_SR & AT91C_PMC_MCKRDY) );
  AT91C_BASE_PMC->PMC_MCKR |= AT91C_PMC_CSS_PLL_CLK;
  // �������� ������������ �������� �������
  while( !(AT91C_BASE_PMC->PMC_SR & AT91C_PMC_MCKRDY) );
  // ���������� ����������� �������
  AT91C_BASE_WDTC->WDTC_WDMR = AT91C_WDTC_WDDIS;
  // ���������� ������������ PIO
  AT91F_PMC_EnablePeriphClock ( AT91C_BASE_PMC, 1 << AT91C_ID_PIOA ) ;
  // ���������������� �����  PIO ��� ������� ������������ ����������� LED1,...LED4
  AT91F_PIO_CfgOutput( AT91C_BASE_PIOA, LED_MASK ) ;
  // ��������� ������� - ������� �����������
  AT91F_PIO_SetOutput( AT91C_BASE_PIOA, LED_MASK ) ;
  // ���������������� �����  PIO ��� ������ ��������� ������� ����� ������ ��� LCD
  AT91F_PIO_CfgOutput( AT91C_BASE_PIOA, U_NEG ) ;
  // ����� ������ ��������� ������� ����� ������ ��� LCD
  AT91F_PIO_ClearOutput( AT91C_BASE_PIOA, U_NEG ) ;
  // ���������������� �����  PIO ��� ������� ������������ ���
  AT91F_PIO_CfgOutput( AT91C_BASE_PIOA, LCD_MASK ) ;
  // ����� ������� ������������ ���
  AT91F_PIO_ClearOutput( AT91C_BASE_PIOA, LCD_MASK ) ;
  }

