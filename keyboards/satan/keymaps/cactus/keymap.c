#include "satan.h"


// Used for SHIFT_ESC
#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _base 0
#define _space 1
#define _menu 2

#define _______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   /*
   *  ANSI Base
   * ,-----------------------------------------------------------------------------.
   * |Esc   |  1|   2|   3|   4|   5|   6|   7|   8|   9|   0|   -|   = |    `|   \|
   * |-----------------------------------------------------------------------------|
   * |Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I|   O|  P|  [|  ]|  Bksp|
   * |-----------------------------------------------------------------------------|
   * |Caps         |    A|    S|    D|    F|   G|  H|  J|  K|  L|  ;|  '|   Enter  |
   * |-----------------------------------------------------------------------------|
   * |Shift      |    Z|     X|    C|     V|  B|  N|  M|  ,|  .|  /|     Shift |   |
   * |-----------------------------------------------------------------------------|
   * |Ctrl|Gui |Alt| Space(tapped), Fn(held) |Alt |Gui |Menu(tapped, Fn2(held)|Ctrl|
   * `-----------------------------------------------------------------------------'
   */
[ _base ] = KEYMAP_HHKB(
  KC_ESC,  KC_1,   KC_2,  KC_3,    KC_4,  KC_5,   KC_6,    KC_7,   KC_8,  KC_9,    KC_0,    KC_MINS,  KC_EQL,   KC_GRV, KC_BSLS , \
  KC_TAB,  KC_Q,   KC_W,  KC_E,    KC_R,  KC_T,   KC_Y,    KC_U,   KC_I,  KC_O,    KC_P,    KC_LBRC,  KC_RBRC,  KC_BSPC, \
  KC_CAPS, KC_A,   KC_S,  KC_D,    KC_F,  KC_G,   KC_H,    KC_J,   KC_K,  KC_L,    KC_SCLN, KC_QUOT,            KC_ENT,  \
  KC_LSFT,         KC_Z,  KC_X,    KC_C,  KC_V,   KC_B,    KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH,            KC_RSFT, KC_NO  , \
  KC_LCTL, KC_LGUI,KC_LALT,        LT(_space,KC_SPACE),                      KC_RALT, KC_RGUI, LT(_menu,KC_APP),    KC_RCTL),
   /*
   * arrow cluster under right hand on home row
   * ,------------------------------------------------------------.
   * |`~ | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|DEL|INS |
   * |------------------------------------------------------------|
   * |Tab  | B+| V+|   |   |   |   |Hme|Up |End| PU|   |   | DEL  |
   * |------------------------------------------------------------|
   * |Caps  | B-| V-|   |   |   | PU|Lef|Dn |Rgt| PD|Psc|  ENT    |
   * |------------------------------------------------------------|
   * |Lshift  |QLK|Mut|   |   |spc| PD| M>| <<| >>|   | Rshift|   |
   * |------------------------------------------------------------|
   * |Lctr|Win |Lalt|       ---------        |Ralt|Win |    |     |
   * `------------------------------------------------------------'
   */
[ _space ] = KEYMAP_HHKB(
  KC_GRV,     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, KC_DELETE,   KC_INSERT,\
  KC_TRNS,  KC_TRNS, KC_VOLU, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_UP  , KC_END , KC_PGUP, KC_TRNS, KC_TRNS, KC_DEL,  \
  KC_TRNS,  KC_TRNS, KC_VOLD, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_PSCR, KC_TRNS,  \
  KC_TRNS,  KC_LOCK, KC_MUTE, KC_TRNS, KC_LOCK, KC_SPACE,KC_PGDN, KC_MPLY, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS, KC_TRNS, \
  KC_TRNS,  KC_TRNS, KC_TRNS,                   KC_TRNS,                           KC_TRNS, KC_TRNS, KC_MENU, KC_TRNS), 
  /* Backlight and mouse
   * ,-----------------------------------------------------------.
   * |   |   |   |   |   |   |   |   |   |   |   |   |   |  RESET|
   * |-----------------------------------------------------------|
   * |     |ms^|LMB|m^ |RMB|   |   |   |   |   |   |BL-|BL+|BL   |
   * |-----------------------------------------------------------|
   * |      |MMB|m< |mv |m> |   |   |       |   |   |   |        |
   * |-----------------------------------------------------------|
   * | |mv / Ron|RGB step|Hue+|Hue- |Sat+|Sat-|Val+| Val-| | |   |
   * |-----------------------------------------------------------|
   * |    |    |    |                        |    |    |    |    |
   * `-----------------------------------------------------------'
   */
[_menu] = KEYMAP_ANSI(
  #ifdef RGBLIGHT_ENABLE
  _______, _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,RESET,  \
  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______, BL_DEC,BL_INC, BL_TOGG, \
  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,        _______, \
  _______,RGB_TOG,RGB_MOD,RGB_HUI,RGB_HUD,RGB_SAI,RGB_SAD,RGB_VAI,RGB_VAD,_______,_______,_______, \
  _______,_______,_______,                 _______,                       _______,_______,_______, _______),
  #else
  _______, _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,RESET,  \
  _______,KC_WH_U,KC_BTN1,KC_MS_U,KC_BTN3,_______,_______,_______,_______,_______,_______, BL_DEC, BL_INC,BL_TOGG, \
  _______,KC_BTN2,KC_MS_L,KC_MS_D,KC_MS_R,_______,_______,_______,_______,_______,_______,_______,_______,  \
  _______,KC_WH_D,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______, \
  _______,_______,_______,                _______,                        _______,_______,_______,_______),
  #endif
};

enum function_id {
    SHIFT_ESC,
};

const uint16_t PROGMEM fn_actions[] = {
  [0]  = ACTION_FUNCTION(SHIFT_ESC),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  static uint8_t shift_esc_shift_mask;
  switch (id) {
    case SHIFT_ESC:
      shift_esc_shift_mask = get_mods()&MODS_CTRL_MASK;
      if (record->event.pressed) {
        if (shift_esc_shift_mask) {
          add_key(KC_GRV);
          send_keyboard_report();
        } else {
          add_key(KC_ESC);
          send_keyboard_report();
        }
      } else {
        if (shift_esc_shift_mask) {
          del_key(KC_GRV);
          send_keyboard_report();
        } else {
          del_key(KC_ESC);
          send_keyboard_report();
        }
      }
      break;
  }
}
