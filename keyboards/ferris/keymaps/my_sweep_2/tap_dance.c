#include "action.h"
#include "process_tap_dance.h"
#include QMK_KEYBOARD_H

#include "tap_dance.h"
#include "layer.h"
#include "caps_word.h"

// Determine the current tap dance state
td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed)
            return TD_SINGLE_TAP;
        else
            return TD_SINGLE_HOLD;
    } else if (state->count == 2)
        return TD_DOUBLE_TAP;
    else
        return TD_UNKNOWN;
}

// Initialize tap structure associated with example tap dance key
static td_tap_t tap_state = {.is_press_action = true, .state = TD_NONE};

// MOD Lyaer
void td_mod_layer_finished(tap_dance_state_t *state, void *user_data) {
    tap_state.state = cur_dance(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            // Register a one-shot shift
            add_oneshot_mods(MOD_BIT(KC_LSFT));
            break;
        case TD_SINGLE_HOLD:
            layer_on(MOD_LAYER);
            break;
        case TD_DOUBLE_TAP:
            // tap_code(KC_CAPS);
            caps_word_on();
            break;
        default:
            break;
    }
}

void td_mod_layer_reset(tap_dance_state_t *state, void *user_data) {
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            break;
        case TD_SINGLE_HOLD:
            layer_off(MOD_LAYER);
            break;
        case TD_DOUBLE_TAP:
            // caps_word_off();
            break;
        default:
            break;
    }
    tap_state.state = TD_NONE;
}

// NAV Layer
void td_nav_layer_finished(tap_dance_state_t *state, void *user_data) {
    tap_state.state = cur_dance(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code(KC_ESC);
            break;
        case TD_SINGLE_HOLD:
            layer_on(NAV_LAYER);
            break;
        case TD_DOUBLE_TAP:
            tap_code(KC_ESC);
            tap_code(KC_ESC);
            // set_oneshot_layer(WM_LAYER, ONESHOT_START);
            break;
        default:
            break;
    }
}

void td_nav_layer_reset(tap_dance_state_t *state, void *user_data) {
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            break;
        case TD_SINGLE_HOLD:
            layer_off(NAV_LAYER);
            break;
        case TD_DOUBLE_TAP:
            // clear_oneshot_layer_state(ONESHOT_PRESSED);
            break;
        default:
            break;
    }
    tap_state.state = TD_NONE;
}

// shift
void td_shift_finished(tap_dance_state_t *state, void *user_data) {
    tap_state.state = cur_dance(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            set_oneshot_mods(MOD_BIT(KC_LSFT));
            break;
        case TD_SINGLE_HOLD:
             register_code(KC_LSFT);
            break;
        case TD_DOUBLE_TAP:
            caps_word_on();
            break;
        default:
            break;
    }
}

void td_shift_reset(tap_dance_state_t *state, void *user_data) {
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            break;
        case TD_SINGLE_HOLD:
            unregister_code(KC_LSFT);
            break;
        case TD_DOUBLE_TAP:
            break;
        default:
            break;
    }
    tap_state.state = TD_NONE;
}

// Associate our tap dance key with its functionality
// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_SCLN_COLN] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_COLN),
    [TD_SHIFT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_shift_finished, td_shift_reset),
    [TD_MOD_LAYER] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_mod_layer_finished, td_mod_layer_reset),
    [TD_NAV_LAYER] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_nav_layer_finished, td_nav_layer_reset)};

// Set a long-ish tapping term for tap-dance keys
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
            return 275;
        default:
            return TAPPING_TERM;
    }
}
