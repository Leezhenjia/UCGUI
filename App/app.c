#include "includes.h"

static OS_STK AppTaskUserIFStk[APP_TASK_USER_IF_STK_SIZE];//ucGUI的任务堆栈
static OS_STK GUIStk[GUI_TASK_STK_SIZE];//GUI

static void AppTaskUserIF(void *p_arg);
static void GUITask(void *p_arg);
extern void MainTask(void);

void Task_Start(void *p_arg)
{
	(void)p_arg;	//规避编译器警告
    
    
    //开始任务
    OSTaskCreateExt(AppTaskUserIF, 
    (void *)0, //pdata
    (OS_STK *)&AppTaskUserIFStk[APP_TASK_USER_IF_STK_SIZE-1], //ptos
    APP_TASK_USER_IF_PRIO, //prio
    APP_TASK_USER_IF_PRIO, //id
    (OS_STK *)&AppTaskUserIFStk[0], //pbos
    APP_TASK_USER_IF_STK_SIZE, //stk_size
    (void *)0, //pext
    OS_TASK_OPT_STK_CHK|OS_TASK_OPT_STK_CLR);//opt
    
    //GUI任务
    OSTaskCreateExt(GUITask, 
    (void *)0, //pdata
    (OS_STK *)&GUIStk[GUI_TASK_STK_SIZE-1], //ptos
    GUI_TASK_PRIO, //prio
    GUI_TASK_PRIO, //id
    (OS_STK *)&GUIStk[0], //pbos
    GUI_TASK_STK_SIZE, //stk_size
    (void *)0, //pext
    OS_TASK_OPT_STK_CHK|OS_TASK_OPT_STK_CLR);//opt
    
	OSTaskDel(OS_PRIO_SELF);   //删除起始任务
}

static void AppTaskUserIF(void *p_arg)
{
    while(1)
    {
        //
    }
}

static void GUITask(void *p_arg)
{
    while(1)
    {
        MainTask();//界面显示
    }
}