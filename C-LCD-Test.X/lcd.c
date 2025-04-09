#include <xc.h>
#include "lcd.h"
#include "timer0.h"

/* Config LCD */
void LCD_Initialize(void)
{
    /* 4-bit operation */
	LCD_CMD(0x02);
    TIMER0_Delay_1ms(1);
      
    /* 2-line display, display on */
    LCD_CMD(0x28);
    TIMER0_Delay_1ms(1);
    
    /* Display On, cursor off, blink off */
    LCD_CMD(0x0C);
    TIMER0_Delay_1ms(1);
  
    /* Entry mode set, increment mode */
    LCD_CMD(0x06);
    TIMER0_Delay_1ms(1);
}

void LCD_printchar(char ascode)
{
        LCD_RS_High;
        LCD_Port = (ascode & 0xF0);
        LCD_ENABLE();
        LCD_Port = ((ascode << 4) & 0xF0);
        LCD_ENABLE();
}

void LCD_printstring(char *text)
{
        do
        {
          LCD_printchar(*text++);
        }
        while (*text != '\n');
}

/* Place LCD cursor in (row, column) */
void LCD_LOCATE(char row, char column)
{
      column--;
      switch (row)
      {
        case 1:
              /* Set cursor to 1st row address and add index*/
              LCD_CMD(column |= 0x80);
              break;
        case 2:
              /* Set cursor to 2nd row address and add index*/
              LCD_CMD(column |= 0x40 | 0x80);
              break;
        case 3:
              /* Set cursor to 2nd row address and add index*/
              LCD_CMD(column |= 0x10 | 0x80);
              break;
        case 4:
              /* Set cursor to 2nd row address and add index*/
              LCD_CMD(column |= 0x50 | 0x80);
              break;
        default:
              break;
  }
}

/* Send a LCD command */
void LCD_CMD(char cmd_data)
{
      LCD_RS_Low;
      
      LCD_Port = (cmd_data  & 0xF0);  // 1111 0000
      LCD_ENABLE();
      LCD_Port = ((cmd_data << 4) & 0xF0);
      LCD_ENABLE();
      TIMER0_Delay_1ms(2);
}

/* Toggle Enable */
void LCD_ENABLE (void)
{
      LCD_Enable_High;
      TIMER0_Delay_1ms(1);
      LCD_Enable_Low;
}

/* Clear LCD screen */
void LCD_CLEAR_DISPLAY(void)
{
      LCD_CMD(0x01);
      TIMER0_Delay_1ms(2);
}

