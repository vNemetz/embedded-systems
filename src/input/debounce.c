
#include "input/debounce.h"

void debounce_init(Debounce *db, bool initial_state,
                   uint32_t now_ms, uint32_t debounce_ms)
{
    db->stable_state = initial_state;
    db->last_reading = initial_state;
    db->last_change_ms = now_ms;
    db->debounce_ms = debounce_ms;
}

ButtonEvent debounce_update(Debounce *db, bool reading,
                            uint32_t now_ms)
{
    if (reading != db->last_reading) {
        db->last_reading = reading;
        db->last_change_ms = now_ms;
    }

    if ((uint32_t)(now_ms - db->last_change_ms) >= db->debounce_ms) {
        if (db->stable_state != db->last_reading) {
            db->stable_state = db->last_reading;

            return db->stable_state
                ? BUTTON_EVENT_PRESSED
                : BUTTON_EVENT_RELEASED;
        }
    }

    return BUTTON_EVENT_NONE;
}
