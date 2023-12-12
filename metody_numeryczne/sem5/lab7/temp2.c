int main (void)
{
  uint32_t receive[18],buf=0x0000;
  SystemClockUpdate() updates the SystemFrequency variable
  SSP1Init();    //SSP Initialization



  SSPSend(1,0x0000,16);  //dummy data=0x0000 to send 16-bit clock



  while(1)
  {
  }
}


void SSP1Init( void )
{
  uint8_t i, Dummy=Dummy;

  LPC_SC->PCONP |= (0x1<<10);        //Enabling the SSP1 Clock

  /* Further divider is needed on SSP1 clock. Using default divided by 4 */
  LPC_SC->PCLKSEL0 &= ~(0x3<<20);
   LPC_SC->PCLKSEL0 |= (0x3<<20);
  /* P0.6~0.9 as SSP1 */
  LPC_PINCON->PINSEL0 &= ~((0x3<<12)|(0x3<<16)|(0x3<<18)|(0x3<<14));  //clear MISO and CLK
  LPC_PINCON->PINSEL0 |= ((0x2<<14)|(0x2<<16));  //set MISO1 and CLK1 pin functions

  /* Set DSS data to 16-bit, CPOL = 1, CPHA = 0, SSI mode and SCR is 7 */
  LPC_SSP1->CR0 = 0x075F;

  /* SSPCPSR clock prescale register, master mode, minimum divisor is 0x02 */
  LPC_SSP1->CPSR = 0x02;

  {
        Dummy = LPC_SSP1->DR;                /* clear the RxFIFO */
     }
   NVIC_EnableIRQ(SSP1_IRQn); /* Enable the SSP Interrupt */




   LPC_SSP1->CR1 = SSPCR1_SSE;/* Master mode *//* Device select as master, SSP Enabled */




  /* Set SSPINMS registers to enable interrupts */
  /* enable all error related interrupts */
  LPC_SSP1->IMSC = SSPIMSC_RORIM | SSPIMSC_RTIM;
  return;
}


void SSPSend( uint32_t portnum, int buf, uint32_t Length )
{
  uint32_t i;
  uint8_t Dummy ;

  for ( i = 0; i < Length; i++ )
  {

     if ( portnum == 1 )
        {
          /* Move on only if NOT busy and TX FIFO not full. */
          while ( (LPC_SSP1->SR & (SSPSR_TNF|SSPSR_BSY)) != SSPSR_TNF );
          LPC_SSP1->DR = buf;

#if !LOOPBACK_MODE
        while ( (LPC_SSP1->SR & (SSPSR_BSY|SSPSR_RNE)) != SSPSR_RNE );
          /* Whenever a byte is written, MISO FIFO counter increments, Clear FIFO
          on MISO. Otherwise, when SSP0Receive() is called, previous data byte
          is left in the FIFO. */
         Dummy = LPC_SSP1->DR;                  //equating the SPDR to Dummy Varaible
#else
          /* Wait until the Busy bit is cleared. */
          while ( LPC_SSP1->SR & SSPSR_BSY );
#endif
    }
  }
  return ;
}