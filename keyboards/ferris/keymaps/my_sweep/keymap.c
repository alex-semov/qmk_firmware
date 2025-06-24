#include QMK_KEYBOARD_H

#include "quantum_keycodes.h"
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

    // CKC_COMM,
    // CKC_DOT,

    CKC_BSPC,
    CKC_SPC,
    // CKC_DEL,

    CKC_LALT,
    CKC_LSFT,
    CKC_LCTL,

    CKC_RPRN,
    CKC_LCBR,

    CKC_LBRC,
    CKC_RABK,

    CKC_ESC,

    SMTD_KEYCODES_END,
};

#include "sm_td.h"

enum layers { DEF, NAV, SYM, NUM };

const uint16_t PROGMEM combo_enter[] = {CKC_N, CKC_E, COMBO_END};
// const uint16_t PROGMEM combo_ent[] = {CKC_N, KC_I, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_enter, KC_ENTER),
    // COMBO(combo_ent, KC_ENT),
};

// #define KT_LL MO(NAV)
// #define KT_LR KC_DEL
//
// #define KT_RL KC_BSPC
// #define KT_RR KC_SPC

// clang-format off

const PROGMEM uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS]  = {
  [DEF] = LAYOUT(
           KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,             KC_J,    KC_L,    KC_U,    KC_Y,   OSM(MOD_RSFT),
           CKC_A,   CKC_R,   CKC_S,   CKC_T,   KC_G,             KC_M,    CKC_N,   CKC_E,   CKC_I,  CKC_O,
           KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,             KC_K,    KC_H,    KC_COMM, KC_DOT, KC_SCLN,
                                      CKC_BSPC, CKC_ESC,         CKC_SPC, QK_REP
  ),


  [NAV] = LAYOUT(
          XXXXXXX, XXXXXXX, KC_PASTE, KC_COPY, KC_CUT,            XXXXXXX,  KC_PGDN, KC_PGUP, XXXXXXX, KC_CAPS,
          KC_LGUI, CKC_LALT, CKC_LSFT, CKC_LCTL, KC_COLN,         KC_LEFT,  KC_DOWN, KC_UP,   KC_RGHT, KC_TAB,
          KC_PSCR, XXXXXXX, XXXXXXX, KC_UNDO, XXXXXXX,            KC_HOME,   LCTL(KC_D), LCTL(KC_U), XXXXXXX, KC_END,
                                     XXXXXXX, XXXXXXX,            KC_BSPC, KC_DEL
  ),

  [SYM] = LAYOUT(
      KC_TILD, _______, KC_AMPR,  KC_BSLS, KC_AT,        KC_HASH, KC_SLSH,  KC_PERC, _______, _______,
      KC_CIRC, CKC_LCBR, KC_LPRN, CKC_RPRN, KC_RCBR,     KC_LABK, CKC_LBRC, KC_RBRC, CKC_RABK, KC_DLR,
      _______, KC_PLUS, KC_EQL,   KC_MINS, KC_PIPE,      KC_ASTR, KC_UNDS,  KC_QUES, KC_EXLM, _______,
                                 _______, _______,    _______, _______
  ),


//     [6] = LAYOUT(
//         KC_PSLS,      KC_7,         KC_8,         KC_9,         KC_PPLS,           KC_TRNS,      KC_TRNS,      KC_TRNS,         KC_TRNS,         KC_TRNS,
//         KC_0,         KC_1,         KC_2,         KC_3,         KC_PMNS,           KC_TRNS,      KC_TRNS,      KC_TRNS,         KC_NO,           KC_TRNS,
//         KC_PAST,      KC_4,         KC_5,         KC_6,         KC_PEQL,           KC_TRNS,      KC_TRNS,      KC_TRNS,         KC_TRNS,         KC_TRNS,
//                                     KC_TRNS,      KC_TRNS,                         KC_TRNS,      KC_TRNS
//     ),
  [NUM] = LAYOUT(
          XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, KC_7, KC_8, KC_9, XXXXXXX,
          KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL,   XXXXXXX,          KC_0,    KC_4, KC_5, KC_6, XXXXXXX,
          XXXXXXX, KC_PLUS, KC_EQL,  KC_MINS,   XXXXXXX,          KC_ASTR, KC_1, KC_2, KC_3, XXXXXXX,
                                     XXXXXXX, XXXXXXX,            KC_BSPC, KC_DEL
  ),
};

void on_smtd_action(uint16_t keycode, smtd_action action, uint8_t tap_count) {
    switch (keycode) {
        // SMTD_MT(CKC_A, KC_A, KC_LEFT_GUI)
        // SMTD_MT(CKC_S, KC_S, KC_LSFT)
        // SMTD_MT(CKC_R, KC_R, KC_LEFT_ALT)
        // SMTD_MT(CKC_T, KC_T, KC_LEFT_CTRL)
        SMTD_LT(CKC_BSPC, KC_BSPC, NUM)
        SMTD_LT(CKC_SPC, KC_SPC, SYM)
        SMTD_LT(CKC_ESC, KC_ESC, NAV)

        SMTD_MT(CKC_T, KC_T, KC_LEFT_CTRL)
        SMTD_MT(CKC_S, KC_S, KC_LEFT_SHIFT)
        SMTD_MT(CKC_R, KC_R, KC_LEFT_ALT)
        SMTD_MT(CKC_A, KC_A, KC_LEFT_GUI)

        SMTD_MT(CKC_N, KC_N, KC_RIGHT_CTRL)
        SMTD_MT(CKC_E, KC_E, KC_RIGHT_SHIFT)
        SMTD_MT(CKC_I, KC_I, KC_RIGHT_ALT)
        SMTD_MT(CKC_O, KC_O, KC_RIGHT_GUI)

        // SMTD_MT(CKC_X, KC_X, KC_LEFT_ALT)
        // SMTD_MT(CKC_C, KC_C, KC_LEFT_CTRL)

        // SMTD_MT(CKC_E, KC_E, KC_RIGHT_SHIFT)
        // SMTD_MT(CKC_O, KC_O, KC_O)
        // SMTD_MT(CKC_COMM, KC_COMM, KC_RIGHT_CTRL)
        // SMTD_MT(CKC_DOT, KC_DOT, KC_RIGHT_ALT)

        // SMTD_LT(CKC_SPC, KC_SPC, SYM)
        // SMTD_LT(CKC_DEL, KC_DEL, NUM)

        // NAV
        SMTD_MT(CKC_LCTL, KC_DQUO, KC_LEFT_CTRL)
        SMTD_MT(CKC_LSFT, KC_QUOT, KC_LEFT_SHIFT)
        SMTD_MT(CKC_LALT, KC_GRAVE, KC_LEFT_ALT)

        // SYM
        SMTD_MT(CKC_RPRN, KC_RPRN, KC_LEFT_CTRL)
        SMTD_MT(CKC_LCBR, KC_LCBR, KC_LEFT_ALT)

        SMTD_MT(CKC_LBRC, KC_LBRC, KC_RIGHT_CTRL)
        SMTD_MT(CKC_RABK, KC_RABK, KC_RIGHT_ALT)
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_smtd(keycode, record)) {
        return false;
    }

    // your rest code here
    return true;
}
/*
 * LAYOUT for the Ferris Sweep
 *
 * This keymap is formatted to visually represent the physical layout of the split keyboard.
 * Each row is split into a left and right half, separated by a wide gap.
 *
 * The `LAYOUT` macro takes all 34 keycodes in the following order:
 * - Top Row (Left): 5 keys
 * - Top Row (Right): 5 keys
 * - Middle Row (Left): 5 keys
 * - Middle Row (Right): 5 keys
 * - Bottom Row (Left): 5 keys
 * - Bottom Row (Right): 5 keys
 * - Thumbs (Left): 2 keys
 * - Thumbs (Right): 2 keys
 */

// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//     /*
//      * Layer 0: Base QWERTY Layout
//      *
//      * Hold-tap behavior:
//      * - LT(layer, key): Tapping sends `key`, holding activates `layer`.
//      * - MOD_T(mod, key): Tapping sends `key`, holding applies `mod` (e.g., LCTL_T for Left Control).
//      */
//     [0] = LAYOUT(
//         KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,              KC_Y,         KC_U,         KC_I,            KC_O,            KC_P,
//         LSFT_T(KC_A), LT(5,KC_S),    LT(1,KC_D),   LT(3,KC_F),   KC_G,              KC_H,         LT(4,KC_J),   LT(2,KC_K),      LT(6,KC_L),      LSFT_T(KC_SCLN),
//         KC_Z,         LCTL_T(KC_X), LALT_T(KC_C), KC_V,         KC_B,              KC_N,         KC_M,         LALT_T(KC_COMM), LCTL_T(KC_DOT),  KC_SLSH,
//                                     KC_P0,        KC_BSPC,                         LT(7,KC_SPC), KC_P1
//     ),
//
//     /*
//      * Layer 1: Mouse Control
//      */
//     [1] = LAYOUT(
//         KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,           KC_BTN1,      KC_WH_U,      KC_BTN2,         KC_TRNS,         KC_TRNS,
//         KC_TRNS,      KC_BTN2,      KC_NO,        KC_BTN1,      KC_TRNS,           KC_MS_L,      KC_MS_D,      KC_MS_U,         KC_MS_R,         KC_TRNS,
//         KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,           KC_WH_L,      KC_WH_D,      KC_WH_R,         KC_TRNS,         KC_TRNS,
//                                     KC_TRNS,      KC_TRNS,                         KC_TRNS,      KC_TRNS
//     ),
//
//     /*
//      * Layer 2: Navigation
//      */
//     [2] = LAYOUT(
//         KC_TRNS,      KC_TRNS,      KC_PGUP,      KC_TRNS,      KC_TRNS,           KC_TRNS,      KC_TRNS,      KC_TRNS,         KC_TRNS,         KC_TRNS,
//         KC_LEFT,      KC_UP,        KC_DOWN,      KC_RGHT,      KC_TRNS,           KC_LGUI,      KC_NO,        LCTL(KC_LALT),   LCA(KC_LSFT),    KC_TRNS,
//         KC_HOME,      KC_PGDN,      KC_END,       KC_TRNS,      KC_TRNS,           KC_TRNS,      KC_TRNS,      KC_TRNS,         KC_TRNS,         KC_TRNS,
//                                     KC_TRNS,      KC_TRNS,                         KC_TRNS,      KC_TRNS
//     ),
//
//     /*
//      * Layer 3: Symbols 1
//      */
//     [3] = LAYOUT(
//         KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,           KC_UNDS,      KC_PIPE,      KC_QUOT,         KC_TRNS,         KC_TRNS,
//         KC_CIRC,      KC_ASTR,      KC_AMPR,      KC_NO,        KC_TRNS,           KC_HASH,      KC_TILD,      KC_SLSH,         KC_DQUO,         KC_DLR,
//         KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,           KC_MINS,      KC_BSLS,      KC_GRV,          KC_TRNS,         KC_TRNS,
//                                     RM_PREV,      KC_TRNS,                         KC_TRNS,      RM_NEXT
//     ),
//
//     /*
//      * Layer 4: Symbols 2 (Brackets, Parentheses)
//      */
//     [4] = LAYOUT(
//         KC_TRNS,      KC_COLN,      KC_LT,        KC_GT,        KC_SCLN,           KC_TRNS,      KC_TRNS,      KC_TRNS,         KC_TRNS,         KC_TRNS,
//         KC_LCBR,      KC_RCBR,      KC_LPRN,      KC_RPRN,      KC_AT,             KC_NO,        KC_EQL,       KC_PLUS,         KC_PERC,         KC_TRNS,
//         KC_EXLM,      KC_LBRC,      KC_RBRC,      KC_TRNS,      KC_TRNS,           KC_TRNS,      KC_TRNS,      KC_TRNS,         KC_TRNS,         KC_TRNS,
//                                     KC_VOLD,      KC_TRNS,                         KC_TRNS,      KC_VOLU
//     ),
//
//     /*
//      * Layer 5: Function Keys (F1-F12)
//      */
//     [5] = LAYOUT(
//         KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,           KC_F7,        KC_F8,        KC_F9,           KC_F10,          KC_TRNS,
//         KC_TRNS,      KC_NO,        LCTL(KC_LALT),KC_TRNS,      KC_TRNS,           KC_F4,        KC_F5,        KC_F6,           KC_F11,          KC_TRNS,
//         KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,           KC_F1,        KC_F2,        KC_F3,           KC_F12,          KC_TRNS,
//                                     KC_TRNS,      KC_TRNS,                         KC_TRNS,      KC_TRNS
//     ),
//
//     /*
//      * Layer 6: Numpad
//      */
//     [6] = LAYOUT(
//         KC_PSLS,      KC_7,         KC_8,         KC_9,         KC_PPLS,           KC_TRNS,      KC_TRNS,      KC_TRNS,         KC_TRNS,         KC_TRNS,
//         KC_0,         KC_1,         KC_2,         KC_3,         KC_PMNS,           KC_TRNS,      KC_TRNS,      KC_TRNS,         KC_NO,           KC_TRNS,
//         KC_PAST,      KC_4,         KC_5,         KC_6,         KC_PEQL,           KC_TRNS,      KC_TRNS,      KC_TRNS,         KC_TRNS,         KC_TRNS,
//                                     KC_TRNS,      KC_TRNS,                         KC_TRNS,      KC_TRNS
//     ),
//
//     /*
//      * Layer 7: System & Special Keys
//      */
//     [7] = LAYOUT(
//         KC_TRNS,      KC_TRNS,      KC_COLN,      KC_ESC,       KC_TRNS,           KC_TRNS,      KC_TRNS,      KC_TRNS,         KC_TRNS,         KC_DEL,
//         KC_TRNS,      KC_PERC,      KC_SLSH,      KC_ENT,       KC_TRNS,           DF(1),        KC_LGUI,      KC_TRNS,         KC_TRNS,         KC_TRNS,
//         KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_EXLM,      KC_TRNS,           DF(0),        KC_TRNS,      RALT_T(KC_COMM), RCTL_T(KC_DOT),  QK_BOOT,
//                                     KC_TRNS,      KC_TAB,                          KC_NO,        KC_TRNS
//     )
// };
