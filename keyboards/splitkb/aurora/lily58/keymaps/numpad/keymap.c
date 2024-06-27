/* Copyright 2022 splitkb.com <support@splitkb.com>
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

enum layers {
    _DEFAULT = 0
};


// Model for an empty layout
// [_FUNCTIONS] = LAYOUT(
//         _______,  _______,  _______,  _______,  _______,  _______,                      _______,  _______,  _______,  _______,  _______,  _______,
//         _______,  _______,  _______,  _______,  _______,  _______,                      _______,  _______,  _______,  _______,  _______,  _______,
//         _______,  _______,  _______,  _______,  _______,  _______,                      _______,  _______,  _______,  _______,  _______,  _______,
//         _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
//                                       _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
// )


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DEFAULT] = LAYOUT(
        KC_KP_0,  KC_KP_1,   KC_KP_4,   KC_KP_7,  KC_NUM,   XXXXXXX,                          XXXXXXX,    XXXXXXX,      XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,
        KC_KP_0,  KC_KP_2,   KC_KP_5,   KC_KP_7,  KC_PSLS,  KC_NUBS,                         XXXXXXX,    XXXXXXX,      XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,
        KC_PDOT,  KC_KP_3,   KC_KP_6,   KC_KP_9,  KC_PAST,  XXXXXXX,                          XXXXXXX,    XXXXXXX,      XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,
        KC_PENT,  KC_PENT,   KC_PPLS,   KC_PPLS,  KC_PMNS,  KC_PEQL,  RGB_TOG,    XXXXXXX,   XXXXXXX,    XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                        XXXXXXX,  XXXXXXX,  KC_MPLY,  KC_PWR,              KC_ENT,    XXXXXXX,   XXXXXXX,   XXXXXXX
    )
};

 void keyboard_post_init_user(void) {
    rgblight_sethsv_noeeprom(HSV_OFF);
 }

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (host_keyboard_led_state().num_lock) {
        RGB_MATRIX_INDICATOR_SET_COLOR(4, 0, 255, 255); // Cyan on 4th LED
    } else {
        RGB_MATRIX_INDICATOR_SET_COLOR(4, 0, 0, 0);
    }
    return false;
}
