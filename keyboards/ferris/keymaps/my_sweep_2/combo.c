#include QMK_KEYBOARD_H

const uint16_t PROGMEM combo_enter[] = {KC_N, KC_E, COMBO_END};
const uint16_t PROGMEM combo_esc[] = {KC_S, KC_T, COMBO_END};


combo_t key_combos[] = {
    COMBO(combo_enter, KC_ENTER),
    COMBO(combo_esc, KC_ESC),
};
