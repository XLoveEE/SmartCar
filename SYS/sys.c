#include "sys.h"

u32 TimingDelay;


void NVIC_Configuration(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
}

void SysTick_Init()
{
	if(SysTick_Config(SystemCoreClock / 1000000))
	{
		while(1);
	}
	
	SysTick->CTRL &= ~ SysTick_CTRL_ENABLE_Msk;
}

void Delay_us(u32 time)
{
	TimingDelay = time;
	SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
	while (TimingDelay != 0);
	SysTick->CTRL &= ~ SysTick_CTRL_ENABLE_Msk;
	SysTick->VAL =0X00;
}

void Delay_ms(u32 time)
{
	Delay_us(time*1000);
}

void TimingDelay_Decrement()
{
		if (TimingDelay != 0x00) {
			 TimingDelay--;
		 }
}
