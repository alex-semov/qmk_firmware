// Copyright 2023 Alex Semov (@Alex Semov)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//

#define MATRIX_ROWS 8
#define MATRIX_COLS 5

#define MASTER_LEFT

#define MAX_DEFERRED_EXECUTORS 10

// #define PERMISSIVE_HOLD

/* Time (in ms) before the one shot key is released */
// #define ONESHOT_TIMEOUT 1000

// #define PERMISSIVE_HOLD

// #define TAPPING_TERM 160

// #define FLOW_COUNT 7
// #define FLOW_LAYERS_COUNT 2
