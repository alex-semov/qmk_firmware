#include QMK_KEYBOARD_H

#include "modifiers.h"
#include "keycodes.h"

enum custom_keycodes {
    SMTD_KEYCODES_BEGIN = SAFE_RANGE,
    CKC_A,
    CKC_R,
    CKC_S,
    CKC_T,
    CKC_N,
    CKC_E,
    CKC_I,
    CKC_O,

    CKC_SPC,
    CKC_DEL,
    SMTD_KEYCODES_END,
};

#include "sm_td.h"

enum layers { DEF, SYM, NAV, NUM };

// #define L_NAV MO(NAV)
// #define L_SYM MO(SYM)
// #define L_NUM MO(NUM)

// clang-format off

const PROGMEM uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS]  = {
  [DEF] = LAYOUT(
           KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,             KC_J,    KC_L,    KC_U,    KC_Y,   KC_QUOT,
           CKC_A,    CKC_R,    CKC_S,    CKC_T,    KC_G,         KC_M,    CKC_N,    CKC_E,    CKC_I,   CKC_O,
           KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,             KC_K,    KC_H,    KC_COMM, KC_DOT, KC_SCLN,
                XXXXXXX, MO(NAV),   CKC_DEL,                      KC_BSPC, CKC_SPC, QK_REP
  ),

  [NAV] = LAYOUT(
          KC_ESC, XXXXXXX, KC_PASTE, KC_COPY, XXXXXXX,            XXXXXXX,  KC_PGDN, KC_PGUP, XXXXXXX, KC_DEL,
          KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, XXXXXXX,            KC_LEFT,  KC_DOWN, KC_UP,   KC_RGHT, KC_ENT,
          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,            _______,  KC_TAB, XXXXXXX, XXXXXXX, KC_CAPS,
                            XXXXXXX, XXXXXXX, XXXXXXX,            _______, _______, _______
  ),

  [SYM] = LAYOUT(
          XXXXXXX, XXXXXXX, XXXXXXX, KC_HASH, KC_TILD,            KC_EQL,  KC_MINS, KC_PLUS, KC_PERC, KC_GRV,
          XXXXXXX, KC_LALT, KC_LSFT, KC_LCTL, KC_DLR,             KC_CIRC, KC_LPRN, KC_LCBR, KC_LBRC, KC_LABK,
          KC_PIPE, XXXXXXX, XXXXXXX, KC_UNDS, KC_AMPR,            KC_SLSH, KC_QUES, KC_EXLM, KC_ASTR, KC_AT,
                            XXXXXXX, XXXXXXX, XXXXXXX,            XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [NUM] = LAYOUT(
          XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, KC_7, KC_8, KC_9, XXXXXXX,
          KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL,   XXXXXXX,          KC_0,    KC_4, KC_5, KC_6, KC_ENT,
          XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, KC_1, KC_2, KC_3, XXXXXXX,
                              XXXXXXX, XXXXXXX, XXXXXXX,          _______, XXXXXXX, XXXXXXX
  ),

};

// clang-format on

void on_smtd_action(uint16_t keycode, smtd_action action, uint8_t tap_count) {
    switch (keycode) {
        SMTD_MT(CKC_A, KC_A, KC_LEFT_GUI)
        SMTD_MT(CKC_R, KC_R, KC_LEFT_ALT)
        SMTD_MT(CKC_S, KC_S, KC_LSFT)
        SMTD_MT(CKC_T, KC_T, KC_LEFT_CTRL)

        SMTD_MT(CKC_N, KC_N, KC_RIGHT_CTRL)
        SMTD_MT(CKC_E, KC_E, KC_RIGHT_SHIFT)
        SMTD_MT(CKC_I, KC_I, KC_RIGHT_ALT)
        SMTD_MT(CKC_O, KC_O, KC_O)

        SMTD_LT(CKC_SPC, KC_SPC, SYM)
        SMTD_LT(CKC_DEL, KC_DEL, NUM)
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_smtd(keycode, record)) {
        return false;
    }

    // your rest code here
    return true;
}
