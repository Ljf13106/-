#include "stm32f10x.h"
#include "key.h"
#include "delay.h"
#include "oled.h"

typedef struct
   {
     unsigned char current_operation_index;
     unsigned up;//�ϼ�
     unsigned down;//�¼�
     unsigned enter;//ȷ�ϼ�
     void (*current_operation)();
     } key_table;

extern key_table code_table[30];
		 