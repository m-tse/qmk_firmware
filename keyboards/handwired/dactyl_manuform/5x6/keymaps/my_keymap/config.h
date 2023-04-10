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

// Tapping term is used for how fast I must double tap L_CTL to get L_META
#define TAPPING_TERM 200
