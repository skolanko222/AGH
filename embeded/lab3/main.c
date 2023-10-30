#include "Driver_USART.h"
#include "LPC17xx.h"                    // Device header
#include "string.h" 

volatile uint32_t msTicks = 0;

extern ARM_DRIVER_USART Driver_USART3;
extern ARM_DRIVER_USART Driver_USART1;
char                   cmd;

void delay(int t)
{
	msTicks = 0;
	while(t> msTicks);
}
void SysTick_Handler(void)
{
	msTicks++;
}
void initUsart(ARM_DRIVER_USART * temp)
{
	temp->Initialize(NULL);
	temp->PowerControl(ARM_POWER_FULL);
	temp->Control(ARM_USART_MODE_ASYNCHRONOUS |ARM_USART_DATA_BITS_8 | ARM_USART_PARITY_NONE | ARM_USART_STOP_BITS_1 | ARM_USART_FLOW_CONTROL_NONE, 4800);
	temp->Control (ARM_USART_CONTROL_TX, 1);    
	temp->Control (ARM_USART_CONTROL_RX, 1);
	
}



int main() {
	static ARM_DRIVER_USART * USARTdrv3 = &Driver_USART3;
	static ARM_DRIVER_USART * USARTdrv1 = &Driver_USART1;
	//initUsart(USARTdrv3);
	//initUsart(USARTdrv1);
	
	SysTick_Config(SystemCoreClock / 100); //10ms
		/*
		USART0
		PIN_Configure(0,2,1,2,0);
		PIN_Configure(0,3,1,2,0);
	
		// USARTdrv1->Receive(&cmd,1);
		// delay(100);

		LPC_UART0->LCR = 3 | (1<<7);
		LPC_UART0->DLL = 27; // dzielnik peryferyjny 2, 256 max
		LPC_UART0->DLM = 0; // tu naddatek x*256
		
		
		LPC_UART0->LCR = 3;*/
		LPC_SC->PCONP |= 1<<24;
		
		PIN_Configure(0,2,1,2,0);
		PIN_Configure(0,3,1,2,0);
	
		// USARTdrv1->Receive(&cmd,1);
		// delay(100);

		LPC_UART0->LCR = 3 | (1<<7);
		LPC_UART0->DLL = 27; // dzielnik peryferyjny 2, 256 max
		LPC_UART0->DLM = 0; // tu naddatek x*256
		
		
		LPC_UART0->LCR = 3;
		
		// USARTdrv3->Send("\nHello World!", 12);
		// USARTdrv1->Send("\nHello World!", 12);
	const char  napis[] = "123456789012345678912345678123456712345\n";
		char reciveByte;
		while(1)
		{
			
			if((LPC_UART0->LSR & 1) == 1)
			{
				reciveByte = LPC_UART0->RBR;
				LPC_UART0->THR = reciveByte;
			}
			
			
			
			/*for(int i = 0; i < sizeof(napis) ; i++){
				
				if(LPC_UART0->LSR >> 6 == 1){
				LPC_UART0->THR = napis[i];
				}
				else{
					i--;
				}
			}
			delay(100);*/
		}
	
	return 0;
}
