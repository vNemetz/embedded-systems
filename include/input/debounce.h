
#ifndef DEBOUNCE_H
#define DEBOUNCE_H

#include <stdbool.h>
#include <stdint.h>

typedef enum {
    BUTTON_EVENT_NONE,
    BUTTON_EVENT_PRESSED,
    BUTTON_EVENT_RELEASED
} ButtonEvent;

typedef struct {
    bool stable_state;
    bool last_reading;
    uint32_t last_change_ms;
    uint32_t debounce_ms;
} Debounce;

void debounce_init(Debounce *db, bool initial_state,
                   uint32_t now_ms, uint32_t debounce_ms);

ButtonEvent debounce_update(Debounce *db, bool reading,
                           uint32_t now_ms);

#endif
