#include "pico/stdlib.h"
#include "hardware/gpio.h"

void my_callback(uint gpio, uint32_t events)
{
    if (gpio == 26)
    {
        gpio_put(21,1 );
    }
}

int main()
{
    gpio_init(21);
    gpio_set_dir(21, GPIO_OUT);

    gpio_init(26);
    gpio_set_dir(26, GPIO_IN);
    gpio_pull_up(26);

    gpio_set_irq_enabled_with_callback(
        26,
        GPIO_IRQ_EDGE_FALL,
        true,
        &my_callback
    );

    while (true)
    {
        sleep_ms(500);
    }
}