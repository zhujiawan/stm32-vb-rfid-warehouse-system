#include "button.h"
#include "stm32f10x.h"
#include "delay.h"

extern u8 pass_word_state;	//输密码时判断是输入了第几位
u8 Key_Data=0;  //按键按下的数据
u8 Key_flag=0;  //按键按下标志位，区分按键按下一次的


void KEY_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOC, ENABLE);//开启时钟
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_Disable, ENABLE); //改变指定管脚的映射完全禁用（JTAG+SW-DP）
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);//改变指定管脚的映射，JTAG-DP 禁用 + SW-DP 使能
		
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;	//LED
	GPIO_InitStructure.GPIO_Pin =GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	LED0 = 0;
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;	//LED
	GPIO_InitStructure.GPIO_Pin =GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	FS = 1;
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;	//蜂鸣器（beep） 低电平触发
	GPIO_InitStructure.GPIO_Pin =GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	BEEP=1;
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;	//继电器（relay） 高电平触发
	GPIO_InitStructure.GPIO_Pin =GPIO_Pin_13;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	RELAY=0;
	
	
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_12;//PA0
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //设置成上拉输入
 	GPIO_Init(GPIOB, &GPIO_InitStructure);//初始化GPIOA0
	
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_13;//PA1
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //设置成上拉输入
 	GPIO_Init(GPIOB, &GPIO_InitStructure);//初始化GPIOA1
 
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_14;//PA2
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //设置成上拉输入 
	GPIO_Init(GPIOB, &GPIO_InitStructure);//初始化GPIOA.2
	
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_14;//PA2
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //设置成上拉输入 
	GPIO_Init(GPIOC, &GPIO_InitStructure);//初始化GPIOA.2
}

