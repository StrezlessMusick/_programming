//-------------------------------------------------------------------------
// �������� ��������� ������������ TWI
//-------------------------------------------------------------------------

#include "Board.h"
#include "twi.h"

//����� ������� ������
volatile extern U8 flagn_kn1, flagn_kn2, flagn_kn3, flagn_kn4;

//����� �������� ���������� I2C
//0x57=0b1010111: ��� ���������� I2C - EEPROM (1010), ����� ���� I2C �� ���� (111)
#define AT91C_EEPROM_I2C_ADDRESS  	(0x57<<16)

U16 int_addr_I2C = 0; //���������� ����� �������� ���������� TWI

U16 I2C_addr_i; //���������� ����� �������� ���������� TWI ��� ���������

char write_byte = 'A', read_byte = 0; //����� ������ ��� ������ � ������ TWI

//������ �������� ���������
void main(void)
{
  CPUinit();         //������������� �������
  timer_init();      //������������� ��������-���������
  AT91F_TWI_Open();  //������������� TWI
  LCDinit_clear();   //��� ������������� � ����� ���

  // ����� �� ��� ��������� ��������
  lcd_pro_data('T', 0);
  lcd_tek_data('W');
  lcd_tek_data('I');
  lcd_tek_data('_');
  lcd_tek_data('F');
  lcd_tek_data('L');
  lcd_tek_data('A');
  lcd_tek_data('S');
  lcd_tek_data('H');

  lcd_pro_data(write_byte, 64); //��������� �����, ����������� ������

  //������������� ����������� ������ �������� � ��� ��� � ��� ���������
            Preobr_ind_int_addr(int_addr_I2C);

  //���������� ������ �� �������� ���������� TWI (2-�������� ����� �����)
            AT91F_TWI_ReadByte(AT91C_BASE_TWI, AT91C_EEPROM_I2C_ADDRESS |
                                        AT91C_TWI_IADRSZ_2_BYTE, int_addr_I2C, &read_byte, 1);

            lcd_pro_data(read_byte, 71); //��������� ������������ �����

    //������ ��������� �����
    for (;;)
    {

      if  (flagn_kn1==1)    // ���������� �� ������ 1
     	    {
            flagn_kn1=0;    //��, �������� ���� �������

            //����� � ��������� ��������, ����������� ������ � ������� ����������
            write_byte ++;
            if (write_byte == 'z')  write_byte = 'A';
            lcd_pro_data(write_byte, 64); //��������� �����, ����������� ������
            }

     if  (flagn_kn2==1)    // ���������� �� ������ 2
	    {
	    flagn_kn2=0;    //��, �������� ���� �������
            //����� � ��������� ���������� ������ �������� ����������
            int_addr_I2C += 50;
            if (int_addr_I2C > 8150) int_addr_I2C = 0;

            //������������� ����������� ������ �������� � ��� ��� � ��� ���������
            Preobr_ind_int_addr(int_addr_I2C);

            //���������� ������ �� �������� ���������� TWI (2-�������� ����� �����)
            AT91F_TWI_ReadByte(AT91C_BASE_TWI, AT91C_EEPROM_I2C_ADDRESS |
                                        AT91C_TWI_IADRSZ_2_BYTE, int_addr_I2C, &read_byte, 1);

            lcd_pro_data(read_byte, 71); //��������� ������������ �����
            }

     if  (flagn_kn3==1)    // ���������� �� ������ 3
	    {
	    flagn_kn3=0;    //��, �������� ���� �������

            //���������� ������ � ������� ���������� TWI (2-�������� ����� �����)
            AT91F_TWI_WriteByte(AT91C_BASE_TWI, AT91C_EEPROM_I2C_ADDRESS |
                                        AT91C_TWI_IADRSZ_2_BYTE, int_addr_I2C, &write_byte, 1);

            lcd_pro_data(write_byte, 76); //��������� ����������� �����

            delay(800000);      //�������� �� ������ (�� ����� 5 ��)

            //���������� ������ �� �������� ���������� TWI (2-�������� ����� �����)
            AT91F_TWI_ReadByte(AT91C_BASE_TWI, AT91C_EEPROM_I2C_ADDRESS |
                                        AT91C_TWI_IADRSZ_2_BYTE, int_addr_I2C, &read_byte, 1);

            lcd_pro_data(read_byte, 71); //��������� ������������ �����
            }

     if  (flagn_kn4==1)    // ���������� �� ������ 4
	    {
	    flagn_kn4=0;    //��, �������� ���� �������

            //���������� ������ �� �������� ���������� TWI (2-�������� ����� �����)
            AT91F_TWI_ReadByte(AT91C_BASE_TWI, AT91C_EEPROM_I2C_ADDRESS |
                                        AT91C_TWI_IADRSZ_2_BYTE, int_addr_I2C, &read_byte, 1);

            lcd_pro_data(read_byte, 71); //��������� ������������ �����
            }
    }
}




