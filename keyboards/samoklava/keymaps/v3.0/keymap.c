#include QMK_KEYBOARD_H

#include "print.h"

enum layers { DEF, MOD_LEFT, MOD_RIGHT, SYM, ALT_SYM, NAV, NUM  };

enum custom_keycodes {
  MOD_THUMB = SAFE_RANGE,
};

typedef struct {
  uint16_t keycode;
  uint16_t modifier;
  uint8_t layer;
} mod_key_t;

const mod_key_t mod_keys[] = {
    {KC_J, KC_LCTL, MOD_RIGHT}, {KC_K, KC_LSFT, MOD_RIGHT},
    {KC_L, KC_LALT, MOD_RIGHT}, {KC_P, KC_LGUI, MOD_RIGHT},
    {KC_F, KC_RCTL, MOD_LEFT},  {KC_D, KC_RSFT, MOD_LEFT},
    {KC_S, KC_RALT, MOD_LEFT},  {KC_A, KC_RGUI, MOD_LEFT},
};

#define NUM_MOD_KEYS (sizeof(mod_keys) / sizeof(mod_keys[0]))

bool mod_active = false;

#define L_NAV MO(NAV)
#define L_SYM MO(SYM)
#define L_NUM MO(NUM)

#define LT1 L_NUM
#define LT2 L_NAV
#define LT3 LT(L_SYM, KC_ESC)

#define RT1 OSM(MOD_LSFT)
#define RT2 KC_SPC
#define RT3 QK_REP

// clang-format off
//
// flow_config should correspond to following format:
// * layer keycode
// * modifier keycode
const uint16_t flow_config[FLOW_COUNT][2] = {
    {L_NAV, KC_LALT},
    {L_NAV, KC_LGUI},
    {L_NAV, KC_LCTL},
    {L_NAV, KC_LSFT},
    {L_SYM, KC_LCTL},
    {L_SYM, KC_LALT},
    {L_SYM, KC_LSFT},
};


// for layers configuration follow this format:
// * custom layer key
// * layer name
const uint16_t flow_layers_config[FLOW_LAYERS_COUNT][2] = {
    {OS_TMUX, TMUX},
    {OS_ALT_SYM, ALT_SYM},
    // {OS_MISC, _MISC},
    // {OS_FUNC, _FUNC},
};
// clang-format on

// clang-format off
// enum keycodes {
//     // Custom oneshot mod implementation with no timers.
//     OS_SHFT = SAFE_RANGE,
//     OS_CTRL,
//     OS_ALT,
//     OS_CMD,
//
//     SW_WIN,  // Switch to next window         (cmd-tab)
//     SW_LANG, // Switch to next input language (ctl-spc)
// };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // [DEF] = LAYOUT(
  //         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,
  //         KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,
  //         KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,
  //                           XXXXXXX, L_NAV,   LT(L_NUM,  KC_DEL),           MT(MOD_LSFT, KC_BSPC), LT(SYM, KC_SPC), QK_REP
  // ),
    // [DEF] = LAYOUT(
    //        KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y,   KC_QUOT,
    //        // KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                         KC_M,    KC_N,    KC_E,    KC_I,   KC_O,
    //        LGUI_T(KC_A), LALT_T(KC_R), LSFT_T(KC_S), LCTL_T(KC_T), KC_G,   KC_M,  RCTL_T(KC_N), RSFT_T(KC_E), LALT_T(KC_I), KC_O,
    //        KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H,    KC_COMM, KC_DOT, KC_SCLN,
    //                          LA_NUM,  LA_NAV, OS_SHFT,                       KC_ESC, KC_SPC, LA_SYM
    // ),
    // [DEF] = LAYOUT(
    //        KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y,   KC_QUOT,
    //        KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                         KC_M,    KC_N,    KC_E,    KC_I,   KC_O,
    //        KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H,    KC_COMM, KC_DOT, KC_SCLN,
    //                          LT1,     LT2,     LT3,                          RT1,     RT2,     RT3
  [DEF] = LAYOUT(
          KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,
          KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,
          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,
                                     L_NUM, L_NAV,   LT(0,  MOD_THUMB),     MT(MOD_LSFT, KC_BSPC), LT(SYM, KC_SPC), L_SYM
                            // L_NUM, L_NAV,   MOD_THUMB,           MT(MOD_LSFT, KC_BSPC), LT(SYM, KC_SPC), L_SYM
  ),


    // KC_BSPC,  LT(L_NAV, KC_ESC), QK_REP,            KC_LSFT, LT(L_SYM, KC_SPC), KC_DEL
    // [DEF] = LAYOUT(
    //        KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y,   KC_QUOT,
    //        // KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                         KC_M,    KC_N,    KC_E,    KC_I,   KC_O,
    //        LGUI_T(KC_A), LALT_T(KC_R), LSFT_T(KC_S), LCTL_T(KC_T), KC_G,   KC_M,  RCTL_T(KC_N), RSFT_T(KC_E), RALT_T(KC_I), RGUI_T(KC_O),
    //        KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H,    KC_COMM, KC_DOT, KC_SCLN,
    //                          LA_NUM,  LA_NAV, OS_SHFT,                       KC_ESC, KC_SPC, LA_SYM
    // ),

  [NAV] = LAYOUT(
          KC_ESC, XXXXXXX, KC_PASTE, KC_COPY, XXXXXXX,                        XXXXXXX,  KC_PGDN, KC_PGUP, XXXXXXX, KC_DEL,
          KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, XXXXXXX,                        KC_LEFT,  KC_DOWN, KC_UP,   KC_RGHT, KC_ENT,
          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, OS_TMUX,                        _______,  KC_TAB, XXXXXXX, XXXXXXX, KC_CAPS,
                            XXXXXXX, XXXXXXX, XXXXXXX,                        _______, _______, _______
  ),

  [MOD_LEFT] = LAYOUT(
          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        _______,  _______, _______, _______, _______,
          KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, XXXXXXX,                        _______,  _______, _______, _______, _______,
          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        _______,  _______, _______, _______, _______,
                            XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [MOD_RIGHT] = LAYOUT(
          _______, _______, _______, _______, _______,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
          _______, _______, _______, _______, _______,                        XXXXXXX, KC_RCTL, KC_RSFT, KC_RALT, KC_RGUI,
          _______, _______, _______, _______, _______,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                            XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [SYM] = LAYOUT(
          XXXXXXX, XXXXXXX, XXXXXXX, KC_HASH, KC_TILD,                        KC_EQL,  KC_MINS, KC_PLUS, KC_PERC, KC_GRV,
          XXXXXXX, KC_LALT, KC_LSFT, KC_LCTL, KC_DLR,                         KC_CIRC, KC_LPRN, KC_LCBR, KC_LBRC, KC_LABK,
          KC_PIPE, XXXXXXX, XXXXXXX, KC_UNDS, KC_AMPR,                        KC_SLSH, KC_QUES, KC_EXLM, KC_ASTR, KC_AT,
                            XXXXXXX, XXXXXXX, XXXXXXX,                        _______, OS_ALT_SYM, XXXXXXX
  ),

  [ALT_SYM] = LAYOUT(
          XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
          XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_RPRN, KC_RCBR, KC_RBRC, KC_RABK,
          XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,                      KC_BSLS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                              XXXXXXX, XXXXXXX, XXXXXXX,                      _______, XXXXXXX, XXXXXXX
  ),

  [NUM] = LAYOUT(
          XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_7, KC_8, KC_9, XXXXXXX,
          KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL,   XXXXXXX,                      KC_0,    KC_4, KC_5, KC_6, KC_ENT,
          XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_1, KC_2, KC_3, XXXXXXX,
                              XXXXXXX, XXXXXXX, XXXXXXX,                      _______, XXXXXXX, XXXXXXX
  ),

  [TMUX] = LAYOUT(
          XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, TM_URL,  XXXXXXX, XXXXXXX, XXXXXXX,
          XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,                      TM_LEFT, TM_NEXT, TM_PREV, TM_RIGHT, XXXXXXX,
          XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,                      TM_NEW, TM_SLCT, XXXXXXX, XXXXXXX, TM_SRCH, 
                              XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [TMUX] = LAYOUT(
          XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, TM_URL,  XXXXXXX, XXXXXXX, XXXXXXX,
          XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,                      TM_LEFT, TM_NEXT, TM_PREV, TM_RIGHT, XXXXXXX,
          XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,                      TM_NEW, TM_SLCT, XXXXXXX, XXXXXXX, TM_SRCH, 
                              XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX
  ),
  /* [NUM] = LAYOUT(
          KC_7,    KC_5,    KC_3,    KC_1,    KC_9,                         KC_8,    KC_0,    KC_2,    KC_4,    KC_6,
          OS_CMD, OS_ALT, OS_SHFT, OS_CTRL, KC_F11,                       KC_F10,   OS_CTRL, OS_SHFT, OS_ALT,OS_CMD,
          KC_F7,   KC_F5,   KC_F3,   KC_F1,   KC_F9,                        KC_F8,   KC_F12,  KC_F2,   KC_F4,   KC_F6,
                            _______, XXXXXXX, XXXXXXX,                      _______, XXXXXXX, _______
  ), */

};

// clang-format on

// void keyboard_post_init_user(void) {
//   // Customise these values to desired behaviour
//   debug_enable=true;
//   debug_matrix=true;
//   debug_keyboard=true;
//   //debug_mouse=true;
// }

// bool is_oneshot_cancel_key(uint16_t keycode) {
//   switch (keycode) {
//   case LA_SYM:
//   case LA_NAV:
//   case LA_NUM:
//     return true;
//   default:
//     return false;
//   }
// }
//
// bool is_oneshot_ignored_key(uint16_t keycode) {
//   switch (keycode) {
//   case LA_SYM:
//   case LA_NAV:
//   case LA_NUM:
//   case KC_LSFT:
//   case OS_SHFT:
//   case OS_CTRL:
//   case OS_ALT:
//   case OS_CMD:
//     return true;
//   default:
//     return false;
//   }
// }
//
// bool sw_win_active = false;
// bool sw_lang_active = false;
//
// oneshot_state os_shft_state = os_up_unqueued;
// oneshot_state os_ctrl_state = os_up_unqueued;
// oneshot_state os_alt_state = os_up_unqueued;
// oneshot_state os_cmd_state = os_up_unqueued;
//
// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   switch (keycode) {
//   case LT(NAV, KC_OPER):
//     if (record->tap.count > 0) {
//       if (record->event.pressed) {
//         register_code(KC_SPC);
//       }
//       return false;
//     }
//     break;
//   }
//   return true;
// }

// layer_state_t layer_state_set_user(layer_state_t state) {
//     return update_tri_layer_state(state, SYM, NAV, NUM);
// }
//

bool process_mod_key(uint16_t keycode, keyrecord_t *record) {
  for (uint8_t i = 0; i < NUM_MOD_KEYS; i++) {
    if (keycode == mod_keys[i].keycode) {
      if (record->event.pressed) {
        uprintf("Activating mod key: %u\n", keycode);

        uprintf("Activating mod layer: %u\n", mod_keys[i].layer);
        layer_on(mod_keys[i].layer);
        register_code(mod_keys[i].modifier);

        uprintf("Activating mod modifier: %u\n", mod_keys[i].modifier);
      } else {
        uprintf("Deactivating mod key: %u\n", keycode);
        layer_off(mod_keys[i].layer);
        unregister_code(mod_keys[i].modifier);
      }
      return true;
    }
  }
  return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  uprintf("Keycode: %u %s\n", keycode,
          record->event.pressed ? "pressed" : "released");
  // if (!update_flow(keycode, record->event.pressed, record->event.key))
  //   return false;

  switch (keycode) {
  // case TM_LEFT:
  //   if (!record->event.pressed)
  //     return true;
  //   SEND_STRING(TMUX_PREFIX "<");
  //   return false;
  // case TM_RIGHT:
  //   if (!record->event.pressed)
  //     return true;
  //   SEND_STRING(TMUX_PREFIX ">");
  //   return false;
  // case TM_NEXT:
  //   if (!record->event.pressed)
  //     return true;
  //   SEND_STRING(TMUX_PREFIX "n");
  //   return false;
  // case TM_PREV:
  //   if (!record->event.pressed)
  //     return true;
  //   SEND_STRING(TMUX_PREFIX "p");
  //   return false;
  // case TM_NEW:
  //   if (!record->event.pressed)
  //     return true;
  //   SEND_STRING(TMUX_PREFIX "c");
  //   return false;
  // case TM_SLCT:
  //   if (!record->event.pressed)
  //     return true;
  //   SEND_STRING(TMUX_PREFIX "[");
  //   return false;
  // case TM_SRCH:
  //   if (!record->event.pressed)
  //     return true;
  //   SEND_STRING(TMUX_PREFIX "\t");
  //   return false;
  // case TM_URL:
  //   if (!record->event.pressed)
  //     return true;
  //   SEND_STRING(TMUX_PREFIX SS_LCTL("u"));
  //   return false;
  case LT(0, MOD_THUMB):
    if (record->tap.count && record->event.pressed) {
      tap_code16(KC_ESC);
      uprintf("MOD_THUMB ESC\n");
      return false;
    } else if (record->event.pressed) {
      mod_active = true;
      uprintf("MOD_THUMB activated\n");
    } else {
      mod_active = false;
      layer_off(MOD_LEFT);
      layer_off(MOD_RIGHT);
      uprintf("MOD_THUMB deactivated\n");
    }
    return false; // Skip all further processing of this key
  default:
    if (mod_active) {
      if (process_mod_key(keycode, record)) {
        return false;
      }
    }
  }
  return true;
}

// void matrix_scan_user(void) { flow_matrix_scan(); }
