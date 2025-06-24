#pragma once

#include QMK_KEYBOARD_H

typedef enum { TD_NONE, TD_UNKNOWN, TD_SINGLE_TAP, TD_SINGLE_HOLD, TD_DOUBLE_TAP } td_state_t;

typedef struct {
    bool       is_press_action;
    td_state_t state;
} td_tap_t;

enum {
    TD_MOD_LAYER,
    TD_NAV_LAYER,
    TD_SCLN_COLN,
};

// Declare the functions to be used with your tap dance key(s)

// Function associated with all tap dances
td_state_t cur_dance(tap_dance_state_t *state);

// Functions associated with individual tap dances
void td_mod_layer_finished(tap_dance_state_t *state, void *user_data);
void td_mod_layer_reset(tap_dance_state_t *state, void *user_data);

void td_nav_layer_finished(tap_dance_state_t *state, void *user_data);
void td_nav_layer_reset(tap_dance_state_t *state, void *user_data);
