// #include "keymap_us.h"

#include "keycode.h"
#include "keycodes.h"
#include QMK_KEYBOARD_H

#include "tap_dance.h"
#include "layer.h"

#include "keycode.c"
#include "combo.c"
#include "tap_dance.c"

// clang-format off

const PROGMEM uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS]  = {
     // ⌨️ Base Layer (Colemak-DH)
    [DEF_LAYER] = LAYOUT(
        KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,         KC_J,    KC_L,    KC_U,    KC_Y,    QK_REP,
        KC_A,    KC_R,    KC_S,    KC_T,    KC_G,         KC_M,    KC_N,    KC_E,    KC_I,    KC_O,
        KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,         KC_K,    KC_H,    KC_COMM, KC_DOT,  TD(TD_SCLN_COLN),
                          MO(NUM_LAYER), TD(TD_NAV_LAYER),  LT(SYM_LAYER, KC_SPC), TD(TD_MOD_LAYER)
    ),

    // ✨ Modifier Layer (Home-Row Mods)
    [MOD_LAYER] = LAYOUT(
        _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______,
        HM_A,    HM_R,    HM_S,    HM_T,    _______,      _______, HM_N,    HM_E,    HM_I,    HM_O,
        _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______,
                                   _______, _______,      _______, _______
    ),

    // 🧭 Navigation Layer
    [NAV_LAYER] = LAYOUT(
        _______, _______, KC_PASTE, KC_COPY,       KC_CUT,       KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_CAPS,
        KC_LGUI, HM_GRAVE, HM_QUOT, HM_DQUO,       KC_COLN,      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TAB,
        KC_PSCR, _______, MO(TMUX_LAYER),  MO(VIM_LAYER), _______,      _______, LCTL(KC_D), LCTL(KC_U),_______, _______,
                                   _______, _______,             KC_BSPC, KC_DEL
    ),

    // 🧭 WM Layer
    [WM_LAYER] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        WM_WS_4, WM_WS_3, WM_WS_2, WM_WS_1, WM_WS_5,      XXXXXXX, WM_WS_7, WM_WS_8, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                   XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX
    ),

    // [VIM_LAYER] = LAYOUT(
    //     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //                                XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX
    // ),

    // 🧭 VIM Layer
    [VIM_LAYER] = LAYOUT(
        _______, _______, _______, _______, _______,      NV_TAB_NEW, NV_BUF_CLOSE, NV_BUF_DELETE, NV_TAB_CLOSE, _______,
        _______, _______, _______, _______, _______,      NV_TAB_PREV, _______, _______, NV_TAB_PREV, _______,
        _______, _______, _______, XXXXXXX, _______,      _______, NV_SPLIT_V, NV_SPLIT_H, _______, _______,
                                   _______, _______,      _______, _______
    ),

    // 🧭 TMUX Layer
    [TMUX_LAYER] = LAYOUT(
        _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______,
        _______, _______, XXXXXXX, _______, _______,      _______, _______, _______, _______, _______,
                                   _______, _______,      _______, _______
    ),

    // 💲 Symbol Layer
    [SYM_LAYER] = LAYOUT(
        KC_TILD, _______, KC_AMPR, KC_BSLS, KC_AT,        KC_HASH, KC_SLSH, KC_PERC, _______, _______,
        KC_CIRC, KC_LCBR, KC_LPRN, KC_RPRN, KC_RCBR,      KC_LABK, KC_LBRC, KC_RBRC, KC_RABK, KC_DLR,
        _______, KC_PLUS, KC_EQL,  KC_MINS, KC_PIPE,      KC_ASTR, KC_UNDS, KC_QUES, KC_EXLM, _______,
                                   _______, _______,      KC_BSPC, KC_DEL
    ),

    // 🔢 Number Layer
    [NUM_LAYER] = LAYOUT(
        _______, _______, _______, _______, _______,      _______, KC_7,    KC_8,    KC_9,    _______,
        KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, _______,      KC_0,    KC_4,    KC_5,    KC_6,    _______,
        _______, KC_PLUS, KC_EQL,  KC_MINS, _______,      KC_ASTR, KC_1,    KC_2,    KC_3,    _______,
                                   _______, _______,      KC_BSPC, KC_DEL
    ),
};

// clang-format on
