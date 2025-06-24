#pragma once

#include QMK_KEYBOARD_H

enum layers { DEF_LAYER, MOD_LAYER, NAV_LAYER, WM_LAYER, VIM_LAYER, TMUX_LAYER, SYM_LAYER, NUM_LAYER };

/*
 * Home Row Modifiers (Mod-Tap Keys)
 * Syntax: MT(modifier, keycode)
 * - Tap: Sends the keycode (e.g., KC_A).
 * - Hold: Activates the modifier (e.g., MOD_LGUI).
 *
 * Icons for reference: ⌘ (GUI/Cmd) | ⌥ (ALT) | ⇧ (SHIFT) | ⌃ (CTRL)
 */
#define HM_A  LGUI_T(KC_A)    // Tap: a | Hold: Left ⌘
#define HM_R  LALT_T(KC_R)    // Tap: r | Hold: Left ⌥
#define HM_S  LSFT_T(KC_S)    // Tap: s | Hold: Left ⇧
#define HM_T  LCTL_T(KC_T)    // Tap: t | Hold: Left ⌃

#define HM_N  RCTL_T(KC_N)    // Tap: n | Hold: Right ⌃
#define HM_E  RSFT_T(KC_E)    // Tap: e | Hold: Right ⇧
#define HM_I  RALT_T(KC_I)    // Tap: i | Hold: Right ⌥
#define HM_O  RGUI_T(KC_O)    // Tap: o | Hold: Right ⌘

#define HM_DQUO LCTL_T(KC_DQUO)
#define HM_QUOT LSFT_T(KC_QUOT)
#define HM_GRAVE LALT_T(KC_GRAVE)

// SYM
#define HM_RPRN MT(MOD_LCTL, KC_RPRN)
#define HM_LCBR MT(MOD_LALT, KC_LCBR)
#define HM_LBRC MT(MOD_RCTL, KC_LBRC)
#define HM_RABK MT(MOD_RALT, KC_RABK)

/*
 * Thumb Keys
 */
// #define KT_LL MO(NUM_LAYER)
// #define KT_LR MO(NAV_LAYER)
//
// #define KT_RL LT(SYM_LAYER, KC_SPC)
// #define KT_RR LT(MOD_LAYER, OSM(MOD_LSFT))

// enum custom_keycodes {
//     SMTD_KEYCODES_BEGIN = SAFE_RANGE,
//     SMTD_KEYCODES_END,
// };
