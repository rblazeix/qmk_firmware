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

#pragma once

// Uncommnt when using the rotary encoder from mech keyboards
// (second keyboard at work)
//#define LEFT_MECH_KEYBOARDS_ROTARY_ENCODER

#ifdef ENCODER_ENABLE
#    ifndef LEFT_MECH_KEYBOARDS_ROTARY_ENCODER
#        define ENCODER_RESOLUTION 2
#    endif
#endif

#define RGB_DISABLE_WHEN_USB_SUSPENDED                 // turn off effects when suspended
#define RGB_MATRIX_TIMEOUT 25000                       // number of milliseconds to wait until rgb automatically turns off
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_COLOR // Sets the default mode, if none has been set

#define RGB_MATRIX_DEFAULT_HUE 123 // Sets the default hue value, if none has been set
#define RGB_MATRIX_DEFAULT_SAT 90  // Sets the default saturation value, if none has been set
#define RGB_MATRIX_DEFAULT_VAL 112 // Sets the default brightness value, if none has been set

#ifdef LEFT_MECH_KEYBOARDS_ROTARY_ENCODER
#    define COLOR_MAIN_LAYER HSV_YELLOW
#    define COLOR_FUNCTION_LAYER HSV_RED
#else
#    define COLOR_MAIN_LAYER HSV_CYAN
#    define COLOR_FUNCTION_LAYER HSV_GREEN
#endif

// #define NO_AUTO_SHIFT_SPECIAL
