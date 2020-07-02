/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once
#include "config_common.h"

// Serial, not i2c wiring
#define USE_SERIAL

// Default to master left
#define MASTER_LEFT

// Rows are doubled-up, because it is the total number of rows between the two halves.
#define MATRIX_ROWS 12
#define MATRIX_COLS 6

// wiring of each half, use the bottom left 6 and the bottom right 6 pins.
#define MATRIX_COL_PINS { F6, F7, B1, B3, B2, B6 }
#define MATRIX_ROW_PINS { D4, C6, D7, E6, B4, B5 }

// Mirror the pins on the other side.
#define MATRIX_COL_PINS_RIGHT { B5, B4, E6, D7, C6, D4 }
#define MATRIX_ROW_PINS_RIGHT { F6, F7, B1, B3, B2, B6 }

// Default diode direction
#define DIODE_DIRECTION COL2ROW

// However, it means I need to properly hold shift and the key to be shifted for longer than
// the tapping term, which is worse. So this is disabled for now.
// #define IGNORE_MOD_TAP_INTERRUPT
 
// Tapping term is used for many things, e.g.
// - how fast I need to double tap the number keys to get an F key
#define TAPPING_TERM 200
