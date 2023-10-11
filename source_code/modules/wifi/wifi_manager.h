#ifndef SCAN_WIFI_H
#define SCAN_WIFI_H

#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"
#include "hardware/vreg.h"
#include "hardware/clocks.h"

extern return_type wifi_scan(void);
extern return_type wifi_init(void);

#endif