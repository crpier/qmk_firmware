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
#undef WS2812_DI_PIN
#define WS2812_DI_PIN D1
#undef RGBLIGHT_LED_COUNT
#define RGBLIGHT_LED_COUNT 18    // Number of LEDs
#define RGBLED_SPLIT { 9, 9 }
#define RGBLIGHT_SPLIT
#define RGBLIGHT_SLEEP
#define RGBLIGHT_LIMIT_VAL 255


// #define RGBLIGHT_EFFECT_ALTERNATING
// #define RGBLIGHT_EFFECT_BREATHING
// #define RGBLIGHT_EFFECT_CHRISTMAS
// #define RGBLIGHT_EFFECT_KNIGHT
// #define RGBLIGHT_EFFECT_RAINBOW_MOOD
// #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
// #define RGBLIGHT_EFFECT_RGB_TEST
// #define RGBLIGHT_EFFECT_SNAKE
// #define RGBLIGHT_EFFECT_STATIC_GRADIENT
// #define RGBLIGHT_EFFECT_TWINKLE

// set the default color to white
#define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_STATIC_LIGHT  // Set to static light mode
#define RGBLIGHT_DEFAULT_HUE 0                            // Hue to 0 (doesn't matter much for white)
#define RGBLIGHT_DEFAULT_SAT 0                            // Saturation to 0 for white
#define RGBLIGHT_DEFAULT_VAL 255                          // Maximum brightness

#define RGBLIGHT_LAYERS

#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 16
// The default is 20. Since we made the mouse about 3 times faster with the previous setting,
// give it more time to accelerate to max speed to retain precise control over short distances.
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX 40
// The default is 300. Let's try and make this as low as possible while keeping the cursor responsive
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY 100
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED 16

#undef MOUSEKEY_WHEEL_MAX_SPEED
#define MOUSEKEY_WHEEL_MAX_SPEED 12

// Tapping settings
// #define HOLD_ON_OTHER_KEY_PRESS
#define LEADER_NO_TIMEOUT
#define LEADER_TIMEOUT 300
#define TAPPING_TERM 130
#define UNICODE_SELECTED_MODES UC_MAC


// Space saving settings
#define LAYER_STATE_8BIT
#define USER_PRINT
#undef LOCKING_RESYNC_ENABLE
#undef LOCKING_SUPPORT_ENABLE
#undef PERMISSIVE_HOLD
