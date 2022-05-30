#include "stm32f10x.h"
#include "delay.h"
#include "sys.h"
#include "oled.h"
#include "bmp.h"
#include "led.h"
#include "key.h"
#include "menu.h"
#include "pwm.h"
 int t,x1,y1,Flag=1;
 
 int main(void)
 {	
	u16 led0pwmval=0; 
  int func_index;   
	u8 dir=1;	
	delay_init();	    	 //延时函数初始化	  
	LED_Init();		  	//初始化与LED连接的硬件接口
	TIM1_PWM_Init(1999,719);//PWM频率=72000000/（719+1）/（1999+1）=50hz=20ms
	OLED_Init();			//初始化OLED  
	key_init();
	OLED_Clear(); 
	while(1)
	{
//		OLED_ShowString(0,3,"set point(  ,  )",16);
//			OLED_ShowNum(100,3,12,2,16);
//			OLED_ShowNum(80,3,12,2,16);
		t=KEY_SCAN();
		switch(t)
		{
		
       case 13: 
			{
				func_index=code_table[func_index].up;    //向上翻
		    code_table[func_index].current_operation();//执行当前操作函数				
			}
    	 break;
	 
			case 14:
      {
		  	func_index=code_table[func_index].enter;//回车
				code_table[func_index].current_operation();//执行当前操作函数
			}
			break;  
		  default: break;		
		}
	}
}
//	TIM1_PWM_Init(899,1599);//不分频。PWM频率=72000/(899+1)=80Khz  
//   	while(1)
//	{
////		if(dir)led0pwmval++;
////		else led0pwmval--;	 
//// 		if(led0pwmval>300)dir=0;
////		if(led0pwmval==0)dir=1;
// 		delay_ms(50);	
////LED1=0;		
////		TIM_SetCompare1(TIM1,45);	
//// 		delay_ms(500);
////LED1=1;
//		TIM_SetCompare1(TIM1,112);			
//	} 
//}
//		OLED_ShowCHinese(0,0,0);//中
//		OLED_ShowCHinese(18,0,1);//景
//		OLED_ShowCHinese(36,0,2);//园
//		OLED_ShowCHinese(54,0,3);//电
//		OLED_ShowCHinese(72,0,4);//子
		
//		OLED_ShowCHinese(54,36,3);//电
//		OLED_ShowCHinese(72,36,4);//子
//		OLED_ShowCHinese(90,0,5);//科
//		OLED_ShowCHinese(108,0,6);//技
