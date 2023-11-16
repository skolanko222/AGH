#include "Driver_USART.h"
#include "LPC17xx.h"                    // Device header
#include "string.h" 
#include "PIN_LPC17xx.h"

void TIMER0_IRQHandler(void){
		const char napis[] = "Ping";
		for(int i = 0; i < sizeof(napis) ; i++){
				
				if(LPC_UART0->LSR >> 6 == 1){
				LPC_UART0->THR = napis[i];
				}
				else{
					i--;
				}
			}
		LPC_TIM0->IR = 1;
}
void RTC_IRQHandler(void){
	const char * n1 = "Tik\n";
	const char * n2 = "Tak\n";
	const char * napis;
	static char flag = 0;
	
	if(flag == 0){
		flag = 1;
		napis = n1;
	}
	else if(flag == 1){
		flag = 0;
		napis = n2;
	}
	
	for(int i = 0; i < sizeof(n1) ; i++){
				
				if(LPC_UART0->LSR >> 6 == 1){
				LPC_UART0->THR = napis[i];
				}
				else{
					i--;
				}
			}
	
	LPC_RTC->ILR = 1;

}

int main() {

		SysTick_Config(SystemCoreClock / 100); //10ms
	
		PIN_Configure(0,2,1,2,0);
		PIN_Configure(0,3,1,2,0);
	

		LPC_UART0->LCR = 3 | (1<<7);
		LPC_UART0->DLL = 27; // dzielnik peryferyjny 2, 256 max
		LPC_UART0->DLM = 0; // tu naddatek x*256
		LPC_UART0->FCR = 6;
		
		
		LPC_UART0->LCR = 3;
	
	
		LPC_TIM0->PR = 0;
		LPC_TIM0->MCR = 3;
		LPC_TIM0->MR0 = 12500000;
		LPC_TIM0->TCR = 1;
		
		//RTC
		LPC_RTC->CCR = 1;
		LPC_RTC->ILR = 1;
		LPC_RTC->CIIR = 1;
	
		
		NVIC_EnableIRQ(TIMER0_IRQn);
		NVIC_EnableIRQ(RTC_IRQn);
		
		while(1)
		{

		}
	
	return 0;
}
