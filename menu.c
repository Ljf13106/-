#include "stm32f10x.h"
#include "key.h"
#include "delay.h"
#include "menu.h"
#include "oled.h"
#include "math.h"
char *p="start(  ,  )";
char *p1="real(  ,  )";
char *p2="time    s";
char *p3="error   %";
char *p4="set x";
char *p6="set y";
char *p5="(  ,  )";

extern t;
extern x1;
extern y1;
extern Flag;
vu8 n;
void fun1()//主菜单
{
OLED_Clear();
	OLED_ShowNum(46,0,1,1,16);
OLED_ShowCHinese(10,0,1);	//功能1
OLED_ShowCHinese(28,0,2);	//功能1
	
	OLED_ShowNum(100,0,2,1,16);
OLED_ShowCHinese(64,0,1);//功能2
OLED_ShowCHinese(82,0,2);//功能2
	
	OLED_ShowNum(46,10,3,1,16);
OLED_ShowCHinese(10,10,1);//功能3
OLED_ShowCHinese(28,10,2);//功能3
	
	OLED_ShowNum(100,10,4,1,16);
OLED_ShowCHinese(64,10,1);//功能4
OLED_ShowCHinese(82,10,2);//功能4
	
};

void fun2()//定点模式
{
OLED_Clear();	
//OLED_ShowCHinese(0,0,5);	//结
//OLED_ShowCHinese(18,0,6);	//束
//OLED_ShowString(36,0,p5,16);
//OLED_ShowString(18,18,p,16);
//OLED_ShowString(36,36,p1,16);
	
//			OLED_ShowCHinese(0,0,0);//中
//		OLED_ShowCHinese(18,0,1);//景
//		OLED_ShowCHinese(36,0,2);//园
//		OLED_ShowCHinese(54,0,3);//电
//		OLED_ShowCHinese(72,0,4);//子
//		OLED_ShowCHinese(90,0,5);//科
//		OLED_ShowCHinese(108,0,6);//技
		OLED_ShowString(0,0,"set point(  ,  )",16);
		OLED_ShowString(0,3,"A set x",16);
		//OLED_ShowString(8,2,"ZHONGJINGYUAN");  
	 //	OLED_ShowString(20,4,"2014/05/01");  
		OLED_ShowString(0,6,"B set y",16);  
//		OLED_ShowString(63,6,"CODE:",16);    
//OLED_ShowCHinese(0,18,5);	//
//OLED_ShowCHinese(18,18,6);	//束	
	
//OLED_ShowString(5,0,p,8);	//显示初始点	
////OLED_ShowString(u8 x,u8 y, u8 *p,u8 Char_Size);	
////OLED_ShowChar(u8 x,u8 y,u8 chr,u8 Char_Size);	
////	OLED_ShowNum(20,40,2,1,16);
//OLED_ShowString(5,16,p1,8);	//显示实时点

////	OLED_ShowNum(20,60,3,1,16);
//OLED_ShowString(5,32,p2,8);	//显示运行时间
	
//OLED_ShowString(60,10,p3,8);	//显示偏差
//	
//OLED_ShowString(5,30,p4,8);	//显示偏差	

};

void fun3()//x,y设置
{   
	  int num_t,i=0;
	  OLED_Clear();
		OLED_ShowString(0,0,"A set x;B set y",16);
		OLED_ShowString(0,3,"set point(  ,  )",16);
		OLED_ShowString(0,6,"C Finsh",16);
	while(Flag)
	{
    t=KEY_SCAN();
	  switch(t)			
		{
			case 1:
			{
			 x1=x1+1;
			OLED_ShowString(0,3,"set point(  ,  )",16);
			OLED_ShowNum(80,3,x1,2,16);
			OLED_ShowNum(100,3,y1,2,16);				
        if(x1>=50)
        x1=0;					
			}
				break;
			case 4:
			{
			y1=y1+1;
			OLED_ShowString(0,3,"set point(  ,  )",16);
			OLED_ShowNum(80,3,x1,2,16);
			OLED_ShowNum(100,3,y1,2,16);
        if(y1>=50)
        y1=0;			
			}				
				break;
			case 9:
			{
			 Flag=0;
	     OLED_Clear();
		 	OLED_ShowString(0,3,"set point(  ,  )",16);				
			 OLED_ShowNum(80,3,x1,2,16);
			 OLED_ShowNum(100,3,y1,2,16);	
		  OLED_ShowString(0,6,"8 start",16);	
		  OLED_ShowString(70,6,"D trturn",16);				
			}				
				break;
			case 2:
			{
			
			
			}							
				break;
			default:break;
		}
		
	}
		
		
		
		
		
};

void fun4()
{
float angle_x, angle_y;
float dx, dy;
float time1,time2;
int setcompare1,setcompare2;	
	dx=x1;
	dy=y1;
int arr=1999;
angle_x=atan2(dx,1);
angle_y=atan2(dy,sqrt(dx*dx+dy*dy));
	time1=(angle_x+45)*1/9;
	time2=(angle_y+45)*1/9;	
	setcompare1=((arr+1)-((arr+1)*time1/20));
	setcompare2=((arr+1)-((arr+1)*time2/20));	
//	TIM_SetCompare1(TIM1,setcompare1);	//x的舵机
//	TIM_SetCompare1(TIM1,setcompare2);	//y的舵机	

};

void fun5()
{
		
};

void fun6()
{

	

	

};

void fun7()
{

};

void fun8()
{
									

};

void fun9()
{
					
};

void fun10()
{

};

void fun11()
{
				
};

void fun12()
{
				
};

void fun13()
{

};

void fun14()
{

 										
};

void fun15()
{

 										
};




key_table code_table[30]=
{

        {0,1,1,0,fun1},//第一层，显示【项目信息】、图形显示、计算器、返回

        {1,1,0,2,fun2},//第一层，显示项目信息、【图形显示】、计算器、返回
				

        {2,3,1,4,fun3},//第一层，显示项目信息、图形显示、【计算器】、返回                     

        {4,4,2,5,fun4},//第一层，显示项目信息、图形显示、计算器、【返回】
			  {4,1,1,14,fun5},//第一层，显示项目信息、图形显示、计算器、【返回】
				
				{5,6,5,1,fun6},//第2层，显示menu1-1
				{6,7,2,9,fun7},//第一层，显示项目信息、图形显示、计算器、【返回】
				{7,8,2,10,fun8},//第一层，显示项目信息、图形显示、计算器、【返回】
				{8,5,2,11,fun9},//第一层，显示项目信息、图形显示、计算器、【返回】

				{9,7,2,5,fun10},//第一层，显示项目信息、图形显示、计算器、【返回】
				{10,1,1,5,fun11},//第一层，显示项目信息、图形显示、计算器、【返回】
				
				{11,1,1,5,fun12},//第一层，显示项目信息、图形显示、计算器、【返回】				
				{12,1,1,2,fun13},//第一层，显示项目信息、图形显示、计算器、【返回】
				{13,1,1,3,fun14},//第一层，显示项目信息、图形显示、计算器、【返回】
				{14,1,1,3,fun15},//第一层，显示项目信息、图形显示、计算器、【返回】
                                                                                   
			 };	
