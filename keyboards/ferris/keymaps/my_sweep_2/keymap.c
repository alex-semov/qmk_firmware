#include "quantum_keycodes.h"
#include QMK_KEYBOARD_H

#include "tap_dance.h"
#include "layer.h"
#include "keycode.h"

#include "keycode.c"
#include "combo.c"
#include "tap_dance.c"

// clang-format off

const PROGMEM uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS]  = {
     // ⌨️ Base Layer (Colemak-DH)
    [DEF_LAYER] = LAYOUT(
        KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,         KC_J,    KC_L,    KC_U,    KC_Y,    QK_REP,
        KC_A,    KC_R,    CKC_S, CKC_T,    KC_G,         KC_M,   CKC_N, CKC_E, KC_I,    KC_O,
        KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,         KC_K,    KC_H,    KC_COMM, KC_DOT,  TD(TD_SCLN_COLN),
                          TKC_LL, TKC_LR,               TKC_RL, TKC_RR
    ),

    // 🧭 Navigation Layer
    [NAV_LAYER] = LAYOUT(
        XXXXXXX, XXXXXXX, KC_PASTE, KC_COPY, KC_CUT,       KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_CAPS,
        XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL,  KC_COLN,      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TAB,
        KC_PSCR, XXXXXXX, MO(TMUX_LAYER),  MO(VIM_LAYER), XXXXXXX,      XXXXXXX, LCTL(KC_D), LCTL(KC_U),XXXXXXX, XXXXXXX,
                                   XXXXXXX, XXXXXXX,             KC_BSPC, KC_RSFT
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
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      NV_TAB_NEW, NV_BUF_CLOSE, NV_BUF_DELETE, NV_TAB_CLOSE, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      NV_TAB_PREV, NV_PANE_ZOOM_V, NV_PANE_ZOOM_H, NV_TAB_NEXT,  NV_PANE_EQ,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, NV_SPLIT_V, NV_SPLIT_H, XXXXXXX, XXXXXXX,
                                   XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX
    ),

    // 🧭 TMUX Layer
    [TMUX_LAYER] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      TM_WIN_NEW, TM_PANE_CLOSE, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      TM_SES_PREV, TM_WIN_PREV, TM_WIN_NEXT, TM_SES_NEXT, TM_PANE_ZOOM,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, TM_SPLIT_H, TM_SPLIT_V, XXXXXXX, XXXXXXX,
                                   XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX
    ),

    // 💲 Symbol Layer
    [SYM_LAYER] = LAYOUT(
        KC_TILD, XXXXXXX, KC_AMPR, KC_BSLS, KC_AT,        KC_HASH, KC_SLSH, KC_PERC, XXXXXXX, XXXXXXX,
        KC_CIRC, KC_LCBR, LALT_T(KC_LPRN), LCTL_T(KC_RPRN), KC_RCBR,      KC_LABK, RCTL_T(KC_LBRC), RALT_T(KC_RBRC), KC_RABK, KC_DLR,
        XXXXXXX, KC_PLUS, KC_EQL,  KC_MINS, KC_PIPE,      KC_ASTR, KC_UNDS, KC_QUES, KC_EXLM, XXXXXXX,
                                   XXXXXXX, XXXXXXX,      KC_BSPC, KC_DEL
    ),

    // 🔢 Number Layer
    [NUM_LAYER] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, KC_7,    KC_8,    KC_9,    XXXXXXX,
        XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, XXXXXXX,      XXXXXXX,    KC_4,    KC_5,    KC_6,    KC_0,
        XXXXXXX, KC_PLUS, KC_EQL,  KC_MINS, XXXXXXX,      KC_ASTR, KC_1,    KC_2,    KC_3,    XXXXXXX,
                                   XXXXXXX, XXXXXXX,      KC_BSPC, KC_DEL
    ),
};

// clang-format on
