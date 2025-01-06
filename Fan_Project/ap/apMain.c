#include "apMain.h"

FILE OUTPUT_F = FDEV_SETUP_STREAM(UART0_Transmit, NULL, _FDEV_SETUP_WRITE);

ISR(TIMER0_OVF_vect)
{
	FND_ISR_process();
	TCNT0 = 130;
}

ISR(TIMER2_COMP_vect)
{
	fanTimerCountDown();
}

ISR(USART0_RX_vect)
{
	UART0_ISR_Process();
}

void apMain_init()
{
	listener_init();
	presenter_init();
	UART0_init();
	Buzzer2_init();
	stdout = &OUTPUT_F;
	
	Timer0_init();
	Timer2_init();
	Timer3_init();
	
	DDRE |= (1<<3);
	DDRB |= (1<<5);
	
	model_SetFanTimeStateData(TIME0);
	model_SetFanModeStateData(OFF);
	model_SetPrevFanModeStateData(OFF);
	model_SetFanMiliTimeData(0);
	model_SetFanTimeData(0);
	
	sei();
}

void apMain_execute()
{
	listener_EventCheck();
	presenter_run();
}