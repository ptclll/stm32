#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "PWM.h"
#include "Key.h"
#include "Delay.h"
#include "LED.h"
uint16_t num;

int main(){
	PWM_Init();
	OLED_Init();
	OLED_Init();
	OLED_ShowNum(1,1,67,5);
	OLED_ShowNum(2,1,num,5);
	PWM_SetCompare1(50);
	void LED1_ON(void);
	while(1)
		{
		if(num>400){
			
			num = 0;			
			 PWM_Stop();
			//PWM_SetCompare1(0);
			Delay_ms(1000);
			 PWM_Start();
			//PWM_SetCompare1(50);
			void LED1_Turn(void);
		}
		//ehuf
		
		OLED_ShowNum(2,1,num*0.45,5);
	
	
	}
}
