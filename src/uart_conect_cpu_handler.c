

/*
	���ڴ���������֮��Ĵ���ͨ��
	����ΪGD32�Ĵ���1��9600��8N1

*/

#include "includes.h"
#include "string.h"




/*
	�������ݽ����жϣ�
		ǰ�᣺ÿһ֡����7���ֽڡ�
		�����б���֡ͷ���к�������ݺ�У��ͣ���7���ֽڣ�
*/
void Com_Cpu_Rne_Int_Handle(void)
{
	uint8_t dat;

	dat = (uint8_t)usart_data_receive(EVAL_COM1);//(USART3);  
		
	Uart_Tx(DEBUG_COM_NUM, dat);   //����0������ֱ�ӷ�������1
}


