#include "Driver_USART.h"
#include "LPC17xx.h"                    // Device header
#include "string.h" 
#include "PIN_LPC17xx.h"
#include "Board_Buttons.h"
#include "Board_LED.h"
#include "Open1768_LCD.h"
#include "LCD_ILI9325.h"

volatile uint32_t msTicks = 0; 
void tempPrint(const char * napis)
{
		//strcat(napis,"\r");
		for(int i = 0; i < strlen(napis);i++){
				
				if(LPC_UART0->LSR >> 6 == 1){
				LPC_UART0->THR = napis[i];
				}
				else{
					i--;
				}
			}
}

void SysTick_Handler(void)  {                               //SysTick interrupt Handler.  
	msTicks++;                                              
 //See startup file startup_LPC17xx.s for SysTick vector 
}

void TIMER0_IRQHandler(void){

		tempPrint("Ping ");
		LPC_TIM0->IR = 1; // reset the interrupt
}
void RTC_IRQHandler(void){
	char * n1 = "Tik ";
	char * n2 = "Tak ";
	char * napis;
	static char flag = 0;
	
	if(flag == 0){
		flag = 1;
		napis = n1;
	}
	else if(flag == 1){
		flag = 0;
		napis = n2;
	}
	
	tempPrint(napis);
	
	LPC_RTC->ILR = 1;

}
void EINT0_IRQHandler(void)
{
	if(msTicks>100){
			tempPrint("!!!click!!! ");
			LED_On(3);
			LPC_SC->EXTINT =1;
			msTicks = 0;
	}
	else{
			//tempPrint("test");
			LPC_SC->EXTINT =1;
			return;
	}
}
void EINT3_IRQHandler(void)
{
	if(msTicks>100){
		tempPrint("bang");
		msTicks = 0;
	}
	else{
	}
	LPC_GPIOINT->IO0IntClr = (1<<19);

}
void BresenhamLine(const int x1, const int y1, const int x2, const int y2)
 {
     // zmienne pomocnicze
     int d, dx, dy, ai, bi, xi, yi;
     int x = x1, y = y1;
     // ustalenie kierunku rysowania
     if (x1 < x2)
     {
         xi = 1;
         dx = x2 - x1;
     }
     else
     {
         xi = -1;
         dx = x1 - x2;
     }
     // ustalenie kierunku rysowania
     if (y1 < y2)
     {
         yi = 1;
         dy = y2 - y1;
     }
     else
     {
         yi = -1;
         dy = y1 - y2;
     }
     // pierwszy piksel
     glVertex2i(x, y);
     // os wiodaca OX
     if (dx > dy)
     {
         ai = (dy - dx) * 2;
         bi = dy * 2;
         d = bi - dx;
         // petla po kolejnych x
         while (x != x2)
         {
             // test wspólczynnika
             if (d >= 0)
             {
                 x += xi;
                 y += yi;
                 d += ai;
             }
             else
             {
                 d += bi;
                 x += xi;
             }
             glVertex2i(x, y);
         }
     }
     // os wiodaca OY
     else
     {
         ai = ( dx - dy ) * 2;
         bi = dx * 2;
         d = bi - dy;
         // petla po kolejnych y
         while (y != y2)
         {
             // test wspólczynnika
             if (d >= 0)
             {
                 x += xi;
                 y += yi;
                 d += ai;
             }
             else
             {
                 d += bi;
                 y += yi;
             }
             glVertex2i(x, y);
         }
     }
 }
int main() {

		SysTick_Config(SystemCoreClock / 100); //10ms
		Buttons_Initialize();
		LED_Initialize();
		LED_Off(0);
		LED_Off(1);
		LED_Off(2);
		LED_Off(3);
	
	
		PIN_Configure(0,2,1,2,0);
		PIN_Configure(0,3,1,2,0);
		LPC_UART0->LCR = 3 | (1<<7);
		LPC_UART0->DLL = 27; // dzielnik peryferyjny 2, 256 max
		LPC_UART0->DLM = 0; // tu naddatek x*256
		LPC_UART0->FCR = 6;
		LPC_UART0->LCR = 3;
	
		// TIMER 0
		LPC_TIM0->PR = 0; // Prescale Register - when PR == PC -> increments TC (Timer Counter) and resets PC
		LPC_TIM0->MCR = 3;
		// 1st bit - interrupt, when TC == MR0
		// 2nd bit - resets TC, when TC == MR0
		LPC_TIM0->MR0 = 12500000; // every 0.5s ???
		LPC_TIM0->TCR = 1; // enables PC & TC for count
			

		//RTC
		LPC_RTC->CCR = 1;
		LPC_RTC->ILR = 1;
		LPC_RTC->CIIR = 1;
		
		//button
		LPC_SC->EXTMODE = 1; // zbocze
		LPC_SC->EXTPOLAR =  0; // falling-edge
		LPC_SC->EXTINT = 1; // interrupt
		PIN_Configure(2,10,1,0,0); // primary function, pull-up, no drain (pull up by trzymal logicznie 1 jak key odlaczony)
		
		//dotykowy
		LPC_GPIOINT->IO0IntEnF = (1<<19);
		PIN_Configure(0,19,1,0,0);
		
	
		
		NVIC_EnableIRQ(TIMER0_IRQn);
		NVIC_EnableIRQ(RTC_IRQn);
		NVIC_EnableIRQ(EINT0_IRQn);
		NVIC_EnableIRQ(EINT3_IRQn);
		
		
		//led
		
		lcdConfiguration();
		init_ILI9325();

		for(int i=0;i<LCD_MAX_X;i++){
				for(int j=LCD_MAX_Y;j>0;j--){
					lcdWriteReg(ADRX_RAM,i);
					lcdWriteReg(ADRY_RAM,j);
					lcdWriteReg(DATA_RAM,LCDRed);
				}
		}
	
		while(1)
		{
			//int num = lcdReadReg(0);
			//if(num == 0x8989)
				//tempPrint("1");
			//else if(num == 0x9325)
				//tempPrint("2");
			//else if(num == 0x9328)
				//tempPrint("3"); <- TO JEST TO
			//else
				//tempPrint("4");
			}
	
	return 0;
}
