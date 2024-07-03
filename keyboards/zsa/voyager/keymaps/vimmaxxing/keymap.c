#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  MAC_LOCK,
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TG(5),          KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_Q,           KC_W,           ALL_T(KC_E),    KC_R,           KC_T,                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_TRANSPARENT, 
    KC_TRANSPARENT, LT(3,KC_A),     MT(MOD_LCTL, KC_S),MT(MOD_LGUI, KC_D),MT(MOD_LALT, KC_F),KC_G,                                           KC_H,           MT(MOD_LALT, KC_J),MT(MOD_LGUI, KC_K),MT(MOD_LCTL, KC_L),LT(3,KC_SCLN),  KC_TRANSPARENT, 
    LCTL(KC_S),     KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_TRANSPARENT, 
                                                    OSL(1),         MT(MOD_LSFT, KC_SPACE),                                MT(MOD_LSFT, KC_ENTER),OSL(2)
  ),
  [1] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_INSERT,      KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_7,           KC_8,           KC_9,           KC_COLN,        KC_MINUS,       
    KC_CAPS,        CW_TOGG,        KC_BSPC,        KC_TAB,         KC_ESCAPE,      KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_4,           KC_5,           KC_6,           KC_COMMA,       KC_UNDS,        
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_1,           KC_2,           KC_3,           KC_DOT,         KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_0
  ),
  [2] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_PIPE,        KC_AMPR,        KC_CIRC,        KC_DLR,         KC_EXLM,                                        KC_TRANSPARENT, KC_LCBR,        KC_RCBR,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_EQUAL,       KC_PLUS,        KC_UNDS,        KC_MINUS,       KC_AT,                                          KC_TRANSPARENT, KC_LBRC,        KC_RBRC,        KC_TRANSPARENT, KC_PERC,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TILD,        KC_GRAVE,       KC_QUOTE,       KC_DQUO,        KC_HASH,                                        KC_TRANSPARENT, KC_LPRN,        KC_RPRN,        KC_ASTR,        KC_BSLS,        KC_TRANSPARENT, 
                                                    MO(4),          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [3] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN1,     KC_MS_UP,       KC_MS_BTN2,     KC_TRANSPARENT,                                 KC_HOME,        KC_PGDN,        KC_PAGE_UP,     KC_END,         KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_TRANSPARENT,                                 KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_MS_WH_LEFT,  KC_MS_WH_DOWN,  KC_MS_WH_UP,    KC_MS_WH_RIGHT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_DELETE,      KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_INSERT
  ),
  [4] = LAYOUT_voyager(
    KC_TRANSPARENT, RGB_SPD,        RGB_SPI,        RGB_TOG,        RGB_SLD,        RGB_MODE_FORWARD,                                KC_TRANSPARENT, QK_DYNAMIC_TAPPING_TERM_DOWN,QK_DYNAMIC_TAPPING_TERM_PRINT,QK_DYNAMIC_TAPPING_TERM_UP,MAGIC_TOGGLE_NKRO,KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_BRIGHTNESS_DOWN,MAC_LOCK,       KC_BRIGHTNESS_UP,KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_AUDIO_VOL_DOWN,KC_AUDIO_MUTE,  KC_AUDIO_VOL_UP,KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_F4,          KC_F5,          KC_F6,          KC_F11,         KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_MEDIA_PREV_TRACK,KC_MEDIA_PLAY_PAUSE,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F12,         KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [5] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_LEFT_GUI,    KC_Q,           KC_W,           KC_E,           KC_R,           KC_G,                                           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LEFT_GUI,    
    KC_LEFT_ALT,    KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LEFT_ALT,    
    KC_LEFT_CTRL,   KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LEFT_CTRL,   
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
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



