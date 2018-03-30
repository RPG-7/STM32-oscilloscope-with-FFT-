#include "stm32f10x_gpio.h"
#include "LCD.h"
#include "stm32f10x.h"
//LCD DATA PC CS PB0 REST PB9 RD PB8 WR PB7 RS PB6
u32 BACK_COLOR=0x0000, POINT_COLOR=0x07E0;
u8  asc2_1608[1520]={
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x00,0x00,0x18,0x18,0x00,0x00,
0x00,0x48,0x6C,0x24,0x12,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x24,0x24,0x24,0x7F,0x12,0x12,0x12,0x7F,0x12,0x12,0x12,0x00,0x00,
0x00,0x00,0x08,0x1C,0x2A,0x2A,0x0A,0x0C,0x18,0x28,0x28,0x2A,0x2A,0x1C,0x08,0x08,
0x00,0x00,0x00,0x22,0x25,0x15,0x15,0x15,0x2A,0x58,0x54,0x54,0x54,0x22,0x00,0x00,
0x00,0x00,0x00,0x0C,0x12,0x12,0x12,0x0A,0x76,0x25,0x29,0x11,0x91,0x6E,0x00,0x00,
0x00,0x06,0x06,0x04,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x40,0x20,0x10,0x10,0x08,0x08,0x08,0x08,0x08,0x08,0x10,0x10,0x20,0x40,0x00,
0x00,0x02,0x04,0x08,0x08,0x10,0x10,0x10,0x10,0x10,0x10,0x08,0x08,0x04,0x02,0x00,
0x00,0x00,0x00,0x00,0x08,0x08,0x6B,0x1C,0x1C,0x6B,0x08,0x08,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x08,0x08,0x08,0x08,0x7F,0x08,0x08,0x08,0x08,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x06,0x04,0x03,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x06,0x00,0x00,
0x00,0x00,0x80,0x40,0x40,0x20,0x20,0x10,0x10,0x08,0x08,0x04,0x04,0x02,0x02,0x00,
0x00,0x00,0x00,0x18,0x24,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x24,0x18,0x00,0x00,
0x00,0x00,0x00,0x08,0x0E,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x3E,0x00,0x00,
0x00,0x00,0x00,0x3C,0x42,0x42,0x42,0x20,0x20,0x10,0x08,0x04,0x42,0x7E,0x00,0x00,
0x00,0x00,0x00,0x3C,0x42,0x42,0x20,0x18,0x20,0x40,0x40,0x42,0x22,0x1C,0x00,0x00,
0x00,0x00,0x00,0x20,0x30,0x28,0x24,0x24,0x22,0x22,0x7E,0x20,0x20,0x78,0x00,0x00,
0x00,0x00,0x00,0x7E,0x02,0x02,0x02,0x1A,0x26,0x40,0x40,0x42,0x22,0x1C,0x00,0x00,
0x00,0x00,0x00,0x38,0x24,0x02,0x02,0x1A,0x26,0x42,0x42,0x42,0x24,0x18,0x00,0x00,
0x00,0x00,0x00,0x7E,0x22,0x22,0x10,0x10,0x08,0x08,0x08,0x08,0x08,0x08,0x00,0x00,
0x00,0x00,0x00,0x3C,0x42,0x42,0x42,0x24,0x18,0x24,0x42,0x42,0x42,0x3C,0x00,0x00,
0x00,0x00,0x00,0x18,0x24,0x42,0x42,0x42,0x64,0x58,0x40,0x40,0x24,0x1C,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00,0x00,0x18,0x18,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x08,0x08,0x04,
0x00,0x00,0x00,0x40,0x20,0x10,0x08,0x04,0x02,0x04,0x08,0x10,0x20,0x40,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0x00,0x00,0x00,0x7F,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x02,0x04,0x08,0x10,0x20,0x40,0x20,0x10,0x08,0x04,0x02,0x00,0x00,
0x00,0x00,0x00,0x3C,0x42,0x42,0x46,0x40,0x20,0x10,0x10,0x00,0x18,0x18,0x00,0x00,
0x00,0x00,0x00,0x1C,0x22,0x5A,0x55,0x55,0x55,0x55,0x2D,0x42,0x22,0x1C,0x00,0x00,
0x00,0x00,0x00,0x08,0x08,0x18,0x14,0x14,0x24,0x3C,0x22,0x42,0x42,0xE7,0x00,0x00,
0x00,0x00,0x00,0x1F,0x22,0x22,0x22,0x1E,0x22,0x42,0x42,0x42,0x22,0x1F,0x00,0x00,
0x00,0x00,0x00,0x7C,0x42,0x42,0x01,0x01,0x01,0x01,0x01,0x42,0x22,0x1C,0x00,0x00,
0x00,0x00,0x00,0x1F,0x22,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x22,0x1F,0x00,0x00,
0x00,0x00,0x00,0x3F,0x42,0x12,0x12,0x1E,0x12,0x12,0x02,0x42,0x42,0x3F,0x00,0x00,
0x00,0x00,0x00,0x3F,0x42,0x12,0x12,0x1E,0x12,0x12,0x02,0x02,0x02,0x07,0x00,0x00,
0x00,0x00,0x00,0x3C,0x22,0x22,0x01,0x01,0x01,0x71,0x21,0x22,0x22,0x1C,0x00,0x00,
0x00,0x00,0x00,0xE7,0x42,0x42,0x42,0x42,0x7E,0x42,0x42,0x42,0x42,0xE7,0x00,0x00,
0x00,0x00,0x00,0x3E,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x3E,0x00,0x00,
0x00,0x00,0x00,0x7C,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x11,0x0F,
0x00,0x00,0x00,0x77,0x22,0x12,0x0A,0x0E,0x0A,0x12,0x12,0x22,0x22,0x77,0x00,0x00,
0x00,0x00,0x00,0x07,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x42,0x7F,0x00,0x00,
0x00,0x00,0x00,0x77,0x36,0x36,0x36,0x36,0x2A,0x2A,0x2A,0x2A,0x2A,0x6B,0x00,0x00,
0x00,0x00,0x00,0xE3,0x46,0x46,0x4A,0x4A,0x52,0x52,0x52,0x62,0x62,0x47,0x00,0x00,
0x00,0x00,0x00,0x1C,0x22,0x41,0x41,0x41,0x41,0x41,0x41,0x41,0x22,0x1C,0x00,0x00,
0x00,0x00,0x00,0x3F,0x42,0x42,0x42,0x42,0x3E,0x02,0x02,0x02,0x02,0x07,0x00,0x00,
0x00,0x00,0x00,0x1C,0x22,0x41,0x41,0x41,0x41,0x41,0x4D,0x53,0x32,0x1C,0x60,0x00,
0x00,0x00,0x00,0x3F,0x42,0x42,0x42,0x3E,0x12,0x12,0x22,0x22,0x42,0xC7,0x00,0x00,
0x00,0x00,0x00,0x7C,0x42,0x42,0x02,0x04,0x18,0x20,0x40,0x42,0x42,0x3E,0x00,0x00,
0x00,0x00,0x00,0x7F,0x49,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x1C,0x00,0x00,
0x00,0x00,0x00,0xE7,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x3C,0x00,0x00,
0x00,0x00,0x00,0xE7,0x42,0x42,0x22,0x24,0x24,0x14,0x14,0x18,0x08,0x08,0x00,0x00,
0x00,0x00,0x00,0x6B,0x49,0x49,0x49,0x49,0x55,0x55,0x36,0x22,0x22,0x22,0x00,0x00,
0x00,0x00,0x00,0xE7,0x42,0x24,0x24,0x18,0x18,0x18,0x24,0x24,0x42,0xE7,0x00,0x00,
0x00,0x00,0x00,0x77,0x22,0x22,0x14,0x14,0x08,0x08,0x08,0x08,0x08,0x1C,0x00,0x00,
0x00,0x00,0x00,0x7E,0x21,0x20,0x10,0x10,0x08,0x04,0x04,0x42,0x42,0x3F,0x00,0x00,
0x00,0x78,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x78,0x00,
0x00,0x00,0x02,0x02,0x04,0x04,0x08,0x08,0x08,0x10,0x10,0x20,0x20,0x20,0x40,0x40,
0x00,0x1E,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x1E,0x00,
0x00,0x38,0x44,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,
0x00,0x06,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x42,0x78,0x44,0x42,0x42,0xFC,0x00,0x00,
0x00,0x00,0x00,0x03,0x02,0x02,0x02,0x1A,0x26,0x42,0x42,0x42,0x26,0x1A,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x38,0x44,0x02,0x02,0x02,0x44,0x38,0x00,0x00,
0x00,0x00,0x00,0x60,0x40,0x40,0x40,0x78,0x44,0x42,0x42,0x42,0x64,0xD8,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x42,0x7E,0x02,0x02,0x42,0x3C,0x00,0x00,
0x00,0x00,0x00,0xF0,0x88,0x08,0x08,0x7E,0x08,0x08,0x08,0x08,0x08,0x3E,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7C,0x22,0x22,0x1C,0x02,0x3C,0x42,0x42,0x3C,
0x00,0x00,0x00,0x03,0x02,0x02,0x02,0x3A,0x46,0x42,0x42,0x42,0x42,0xE7,0x00,0x00,
0x00,0x00,0x00,0x0C,0x0C,0x00,0x00,0x0E,0x08,0x08,0x08,0x08,0x08,0x3E,0x00,0x00,
0x00,0x00,0x00,0x30,0x30,0x00,0x00,0x38,0x20,0x20,0x20,0x20,0x20,0x20,0x22,0x1E,
0x00,0x00,0x00,0x03,0x02,0x02,0x02,0x72,0x12,0x0A,0x16,0x12,0x22,0x77,0x00,0x00,
0x00,0x00,0x00,0x0E,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x3E,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0x92,0x92,0x92,0x92,0x92,0xB7,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3B,0x46,0x42,0x42,0x42,0x42,0xE7,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x42,0x42,0x42,0x42,0x42,0x3C,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1B,0x26,0x42,0x42,0x42,0x22,0x1E,0x02,0x07,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x78,0x44,0x42,0x42,0x42,0x44,0x78,0x40,0xE0,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x77,0x4C,0x04,0x04,0x04,0x04,0x1F,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7C,0x42,0x02,0x3C,0x40,0x42,0x3E,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x08,0x08,0x3E,0x08,0x08,0x08,0x08,0x08,0x30,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x63,0x42,0x42,0x42,0x42,0x62,0xDC,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE7,0x42,0x24,0x24,0x14,0x08,0x08,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xEB,0x49,0x49,0x55,0x55,0x22,0x22,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x76,0x24,0x18,0x18,0x18,0x24,0x6E,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE7,0x42,0x24,0x24,0x14,0x18,0x08,0x08,0x07,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7E,0x22,0x10,0x08,0x08,0x44,0x7E,0x00,0x00,
0x00,0xC0,0x20,0x20,0x20,0x20,0x20,0x10,0x20,0x20,0x20,0x20,0x20,0x20,0xC0,0x00,
0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,
0x00,0x06,0x08,0x08,0x08,0x08,0x08,0x10,0x08,0x08,0x08,0x08,0x08,0x08,0x06,0x00,
0x0C,0x32,0xC2,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};
//lcd_delay
void lcd_delay(u16 time)
{    
	u16 i=0;  
	while(time--)
	{
		i=10;  
		while(i--) ;    
	}
}

//LCD
void LCD_Writ_Bus(u16 dat)  
{	
     GPIO_Write(GPIOC,dat);	
     WR0;
	WR1;
} 
 void LCD_WR_DATA(u16 dat)
{
     RS1;
	LCD_Writ_Bus(dat);
}	  
void LCD_WR_REG(u16 dat)	 
{	
     RS0;
	LCD_Writ_Bus(dat);
}
 void LCD_WR_REG_DATA(int reg,int dat)
{
     LCD_WR_REG(reg);
	LCD_WR_DATA(dat);
}
void Address_set(unsigned int x1,unsigned int y1,unsigned int x2,unsigned int y2)
{ 
	LCD_WR_REG(0x0020);LCD_WR_DATA(x1);	 
	LCD_WR_REG(0x0021);LCD_WR_DATA(y1);   
	LCD_WR_REG(0x0050);LCD_WR_DATA(x1);   
	LCD_WR_REG(0x0052);LCD_WR_DATA(y1);	  
	LCD_WR_REG(0x0051);LCD_WR_DATA(x2);  
	LCD_WR_REG(0x0053);LCD_WR_DATA(y2);   
	LCD_WR_REG(0x0022);							 						 
}
void Lcd_Init(void)
{
    CS1;
    REST1;
    lcd_delay(20);	
    REST0;
    lcd_delay(20);
    REST1;
    CS1;
    RD1;
    WR1;
    lcd_delay(20);
    CS0; 

	LCD_WR_REG_DATA(0x0001,0x0100); 
	LCD_WR_REG_DATA(0x0002,0x0700); 
	LCD_WR_REG_DATA(0x0003,0x1030); 
	LCD_WR_REG_DATA(0x0004,0x0000); 
	LCD_WR_REG_DATA(0x0008,0x0207);  
	LCD_WR_REG_DATA(0x0009,0x0000);
	LCD_WR_REG_DATA(0x000A,0x0000); 
	LCD_WR_REG_DATA(0x000C,0x0000); 
	LCD_WR_REG_DATA(0x000D,0x0000);
	LCD_WR_REG_DATA(0x000F,0x0000);
	//power on sequence VGHVGL
	LCD_WR_REG_DATA(0x0010,0x0000);   
	LCD_WR_REG_DATA(0x0011,0x0007);  
	LCD_WR_REG_DATA(0x0012,0x0000);  
	LCD_WR_REG_DATA(0x0013,0x0000); 
	//vgh 
	LCD_WR_REG_DATA(0x0010,0x1290);   
	LCD_WR_REG_DATA(0x0011,0x0227);
	//vregiout 
	LCD_WR_REG_DATA(0x0012,0x001d); //0x001b
	//delayms(100); 
	//vom amplitude
	LCD_WR_REG_DATA(0x0013,0x1500);
	//delayms(100); 
	//vom H
	LCD_WR_REG_DATA(0x0029,0x0018); 
	LCD_WR_REG_DATA(0x002B,0x000D); 
	//gamma
	LCD_WR_REG_DATA(0x0030,0x0004);
	LCD_WR_REG_DATA(0x0031,0x0307);
	LCD_WR_REG_DATA(0x0032,0x0002);// 0006
	LCD_WR_REG_DATA(0x0035,0x0206);
	LCD_WR_REG_DATA(0x0036,0x0408);
	LCD_WR_REG_DATA(0x0037,0x0507); 
	LCD_WR_REG_DATA(0x0038,0x0204);// 0200
	LCD_WR_REG_DATA(0x0039,0x0707); 
	LCD_WR_REG_DATA(0x003C,0x0405);// 0504
	LCD_WR_REG_DATA(0x003D,0x0F02); 
	//ram
	LCD_WR_REG_DATA(0x0050,0x0000); 
	LCD_WR_REG_DATA(0x0051,0x00EF);
	LCD_WR_REG_DATA(0x0052,0x0000); 
	LCD_WR_REG_DATA(0x0053,0x013F);  
	LCD_WR_REG_DATA(0x0060,0xA700); 
	LCD_WR_REG_DATA(0x0061,0x0001); 
	LCD_WR_REG_DATA(0x006A,0x0000); 
	//
	LCD_WR_REG_DATA(0x0080,0x0000); 
	LCD_WR_REG_DATA(0x0081,0x0000); 
	LCD_WR_REG_DATA(0x0082,0x0000); 
	LCD_WR_REG_DATA(0x0083,0x0000); 
	LCD_WR_REG_DATA(0x0084,0x0000); 
	LCD_WR_REG_DATA(0x0085,0x0000); 
	//
	LCD_WR_REG_DATA(0x0090,0x0010); 
	LCD_WR_REG_DATA(0x0092,0x0600); 
	LCD_WR_REG_DATA(0x0093,0x0003); 
	LCD_WR_REG_DATA(0x0095,0x0110); 
	LCD_WR_REG_DATA(0x0097,0x0000); 
	LCD_WR_REG_DATA(0x0098,0x0000);
	LCD_WR_REG_DATA(0x0007,0x0133);
}
void LCD_Clear(u16 Color)
{	
	int i,j;
	Address_set(0,0,LCD_W-1,LCD_H-1);
     for(i=0;i<LCD_W;i++)
	 {
	  for (j=0;j<LCD_H;j++)
	   	{
        	 LCD_WR_DATA(Color);
	    }

	 }
}
void LCD_DrawPoint(u16 x,u16 y)
{
	Address_set(x,y,x,y); 
	LCD_WR_DATA(POINT_COLOR); 	    
} 
void LCD_Black(void)
{
	u16 i,j;
	Address_set(0,0,LCD_W-1,LCD_H-1);
     for(i=0;i<LCD_W;i++)
	{
	     for (j=0;j<LCD_H;j++)
	   	{
			RS1;
			LCD_Writ_Bus(0x0000);
	     }

	}
}
void LCD_ShowChar(u16 x,u16 y,u8 num)
{
     u8 temp;
	int i,j;
     u8 pos;
	int t;
     if(x>LCD_W-16||y>LCD_H-8)return;	    		   
	num=num-' '; 
	//���
	Address_set(x,y,x+16,y+8);
     for(i=0;i<=16;i++)
	{
	     for (j=8;j>=0;j--)
	   	{
			RS1;
			LCD_Writ_Bus(0x0000);
	     }

	}
	//write
	for(pos=0;pos<16;pos++)
	{
		temp=asc2_1608[(u16)num*16+pos];		 
	     for(t=7;t>=0;t--)
		{                 
		     if(temp&0x01)LCD_DrawPoint(x+pos,y+t);     
		     temp>>=1; 
		}
	}    	   	 	  
}  
void LCD_ShowString(u16 x,int y,u8 *p)
{         
    while(*p!='\0')
    {       
        if(x>LCD_W-16){LCD_Black();y=312;x=0;}
        if(y<0){y=312;x=x+16;}
        LCD_ShowChar(x,y,*p);
        y-=8;
        p++;
    }     
}
void Draw_Circle(u16 x0,u16 y0,u8 r)
{
	int a,b;
	int di;
	a=0;b=r;	  
	di=3-(r<<1);             
	while(a<=b)
	{
		LCD_DrawPoint(x0-b,y0-a);             //3           
		LCD_DrawPoint(x0+b,y0-a);             //0           
		LCD_DrawPoint(x0-a,y0+b);             //1       
		LCD_DrawPoint(x0-b,y0-a);             //7           
		LCD_DrawPoint(x0-a,y0-b);             //2             
		LCD_DrawPoint(x0+b,y0+a);             //4               
		LCD_DrawPoint(x0+a,y0-b);             //5
		LCD_DrawPoint(x0+a,y0+b);             //6 
		LCD_DrawPoint(x0-b,y0+a);             
		a++;
		
		if(di<0)di +=4*a+6;	  
		else
		{
			di+=10+4*(a-b);   
			b--;
		} 
		LCD_DrawPoint(x0+a,y0+b);
	}
}
void putnums(u16 x,u16 y,int num)
{
	int ge=0,shi=0,bai=0,qian=0,wan=0,shiwan=0,baiwan=0;
	u8 numx[8];
	ge    =(num%10);
	shi   =(num%100)/10;
	bai   =(num%1000)/100;
	qian  =(num%10000)/1000;
	wan   =(num%100000)/10000;
	shiwan=(num%1000000)/100000;
	baiwan=num/1000000;
	numx[0]=baiwan+48;
	numx[1]=shiwan+48;
	numx[2]=wan+48;
	numx[3]=qian+48;
	numx[4]=bai+48;
	numx[5]=shi+48;
	numx[6]=ge+48;
	numx[7]=0;
	LCD_ShowString(x,y,numx);
}
void putfloatnums(u16 x,u16 y,float num)
{
	u8 ge=0,shi=0,bai=0,qian=0,wan=0,shiwan=0,baiwan=0;
	u8 numi[4];
	u8 numf[5];
	num=num*10000;
	
	ge    =((int)num%10);
	shi   =((int)num%100)/10;
	bai   =((int)num%1000)/100;
	qian  =((int)num%10000)/1000;
	wan   =((int)num%100000)/10000;
	shiwan=((int)num%1000000)/100000;
	baiwan=num/1000000;
	numi[0]=baiwan+48;
	numi[1]=shiwan+48;
	numi[2]=wan+48;
	numi[3]=0;
	numf[0]=qian+48;
	numf[1]=bai+48;
	numf[2]=shi+48;
	numf[3]=ge+48;
	numf[4]=0;
	
	
	LCD_ShowString(x,y,numi);
	LCD_ShowString(x,y-24,".");
	LCD_ShowString(x,y-32,numf);
	
}
void show_line1(int x0,int x1,int y)
{
	int count;
	for(count=x1-x0;count>0;count--)
	{
		LCD_DrawPoint(x0,y);
		x0++;
	}
}
void show_line2(int y0,int y1,int x)
{
	int count;
	for(count=y1-y0;count>0;count--)
	{
		LCD_DrawPoint(x,y0);
		y0++;
	}	
}