#include "layer.h"
#include "quantum_keycodes.h"
#include QMK_KEYBOARD_H

#include "keycodes.h"
#include "tap_dance.h"
#include "keycode.h"

const uint16_t PROGMEM combo_enter[] = {CKC_N, CKC_E, COMBO_END};
const uint16_t PROGMEM combo_tab[] = {CKC_E, KC_I, COMBO_END};

const uint16_t PROGMEM combo_en[] = {KC_F, CKC_T, COMBO_END};
const uint16_t PROGMEM combo_el[] = {CKC_N, KC_U, COMBO_END};

const uint16_t PROGMEM combo_slsh[] = {KC_H, CKC_E, COMBO_END};
const uint16_t PROGMEM combo_bsls[] = {CKC_N, KC_COMMA, COMBO_END};

const uint16_t PROGMEM combo_tmux_layer[] = {TKC_LR, CKC_S, COMBO_END};
const uint16_t PROGMEM combo_nvim_layer[] = {TKC_LR, CKC_T, COMBO_END};
// const uint16_t PROGMEM combo_dquote[] = {TD(TD_NAV_LAYER), KC_T, COMBO_END};
// const uint16_t PROGMEM combo_quote[] = {TD(TD_NAV_LAYER), KC_S, COMBO_END};
// const uint16_t PROGMEM combo_grave[] = {TD(TD_NAV_LAYER), KC_R, COMBO_END};
// const uint16_t PROGMEM combo_nv_save[] = {KC_R, KC_S, COMBO_END};
// const uint16_t PROGMEM combo_dquote[] = {KC_C, KC_D, COMBO_END};
// const uint16_t PROGMEM combo_quote[] = {KC_X, KC_D, COMBO_END};
// const uint16_t PROGMEM combo_grave[] = {KC_X, KC_C, KC_D, COMBO_END};
//
// const uint16_t PROGMEM combo_lctl[] = {KC_S, KC_T, COMBO_END};
// const uint16_t PROGMEM combo_lshift[] = {KC_R, KC_S, COMBO_END};
// const uint16_t PROGMEM combo_lalt[] = {KC_R, KC_T, COMBO_END};
// const uint16_t PROGMEM combo_lctr_shift_alt[] = {KC_R, KC_S, KC_T, COMBO_END};
//
//
// const uint16_t PROGMEM combo_rctl[] = {KC_N, KC_E, COMBO_END};
// const uint16_t PROGMEM combo_rshift[] = {KC_E, KC_I, COMBO_END};
// const uint16_t PROGMEM combo_ralt[] = {KC_N, KC_I, COMBO_END};
// const uint16_t PROGMEM combo_rctr_shift_alt[] = {KC_N, KC_E, KC_I, COMBO_END};
//
// const uint16_t PROGMEM combo_nv_save[] = {KC_S, KC_D, COMBO_END};
// const uint16_t PROGMEM combo_nv_noa_save[] = {KC_T, KC_C, COMBO_END};


combo_t key_combos[] = {
    COMBO(combo_enter, KC_ENTER),
    COMBO(combo_tab, KC_TAB),

    COMBO(combo_en, LCA(KC_1)),
    COMBO(combo_el, LCA(KC_2)),

    COMBO(combo_slsh, KC_SLSH),
    COMBO(combo_bsls, KC_BSLS),

    COMBO(combo_tmux_layer, MO(TMUX_LAYER)),
    COMBO(combo_nvim_layer, MO(VIM_LAYER)),

    // COMBO(combo_lctl, KC_LCTL),
    // COMBO(combo_lshift, KC_LSFT),
    // COMBO(combo_lalt, KC_LALT),
    // COMBO(combo_lctr_shift_alt, LCTL(LSFT(KC_LALT))),
    //
    // COMBO(combo_rctl, KC_RCTL),
    // COMBO(combo_rshift, KC_RSFT),
    // COMBO(combo_ralt, KC_RALT),
    // COMBO(combo_rctr_shift_alt, RCTL(RSFT(KC_RALT))),
    //
    // COMBO(combo_dquote, KC_DQUO),
    // COMBO(combo_quote, KC_QUOT),
    // COMBO(combo_grave, KC_GRAVE),
    // COMBO(combo_nv_save, COMBO_NV_SAVE),
    // COMBO(combo_nv_noa_save, COMBO_NV_NOA_SAVE),
};
