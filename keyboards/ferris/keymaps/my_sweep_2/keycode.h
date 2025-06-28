#pragma once

#include "quantum_keycodes.h"

#define TMUX_PREFIX SS_LCTL("b")

#define CKC_S MT(MOD_LALT, KC_S) // Colemak-DH S
#define CKC_T MT(MOD_LCTL, KC_T) // Colemak-DH T
#define CKC_N MT(MOD_RCTL, KC_N) // Colemak-DH N
#define CKC_E MT(MOD_RALT, KC_E) // Colemak-DH E

#define TKC_LL MO(NUM_LAYER)         // Tap Key Code for Number Layer
#define TKC_LR TD(TD_NAV_LAYER)      // Tap Key Code for Navigation Layer
#define TKC_RL LT(SYM_LAYER, KC_SPC) // Tap Key Code for Symbols Layer
#define TKC_RR TD(TD_SHIFT)          // Tap Key Code for Shift  Layer

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

    // NV_SAVE,

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
    WM_WS_7,
    WM_WS_8,

    COMBO_ENTER,
    COMBO_NV_SAVE,
    COMBO_NV_NOA_SAVE
};
