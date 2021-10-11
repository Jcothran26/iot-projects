#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "hardware/gpio.h"

 
#define GPIO_ON 1
#define GPIO_OFF 0

#define LED_PIN 25

 int main() {
    //initialize LED pin
    gpio_init(LED_PIN);
    //LED pin as output
	gpio_set_dir(LED_PIN, GPIO_OUT);
    stdio_init_all();
    //adc initialization
    adc_init();
    //set io pin to 26 (adc pin)
    adc_gpio_init(26);
    // Select ADC input 0 (GPIO26)
    adc_select_input(0);
    while (1) {
    gpio_put(LED_PIN, GPIO_OFF);
    // read out of analog-digital converter
    uint16_t result = adc_read();
    if(result > (uint16_t) 3500) {
        	gpio_put(LED_PIN, GPIO_ON);
			sleep_ms(75);
    }
    }
}

