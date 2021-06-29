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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    QWERTY,
    COLEMAK,
    COLEMAK_DH,
    SYM,
    NUMB,  // split-hand number layer
    NUMP,  // right-hand number pad
    NAV,
    FUN,
};

// left hand
//  +-------+-----+-----+-----+-----+-----+
//  | =     | l01 | l02 | l03 | l04 | l05 |
//  +-------+-----+-----+-----+-----+-----+
//  |TAB/CTL|C/l11| l12 | l13 | l14 | l15 |
//  +-------+-----+-----+-----+-----+-----+
//  | LSHIFT| l21 |A/l22|S/l23|G/l24| l25 |
//  +-------+-----+-----+-----+-----+-----+-----+
//                |     | FUN | SYM | BSP | DEL |
//                +-----+-----+-----+-----+-----+
//
// right hand
//        +-----+-----+-----+-----+-----+-------+
//        | r00 | r01 | r02 | r03 | r04 |   -   |
//        +-----+-----+-----+-----+-----+-------+
//        | r10 | r11 | r12 | r13 |C/r14|'/RCTL |
//        +-----+-----+-----+-----+-----+-------+
//        | r20 |G/r21|S/r22|A/r23| r24 | RSHIFT|
//  +-----+-----+-----+-----+-----+-----+-------+
//  | ENT | SPC | SYM | FUN |     |
//  +-----+-----+-----+-----+-----+
#define BASE_LAYER(                                                                                         \
  l01, l02, l03, l04, l05,                                                                                  \
  l11, l12, l13, l14, l15,                                                                                  \
  l21, l22, l23, l24, l25,                                                                                  \
                                                                                                            \
  r00, r01, r02, r03, r04,                                                                                  \
  r10, r11, r12, r13, r14,                                                                                  \
  r20, r21, r22, r23, r24)                                                                                  \
                                                                                                            \
LAYOUT_tightyl(                                                                                             \
    KC_EQL,         l01,         l02,         l03,         l04,         l05,                                \
    LCTL_T(KC_TAB), LCTL_T(l11), l12,         l13,         l14,         l15,                                \
    KC_LSFT,        l21,         LALT_T(l22), LSFT_T(l23), LGUI_T(l24), l25,                                \
                                 KC_TRNS,     MO(FUN),     MO(SYM),     LT(NAV, KC_BSPC), LT(NUMP, KC_DEL), \
                                                                                                            \
             r00,              r01,         r02,         r03,         r04,         KC_MINS,                 \
             r10,              r11,         r12,         r13,         RCTL_T(r14), RCTL_T(KC_QUOT),         \
             r20,              RGUI_T(r21), RSFT_T(r22), RALT_T(r23), r24,         KC_RSFT,                 \
    KC_ENT,  LT(NUMB, KC_SPC), MO(SYM),     MO(FUN),     KC_TRNS                                            \
    )

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Default QWERTY base layer */
    [QWERTY] = BASE_LAYER(
    KC_Q, KC_W, KC_E, KC_R, KC_T,
    KC_A, KC_S, KC_D, KC_F, KC_G,
    KC_Z, KC_X, KC_C, KC_V, KC_B,

    KC_Y, KC_U, KC_I,    KC_O,   KC_P,
    KC_H, KC_J, KC_K,    KC_L,   KC_SCLN,
    KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH),

    /* Alternate COLEMAK base layer */
    [COLEMAK] = BASE_LAYER(
    KC_Q, KC_W, KC_F, KC_P, KC_G,
    KC_A, KC_R, KC_S, KC_T, KC_D,
    KC_Z, KC_X, KC_C, KC_V, KC_B,

    KC_J, KC_L, KC_U,    KC_Y,   KC_SCLN,
    KC_H, KC_N, KC_E,    KC_I,   KC_O,
    KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH),

    /* Alternate COLEMAK-DH base layer */
    [COLEMAK_DH] = BASE_LAYER(
    KC_Q, KC_W, KC_F, KC_P, KC_B,
    KC_A, KC_R, KC_S, KC_T, KC_G,
    KC_Z, KC_X, KC_C, KC_D, KC_V,

    KC_J, KC_L, KC_U,    KC_Y,   KC_SCLN,
    KC_M, KC_N, KC_E,    KC_I,   KC_O,
    KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH),

    [NUMP] = LAYOUT_tightyl(
// left hand
//  +-------+-----+-----+-----+-----+-----+
//  |       |     |     |     |     |     |
//  +-------+-----+-----+-----+-----+-----+
//  |       |     |     | MB2 | MB1 |     |
//  +-------+-----+-----+-----+-----+-----+
//  |       |     |     |     | MB3 |     |
//  +-------+-----+-----+-----+-----+-----+-----+
//                |     |     |     |     |     |
//                +-----+-----+-----+-----+-----+

    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN2, KC_BTN1, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN3, KC_TRNS,
                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
// right hand
//        +-----+-----+-----+-----+-----+-------+
//        |  {  |  7  |  8  |  9  |  }  |       |
//        +-----+-----+-----+-----+-----+-------+
//        |  (  |  4  |  5  |  6  |  )  |       |
//        +-----+-----+-----+-----+-----+-------+
//        |  [  |  1  |  2  |  3  |  ]  |       |
//  +-----+-----+-----+-----+-----+-----+-------+
//  |     |  0  |     |     |     |
//  +-----+-----+-----+-----+-----+
             KC_LCBR, KC_7,    KC_8,    KC_9,    KC_RCBR, KC_TRNS,
             KC_LPRN, KC_4,    KC_5,    KC_6,    KC_RPRN, KC_TRNS,
             KC_LBRC, KC_1,    KC_2,    KC_3,    KC_RBRC, KC_TRNS,
    KC_TRNS, KC_0,    KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [NUMB] = LAYOUT_tightyl(
// left hand
//  +-------+-----+-----+-----+-----+-----+
//  |       |  1  |  2  |  3  |  4  |  5  |
//  +-------+-----+-----+-----+-----+-----+
//  |       |  6  |  7  |  8  |  9  |  0  |
//  +-------+-----+-----+-----+-----+-----+
//  |       |  [  |  ]  |  {  |  }  |     |
//  +-------+-----+-----+-----+-----+-----+-----+
//                |     |     |  (  |  )  |     |
//                +-----+-----+-----+-----+-----+

    KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
    KC_TRNS, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_TRNS, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_TRNS,
                      KC_TRNS, KC_TRNS, KC_LPRN, KC_RPRN, KC_TRNS,
// right hand
//        +-----+-----+-----+-----+-----+-------+
//        |  6  |  7  |  8  |  9  |  0  |       |
//        +-----+-----+-----+-----+-----+-------+
//        |     |     |     |     |     |       |
//        +-----+-----+-----+-----+-----+-------+
//        |     |     |     |     |     |       |
//  +-----+-----+-----+-----+-----+-----+-------+
//  |     |     |     |     |     |
//  +-----+-----+-----+-----+-----+
             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS,
             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [NAV] = LAYOUT_tightyl(
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
//        |  ^  |  &  |  *  |  (  |  )  |   _   |
//        +-----+-----+-----+-----+-----+-------+
//        |     |  +  |  {  |  }  |  :  |   "   |
//        +-----+-----+-----+-----+-----+-------+
//        |     | ESC |  [  |  ]  |  ?  |       |
//  +-----+-----+-----+-----+-----+-----+-------+
//  |     |     |     |     |     |
//  +-----+-----+-----+-----+-----+
             KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS,
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
//        |QWERT|     |     |     |     |       |
//        +-----+-----+-----+-----+-----+-------+
//        |COLEM|     |     |     |     |       |
//        +-----+-----+-----+-----+-----+-------+
//        |COLDH|     |     |     |     |       |
//  +-----+-----+-----+-----+-----+-----+-------+
//  |     |     |     |     |RESET|
//  +-----+-----+-----+-----+-----+
             DF(QWERTY),     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
             DF(COLEMAK),    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
             DF(COLEMAK_DH), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, RESET
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

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(NAV, KC_BSPC):
        case LT(NUMP, KC_DEL):
            return 150;

        default:
            return TAPPING_TERM;
    }
}
