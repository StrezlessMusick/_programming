//----------------------------------------------------------------------------
// �� ������������ ��������-���������
//----------------------------------------------------------------------------

#include "Board.h"

#define TIMER0_INTERRUPT_LEVEL		1
#define TIMER1_INTERRUPT_LEVEL		4

static U8 U_NEG_old_state=0; //���������� ���� ������ ��������� ����� ���� ��� LCD

// ����� ������������ ��������-���������
#define TC_CLKS                  0x7 //������� ������������ ��
#define TC_CLKS_MCK2             0x0 //----------------------------------
#define TC_CLKS_MCK8             0x1 //
#define TC_CLKS_MCK32            0x2 //  ���������� ������������� ��
#define TC_CLKS_MCK128           0x3 //
#define TC_CLKS_MCK1024          0x4 //----------------------------------

//������������� ������ �������-�������� � ���������� ������������
//������� ���������     : <tc_pt> = ��������� ����������� ������
//                        <mode> = ����� ������� ��������
//                      : <TimerId> = ����������� �������������� �������������
//                      : ���������� (�������)
//�������� ���������    : ���
void AT91F_TC_Open ( AT91PS_TC TC_pt, unsigned int Mode, unsigned int TimerId)
{
    unsigned int dummy;
    //���������� ������������ ������� TIMER
    	AT91F_PMC_EnablePeriphClock ( AT91C_BASE_PMC, 1<< TimerId ) ;
    //���������� ������������ � ����������
        TC_pt->TC_CCR = AT91C_TC_CLKDIS ;
	TC_pt->TC_IDR = 0xFFFFFFFF ;
    //������� ���� �������
        dummy = TC_pt->TC_SR;
        dummy = dummy; //����� �� �������������� ��������� � ��������� ����������
    //������� ������ �������-��������
	TC_pt->TC_CMR = Mode ;
    //���������� ������������
	TC_pt->TC_CCR = AT91C_TC_CLKEN ;
}

// ������� - ���������� ���������� �� timer0
void timer0_c_irq_handler(void)
{
	AT91PS_TC TC_pt = AT91C_BASE_TC0;
    unsigned int dummy;
    //* ����������� ��������� ����������
    dummy = TC_pt->TC_SR;
    dummy = dummy; //����� �� �������������� ��������� � ��������� ����������

    //* �������� ��� ����������
    //
    //
}

// ������� - ���������� ���������� �� timer1
void timer1_c_irq_handler(void)
{
	AT91PS_TC TC_pt = AT91C_BASE_TC1;
    unsigned int dummy;
    //* ����������� ��������� ����������
    dummy = TC_pt->TC_SR;
    dummy = dummy; //����� �� �������������� ��������� � ��������� ����������

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

// ������� ������������� ��������-���������
void timer_init ( void )
{
    // ���������� timer 0
     //	AT91F_TC_Open(AT91C_BASE_TC0,TC_CLKS_MCK1024,AT91C_ID_TC0);
    // ���������� ���������� ��  Timer 0
     //	AT91F_AIC_ConfigureIt ( AT91C_BASE_AIC, AT91C_ID_TC0,
     // TIMER0_INTERRUPT_LEVEL,AT91C_AIC_SRCTYPE_INT_HIGH_LEVEL, timer0_c_irq_handler);
     //	AT91C_BASE_TC0->TC_IER = AT91C_TC_COVFS;  //  ���������� ���������� �� ������������
     //	AT91F_AIC_EnableIt (AT91C_BASE_AIC, AT91C_ID_TC0);
    // ���������� timer 1
	AT91F_TC_Open(AT91C_BASE_TC1,TC_CLKS_MCK2,AT91C_ID_TC1);
    // ���������� ���������� ��  Timer 1
	AT91F_AIC_ConfigureIt ( AT91C_BASE_AIC, AT91C_ID_TC1,
        TIMER1_INTERRUPT_LEVEL,AT91C_AIC_SRCTYPE_INT_HIGH_LEVEL, timer1_c_irq_handler);
	AT91C_BASE_TC1->TC_IER  = AT91C_TC_CPCS;  //���������� ���������� ��� ���������� � RC
	AT91F_AIC_EnableIt (AT91C_BASE_AIC, AT91C_ID_TC1);
        AT91C_BASE_TC1->TC_RC = 0x1000 ; // ������� �������� RC (���������� ������ ����������)
        AT91C_BASE_TC1->TC_CMR  = AT91C_TC_CPCTRG ; //������� �������� ��� ���������� � RC
    // ����� � ������ timer0
      //  AT91C_BASE_TC0->TC_CCR = AT91C_TC_SWTRG ;
    // ����� � ������ timer1
        AT91C_BASE_TC1->TC_CCR = AT91C_TC_SWTRG ;
}
