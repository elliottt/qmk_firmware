/* Good on you for modifying your layout! if you don't have
 * time to read the QMK docs, a list of keycodes can be found at
 *
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 *
 * There's also a template for adding new layers at the bottom of this file!
 */

#include QMK_KEYBOARD_H

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define NUMB 2 // numbers/motion

// Blank template at the bottom

enum customKeycodes {
	URL  = 1
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * | = / +  |   Q  |   W  |   E  |   R  |   T  |                         |   Y  |   U  |   I  |   O  |   P  |  - _   |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |Ctrl/Tab|   A  |   S  |  D   |   F  |   G  | Esc  |           | Esc  |   H  |   J  |   K  |   L  | ;  : | Ctrl/" |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  | LGui |           | RGui |   N  |   M  | ,  < | . >  | /  ? | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                    .----------.   .-------.                                 .------.   .-----.
 *                    | Alt      |   | SYMB  |                                 | SYMB |   |BKSP |
 *                    '----------'   '-------'                                 `------.   '-----'
 *                                        ,-------.                      ,-------.
 *                                        | MMB   |                      | PgDn  |
 *                                 ,------|-------|                      |-------|------.
 *                                 | NUMB | SYMB  |                      | SYMB  | NUMB |
 *                                 | Bksp | Del   |                      | Ent   |Space |
 *                                 |      |       |                      |       |      |
 *                                 `--------------'                      `--------------'
 */
[BASE] = LAYOUT_gergo(
    LT(NUMB, KC_EQUAL),   KC_Q,  KC_W,   KC_E,   KC_R, KC_T,                                              KC_Y,    KC_U, KC_I, KC_O,   KC_P,    KC_MINS,
    MT(MOD_LCTL, KC_TAB), KC_A,  KC_S,   KC_D,   KC_F, KC_G, KC_ESC,                            KC_ESC,   KC_H,    KC_J, KC_K, KC_L,   KC_SCLN, MT(MOD_RCTL, KC_QUOT),
    KC_LSFT,              KC_Z,  KC_X,   KC_C,   KC_V, KC_B, KC_LGUI, KC_BTN3,         KC_PGDN, KC_RGUI,  KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
    KC_LALT,              MO(SYMB),             LT(NUMB, KC_BSPC), LT(SYMB, KC_DEL),   LT(SYMB, KC_ENT), LT(NUMB, KC_SPC), MO(SYMB), KC_RALT
    ),
/* Keymap 1: Symbols layer
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        |  !   |  @   |  #   |  $   |  %   |                         |   ^  |  &   |  *   |  (   |  )   |  - _   |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |        |  |   |  (   |  )   |  ~   |  `   |      |           |      |   +  |  -   |  :   |  {   |  }   |  ' "   |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |        |  \   |  [   |  ]   |      |      |      |           |      |   &  |  =   |  ,   |  [   |  ]   |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                        .------.   .------.                                 .------.   .-----.
 *                        |      |   |      |                                 |      |   |     |
 *                        '------'   '------'                                 `------.   '-----'
 *                                        ,-------.                     ,-------.
 *                                        |       |                     | PgUp  |
 *                                 ,------|-------|                     |-------|------.
 *                                 |      |       |                     |       |      |
 *                                 | Bksp | Del   |                     | Enter |Space |
 *                                 |      |       |                     |       |      |
 *                                 `--------------'                     `--------------'
 */
[SYMB] = LAYOUT_gergo(
    KC_TRNS, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TRNS,
    KC_TRNS, KC_PIPE, KC_LPRN, KC_RPRN, KC_TILD, KC_GRV,  KC_TRNS,                          KC_TRNS, KC_PLUS, KC_MINS, KC_COLN, KC_LCBR, KC_RCBR, KC_QUOT,
    KC_TRNS, KC_BSLS, KC_TILD, KC_LBRC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_PGUP, KC_TRNS, KC_AMPR, KC_EQL,  KC_COMM, KC_LBRC, KC_RBRC, KC_TRNS,
                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
/* Keymap 2: Pad/Function layer
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        |   1  |  2   |  3   |  4   |  5   |                         |  6   |  7   |  8   |  9   |  0   |  _ -   |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |  F1    |  F2  | F3   | F4   | F5   | F6   | BTN1 |           | BTN1 | LEFT | DOWN |  UP  | RIGHT|VolDn | VolUp  |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |  F7    |  F8  | F9   | F10  | F11  | F12  | BTN2 |           | BTN2 | MLFT | MDWN | MUP  | MRGHT|Ply/Pa|  Skip  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                        .------.   .------.                                 .------.   .-----.
 *                        |      |   |      |                                 |      |   |     |
 *                        '------'   '------'                                 `------.   '-----'
 *                                        ,-------.                     ,-------.
 *                                        |       |                     | PgUp  |
 *                                 ,------|-------|                     |-------|------.
 *                                 |      |       |                     |       |      |
 *                                 |      |       |                     |       |      |
 *                                 |      |       |                     |       |      |
 *                                 `--------------'                     `--------------'
 */
[NUMB] = LAYOUT_gergo(
    KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_UNDS,
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_BTN1,                       KC_BTN1,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_VOLD, KC_VOLU,
    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_BTN2, KC_TRNS,     KC_PGUP, KC_BTN2,  KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_MPLY, KC_MNXT,
                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS
    ),
};

/* Keymap template
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        |      |      |      |      |      |                         |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                        .------.   .------.                                 .------.   .-----.
 *                        |      |   |      |                                 |      |   |     |
 *                        '------'   '------'                                 `------.   '-----'
 *                                        ,-------.       ,-------.
 *                                        |       |       |       |
 *                                 ,------|-------|       |-------|------.
 *                                 |      |       |       |       |      |
 *                                 |      |       |       |       |      |
 *                                 |      |       |       |       |      |
 *                                 `--------------'       `--------------'
[SYMB] = LAYOUT_gergo(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
 */
