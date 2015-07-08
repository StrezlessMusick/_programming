//----------------------------------------------------------------------------
// �� ������������ ���
//----------------------------------------------------------------------------

#include "Board.h"
#include "adc.h"

const U16 Upit_mV = 3298; //���������� ������� � �� (������ ��������)

  U16 ADCres=0;     //��������� ��� � ���������
  U16 ADCres_mV=0;  //��������� ��� � ��

  U8 r1000=0;   //-----------------------------------
  U8 r100=0;    // ������� ����������� �����
  U8 r10=0;     //
  U8 r1=0;      //-----------------------------------

#define   TRGEN    (0x0)    // ����������� ������� ���
#define   TRGSEL   (0x0)    // �� ����� �������� ��� ���������� ��������
#define   LOWRES10 (0x0)    // 10-��������� ������ ���������� ���
#define   SLEEP    (0x0)    // ���������� ����� ���
#define   PRESCAL  (0xF)    // ADCClock = MCK / ((PRESCAL+1) * 2)
#define   STARTUP  (0xF)    // Startup Time = (STARTUP+1) * 8 / ADCClock
#define   SHTIM    (0x4)    // Sample & Hold Time  = (SHTIM+1) / ADCClock

//��������� ����� ���
#define   CHANNEL  (4)      // 0 - 7

// ������� ������������� ADC (������� �������� - ����������� ����������)
void ADC_init (U8 res)
       {
       //������� ����������� ���������� ���
       AT91F_ADC_SoftReset (AT91C_BASE_ADC);

       //������� ���������� ���
       AT91F_ADC_CfgModeReg (AT91C_BASE_ADC,
                            (SHTIM << 24) | (STARTUP << 16) | (PRESCAL << 8) |
                            (SLEEP << 5) | (res <<4) | (TRGSEL << 1) | (TRGEN )) ;

        //����� ��������� ������ ���
        AT91F_ADC_EnableChannel (AT91C_BASE_ADC, (1<<CHANNEL));
        }

// ������� ������� � ��������� ���������� ADC ��� 10-���������� ����������
void ADC_start_ind_10 (void)
        {
        //����� ��������������
        AT91F_ADC_StartConversion (AT91C_BASE_ADC);

        //�������� ���������� ��������������
        while (!((AT91F_ADC_GetStatus (AT91C_BASE_ADC)) & (1<<CHANNEL)));

        //������ � ��������� ���������� ���  ����������
        ADCres = AT91F_ADC_GetConvertedDataCH4 (AT91C_BASE_ADC);
        ADCres_mV = (ADCres * Upit_mV) / 1024; //���������� ���������� ��� � ��

        //�������������� � ���������� ������������� � ���������
        //���������� ��� � ���������
        r1000 = ADCres / 1000;
        ADCres = ADCres % 1000;
        r100 = ADCres / 100;
        ADCres = ADCres % 100;
        r10 = ADCres / 10;
        r1 = ADCres % 10;
        lcd_pro_data(r1000,64);
        lcd_tek_data(r100);
        lcd_tek_data(r10);
        lcd_tek_data(r1);

        //�������������� � ���������� ������������� � ���������
        //���������� ��� � ��
        r1000 = ADCres_mV / 1000;
        ADCres_mV = ADCres_mV % 1000;
        r100 = ADCres_mV / 100;
        ADCres_mV = ADCres_mV % 100;
        r10 = ADCres_mV / 10;
        r1 = ADCres_mV % 10;
        lcd_pro_data(r1000,72);
        lcd_tek_data(r100);
        lcd_tek_data(r10);
        lcd_tek_data(r1);
        lcd_pro_data(rus_m,77);
        lcd_tek_data('B');
        }

// ������� ������� � ��������� ���������� ADC ��� 8-���������� ����������
void ADC_start_ind_8 (void)
        {
        //����� ��������������
        AT91F_ADC_StartConversion (AT91C_BASE_ADC);

        //�������� ���������� ��������������
        while (!((AT91F_ADC_GetStatus (AT91C_BASE_ADC)) & (1<<CHANNEL)));

        //������ � ��������� ���������� ���  ����������
        ADCres = AT91F_ADC_GetConvertedDataCH4 (AT91C_BASE_ADC);
        ADCres_mV = (ADCres * Upit_mV) / 256; //���������� ���������� ��� � ��

        //�������������� � ���������� ������������� � ���������
        //���������� ��� � ���������
        r1000 = ADCres / 1000;
        ADCres = ADCres % 1000;
        r100 = ADCres / 100;
        ADCres = ADCres % 100;
        r10 = ADCres / 10;
        r1 = ADCres % 10;
        lcd_pro_data(r1000,64);
        lcd_tek_data(r100);
        lcd_tek_data(r10);
        lcd_tek_data(r1);

        //�������������� � ���������� ������������� � ���������
        //���������� ��� � ��
        r1000 = ADCres_mV / 1000;
        ADCres_mV = ADCres_mV % 1000;
        r100 = ADCres_mV / 100;
        ADCres_mV = ADCres_mV % 100;
        r10 = ADCres_mV / 10;
        r1 = ADCres_mV % 10;
        lcd_pro_data(r1000,72);
        lcd_tek_data(r100);
        lcd_tek_data(r10);
        lcd_tek_data(r1);
        lcd_pro_data(rus_m,77);
        lcd_tek_data('B');
        }


