#include QMK_KEYBOARD_H


#define _BASE 0
#define _SYM2 1
#define _SYM1 2
#define _NAV 3
#define _UTIL 4
#define _UNICODE 5

// FILLERS
#define ___ KC_TRANSPARENT

// LAYER KEYS
#define SYM2  OSL(_SYM2)
#define SYM1  OSL(_SYM1)
#define NAV   OSL(_NAV)
#define UTIL  OSL(_UTIL)
#define UNICODE  OSL(_UNICODE)

// LEFT HOME ROW MODS
#define HOME_A LT(_NAV, KC_A)
#define HOME_S LCTL_T(KC_S)
#define HOME_D LGUI_T(KC_D)
#define HOME_F LALT_T(KC_F)

// RIGHT HOME ROW MODS
#define HOME_SCLN LT(_NAV, KC_SCLN)
#define HOME_L LCTL_T(KC_L)
#define HOME_K LGUI_T(KC_K)
#define HOME_J LALT_T(KC_J)

// Other dual function keys
#define SHIFT_ENTER LSFT_T(KC_ENTER)
#define SHIFT_SPACE LSFT_T(KC_SPACE)

// App specific keys
#define TMUX LCTL(KC_S)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* BASE
 * +-----------------------------------------+                             +-----------------------------------------+
 * | TMUX |   Q  |   W  |HYPR/E|   R  |   T  |                             |   Y  |   U  |   I  |   O  |   P  |UNICOD|
 * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
 * | CMD  | A/NAV|S/CTRL|D/CMD |F/ALT |   G  |                             |   H  | J/ALT|K/CMD |L/CTRL| ;/NAV| ALT  |
 * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
 * | CTRL |   Z  |   X  |   C  |   V  |   B  |                             |   N  |   M  |   ,  |   .  |   /  | CTRL |
 * +------+------+------+------+-------------+                             +-------------+------+------+------+------+
 *               |      |      |                                                         |      |      |
 *               +-------------+--------------------+               +------+-------------+-------------+
 *                             |  L1  | UTIL |RESET |               | RESET| UTIL |  L2  |
 *                             |------+------|------|               |------|------+------|
 *                                    |SPC/SH|      |               |      |ENT/SH|
 *                                    +-------------+               +-------------+
 */
[_BASE] = LAYOUT( \
    TMUX, KC_Q,   KC_W,   HYPR_T(KC_E),   KC_R,   KC_T,           KC_Y,   KC_U,   KC_I,    KC_O,   KC_P,    UNICODE,   \
    KC_LSFT, HOME_A, HOME_S, HOME_D, HOME_F, KC_G,                KC_H,   HOME_J, HOME_K,  HOME_L, HOME_SCLN, KC_LSFT, \
    TMUX, KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,                   KC_N,   KC_M,   KC_COMM, KC_DOT, KC_SLSH, TMUX,   \
                    ___, ___,                                        ___, ___,        \
                                    SYM1, ___,                          ___, SYM2,                                     \
                                    SHIFT_SPACE, UTIL,                      UTIL,  SHIFT_ENTER,                                      \
                                    _, RESET,                               RESET, _                                       \
),

/* L1
 * +-----------------------------------------+                             +-----------------------------------------+
 * |      |      |      | INS  |PRTSCR|      |                             |      |   7  |   8  |   9  |   :  |      |
 * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
 * | CAPS |CAPS_W| BSPC | TAB  | ESC  |      |                             |      |   4  |   5  |   6  |   ,  |      |
 * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                             |      |   1  |   2  |   3  |   .  |      |
 * +------+------+------+------+-------------+                             +-------------+------+------+------+------+
 *               |      |      |                                                         |   0  |      |
 *               +-------------+--------------------+               +------+-------------+-------------+
 *                             |      |      |      |               |      |  L4  |      |
 *                             |------+------|------|               |------|------+------|
 *                                    |      |      |               |      |      |
 *                                    +-------------+               +-------------+
 */
[_SYM1] = LAYOUT(
    ___,  ___, ___,  KC_INS, KC_PSCREEN,   ___,              ___, KC_7, KC_8, KC_9, KC_COLON, ___, \
    KC_CAPS,  KC_CAPS, KC_BSPACE, KC_TAB, KC_ESC, ___,           ___, KC_4, KC_5, KC_6, KC_COMMA, ___, \
    ___, ___, ___, ___, ___, ___,                            ___, KC_1, KC_2, KC_3, KC_DOT, ___, \
                   ___, ___,                                      ___, ___,  \
                                 ___, ___,     ___, KC_0,                                      \
                                 ___, ___,      ___, ___,                                      \
                                 ___, ___,     ___,   ___                                       \
),

/* L2
 * +------+----------------------------------+                             +-----------------------------------------+
 * |      |  |   | &    | ^    | $    | !    |                             |      |   {  |   }  |      |      |      |
 * |------|------+------+------+------+------+                             |------+------+------+------+------+------|
 * |      |  =   | +    | _    | -    | @    |                             |      |   [  |   ]  | BSPC |   %         |
 * |------|------+------+------+------+------+                             |------+------+------+------+------+------|
 * |      |  ~   | `    | '    | "    | #    |                             |      |   (  |   )  |   *  |   \  |      |
 * +------+------+------+------+------+-------                             +-------------+------+------+------+------+
 *               |      |      |                                                         |      |      |
 *               +-------------+--------------------+               +------+-------------+-------------+
 *                             |             |      |               |      |             |
 *                             |------+------|------|               |------|------+------|
 *                                    |      |      |               |      |      |
 *                                    +-------------+               +-------------+
 */
[_SYM2] = LAYOUT(
    ___,  KC_PIPE, KC_AMPERSAND, KC_CIRCUMFLEX, KC_DOLLAR, KC_EXCLAIM,             ___, KC_LEFT_CURLY_BRACE,    KC_RIGHT_CURLY_BRACE,    ___, ___, ___, \
    ___, KC_EQUAL, KC_PLUS, KC_UNDERSCORE, KC_MINUS, KC_AT,                        ___, KC_LBRACKET, KC_RBRACKET, KC_BSPC, KC_PERCENT, ___, \
    ___, KC_TILDE,  KC_GRAVE,   KC_QUOTE,   KC_DOUBLE_QUOTE,  KC_HASH,             ___, KC_LEFT_PAREN, KC_RIGHT_PAREN, KC_ASTERISK, KC_BSLASH, ___, \
                      ___, ___,                                                   ___,  ___,                    \
                                        ___, ___,                                   ___, ___,                                          \
                                        ___, ___,                                   ___,  ___,                                      \
                                        ___, ___,                                     ___, ___                                        \

),

/* L3
 * +------+----------------------------------+                             +-----------------------------------------+
 * |      |      |LCLICK| MUP  |RCLICK|      |                             | HOME | PGDN | PGUP |  END |      |      |
 * |------|------+------+------+------+------+                             |------+------+------+------+------+------|
 * |      |      |MLEFT |MDOWN |MRIGHT|      |                             | LEFT | DOWN |  UP  | RIGHT|      |      |
 * |------|------+------+------+------+------+                             |------+------+------+------+------+------|
 * |      |      |      |WHLUP |WHLDN |      |                             |      | ACC0 | ACC1 | ACC2 |      |      |
 * +------+------+------+------+------+-------                             +-------------+------+------+------+------+
 *               |      | DEL  |                                                         | INS  |      |
 *               +-------------+--------------------+               +------+-------------+-------------+
 *                             |      |      |      |               |      |      |      |
 *                             |------+------|------|               |------|------+------|
 *                                    |      |      |               |      |      |
 *                                    +-------------+               +-------------+
 */
[_NAV] = LAYOUT(
    ___, ___, KC_MS_BTN1, KC_MS_UP, KC_MS_BTN2, ___,                           KC_HOME, KC_PGDOWN, KC_PGUP, KC_END, ___, ___, \
    ___, ___, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, RGB_VAI,                        KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, ___, ___, \
    ___, KC_MS_WH_LEFT, KC_MS_WH_UP ,KC_MS_WH_DOWN, KC_MS_WH_RIGHT, ___,           ___, KC_MS_ACCEL0, KC_MS_ACCEL1, KC_MS_ACCEL2, ___, ___, \
                      ___, ___,                                          KC_INS, ___,                            \
                              KC_DELETE, ___,                                           ___, ___,                                            \
                              ___, ___,                                           ___, ___,                                            \
                              ___, ___,                                           ___, ___                                             \
),
/* L4
 * +------+----------------------------------+                             +-----------------------------------------+
 * |      |POWER |BRGHDN|BRGHDN|      |      |                             |      |  F7  |  F8  |  F9  |  F10 |      |
 * |------|------+------+------+------+------+                             |------+------+------+------+------+------|
 * |      |SLEEP |VOLDN |VOLUP | MUTE |      |                             |      |  F4  |  F5  |  F6  |  F11 |      |
 * |------|------+------+------+------+------+                             |------+------+------+------+------+------|
 * |      | WAKE | PREV | PLAY | NEXT |      |                             |      |  F1  |  F2  |  F3  |  F12 |      |
 * +------+------+------+------+------+-------                             +-------------+------+------+------+------+
 *               |      |      |                                                         |      |      |
 *               +-------------+--------------------+               +------+-------------+-------------+
 *                             |             |      |               |      |             |
 *                             |------+------|------|               |------|------+------|
 *                                    |      |      |               |      |      |
 *                                    +-------------+               +-------------+
 */
[_UTIL] = LAYOUT(
    ___, KC_KB_POWER, KC_BRIGHTNESS_DOWN, KC_BRIGHTNESS_UP, ___, ___,           ___, KC_F7, KC_F8, KC_F9, KC_F10, ___, \
    ___, KC_SYSTEM_SLEEP, KC_VOLD, KC_VOLU, KC_MUTE, RGB_M_P,                                 ___, KC_F4, KC_F5, KC_F6, KC_F11, ___, \
    ___, KC_WAKE, KC_MPRV, KC_MPLY, KC_MNXT, RGB_M_B,                                ___, KC_F1, KC_F2, KC_F3, KC_F12, ___, \
                      RGB_HUD, RGB_HUI,                                                       RGB_TOG, RGB_MODE_FORWARD,                            \
                                        ___, ___,                            ___, ___,                                            \
                                        RGB_SAD, RGB_SAI,                            ___, ___,                                            \
                                        RGB_VAD, RGB_VAI,                            ___, ___                                             \
),
[_UNICODE] = LAYOUT(
    ___, UC(0x0103), ___, ___, ___, UC(0x021B),                    ___, ___, UC(0x00EE), ___, ___, ___, \
    ___, UC(0x00E2), UC(0x0219), ___, ___, ___,           ___, ___, ___, ___, ___, ___, \
    ___, ___, ___, ___, ___, ___,                    ___, ___, ___, ___, ___, ___, \
                      ___, ___,                      ___, ___,                    \
                      ___, ___,                      ___, ___,                   \
                      ___, ___,                      ___, ___,                  \
                      ___, ___,                      ___, ___                  \
)
};

LEADER_EXTERNS();
void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_S) {
      send_unicode_string("¯\\_(ツ)_/¯");
    }
    SEQ_ONE_KEY(KC_C) {
      send_unicode_string("274C");
    }
    SEQ_ONE_KEY(KC_A) {
      send_unicode_string("256E 0028 256F 0020 005F 2570 0020 0029 256D");
    }
    SEQ_ONE_KEY(KC_T) {
      send_unicode_string("2705");
    }
    SEQ_ONE_KEY(KC_D) {
      send_unicode_string("033F 033F 0020 033F 033F 0020 033F 033F 0020 033F 0027 033F 0027 005C 0335 0347 033F 033F 005C 0437 003D 0020 0028 0020 2580 0020 035C 035E 0296 2580 0029 0020 003D 03B5 002F 0335 0347 033F 033F 002F 2019 033F 2019 033F 0020 033F 0020 033F 033F 0020 033F 033F 0020 033F 033F");
    }
    SEQ_ONE_KEY(KC_Z) {
      send_unicode_string("256E 0028 256F 002D 2570 201D 0029 256D");
    }
  }
}

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

/* layer_state_t layer_state_set_user(layer_state_t state) { */
/*     switch (get_highest_layer(state)) { */
/*     case _SYM2: */
/*         rgblight_setrgb (0x30,  0x00, 0x00); */
/*         break; */
/*     case _SYM1: */
/*         rgblight_setrgb (0x00,  0x30, 0x00); */
/*         break; */
/*     case _NAV: */
/*         rgblight_setrgb (0x30,  0x00, 0x30); */
/*         break; */
/*     case _UTIL: */
/*         rgblight_setrgb (0x00,  0x00, 0x30); */
/*         break; */
/*     default: */
/*         rgblight_setrgb (0x00,  0x30, 0x30); */
/*         break; */
/*     } */
/* return state; */
/* } */


// #ifdef HOLD_ON_OTHER_KEY_PRESS_PER_KEY
// bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
//             // Immediately select the hold action when another key is pressed.
//             return true;
//         default:
//             // Do not select the hold action when another key is pressed.
//             return false;
//     }
// }
// #endif

// #ifdef TAPPING_TERM_PER_KEY
// uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         // case HOME_O:
//         //     return TAPPING_TERM + 30;
//         case SHIFT_SPACE:
//             // Very low tapping term to make sure I don't hit Enter accidentally.
//             return TAPPING_TERM - 45;
//         default:
//             return TAPPING_TERM;
//     }
// };
// #endif
