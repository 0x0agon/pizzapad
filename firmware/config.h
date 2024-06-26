/*
Copyright 2022 imchipwood && deveth0

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

#define DEBUG

// #define ENCODERS_PAD_A { D4 }
// #define ENCODERS_PAD_B { B2 }
#define DEBOUNCE 10

#define MATRIX_COLS 3
#define MATRIX_ROWS 2

/* Onboard LEDs  */
// #define LED_00 D1

#define RGB_MATRIX_LED_COUNT 6
#define RGBLED_NUM 5
#define WS2812_DI_PIN D1
#define RGBLIGHT_DEFAULT_HUE 5
#define RGBLIGHT_DEFAULT_VAL 200
#define RGBLIGHT_DEFAULT_SAT 200
#define RGBLIGHT_DEFAULT_ON true
#define RGBLIGHT_EFFECT_ALTERNATING true
#define RGBLIGHT_EFFECT_BREATHING true
#define RGBLIGHT_EFFECT_TWINKLE true

// #define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_BREATHING

#define RGBLIGHT_LAYERS
#define RGBLIGHT_LAYERS_RETAIN_VAL


// Cleanup RGB
//#ifdef RGB_MATRIX_ENABLE
//
//// #define RGB_DISABLE_WHEN_USB_SUSPENDED
//
//#define RGB_MATRIX_FRAMEBUFFER_EFFECTS  // Heatmap, Rain
//#define RGB_MATRIX_KEYPRESSES
//
//#define ENABLE_RGB_MATRIX_ALPHAS_MODS
//#define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
//#define ENABLE_RGB_MATRIX_BREATHING
//#define ENABLE_RGB_MATRIX_BAND_SAT
//#define ENABLE_RGB_MATRIX_BAND_VAL
//#define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
//#define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
//#define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
//#define ENABLE_RGB_MATRIX_RAINDROPS
//#define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
//#define ENABLE_RGB_MATRIX_PIXEL_RAIN
//#define ENABLE_RGB_MATRIX_PIXEL_FLOW
//#define ENABLE_RGB_MATRIX_PIXEL_FRACTAL
//// enabled only if RGB_MATRIX_FRAMEBUFFER_EFFECTS is defined
//#define ENABLE_RGB_MATRIX_TYPING_HEATMAP
//#define ENABLE_RGB_MATRIX_DIGITAL_RAIN
//// enabled only of RGB_MATRIX_KEYPRESSES or RGB_MATRIX_KEYRELEASES is defined
//#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
//#define ENABLE_RGB_MATRIX_SOLID_REACTIVE
//#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
//#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
//#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
//#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
//#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
//#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
//#define ENABLE_RGB_MATRIX_SPLASH
//#define ENABLE_RGB_MATRIX_MULTISPLASH
//#define ENABLE_RGB_MATRIX_SOLID_SPLASH
//#define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH

//#endif
