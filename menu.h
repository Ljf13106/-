#include "stm32f10x.h"
#include "key.h"
#include "delay.h"
#include "oled.h"

typedef struct
   {
     unsigned char current_operation_index;
     unsigned up;//上键
     unsigned down;//下键
     unsigned enter;//确认键
     void (*current_operation)();
     } key_table;

extern key_table code_table[30];
		 