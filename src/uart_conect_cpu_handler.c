

/*
	用于处理与蓝牙之间的串口通信
	串口为GD32的串口1，9600，8N1

*/

#include "includes.h"
#include "string.h"




/*
	串口数据接收中断：
		前提：每一帧都是7个字节。
		队列中保存帧头，有后面的数据和校验和（共7个字节）
*/
void Com_Cpu_Rne_Int_Handle(void)
{
	uint8_t dat;

	dat = (uint8_t)usart_data_receive(EVAL_COM1);//(USART3);  
		
	Uart_Tx(DEBUG_COM_NUM, dat);   //串口0的数据直接发给串口1
}


