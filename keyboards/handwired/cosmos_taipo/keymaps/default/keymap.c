// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ortho_2x5(
        KC_BSPC, KC_I, KC_N, KC_S, KC_R,
        KC_SPC,  KC_E, KC_T, KC_O, KC_A
    )
};

#define TAIPO_SEQ(x, y) \
    const uint16_t PROGMEM X_##x##y[] = {KC_##x, KC_##y, COMBO_END}; \
    const uint16_t PROGMEM I_##x##y[] = {KC_##x, KC_##y, KC_BSPC, COMBO_END}; \
    const uint16_t PROGMEM O_##x##y[] = {KC_##x, KC_##y, KC_SPC, COMBO_END};

#define TAIPO_COMBO(x, y, k, ki, ko) \
    COMBO(X_##x##y, k), \
    COMBO(I_##x##y, ki), \
    COMBO(O_##x##y, ko)

const uint16_t PROGMEM O_I[] = {KC_I,KC_SPC,COMBO_END};
const uint16_t PROGMEM I_I[] = {KC_I,KC_BSPC,COMBO_END};
const uint16_t PROGMEM O_N[] = {KC_N,KC_SPC,COMBO_END};
const uint16_t PROGMEM I_N[] = {KC_N,KC_BSPC,COMBO_END};
const uint16_t PROGMEM O_S[] = {KC_S,KC_SPC,COMBO_END};
const uint16_t PROGMEM I_S[] = {KC_S,KC_BSPC,COMBO_END};
const uint16_t PROGMEM O_R[] = {KC_R,KC_SPC,COMBO_END};
const uint16_t PROGMEM I_R[] = {KC_R,KC_BSPC,COMBO_END};
const uint16_t PROGMEM O_E[] = {KC_E,KC_SPC,COMBO_END};
const uint16_t PROGMEM I_E[] = {KC_E,KC_BSPC,COMBO_END};
const uint16_t PROGMEM O_T[] = {KC_T,KC_SPC,COMBO_END};
const uint16_t PROGMEM I_T[] = {KC_T,KC_BSPC,COMBO_END};
const uint16_t PROGMEM O_O[] = {KC_O,KC_SPC,COMBO_END};
const uint16_t PROGMEM I_O[] = {KC_O,KC_BSPC,COMBO_END};
const uint16_t PROGMEM O_A[] = {KC_A,KC_SPC,COMBO_END};
const uint16_t PROGMEM I_A[] = {KC_A,KC_BSPC,COMBO_END};

TAIPO_SEQ(I, N); TAIPO_SEQ(S, R);
TAIPO_SEQ(E, T); TAIPO_SEQ(O, A);
TAIPO_SEQ(T, O); TAIPO_SEQ(N, S);
TAIPO_SEQ(E, A); TAIPO_SEQ(I, R);
TAIPO_SEQ(I, S); TAIPO_SEQ(N, R);
TAIPO_SEQ(E, O); TAIPO_SEQ(T, A);
TAIPO_SEQ(I, O); TAIPO_SEQ(T, R);
TAIPO_SEQ(N, A); TAIPO_SEQ(E, S);
TAIPO_SEQ(I, A); TAIPO_SEQ(E, R);
TAIPO_SEQ(N, O); TAIPO_SEQ(T, S);
TAIPO_SEQ(I, T); TAIPO_SEQ(O, R);
TAIPO_SEQ(S, A); TAIPO_SEQ(E, N);
TAIPO_SEQ(I, E); TAIPO_SEQ(R, A);
TAIPO_SEQ(N, T); TAIPO_SEQ(S, O);

const uint16_t PROGMEM X_INS_[] = {KC_I, KC_N, KC_S, COMBO_END};
const uint16_t PROGMEM I_INS_[] = {KC_I, KC_N, KC_S, KC_BSPC, COMBO_END};
const uint16_t PROGMEM O_INS_[] = {KC_I, KC_N, KC_S, KC_SPC, COMBO_END};

const uint16_t PROGMEM X_ETO_[] = {KC_E, KC_T, KC_O, COMBO_END};
const uint16_t PROGMEM I_ETO_[] = {KC_E, KC_T, KC_O, KC_BSPC, COMBO_END};
const uint16_t PROGMEM O_ETO_[] = {KC_E, KC_T, KC_O, KC_SPC, COMBO_END};

const uint16_t PROGMEM X__TOA[] = {KC_T,KC_O,KC_A,COMBO_END};

combo_t key_combos[] = {
    COMBO(I_I, S(KC_I)),
    COMBO(O_I, KC_RPRN),
    COMBO(I_N, S(KC_N)),
    COMBO(O_N, KC_RBRC),
    COMBO(I_S, S(KC_S)),
    COMBO(O_S, S(KC_RBRC)),
    COMBO(I_R, S(KC_R)),
    COMBO(O_R, KC_LT),
    COMBO(I_E, S(KC_E)),
    COMBO(O_E, S(KC_LPRN)),
    COMBO(I_T, S(KC_T)),
    COMBO(O_T, KC_LBRC),
    COMBO(I_O, S(KC_O)),
    COMBO(O_O, S(KC_LBRC)),
    COMBO(I_A, S(KC_A)),
    COMBO(O_A, KC_GT),

    TAIPO_COMBO(I, N, KC_Y,    S(KC_Y), KC_5),    TAIPO_COMBO(S, R, KC_B,    S(KC_B), KC_9),
    TAIPO_COMBO(E, T, KC_H,    S(KC_H), KC_0),    TAIPO_COMBO(O, A, KC_L,    S(KC_L), KC_4),
    TAIPO_COMBO(T, O, KC_U,    S(KC_U), KC_2),    TAIPO_COMBO(N, S, KC_P,    S(KC_P), KC_7),
    TAIPO_COMBO(E, A, KC_D,    S(KC_D), KC_AT),   TAIPO_COMBO(I, R, KC_G,    S(KC_G), KC_HASH),
    TAIPO_COMBO(I, S, KC_F,    S(KC_F), KC_6),    TAIPO_COMBO(N, R, KC_Z,    S(KC_Z), KC_8),
    TAIPO_COMBO(E, O, KC_C,    S(KC_C), KC_1),    TAIPO_COMBO(T, A, KC_Q,    S(KC_Q), KC_3),
    TAIPO_COMBO(I, O, KC_K,    S(KC_K), KC_PLUS), TAIPO_COMBO(T, R, KC_X,    S(KC_X), KC_CIRC),
    TAIPO_COMBO(N, A, KC_J,    S(KC_J), KC_EQL),  TAIPO_COMBO(E, S, KC_V,    S(KC_V), KC_ASTR),
    TAIPO_COMBO(I, A, KC_W,    S(KC_W), KC_AMPR), TAIPO_COMBO(E, R, KC_M,    S(KC_M), KC_DLR),
    TAIPO_COMBO(N, O, KC_MINS, KC_UNDS, KC_PERC), TAIPO_COMBO(T, S, KC_SLSH, KC_BSLS, KC_PIPE),
    TAIPO_COMBO(I, T, KC_QUES, KC_EXLM, KC_NO),   TAIPO_COMBO(O, R, KC_SCLN, KC_COLN, KC_NO),
    TAIPO_COMBO(S, A, KC_QUOT, KC_DQUO, KC_GRV),  TAIPO_COMBO(E, N, KC_COMM, KC_DOT,  KC_TILD),

    TAIPO_COMBO(I, E, OSM(MOD_LSFT), KC_LEFT, KC_PGDN), TAIPO_COMBO(R, A, OSM(MOD_LGUI), KC_RGHT, KC_PGUP),
    TAIPO_COMBO(N, T, OSM(MOD_LCTL), KC_DOWN, KC_END),  TAIPO_COMBO(S, O, OSM(MOD_LALT), KC_UP,   KC_HOME),

    COMBO(X_INS_, KC_TAB),
    COMBO(I_INS_, KC_DEL),
    COMBO(O_INS_, KC_NO), // TODO: function key layer

    COMBO(X_ETO_, KC_ENT),
    COMBO(I_ETO_, KC_ESC),
    COMBO(O_ETO_, KC_ALGR),

    COMBO(X__TOA, QK_BOOT),
};
