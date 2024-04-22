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

#include QMK_KEYBOARD_H
#include "print.h"

enum layer_names {
    _MDIA,
    _FN,
    _SCRL,
    _RGB
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
            MDIA LAYER - Media
    /-------------------------------------------`
    |             | Play/Pause |    Mute    |   Sleep   |
    |             |------------|------------|-----------|
    |             | Prv Track  | Next Track | FN layer |
    \-------------------------------------------'
    */
    [_MDIA] = LAYOUT(
                    KC_MPLY,      KC_MUTE,    KC_SLEP,
                    KC_MPRV,      KC_MNXT,    TO(_FN)
    ),
    /*
            SUB LAYER  - FN controls, Modes on encoder
    /-------------------------------------------`
    |             | Print Screen  | Mission Control |    Sleep    |
    |             |---------------|-----------------|-------------|
    |             |  Teams Mute   |    Zoom Mute    |  SCRL layer |
    \-------------------------------------------'
    */
    [_FN] = LAYOUT(
                    LCTL(LSFT(LGUI(KC_P4))),   KC_MCTL ,     KC_SLEP,
                    LCTL(LSFT(KC_M)),     LSFT(LGUI(KC_A)),    TO(_SCRL)
                    // KC_P6,      KC_P7,    KC_P8,
                    // KC_P9,      KC_P0,    TO(0)
    ),
    /*
            SUB LAYER  - SCRL controls, scrolling
    /-------------------------------------------`
    |             | Speed 0  | Speed 2 | Sleep |
    |             |---------|---------|---------|
    |             | Sroll Left | Scroll Right | RGB Layer |
    \-------------------------------------------'
    */
    [_SCRL] = LAYOUT(
                    KC_ACL0,    KC_ACL2,     KC_SLEP,
                    KC_WH_R,     KC_WH_L,    TO(_RGB)
                    // KC_P6,      KC_P7,    KC_P8,
                    // KC_P9,      KC_P0,    TO(0)
    ),
    /*
            SUB LAYER  - RGB controls, Modes on encoder
    /-------------------------------------------`
    |             | On/Off  | No Anim | Sleep |
    |             |---------|---------|---------|
    |             | Twinkle |  Breathe |  MDIA Layer |
    \-------------------------------------------'
    */
    [_RGB] = LAYOUT(
                    RGB_TOG,    RGB_M_P,     KC_SLEP,
                    RGB_M_TW,     RGB_M_B,    TO(_MDIA)
                    // KC_P6,      KC_P7,    KC_P8,
                    // KC_P9,      KC_P0,    TO(0)
    ),
};
// clang-format on

// encoder mapping
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_MDIA] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_FN] = { ENCODER_CCW_CW(LGUI(KC_TAB), LSFT(LGUI(KC_TAB))) },
    [_SCRL] = { ENCODER_CCW_CW(KC_WH_D, KC_WH_U)},
    [_RGB] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
};
#endif

// define rgb light layers
const rgblight_segment_t PROGMEM layer1[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 5, HSV_GOLD}
);
const rgblight_segment_t PROGMEM layer2[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 5, HSV_RED}
);
const rgblight_segment_t PROGMEM layer3[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 5, HSV_MAGENTA}
);
const rgblight_segment_t PROGMEM layer4[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 5, HSV_TEAL}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM custom_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    layer1,
    layer2,
    layer3,
    layer4

);

void keyboard_post_init_user(void) {
    debug_enable=true;
    debug_matrix=true;
    debug_keyboard=true;
    // Enable the LED layers
    rgblight_layers = custom_rgb_layers;
}

// now the code for actually updating the rgb light layers
layer_state_t layer_state_set_user(layer_state_t state) {
    layer_state_t highest_layer = get_highest_layer(state);
    rgblight_set_layer_state(0, highest_layer == _MDIA);
    rgblight_set_layer_state(1, highest_layer == _FN);
    rgblight_set_layer_state(2, highest_layer == _SCRL);
    rgblight_set_layer_state(3, highest_layer == _RGB);
    switch (highest_layer) {
    case _RGB:
        rgblight_mode(2);
    }

    return state;
}
