/* Copyright 2022 Jose Pablo Ramirez <jp.ramangulo@gmail.com>
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
#if __has_include("keymap.h")
#    include "keymap.h"
#endif
#include "rgb_hid.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(KC_MUTE, KC_7, KC_8, KC_9, KC_4, KC_5, KC_6, KC_1, KC_2, KC_3, KC_0, KC_DOT, KC_ENT),
    [1] = LAYOUT(KC_TRNS, KC_F13, KC_F14, KC_F15, KC_F16, KC_F17, KC_F18, KC_F19, KC_F20, KC_F21, KC_F22, KC_F23, KC_F24),
    [2] = LAYOUT(RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAI, RGB_SPI, KC_NO, RGB_VAD, RGB_SPD, KC_NO)
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(TO(2), TO(1)) },
  [1] = { ENCODER_CCW_CW(TO(0), TO(2)) },
  [2] = { ENCODER_CCW_CW(TO(1), TO(0)) },
};
#endif


bool oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case 1:
            oled_write_P(PSTR("FN\n"), false);
            break;
        case 2:
            oled_write_P(PSTR("RGB\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    return false;
}


