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
    QWERTY,
    COLEMAK,
    NUM,
    SYM,

    MOUSE,
    NAV,
    MEDIA,
    FUN,

    BUTTON,

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
//        | r10 | r11 | r12 | r13 | r14 |   '   |
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
#define THUMB_TAB LT(MOUSE, KC_TAB)

#define THUMB_DEL LT(FUN, KC_DEL)
#define THUMB_BSP LT(NUM, KC_BSPC)
#define THUMB_ENT LT(SYM, KC_ENT)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Default QWERTY base layer
    // Homerow mods: GACS
    [QWERTY] = BASE_36(
    KC_Q,             KC_W,         KC_E,         KC_R,         KC_T,
    LGUI_T(KC_A),     LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G,
    LT(BUTTON, KC_Z), KC_X,         KC_C,         KC_V,         KC_B,
                                                  THUMB_ESC,    THUMB_SPC, THUMB_TAB,

               KC_Y,      KC_U,         KC_I,         KC_O,         KC_P,
               KC_H,      RSFT_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), RGUI_T(KC_QUOT),
               KC_N,      KC_M,         KC_COMM,      KC_DOT,       LT(BUTTON, KC_SLSH),
    THUMB_ENT, THUMB_BSP, THUMB_DEL),

    // Alternate COLEMAK base layer
    // Homerow mods: GACS
    [COLEMAK] = BASE_36(
    KC_Q,             KC_W,         KC_F,         KC_P,         KC_G,
    LGUI_T(KC_A),     LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T), KC_D,
    LT(BUTTON, KC_Z), KC_X,         KC_C,         KC_V,         KC_B,
                                    THUMB_ESC,    THUMB_SPC,    THUMB_TAB,

               KC_J,      KC_L,         KC_U,         KC_Y,         KC_QUOT,
               KC_H,      RSFT_T(KC_N), RCTL_T(KC_E), RALT_T(KC_I), RGUI_T(KC_O),
               KC_K,      KC_M,         KC_COMM,      KC_DOT,       LT(BUTTON, KC_SLSH),
    THUMB_ENT, THUMB_BSP, THUMB_DEL),

    [NUM] = LAYOUT_tightyl(
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

    [SYM] = LAYOUT_tightyl(
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

    [MOUSE] = LAYOUT_tightyl(

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
//        |MS_L |MS_D |MS_U |MS_R |     |       |
//        +-----+-----+-----+-----+-----+-------+
//        |WH_L |WH_D |WH_U |WH_R |     |       |
//  +-----+-----+-----+-----+-----+-----+-------+
//  | MB1 | MB3 | MB2 |     |     |
//  +-----+-----+-----+-----+-----+
             KC_AGIN, KC_PSTE, KC_COPY, KC_CUT,  KC_UNDO, KC_TRNS,
             KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_TRNS, KC_TRNS,
             KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_TRNS, KC_TRNS,
    KC_BTN1, KC_BTN3, KC_BTN2, KC_TRNS, KC_TRNS
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
//        | MPRV| VOLD| VOLU| MNXT|     |       |
//        +-----+-----+-----+-----+-----+-------+
//        |     |     |     |     |     |       |
//  +-----+-----+-----+-----+-----+-----+-------+
//  | MSTP| MPLY| MUTE|     |     |
//  +-----+-----+-----+-----+-----+
             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
             KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_TRNS, KC_TRNS,
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

    [BUTTON] = LAYOUT_tightyl(
// left hand
//  +-------+-----+-----+-----+-----+-----+
//  |       | UNDO| CUT |COPY |PASTE|REDO |
//  +-------+-----+-----+-----+-----+-----+
//  |       | LGUI| LALT| LCTL| LSFT|     |
//  +-------+-----+-----+-----+-----+-----+
//  |       | UNDO| CUT |COPY |PASTE|REDO |
//  +-------+-----+-----+-----+-----+-----+-----+
//                |     |     | MB2 | MB3 | MB1 |
//                +-----+-----+-----+-----+-----+

    KC_TRNS, KC_UNDO, KC_CUT,  KC_COPY, KC_PASTE, KC_AGIN,
    KC_TRNS, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,  KC_TRNS,
    KC_TRNS, KC_UNDO, KC_CUT,  KC_COPY, KC_PASTE, KC_AGIN,
                      KC_TRNS, KC_TRNS, KC_BTN2,  KC_BTN3, KC_BTN1,
// right hand
//        +-----+-----+-----+-----+-----+-------+
//        |REDO |PASTE|COPY | CUT |UNDO |       |
//        +-----+-----+-----+-----+-----+-------+
//        |     | RSFT| RCTL| RALT| RGUI|       |
//        +-----+-----+-----+-----+-----+-------+
//        |REDO |PASTE|COPY | CUT |UNDO |       |
//  +-----+-----+-----+-----+-----+-----+-------+
//  | MB1 | MB3 | MB2 |     |     |
//  +-----+-----+-----+-----+-----+
             KC_AGIN, KC_PASTE, KC_COPY, KC_CUT,  KC_UNDO, KC_TRNS,
             KC_TRNS, KC_RSFT,  KC_RCTL, KC_RALT, KC_RGUI, KC_TRNS,
             KC_AGIN, KC_PASTE, KC_COPY, KC_CUT,  KC_UNDO, KC_TRNS,
    KC_BTN1, KC_BTN3, KC_BTN2,  KC_TRNS, KC_TRNS
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
//        |     |QWERT|     |     |     |       |
//        +-----+-----+-----+-----+-----+-------+
//        |     |COLEM|     |     |     |       |
//        +-----+-----+-----+-----+-----+-------+
//        |     |     |     |     |     |       |
//  +-----+-----+-----+-----+-----+-----+-------+
//  |     |     |     |     |RESET|
//  +-----+-----+-----+-----+-----+
             KC_TRNS, DF(QWERTY),  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
             KC_TRNS, DF(COLEMAK), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
             KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, RESET
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
            return true;

        default:
            return false;
    }
}
