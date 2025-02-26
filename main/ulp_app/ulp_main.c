/*
 * SPDX-FileCopyrightText: 2025 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include "ulp_lp_core_utils.h"

 int my_counter = 0;

 int main (void)
 {
     my_counter++;

     if (my_counter >= 5) {
        ulp_lp_core_wakeup_main_processor();
    }
 }
