#include QMK_KEYBOARD_H

enum custom_keycodes {
    SLEEP = SAFE_RANGE,
};

#define BASE 0
#define NUMBER_SYMBOL 1
#define FUNCTION 2
#define ARROWS 3
#define L_SYM MO(NUMBER_SYMBOL)
#define L_ARROWS MO(ARROWS)
#define L_FUNC LT(FUNCTION, KC_ESC)
// This is a workaround, where my logitech M720 mouse button is hardcoded to hit LCTL+LGUI+TAB, so I need to make the
// keyboard do the same combination so I can have both a mouse and keyboard way to use mission control.
#define MISS_CTL LCTL(LGUI(KC_TAB))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Philosophy around default layout:
    // - `ctrl` and `meta` keys really need to be near the pinkies. Too much muscle memory, and hopping between
    //   `alt` / `ctrl` over the space bar results in a lot of mistakes.
    // - With the `ctrl` spot taken up, `shift` has to move up by 1, but it's impossible to have good `shift` ergonomics
    //   with frequently used keys, i.e. `'`, which is often typed very quickly along with a next letter for quoted
    //   text. When typing quickly, you either get the quote and letter, or the shifted letter, there's no conceivable
    //   way to get both. `escape` on the left side is fine since that is not often typed with other keys. On the right
    //   side, the `'` key is used too often, so I move it up by one, and also move backslash up by one.
    // - The F-keys are perfect for swapping spaces/desktops in both windows and mac. It is too error-prone to hold an
    //   extra thumb cluster key and then hit a number key for desktop swapping, especially since it would require
    //   hopping over the space key. So I added a layer tap on top of the escape key. Tap it for escape, hold it
    //   to go to the F key layer.
    // - I had Z be a hold-for-meta key for awhile, but got too annoyed with Z typos. Now I made LCTL into META when
    //   double tapped.
    [BASE] = LAYOUT_5x6(
    // |       |       |       |       |       |           |       |       |       |       |       |
        L_FUNC, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,       KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_BSLS,
        KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,       KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_QUOT,
        KC_LSFT,KC_A,   KC_S,   KC_D,   KC_F,   KC_G,       KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_RSFT,
        KC_LCTL,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,       KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,L_ARROWS,
    // |       |       |       |       |       |           |       |       |       |       |       |
                        KC_LEFT,KC_RIGHT,                                   KC_NO,  KC_NO,
                                        KC_LALT,KC_SPC,     KC_BSPC,KC_ENT,
                                        KC_UP,  L_SYM,      L_SYM,  KC_CAPS,
                                        KC_DOWN,KC_LGUI,    KC_VOLD,KC_VOLU
    // |       |       |       |       |       |           |       |       |       |       |       |
    ),

    // Number/symbol layer, provides access to obscure keys closer to the home row.
    [NUMBER_SYMBOL] = LAYOUT_5x6(
    // |       |       |       |       |       |           |       |       |       |       |       |
        _______,_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,_______,
        _______,_______,_______,KC_GRV, _______,_______,    _______,_______,KC_MINS,KC_EQL, _______,_______,
        _______,KC_1,   KC_2,   KC_3,   KC_4,   KC_5,       KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   _______,
        _______,_______,_______,_______,_______,_______,    _______,_______,KC_LBRC,KC_RBRC,_______,_______,
    // |       |       |       |       |       |           |       |       |       |       |       |
                        _______,_______,                                    _______,_______,
                                        _______,_______,    _______,_______,
                                        KC_PGUP,_______,    _______,_______,
                                        KC_PGDN,SLEEP,      _______,_______
    // |       |       |       |       |       |           |       |       |       |       |       |
    ),

    // Easy to access F key layer.
    [FUNCTION] = LAYOUT_5x6(
    // |       |       |       |       |       |           |       |       |       |       |       |
        _______,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,      KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11,
        _______,_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,KC_F12,
        _______,_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,_______,
    // |       |       |       |       |       |           |       |       |       |       |       |
                        _______,_______,                                    _______,_______,
                                       MISS_CTL,_______,    _______,_______,
                                        _______,_______,    _______,_______,
                                        _______,_______,    _______,_______
    // |       |       |       |       |       |           |       |       |       |       |       |
    ),
    [ARROWS] = LAYOUT_5x6(
    // |       |       |       |       |       |           |       |       |       |       |       |
        _______,_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,_______,
        _______,_______,_______,KC_UP,  _______,_______,    _______,_______,_______,_______,_______,_______,
        KC_LSFT,_______,KC_LEFT,KC_DOWN,KC_RGHT,_______,    _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,_______,
    // |       |       |       |       |       |           |       |       |       |       |       |
                        _______,_______,                                    _______,_______,
                                        _______,_______,    _______,_______,
                                        _______,_______,    _______,_______,
                                        _______,_______,    _______,_______
    // |       |       |       |       |       |           |       |       |       |       |       |
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case SLEEP:
        if (record->event.pressed) {
            SEND_STRING(SS_LALT(SS_LCTL("q")));
        }
        break;
    }
    return true;
};
