#include "includes.h"

OS_STK start_task_stk[START_TASK_STK_SIZE]; 

/*
 *	函数名	:	SysTick_init
 *	描述	:	配置 SysTick 定时器
 *	输入	:	无
 *	输出	:	无
 */

void SysTick_init(void)
{
	SysTick_Config(SystemCoreClock/OS_TICKS_PER_SEC);	//初始化并使能	SysTick	定时器SystemFrequency
}

/*
 *	函数名	:	BSPInit
 *	描述	:	时钟初始化,硬件初始化
 *	输入	:	无
 *	输出	:	无
 */
 
static void BSP_init(void)
{
	SystemInit();		//配置系统时钟为72M
	SysTick_init();;	//初始化并使能 Systick 定时器
    
    GUI_Init();         //GUI初始化
}


int main(void)
{		
    BSP_init(); //板级硬件初始化
    OSInit();  //系统初始化
    
#if OS_STK_GROWTH == 1  //自适应栈向上向下生长
	OSTaskCreate(Task_Start, (void *)0, &start_task_stk[START_TASK_STK_SIZE - 1], START_TASK_PRIO);
#else 
	OSTaskCreate(Task_Start, (void *)0, &start_task_stk[0], START_TASK_PRIO);
#endif
    
    OSStart();  //开始多任务调度
    return 0;	
}





/* ------------------------------------------end of file---------------------------------------- */

