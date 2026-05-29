#include QMK_KEYBOARD_H

#include "oneshot.h"
#include "swapper.h"


#define HOME G(KC_LEFT)
#define END G(KC_RGHT)
#define FWD G(KC_RBRC)
#define BACK G(KC_LBRC)
#define TAB_L G(S(KC_LBRC))
#define TAB_R G(S(KC_RBRC))
#define SPACE_L A(G(KC_LEFT))
#define SPACE_R A(G(KC_RGHT))
#define LA_SYM MO(SYM)
#define LA_NAV MO(NAV)
#define LA_NUM MO(NUM)

enum layers {
    DEF,
    SYM,
    NAV,
    NUM,
};

enum keycodes {
    // Custom oneshot mod implementation with no timers.
    OS_SHFT = SAFE_RANGE,
    OS_CTRL,
    OS_ALT,
    OS_CMD,

    SW_WIN,  // Switch to next window         (cmd-tab)
    SW_LANG, // Switch to next input language (ctl-spc)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // [DEF] = LAYOUT(
  //         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,
  //         KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,
  //         KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,
  //                          KC_ESC, KC_SPC,  LA_NAV,                         KC_ENT, KC_BSPC, LA_SYM
  // ),
    // [DEF] = LAYOUT(
    //        KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y,   KC_QUOT,
    //        // KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                         KC_M,    KC_N,    KC_E,    KC_I,   KC_O,
    //        LGUI_T(KC_A), LALT_T(KC_R), LSFT_T(KC_S), LCTL_T(KC_T), KC_G,   KC_M,  RCTL_T(KC_N), RSFT_T(KC_E), LALT_T(KC_I), KC_O,
    //        KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H,    KC_COMM, KC_DOT, KC_SCLN,
    //                          LA_NUM,  LA_NAV, OS_SHFT,                       KC_ESC, KC_SPC, LA_SYM
    // ),
    [DEF] = LAYOUT(
           KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y,   KC_QUOT,
           KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                         KC_M,    KC_N,    KC_E,    KC_I,   KC_O,
           KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H,    KC_COMM, KC_DOT, KC_SCLN,
                             LA_NUM,  LA_NAV, OS_SHFT,                       KC_ESC, KC_SPC, LA_SYM
    ),


    // [DEF] = LAYOUT(
    //        KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y,   KC_QUOT,
    //        // KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                         KC_M,    KC_N,    KC_E,    KC_I,   KC_O,
    //        LGUI_T(KC_A), LALT_T(KC_R), LSFT_T(KC_S), LCTL_T(KC_T), KC_G,   KC_M,  RCTL_T(KC_N), RSFT_T(KC_E), RALT_T(KC_I), RGUI_T(KC_O),
    //        KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H,    KC_COMM, KC_DOT, KC_SCLN,
    //                          LA_NUM,  LA_NAV, OS_SHFT,                       KC_ESC, KC_SPC, LA_SYM
    // ),

  [NAV] = LAYOUT(
          KC_CAPS,  SW_WIN,  KC_PASTE, KC_COPY, KC_CUT,                      HOME,  KC_PGDN, KC_PGUP, END, KC_PSCR,
          OS_CMD, OS_ALT, OS_SHFT, OS_CTRL, XXXXXXX,                          KC_LEFT,  KC_DOWN, KC_UP,   KC_RGHT, KC_ENT,
          SPACE_L, SPACE_R, BACK,    FWD,     XXXXXXX,                      XXXXXXX,  XXXXXXX, XXXXXXX, SW_LANG, XXXXXXX,
                            _______, _______, _______,                      KC_TAB, KC_BSPC, KC_DEL
  ),

  [SYM] = LAYOUT(
          KC_LABK,  KC_LBRC, KC_LCBR, KC_LPRN, KC_TILD,                     KC_CIRC, KC_RPRN, KC_RCBR, KC_RBRC, KC_RABK,
          KC_MINS, KC_ASTR, KC_EQL, KC_SLSH, KC_DLR,                       KC_HASH, KC_BSLS, _______, _______, KC_GRV,
          KC_PLUS, KC_PIPE, KC_AT,   KC_UNDS, KC_PERC,                      KC_PERC, KC_AMPR, _______, KC_QUES, KC_EXLM,
                            _______, KC_LCTL, _______,                      _______, _______, _______
  ),



  [NUM] = LAYOUT(
          KC_7,    KC_5,    KC_3,    KC_1,    KC_9,                         KC_8,    KC_0,    KC_2,    KC_4,    KC_6,
          OS_CMD, OS_ALT, OS_SHFT, OS_CTRL, KC_F11,                       KC_F10,   OS_CTRL, OS_SHFT, OS_ALT,OS_CMD,
          KC_F7,   KC_F5,   KC_F3,   KC_F1,   KC_F9,                        KC_F8,   KC_F12,  KC_F2,   KC_F4,   KC_F6,
                            _______, _______, _______,                      KC_ENT, KC_BSPC, KC_DEL
  ),

};



// void keyboard_post_init_user(void) {
//   // Customise these values to desired behaviour
//   debug_enable=true;
//   debug_matrix=true;
//   debug_keyboard=true;
//   //debug_mouse=true;
// }

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case LA_SYM:
    case LA_NAV:
    case LA_NUM:
        return true;
    default:
        return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    case LA_SYM:
    case LA_NAV:
    case LA_NUM:
    case KC_LSFT:
    case OS_SHFT:
    case OS_CTRL:
    case OS_ALT:
    case OS_CMD:
        return true;
    default:
        return false;
    }
}

bool sw_win_active = false;
bool sw_lang_active = false;

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_swapper(
        &sw_win_active, KC_LGUI, KC_TAB, SW_WIN,
        keycode, record
    );
    update_swapper(
        &sw_lang_active, KC_LCTL, KC_SPC, SW_LANG,
        keycode, record
    );

    update_oneshot(
        &os_shft_state, KC_LSFT, OS_SHFT,
        keycode, record
    );
    update_oneshot(
        &os_ctrl_state, KC_LCTL, OS_CTRL,
        keycode, record
    );
    update_oneshot(
        &os_alt_state, KC_LALT, OS_ALT,
        keycode, record
    );
    update_oneshot(
        &os_cmd_state, KC_LCMD, OS_CMD,
        keycode, record
    );

    return true;
}

// layer_state_t layer_state_set_user(layer_state_t state) {
//     return update_tri_layer_state(state, SYM, NAV, NUM);
// }
