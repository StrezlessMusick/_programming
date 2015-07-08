//-------------------------------------------------------------------------------
// �� ������������ PIT
//-------------------------------------------------------------------------------

#include "Board.h"

#define PIT_INTERRUPT_LEVEL	1
#define PIV_PERIOD 		1000     	//������ ���������� �� PIT -
                                                // 0,3 �� ��� 48 ���

static U8 U_NEG_old_state=0; //���������� ���� ������ ��������� ����� ���� ��� LCD

//���������� ���������� �� PIT
void Periodic_Interval_Timer_handler(void)
{
    unsigned int status;
    //����� ���������� �� PIT
    status = AT91C_BASE_PITC->PITC_PIVR;
	status =status; //����� �� �������������� ��������� � ��������� ����������

    //* �������� ��� ����������
    opros_kn1(); // ����� ������ 1
    opros_kn2(); // ����� ������ 2
    opros_kn3(); // ����� ������ 3
    opros_kn4(); // ����� ������ 4

     //����� ��������� ������ ��������� ����� ���� ��� LCD
            if (U_NEG_old_state==OFF)
                     {
                     AT91F_PIO_ClearOutput( AT91C_BASE_PIOA, U_NEG); // ����� U_NEG
                     U_NEG_old_state=ON;
                     }
            else
                     {
                     AT91F_PIO_SetOutput( AT91C_BASE_PIOA, U_NEG); // ��� U_NEG
                     U_NEG_old_state=OFF;
                     }
}

//������� ������������� PIT
void PIT_init( void )
{
        //���������������� AIC
	AT91F_AIC_ConfigureIt ( AT91C_BASE_AIC, AT91C_ID_SYS, PIT_INTERRUPT_LEVEL,
                               AT91C_AIC_SRCTYPE_INT_POSITIVE_EDGE,
                               Periodic_Interval_Timer_handler);
	//���������� PIT, ���������� ���������� �� PIT � �������� ��� �������
	AT91C_BASE_PITC->PITC_PIMR = AT91C_PITC_PITEN | AT91C_PITC_PITIEN | PIV_PERIOD;
        AT91F_AIC_EnableIt (AT91C_BASE_AIC, AT91C_ID_SYS);
}
