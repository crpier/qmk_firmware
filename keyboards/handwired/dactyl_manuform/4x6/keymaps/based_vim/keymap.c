#include QMK_KEYBOARD_H

// FILLERS
#define _______ KC_TRANSPARENT
#define __NOP__ KC_TRANSPARENT

// LAYERS
#define _BASE    0
#define _TYPING  1
#define _SYM1    2
#define _SYM2    3
#define _NAV     4
#define _UTIL    5
#define _UNICODE 6

// LAYER KEYS
#define SYM1    OSL(_SYM1)
#define SYM2    OSL(_SYM2)
#define NAV     OSL(_NAV)
#define UTIL    OSL(_UTIL)
#define UNICODE OSL(_UNICODE)
// Change default layer
#define TYPING  DF (_TYPING)
#define BASE_DF DF (_BASE)

// LEFT HOME ROW MODS
#define HOME_A LT(_NAV, KC_A)
#define HOME_S LCTL_T(KC_S)
#define HOME_D LGUI_T(KC_D)
#define HOME_F LALT_T(KC_F)
#define HYPR_E HYPR_T(KC_E)


// RIGHT HOME ROW MODS
#define HOME_SC LT(_NAV, KC_SCLN)
#define HOME_L LCTL_T(KC_L)
#define HOME_K LGUI_T(KC_K)
#define HOME_J LALT_T(KC_J)

// Other dual function keys
#define SFT_ENT LSFT_T(KC_ENTER)
#define SFT_SPC LSFT_T(KC_SPACE)

// App specific keys
#define TMUX_PR LCTL(KC_S)

// Abbreviations
#define RO_T UC(0x021B)
#define RO_A_U UC(0x0103)
#define RO_A_D UC(0x00E2)
#define RO_S UC(0x0219)
#define RO_I UC(0x00EE)


// RGB colors related to layers
const rgblight_segment_t PROGMEM base_layer_rgb[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 18, HSV_WHITE}
);
const rgblight_segment_t PROGMEM sym1_layer_rgb[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 18, HSV_GOLD}
);
const rgblight_segment_t PROGMEM sym2_layer_rgb[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 18, HSV_CHARTREUSE}
);
const rgblight_segment_t PROGMEM nav_layer_rgb[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 18, HSV_ORANGE}
);
const rgblight_segment_t PROGMEM util_layer_rgb[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 18, HSV_TEAL}
);
const rgblight_segment_t PROGMEM unicode_layer_rgb[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 18, HSV_CORAL}
);
const rgblight_segment_t PROGMEM typing_layer_rgb[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 18, HSV_PURPLE}
);

// RGB color unrelated to a layer
const rgblight_segment_t PROGMEM caps_lock_rgb[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 18, HSV_RED}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    // these rgb layers correspond to keymap layers
    // it's imperative their order here matches the layer number
    // for the rest of rg the code to work correctly
    base_layer_rgb,
    typing_layer_rgb,
    sym1_layer_rgb,
    sym2_layer_rgb,
    nav_layer_rgb,
    util_layer_rgb,
    unicode_layer_rgb,
    // this does not corresponde to an actual layer
    // so leave it for last
    caps_lock_rgb
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(7, led_state.caps_lock);
    return true;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(_BASE,    layer_state_cmp(state, _BASE));
    rgblight_set_layer_state(_TYPING,    layer_state_cmp(state, _TYPING));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(_SYM1,       layer_state_cmp(state, _SYM1));
    rgblight_set_layer_state(_SYM2,       layer_state_cmp(state, _SYM2));
    rgblight_set_layer_state(_NAV,        layer_state_cmp(state, _NAV));
    rgblight_set_layer_state(_UTIL,       layer_state_cmp(state, _UTIL));
    rgblight_set_layer_state(_UNICODE,    layer_state_cmp(state, _UNICODE));
    return state;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* BASE
 * +-----------------------------------------+                          +-----------------------------------------+
 * |      |   Q  |   W  |HYPR/E|   R  |   T  |                          |   Y  |   U  |   I  |   O  |   P  |UNICOD|
 * |------+------+------+------+------+------|                          |------+------+------+------+------+------|
 * | CMD  |A/NAV |S/CTRL|D/CMD |F/ALT |   G  |                          |   H  | J/ALT|K/CMD |L/CTRL| ;/NAV| ALT  |
 * |------+------+------+------+------+------|                          |------+------+------+------+------+------|
 * | CTRL |   Z  |   X  |   C  |   V  |   B  |                          |   N  |   M  |   ,  |   .  |   /  | CTRL |
 * +------+------+------+------+-------------+                          +-------------+------+------+------+------+
 *               |      |      |                                                      |      |      |
 *               +-------------+--------------------+            +------+-------------+-------------+
 *                             |  L1  | UTIL |      |            |      | UTIL |  L2  |
 *                             |------+------|------|            |------|------+------|
 *                                    |SPC/SH|      |            |      |ENT/SH|
 *                                    +-------------+            +-------------+
 */
[_BASE] = LAYOUT(                                                                                                   \
    _______,  KC_Q,    KC_W,    HYPR_E,  KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   UNICODE, \
    KC_LSFT, HOME_A,  HOME_S,  HOME_D,  HOME_F,  KC_G,        KC_H,    HOME_J,  HOME_K,  HOME_L,  HOME_SC, _______, \
    TMUX_PR, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, TMUX_PR, \
                      _______, _______,                                         _______, _______,                   \
                                        SYM1,    __NOP__,     __NOP__, SYM2,                                        \
                                        SFT_SPC, UTIL,        UTIL,    SFT_ENT,                                     \
                                        _______, TYPING,      _______, _______                                      \
),

/* TYPING
 * +-----------------------------------------+                          +-----------------------------------------+
 * |      |   Q  |   W  |   E  |   R  |   T  |                          |   Y  |   U  |   I  |   O  |   P  |      |
 * |------+------+------+------+------+------|                          |------+------+------+------+------+------|
 * |      |   A  |   S  |   D  |   F  |   G  |                          |   H  |   J  |   K  |   L  |   ;  |      |
 * |------+------+------+------+------+------|                          |------+------+------+------+------+------|
 * |      |   Z  |   X  |   C  |   V  |   B  |                          |   N  |   M  |   ,  |   .  |   /  |      |
 * +------+------+------+------+-------------+                          +-------------+------+------+------+------+
 *               |      |      |                                                      |      |      |
 *               +-------------+--------------------+            +------+-------------+-------------+
 *                             |      |      |      |            |      |      |      |
 *                             |------+------|------|            |------|------+------|
 *                                    |      |      |            |      |      |
 *                                    +-------------+            +-------------+
 */
[_TYPING] = LAYOUT(                                                                                                 \
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    UNICODE, \
    KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_RSFT, \
    KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RCTL, \
                      _______, _______,                                         _______, _______,                   \
                                        SYM1,    __NOP__,     __NOP__, SYM2,                                        \
                                        KC_SPC,  KC_LALT,     KC_RGUI, KC_ENT,                                      \
                                        _______, BASE_DF,     _______, _______                                      \
),

/* L1
 * +-----------------------------------------+                             +-----------------------------------------+
 * |      |      |      |      |PRTSCR|      |                             |      |   7  |   8  |   9  |   :  |      |
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
    _______,       _______,      _______,      _______,       KC_PSCR,    _______,                   _______,     KC_7,     KC_8,      KC_9,     KC_COLN,   _______,               \
    KC_CAPS,   CW_TOGG,  KC_BSPC,  KC_TAB,    KC_ESC,     _______,                   _______,     KC_4,     KC_5,      KC_6,     KC_COMM,    _______,                                        \
    _______,       _______,      _______,      _______,       _______,        _______,                   _______,     KC_1,     KC_2,      KC_3,     KC_DOT,     _______,                                                        \
                         _______,      _______,                                                             _______,       _______,                                                                             \
                                              _______,        _______,                   _______,   KC_0,                                                                                               \
                                              _______,        _______,                   _______,   _______,                                                                                               \
                                              _______,        _______,                   _______,   _______                                                                                               \
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
    _______,       KC_PIPE,  KC_AMPR,  KC_CIRC,   KC_DLR,     KC_EXLM,               _______,     KC_LCBR,  KC_RCBR,   _______,      _______,        _______,   \
    _______,       KC_EQL,   KC_PLUS,  KC_UNDS,   KC_MINS,    KC_AT,                 _______,     KC_LBRC,  KC_RBRC,   KC_BSPC,  KC_PERC,    _______,   \
    _______,       KC_TILDE, KC_GRAVE, KC_QUOTE,  KC_DQUO,    KC_HASH,               _______,     KC_LPRN,  KC_RPRN,   KC_ASTR,  KC_BSLS,    _______,   \
                         _______,      _______,                                                             _______,       _______,                         \
                                              _______,        __NOP__,                   __NOP__,   _______,                                                \
                                              _______,        _______,                   _______,   _______,                                                \
                                              _______,        _______,                   _______,   _______                                                 \

),

/* L3
 * +------+----------------------------------+                             +-----------------------------------------+
 * |      |      |LCLICK| MUP  |RCLICK|      |                             | HOME | PGDN | PGUP |  END |      |      |
 * |------|------+------+------+------+------+                             |------+------+------+------+------+------|
 * |      |      |MLEFT |MDOWN |MRIGHT|      |                             | LEFT | DOWN |  UP  | RIGHT|      |      |
 * |------|------+------+------+------+------+                             |------+------+------+------+------+------|
 * |      |      |WHL R |WHL UP|WHL DN|WHL L |                             |      | ACC0 | ACC1 | ACC2 |      |      |
 * +------+------+------+------+------+-------                             +-------------+------+------+------+------+
 *               |      |      |                                                         | INS  |      |
 *               +-------------+--------------------+               +------+-------------+-------------+
 *                             |DELETE|      |      |               |      |      |      |
 *                             |------+------|------|               |------|------+------|
 *                                    |      |      |               |      |      |
 *                                    +-------------+               +-------------+
 */
[_NAV] = LAYOUT(
    _______,       _______,      KC_BTN1,  KC_MS_U,   KC_BTN2,    _______,                   KC_HOME, KC_PGDN,  KC_PGUP,   KC_END,   _______,       _______, \
    _______,       _______,      KC_MS_L,  KC_MS_D,   KC_MS_R,    _______,                   KC_LEFT, KC_DOWN,  KC_UP,     KC_RGHT, _______,       _______, \
    _______,       KC_WH_L,  KC_WH_U,  KC_WH_D,   KC_WH_R,    _______,                   _______,     KC_ACL0,  KC_ACL1,   KC_ACL2,  _______,       _______, \
                         _______,      _______,                                                             KC_INS,    _______,                            \
                                              KC_DEL,     __NOP__,                   __NOP__,   _______,                                            \
                                              _______,        _______,                   _______,   _______,                                            \
                                              _______,        _______,                   _______,   _______                                             \
),
/* L4
 * +------+----------------------------------+                             +-----------------------------------------+
 * |RESET |POWER |BRGHDN|      |BRGHUP|      |                             |      |  F7  |  F8  |  F9  |  F10 |UN_LIN|
 * |------|------+------+------+------+------+                             |------+------+------+------+------+------|
 * |      |SLEEP |VOLDN | MUTE |VOLUP |      |                             |      |  F4  |  F5  |  F6  |  F11 |UN_MAC|
 * |------|------+------+------+------+------+                             |------+------+------+------+------+------|
 * |      | WAKE | PREV | PLAY | NEXT |      |                             |      |  F1  |  F2  |  F3  |  F12 |UN_WIN|
 * +------+------+------+------+------+-------                             +-------------+------+------+------+------+
 *               |      |      |                                                         |RGB_ON|      |
 *               +-------------+--------------------+               +------+-------------+-------------+
 *                             |      |      |      |               |      |      |      |
 *                             |------+------|------|               |------|------+------|
 *                                    |      |      |               |      |      |
 *                                    +-------------+               +-------------+
 */
[_UTIL] = LAYOUT(
    QK_BOOT, KC_PWR,   KC_BRID,  _______,     KC_BRIU,     _______,           _______, KC_F7, KC_F8, KC_F9, KC_F10, QK_UNICODE_MODE_LINUX, \
    _______,     KC_SLEP,    KC_VOLD,  KC_MUTE, KC_VOLU,     _______,                                 _______, KC_F4, KC_F5, KC_F6, KC_F11, QK_UNICODE_MODE_MACOS, \
    _______,     KC_WAKE,    KC_MPRV,  KC_MPLY, KC_MNXT,     _______,                                _______, KC_F1, KC_F2, KC_F3, KC_F12, QK_UNICODE_MODE_WINDOWS, \
                      _______, _______,                                                       UG_TOGG, _______,                            \
                                        _______, __NOP__,                            __NOP__, _______,                                            \
                                        _______, _______,                            _______, _______,                                            \
                                        _______, _______,                            _______, _______                                             \
),



/* L4
 * +------+----------------------------------+                             +-----------------------------------------+
 * |      |   ă  |      |      |      |  ț   |                             |      |      |  î   |      |      |      |
 * |------|------+------+------+------+------+                             |------+------+------+------+------+------|
 * |      |   â  |  ș   |      |      |      |                             |      |      |      |      |      |      |
 * |------|------+------+------+------+------+                             |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                             |      |      |      |      |      |      |
 * +------+------+------+------+------+-------                             +-------------+------+------+------+------+
 *               |      |      |                                                         |      |      |
 *               +-------------+--------------------+               +------+-------------+-------------+
 *                             |      |      |      |               |      |      |      |
 *                             |------+------|------|               |------|------+------|
 *                                    |      |      |               |      |      |
 *                                    +-------------+               +-------------+
 */
[_UNICODE] = LAYOUT(
    _______, RO_A_U, _______, _______, _______, RO_T,                    _______, _______, RO_I, _______, _______, _______, \
    _______, RO_A_D, RO_S, _______, _______, _______,           _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______, \
                      _______, _______,                      _______, _______,                    \
                      _______, __NOP__,                      __NOP__, _______,                   \
                      _______, _______,                      _______, _______,                  \
                      _______, _______,                      _______, _______                  \
),

};
