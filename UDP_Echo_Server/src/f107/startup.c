//#include "system.h"

#define WEAK __attribute__ ((weak))

 
 void WEAK Reset_Handler(void);
 void WEAK NMI_Handler(void);
 void WEAK HardFault_Handler(void);
 void WEAK MemManage_Handler(void);
 void WEAK BusFault_Handler(void);
 void WEAK UsageFault_Handler(void);
 void WEAK SVC_Handler(void);
 void WEAK DebugMon_Handler(void);
 void WEAK PendSV_Handler(void);
 void WEAK SysTick_Handler(void);

 void WWDGT_IRQHandler (void);            
 void LVD_IRQHandler (void);              
 void TAMPER_IRQHandler (void);           
 void RTC_IRQHandler (void);              
 void FMC_IRQHandler (void);              
 void RCU_IRQHandler (void);              
 void EXTI0_IRQHandler (void);            
 void EXTI1_IRQHandler (void);            
 void EXTI2_IRQHandler (void);            
 void EXTI3_IRQHandler (void);            
 void EXTI4_IRQHandler (void);            
 void DMA0_Channel0_IRQHandler (void);    
 void DMA0_Channel1_IRQHandler (void);    
 void DMA0_Channel2_IRQHandler (void);    
 void DMA0_Channel3_IRQHandler (void);    
 void DMA0_Channel4_IRQHandler (void);    
 void DMA0_Channel5_IRQHandler (void);    
 void DMA0_Channel6_IRQHandler (void);    
 void ADC0_1_IRQHandler (void);           
 void CAN0_TX_IRQHandler (void);          
 void CAN0_RX0_IRQHandler (void);         
 void CAN0_RX1_IRQHandler (void);         
 void CAN0_EWMC_IRQHandler (void);        
 void EXTI5_9_IRQHandler (void);          
 void TIMER0_BRK_IRQHandler (void);       
 void TIMER0_UP_IRQHandler (void);        
 void TIMER0_TRG_CMT_IRQHandler (void);   
 void TIMER0_Channel_IRQHandler (void);   
 void TIMER1_IRQHandler (void);           
 void TIMER2_IRQHandler (void);           
 void TIMER3_IRQHandler (void);           
 void I2C0_EV_IRQHandler (void);          
 void I2C0_ER_IRQHandler (void);          
 void I2C1_EV_IRQHandler (void);          
 void I2C1_ER_IRQHandler (void);          
 void SPI0_IRQHandler (void);             
 void SPI1_IRQHandler (void);             
 void USART0_IRQHandler (void);           
 void USART1_IRQHandler (void);           
 void USART2_IRQHandler (void);           
 void EXTI10_15_IRQHandler (void);        
 void RTC_Alarm_IRQHandler (void);        
 void USBFS_WKUP_IRQHandler (void);       
 void TIMER7_BRK_IRQHandler (void);       
 void TIMER7_UP_IRQHandler (void);        
 void TIMER7_TRG_CMT_IRQHandler (void);   
 void TIMER7_Channel_IRQHandler (void);   
 void EXMC_IRQHandler (void);             
 void TIMER4_IRQHandler (void);           
 void SPI2_IRQHandler (void);             
 void UART3_IRQHandler (void);            
 void UART4_IRQHandler (void);            
 void TIMER5_IRQHandler (void);           
 void TIMER6_IRQHandler (void);           
 void DMA1_Channel0_IRQHandler (void);    
 void DMA1_Channel1_IRQHandler (void);    
 void DMA1_Channel2_IRQHandler (void);    
 void DMA1_Channel3_IRQHandler (void);    
 void DMA1_Channel4_IRQHandler (void);    
 void ENET_IRQHandler (void);             
 void ENET_WKUP_IRQHandler (void);        
 void CAN1_TX_IRQHandler (void);          
 void CAN1_RX0_IRQHandler (void);         
 void CAN1_RX1_IRQHandler (void);         
 void CAN1_EWMC_IRQHandler (void);        
 void USBFS_IRQHandler (void);            

 // Exported constants which defined in linker script.
extern unsigned long __etext;
extern unsigned long _sidata;	// start addr for the init values of the .data section. 
extern unsigned long _sdata;	
extern unsigned long _edata;
extern unsigned long __data_start__;	// start addr for the .data section.
extern unsigned long __data_end__;		// end addr for the .data section.
extern unsigned long __bss_start__;		// start addr for the .bss section.
extern unsigned long __bss_end__;			// end addr for the .bss section.
extern unsigned long __stack;					// init value for the stack pointer.
extern unsigned long _estack;

// Function prototypes
void __attribute__((section(".text_init"))) Reset_Handler(void);
extern int main(void);    
extern int SystemInit(void);                                                                                                                                                                                                                                          
extern void __libc_init_array(void);

__attribute__ ((section(".isr_vector")))
__attribute__ ((used))
void (* const g_pfnVectors[])(void) = {
  // The initial stack pointer                                                                                                                                                                                                          
//	(void (*)(void))((unsigned long) 0x02100000),    //TODO                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
	(void (*)(void))((unsigned long)&_estack),  
//	Reset_Handler,	    // Reset Handler
    Reset_Handler,
    NMI_Handler,
    HardFault_Handler,
    MemManage_Handler,
    BusFault_Handler,
    UsageFault_Handler,
    0,
    0,
    0,
    0,
    SVC_Handler,
    DebugMon_Handler,
    0,
    PendSV_Handler,
    SysTick_Handler,

                   /* external interrupts handler */
     WWDGT_IRQHandler,                  // 16:Window Watchdog Timer
     LVD_IRQHandler,                    // 17:LVD through EXTI Line detect
     TAMPER_IRQHandler,                 // 18:Tamper Interrupt   
     RTC_IRQHandler,                    // 19:RTC through EXTI Line
     FMC_IRQHandler,                    // 20:FMC
     RCU_IRQHandler,                    // 21:RCU
     EXTI0_IRQHandler,                  // 22:EXTI Line 0
     EXTI1_IRQHandler,                  // 23:EXTI Line 1
     EXTI2_IRQHandler,                  // 24:EXTI Line 2
     EXTI3_IRQHandler,                  // 25:EXTI Line 3
     EXTI4_IRQHandler,                  // 26:EXTI Line 4
     DMA0_Channel0_IRQHandler,          // 27:DMA0 Channel 0
     DMA0_Channel1_IRQHandler,          // 28:DMA0 Channel 1
     DMA0_Channel2_IRQHandler,          // 29:DMA0 Channel 2
     DMA0_Channel3_IRQHandler,          // 30:DMA0 Channel 3
     DMA0_Channel4_IRQHandler,          // 31:DMA0 Channel 4
     DMA0_Channel5_IRQHandler,          // 32:DMA0 Channel 5 
     DMA0_Channel6_IRQHandler,          // 33:DMA0 Channel 6
     ADC0_1_IRQHandler,                 // 34:ADC0 and ADC1
     CAN0_TX_IRQHandler,                // 35:CAN0 TX
     CAN0_RX0_IRQHandler,               // 36:CAN0 RX0
     CAN0_RX1_IRQHandler,               // 37:CAN0 RX1
     CAN0_EWMC_IRQHandler,              // 38:CAN0 EWMC
     EXTI5_9_IRQHandler,                // 39:EXTI Line 5 to EXTI Line 9
     TIMER0_BRK_IRQHandler,             // 40:TIMER0 Break
     TIMER0_UP_IRQHandler,              // 41:TIMER0 Update
     TIMER0_TRG_CMT_IRQHandler,         // 42:TIMER0 Trigger and Commutation
     TIMER0_Channel_IRQHandler,         // 43:TIMER0 Channel Capture Compare
     TIMER1_IRQHandler,                 // 44:TIMER1
     TIMER2_IRQHandler,                 // 45:TIMER2
     TIMER3_IRQHandler,                 // 46:TIMER3
     I2C0_EV_IRQHandler,                // 47:I2C0 Event
     I2C0_ER_IRQHandler,                // 48:I2C0 Error
     I2C1_EV_IRQHandler,                // 49:I2C1 Event
     I2C1_ER_IRQHandler,                // 50:I2C1 Error
     SPI0_IRQHandler,                   // 51:SPI0
     SPI1_IRQHandler,                   // 52:SPI1
     USART0_IRQHandler,                 // 53:USART0
     USART1_IRQHandler,                 // 54:USART1
     USART2_IRQHandler,                 // 55:USART2
     EXTI10_15_IRQHandler,              // 56:EXTI Line 10 to EXTI Line 15
     RTC_Alarm_IRQHandler,              // 57:RTC Alarm through EXTI Line
     USBFS_WKUP_IRQHandler,             // 58:USBFS WakeUp from suspend through EXTI Line
     TIMER7_BRK_IRQHandler,             // 59:TIMER7 Break Interrupt
     TIMER7_UP_IRQHandler,              // 60:TIMER7 Update Interrupt
     TIMER7_TRG_CMT_IRQHandler,         // 61:TIMER7 Trigger
     TIMER7_Channel_IRQHandler,         // 62:TIMER7 Channel Capture Compare 
     0,                                 // Reserved
     EXMC_IRQHandler,                   // 64:EXMC
     0,                                 // Reserved
     TIMER4_IRQHandler,                 // 66:TIMER4
     SPI2_IRQHandler,                   // 67:SPI2
     UART3_IRQHandler,                  // 68:UART3
     UART4_IRQHandler,                  // 69:UART4
     TIMER5_IRQHandler,                 // 70:TIMER5
     TIMER6_IRQHandler,                 // 71:TIMER6
     DMA1_Channel0_IRQHandler,          // 72:DMA1 Channel0
     DMA1_Channel1_IRQHandler,          // 73:DMA1 Channel1
     DMA1_Channel2_IRQHandler,          // 74:DMA1 Channel2
     DMA1_Channel3_IRQHandler,          // 75:DMA1 Channel3
     DMA1_Channel4_IRQHandler,          // 76:DMA1 Channel4
     ENET_IRQHandler,                   // 77:Ethernet
     ENET_WKUP_IRQHandler,              // 78:Ethernet Wakeup through EXTI line
     CAN1_TX_IRQHandler,                // 79:CAN1 TX
     CAN1_RX0_IRQHandler,               // 80:CAN1 RX0
     CAN1_RX1_IRQHandler,               // 81:CAN1 RX1
     CAN1_EWMC_IRQHandler,              // 82:CAN1 EWMC
     USBFS_IRQHandler                   // 83:USBFS
};   



#pragma weak NMI_Handler = Default_Handler
#pragma weak HardFault_Handler = Default_Handler
#pragma weak MemManage_Handler = Default_Handler
#pragma weak BusFault_Handler = Default_Handler
#pragma weak UsageFault_Handler = Default_Handler
#pragma weak SVC_Handler = Default_Handler
#pragma weak DebugMon_Handler = Default_Handler
#pragma weak PendSV_Handler = Default_Handler
#pragma weak SysTick_Handler = Default_Handler

#pragma weak WWDGT_IRQHandler = Default_Handler            
#pragma weak LVD_IRQHandler = Default_Handler              
#pragma weak TAMPER_IRQHandler = Default_Handler           
#pragma weak RTC_IRQHandler = Default_Handler              
#pragma weak FMC_IRQHandler = Default_Handler              
#pragma weak RCU_IRQHandler = Default_Handler              
#pragma weak EXTI0_IRQHandler = Default_Handler            
#pragma weak EXTI1_IRQHandler = Default_Handler            
#pragma weak EXTI2_IRQHandler = Default_Handler            
#pragma weak EXTI3_IRQHandler = Default_Handler            
#pragma weak EXTI4_IRQHandler = Default_Handler            
#pragma weak DMA0_Channel0_IRQHandler = Default_Handler    
#pragma weak DMA0_Channel1_IRQHandler = Default_Handler    
#pragma weak DMA0_Channel2_IRQHandler = Default_Handler    
#pragma weak DMA0_Channel3_IRQHandler = Default_Handler    
#pragma weak DMA0_Channel4_IRQHandler = Default_Handler    
#pragma weak DMA0_Channel5_IRQHandler = Default_Handler    
#pragma weak DMA0_Channel6_IRQHandler = Default_Handler    
#pragma weak ADC0_1_IRQHandler = Default_Handler           
#pragma weak CAN0_TX_IRQHandler = Default_Handler          
#pragma weak CAN0_RX0_IRQHandler = Default_Handler         
#pragma weak CAN0_RX1_IRQHandler = Default_Handler         
#pragma weak CAN0_EWMC_IRQHandler = Default_Handler        
#pragma weak EXTI5_9_IRQHandler = Default_Handler          
#pragma weak TIMER0_BRK_IRQHandler = Default_Handler       
#pragma weak TIMER0_UP_IRQHandler = Default_Handler        
#pragma weak TIMER0_TRG_CMT_IRQHandler = Default_Handler   
#pragma weak TIMER0_Channel_IRQHandler = Default_Handler   
#pragma weak TIMER1_IRQHandler = Default_Handler           
#pragma weak TIMER2_IRQHandler = Default_Handler           
#pragma weak TIMER3_IRQHandler = Default_Handler           
#pragma weak I2C0_EV_IRQHandler = Default_Handler          
#pragma weak I2C0_ER_IRQHandler = Default_Handler          
#pragma weak I2C1_EV_IRQHandler = Default_Handler          
#pragma weak I2C1_ER_IRQHandler = Default_Handler          
#pragma weak SPI0_IRQHandler = Default_Handler             
#pragma weak SPI1_IRQHandler = Default_Handler             
#pragma weak USART0_IRQHandler = Default_Handler           
#pragma weak USART1_IRQHandler = Default_Handler           
#pragma weak USART2_IRQHandler = Default_Handler           
#pragma weak EXTI10_15_IRQHandler = Default_Handler        
#pragma weak RTC_Alarm_IRQHandler = Default_Handler        
#pragma weak USBFS_WKUP_IRQHandler = Default_Handler       
#pragma weak TIMER7_BRK_IRQHandler = Default_Handler       
#pragma weak TIMER7_UP_IRQHandler = Default_Handler        
#pragma weak TIMER7_TRG_CMT_IRQHandler = Default_Handler   
#pragma weak TIMER7_Channel_IRQHandler = Default_Handler   
#pragma weak EXMC_IRQHandler = Default_Handler             
#pragma weak TIMER4_IRQHandler = Default_Handler           
#pragma weak SPI2_IRQHandler = Default_Handler             
#pragma weak UART3_IRQHandler = Default_Handler            
#pragma weak UART4_IRQHandler = Default_Handler            
#pragma weak TIMER5_IRQHandler = Default_Handler           
#pragma weak TIMER6_IRQHandler = Default_Handler           
#pragma weak DMA1_Channel0_IRQHandler = Default_Handler    
#pragma weak DMA1_Channel1_IRQHandler = Default_Handler    
#pragma weak DMA1_Channel2_IRQHandler = Default_Handler    
#pragma weak DMA1_Channel3_IRQHandler = Default_Handler    
#pragma weak DMA1_Channel4_IRQHandler = Default_Handler    
#pragma weak ENET_IRQHandler = Default_Handler             
#pragma weak ENET_WKUP_IRQHandler = Default_Handler        
#pragma weak CAN1_TX_IRQHandler = Default_Handler          
#pragma weak CAN1_RX0_IRQHandler = Default_Handler         
#pragma weak CAN1_RX1_IRQHandler = Default_Handler         
#pragma weak CAN1_EWMC_IRQHandler = Default_Handler        
#pragma weak USBFS_IRQHandler = Default_Handler            


/* This is the code that gets called when the processor receives an unexpected
	interrupt.  This simply enters an infinite loop, preserving the system state
	for examination by a debugger. */
void Default_Handler(void) { while (1); } // Go into an infinite loop.


/* This is the code that gets called when the processor first starts execution
	following a reset event.  Only the absolutely necessary set is performed,
	after which the application supplied main() routine is called. */
void __attribute__ ((naked)) __attribute__((section(".text_init"))) Reset_Handler(void) {
	unsigned long *pulSrc, *pulDest;    
	// Zero fill the bss segment.
	for(pulDest = &__bss_start__; pulDest < &__bss_end__; )
		*(pulDest++) = 0;

    pulDest = &_sdata; 
    pulSrc = &_sidata;
    while (pulDest < &_edata)
    {
        *pulDest++ = *pulSrc++;
    }

//	clock_update();

//	VTOR_update((unsigned*)g_pfnVectors);
    SystemInit();
    __libc_init_array();
//	setup();



	// Call the application's entry point.
	main();
	// Go to infinite loop
	Default_Handler();
}
