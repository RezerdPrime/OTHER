#include <inttypes.h>
#include <stdio.h>
 
#include <periph/gpio.h>
#include <periph/pwm.h>
#include <msg.h>
#include <thread.h>
#include <xtimer.h>

#define RCV_QUEUE_SIZE  (2)
uint32_t start_time;
unsigned short shift = 0;
unsigned short mode = 0;

static char rcv_stack1[THREAD_STACKSIZE_DEFAULT / 2];
static char rcv_stack2[THREAD_STACKSIZE_DEFAULT / 2];
static char rcv_stack3[THREAD_STACKSIZE_DEFAULT / 2];

static msg_t rcv_queue1[RCV_QUEUE_SIZE];
static msg_t rcv_queue2[RCV_QUEUE_SIZE];
static msg_t rcv_queue3[RCV_QUEUE_SIZE];


void init_gpio_after_pwm(gpio_t pin) {
    gpio_init(pin, GPIO_OUT);
}



static void* rcv1(void *arg) {
    msg_t msg;
    gpio_t pin1, pin2;
    (void)arg;

    msg_init_queue(rcv_queue1, RCV_QUEUE_SIZE);

    while (1) {
        msg_receive(&msg);


    // Глобальный режим 0 //=======================================================//

        if (mode == 0) {

            pin1 = LED3_PIN;
            pin2 = LED6_PIN;

            if (msg.content.value == 1) {
                pin1 = LED6_PIN;
                pin2 = LED3_PIN;
            }

            else if (msg.content.value == 0) {
                pin1 = LED3_PIN;
                pin2 = LED6_PIN;
            }

            gpio_set(pin1); 

            gpio_set(pin2);
            xtimer_usleep(500000);
            gpio_clear(pin2);
            xtimer_usleep(500000);

            gpio_set(pin2);
            xtimer_usleep(500000);

            gpio_clear(pin2); 
            gpio_clear(pin1);
            xtimer_usleep(500000);
        }
        

    // Глобальный режим 1 //=======================================================//

        else {
            for (uint32_t i = 0; (i < msg.content.value + 1) && (!gpio_read(BTN0_PIN)); i++) {
                if (!gpio_read(BTN0_PIN)) {
                    
                    gpio_set(LED3_PIN);
                    xtimer_usleep(1000000 / (msg.content.value + 1) );
                    gpio_clear(LED3_PIN);

                    gpio_set(LED5_PIN);
                    xtimer_usleep(1000000 / (msg.content.value + 1) );
                    gpio_clear(LED5_PIN);

                    gpio_set(LED6_PIN);
                    xtimer_usleep(1000000 / (msg.content.value + 1) );
                    gpio_clear(LED6_PIN);

                    gpio_set(LED4_PIN);
                    xtimer_usleep(1000000 / (msg.content.value + 1) );
                    gpio_clear(LED4_PIN);
                }
            }
        }
    }
    return NULL;
}



static void* rcv2(void *arg) {

    msg_t msg;
    (void)arg;

    msg_init_queue(rcv_queue2, RCV_QUEUE_SIZE);

    while (1) {
        msg_receive(&msg);
        // gpio_set(LED4_PIN);


    // Глобальный режим 0 //=======================================================//

        if (mode == 0) {

            if(msg.content.value) {
                pwm_init(PWM_DEV(1), PWM_LEFT, 1000, 250);

                for (short i = 250; i > 0; i--) {

                    pwm_set(PWM_DEV(1), 0, i);
                    xtimer_usleep(4000);
                }

                for (short i = 0; i < 250; i++) {

                    pwm_set(PWM_DEV(1), 0, i);
                    xtimer_usleep(4000);
                }

                pwm_set(PWM_DEV(1), 0, 0);
                init_gpio_after_pwm(LED4_PIN);
            }

            else {
                
                pwm_init(PWM_DEV(1), PWM_LEFT, 1000, 250);

                for (char _ = 0; _<2; _++) {

                    for (short i = 250; i > 0; i--) {

                        pwm_set(PWM_DEV(1), 0, i);
                        xtimer_usleep(2000);
                    }

                    for (short i = 0; i < 250; i++) {

                        pwm_set(PWM_DEV(1), 0, i);
                        xtimer_usleep(2000);
                    }
                }
                pwm_set(PWM_DEV(1), 0, 0);
                init_gpio_after_pwm(LED4_PIN);

            }
        }


    // Глобальный режим 1 //=======================================================//

        // else {
        //     gpio_clear(LED4_PIN);
        //     xtimer_usleep(1500000);

        //     gpio_set(LED4_PIN);
        //     xtimer_usleep(500000);
        //     gpio_clear(LED4_PIN);
        // }
    }

    return NULL;
}



static void* rcv3(void *arg) {

    msg_t msg;
    (void)arg;

    msg_init_queue(rcv_queue3, RCV_QUEUE_SIZE);
    while (1) {

        msg_receive(&msg);
        // gpio_set(LED5_PIN);


    // Глобальный режим 0 //=======================================================//

        if (mode == 0) {

            if(msg.content.value) {
                pwm_init(PWM_DEV(2), PWM_LEFT, 1000, 250);

                for (char _ = 0; _<2; _++) {

                    for (short i = 250; i > 0; i--) {

                        pwm_set(PWM_DEV(2), 0, i);
                        xtimer_usleep(2000);
                    }

                    for (short i = 0; i < 250; i++) {

                        pwm_set(PWM_DEV(2), 0, i);
                        xtimer_usleep(2000); //3906
                    }
                }
                pwm_set(PWM_DEV(2), 0, 0);
                init_gpio_after_pwm(LED5_PIN);
            }

            else {
                
                pwm_init(PWM_DEV(2), PWM_LEFT, 1000, 250);

                for (short i = 0; i < 250; i++) {

                    pwm_set(PWM_DEV(2), 0, i);
                    xtimer_usleep(4000);
                }

                for (short i = 250; i > 0; i--) {

                    pwm_set(PWM_DEV(2), 0, i);
                    xtimer_usleep(4000);
                }
                
                pwm_set(PWM_DEV(2), 0, 0);
                init_gpio_after_pwm(LED5_PIN);
            }
        }
        

    // Глобальный режим 1 //=======================================================//

        // else {
        //     gpio_clear(LED5_PIN);
        //     xtimer_usleep(500000);

        //     gpio_set(LED5_PIN);
        //     xtimer_usleep(500000);
        //     gpio_clear(LED5_PIN);

        //     xtimer_usleep(1000000);
        // }
    }
    return NULL;
}


void btn_tap(void* arg){
    (void)arg;

    if (gpio_read(BTN0_PIN)) {
        start_time = (uint32_t)xtimer_now_usec();
        
    } else {
        uint32_t diff = (uint32_t)xtimer_now_usec() - start_time;

        if (diff > 1000000) {
            if (mode) mode = 0;
            else mode = 1;
            shift = 0;

            gpio_clear(LED3_PIN);
            gpio_clear(LED4_PIN);
            gpio_clear(LED5_PIN);
            gpio_clear(LED6_PIN);
        }

        else {
            if (mode) {
                shift = (shift + 1) % 3;
            } else {
                shift = (shift + 1) % 2;
            }
        }

        // if ((uint32_t)xtimer_now_usec() - start_time < 1000000) { 
        //     shift = (shift + 1) % 2; 
        // }


    }
}


int main(void)
{
    msg_t msg;
    kernel_pid_t rcv_pid1, rcv_pid2, rcv_pid3;
    msg.content.value = shift;

    gpio_init_int(BTN0_PIN, GPIO_IN, GPIO_BOTH, btn_tap, NULL);
    
    rcv_pid1 = thread_create(rcv_stack1, sizeof(rcv_stack1),
                THREAD_PRIORITY_MAIN, 0, rcv1, NULL, "rcv1");

    rcv_pid2 = thread_create(rcv_stack2, sizeof(rcv_stack2),
                THREAD_PRIORITY_MAIN, 0, rcv2, NULL, "rcv2");

    rcv_pid3 = thread_create(rcv_stack3, sizeof(rcv_stack3),
                THREAD_PRIORITY_MAIN, 0, rcv3, NULL, "rcv3");

    while (1) {
        msg.content.value = shift;

        msg_try_send(&msg, rcv_pid1);

        if (!mode) {
            msg_try_send(&msg, rcv_pid2);
            msg_try_send(&msg, rcv_pid3);
        }

        xtimer_sleep(2 + 2 * mode * (shift == 0));
    }
    return 0;
}





/*
static void* rcv2(void *arg) {

    msg_t msg;
    (void)arg;

    msg_init_queue(rcv_queue2, RCV_QUEUE_SIZE);

    while (1) {
        msg_receive(&msg);

        if(msg.content.value) {
            pwm_init(PWM_DEV(1), PWM_LEFT, 1000, 256);

            for (char i = 0; i < 255; i++) {

                pwm_set(PWM_DEV(1), 0, i);
                xtimer_usleep(3906);
            }

            for (char i = 255; i > 0; i--) {

                pwm_set(PWM_DEV(1), 0, i);
                xtimer_usleep(3906);
            }
            pwm_set(PWM_DEV(1), 0, 0);
            init_gpio_after_pwm(LED4_PIN);
        }

        else {
            
            pwm_init(PWM_DEV(1), PWM_LEFT, 1000, 256);

            for (char _ = 0; _<2; _++) {
                for (char i = 0; i < 255; i++) {

                    pwm_set(PWM_DEV(1), 0, i);
                    xtimer_usleep(1953);
                }

                for (char i = 255; i > 0; i--) {

                    pwm_set(PWM_DEV(1), 0, i);
                    xtimer_usleep(1953);
                }
            }
            pwm_set(PWM_DEV(1), 0, 0);
            init_gpio_after_pwm(LED4_PIN);

        }

    }

    return NULL;
}


static void* rcv3(void *arg) {

    msg_t msg;
    (void)arg;

    msg_init_queue(rcv_queue3, RCV_QUEUE_SIZE);
    while (1) {
        msg_receive(&msg);

        if(msg.content.value) {
            pwm_init(PWM_DEV(2), PWM_LEFT, 1000, 256);

            for (char _ = 0; _<2; _++) {
                for (char i = 0; i < 255; i++) {

                    pwm_set(PWM_DEV(2), 0, i);
                    xtimer_usleep(1953); //3906
                }

                for (char i = 255; i > 0; i--) {

                    pwm_set(PWM_DEV(2), 0, i);
                    xtimer_usleep(1953);
                }
            }
            pwm_set(PWM_DEV(2), 0, 0);
            init_gpio_after_pwm(LED5_PIN);
        }

        else {
            
            pwm_init(PWM_DEV(2), PWM_LEFT, 1000, 256);

            
            for (char i = 0; i < 255; i++) {

                pwm_set(PWM_DEV(2), 0, i);
                xtimer_usleep(3906);
            }

            for (char i = 255; i > 0; i--) {

                pwm_set(PWM_DEV(2), 0, i);
                xtimer_usleep(3906);
            }
            
            pwm_set(PWM_DEV(2), 0, 0);
            init_gpio_after_pwm(LED5_PIN);
        }
    }
    return NULL;
}
*/
