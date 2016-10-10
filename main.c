#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
//uint8_t ui8PinData=2;

int main(void)
{
	SysCtlClockSet(SYSCTL_SYSDIV_5|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);

	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
	GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);

	while(1)
	{
	GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, GPIO_PIN_3);
	SysCtlDelay(20000000);
	GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0x00);
	SysCtlDelay(20000000);
	//if(ui8PinData==8) {ui8PinData=2;} else {ui8PinData=ui8PinData*2;} //For all three LEDs to blink one by one...2,4,8
	}

}

