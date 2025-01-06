#include "fansystem.h"




void fanTimerCountDown()
{
	uint32_t fanTimeData = model_GetFanTimeData();
	uint8_t fanModeStateData = model_GetFanModeStateData();
	static uint8_t count = 0;
	static uint32_t miliTime = 0;
	
	if (fanModeStateData == OFF)
	{
		model_SetFanTimeData(0);
		model_SetFanMiliTimeData(0);
		model_SetFanTimeStateData(TIME0);
		count = 0;
		return;
	}
	
	if (fanTimeData == 0)
	{
		model_SetFanMiliTimeData(0);
		count = 0;
		return;
	}
	
	if(count==0 && fanTimeData == 180)
	{
		miliTime = 0;
		miliTime = fanTimeData * 1000;
		count++;
	}
	if(count==1 && fanTimeData == 300)
	{
		miliTime = 0;
		miliTime = fanTimeData * 1000;
		count++;
	}
	else if(count==2 && fanTimeData == 420)
	{
		miliTime = 0;
		miliTime = fanTimeData * 1000;
		count=0;
	}
	
	model_SetFanMiliTimeData(miliTime);
	
	miliTime = (miliTime-1);
	if (miliTime == 0)
	{
		model_SetFanModeStateData(OFF);
		count = 0;
		model_SetFanTimeData(0);
		model_SetFanTimeStateData(TIME0);
	}
}

void fanAutoMode()
{
	static uint8_t AutoState = A;
	static uint16_t timeTick=0;
	static uint16_t prevTime=0;
	
	switch(AutoState)
	{
		case A:
		fan_makeHertz(600);
		if(timeTick - prevTime >= 30)
		{
			prevTime = timeTick;
			AutoState = B;
		}
		break;
		
		case B:
		fan_makeHertz(100);
		if(timeTick - prevTime >= 10)
		{
			prevTime = timeTick;
			AutoState = C;
		}
		break;
		
		case C:
		fan_makeHertz(900);
		if(timeTick - prevTime >= 30)
		{
			prevTime = timeTick;
			AutoState = D;
		}
		break;
		
		case D:
		fan_makeHertz(300);
		if(timeTick - prevTime >= 10)
		{
			prevTime = timeTick;
			AutoState = A;
		}
		break;
	}
	timeTick++;
}
