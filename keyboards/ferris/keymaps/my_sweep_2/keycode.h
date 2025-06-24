#pragma once

#include QMK_KEYBOARD_H

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
  NV_PANE_CLOSE,
  // Neovim Tab Navigation
  NV_TAB_PREV,
  NV_TAB_NEXT,
  NV_TAB_NEW,
  NV_TAB_CLOSE,
  NV_BUF_CLOSE,
  NV_BUF_DELETE,

  NV_SAVE,

  // App Shortcuts
  TELESCOPE,
  // Tiling WM Shortcuts
  WM_WS_1,
  WM_WS_2,
  WM_WS_3,
  WM_WS_4,
  WM_WS_5,
  WM_WS_7, WM_WS_8, };
