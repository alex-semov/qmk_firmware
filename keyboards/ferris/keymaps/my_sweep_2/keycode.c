#include QMK_KEYBOARD_H

#include "keycode.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      // --- Neovim Pane Control ---
      case NV_PANE_L:     SEND_STRING(SS_LCTL("w") "h"); break;
      case NV_PANE_D:     SEND_STRING(SS_LCTL("w") "j"); break;
      case NV_PANE_U:     SEND_STRING(SS_LCTL("w") "k"); break;
      case NV_PANE_R:     SEND_STRING(SS_LCTL("w") "l"); break;
      case NV_SPLIT_H:    SEND_STRING(SS_LCTL("w") "s"); break;
      case NV_SPLIT_V:    SEND_STRING(SS_LCTL("w") "v"); break;
      case NV_PANE_ZOOM:  SEND_STRING(SS_LCTL("w") "o"); break;
      case NV_PANE_CLOSE: SEND_STRING(SS_LCTL("w") "q"); break;
      case NV_SAVE: SEND_STRING(":w" SS_TAP(X_ENTER)); break;
      // --- Neovim Tab Control ---
      case NV_TAB_NEW:   SEND_STRING(":tabnew" SS_TAP(X_ENTER)); break;
      case NV_TAB_CLOSE:  SEND_STRING(":tabclose" SS_TAP(X_ENTER)); break;
      case NV_BUF_CLOSE:  SEND_STRING(":q" SS_TAP(X_ENTER)); break;
      case NV_BUF_DELETE:  SEND_STRING(":bd" SS_TAP(X_ENTER)); break;
      case NV_TAB_PREV:   SEND_STRING(":tabp" SS_TAP(X_ENTER)); break;
      case NV_TAB_NEXT:   SEND_STRING(":tabn" SS_TAP(X_ENTER)); break;
      // --- App Shortcuts ---
      case TELESCOPE:     SEND_STRING(":Telescope find_files" SS_TAP(X_ENTER)); break;
      // --- Window Manager Control (for i3/Sway/etc.) ---
      case WM_WS_1:       SEND_STRING(SS_LGUI("1")); break;
      case WM_WS_2:       SEND_STRING(SS_LGUI("2")); break;
      case WM_WS_3:       SEND_STRING(SS_LGUI("3")); break;
      case WM_WS_4:       SEND_STRING(SS_LGUI("4")); break;
      case WM_WS_5:       SEND_STRING(SS_LGUI("5")); break;
      case WM_WS_7:       SEND_STRING(SS_LGUI("7")); break;
      case WM_WS_8:       SEND_STRING(SS_LGUI("8")); break;
      default:            return true; // Continue with default processing
    }
    return false; // Stop processing here
  }
  return true;
}
