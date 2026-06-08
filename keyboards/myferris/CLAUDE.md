# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

This directory is `myferris`, a personal QMK keyboard variant based on the Ferris sweep (34-key split, Colemak-DH). It lives inside the upstream `qmk_firmware` tree but has its own build flow and a multi-file keymap with a non-obvious include strategy — read the sections below before editing.

## Build & flash

- **Flash:** `./flash.sh` — runs `qmk flash -kb myferris -km default -e CONVERT_TO=rp2040_ce && sudo umount /media/alex/RPI-RP2/`. The umount path is Linux-specific; on macOS the umount step will no-op or fail harmlessly.
- **Compile only:** `qmk compile -kb myferris -km default -e CONVERT_TO=rp2040_ce`
- **`CONVERT_TO=rp2040_ce` is required.** `keyboard.json` declares `development_board: promicro` (AVR pin names) but the physical board is RP2040; the converter remaps pins at build time. Do not drop this flag.
- **Enter bootloader:** hold the outermost top key on either half while plugging in that half (Bootmagic on matrix `[4,4]` / its left-half mirror), or press the on-PCB reset.

## Keymap architecture

The `keymaps/default/` keymap is split across several files using an unusual include strategy: **`keymap.c` `#include`s the sibling `.c` files directly** (`#include "keycode.c"`, `"combo.c"`, `"tap_dance.c"`). The corresponding `SRC +=` lines in `rules.mk` are intentionally commented out. Editing the `.c` files works as-is; do not "fix" this to `SRC +=` without confirming the build still links.

File roles:

- `keymap.c` — only the `keymaps[][][]` layer table.
- `layer.h` — `enum layers` and `HM_*` home-row mod aliases.
- `keycode.h` — `CKC_*` mod-tap aliases, `TKC_*` thumb keys, and the `custom_keycodes` enum (Vim / Tmux / WM / CLI-app / Combo macros). `TMUX_PREFIX` is defined here as `Ctrl-b`.
- `keycode.c` — `process_record_user`: dispatches custom keycodes to `SEND_STRING` macros, and intercepts a few mod-tap keys (`CKC_LCBR`, `CKC_RCBR`, `CKC_PLUS`, `CKC_MINS`) so the tap path emits the symbol cleanly.
- `combo.c` — chord definitions (e.g. `n+e+i` → Enter, `e+i` → Tab).
- `tap_dance.h` / `tap_dance.c` — `TD_SHIFT` on the right inner thumb: tap = one-shot shift, hold = shift, double-tap = `caps_word_on()`. `get_tapping_term` is also defined here.
- `config.h` — `TAPPING_TERM 200`, `COMBO_TERM 90`, `PERMISSIVE_HOLD`, `DEBOUNCE 10`, `RP2040_BOOTLOADER_DOUBLE_TAP_RESET`.
- `rules.mk` — enables `REPEAT_KEY`, `COMBO`, `TAP_DANCE`, `CAPS_WORD`.

To add a new app-style macro (e.g. another Vim shortcut): add the enum entry in `keycode.h`, add the `SEND_STRING` case in `keycode.c`, then place the keycode somewhere in `keymap.c`.

## Layers

Base is Colemak-DH with home-row mods on `a r s t` / `n e i o` (via `CKC_*` / `HM_*`). Functional layers: `NAV` (arrows + clipboard + `MO()` into TMUX/VIM/CLIAPP), `WM` (workspace switching via `LGUI+N`), `VIM` and `VIM_TAB` (window/tab/buffer SEND_STRINGs), `TMUX` (uses `TMUX_PREFIX` = `Ctrl-b`), `SYM`, `NUM`, `FUN`, `CLIAPP` (network-device CLI shortcuts like `enable`, `show running-config`).

Stub layers: `SYM_QOTE_LAYER` and `SYM_QUES_LAYER` are in the `layer.h` enum but have no entries in the `keymaps[]` table (definitions are commented out in `keymap.c`). Treat them as unused.

## Hardware

Defined in `keyboard.json` at this directory's root:

- Direct-wired split, 4×5 matrix per half, 34 keys total. Community layout: `split_3x5_2`.
- Split serial pin: `D2` (promicro names; remapped by `rp2040_ce` at build time).
- Bootmagic reset: matrix `[4, 4]` (top-outer key on the right half; the mirrored position on the left half also works).

## Known quirks

- `keymaps/default/keymap.json` contains stale metadata (`"keyboard": "ferris/0_1"`, `"keymap": "my_sweep_2"`) that does not match this directory's path. It is not consumed by `flash.sh` (which passes `-kb myferris -km default` explicitly). Treat `keyboard.json` as authoritative for hardware and `flash.sh` as authoritative for build args.
