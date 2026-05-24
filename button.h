
#include "delay.h"
#include "sys.h"

#ifndef BUTTON_H_
#define BUTTON_H_

#define LED0 PBout(1)
#define RELAY PCout(13)
#define BEEP PAout(0)


#define key3  PBin(12)   	
#define key2  PBin(13)	 
#define key1  PBin(14)	 
#define YW  PCin(14)
#define FS  PCout(15)
//#define xx 10
//#define yy 11
//#define add 12 
//#define sub 13 
//#define enter 14 
//#define back 15 

////PA12 -PA15不用 PB3/4不用
////*****************按键接口定义区******************
//#define C4_port GPIOB
//#define C3_port GPIOB
//#define C2_port GPIOB
//#define C1_port GPIOB  
//#define R4_port GPIOB
//#define R3_port GPIOA
//#define R2_port GPIOA
//#define R1_port GPIOA

//#define C4_pin GPIO_Pin_12
//#define C3_pin GPIO_Pin_13
//#define C2_pin GPIO_Pin_14
//#define C1_pin GPIO_Pin_15
//#define R4_pin GPIO_Pin_3
//#define R3_pin GPIO_Pin_15
//#define R2_pin GPIO_Pin_11
//#define R1_pin GPIO_Pin_8
////*****************按键接口定义区******************

//#define key1_1 GPIO_SetBits(C1_port, C1_pin)
//#define key1_0 GPIO_ResetBits(C1_port, C1_pin)

//#define key2_1 GPIO_SetBits(C2_port, C2_pin)
//#define key2_0 GPIO_ResetBits(C2_port, C2_pin)

//#define key3_1 GPIO_SetBits(C3_port, C3_pin)
//#define key3_0 GPIO_ResetBits(C3_port, C3_pin)

//#define key4_1 GPIO_SetBits(C4_port, C4_pin)
//#define key4_0 GPIO_ResetBits(C4_port, C4_pin)

//#define key5_1 GPIO_SetBits(R1_port, R1_pin)
//#define key5_0 GPIO_ResetBits(R1_port, R1_pin)

//#define key6_1 GPIO_SetBits(R2_port, R2_pin)
//#define key6_0 GPIO_ResetBits(R2_port, R2_pin)

//#define key7_1 GPIO_SetBits(R3_port, R3_pin)
//#define key7_0 GPIO_ResetBits(R3_port, R3_pin)

//#define key8_1 GPIO_SetBits(R4_port, R4_pin)
//#define key8_0 GPIO_ResetBits(R4_port, R4_pin)

//#define key1 GPIO_ReadInputDataBit(C1_port,C1_pin)
//#define key2 GPIO_ReadInputDataBit(C2_port,C2_pin)
//#define key3 GPIO_ReadInputDataBit(C3_port,C3_pin)
//#define key4 GPIO_ReadInputDataBit(C4_port,C4_pin)
//#define key5 GPIO_ReadInputDataBit(R1_port,R1_pin)
//#define key6 GPIO_ReadInputDataBit(R2_port,R2_pin)
//#define key7 GPIO_ReadInputDataBit(R3_port,R3_pin)
//#define key8 GPIO_ReadInputDataBit(R4_port,R4_pin)   //按键相关操作定义



void KEY_Init(void);  //调用这一个函数初始化
//void Key_assignment(unsigned char z);
//u8 Key_Scan(void);

//void key_LowOutPutConfig(void);
//void key_HighOutPutConfig(void);

#endif /* BUTTON_H_ */
