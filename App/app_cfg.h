#ifndef __APP_CFG_H__
#define __APP_CFG_H__

/***************设置任务优先级*****************/
#define START_TASK_PRIO 4
#define APP_TASK_USER_IF_PRIO 5
#define GUI_TASK_PRIO 63    //界面显示

/***************设置栈大小(单位为 OS_STK	)**************/
#define START_TASK_STK_SIZE 80
#define APP_TASK_USER_IF_STK_SIZE 256
#define GUI_TASK_STK_SIZE 256   //todo:后期测试堆栈大小

#endif
