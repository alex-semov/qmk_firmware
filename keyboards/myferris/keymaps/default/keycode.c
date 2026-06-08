#include QMK_KEYBOARD_H

#include "keycode.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    // Check for Left Control modifier specifically for arrow keys remapping
    // if (get_mods() & MOD_BIT(KC_LCTL)) {
    //   switch (keycode) {
    //     case KC_UP:
    //       tap_code16(LCTL(KC_U));
    //       return false; // Consume the key event
    //     case KC_DOWN:
    //       tap_code16(LCTL(KC_D));
    //       return false; // Consume the key event
    //   }
    // }

    switch (keycode) {
        case CKC_LCBR:
            if (record->tap.count) {
                tap_code16(KC_LCBR);
                return false;
            }
            return true; // Allow default processing for hold

        case CKC_RCBR:
            if (record->tap.count) {
                tap_code16(KC_RCBR);
                return false;
            }
            return true; // Allow default processing for hold

        case CKC_PLUS:
            if (record->tap.count) {
                tap_code16(KC_PLUS);
                return false;
            }
            return true; // Allow default processing for hold (LGUI)
        case CKC_MINS:
            if (record->tap.count) {
                tap_code16(CKC_MINS);
                return false;
            }
            return true; // Allow default processing for hold (LGUI)


      // --- Neovim Pane Control ---
      case NV_PANE_L:     SEND_STRING(SS_LCTL("w") "h"); break;
      case NV_PANE_D:     SEND_STRING(SS_LCTL("w") "j"); break;
      case NV_PANE_U:     SEND_STRING(SS_LCTL("w") "k"); break;
      case NV_PANE_R:     SEND_STRING(SS_LCTL("w") "l"); break;
      case NV_SPLIT_H:    SEND_STRING(SS_LCTL("w") "s"); break;
      case NV_SPLIT_V:    SEND_STRING(SS_LCTL("w") "v"); break;
      case NV_PANE_ZOOM:  SEND_STRING(SS_LCTL("w") "o"); break;
      case NV_PANE_ZOOM_V:  SEND_STRING(SS_LCTL("w") "|"); break;
      case NV_PANE_ZOOM_H:  SEND_STRING(SS_LCTL("w") "_"); break;
      case NV_PANE_EQ:  SEND_STRING(SS_LCTL("w") "="); break;
      case NV_PANE_CLOSE: SEND_STRING(SS_LCTL("w") "q"); break;
      // case NV_SAVE: SEND_STRING(":w" SS_TAP(X_ENTER)); break;
      // --- Neovim Tab Control ---
      case NV_TAB_NEW:   SEND_STRING(":tabnew" SS_TAP(X_ENTER)); break;
      case NV_TAB_CLOSE:  SEND_STRING(":tabclose" SS_TAP(X_ENTER)); break;
      case NV_BUF_CLOSE:  SEND_STRING(":q" SS_TAP(X_ENTER)); break;
      case NV_BUF_DELETE:  SEND_STRING(":bd" SS_TAP(X_ENTER)); break;
      case NV_TAB_PREV:   SEND_STRING(":tabp" SS_TAP(X_ENTER)); break;
      case NV_TAB_NEXT:   SEND_STRING(":tabn" SS_TAP(X_ENTER)); break;

      // COMBO
            case COMBO_NV_SAVE: SEND_STRING(":w" SS_TAP(X_ENTER)); break;
            case COMBO_NV_NOA_SAVE: SEND_STRING(":noa w" SS_TAP(X_ENTER)); break;

      // --- OS-aware clipboard ---
      // Cmd (GUI) on macOS/iOS, Ctrl on Linux/Windows/everything else.
      case OS_COPY:
      case OS_PASTE:
      case OS_CUT: {
          os_variant_t os = detected_host_os();
          uint8_t mod = (os == OS_MACOS || os == OS_IOS) ? KC_LGUI : KC_LCTL;
          uint8_t key = (keycode == OS_COPY) ? KC_C : (keycode == OS_PASTE) ? KC_V : KC_X;
          register_code(mod);
          tap_code(key);
          unregister_code(mod);
          break;
      }
      // Paste without formatting: GUI(Cmd)+Shift+V on macOS/iOS, Ctrl+Shift+V elsewhere
      case OS_PASTE_PLAIN: {
          os_variant_t os = detected_host_os();
          uint8_t mod = (os == OS_MACOS || os == OS_IOS) ? KC_LGUI : KC_LCTL;
          register_code(mod);
          register_code(KC_LSFT);
          tap_code(KC_V);
          unregister_code(KC_LSFT);
          unregister_code(mod);
          break;
      }
      // Tmux
      // --- Tmux Control ---
      case TM_PREFIX:     SEND_STRING(TMUX_PREFIX); break;
      case TM_COPY_MODE:  SEND_STRING(TMUX_PREFIX "["); break;
      case TM_PANE_L:     SEND_STRING(TMUX_PREFIX "h"); break;
      case TM_PANE_D:     SEND_STRING(TMUX_PREFIX "j"); break;
      case TM_PANE_U:     SEND_STRING(TMUX_PREFIX "k"); break;
      case TM_PANE_R:     SEND_STRING(TMUX_PREFIX "l"); break;
      case TM_SPLIT_H:    SEND_STRING(TMUX_PREFIX "\""); break; // Note: " is vertical split
      case TM_SPLIT_V:    SEND_STRING(TMUX_PREFIX "%"); break;  // Note: % is horizontal split
      case TM_PANE_ZOOM:  SEND_STRING(TMUX_PREFIX "z"); break;
      case TM_PANE_CLOSE: SEND_STRING(TMUX_PREFIX "x"); break;
      case TM_WIN_PREV:   SEND_STRING(TMUX_PREFIX "p"); break;
      case TM_WIN_NEXT:   SEND_STRING(TMUX_PREFIX "n"); break;
      case TM_WIN_NEW:    SEND_STRING(TMUX_PREFIX "c"); break;
      case TM_SES_PREV:   SEND_STRING(TMUX_PREFIX "("); break;
      case TM_SES_NEXT:   SEND_STRING(TMUX_PREFIX ")"); break;




      // --- App Shortcuts ---

      // --- Window Manager Control (for i3/Sway/etc.) ---
      case WM_WS_1:       SEND_STRING(SS_LGUI("1")); break;
      case WM_WS_2:       SEND_STRING(SS_LGUI("2")); break;
      case WM_WS_3:       SEND_STRING(SS_LGUI("3")); break;
      case WM_WS_4:       SEND_STRING(SS_LGUI("4")); break;
      case WM_WS_5:       SEND_STRING(SS_LGUI("5")); break;
      case WM_WS_6:       SEND_STRING(SS_LGUI("6")); break;
      case WM_WS_7:       SEND_STRING(SS_LGUI("7")); break;
      case WM_WS_8:       SEND_STRING(SS_LGUI("8")); break;
      case WM_WS_9:       SEND_STRING(SS_LGUI("9")); break;
      case WM_WS_0:       SEND_STRING(SS_LGUI("0")); break;


        case CLIAPP_ENABLE:
            // Sends the "enable" command and presses Enter to execute it.
            SEND_STRING("enable" SS_TAP(X_ENTER));
            break;
        case CLIAPP_CONFIG_MODE:
            // Sends the command to enter configuration mode and presses Enter.
            // "config terminal" is a common command for this, but might vary.
            SEND_STRING("config terminal" SS_TAP(X_ENTER));
            break;
        case CLIAPP_TERMINAL_LOGGING:
            // Sends a command to enable terminal logging (e.g., "terminal monitor").
            SEND_STRING("terminal logging" SS_TAP(X_ENTER));
            break;
        case CLIAPP_INTERFACE:
            // Sends "interface " to prompt for an interface name.
            // This keycode would typically be followed by other keycodes
            // to type out the specific interface name.
            SEND_STRING("interface ");
            break;
        case CLIAPP_INTERFACE_GBE1:
            // Sends the command to select the "gbe1" interface and presses Enter.
            SEND_STRING("interface gbe1" SS_TAP(X_ENTER));
            break;
        case CLIAPP_INTERFACE_COMBO1:
            // Sends the command to select the "combo1" interface and presses Enter.
            SEND_STRING("interface combo1" SS_TAP(X_ENTER));
            break;
        case CLIAPP_SHOW_RUNNING_CONFIG:
            // Sends the command to display the running configuration and presses Enter.
            SEND_STRING("show running-config" SS_TAP(X_ENTER));
            break;
        case CLIAPP_SHOW_XML_RUNNING_CONFIG:
            // Sends a command to display the running configuration in XML format.
            SEND_STRING("do show xml running-config" SS_TAP(X_ENTER));
            break;


      default:            return true; // Continue with default processing
    }
    return false; // Stop processing here
  }
  return true;
}
