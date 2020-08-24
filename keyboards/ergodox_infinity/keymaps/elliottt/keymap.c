#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0
#define SYMB 1
#define NUMB 2
#define FUN  3

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = LAYOUT_ergodox(  // layer 0 : default
/*
 * left hand
 *    +-------+-----+-----+-----+-----+-----+-----+
 *    |       |  0  |  2  |  3  |  4  |  5  |     |
 *    +-------+-----+-----+-----+-----+-----+-----+
 *    | =/LALT|  Q  |  W  |  E  |  R  |  T  | ESC |
 *    +-------+-----+-----+-----+-----+-----+     |
 *    |TAB/CTL|  A  |  S  |  D  |  F  |  G  +-----+
 *    +-------+-----+-----+-----+-----+-----+ LGUI|
 *    | LSHIFT|  Z  |  X  |  C  |  V  |  B  |     |
 *    +-+-----+-----+-----+-----+-----+-----+-----+
 *      |     |     |     |     | SYMB|
 *      +-----+-----+-----+-----+-----+   +-----+-----+
 *                                        |     |     |
 *                                  +-----+-----+-----+
 *                                  |BKSPC|     |     |
 *                                  |  /  | DEL +-----+
 *                                  | NUMB|     |     |
 *                                  +-----+-----+-----+
 */
        KC_TRNS,              KC_1,    KC_2,    KC_3,               KC_4,               KC_5, KC_TRNS,
        MT(MOD_LALT, KC_EQL), KC_Q,    KC_W,    KC_E,               KC_R,               KC_T, KC_ESC,
        MT(MOD_LCTL, KC_TAB), KC_A,    KC_S,    MT(MOD_LGUI, KC_D), MT(MOD_LCTL, KC_F), KC_G,
        KC_LSFT,              KC_Z,    KC_X,    KC_C,               KC_V,               KC_B, KC_LGUI,
        KC_TRNS,              KC_TRNS, KC_TRNS, KC_TRNS,            MO(SYMB),
                                                                    KC_TRNS, KC_TRNS,
                                                                             KC_TRNS,
                                                 LT(NUMB, KC_BSPC), KC_DEL,  KC_TRNS,
/* right hand
 *        +-----+-----+-----+-----+-----+-----+-------+
 *        |     |  6  |  7  |  8  |  9  |  0  |       |
 *        +-----+-----+-----+-----+-----+-----+-------+
 *        | ESC |  Y  |  U  |  I  |  O  |  P  |-/RALT |
 *        |     +-----+-----+-----+-----+-----+-------+
 *        +-----+  H  |  J  |  K  |  L  |  ;  |'/RCTL |
 *        | RGUI+-----+-----+-----+-----+-----+-------+
 *        |     |  N  |  M  |  ,  |  .  |  /  | RSHIFT|
 *        +-----+-----+-----+-----+-----+-----+-----+-+
 *                    | SYMB| FUN |     |     |     |
 *    +-----+-----+   +-----+-----+-----+-----+-----+
 *    |     |     |
 *    +-----+-----+-----+
 *    |     |     | SPC |
 *    +-----+ ENT |  /  |
 *    |     |     | NUMB|
 *    +-----+-----+-----+
 */
             KC_TRNS, KC_6,   KC_7,               KC_8,               KC_9,    KC_0,     KC_TRNS,
             KC_ESC,  KC_Y,   KC_U,               KC_I,               KC_O,    KC_P,     MT(MOD_LALT, KC_MINS),
                      KC_H,   MT(MOD_RCTL, KC_J), MT(MOD_RGUI, KC_K), KC_L,    KC_SCLN,  MT(MOD_RCTL, KC_QUOT),
             KC_RGUI, KC_N,   KC_M,               KC_COMM,            KC_DOT,  KC_SLSH,  KC_RSFT,
                              MO(SYMB),           MO(FUN),            KC_TRNS, KC_TRNS,  KC_TRNS,
             KC_TRNS, KC_TRNS,
             KC_TRNS,
             KC_TRNS, KC_ENT, LT(NUMB, KC_SPC)
    ),

[SYMB] = LAYOUT_ergodox( // layer 1 : symbols
/* left hand
 *    +-------+-----+-----+-----+-----+-----+-----+
 *    |       | f1  | f2  | f3  | f4  | f5  | f11 |
 *    +-------+-----+-----+-----+-----+-----+-----+
 *    |       |  !  |  @  |  #  |  $  |  %  |     |
 *    +-------+-----+-----+-----+-----+-----+     |
 *    |       |  |  |  (  |  )  |  ~  |  `  +-----+
 *    +-------+-----+-----+-----+-----+-----+     |
 *    |       |  \  |  <  |  >  |     |     |     |
 *    +-+-----+-----+-----+-----+-----+-----+-----+
 *      |     |     |     |     |     |
 *      +-----+-----+-----+-----+-----+   +-----+-----+
 *                                        |     |     |
 *                                  +-----+-----+-----+
 *                                  |     |     |     |
 *                                  | ESC |     +-----+
 *                                  |     |     |     |
 *                                  +-----+-----+-----+
 */
       KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,
       KC_TRNS, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_TRNS,
       KC_TRNS, KC_PIPE, KC_LPRN, KC_RPRN, KC_TILD, KC_GRV,
       KC_TRNS, KC_BSLS, KC_LT,   KC_GT,   KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                      KC_TRNS, KC_TRNS,
                                                               KC_TRNS,
                                              KC_ESC, KC_TRNS, KC_TRNS,
/* right hand
 *        +-----+-----+-----+-----+-----+-----+-------+
 *        | f12 | f6  | f7  | f8  | f9  | f10 |       |
 *        +-----+-----+-----+-----+-----+-----+-------+
 *        |     |  ^  |  &  |  *  |  (  |  )  |       |
 *        |     +-----+-----+-----+-----+-----+-------+
 *        +-----+  +  |  :  |  {  |  }  |     |       |
 *        |     +-----+-----+-----+-----+-----+-------+
 *        |     |     |  =  |  [  |  ]  |     |       |
 *        +-----+-----+-----+-----+-----+-----+-----+-+
 *                    |     |     |     |     |     |
 *    +-----+-----+   +-----+-----+-----+-----+-----+
 *    |     |     |
 *    +-----+-----+-----+
 *    |     |     |     |
 *    +-----+     | ESC |
 *    |     |     |     |
 *    +-----+-----+-----+
 */
       KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_TRNS,
       KC_TRNS, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TRNS,
                KC_PLUS, KC_COLN, KC_LCBR, KC_RCBR, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_EQL,  KC_LBRC, KC_RBRC, KC_TRNS, KC_TRNS,
                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_ESC
),
[NUMB] = LAYOUT_ergodox( // numbers
/* Left hand
 *    +-------+-----+-----+-----+-----+-----+-----+
 *    |       |     |     |     |     |     |     |
 *    +-------+-----+-----+-----+-----+-----+-----+
 *    |       |  1  |  2  |  3  |  4  |  5  |     |
 *    +-------+-----+-----+-----+-----+-----+     |
 *    |       |     |     | BTN2| BTN1|     +-----+
 *    +-------+-----+-----+-----+-----+-----+     |
 *    |       |     |     |     | BTN3|     |     |
 *    +-+-----+-----+-----+-----+-----+-----+-----+
 *      |FLASH|     |     |     |     |
 *      +-----+-----+-----+-----+-----+   +-----+-----+
 *                                        |     |     |
 *                                  +-----+-----+-----+
 *                                  |     |     |     |
 *                                  | ESC |     +-----+
 *                                  |     |     |     |
 *                                  +-----+-----+-----+
 */
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN2, KC_BTN1, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN3, KC_TRNS, KC_TRNS,
       RESET,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                   KC_ESC, KC_TRNS, KC_TRNS,
/* right hand
 *        +-----+-----+-----+-----+-----+-----+-------+
 *        |     |     |     |     |     |     |       |
 *        +-----+-----+-----+-----+-----+-----+-------+
 *        |     |  6  |  7  |  8  |  9  |  0  |       |
 *        |     +-----+-----+-----+-----+-----+-------+
 *        +-----+ LEFT| UP  | DOWN|RIGHT|     |       |
 *        |     +-----+-----+-----+-----+-----+-------+
 *        |     | MLFT| MUP | MDWN| MRHT|     |       |
 *        +-----+-----+-----+-----+-----+-----+-----+-+
 *                    |     |     |     |     |FLASH|
 *    +-----+-----+   +-----+-----+-----+-----+-----+
 *    |     |     |
 *    +-----+-----+-----+
 *    |     |     |     |
 *    +-----+     | ESC |
 *    |     |     |     |
 *    +-----+-----+-----+
 */
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_6,    KC_7,    KC_8,    KC_9,     KC_0,    KC_TRNS,
                 KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,  KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, RESET,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_ESC
),
[FUN] = LAYOUT_ergodox( // function keys
/* Left hand
 *    +-------+-----+-----+-----+-----+-----+-----+
 *    |       |     |     |     |     |     |     |
 *    +-------+-----+-----+-----+-----+-----+-----+
 *    |       |  F1 |  F2 |  F3 |  F4 |  F5 |     |
 *    +-------+-----+-----+-----+-----+-----+     |
 *    |       |  F6 |  F7 |  F8 |  F9 | F10 +-----+
 *    +-------+-----+-----+-----+-----+-----+     |
 *    |       |     |     | F11 | F12 |     |     |
 *    +-+-----+-----+-----+-----+-----+-----+-----+
 *      |     |     |     |     |     |
 *      +-----+-----+-----+-----+-----+   +-----+-----+
 *                                        |     |     |
 *                                  +-----+-----+-----+
 *                                  |     |     |     |
 *                                  |     |     +-----+
 *                                  |     |     |     |
 *                                  +-----+-----+-----+
 */
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,
       KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_F11,  KC_F12,  KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
/* right hand
 *        +-----+-----+-----+-----+-----+-----+-------+
 *        |     |     |     |     |     |     |       |
 *        +-----+-----+-----+-----+-----+-----+-------+
 *        |     |     |     |     |     |     |       |
 *        |     +-----+-----+-----+-----+-----+-------+
 *        +-----+     |     |     |     |     |       |
 *        |     +-----+-----+-----+-----+-----+-------+
 *        |     |     |     |     |     |     |       |
 *        +-----+-----+-----+-----+-----+-----+-----+-+
 *                    |     |     |     |     |     |
 *    +-----+-----+   +-----+-----+-----+-----+-----+
 *    |     |     |
 *    +-----+-----+-----+
 *    |     |     |     |
 *    +-----+     |     |
 *    |     |     |     |
 *    +-----+-----+-----+
 */
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
        case 1:
        if (record->event.pressed) { // For resetting EEPROM
          eeconfig_init();
        }
        break;
      }
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
