//------------------------------------------------------------------------
//�� ��������� ��� HD44780. ������ ���������� � ��� �� 4-������ ����.
//���� ��� ������������, �� ������� "lcd_opros();" ���� �����������������,
//� ������� "delay(3000);" � "delay(100000);" ����������������, ���� ���
//�� ������������, �� ��������.
//------------------------------------------------------------------------

#include "Board.h"

void delay(U32 ticks)   //�������� ��� �������� ���������� ���
  {
     for(; ticks; --ticks)
	    {
		asm ("nop");
	    }
  }

void lcd_pulse_E()  //������� ������������� ������/������ ���
  {
  delay(100);
  AT91F_PIO_SetOutput( AT91C_BASE_PIOA, E);  // ����� �������� E
  delay(100);
  AT91F_PIO_ClearOutput( AT91C_BASE_PIOA, E);  // ���� �������� E
  delay(100);
  }

void lcd_send_byte(U8 byte) //�������� � ��� ����� ����� ���������
  {
    if (BIT_TEST(byte,4))  AT91F_PIO_SetOutput( AT91C_BASE_PIOA, DB4); //---
    else   AT91F_PIO_ClearOutput( AT91C_BASE_PIOA, DB4);               //
    if (BIT_TEST(byte,5))  AT91F_PIO_SetOutput( AT91C_BASE_PIOA, DB5); //
    else   AT91F_PIO_ClearOutput( AT91C_BASE_PIOA, DB5);               //
    if (BIT_TEST(byte,6))  AT91F_PIO_SetOutput( AT91C_BASE_PIOA, DB6); // �������� �� �������
    else   AT91F_PIO_ClearOutput( AT91C_BASE_PIOA, DB6);               //
    if (BIT_TEST(byte,7))  AT91F_PIO_SetOutput( AT91C_BASE_PIOA, DB7); //
    else   AT91F_PIO_ClearOutput( AT91C_BASE_PIOA, DB7);               //
  lcd_pulse_E();                                                       //---
    if (BIT_TEST(byte,0))  AT91F_PIO_SetOutput( AT91C_BASE_PIOA, DB4); //---
    else   AT91F_PIO_ClearOutput( AT91C_BASE_PIOA, DB4);               //
    if (BIT_TEST(byte,1))  AT91F_PIO_SetOutput( AT91C_BASE_PIOA, DB5); //
    else   AT91F_PIO_ClearOutput( AT91C_BASE_PIOA, DB5);               // �������� �� �������
    if (BIT_TEST(byte,2))  AT91F_PIO_SetOutput( AT91C_BASE_PIOA, DB6); //
    else   AT91F_PIO_ClearOutput( AT91C_BASE_PIOA, DB6);               //
    if (BIT_TEST(byte,3))  AT91F_PIO_SetOutput( AT91C_BASE_PIOA, DB7); //
    else   AT91F_PIO_ClearOutput( AT91C_BASE_PIOA, DB7);               //
  lcd_pulse_E();                                                       //---
  }

// ������ � ��� ������ ������� ������ �� ������������� ������ ��� ���
//���� ��� ������������, �� ������� "lcd_opros();" ���� �����������������,
//� ������� "delay(3000);" ����������������, � ��������� ������ - ��������
void lcd_pro_data(U8 date, U8 addr)
  {
   AT91F_PIO_ClearOutput( AT91C_BASE_PIOA, RW);         //����� ������ � ���
   AT91F_PIO_ClearOutput( AT91C_BASE_PIOA, RS);        //����� ������������ �������
   BIT_SET(addr,7);     //����� ������������ ����� ��� ���
   lcd_send_byte(addr); //�������� ������
   delay(3000);         //�������� 50 ��� ��� ���������� ���
   //lcd_opros(); //�������� ���������� ���
   AT91F_PIO_SetOutput( AT91C_BASE_PIOA, RS);          //����� ������������ ������
   if (date < 10)  lcd_send_byte(date + 0x30); //���������� �������� �����
   else   lcd_send_byte(date);                //���������� ���� (�� �����)
   delay(3000);//�������� 50 ��� ��� ���������� ���
   //lcd_opros(); //�������� ���������� ���
  }

// ������ � ��� ������ ������� ������ �� �������� ������ ��� ���
//���� ��� ������������, �� ������� "lcd_opros();" ���� �����������������,
//� ������� "delay(3000);" ����������������, � ��������� ������ - ��������
void lcd_tek_data(U8 date)
  {
   AT91F_PIO_ClearOutput( AT91C_BASE_PIOA, RW);       //����� ������ � ���
   AT91F_PIO_SetOutput( AT91C_BASE_PIOA, RS);         //����� ������������ ������
   if (date < 10) lcd_send_byte(date + 0x30); //���������� �������� �����
   else    lcd_send_byte(date);               //���������� ���� (�� �����)
   delay(3000);//�������� 50 ��� ��� ���������� ���
   //lcd_opros(); //�������� ���������� ���
  }

void lcd_com(U8 comand) // ������ � ��� �������
//���� ��� ������������, �� ������� "lcd_opros();" ���� �����������������,
//� ������� "delay(100000);" ����������������, � ��������� ������ - ��������
  {
   AT91F_PIO_ClearOutput( AT91C_BASE_PIOA, RW);  //����� ������ � ���
   AT91F_PIO_ClearOutput( AT91C_BASE_PIOA, RS);  //����� ������������ �������
   lcd_send_byte(comand); //�������� �������
   delay(100000); //�������� 2000 ��� ��� ���������� ���
   //lcd_opros(); //�������� ���������� ���
  }

void lcd_init() // ������������� ���
  {
   lcd_com(0x28);   //4-� ������ ����, 2 ������, ������ 5�7
   lcd_com(0x01);   //������� �������, ������ � ��� ���������
   lcd_com(0x06);   //������� �� ��������, ������ ��������
   lcd_com(0x0C);   //�������� �������,��������  ������
  }

void lcd_clear()  //������� ������ ���
  {
   lcd_com(0x01);   //������� �������, ������ � ��� ���������
  }

void LCDinit_clear() //��������� ������������� � ����� ��� ����� ��� �������
  {
  U8 i = 20;
  delay(5000000);       //�������� �� ����� ���
  for(; i; --i)
    {
      lcd_init();           // ������������� ���
    delay(1000000);          //
    }
  lcd_clear();            //������� ���
  delay(1000000);          //
  }

//����� ��� �� ������� ��� ���������� ��������� ������� � ������
void lcd_opros()
  {
   AT91F_PIO_SetOutput( AT91C_BASE_PIOA, RW);         //����� ������ �� ���
   AT91F_PIO_ClearOutput( AT91C_BASE_PIOA, RS);  //����� �������� �������
   // ������� ���� ����� ��� �������
   AT91F_PIO_CfgInput( AT91C_BASE_PIOA, LCD_DMASK ) ;
  Opros:
   delay(100);       //
   AT91F_PIO_SetOutput( AT91C_BASE_PIOA, E);  // ����� �������� E
   delay(100);       //
  //(����� ����� BUSY) �������� �� ��� ?
  if ( (AT91F_PIO_GetInput(AT91C_BASE_PIOA) & DB7) == 1)
     {
     delay(100); //
     AT91F_PIO_ClearOutput( AT91C_BASE_PIOA, E);  // ���� �������� E
     delay(100); //
     lcd_pulse_E();  //������� ������������� ������/������ ���
     goto  Opros;  //
     }
  else
     {
     delay(100); //
     AT91F_PIO_ClearOutput( AT91C_BASE_PIOA, E);  // ���� �������� E
     delay(100); //
     lcd_pulse_E();  //������� ������������� ������/������ ���
     }
   AT91F_PIO_ClearOutput( AT91C_BASE_PIOA, RW);  //����� ������ � ���
   // ������� ���� ����� ��� ��������
   AT91F_PIO_CfgOutput( AT91C_BASE_PIOA, LCD_DMASK ) ;
   delay(100);  //
   }












