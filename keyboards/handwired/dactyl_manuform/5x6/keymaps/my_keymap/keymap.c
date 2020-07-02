/* A standard layout for the Dactyl Manuform 5x6 Keyboard */ 

#include QMK_KEYBOARD_H


#define _QWERTY 0
#define _NAV 1
#define _NUMPAD 2
#define _NUM_SYMBOL 3

enum custom_keycodes {
    LAYER_CLEAR = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case LAYER_CLEAR:
        if (record->event.pressed) {
            // when keycode LAYER_CLEAR is pressed
            layer_clear();
        } else {
            // when keycode LAYER_CLEAR is released
        }
        break;
    }
    return true;
};

// Tap Dance declarations
enum {
    T1,
    T2,
    T3,
    T4,
    T5,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for the number, twice for the F-key.
    [T1] = ACTION_TAP_DANCE_DOUBLE(KC_1, KC_F1),
    [T2] = ACTION_TAP_DANCE_DOUBLE(KC_2, KC_F2),
    [T3] = ACTION_TAP_DANCE_DOUBLE(KC_3, KC_F3),
    [T4] = ACTION_TAP_DANCE_DOUBLE(KC_4, KC_F4),
    [T5] = ACTION_TAP_DANCE_DOUBLE(KC_5, KC_F5),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_5x6(
        KC_GRV, TD(T1), TD(T2), TD(T3), TD(T4), TD(T5),                 KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,
        KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_BSLS,
LSFT_T(KC_ESC), KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,
 KC_LCTL,WIN_T(KC_Z),   KC_X,   KC_C,   KC_V,   KC_B,                   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_RSFT,
                        KC_PAUS,KC_EQL,                                                 KC_LBRC,KC_RBRC,
                                        KC_LALT,KC_SPC,                 KC_BSPC,KC_ENT,
                                        KC_LGUI,OSL(3),                 OSL(3),LAYER_CLEAR,
                                        TO(1),  OSL(3),                 KC_CAPS,TO(2)
  ),

  [_NAV] = LAYOUT_5x6(
        _______,_______,_______,_______,_______,_______,                _______,_______,_______,_______,_______,_______,
        _______,KC_HOME,_______,KC_UP,  _______,KC_PGUP,                _______,_______,_______,_______,_______,_______,
        _______,KC_END, KC_LEFT,KC_DOWN,KC_RGHT,KC_PGDN,                _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,                _______,_______,_______,_______,_______,_______,
                        _______,_______,                                                _______,_______,
                                        _______,_______,                _______,_______,
                                        _______,_______,                _______,_______,
                                        _______,_______,                _______,_______

  ),

  [_NUMPAD] = LAYOUT_5x6(
        _______,_______,_______,KC_PSLS,KC_PAST,KC_PMNS,                _______,_______,KC_PSLS,KC_PAST,KC_PMNS,_______,
        _______,_______,KC_KP_7,KC_KP_8,KC_KP_9,KC_PPLS,                _______,KC_KP_7,KC_KP_8,KC_KP_9,KC_PPLS,_______,
        _______,_______,KC_KP_4,KC_KP_5,KC_KP_6,KC_PPLS,                _______,KC_KP_4,KC_KP_5,KC_KP_6,KC_PPLS,_______,
        _______,_______,KC_KP_1,KC_KP_2,KC_KP_3,KC_PENT,                _______,KC_KP_1,KC_KP_2,KC_KP_3,KC_PENT,_______,
                        KC_KP_0,KC_PDOT,                                                KC_KP_0,KC_PDOT,
                                        KC_PENT,KC_PENT,                _______,KC_KP_0,
                                        _______,_______,                _______,_______,
                                        _______,_______,                _______,_______
  ),
  [_NUM_SYMBOL] = LAYOUT_5x6(
        _______,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,                  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12,
        _______,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,                  KC_F7,  KC_F8,  KC_F9,  KC_MINS,KC_EQL, _______,
        _______,KC_1,   KC_2,   KC_3,   KC_4,   KC_5,                   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   _______,
        _______,_______,_______,_______,KC_GRV, _______,                _______,_______,_______,KC_LBRC,KC_RBRC,_______,
                        _______,_______,                                                _______,_______,
                                        _______,_______,                _______,_______,
                                        _______,_______,                _______,_______,
                                        _______,_______,                _______,_______
  ),
};
