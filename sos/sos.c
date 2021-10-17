#include "pico/stdlib.h"
#include "stdbool.h"

#define GPIO_ON 1
#define GPIO_OFF 0

#define LED_PIN 25

int main() {
	gpio_init(LED_PIN);
	gpio_set_dir(LED_PIN, GPIO_OUT);
	bool ctrl = true;
	while(true) {
		if(ctrl) {
			// ...
			dot();
        	dot();
			dot();
			ctrl = false;
		}else {
			// - - -
			dash();
			dash();
			dash();
			ctrl = true;
		}
	}
}

void dot(void) {
	gpio_put(LED_PIN, GPIO_ON);
        sleep_ms(250);
        gpio_put(LED_PIN, GPIO_OFF);
        sleep_ms(60);
}

void dash(void) {
	gpio_put(LED_PIN, GPIO_ON);
	sleep_ms(750);
	gpio_put(LED_PIN, GPIO_OFF);
	sleep_ms(60);
}


