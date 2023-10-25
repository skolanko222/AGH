#include "Board_Buttons.h"
#include "Board_LED.h"
#include "Board_Joystick.h"
#include "LPC17xx.h"
#include "Driver_USART.h"

void delay(int n ){
	for(int i = 0; i < n;i++){
		if (Buttons_GetState() == 2) {
			LED_Off(3);
			LED_Off(2);
			LED_Off(11);
		}
		else if(Joystick_GetState() == 8 )
			LED_On(2);
		
		else if(Joystick_GetState() == 16 )
			LED_On(3);
		else if(Joystick_GetState() == 4 )
			LED_On(11);
			
	}
}
volatile uint32_t msTicks = 0; 

void delay2(int t)
{
	msTicks = 0;
	while(t > msTicks);
}
void SysTick_Handler(void)  {                               //SysTick interrupt Handler.  
msTicks++;                                              
 //See startup file startup_LPC17xx.s for SysTick vector 
}

extern ARM_DRIVER_USART Driver_USART3;

int main(){
	static ARM_DRIVER_USART * USARTdrv = &Driver_USART3;
	USARTdrv->Initialize(NULL);
	USARTdrv->PowerControl(ARM_POWER_FULL);
	
	USARTdrv->Control(ARM_USART_MODE_ASYNCHRONOUS | ARM_USART_DATA_BITS_8 | ARM_USART_PARITY_NONE | ARM_USART_STOP_BITS_1 | ARM_USART_FLOW_CONTROL_NONE, 4800);
	
	USARTdrv->Control (ARM_USART_CONTROL_TX, 1);    
	USARTdrv->Control (ARM_USART_CONTROL_RX, 1);     
	USARTdrv->Send("\nPress Enter to receive a message", 34);
	LED_Initialize();
	uint32_t returnCode;   
	returnCode = SysTick_Config(1000000);      // Configure SysTick to generate an interrupt every millisecond   
	if (returnCode != 0)  {                                   //Check return code for errors    
		// Error Handling   
		}    
	while(1)
	{
		
		LED_Off(2);
		delay2(100);
		LED_On(2);
		delay2(100);
		
	};

	/*LED_Initialize();
	Buttons_Initialize();
	LED_Off(1);
	LED_Off(2);
	LED_Off(3);
	while(1){
		LED_On(0);
		LED_Off(1);
		delay(150000);
		LED_On(1);
		LED_Off(0);
		delay(150000);
	}*/
	LED_Uninitialize();
	return 0;
}
