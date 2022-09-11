

/*
	按键开关机：2022-07-22
	根据原理图，按键可以使单片机通电，在电池供电的情况下
	
	在外接usb供电的情况下，还是要考虑开机关机的问题
	
*/


#include "includes.h"


const char* g_build_time_str = "Buildtime :"__DATE__" "__TIME__;   //获得编译时间
uint16_t g_task_id;   //每一个位对应一个任务，为1表示需要启动任务，在任务中清零该位



////800ms 看门狗
//static void iwdog_init(void)
//{
//	fwdgt_write_enable();
//	fwdgt_config(0xfff,FWDGT_PSC_DIV8);    //设置分配系数,最长819ms
//	
//	fwdgt_enable(); //使能看门狗
//}


//static  void iwdog_feed(void)
//{
////	if(mcu_reboot)  //设置mcu重启，不喂狗。2021-12-17增加
////		return ;
//	fwdgt_counter_reload();
//}





void PowerManager_init(void)
{
	//1.时钟使能
	rcu_periph_clock_enable(RCU_GPIOB);	
	rcu_periph_clock_enable(RCU_GPIOC);	
	
	//2.外设3.3v控制引脚
	gpio_init(GPIOB, GPIO_MODE_OUT_PP, GPIO_OSPEED_2MHZ, GPIO_PIN_13 | GPIO_PIN_14);	 //外设供电引脚
	gpio_bit_set(GPIOB, GPIO_PIN_13);  //通电无电
	gpio_bit_reset(GPIOB, GPIO_PIN_14);  //5v不输出
	
	//3.单片机电源控制引脚，高有效
	gpio_bit_set(GPIOC, GPIO_PIN_3);  //单片机电源引脚使能，单片机才有电
	gpio_init(GPIOC, GPIO_MODE_OUT_PP, GPIO_OSPEED_2MHZ, GPIO_PIN_3);	 //单片机电源供电引脚
	

	
	//7 升压5v输出使能，时钟使能
//	rcu_periph_clock_enable(RCU_GPIOB);			
	gpio_init(GPIOB, GPIO_MODE_OUT_PP, GPIO_OSPEED_2MHZ, GPIO_PIN_15);	
	gpio_bit_reset(GPIOB, GPIO_PIN_15);  //5v不输出
	


}




static void BoardInit(void)
{
	
	//1. 中断分组初始化
	//NVIC_SetPriorityGrouping(4);  //均为4个等级
	nvic_priority_group_set(NVIC_PRIGROUP_PRE2_SUB2);
		
	
	//4.systick 初始化
	SystickConfig();
	
	//5.串口初始化
	//#define DEBUG_COM_NUM 0   //调试串口号
	//#define TOCPU_COM_NUM 1   //与cpu通信的串口
	gd_eval_com_init(DEBUG_COM_NUM,115200);  //用于调试
	gd_eval_com_init(TOCPU_COM_NUM,9600);  //用于与蓝牙模块通信
	
	PowerManager_init();

}


//void ulp_deepsleepmode_enable(void)
//{
//	nvic_priority_group_set(NVIC_PRIGROUP_PRE2_SUB2);
//	btn_init_irq();    //只初始化按键引脚为中断引脚，用于cpu唤醒
//	pmu_to_deepsleepmode(PMU_LDO_LOWPOWER,WFI_CMD);
//	SystemInit();
//	SystemCoreClockUpdate();
//}


int main(void)
{


	//1. 初始化
	BoardInit();

	printf("%s\r\n", g_build_time_str);
	printf("BoardInit done! 2022-09-11\r\n");
	
	
	while(1)
	{
			
	}
}


