#ifndef SCAN_WIFI_H
#define SCAN_WIFI_H

#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"
#include "hardware/vreg.h"
#include "hardware/clocks.h"

// absolute_time_t scan_time;
// extern bool scan_in_progress;

int wifi_scan(void);
bool wifi_init(void);

#endif