
#ifndef __TASK_CFG_H__
#define __TASK_CFG_H__


#include <gd32f10x.h>

//任务由main函数调用。

//使用宏定义任务的间隔时间，任务的定时由systick.c中处理

//任务调用的格式 void fun(void)

#define TASK_MAX 16   //目前最大的任务数

#define TASK1_TICKS_INTERVAL 10   //任务1，上电按钮扫描 10ms。
#define TASK2_TICKS_INTERVAL 1   //任务2 激光的pwm设置，10ms一次
//#define TASK3_TICKS_INTERVAL 10   //任务3，空
#define TASK4_TICKS_INTERVAL 1000   //任务4，温湿度读取任务，1000ms调用一次
#define TASK5_TICKS_INTERVAL 50   //任务5，系统状态灯控制，50ms一次
#define TASK6_TICKS_INTERVAL 500   //任务6，红外开关检测，500ms进入一次,包含红外发射
#define TASK7_TICKS_INTERVAL 500   //任务7，电池电压监控,充电中不检测电压 500ms一次
//#define TASK15_TICKS_INTERVAL 533   //任务5，喂狗，暂定533ms
//#define TASK16_TICKS_INTERVAL 1000   //任务16，1s扫描，工作led闪烁任务.2021-12-01 任务删除

extern uint16_t g_task_id;   //每一个位对应一个任务，为1表示需要启动任务，在任务中清零该位
//2021-09-30增加task_allow,控制定时器，设置任务运行
//extern uint16_t task_allow; //每一个位对应一个任务，为1表示允许定时扫描该任务，关机后，可以将不必要的任务设置为不允许

typedef void(* task_t)(void);
#endif
