#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define SERVO_PIN 22  // GPIO para controle do servomotor
#define PWM_FREQ 50   // Frequência do PWM (50Hz -> período de 20ms)

void set_servo_pulse(uint slice, uint16_t pulse_us) {
    uint32_t clock = 125000000 / 64; // Clock fixo em 125MHz dividido por 64
    uint32_t wrap = clock / PWM_FREQ;
    pwm_set_wrap(slice, wrap);
    pwm_set_chan_level(slice, PWM_CHAN_A, (wrap * pulse_us) / 20000);
}

int main() {
    stdio_init_all();
    gpio_set_function(SERVO_PIN, GPIO_FUNC_PWM);
    uint slice = pwm_gpio_to_slice_num(SERVO_PIN);
    pwm_set_clkdiv(slice, 64.0);
    pwm_set_enabled(slice, true);

    while (1) {
        // Posição 180 graus (2400us)
        set_servo_pulse(slice, 2400);
        sleep_ms(5000);

        // Posição 90 graus (1470us)
        set_servo_pulse(slice, 1470);
        sleep_ms(5000);

        // Posição 0 graus (500us)
        set_servo_pulse(slice, 500);
        sleep_ms(5000);
    }
}
