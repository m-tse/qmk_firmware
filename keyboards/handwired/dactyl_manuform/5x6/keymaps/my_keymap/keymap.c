#include QMK_KEYBOARD_H

enum custom_keycodes {
    LYR_CLR = SAFE_RANGE, // Clear Layer
};

#define BASE 0
#define NAVIGATION 1
#define NUMPAD 2
#define NUMBER_SYMBOL 3
#define GAMING 4
#define FUNCTION 5

#define SHF_ESC LSFT_T(KC_ESC)
#define WIN_Z WIN_T(KC_Z)
#define SHF_CLN RSFT_T(KC_SCLN)
#define L_NAV TO(NAVIGATION)
#define L_GAME TO(GAMING)
#define L_NUM TO(NUMPAD)
#define L_SYM MO(NUMBER_SYMBOL)
#define L_FUNC LT(FUNCTION, KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Philosophy around default layout:
    // - `ctrl` and `meta` keys really need to be near the pinkies. Too much muscle memory, and hopping between
    //   `alt` / `ctrl` over the space bar results in a lot of mistakes.
    // - With the `ctrl` spot taken up, `shift` has to move up by 1, but it's impossible to have good `shift` ergonomics
    //   with frequently used keys, i.e. `'`, which is often typed very quickly along with a next letter for quoted
    //   text. When typing quickly, you either get the quote and letter, or the shifted letter, there's no conceivable
    //   way to get both. `escape` on the left side is fine since that is not often typed with other keys. On the right
    //   side, the `` is way too often used, but could be replaced with `;` which is rarely used. It also improves
    //   efficiency of the home row, so it seems a worthwhile tradeoff.
    // - The F-keys are perfect for swapping spaces/desktops in both windows and mac. It is too error-prone to hold an
    //   extra thumb cluster key and then hit a number key for desktop swapping, especially since it would require 
    //   hopping over the space key. So I added a layer tap on top of the tilde key. Tap it for backtick/tilde, hold it
    //   to go to the F key layer.
    [BASE] = LAYOUT_5x6(
    // |       |       |       |       |       |           |       |       |       |       |       |
        L_FUNC, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,       KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   _______,
        KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,       KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_BSLS,
        SHF_ESC,KC_A,   KC_S,   KC_D,   KC_F,   KC_G,       KC_H,   KC_J,   KC_K,   KC_L,   KC_QUOT,SHF_CLN,
        KC_LCTL,WIN_Z,  KC_X,   KC_C,   KC_V,   KC_B,       KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_CAPS,
    // |       |       |       |       |       |           |       |       |       |       |       |
                        KC_VOLD,KC_VOLU,                                    _______,_______,
                                        KC_LALT,KC_SPC,     KC_BSPC,KC_ENT,
                                        LYR_CLR,L_SYM,      L_SYM,  LYR_CLR,
                                        L_NAV,  L_NUM,      KC_CAPS,L_GAME
    // |       |       |       |       |       |           |       |       |       |       |       |
    ),

    // A left hand navigation layer.
    // LWIN on space key for arrow key + windows key manipulation.
    [NAVIGATION] = LAYOUT_5x6(
    // |       |       |       |       |       |           |       |       |       |       |       |
        _______,_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,_______,
        _______,KC_HOME,_______,KC_UP,  _______,KC_PGUP,    _______,KC_KP_7,KC_KP_8,KC_KP_9,KC_PPLS,_______,
        _______,KC_END, KC_LEFT,KC_DOWN,KC_RGHT,KC_PGDN,    _______,KC_KP_4,KC_KP_5,KC_KP_6,KC_PPLS,_______,
        _______,_______,_______,_______,_______,_______,    _______,KC_KP_1,KC_KP_2,KC_KP_3,KC_PENT,_______,
    // |       |       |       |       |       |           |       |       |       |       |       |
                        _______,_______,                                    KC_KP_0,KC_PDOT,
                                        _______,KC_LWIN,    _______,_______,
                                        _______,_______,    _______,_______,
                                        _______,_______,    _______,_______
    // |       |       |       |       |       |           |       |       |       |       |       |
    ),

    // Numpad on left.
    [NUMPAD] = LAYOUT_5x6(
    // |       |       |       |       |       |           |       |       |       |       |       |
        _______,_______,_______,KC_PSLS,KC_PAST,KC_PMNS,    _______,_______,_______,_______,_______,_______,
        _______,_______,KC_KP_7,KC_KP_8,KC_KP_9,KC_PPLS,    _______,_______,_______,_______,_______,_______,
        _______,KC_BSPC,KC_KP_4,KC_KP_5,KC_KP_6,KC_PPLS,    _______,_______,_______,_______,_______,_______,
        _______,_______,KC_KP_1,KC_KP_2,KC_KP_3,KC_PENT,    _______,_______,_______,_______,_______,_______,
    // |       |       |       |       |       |           |       |       |       |       |       |
                        KC_KP_0,KC_PDOT,                                    _______,_______,
                                        KC_PENT,KC_PENT,    _______,_______,
                                        _______,_______,    _______,_______,
                                        _______,_______,    _______,_______
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
                                        _______,_______,    _______,_______,
                                        _______,_______,    _______,_______
    // |       |       |       |       |       |           |       |       |       |       |       |
    ),

    // Gaming layer, turn off dual function keys for maximum responsiveness.
    [GAMING] = LAYOUT_5x6(
    // |       |       |       |       |       |           |       |       |       |       |       |
        KC_ESC, _______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,KC_MINS,
        _______,_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,_______,
        KC_LSFT,_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,KC_RSFT,
        _______,KC_Z,   _______,_______,_______,_______,    _______,_______,_______,_______,_______,_______,
    // |       |       |       |       |       |           |       |       |       |       |       |
                        _______,_______,                                    _______,_______,
                                        _______,_______,    _______,_______,
                                        _______,_______,    _______,_______,
                                        _______,_______,    _______,_______
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
                                        _______,_______,    _______,_______,
                                        _______,_______,    _______,_______,
                                        _______,_______,    _______,_______
    // |       |       |       |       |       |           |       |       |       |       |       |
    ),
};

// I want shift to work quickly, however I want the meta mod tap key to work a bit slower,
// which allows typing `zsh` without doing a "meta + s" combination.
bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case WIN_T(KC_Z):
            return true;
        default:
            return false;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case LYR_CLR:
        if (record->event.pressed) {
            layer_clear();
        }
        break;
    }
    return true;
};
