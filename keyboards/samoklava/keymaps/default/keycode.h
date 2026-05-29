#pragma once

#include "quantum_keycodes.h"

#define TMUX_PREFIX SS_LCTL("b")

#define CKC_Z MT(MOD_LGUI, KC_Z)
#define CKC_X MT(MOD_LALT, KC_X)
#define CKC_C MT(MOD_LSFT, KC_C)
#define CKC_D MT(MOD_LCTL, KC_D)
#define CKC_H MT(MOD_RCTL, KC_H)
#define CKC_COMM MT(MOD_RSFT, KC_COMM)
#define CKC_DOT MT(MOD_RALT, KC_DOT)
#define CKC_SCLN MT(MOD_RGUI, KC_SCLN)
#define CKC_A LT(SYM_QOTE_LAYER, KC_A)
#define CKC_O LT(SYM_QUES_LAYER, KC_O)

#define CKC_PLUS LALT_T(KC_PLUS)
#define CKC_EQL LSFT_T(KC_EQL)
#define CKC_MINS LCTL_T(KC_MINS)

#define CKC_LCBR LCTL_T(KC_LCBR)
#define CKC_RCBR LSFT_T(KC_RCBR)

#define TKC_LL MO(NUM_LAYER)
#define TKC_LR LT(NAV_LAYER, KC_ESC)
#define TKC_RL LT(SYM_LAYER, KC_SPC)
#define TKC_RR TD(TD_SHIFT)

enum custom_keycodes {
    // Neovim Pane Navigation
    NV_PANE_L = SAFE_RANGE,
    NV_PANE_D,
    NV_PANE_U,
    NV_PANE_R,
    // Neovim Pane Actions
    NV_SPLIT_H,
    NV_SPLIT_V,
    NV_PANE_ZOOM,
    NV_PANE_ZOOM_V,
    NV_PANE_ZOOM_H,
    NV_PANE_EQ,
    NV_PANE_CLOSE,
    // Neovim Tab Navigation
    NV_TAB_PREV,
    NV_TAB_NEXT,
    NV_TAB_NEW,
    NV_TAB_CLOSE,
    NV_BUF_CLOSE,
    NV_BUF_DELETE,

    TM_PREFIX,
    TM_COPY_MODE,
    TM_PANE_L,
    TM_PANE_D,
    TM_PANE_U,
    TM_PANE_R,
    TM_SPLIT_H,
    TM_SPLIT_V,
    TM_PANE_ZOOM,
    TM_PANE_CLOSE,
    TM_WIN_PREV,
    TM_WIN_NEXT,
    TM_WIN_NEW,
    TM_SES_PREV,
    TM_SES_NEXT,

    // App Shortcuts
    TELESCOPE,
    // Tiling WM Shortcuts
    WM_WS_1,
    WM_WS_2,
    WM_WS_3,
    WM_WS_4,
    WM_WS_5,
    WM_WS_6,
    WM_WS_7,
    WM_WS_8,
    WM_WS_9,
    WM_WS_0,

    CLIAPP_ENABLE,
    CLIAPP_CONFIG_MODE,
    CLIAPP_TERMINAL_LOGGING,
    CLIAPP_INTERFACE,
    CLIAPP_INTERFACE_GBE1,
    CLIAPP_INTERFACE_COMBO1,
    CLIAPP_SHOW_RUNNING_CONFIG,
    CLIAPP_SHOW_XML_RUNNING_CONFIG,

    COMBO_ENTER,
    COMBO_NV_SAVE,
    COMBO_NV_NOA_SAVE
};
