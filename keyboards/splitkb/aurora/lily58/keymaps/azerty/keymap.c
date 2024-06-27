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
#include "keymap_french.h"

enum layers {
    _DEFAULT = 0,
    _NO_HOME_ROW_MOD,
    _FUNCTIONS
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
        KC_ESC,    KC_1,     KC_2,      KC_3,       KC_4,       KC_5,                         KC_6,    KC_7,      KC_8,     KC_9,     KC_0,     FR_RPRN,
        KC_TAB,    FR_A,     FR_Z,      FR_E,       FR_R,       FR_T,                         FR_Y,    FR_U,      FR_I,     FR_O,     FR_P,     FR_EQL,
        KC_LSFT,   FR_Q,     FR_S,      RALT_T(FR_D), SFT_T(FR_F), FR_G,                      FR_H,    SFT_T(FR_J),  RALT_T(FR_K),     FR_L,     FR_M,     KC_QUOT,
        KC_LCTL,   FR_W,     FR_X,      FR_C,       FR_V,       FR_B,      C(KC_F3), KC_HOME, FR_N,    FR_COMM,   FR_SCLN,  FR_COLN,  FR_EXLM,  KC_RSFT,
                                        KC_LALT,    KC_LGUI,    MO(_FUNCTIONS),     KC_SPC,   KC_ENT,    MO(_FUNCTIONS),   KC_BSPC,   KC_RALT
    ),
    [_NO_HOME_ROW_MOD] = LAYOUT(
            _______,  _______,  _______,  _______,  _______,  _______,                      _______,  _______,  _______,  _______,  _______,  _______,
            _______,  _______,  _______,  _______,  _______,  _______,                      _______,  _______,  _______,  _______,  _______,  _______,
            _______,  _______,  _______,  FR_D,     FR_F   ,  _______,                      _______,  FR_J,     FR_K,     _______,  _______,  _______,
            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
                                          _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
    ),
    [_FUNCTIONS] = LAYOUT(
        KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,                            _______,  S(FR_EQL),  FR_MINS,  FR_ASTR,  FR_EQL,  FR_DLR,
        KC_F7  ,  KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,                           KC_HOME,  KC_DELETE,  KC_UP,    KC_PGUP,  RGB_VAI,  FR_CIRC,
        _______,  _______,  _______,  FR_LCBR,  FR_RCBR,  FR_LABK,                          KC_END,   KC_LEFT,    KC_DOWN,  KC_RIGHT, RGB_VAD,  _______,
        _______,  FR_LABK,  _______,  FR_LBRC,  FR_RBRC,  S(FR_LABK),  _______,  KC_AUDIO_MUTE,_______,  _______,    _______,  KC_PGDN,  RGB_TOG, _______,
                                      _______,  _______,  _______,    _______,  _______,      _______,  _______,    TG(_NO_HOME_ROW_MOD)
    )

};

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {

    if (index == 0) {
        // 0 is left-half encoder
        // revert rotation direction depnding on the type of rotary encoder
#ifdef LEFT_MECH_KEYBOARDS_ROTARY_ENCODER
        clockwise = !clockwise; // revert clockwise value
#endif
        if (clockwise) {
            if (IS_LAYER_ON(_FUNCTIONS)) {
                // volume
                tap_code(KC_AUDIO_VOL_UP);
            } else {
                // find
                tap_code(KC_F3);
            }
        } else {
            if (IS_LAYER_ON(_FUNCTIONS)) {
                // volume
                tap_code(KC_AUDIO_VOL_DOWN);
            } else {
                register_code(KC_LSFT);
                tap_code(KC_F3);
                unregister_code(KC_LSFT);
            }
        }
    } else if (index == 1) {
        // 1 is right-half encoder
        if (clockwise) {
            if (IS_LAYER_ON(_FUNCTIONS)) {
                // volume
                tap_code(KC_AUDIO_VOL_UP);
             } else {
                // scrolling
                tap_code(KC_PGDN);
            }
        } else {
            if (IS_LAYER_ON(_FUNCTIONS)) {
                // volume
                tap_code(KC_AUDIO_VOL_DOWN);
            } else {
                // scrolling
              tap_code(KC_PGUP);
            }
        }
    }
    return false;
}
#endif

 void keyboard_post_init_user(void) {
    rgblight_sethsv_noeeprom(COLOR_MAIN_LAYER);
 }

layer_state_t layer_state_set_user(layer_state_t state) {
  switch (get_highest_layer(state)) {
   case _FUNCTIONS:
        rgblight_sethsv_noeeprom(COLOR_FUNCTION_LAYER);
        break;
    case _DEFAULT:
    default: //  for any other layers, or the default layer
        rgblight_sethsv_noeeprom(COLOR_MAIN_LAYER);
        break;
    }
  return state;
}

#ifdef OLED_ENABLE
void render_layer_state_custom(void) {
    static const char PROGMEM default_layer[] = {
        0x20, 0x94, 0x95, 0x96, 0x20,
        0x20, 0xb4, 0xb5, 0xb6, 0x20,
        0x20, 0xd4, 0xd5, 0xd6, 0x20, 0};
    static const char PROGMEM raise_layer[] = {
        0x20, 0x97, 0x98, 0x99, 0x20,
        0x20, 0xb7, 0xb8, 0xb9, 0x20,
        0x20, 0xd7, 0xd8, 0xd9, 0x20, 0};
    static const char PROGMEM lower_layer[] = {
        0x20, 0x9a, 0x9b, 0x9c, 0x20,
        0x20, 0xba, 0xbb, 0xbc, 0x20,
        0x20, 0xda, 0xdb, 0xdc, 0x20, 0};

    switch (get_highest_layer(layer_state | default_layer_state)) {
        case _NO_HOME_ROW_MOD:
            oled_write_P(lower_layer, false);
            break;
        case _FUNCTIONS:
            oled_write_P(raise_layer, false);
            break;
        default:
            oled_write_P(default_layer, false);
    }
}


bool oled_task_user(void){
    if (is_oled_on()){
        // screen is 5 chars wide
        // font is 6x8 pixels
        static const char PROGMEM logo_custom[] = {
            0x80, 0x81, 0x82, 0x83, 0x84,
            0xA0, 0xA1, 0xA2, 0xA3, 0xA4,
            0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0
        };
        static const char PROGMEM space[] = {
            0x20, 0x20, 0x20, 0x20, 0x20, 0
        };
        oled_write_P(logo_custom, false);
        oled_write_P(space, false);

        oled_write_P(PSTR("LEDs "), false);
        bool rgbEnabled = rgblight_is_enabled();
        oled_write_P(rgbEnabled ? PSTR("   on") : PSTR("  off"), false);

        oled_write_P(PSTR("H ROW"), false);
        bool homeRowDisabled = IS_LAYER_ON(_NO_HOME_ROW_MOD);
        oled_write_P(!homeRowDisabled ? PSTR("   on") : PSTR("  off"), false);

        oled_write_P(space, false);

        // use default render layer state
        render_layer_state_custom();

        // SHIFT
        uint8_t modifiers = get_mods()|get_oneshot_mods();
        if(modifiers & MOD_MASK_SHIFT) {
            oled_write_P(PSTR("Shift"), false);
        } else {
            oled_write_P(space, false);
        }
        // CTRL
        if(modifiers & MOD_MASK_CTRL) {
            oled_write_P(PSTR("Ctrl "), false);
        } else {
            oled_write_P(space, false);
        }
        // ALT and ALTGR
        if(modifiers & MOD_BIT_RALT) {
            oled_write_P(PSTR("AltGr"), false);
        } else if(modifiers & MOD_BIT_LALT) {
            oled_write_P(PSTR("Alt  "), false);
        }else {
            oled_write_P(space, false);
        }
    }
    return false;
}
#endif
