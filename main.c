//头文件
#include "stm32f10x.h"
#include "delay.h"
#include "sys.h"
#include "button.h"
#include "lcd12864.h"
#include "timer.h"
#include "usart2.h"
#include "rc522.h"
#include "usart.h"
#include "dht11.h"
#include "mlx90614.h"
#include "adc.h"
void num2char(uint8_t *str, float number, u8 g, u8 l);
extern u8 Key_flag; 	//按键按下标志位，区分按键按下一次的
u16 zhiwen_ID=0;  	//刷卡后存放指纹ID号
u8 state=1;  		//显示界面状态标志  初始5为第一解锁界面
u8 key;  			//按键值
unsigned char string1[5]=" ";
unsigned char string2[5]=" ";
unsigned char string3[5]=" ";
unsigned char string4[5]=" ";
u8 temp_x;		    //温度
u8 humi_x;	      //湿度  	
unsigned int humi;        	//湿度
unsigned int temp1;		      //温度
static char table[]={'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int mq2_vol,mq1_vol;
int main(void)
{	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置系统中断优先级分组2
	SystemInit();		// 配置系统时钟为72M 
	delay_init();    	//延时初始化	
	uart_init(9600);	//串口初始化为9600
	RC522_Init();       //初始化射频卡模块
	usart2_init(usart2_baund);//初始化串口2 与指纹通信用，同时初始化定时器
	Lcd_Init();	
	KEY_Init();
	DHT11_Init();
	  ADCx_Init();  
	RELAY=1;	//关继电器
	while(1)
        {	
				 if(!key1){   //菜单按键
				  delay_ms(10);
					if(!key1){  
					state=3;
					}	
				}
				 if(!key2){  //撤销按键
				  delay_ms(10);
					if(!key2){  
					state=2;
					}	
				}
				 if(!key3){//注册按键
				  delay_ms(10);
					if(!key3){  
					state=1;
					}	
				}
				if(state==1)  //菜单界面
				{
			  

				DHT11_Read_Data(&temp_x,&humi_x);//获取温湿度函数
        temp1=temp_x;
	      humi=humi_x;
				
				printf("D");
				delay_ms(90);
				sprintf(string1,"%d%c",temp1,'%');  
				sprintf(string2,"%d%c",humi, '%');
				
				printf((char *)string1);	//发送温度给上位机					
				delay_ms(90);
				printf("M");
				delay_ms(90);
        printf((char *)string2);  //发送湿度给上位机	
        delay_ms(90);
 
				LCD_Display_Words(0,0,"                ");
				LCD_Display_Words(1,0,"    欢迎使用    ");
				LCD_Display_Words(2,0,"智能仓库管理系统");
				LCD_Display_Words(3,0,"                ");
				RC522_Hande3();
			  
				if(CKJS2==2)
				{BEEP=0;FS=0;}
				else
				{BEEP=1;FS=1;}	
				
				}
				if(state==2) //撤销界面
				{
				LCD_Display_Words(0,0,"                ");
				LCD_Display_Words(1,0,"    撤销界面    ");
				LCD_Display_Words(2,0,"                ");
				LCD_Display_Words(3,0,"                ");
			  RC522_Hande4();
				}
				if(state==3)//注册界面
				{
				LCD_Display_Words(0,0,"                ");
				LCD_Display_Words(1,0,"    注册界面    ");
				LCD_Display_Words(2,0,"                ");
				LCD_Display_Words(3,0,"                ");
				RC522_Hande2(); 
				}	
				  CKJS=0;			
        }
	   

}

void num2char(uint8_t *str, float number, u8 g, u8 l)  //浮点数转字符
{
    u8 i;
    int temp = number/1;
    float t2 = 0.0;
    for (i = 1; i<=g; i++)
    {
        if (temp==0)
            str[g-i] = table[0];
        else
            str[g-i] = table[temp%10];
        temp = temp/10;
    }
    *(str+g) = ' ';
    temp = 0;
    t2 = number;
    for(i=1; i<=l; i++)
    {
        temp = t2*10;
        str[g+i] = table[temp%10];
        t2 = t2*10;
    }
    *(str+g+l+1) = '\0';
}
