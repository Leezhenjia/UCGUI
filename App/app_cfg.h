#ifndef __APP_CFG_H__
#define __APP_CFG_H__

/***************�����������ȼ�*****************/
#define START_TASK_PRIO 4
#define APP_TASK_USER_IF_PRIO 5
#define GUI_TASK_PRIO 63    //������ʾ

/***************����ջ��С(��λΪ OS_STK	)**************/
#define START_TASK_STK_SIZE 80
#define APP_TASK_USER_IF_STK_SIZE 256
#define GUI_TASK_STK_SIZE 256   //todo:���ڲ��Զ�ջ��С

#endif
