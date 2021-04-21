/* Copyright 2021 Trevor Elliott
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

const uint16_t PROGMEM uj_combo[] = {KC_U, KC_J, COMBO_END};
const uint16_t PROGMEM rf_combo[] = {KC_R, KC_F, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(uj_combo, KC_ESC),
    COMBO(rf_combo, KC_TAB),
};

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    BASE,
    SYM,
    NUMB,
    FUN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [BASE] = LAYOUT_tightyl(
/*
 * left hand
 *  +-------+-----+-----+-----+-----+-----+
 *  | =     |  Q  |  W  |  E  |  R  |  T  |
 *  +-------+-----+-----+-----+-----+-----+
 *  |TAB/CTL| C/A |  S  |  D  |  F  |  G  |
 *  +-------+-----+-----+-----+-----+-----+
 *  | LSHIFT|  Z  | A/X | S/C | G/V |  B  |
 *  +-------+-----+-----+-----+-----+-----+-----+
 *                |     | FUN | SYM | BSP | DEL |
 *                +-----+-----+-----+-----+-----+
 */

    KC_EQL,         KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,
    LCTL_T(KC_TAB), LCTL_T(KC_A), KC_S,         KC_D,         KC_F,         KC_G,
    KC_LSFT,        KC_Z,         LALT_T(KC_X), LSFT_T(KC_C), LGUI_T(KC_V), KC_B,
                                  KC_TRNS,      MO(FUN),      MO(SYM),      LT(NUMB, KC_BSPC), KC_DEL,
/* right hand
 *        +-----+-----+-----+-----+-----+-------+
 *        |  Y  |  U  |  I  |  O  |  P  |-/RALT |
 *        +-----+-----+-----+-----+-----+-------+
 *        |  H  |  J  |  K  |  L  | C/; |'/RCTL |
 *        +-----+-----+-----+-----+-----+-------+
 *        |  N  | G/M | S/, | A/. |  /  | RSHIFT|
 *  +-----+-----+-----+-----+-----+-----+-------+
 *  | ENT | SPC | SYM | FUN |     |
 *  +-----+-----+-----+-----+-----+
 */
             KC_Y,             KC_U,         KC_I,            KC_O,           KC_P,            KC_MINS,
             KC_H,             KC_J,         KC_K,            KC_L,           RCTL_T(KC_SCLN), RCTL_T(KC_QUOT),
             KC_N,             RGUI_T(KC_M), RSFT_T(KC_COMM), RALT_T(KC_DOT), KC_SLSH,         KC_RSFT,
    KC_ENT,  LT(NUMB, KC_SPC), MO(SYM),      MO(FUN),         KC_TRNS
    ),

    [NUMB] = LAYOUT_tightyl(
// left hand
//  +-------+-----+-----+-----+-----+-----+
//  |       |  1  |  2  |  3  |  4  |  5  |
//  +-------+-----+-----+-----+-----+-----+
//  |       |     |     | BTN2| BTN1|     |
//  +-------+-----+-----+-----+-----+-----+
//  |       |     |     |     | BTN3|     |
//  +-------+-----+-----+-----+-----+-----+-----+
//                |     |     |     |     |     |
//                +-----+-----+-----+-----+-----+

    KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN2, KC_BTN1, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN3, KC_TRNS,
                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
// right hand
//        +-----+-----+-----+-----+-----+-------+
//        |  6  |  7  |  8  |  9  |  0  |       |
//        +-----+-----+-----+-----+-----+-------+
//        | LEFT| DOWN| UP  |RIGHT|     |       |
//        +-----+-----+-----+-----+-----+-------+
//        | MLFT| MDN | MUP |MRGHT|     |       |
//  +-----+-----+-----+-----+-----+-----+-------+
//  |     |     |     |     |     |
//  +-----+-----+-----+-----+-----+
             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS,
             KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS, KC_TRNS,
             KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [SYM] = LAYOUT_tightyl(
// left hand
//  +-------+-----+-----+-----+-----+-----+
//  |       |  !  |  @  |  #  |  $  |  %  |
//  +-------+-----+-----+-----+-----+-----+
//  |       |  |  |  (  |  )  |  ~  |  `  |
//  +-------+-----+-----+-----+-----+-----+
//  |       |  \  |  <  |  >  | ESC |     |
//  +-------+-----+-----+-----+-----+-----+-----+
//                |     |     |     |     |     |
//                +-----+-----+-----+-----+-----+

    KC_TRNS, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,
    KC_TRNS, KC_PIPE, KC_LPRN, KC_RPRN, KC_TILD, KC_GRV,
    KC_TRNS, KC_BSLS, KC_LT,   KC_GT,   KC_ESC,  KC_TRNS,
                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
// right hand
//        +-----+-----+-----+-----+-----+-------+
//        |  ^  |  &  |  *  |  (  |  )  |       |
//        +-----+-----+-----+-----+-----+-------+
//        |     |  +  |  {  |  }  |  :  |   "   |
//        +-----+-----+-----+-----+-----+-------+
//        |     | ESC |  [  |  ]  |  ?  |       |
//  +-----+-----+-----+-----+-----+-----+-------+
//  |     |     |     |     |     |
//  +-----+-----+-----+-----+-----+
             KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TRNS,
             KC_TRNS, KC_PLUS, KC_LCBR, KC_RCBR, KC_COLN, KC_DQUO,
             KC_TRNS, KC_ESC,  KC_LBRC, KC_RBRC, KC_QUES, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [FUN] = LAYOUT_tightyl(
// left hand
//  +-------+-----+-----+-----+-----+-----+
//  |       |  F1 |  F2 |  F3 |  F4 |  F5 |
//  +-------+-----+-----+-----+-----+-----+
//  |       |  F6 |  F7 |  F8 |  F9 | F10 |
//  +-------+-----+-----+-----+-----+-----+
//  |       |     |     | F11 | F12 |     |
//  +-------+-----+-----+-----+-----+-----+-----+
//                |RESET|     |     |     |     |
//                +-----+-----+-----+-----+-----+

    KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,
    KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_F11,  KC_F12,  KC_TRNS,
                      RESET,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
// right hand
//        +-----+-----+-----+-----+-----+-------+
//        |     |     |     |     |     |       |
//        +-----+-----+-----+-----+-----+-------+
//        |     |     |     |     |     |       |
//        +-----+-----+-----+-----+-----+-------+
//        |     |     |     |     |     |       |
//  +-----+-----+-----+-----+-----+-----+-------+
//  |     |     |     |     |RESET|
//  +-----+-----+-----+-----+-----+
             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET
    ),
/*
    [] = LAYOUT_tightyl(
// left hand
//  +-------+-----+-----+-----+-----+-----+
//  |       |     |     |     |     |     |
//  +-------+-----+-----+-----+-----+-----+
//  |       |     |     |     |     |     |
//  +-------+-----+-----+-----+-----+-----+
//  |       |     |     |     |     |     |
//  +-------+-----+-----+-----+-----+-----+-----+
//                |     |     |     |     |     |
//                +-----+-----+-----+-----+-----+

    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
// right hand
//        +-----+-----+-----+-----+-----+-------+
//        |     |     |     |     |     |       |
//        +-----+-----+-----+-----+-----+-------+
//        |     |     |     |     |     |       |
//        +-----+-----+-----+-----+-----+-------+
//        |     |     |     |     |     |       |
//  +-----+-----+-----+-----+-----+-----+-------+
//  |     |     |     |     |     |
//  +-----+-----+-----+-----+-----+
             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
*/
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}

bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LCTL_T(KC_A):
        case LALT_T(KC_X):
        case LSFT_T(KC_C):
        case LGUI_T(KC_V):
        case RGUI_T(KC_M):
        case RSFT_T(KC_COMM):
        case RALT_T(KC_DOT):
        case RCTL_T(KC_SCLN):
        case LT(NUMB, KC_SPC):
            return true;

        default:
            return false;
    }
}
