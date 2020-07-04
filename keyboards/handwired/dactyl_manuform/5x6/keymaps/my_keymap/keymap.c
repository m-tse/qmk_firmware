#include QMK_KEYBOARD_H

enum custom_keycodes {
    LYR_CLR = SAFE_RANGE, // Clear Layer
};

// Tap Dance declarations
enum {
    T1,
    T2,
    T3,
    T4,
    T5,
};

#define SHF_ESC LSFT_T(KC_ESC)
#define WIN_Z WIN_T(KC_Z)
#define WIN_SLS WIN_T(KC_SLSH)
#define SHF_CLN RSFT_T(KC_SCLN)
#define L_NAV TO(1)
#define L_GAME TO(4)
#define L_NUM TO(2)
#define L_SYM MO(3)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Philosophy around default layout:
    // - `ctrl` and `meta` keys really need to be near the pinkies. Too much muscle memory, and hopping between
    //   `alt` / `ctrl` over the space bar results in a lot of mistakes.
    // - With the `ctrl` spot taken up, `shift` has to move up by 1, but it's impossible to have good `shift` ergonomics
    //   with frequently used keys, i.e. `'`, which is often typed very quickly along with a next letter for quoted text.
    //   When typing quickly, you either get the quote and letter, or the shifted letter, there's no conceivable way to get
    //   both. So `escape` on the left side is fine since that is not often typed with other keys. On the right side, the
    //   `'` is way too often used, but could be replaced with `;` which is rarely used. It also improves efficiency of
    //   the home row, so it seems a worthwhile tradeoff.
    // - The F-keys are perfect for swapping spaces/desktops in both windows and mac. It is too error-prone to hold an
    //   extra thumb cluster key and then hit a number key for desktop swapping, especially since it would require hopping
    //   over the space key. So I add double tap F1 through F5 for 5 windows. I don't do this for the other number keys
    //   because it does reduce responsiveness of the keys.
    [0] = LAYOUT_5x6(
    // |       |       |       |       |       |           |       |       |       |       |       |
        KC_GRV, TD(T1), TD(T2), TD(T3), TD(T4), TD(T5),     KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_PAUS,
        KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,       KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_BSLS,
        SHF_ESC,KC_A,   KC_S,   KC_D,   KC_F,   KC_G,       KC_H,   KC_J,   KC_K,   KC_L,   KC_QUOT,SHF_CLN,
        KC_LCTL,WIN_Z,  KC_X,   KC_C,   KC_V,   KC_B,       KC_N,   KC_M,   KC_COMM,KC_DOT, WIN_SLS,KC_RCTL,
    // |       |       |       |       |       |           |       |       |       |       |       |
                        KC_MINS,KC_EQL,                                     KC_LBRC,KC_RBRC,
                                        KC_LALT,KC_SPC,     KC_BSPC,KC_ENT,
                                        LYR_CLR,L_SYM,      L_SYM,  LYR_CLR,
                                        L_NAV,  L_GAME,     KC_CAPS,L_NUM
    // |       |       |       |       |       |           |       |       |       |       |       |

    ),

    // A left hand navigation layer, with right hand on mouse.
    // LWIN on space key for arrow key + windows key manipulation.
    [1] = LAYOUT_5x6(
    // |       |       |       |       |       |           |       |       |       |       |       |
        _______,_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,_______,
        _______,KC_HOME,_______,KC_UP,  _______,KC_PGUP,    _______,_______,_______,_______,_______,_______,
        _______,KC_END, KC_LEFT,KC_DOWN,KC_RGHT,KC_PGDN,    _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,_______,
    // |       |       |       |       |       |           |       |       |       |       |       |
                        _______,_______,                                    _______,_______,
                                        _______,KC_LWIN,    _______,_______,
                                        _______,_______,    _______,_______,
                                        _______,_______,    _______,_______
    // |       |       |       |       |       |           |       |       |       |       |       |
    ),

    // Numpad on both left and right.
    [2] = LAYOUT_5x6(
    // |       |       |       |       |       |           |       |       |       |       |       |
        _______,_______,_______,KC_PSLS,KC_PAST,KC_PMNS,    _______,_______,KC_PSLS,KC_PAST,KC_PMNS,_______,
        _______,_______,KC_KP_7,KC_KP_8,KC_KP_9,KC_PPLS,    _______,KC_KP_7,KC_KP_8,KC_KP_9,KC_PPLS,_______,
        _______,_______,KC_KP_4,KC_KP_5,KC_KP_6,KC_PPLS,    _______,KC_KP_4,KC_KP_5,KC_KP_6,KC_PPLS,_______,
        _______,_______,KC_KP_1,KC_KP_2,KC_KP_3,KC_PENT,    _______,KC_KP_1,KC_KP_2,KC_KP_3,KC_PENT,_______,
    // |       |       |       |       |       |           |       |       |       |       |       |
                        KC_KP_0,KC_PDOT,                                    KC_KP_0,KC_PDOT,
                                        KC_PENT,KC_PENT,    _______,KC_KP_0,
                                        _______,_______,    _______,_______,
                                        _______,_______,    _______,_______
    // |       |       |       |       |       |           |       |       |       |       |       |
    ),

    // Aspirational number/symbol layer.
    [3] = LAYOUT_5x6(
    // |       |       |       |       |       |           |       |       |       |       |       |
        _______,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,      KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12,
        _______,_______,_______,KC_GRV, _______,_______,    _______,_______,KC_MINS,KC_EQL, _______,_______,
        _______,KC_1,   KC_2,   KC_3,   KC_4,   KC_5,       KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   _______,
        _______,_______,_______,_______,_______,_______,    _______,_______,KC_LBRC,KC_RBRC,_______,_______,
    // |       |       |       |       |       |           |       |       |       |       |       |
                        _______,_______,                                    KC_VOLD,KC_VOLU,
                                        _______,_______,    _______,_______,
                                        _______,_______,    _______,_______,
                                        _______,_______,    _______,_______
    // |       |       |       |       |       |           |       |       |       |       |       |
    ),

    // Gaming layer, turn off dual function keys for maximum responsiveness.
    [4] = LAYOUT_5x6(
    // |       |       |       |       |       |           |       |       |       |       |       |
        _______,KC_1,   KC_2,   KC_3,   KC_4,   KC_5,       _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,_______,
        KC_LSFT,_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,KC_RSFT,
        _______,KC_Z,   _______,_______,_______,_______,    _______,_______,_______,_______,KC_SLSH,_______,
    // |       |       |       |       |       |           |       |       |       |       |       |
                        _______,_______,                                    _______,_______,
                                        _______,_______,    _______,_______,
                                        _______,_______,    _______,_______,
                                        _______,_______,    _______,_______
    // |       |       |       |       |       |           |       |       |       |       |       |
    ),
};

// I want shift to work quickly, however I want the meta mod tap key to work a bit slower,
// which allows typing `zsh` without doing a "meta + s" combination. Similar logic for the slashes.
bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case WIN_T(KC_Z):
            return true;
        case WIN_T(KC_SLSH):
            return true;
        default:
            return false;
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for the number, twice for the F-key.
    [T1] = ACTION_TAP_DANCE_DOUBLE(KC_1, KC_F1),
    [T2] = ACTION_TAP_DANCE_DOUBLE(KC_2, KC_F2),
    [T3] = ACTION_TAP_DANCE_DOUBLE(KC_3, KC_F3),
    [T4] = ACTION_TAP_DANCE_DOUBLE(KC_4, KC_F4),
    [T5] = ACTION_TAP_DANCE_DOUBLE(KC_5, KC_F5),
};

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
