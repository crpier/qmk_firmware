/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

/* Use I2C or Serial, not both */
#define USE_SERIAL
// #define USE_I2C

/* Select hand configuration */

//#define MASTER_LEFT
//#define MASTER_RIGHT
#define EE_HANDS

/* Encoder support */
#define ENCODERS_PAD_A { F5 }
#define ENCODERS_PAD_B { F4 }
#define ENCODERS_PAD_A_RIGHT { F4 }
#define ENCODERS_PAD_B_RIGHT { F5 }
#define ENCODER_RESOLUTION 2
//#define ENCODER_DIRECTION_FLIP

// Underglow
#undef RGB_DI_PIN
#define RGB_DI_PIN D1
#undef RGBLED_NUM
#define RGBLED_NUM 18    // Number of LEDs
#define RGBLED_SPLIT { 9, 9 }
#define RGBLIGHT_SLEEP
#define RGBLIGHT_LIMIT_VAL 150
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_RAINBOW_MOOD
#define RGBLIGHT_LAYERS

// Mouse settings
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 23
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED 12
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX 29
#undef MOUSEKEY_WHEEL_MAX_SPEED
#define MOUSEKEY_WHEEL_MAX_SPEED 12

// Tapping settings
#define TAPPING_TERM 140
#define IGNORE_MOD_TAP_INTERRUPT
/* #define PERMISSIVE_HOLD */
/* #define HOLD_ON_OTHER_KEY_PRESS */

#define UNICODE_SELECTED_MODES UC_MAC

#define LEADER_TIMEOUT 300
#define LEADER_NO_TIMEOUT
