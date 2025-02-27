#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL

// FILLERS
#define _______ _______

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  MAC_LOCK,
};

// LAYERS
#define BASE      0
#define TYPING    1
#define SYM1      2
#define SYM2      3
#define NAV       4
#define UTIL      5
#define UNICODE   6

// LAYER KEYS
#define OSLSYM1    OSL(_SYM1)
#define OSLSYM2    OSL(_SYM2)
#define OSLNAV     OSL(_NAV)
#define OSLUTIL    OSL(_UTIL)
#define OSLUTF8    OSL(_UNICODE)

// Change default layer
#define DF_TYPE    DF(_TYPING)
#define DF_BASE    DF(_BASE)

// LEFT HOME ROW MODS
#define HOME_A     LT(_NAV, KC_A)
#define HOME_S     LCTL_T(KC_S)
#define HOME_D     LGUI_T(KC_D)
#define HOME_F     LALT_T(KC_F)
#define HYPER_E    HYPR_T(KC_E)


// RIGHT HOME ROW MODS
#define HOME_J     LALT_T(KC_J)
#define HOME_K     LGUI_T(KC_K)
#define HOME_L     LCTL_T(KC_L)
#define HOME_SC    LT(_NAV, KC_SCLN)

// Other dual function keys
#define SFT_SPC    LSFT_T(KC_SPACE)
#define SFT_ENT    LSFT_T(KC_ENTER)

// App specific keys
#define TMUX_PR    LCTL(KC_S)

// Aliases for long names
#define QK_DYNAMIC_TAPPING_TERM_DOWN  TAPUP
#define QK_DYNAMIC_TAPPING_TERM_PRINT TAPPRNT
#define QK_DYNAMIC_TAPPING_TERM_UP    TAPDN
#define MAGIC_TOGGLE_NKRO             TG_NKRO

/* +-----------------------------------------------+        +-----------------------------------------------+
 * |       |       |       |       |       |       |        |       |       |       |       |       |       |
 * +-----------------------------------------------+        +-----------------------------------------------+
 * |       |   Q   |   W   |HYPR/E |   R   |   T   |        |   Y   |   U   |   I   |   O   |   P   |UNICODE|
 * |-------+-------+-------+-------+-------+-------+        |-------+-------+-------+-------+-------+-------|
 * |       |A/NAV  |S/CTRL |D/CMD  |F/ALT  |   G   |        |   H   | J/ALT |K/CMD  |L/CTRL | ;/NAV |       |
 * |-------+-------+-------+-------+-------+-------+        |-------+-------+-------+-------+-------+-------|
 * | TMUX  |   Z   |   X   |   C   |   V   |   B   |        |   N   |   M   |   ,   |   .   |   /   | TMUX  |
 * +-------+-------+-------+-------+-------+-------+        +-------+-------+-------+-------+-------+-------+
 *                                 |UTIL   |TYPING |        | UTIL  | UTIL  |
 *                                 +-------+-------+        +-------+-------+ */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_voyager(
    _______,_______,_______,_______,_______,_______,         _______,_______,_______,_______,_______,_______,
    _______,KC_Q   ,KC_W   ,HYPER_E,KC_R   ,KC_T   ,         KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P   ,_______,
    _______,HOME_A ,HOME_S ,HOME_D ,HOME_F ,KC_G   ,         KC_H   ,HOME_J ,HOME_K ,HOME_L ,HOME_SC,_______,
    TMUX_PR,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B   ,         KC_N   ,KC_M   ,KC_COMM,KC_DOT ,KC_SLSH,_______,
                                    OSLSYM1,SFT_SPC,         SFT_ENT,OSLSYM2
  ),
  [TYPING] = LAYOUT_voyager(
   _______,_______,_______,_______,_______,_______,          _______,_______,_______,_______,_______,_______,
   KC_LGUI,KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   ,          _______,_______,_______,_______,_______,KC_LGUI,
   KC_LALT,KC_A   ,KC_S   ,KC_D   ,KC_F   ,KC_G   ,          _______,_______,_______,_______,_______,KC_LALT,
   KC_LCTL,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B   ,          _______,_______,_______,_______,_______,KC_LCTL,
                                   _______,_______,          _______,_______
  ),
  [SYM1] = LAYOUT_voyager(
   _______,_______,_______,_______,_______,_______,          _______,_______,_______,_______,_______,_______,
   _______,_______,_______,KC_INS ,_______,_______,          _______,KC_7   ,KC_8   ,KC_9   ,KC_COLN,KC_MINS,
   KC_CAPS,CW_TOGG,KC_BSPC,KC_TAB,KC_ESC  ,_______,          _______,KC_4   ,KC_5   ,KC_6   ,KC_COMM,KC_UNDS,
   _______,_______,_______,_______,_______,_______,          _______,KC_1   ,KC_2   ,KC_3   ,KC_DOT ,_______,
                                   _______,_______,          _______,KC_0
  ),
  [SYM2] = LAYOUT_voyager(
   _______,_______,_______,_______,_______,_______,          _______,_______,_______,_______,_______,_______,
   _______,KC_PIPE,KC_AMPR,KC_CIRC,KC_DLR ,KC_EXLM,          _______,KC_LCBR,KC_RCBR,_______,_______,_______,
   _______,KC_EQL ,KC_PLUS,KC_UNDS,KC_MINS,KC_AT  ,          _______,KC_LBRC,KC_RBRC,_______,KC_PERC,_______,
   _______,KC_TILD,KC_GRV ,KC_QUOT,KC_DQUO,KC_HASH,          _______,KC_LPRN,KC_RPRN,KC_ASTR,KC_BSLS,_______,
                                   OSLUTIL,_______,          _______,_______
  ),
  [NAV] = LAYOUT_voyager(
    _______,_______,_______,_______,_______,_______,         _______,_______,_______,_______,_______,_______,
    _______,_______,MS_BTN1,MS_UP  ,MS_BTN2,_______,         KC_HOME,KC_PGDN,KC_PGUP,KC_END ,_______,_______,
    _______,_______,MS_LEFT,MS_DOWN,MS_RGHT,_______,         KC_LEFT,KC_DOWN,KC_UP,KC_RGHT  ,_______,_______,
    _______,MS_WHLL,MS_WHD ,MS_WHU ,MSWHR  ,_______,         _______,_______,_______,_______,_______,_______,
                                    KC_DEL ,_______,         _______,KC_INS
  ),
  [UTIL] = LAYOUT_voyager(
    _______,RGB_SPD,RGB_SPI,RGB_TOG,RGB_SLD,RGB_MOD,        _______,TAPDN   ,TAPPRNT,TAPUP ,TG_NKRO,_______,
    _______,_______,KC_BRID,_______,KC_BRIU,_______,        _______,KC_F7   ,KC_F8  ,KC_F9 ,KC_F10 ,_______,
    _______,_______,KC_VOLD,KC_MUTE,KC_VOLU,_______,        _______,KC_F4   ,KC_F5  ,KC_F6 ,KC_F11 ,_______,
    _______,_______,KC_MPRV,KC_MPLY,KC_MNXT,_______,        _______,KC_F1   ,KC_F2  ,KC_F3 ,KC_F12 ,_______,
                                    _______,_______,        _______,_______
  ),

};




bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MAC_LOCK:
      HCS(0x19E);

    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}



