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
void fun1()//���˵�
{
OLED_Clear();
	OLED_ShowNum(46,0,1,1,16);
OLED_ShowCHinese(10,0,1);	//����1
OLED_ShowCHinese(28,0,2);	//����1
	
	OLED_ShowNum(100,0,2,1,16);
OLED_ShowCHinese(64,0,1);//����2
OLED_ShowCHinese(82,0,2);//����2
	
	OLED_ShowNum(46,10,3,1,16);
OLED_ShowCHinese(10,10,1);//����3
OLED_ShowCHinese(28,10,2);//����3
	
	OLED_ShowNum(100,10,4,1,16);
OLED_ShowCHinese(64,10,1);//����4
OLED_ShowCHinese(82,10,2);//����4
	
};

void fun2()//����ģʽ
{
OLED_Clear();	
//OLED_ShowCHinese(0,0,5);	//��
//OLED_ShowCHinese(18,0,6);	//��
//OLED_ShowString(36,0,p5,16);
//OLED_ShowString(18,18,p,16);
//OLED_ShowString(36,36,p1,16);
	
//			OLED_ShowCHinese(0,0,0);//��
//		OLED_ShowCHinese(18,0,1);//��
//		OLED_ShowCHinese(36,0,2);//԰
//		OLED_ShowCHinese(54,0,3);//��
//		OLED_ShowCHinese(72,0,4);//��
//		OLED_ShowCHinese(90,0,5);//��
//		OLED_ShowCHinese(108,0,6);//��
		OLED_ShowString(0,0,"set point(  ,  )",16);
		OLED_ShowString(0,3,"A set x",16);
		//OLED_ShowString(8,2,"ZHONGJINGYUAN");  
	 //	OLED_ShowString(20,4,"2014/05/01");  
		OLED_ShowString(0,6,"B set y",16);  
//		OLED_ShowString(63,6,"CODE:",16);    
//OLED_ShowCHinese(0,18,5);	//
//OLED_ShowCHinese(18,18,6);	//��	
	
//OLED_ShowString(5,0,p,8);	//��ʾ��ʼ��	
////OLED_ShowString(u8 x,u8 y, u8 *p,u8 Char_Size);	
////OLED_ShowChar(u8 x,u8 y,u8 chr,u8 Char_Size);	
////	OLED_ShowNum(20,40,2,1,16);
//OLED_ShowString(5,16,p1,8);	//��ʾʵʱ��

////	OLED_ShowNum(20,60,3,1,16);
//OLED_ShowString(5,32,p2,8);	//��ʾ����ʱ��
	
//OLED_ShowString(60,10,p3,8);	//��ʾƫ��
//	
//OLED_ShowString(5,30,p4,8);	//��ʾƫ��	

};

void fun3()//x,y����
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
//	TIM_SetCompare1(TIM1,setcompare1);	//x�Ķ��
//	TIM_SetCompare1(TIM1,setcompare2);	//y�Ķ��	

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

        {0,1,1,0,fun1},//��һ�㣬��ʾ����Ŀ��Ϣ����ͼ����ʾ��������������

        {1,1,0,2,fun2},//��һ�㣬��ʾ��Ŀ��Ϣ����ͼ����ʾ����������������
				

        {2,3,1,4,fun3},//��һ�㣬��ʾ��Ŀ��Ϣ��ͼ����ʾ������������������                     

        {4,4,2,5,fun4},//��һ�㣬��ʾ��Ŀ��Ϣ��ͼ����ʾ���������������ء�
			  {4,1,1,14,fun5},//��һ�㣬��ʾ��Ŀ��Ϣ��ͼ����ʾ���������������ء�
				
				{5,6,5,1,fun6},//��2�㣬��ʾmenu1-1
				{6,7,2,9,fun7},//��һ�㣬��ʾ��Ŀ��Ϣ��ͼ����ʾ���������������ء�
				{7,8,2,10,fun8},//��һ�㣬��ʾ��Ŀ��Ϣ��ͼ����ʾ���������������ء�
				{8,5,2,11,fun9},//��һ�㣬��ʾ��Ŀ��Ϣ��ͼ����ʾ���������������ء�

				{9,7,2,5,fun10},//��һ�㣬��ʾ��Ŀ��Ϣ��ͼ����ʾ���������������ء�
				{10,1,1,5,fun11},//��һ�㣬��ʾ��Ŀ��Ϣ��ͼ����ʾ���������������ء�
				
				{11,1,1,5,fun12},//��һ�㣬��ʾ��Ŀ��Ϣ��ͼ����ʾ���������������ء�				
				{12,1,1,2,fun13},//��һ�㣬��ʾ��Ŀ��Ϣ��ͼ����ʾ���������������ء�
				{13,1,1,3,fun14},//��һ�㣬��ʾ��Ŀ��Ϣ��ͼ����ʾ���������������ء�
				{14,1,1,3,fun15},//��һ�㣬��ʾ��Ŀ��Ϣ��ͼ����ʾ���������������ء�
                                                                                   
			 };	
