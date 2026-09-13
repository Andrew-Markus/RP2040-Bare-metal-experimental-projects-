#include <stdio.h>
#include "pico/stdlib.h"

int main() {
    stdio_init_all();

    gpio_init(21);

    volatile uint32_t *gpio_oe_set  = (volatile uint32_t *)(SIO_BASE + 0x024); // OE SET
    volatile uint32_t * GPIO_OUT_XOR = (volatile uint32_t *)(SIO_BASE + 0x01c); // XOR
    
    *gpio_oe_set = (1 << 21);
      
    while (true) {      
        * GPIO_OUT_XOR = (1 << 21);   
        sleep_ms(500);
    }
}