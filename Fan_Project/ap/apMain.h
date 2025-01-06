
#ifndef APMAIN_H_
#define APMAIN_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "../driver/lcd/lcd.h"
#include "../driver/fan/fan.h"
#include "../driver/fnd/fnd.h"
#include "../driver/buzzer/buzzer.h"
#include "../periph/timer/timer.h"

#include "listener/listener.h"
#include "presenter/presenter.h"
#include "service/fansystem.h"

#include "model/modelfanmodestate.h"
#include "model/modelfantimestate.h"
#include "model/modeltimedata.h"

void apMain_init();
void apMain_execute();

ISR(TIMER0_OVF_vect);
ISR(TIMER2_COMP_vect);
ISR(USART0_RX_vect);


#endif /* APMAIN_H_ */