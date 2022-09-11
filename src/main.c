

/*
	�������ػ���2022-07-22
	����ԭ��ͼ����������ʹ��Ƭ��ͨ�磬�ڵ�ع���������
	
	�����usb���������£�����Ҫ���ǿ����ػ�������
	
*/


#include "includes.h"


const char* g_build_time_str = "Buildtime :"__DATE__" "__TIME__;   //��ñ���ʱ��
uint16_t g_task_id;   //ÿһ��λ��Ӧһ������Ϊ1��ʾ��Ҫ���������������������λ



////800ms ���Ź�
//static void iwdog_init(void)
//{
//	fwdgt_write_enable();
//	fwdgt_config(0xfff,FWDGT_PSC_DIV8);    //���÷���ϵ��,�819ms
//	
//	fwdgt_enable(); //ʹ�ܿ��Ź�
//}


//static  void iwdog_feed(void)
//{
////	if(mcu_reboot)  //����mcu��������ι����2021-12-17����
////		return ;
//	fwdgt_counter_reload();
//}





void PowerManager_init(void)
{
	//1.ʱ��ʹ��
	rcu_periph_clock_enable(RCU_GPIOB);	
	rcu_periph_clock_enable(RCU_GPIOC);	
	
	//2.����3.3v��������
	gpio_init(GPIOB, GPIO_MODE_OUT_PP, GPIO_OSPEED_2MHZ, GPIO_PIN_13 | GPIO_PIN_14);	 //���蹩������
	gpio_bit_set(GPIOB, GPIO_PIN_13);  //ͨ���޵�
	gpio_bit_reset(GPIOB, GPIO_PIN_14);  //5v�����
	
	//3.��Ƭ����Դ�������ţ�����Ч
	gpio_bit_set(GPIOC, GPIO_PIN_3);  //��Ƭ����Դ����ʹ�ܣ���Ƭ�����е�
	gpio_init(GPIOC, GPIO_MODE_OUT_PP, GPIO_OSPEED_2MHZ, GPIO_PIN_3);	 //��Ƭ����Դ��������
	

	
	//7 ��ѹ5v���ʹ�ܣ�ʱ��ʹ��
//	rcu_periph_clock_enable(RCU_GPIOB);			
	gpio_init(GPIOB, GPIO_MODE_OUT_PP, GPIO_OSPEED_2MHZ, GPIO_PIN_15);	
	gpio_bit_reset(GPIOB, GPIO_PIN_15);  //5v�����
	


}




static void BoardInit(void)
{
	
	//1. �жϷ����ʼ��
	//NVIC_SetPriorityGrouping(4);  //��Ϊ4���ȼ�
	nvic_priority_group_set(NVIC_PRIGROUP_PRE2_SUB2);
		
	
	//4.systick ��ʼ��
	SystickConfig();
	
	//5.���ڳ�ʼ��
	//#define DEBUG_COM_NUM 0   //���Դ��ں�
	//#define TOCPU_COM_NUM 1   //��cpuͨ�ŵĴ���
	gd_eval_com_init(DEBUG_COM_NUM,115200);  //���ڵ���
	gd_eval_com_init(TOCPU_COM_NUM,9600);  //����������ģ��ͨ��
	
	PowerManager_init();

}


//void ulp_deepsleepmode_enable(void)
//{
//	nvic_priority_group_set(NVIC_PRIGROUP_PRE2_SUB2);
//	btn_init_irq();    //ֻ��ʼ����������Ϊ�ж����ţ�����cpu����
//	pmu_to_deepsleepmode(PMU_LDO_LOWPOWER,WFI_CMD);
//	SystemInit();
//	SystemCoreClockUpdate();
//}


int main(void)
{


	//1. ��ʼ��
	BoardInit();

	printf("%s\r\n", g_build_time_str);
	printf("BoardInit done! 2022-09-11\r\n");
	
	
	while(1)
	{
			
	}
}


