//----------------------------------------------------------------------------------
// ����������� ��� ���������� �����  (AT91SAM7X128)
//----------------------------------------------------------------------------------
#ifndef Board_h
#define Board_h

#include "include/AT91SAM7X128.h"
#define __inline inline
#include "include/lib_AT91SAM7X128.h"

#define true	1
#define false	0
#define ON      1
#define OFF     0

//����������� ����� �������
typedef unsigned int            U8;             /*  8 bit unsigned UPGRADE*/
typedef signed int              S8;             /*  8 bit signed   UPGRADE*/
typedef unsigned int            U16;            /* 16 bit unsigned */
typedef signed int              S16;            /* 16 bit signed */
typedef unsigned long int       U32;            /* 32 bit unsigned */
typedef signed long int         S32;            /* 32 bit signed */

//������� ���������, ������ � ������������ ����
#define  BIT_SET(address,bit)     (address |= (1 << bit))
#define  BIT_CLEAR(address,bit)   (address &= ~(1 << bit))
#define  BIT_TEST(address,bit)    (address & (1 << bit))

//0��������� ������� ����������� ---------------------------------------------------

#define LED1            (1<<22) //PB22	
#define LED2            (1<<21)	//PB21
#define LED3            (1<<20)	//PB20
#define LED4            (1<<19) //PB19
#define NB_LEB			4
#define LED_MASK        (LED1|LED2|LED3|LED4)
//----------------------------------------------------------------------------------

//��������� ������ ��������� ������� ������������ �������������� ���������� ��� LCD
#define U_NEG 	(1<<5)	// PA5

//����������, ����������� � ������� ------------------------------------------------

#define SW1_MASK        (1<<21)	
#define SW2_MASK        (1<<22)	
#define SW3_MASK        (1<<23)	
#define SW4_MASK        (1<<24)	
#define SW5_MASK        (1<<25)

#define SW_MASK         (SW1_MASK|SW2_MASK|SW3_MASK|SW4_MASK|SW5_MASK)
#define SW1 	(1<<21)	// PA21
#define SW2 	(1<<22)	// PA22
#define SW3 	(1<<23)	// PA23
#define SW4 	(1<<24)	// PA24
#define SW5 	(1<<25)	// PA25

//���������� ������� ������ ������
void opros_kn1(); // ����� ������ 1
void opros_kn2(); // ����� ������ 2
void opros_kn3(); // ����� ������ 3
void opros_kn4(); // ����� ������ 4
void opros_kn5(); // ����� ������ 5

//��������� ���������� �������� ������
#define  DREB_KN1_K   200
#define  DREB_KN2_K   200
#define  DREB_KN3_K   200
#define  DREB_KN4_K   200
#define  DREB_KN5_K   200

//----------------------------------------------------------------------------------

//----------------------����������, ����������� � ������� --------------------------
//�������� �������
#define EXT_OC          18432000   // Exetrnal ocilator MAINCK
#define MCK             48054857   // MCK (PLLRC div by 2)
#define MCKKHz          (MCK/1000) //

//���������� ������� ������������� �������
void CPUinit();

// ��������� ������� ������������� ��������-���������
extern void timer_init (void );
//----------------------------------------------------------------------------------

//----------------------����������, ����������� � ���-------------------------------
//������� ����� ���
#define RW              (1<<12)	// PA12 - ��� 1 XP4 "EXT2" - � ��� 5 ��� HD44780 WH1602
#define RS              (1<<17)	// PA17 - ��� 2 XP4 "EXT2" - � ��� 4 ��� HD44780 WH1602
#define E               (1<<14)	// PA14 - ��� 3 XP4 "EXT2" - � ��� 6 ��� HD44780 WH1602
#define DB4             (1<<18)	// PA18 - ��� 4 XP4 "EXT2" - � ��� 11 ��� HD44780 WH1602
#define DB5             (1<<13)	// PA13 - ��� 5 XP4 "EXT2" - � ��� 12 ��� HD44780 WH1602
#define DB6             (1<<16)	// PA16 - ��� 7 XP4 "EXT2" - � ��� 13 ��� HD44780 WH1602
#define DB7             (1<<15)	// PA15 - ��� 6 XP4 "EXT2" - � ��� 14 ��� HD44780 WH1602
//��� 9 XP4 "EXT2" (VCC) - � ��� 2 (VCC) ��� HD44780 WH1602
//��� 10 XP4 "EXT2" (GND) - � ��� 1 (GND), 3 (VS) ��� HD44780 WH1602

#define LCD_MASK        (RW|RS|E|DB4|DB5|DB6|DB7)
#define LCD_DMASK       (DB4|DB5|DB6|DB7)

//���������� ������� �������� ��� �������� ���������� ���
void  delay(U32); //��� �������� 50 ��� ��� ���� ���� 50 ���  ticks=3000
                  //��� �������� 1800 ��� ��� ���� ���� 50 ���  ticks=100000

//���������� ������� �������� ������������� ������/������ ���
void lcd_pulse_E();

//���������� ������� �������� � ��� �����
void lcd_send_byte(U8);

//���������� ������� ������ � ��� ������ ������� ������ ��
//������������� ������ ��� ���
void lcd_pro_data(U8, U8);

//���������� ������� ������ � ��� ������ ������� ������ ��
//�������� ������ ��� ���
void lcd_tek_data(U8);

//���������� ������� ������ � ��� �������
void lcd_com(U8);

//���������� ������� ������������� ���
void lcd_init();

//���������� ������� ������� ������ ���
void lcd_clear();

//���������� ������� ��� ������������� � ������ ���
void LCDinit_clear();

//���������� ������� ������ ��� �� ������� ��� ����������
//��������� ������� � ������
void lcd_opros();

//����������� ������� ���� ��������������� ���  HD44780
#define rus_b         0xB2  //  �
#define rus_v         0xB3  //  �
#define rus_g         0xB4  //  �
#define rus_d         0xE3  //  �
#define rus_eo        0xA2  //  e''
#define rus_j         0xB6  //  �
#define rus_z         0xB7  //  �
#define rus_i         0xB8  //  �
#define rus_ik        0xB9  //  �
#define rus_k         0xBA  //  �
#define rus_l         0xBB  //  �
#define rus_m         0xBC  //  �
#define rus_n         0xBD  //  �
#define rus_p         0xBE  //  �
#define rus_t         0xBF  //  �
#define rus_f         0xE4  //  �
#define rus_tz        0xE5  //  �
#define rus_ch        0xC0  //  �
#define rus_sch       0xC1  //  �
#define rus_ssch      0xE6  //  �
#define rus_m_zn      0xC4  //  �
#define rus_t_zn      0xC2  //  �
#define rus_ii        0xC3  //  �
#define rus_ei        0xC5  //  �
#define rus_ju        0xC6  //  �
#define rus_ja        0xC7  //  �

#define rus_B         0xA0  //  �
#define rus_G         0xA1  //  �
#define rus_D         0xE0  //  �
#define rus_J         0xA3  //  �
#define rus_Z         0xA4  //  �
#define rus_I         0xA5  //  �
#define rus_IK        0xA6  //  �
#define rus_L         0xA7  //  �
#define rus_P         0xA8  //  �
#define rus_U         0xA9  //  �
#define rus_F         0xAA  //  �
#define rus_TZ        0xE1  //  �
#define rus_CH        0xAB  //  �
#define rus_SCH       0xAC  //  �
#define rus_SSCH      0xE2  //  �
#define rus_T_ZN      0xAD  //  �
#define rus_II        0xAE  //  �
#define rus_EI        0xAF  //  �
#define rus_JU        0xB0  //  �
#define rus_JA        0xB1  //  �
//-----------------------------------------------------------------------------------


#endif /* Board_h */
