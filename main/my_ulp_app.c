#include <stdio.h>
#include "ulp_lp_core.h"

extern const uint8_t ulp_hello_world_bin_start[] asm("_binary_ulp_hello_world_bin_start");
extern const uint8_t ulp_hello_world_bin_end[]   asm("_binary_ulp_hello_world_bin_end");

void app_main(void)
{
    ulp_lp_core_cfg_t cfg = {
        .wakeup_source = ULP_LP_CORE_WAKEUP_SOURCE_LP_TIMER,
        .lp_timer_sleep_duration_us = 1000000,
    };

    ESP_ERROR_CHECK(ulp_lp_core_load_binary(ulp_hello_world_bin_start, (ulp_hello_world_bin_end - ulp_hello_world_bin_start)));
    ESP_ERROR_CHECK(ulp_lp_core_run(&cfg));

    printf("LP core loaded with firmware and running successfully\n");
}
