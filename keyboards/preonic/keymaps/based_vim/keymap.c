/* Copyright 2015-2021 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"

enum preonic_layers {
  _QWERTY,
  _SYM1,
  _SYM2,
  _UTIL,
  _NAV
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  SYM1,
  SYM2,
  UTIL,
  NAV,
  BACKLIT,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |SYM1 |    Space    |SYM2 | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid(
  _______,  _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
  _______,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______,
  _______,  LT(_NAV,KC_A),    LCTL_T(KC_S),    LGUI_T(KC_D),    LALT_T(KC_F),    KC_G,    KC_H,    LALT_T(KC_J),    LGUI_T(KC_K),    LCTL_T(KC_L),    LT(_NAV, KC_SCLN), _______,
  _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______,
  OSL(_UTIL), KC_LEFT_CTRL, KC_LEFT_ALT, KC_LEFT_GUI, SYM1,   LSFT_T(KC_SPC),  LSFT_T(KC_ENTER),  SYM2,   _______, _______, _______,   _______
),

/* SYM1
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_SYM1] = LAYOUT_preonic_grid(
  RESET, _______, _______,   _______, _______,  _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______,   _______, _______,  _______, KC_CIRC, KC_7, KC_8, KC_9, _______, _______,
  _______,  KC_CAPS_LOCK,   KC_BACKSPACE,   KC_TAB,   KC_ESC,   _______,   _______,   KC_4, KC_5, KC_6, _______, _______,
  _______, _______,   _______,   _______,   _______,  _______,  _______,KC_1,KC_2,KC_3, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, KC_0, _______, _______, _______, _______
),

/* SYM2
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / | Pg Up| Pg Dn|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_SYM2] = LAYOUT_preonic_grid(
  _______,  _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
  _______,  KC_PIPE,    KC_AMPERSAND,    KC_CIRCUMFLEX,    KC_DOLLAR,    KC_EXCLAIM,    _______,    KC_LEFT_CURLY_BRACE,    KC_RIGHT_CURLY_BRACE,    KC_9,    KC_0,    KC_DEL,
  _______,  KC_EQUAL,   KC_PLUS,   KC_UNDERSCORE,   KC_MINUS,   KC_AT,   _______,   KC_LEFT_BRACKET, KC_RIGHT_BRACKET,  KC_BACKSPACE, KC_PERCENT, _______,
  _______, KC_TILDE,   KC_GRAVE,   KC_QUOTE,   KC_DOUBLE_QUOTE,  KC_HASH,  _______,  KC_LEFT_PAREN, KC_RIGHT_PAREN, KC_ASTERISK, KC_BACKSLASH, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Adjust (SYM1 + SYM2)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset| Debug|      |      |      |      |TermOf|TermOn|      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |Aud cy|Aud on|AudOff|AGnorm|AGswap|Qwerty|      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_UTIL] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, KC_KB_POWER,   KC_BRIGHTNESS_DOWN, KC_BRIGHTNESS_UP,   _______, _______, KC_F7, KC_F8, KC_F9,KC_F10, _______,
  _______, _______, KC_SYSTEM_SLEEP, KC_AUDIO_VOL_DOWN,   KC_AUDIO_VOL_UP,  KC_AUDIO_MUTE,  _______, KC_F4, KC_F5,  KC_F6, KC_F11,  _______,
  _______, _______, KC_MEDIA_PREV_TRACK,  KC_MEDIA_PLAY_PAUSE,   KC_MEDIA_NEXT_TRACK,  _______,   _______,  KC_F1, KC_F2, KC_F3, KC_F12, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),
[_NAV] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______,   _______,   KC_MS_BTN1,   KC_MS_UP,   KC_MS_BTN2,   _______,   KC_HOME,   KC_PAGE_DOWN, KC_PAGE_UP,     KC_END,  _______,  _______,
  _______, _______, KC_MS_LEFT,   KC_MS_DOWN,   KC_MS_RIGHT, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT,_______, _______,
  _______,  KC_MS_WH_LEFT,  KC_MS_WH_DOWN,   KC_MS_WH_UP,  KC_MS_WH_RIGHT, _______, KC_MS_ACCEL0, KC_MS_ACCEL1, KC_MS_ACCEL2, _______, _______, _______,
  _______, _______, _______, _______, KC_DEL, _______, _______, KC_INS, _______, _______, _______, _______
)


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
        case SYM1:
          if (record->event.pressed) {
            layer_on(_SYM1);
            update_tri_layer(_SYM1, _SYM2, _UTIL);
          } else {
            layer_off(_SYM1);
            update_tri_layer(_SYM1, _SYM2, _UTIL);
          }
          return false;
          break;
        case SYM2:
          if (record->event.pressed) {
            layer_on(_SYM2);
            update_tri_layer(_SYM1, _SYM2, _UTIL);
          } else {
            layer_off(_SYM2);
            update_tri_layer(_SYM1, _SYM2, _UTIL);
          }
          return false;
          break;
        case BACKLIT:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
            #ifdef RGBLIGHT_ENABLE
              rgblight_step();
            #endif
            #ifdef __AVR__
            writePinLow(E6);
            #endif
          } else {
            unregister_code(KC_RSFT);
            #ifdef __AVR__
            writePinHigh(E6);
            #endif
          }
          return false;
          break;
      }
    return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_SYM2)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
    return true;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                layer_on(_UTIL);
            } else {
                layer_off(_UTIL);
            }
            break;
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
    return true;
}


void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case SYM2:
    case SYM1:
      return false;
    default:
      return true;
  }
}

// TODO: re-do the ADJUST layer
