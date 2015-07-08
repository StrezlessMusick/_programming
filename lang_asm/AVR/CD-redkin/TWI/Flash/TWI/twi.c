//------------------------------------------------------------------------
//�� ������������ TWI
//-------------------------------------------------------------------------

#include "Board.h"
#include "twi.h"

#define ERROR (AT91C_TWI_NACK)

U8 r1000=0;   //-----------------------------------
U8 r100=0;    //  ������� ����������� �����
U8 r10=0;     //
U8 r1=0;      //-----------------------------------

//������� ������� ������� ������������� TWI
void AT91F_SetTwiClock(void)
{
	int sclock;

	//CKDIV = 1, CHDIV=CLDIV  ==> CLDIV = CHDIV = 1/4*((Fmclk/FTWI) -6)

	sclock = (10*MCK /AT91C_TWI_CLOCK);
	if (sclock % 10 >= 5)
		sclock = (sclock /10) - 5;
	else
		sclock = (sclock /10)- 6;
	sclock = (sclock + (4 - sclock %4)) >> 2;	

    AT91C_BASE_TWI->TWI_CWGR	= ( 1<<16 ) | (sclock << 8) | sclock  ;
}

//������� ������ ����� ������ � ������� ���������� TWI
int AT91F_TWI_WriteByte(const AT91PS_TWI pTwi ,int mode, int int_address, char *data2send, int nb)
{
	unsigned int status,counter=0,error=0;

	// ������� ����������� �������� ����������� ������ TWI
	if ((mode & AT91C_TWI_IADRSZ) != 0) pTwi->TWI_IADR = int_address;

	// ������� ����������� �������� ������ �������� TWI
	  pTwi->TWI_MMR = mode & ~AT91C_TWI_MREAD;
	if(nb <2){
		pTwi->TWI_CR = AT91C_TWI_START | AT91C_TWI_MSEN | AT91C_TWI_STOP;
		pTwi->TWI_THR = *data2send;
	}
	else
	{
          for(counter=0;counter<nb;counter++){
          pTwi->TWI_CR = AT91C_TWI_START | AT91C_TWI_MSEN;
          if (counter == (nb - 1)) pTwi->TWI_CR = AT91C_TWI_STOP;
          status = pTwi->TWI_SR;
          if ((status & ERROR) == ERROR) error++;
          while (!(status & AT91C_TWI_TXRDY)){
               status = pTwi->TWI_SR;
               if ((status & ERROR) == ERROR) error++;
          }
          pTwi->TWI_THR = *(data2send+counter);
	   }
	}
	status = pTwi->TWI_SR;
	if ((status & ERROR) == ERROR) error++;
	while (!(status & AT91C_TWI_TXCOMP)){
    		status = pTwi->TWI_SR;
    		if ((status & ERROR) == ERROR) error++;
    }
	return error;
}

//������� ������ ����� ������ �� �������� ���������� TWI
int AT91F_TWI_ReadByte(const AT91PS_TWI pTwi ,int mode, int int_address, char *data, int nb)
{
	unsigned int status,counter=0,error=0;

	//������� ����������� �������� ����������� ������ TWI
	if ((mode & AT91C_TWI_IADRSZ) != 0) pTwi->TWI_IADR = int_address;

	//������� ����������� �������� ������ �������� TWI
	pTwi->TWI_MMR = mode | AT91C_TWI_MREAD;

	// ������ ��������
	if (nb == 1){
	   pTwi->TWI_CR = AT91C_TWI_START | AT91C_TWI_STOP;
	   status = pTwi->TWI_SR;
    	   if ((status & ERROR) == ERROR) error++;
	   while (!(status & AT91C_TWI_TXCOMP)){
    	      status = pTwi->TWI_SR;
              if ((status & ERROR) == ERROR) error++;
    	   }
	   *(data) = pTwi->TWI_RHR;
	}
 	else{
 	   pTwi->TWI_CR = AT91C_TWI_START | AT91C_TWI_MSEN;
	   status = pTwi->TWI_SR;
	   if ((status & ERROR) == ERROR) error++;

	// �������� ��������� ��������
           while (!(status & AT91C_TWI_TXCOMP)){
   		status = pTwi->TWI_SR;
   		if ((status & ERROR )== ERROR) error++;
    		if(status & AT91C_TWI_RXRDY){
			*(data+counter++) = pTwi->TWI_RHR;
			if (counter == (nb - 1)) pTwi->TWI_CR = AT91C_TWI_STOP;
		}
	   }
	}
	return 0;
}

//������� ������������� TWI
void AT91F_TWI_Open(void)
{
	// ���������������� PIO  ��� TWI
	AT91F_TWI_CfgPIO ();
	// ���������������� PMC ��� ���������� ������������ TWI
	AT91F_TWI_CfgPMC ();

	// ���������������� TWI � ������ ��������
	AT91F_TWI_Configure (AT91C_BASE_TWI);

	// ������� ������� ������������� TWI
	AT91F_SetTwiClock();
}

// ������� ������������� ����������� ������ �������� � ��� ��� � ��� ���������
void Preobr_ind_int_addr(int int_addr_I2C_)
            {
            int I2C_addr_i=0;

            I2C_addr_i = int_addr_I2C_;
            r1000 = I2C_addr_i / 1000;
            I2C_addr_i = I2C_addr_i % 1000;
            r100 = I2C_addr_i / 100;
            I2C_addr_i = I2C_addr_i % 100;
            r10 = I2C_addr_i / 10;
            r1 = I2C_addr_i % 10;
            lcd_pro_data(r1000,66);
            lcd_tek_data(r100);
            lcd_tek_data(r10);
            lcd_tek_data(r1);
            }

















