#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "PWM.h"
#include "Key.h"
#include "Delay.h"
uint16_t num;

int main(){
	PWM_Init();
	OLED_Init();
	OLED_ShowNum(1,1,67,5);
	OLED_ShowNum(2,1,num,5);
	PWM_SetCompare1(50);
	
	while(1)
		{
		if(num>800){
			
			num = 0;			
			
			
		}
		//ehuf
		
		OLED_ShowNum(2,1,num*0.45,5);
	
	
	}
}
