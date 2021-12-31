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
#include "features/caps_word.h"

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    QWERTY_ALT,
    COLEMAK_ALT,
    QWERTY,
    COLEMAK,

    NUM_ALT,
    NUM,

    SYM_ALT,
    SYM,

    MOUS,
    NAV,
    MEDIA,
    FUN,

    CFG,
};

// left hand
//  +-------+-----+-----+-----+-----+-----+
//  |   =   | l01 | l02 | l03 | l04 | l05 |
//  +-------+-----+-----+-----+-----+-----+
//  |  TAB  | l11 | l12 | l13 | l14 | l15 |
//  +-------+-----+-----+-----+-----+-----+
//  | LSHIFT| l21 | l22 | l23 | l24 | l25 |
//  +-------+-----+-----+-----+-----+-----+-----+
//                |     | CFG | lt1 | lt3 | lt3 |
//                +-----+-----+-----+-----+-----+
//
// right hand
//        +-----+-----+-----+-----+-----+-------+
//        | r00 | r01 | r02 | r03 | r04 |   -   |
//        +-----+-----+-----+-----+-----+-------+
//        | r10 |S/r11|C/r12|A/r13|G/r14|   '   |
//        +-----+-----+-----+-----+-----+-------+
//        | r20 | r21 | r22 | r23 | r24 | RSHIFT|
//  +-----+-----+-----+-----+-----+-----+-------+
//  | ENT | BSP | DEL | CFG |     |
//  +-----+-----+-----+-----+-----+
#define BASE_36(                                        \
  l01, l02, l03, l04, l05,                              \
  l11, l12, l13, l14, l15,                              \
  l21, l22, l23, l24, l25,                              \
                 lt1, lt2, lt3,                         \
                                                        \
       r00, r01, r02, r03, r04,                         \
       r10, r11, r12, r13, r14,                         \
       r20, r21, r22, r23, r24,                         \
  rt1, rt2, rt3)                                        \
                                                        \
LAYOUT_tightyl(                                         \
    KC_EQL,  l01, l02,     l03,     l04, l05,           \
    KC_TAB,  l11, l12,     l13,     l14, l15,           \
    KC_LSFT, l21, l22,     l23,     l24, l25,           \
                  KC_TRNS, MO(CFG), lt1, lt2, lt3,      \
                                                        \
               r00, r01,     r02,    r03, r04, KC_MINS, \
               r10, r11,     r12,    r13, r14, KC_QUOT, \
               r20, r21,     r22,    r23, r24, KC_RSFT, \
    rt1, rt2, rt3,  MO(CFG), KC_TRNS                    \
    )

#define THUMB_ESC LT(MEDIA, KC_ESC)
#define THUMB_SPC LT(NAV, KC_SPC)
#define THUMB_TAB LT(MOUS, KC_TAB)

#define THUMB_DEL LT(FUN, KC_DEL)
#define THUMB_BSP LT(NUM, KC_BSPC)
#define THUMB_ENT LT(SYM, KC_ENT)

#define T_ALT_BSP LT(NUM_ALT, KC_BSPC)
#define T_ALT_ENT LT(SYM_ALT, KC_ENT)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Default QWERTY base layer
    // Homerow mods: GACS
    [QWERTY_ALT] = BASE_36(
    KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,
    LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G,
    KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,
                                              THUMB_ESC,    THUMB_SPC, THUMB_TAB,

               KC_Y,      KC_U,         KC_I,         KC_O,         KC_P,
               KC_H,      RSFT_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), RGUI_T(KC_SCLN),
               KC_N,      KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,
    T_ALT_ENT, T_ALT_BSP, THUMB_DEL),

    // Alternate COLEMAK base layer
    // Homerow mods: GACS
    [COLEMAK_ALT] = BASE_36(
    KC_Q,         KC_W,         KC_F,         KC_P,         KC_G,
    LGUI_T(KC_A), LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T), KC_D,
    KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,
                                THUMB_ESC,    THUMB_SPC,    THUMB_TAB,

               KC_J,      KC_L,         KC_U,         KC_Y,         KC_SCLN,
               KC_H,      RSFT_T(KC_N), RCTL_T(KC_E), RALT_T(KC_I), RGUI_T(KC_O),
               KC_K,      KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,
    T_ALT_ENT, T_ALT_BSP, THUMB_DEL),

    // Alternate QWERTY base layer
    // Homerow mods: C
    //                ASG
    [QWERTY] = BASE_36(
    KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,
    LCTL_T(KC_A), KC_S,         KC_D,         KC_F,         KC_G,
    KC_Z,         LALT_T(KC_X), LSFT_T(KC_C), LGUI_T(KC_V), KC_B,
                                              THUMB_ESC,    THUMB_SPC, THUMB_TAB,

               KC_Y,      KC_U,         KC_I,            KC_O,           KC_P,
               KC_H,      KC_J,         KC_K,            KC_L,           RCTL_T(KC_SCLN),
               KC_N,      RGUI_T(KC_M), RSFT_T(KC_COMM), RALT_T(KC_DOT), KC_SLSH,
    THUMB_ENT, THUMB_BSP, THUMB_DEL),

    // Alternate COLEMAK base layer
    // Homerow mods: C
    //                ASG
    [COLEMAK] = BASE_36(
    KC_Q,         KC_W,         KC_F,         KC_P,         KC_G,
    LCTL_T(KC_A), KC_R,         KC_S,         KC_T,         KC_D,
    KC_Z,         LALT_T(KC_X), LSFT_T(KC_C), LGUI_T(KC_V), KC_B,
                                              THUMB_ESC,    THUMB_SPC, THUMB_TAB,

               KC_J,      KC_L,         KC_U,            KC_Y,           KC_SCLN,
               KC_H,      KC_N,         KC_E,            KC_I,           RCTL_T(KC_O),
               KC_K,      RGUI_T(KC_M), RSFT_T(KC_COMM), RALT_T(KC_DOT), KC_SLSH,
    THUMB_ENT, THUMB_BSP, THUMB_DEL),


    [NUM_ALT] = LAYOUT_tightyl(
// left hand
//  +-------+-----+-----+-----+-----+-----+
//  |       |  [  |  7  |  8  |  9  |  ]  |
//  +-------+-----+-----+-----+-----+-----+
//  |       |  ;  |  4  |  5  |  6  |  =  |
//  +-------+-----+-----+-----+-----+-----+
//  |       |  `  |  1  |  2  |  3  |  \  |
//  +-------+-----+-----+-----+-----+-----+-----+
//                |     |     |  .  |  0  |  -  |
//                +-----+-----+-----+-----+-----+

    KC_TRNS, KC_LBRC, KC_7,    KC_8,    KC_9,   KC_RBRC,
    KC_TRNS, KC_SCLN, KC_4,    KC_5,    KC_6,   KC_EQL,
    KC_TRNS, KC_GRV,  KC_1,    KC_2,    KC_3,   KC_BSLS,
                      KC_TRNS, KC_TRNS, KC_DOT, KC_0,    KC_MINS,
// right hand
//        +-----+-----+-----+-----+-----+-------+
//        |     |     |     |     |     |       |
//        +-----+-----+-----+-----+-----+-------+
//        |     | RSFT| RCTL| RALT| RGUI|       |
//        +-----+-----+-----+-----+-----+-------+
//        |     |     |     |     |     |       |
//  +-----+-----+-----+-----+-----+-----+-------+
//  |     |     |     |     |     |
//  +-----+-----+-----+-----+-----+
             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
             KC_TRNS, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, KC_TRNS,
             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [NUM] = LAYOUT_tightyl(
// left hand
//  +-------+-----+-----+-----+-----+-----+
//  |       |  1  |  2  |  3  |  4  |  5  |
//  +-------+-----+-----+-----+-----+-----+
//  |       |  6  |  7  |  8  |  9  |  0  |
//  +-------+-----+-----+-----+-----+-----+
//  |       |  `  |  [  |  ]  |  =  |  \  |
//  +-------+-----+-----+-----+-----+-----+-----+
//                |     |     |  '  |  ;  |  -  |
//                +-----+-----+-----+-----+-----+

    KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
    KC_TRNS, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_TRNS, KC_GRV,  KC_LBRC, KC_RBRC, KC_EQL,  KC_BSLS,
                      KC_TRNS, KC_TRNS, KC_QUOT, KC_SCLN, KC_MINS,
// right hand
//        +-----+-----+-----+-----+-----+-------+
//        |     |     |     |     |     |       |
//        +-----+-----+-----+-----+-----+-------+
//        |     |     |     |     | RCTL|       |
//        +-----+-----+-----+-----+-----+-------+
//        |     | RGUI| RSFT| RALT|     |       |
//  +-----+-----+-----+-----+-----+-----+-------+
//  |     |     |     |     |     |
//  +-----+-----+-----+-----+-----+
             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_RCTL, KC_TRNS,
             KC_TRNS, KC_RGUI, KC_RSFT, KC_RALT, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [SYM_ALT] = LAYOUT_tightyl(
// left hand
//  +-------+-----+-----+-----+-----+-----+
//  |       |  {  |  &  |  *  |  (  |  }  |
//  +-------+-----+-----+-----+-----+-----+
//  |       |  :  |  $  |  %  |  ^  |  +  |
//  +-------+-----+-----+-----+-----+-----+
//  |       |  ~  |  !  |  @  |  #  |  |  |
//  +-------+-----+-----+-----+-----+-----+-----+
//                |     |     |  (  |  )  |  _  |
//                +-----+-----+-----+-----+-----+

    KC_TRNS, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,
    KC_TRNS, KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,
    KC_TRNS, KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE,
                      KC_TRNS, KC_TRNS, KC_LPRN, KC_RPRN, KC_UNDS,
// right hand
//        +-----+-----+-----+-----+-----+-------+
//        |     |     |     |     |     |       |
//        +-----+-----+-----+-----+-----+-------+
//        |     | RSFT| RCTL| RALT| RGUI|       |
//        +-----+-----+-----+-----+-----+-------+
//        |     |     |     |     |     |       |
//  +-----+-----+-----+-----+-----+-----+-------+
//  |     |     |     |     |     |
//  +-----+-----+-----+-----+-----+
             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
             KC_TRNS, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, KC_TRNS,
             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),


    [SYM] = LAYOUT_tightyl(
// left hand
//  +-------+-----+-----+-----+-----+-----+
//  |       |  !  |  @  |  #  |  $  |  %  |
//  +-------+-----+-----+-----+-----+-----+
//  |       |  ^  |  &  |  *  |  (  |  )  |
//  +-------+-----+-----+-----+-----+-----+
//  |       |  ~  |  {  |  }  |  +  |  |  |
//  +-------+-----+-----+-----+-----+-----+-----+
//                |     |     |  "  |  :  |  _  |
//                +-----+-----+-----+-----+-----+

    KC_TRNS, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,
    KC_TRNS, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
    KC_TRNS, KC_TILD, KC_LCBR, KC_RCBR, KC_PLUS, KC_PIPE,
                      KC_TRNS, KC_TRNS, KC_DQUO, KC_COLN, KC_UNDS,
// right hand
//        +-----+-----+-----+-----+-----+-------+
//        |     |     |     |     |     |       |
//        +-----+-----+-----+-----+-----+-------+
//        |     |     |     |     | RCTL|       |
//        +-----+-----+-----+-----+-----+-------+
//        |     | RGUI| RSFT| RALT|     |       |
//  +-----+-----+-----+-----+-----+-----+-------+
//  |     |     |     |     |     |
//  +-----+-----+-----+-----+-----+
             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_RCTL, KC_TRNS,
             KC_TRNS, KC_RGUI, KC_RSFT, KC_RALT, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [NAV] = LAYOUT_tightyl(
// left hand
//  +-------+-----+-----+-----+-----+-----+
//  |       |     |     |     |     |     |
//  +-------+-----+-----+-----+-----+-----+
//  |       | LGUI| LALT| LCTL| LSFT|     |
//  +-------+-----+-----+-----+-----+-----+
//  |       |     |     |     |     |     |
//  +-------+-----+-----+-----+-----+-----+-----+
//                |     |     |     |     |     |
//                +-----+-----+-----+-----+-----+

    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
// right hand
//        +-----+-----+-----+-----+-----+-------+
//        | AGIN|PASTE| COPY| CUT | UNDO|       |
//        +-----+-----+-----+-----+-----+-------+
//        | LEFT| DOWN| UP  |RIGHT| CAPS|       |
//        +-----+-----+-----+-----+-----+-------+
//        | HOME| PGDN| PGUP| END | INS |       |
//  +-----+-----+-----+-----+-----+-----+-------+
//  |     |     |     |     |     |
//  +-----+-----+-----+-----+-----+
             KC_AGIN, KC_PSTE, KC_COPY, KC_CUT,  KC_UNDO, KC_TRNS,
             KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_CAPS, KC_TRNS,
             KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_INS,  KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [MOUS] = LAYOUT_tightyl(

// left hand
//  +-------+-----+-----+-----+-----+-----+
//  |       |     | MB3 | MB1 | MB2 |     |
//  +-------+-----+-----+-----+-----+-----+
//  |       | LGUI| LALT| LCTL| LSFT|     |
//  +-------+-----+-----+-----+-----+-----+
//  |       |     |     |     |     |     |
//  +-------+-----+-----+-----+-----+-----+-----+
//                |     |     |     |     |     |
//                +-----+-----+-----+-----+-----+

    KC_TRNS, KC_TRNS, KC_BTN3, KC_BTN1, KC_BTN2, KC_TRNS,
    KC_TRNS, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
// right hand
//        +-----+-----+-----+-----+-----+-------+
//        | AGIN|PASTE| COPY| CUT | UNDO|       |
//        +-----+-----+-----+-----+-----+-------+
//        |MS_L |MS_D |MS_U |MS_R |     |       |
//        +-----+-----+-----+-----+-----+-------+
//        |WH_L |WH_D |WH_U |WH_R |     |       |
//  +-----+-----+-----+-----+-----+-----+-------+
//  | MB2 | MB1 | MB3 |     |     |
//  +-----+-----+-----+-----+-----+
             KC_AGIN, KC_PSTE, KC_COPY, KC_CUT,  KC_UNDO, KC_TRNS,
             KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_TRNS, KC_TRNS,
             KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_TRNS, KC_TRNS,
    KC_BTN2, KC_BTN1, KC_BTN3, KC_TRNS, KC_TRNS
    ),

    [MEDIA] = LAYOUT_tightyl(
// left hand
//  +-------+-----+-----+-----+-----+-----+
//  |       |     |     |     |     |     |
//  +-------+-----+-----+-----+-----+-----+
//  |       | LGUI| LALT| LCTL| LSFT|     |
//  +-------+-----+-----+-----+-----+-----+
//  |       |     |     |     |     |     |
//  +-------+-----+-----+-----+-----+-----+-----+
//                |     |     |     |     |     |
//                +-----+-----+-----+-----+-----+

    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
// right hand
//        +-----+-----+-----+-----+-----+-------+
//        |     |     |     |     |     |       |
//        +-----+-----+-----+-----+-----+-------+
//        |     | MPRV| VOLD| VOLU| MNXT|       |
//        +-----+-----+-----+-----+-----+-------+
//        |     |     |     |     |     |       |
//  +-----+-----+-----+-----+-----+-----+-------+
//  | MSTP| MPLY| MUTE|     |     |
//  +-----+-----+-----+-----+-----+
             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
             KC_TRNS, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_TRNS,
             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_MSTP, KC_MPLY, KC_MUTE, KC_TRNS, KC_TRNS
    ),

    [FUN] = LAYOUT_tightyl(
// left hand
//  +-------+-----+-----+-----+-----+-----+
//  |       | F12 |  F7 |  F8 |  F9 |     |
//  +-------+-----+-----+-----+-----+-----+
//  |       | F11 |  F4 |  F5 |  F6 |     |
//  +-------+-----+-----+-----+-----+-----+
//  |       | F10 |  F1 |  F2 |  F3 |     |
//  +-------+-----+-----+-----+-----+-----+-----+
//                |     |     |     |     |     |
//                +-----+-----+-----+-----+-----+

    KC_TRNS, KC_F12, KC_F7,   KC_F8,   KC_F9,   KC_TRNS,
    KC_TRNS, KC_F11, KC_F4,   KC_F5,   KC_F6,   KC_TRNS,
    KC_TRNS, KC_F10, KC_F1,   KC_F2,   KC_F3,   KC_TRNS,
                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
// right hand
//        +-----+-----+-----+-----+-----+-------+
//        |     |     |     |     |     |       |
//        +-----+-----+-----+-----+-----+-------+
//        |     | RSFT| RCTL| RALT| RGUI|       |
//        +-----+-----+-----+-----+-----+-------+
//        |     |     |     |     |     |       |
//  +-----+-----+-----+-----+-----+-----+-------+
//  |     |     |     |     |     |
//  +-----+-----+-----+-----+-----+
             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
             KC_TRNS, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, KC_TRNS,
             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [CFG] = LAYOUT_tightyl(
// left hand
//  +-------+-----+-----+-----+-----+-----+
//  |       |     |     |     |     |     |
//  +-------+-----+-----+-----+-----+-----+
//  |       |     |     |     |     |     |
//  +-------+-----+-----+-----+-----+-----+
//  |       |     |     |     |     |     |
//  +-------+-----+-----+-----+-----+-----+-----+
//                |RESET|     |     |     |     |
//                +-----+-----+-----+-----+-----+

    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                      RESET,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
// right hand
//        +-----+-----+-----+-----+-----+-------+
//        |QWERT|QWER2|     |     |     |       |
//        +-----+-----+-----+-----+-----+-------+
//        |COLEM|COLE2|     |     |     |       |
//        +-----+-----+-----+-----+-----+-------+
//        |     |     |     |     |     |       |
//  +-----+-----+-----+-----+-----+-----+-------+
//  |     |     |     |     |RESET|
//  +-----+-----+-----+-----+-----+
             DF(QWERTY), DF(QWERTY_ALT),  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
             DF(COLEMAK),DF(COLEMAK_ALT), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
             KC_TRNS,    KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,    KC_TRNS,         KC_TRNS, RESET
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
    if (!process_caps_word(keycode, record)) {
        return false;
    }

    return true;
}

// Faster tapping-term for thumb keys
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case THUMB_ESC:
        case THUMB_SPC:
        case THUMB_TAB:
        case THUMB_DEL:
        case THUMB_BSP:
        case THUMB_ENT:
        case T_ALT_BSP:
        case T_ALT_ENT:
            return 150;

        default:
            return TAPPING_TERM;
    }
}

// Use permissive-hold for all of the thumb keys
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_F):
        case RSFT_T(KC_J):
        case THUMB_ESC:
        case THUMB_SPC:
        case THUMB_TAB:
        case THUMB_DEL:
        case THUMB_BSP:
        case THUMB_ENT:
        case T_ALT_BSP:
        case T_ALT_ENT:
            return true;

        default:
            return false;
    }
}
