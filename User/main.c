#include "includes.h"

OS_STK start_task_stk[START_TASK_STK_SIZE]; 

/*
 *	������	:	SysTick_init
 *	����	:	���� SysTick ��ʱ��
 *	����	:	��
 *	���	:	��
 */

void SysTick_init(void)
{
	SysTick_Config(SystemCoreClock/OS_TICKS_PER_SEC);	//��ʼ����ʹ��	SysTick	��ʱ��SystemFrequency
}

/*
 *	������	:	BSPInit
 *	����	:	ʱ�ӳ�ʼ��,Ӳ����ʼ��
 *	����	:	��
 *	���	:	��
 */
 
static void BSP_init(void)
{
	SystemInit();		//����ϵͳʱ��Ϊ72M
	SysTick_init();;	//��ʼ����ʹ�� Systick ��ʱ��
    
    GUI_Init();         //GUI��ʼ��
}


int main(void)
{		
    BSP_init(); //�弶Ӳ����ʼ��
    OSInit();  //ϵͳ��ʼ��
    
#if OS_STK_GROWTH == 1  //����Ӧջ������������
	OSTaskCreate(Task_Start, (void *)0, &start_task_stk[START_TASK_STK_SIZE - 1], START_TASK_PRIO);
#else 
	OSTaskCreate(Task_Start, (void *)0, &start_task_stk[0], START_TASK_PRIO);
#endif
    
    OSStart();  //��ʼ���������
    return 0;	
}





/* ------------------------------------------end of file---------------------------------------- */

