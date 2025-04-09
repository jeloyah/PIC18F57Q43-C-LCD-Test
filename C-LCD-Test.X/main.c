
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
    
    /* Config Timer0 */
    TIMER0_Initialize();
    
    /* Config IOC */
    IOC_Initialize();
        
    /* Enable interrupts */
    ei();
       
    /* Config LCD */
    LCD_Initialize();
    
    LCD_CLEAR_DISPLAY();
    //LCD_writeCGRAM();
    
    /* infinite loop */
    while(1)
    {

        
        
        //LCD_printchar(0x0A);
        //LCD_printchar(0x0B);
        
        /* Row 1, column 1 */
        LCD_LOCATE(1,6);
        
        /* Print character M using ASCII code */
		LCD_printchar(0x4D);
        
        /* Print character C using ASCII code */
        LCD_printchar(0x43);
        
        /* Print character U using ASCII code */
        LCD_printchar(0x55);
        
        /* Print space using ASCII code */
        LCD_printchar(0x20);
        
        /* Print character P */
        LCD_printchar('P');
        
        /* Print character I */
        LCD_printchar('I');
        
        /* Print character C */
        LCD_printchar('C');
		
		/* Row 2, column 1 */
        LCD_LOCATE(2,3);
              
        /* Print a string of characters (must end with \n) */
	    LCD_printstring("**18F57Q43**\n");
        
        
              
     } /* while */
        
    
    return;
} /* main*/