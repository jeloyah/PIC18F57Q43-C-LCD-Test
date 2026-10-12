
#include <xc.h>
#include "main.h"
#include "clock.h"
#include "gpio.h"
#include "timer0.h"
#include "lcd.h"
#include "ioc.h"

void main(void) {
    
    /* System Clock Initialization */
	CLOCK_Initialize();
    
    /* Config Timer0 */
    TIMER0_Initialize();
    
    TIMER0_Delay_ms(100);
    
    /* Config PortA */
    PortA_Initialize();
    
    /* Config PortB */
    PortB_Initialize();

    /* Config PortC */
    PortC_Initialize();
    
    /* Config PortD */
    PortD_Initialize();
    
    /* Config PortE */
    PortE_Initialize();
    
    /* Config PortF */
    PortF_Initialize();
     
    /* Config IOC */
    IOC_Initialize();
          
    /* Enable interrupts */
    ei();
       
    /* Config LCD */
    LCD_Initialize();
    
    LCD_CLEAR_DISPLAY();
     
    /* infinite loop */
    while(1)
    {
       
        /* Row 1, column 5 */
        LCD_LOCATE(1,5);
        
        /* Print a string of characters (must end with \n) */
	    LCD_printstring("**8-bit MCU**\n");       
       		
		/* Row 2, column 1 */
        LCD_LOCATE(2,1);
              
        /* Print a string of characters (must end with \n) */
	    LCD_printstring("**PIC18F57Q43**\n");       
              
     } /* while */
        
    
    return;
} /* main*/
