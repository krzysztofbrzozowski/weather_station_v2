#include "main.h"


#define UART_ID uart0
#define BAUD_RATE 115200

// We are using pins 0 and 1, but see the GPIO function select table in the
// datasheet for information on which other pins can be used.
#define UART_TX_PIN 0
#define UART_RX_PIN 1

int main() {
    /* Start WiFi init */
    wifi_init();
    /* End WiFi init */
    /* Start UART init */
    uart_init(UART_ID, BAUD_RATE);

    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);
    /* End UART init */

    while (true) {
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
        sleep_ms(1000);
         cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
        sleep_ms(1000);
        
        wifi_scan();

        uart_putc_raw(UART_ID, 'A');
        uart_putc(UART_ID, 'B');
        uart_puts(UART_ID, " Hello, UART!\n");
    }
}
