/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "quantum.h"

#define BASE 0
#define NAV 1
#define NUM 2
#define SYM 3
#define GAME 4
#define MOUSE 5
#define QUERTY 6

#define VOL_UP KC_KB_VOLUME_UP
#define VOL_DN KC_KB_VOLUME_DOWN
#define BSPC_NAV LT(NAV, KC_BSPC)
#define NUM_SPC LT(NUM, KC_SPC)

#define HM_T LSFT_T(KC_T)
#define HM_S LCTL_T(KC_S)
#define HM_R LALT_T(KC_R)
#define HM_A LGUI_T(KC_A)

#define HM_N RSFT_T(KC_N)
#define HM_E RCTL_T(KC_E)
#define HM_I RALT_T(KC_I)
#define HM_O RGUI_T(KC_O)

#define HMQ_F LGUI_T(KC_F)
#define HMQ_D LCTL_T(KC_D)
#define HMQ_S LALT_T(KC_S)

#define HMQ_J RGUI_T(KC_J)
#define HMQ_K RCTL_T(KC_K)
#define HMQ_L RALT_T(KC_L)

#define CAG C(A(KC_LGUI))
#define HA(kc) LALT_T(kc)
#define HC(kc) LCTL_T(kc)
#define HS(kc) LSFT_T(kc)
#define HG(kc) LGUI_T(kc)

// enum custom_keycodes {
//     SCRL_TOG = KEYBALL_SAFE_RANGE,
// };

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [BASE] = LAYOUT_universal( // BASE
//╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮   ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮
      KC_TAB    ,    KC_Q     ,    KC_W     ,    KC_F     ,    KC_P     ,    KC_G     ,        KC_J     ,    KC_L     ,    KC_U     ,    KC_Y     ,   KC_QUOT   ,    QK_REP   ,
//├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
      KC_ESC    ,   HG(KC_A)  ,   HA(KC_R)  ,   HC(KC_S)  ,   HS(KC_T)  ,    KC_D     ,        KC_H     ,   HS(KC_N)  ,   HC(KC_E)  ,   HA(KC_I)  ,   HG(KC_O)  ,    KC_ENT   ,
//├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
      CW_TOGG   ,    KC_Z     ,    KC_X     ,    KC_C     ,    KC_V     ,    KC_B     ,        KC_K     ,    KC_M     ,   KC_COMM   ,    KC_DOT   ,   KC_SLSH   ,    KC_UNDS  ,
//╰─────────────┴─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┴─────────────┴─────────────╯
                    TO(GAME)  ,  DF(QUERTY) ,   OSL(SYM)  ,   NUM_SPC   ,     CAG     ,       KC_ENT    ,   BSPC_NAV  ,   XXXXXXX   ,   XXXXXXX   ,   TO(BASE)
//              ╰─────────────┴─────────────┴─────────────┴─────────────┴─────────────╯   ╰─────────────┴─────────────╯                           ╰─────────────╯
  ),
//   [BASE] = LAYOUT_universal( // BASE
// //╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮   ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮
//       KC_TAB    ,    KC_Q     ,    KC_W     ,    KC_E     ,    KC_R     ,    KC_T     ,        KC_Y     ,    KC_U     ,    KC_I     ,    KC_O     ,    KC_P     ,    QK_REP   ,
// //├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
//       KC_ESC    ,    KC_A     ,    HMQ_S    ,    HMQ_D    ,    HMQ_F    ,    KC_G     ,        KC_H     ,    HMQ_J    ,    HMQ_K    ,    HMQ_L    ,   KC_SCLN   ,    KC_ENT   ,
// //├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
//       CW_TOGG   ,    KC_Z     ,    KC_X     ,    KC_C     ,    KC_V     ,    KC_B     ,        KC_N     ,    KC_M     ,   KC_COMM   ,    KC_DOT   ,   KC_SLSH   ,    KC_UNDS  ,
// //╰─────────────┴─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┴─────────────┴─────────────╯
//                     TO(GAME)  ,   XXXXXXX   ,   OSL(SYM)  ,   NUM_SPC   ,OSM(MOD_LSFT),       KC_BSPC   ,   LCAG_NAV  ,   XXXXXXX   ,   XXXXXXX   ,   TO(BASE)
// //              ╰─────────────┴─────────────┴─────────────┴─────────────┴─────────────╯   ╰─────────────┴─────────────╯                           ╰─────────────╯
//   ),

  [NAV] = LAYOUT_universal( // NAV
//╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮   ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮
      RGB_RMOD  ,   RGB_MOD   ,   KC_BRMD   ,   KC_BRMU   ,   KC_VOLD   ,   KC_VOLU   ,       XXXXXXX   ,   KC_PGDN   ,   KC_PGUP   ,   XXXXXXX   ,   XXXXXXX   ,   QK_BOOT   ,
//├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
      RGB_HUD   ,   RGB_HUI   ,   KC_LALT   ,   KC_LCTL   ,   KC_LGUI   ,   XXXXXXX   ,       KC_LEFT   ,   KC_DOWN   ,    KC_UP    ,   KC_RGHT   ,   XXXXXXX   ,   KC_ENT    ,
//├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
      RGB_TOG   ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,       XXXXXXX   ,   KC_BTN4   ,   KC_BTN5   ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,
//╰─────────────┴─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┴─────────────┴─────────────╯
                    XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,   KC_LSFT   ,       KC_BSPC   ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX
//              ╰─────────────┴─────────────┴─────────────┴─────────────┴─────────────╯   ╰─────────────┴─────────────╯                           ╰─────────────╯
  ),

  [NUM] = LAYOUT_universal( // NUM
//╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮   ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮
      XXXXXXX   ,    KC_F6    ,    KC_F4    ,     KC_F2   ,    KC_F10   ,   XXXXXXX   ,       XXXXXXX   ,    KC_F1    ,    KC_F3    ,     KC_F5   ,    KC_F7    ,   XXXXXXX   ,
//├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
      KC_ESC    ,    KC_6     ,    KC_4     ,     KC_2    ,    KC_0     ,    KC_F12   ,        KC_F11   ,     KC_1    ,     KC_3    ,     KC_5    ,     KC_7    ,   KC_ENT    ,
//├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
      XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,    KC_8     ,    KC_F8    ,        KC_F9    ,     KC_9    ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,
//╰─────────────┴─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┴─────────────┴─────────────╯
                    XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,       KC_BSPC   ,   KC_SPC    ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX
//              ╰─────────────┴─────────────┴─────────────┴─────────────┴─────────────╯   ╰─────────────┴─────────────╯                           ╰─────────────╯
  ),

  [SYM] = LAYOUT_universal( // SYM
//╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮   ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮
      XXXXXXX   ,   XXXXXXX   ,   KC_TILD   ,   KC_ASTR   ,   KC_CIRC   ,   XXXXXXX   ,       KC_HASH   ,   KC_DLR    ,    KC_AT    ,   XXXXXXX   ,   KC_GRV    ,   XXXXXXX   ,
//├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
      XXXXXXX   ,   KC_EXLM   ,   KC_MINS   ,   KC_PLUS   ,   KC_EQL    ,   KC_PERC   ,       KC_SCLN   ,   KC_LPRN   ,   KC_RPRN   ,   KC_LBRC   ,   KC_UNDS   ,   XXXXXXX   ,
//├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
      XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,   KC_PIPE   ,   KC_AMPR   ,   XXXXXXX   ,       KC_COLN   ,   KC_LCBR   ,   KC_RCBR   ,   KC_RBRC   ,   KC_BSLS   ,   XXXXXXX   ,
//╰─────────────┴─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┴─────────────┴─────────────╯
                    XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,       KC_BSPC   ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX
//              ╰─────────────┴─────────────┴─────────────┴─────────────┴─────────────╯   ╰─────────────┴─────────────╯                           ╰─────────────╯
  ),

  [GAME] = LAYOUT_universal(
//╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮   ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮
      KC_ESC    ,    KC_Q     ,    KC_R     ,    KC_W     ,    KC_E     ,    KC_G     ,        KC_J     ,    KC_L     ,    KC_U     ,    KC_Y     ,   KC_SCLN   ,    KC_DEL   ,
//├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
      CW_TOGG   ,    KC_T     ,    KC_A     ,    KC_S     ,    KC_D     ,    KC_F     ,     RALT_T(KC_H), RGUI_T(KC_N), RCTL_T(KC_E),    KC_I     ,     KC_O    ,    KC_QUOT  ,
//├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
      KC_LCTL   ,    KC_Z     ,    KC_X     ,    KC_C     ,    KC_V     ,    KC_B     ,        KC_K     ,    KC_M     ,   KC_COMM   ,    KC_DOT   ,   KC_SLSH   ,    TO(NUM)  ,
//╰─────────────┴─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┴─────────────┴─────────────╯
                    KC_LALT   ,   KC_LGUI   ,   KC_LCTL   ,   KC_SPC    ,   KC_LSFT   ,       KC_BSPC   ,LT(BASE,KC_ENT), XXXXXXX   ,   XXXXXXX   ,   TO(BASE)
//              ╰─────────────┴─────────────┴─────────────┴─────────────┴─────────────╯   ╰─────────────┴─────────────╯                           ╰─────────────╯
  ),
  [MOUSE] = LAYOUT_universal(
//╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮   ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮
      XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,       XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   , 
//├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
      KC_ESC    ,   XXXXXXX   ,   KC_LALT   ,   KC_LCTL   ,   KC_LGUI   ,   XXXXXXX   ,       KC_BTN4   ,   KC_BTN1   ,   KC_BTN2   ,   KC_BTN5   ,   XXXXXXX   ,   KC_ENT    ,
//├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
      XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,       XXXXXXX   ,   SSNP_HOR  ,   SCRL_MO   ,   SSNP_VRT  ,   XXXXXXX   ,   XXXXXXX   ,
//╰─────────────┴─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┴─────────────┴─────────────╯
                    XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,   KC_LSFT   ,       XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX
//              ╰─────────────┴─────────────┴─────────────┴─────────────┴─────────────╯   ╰─────────────┴─────────────╯                           ╰─────────────╯
  ),

};
// clang-format on
// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//
//   switch (keycode) {
//   case LCAG_NAV:
//     if (record->tap.count > 0) {
//       if (record->event.pressed) {
//         set_oneshot_mods(MOD_LCTL | MOD_LALT | MOD_LGUI);
//       }
//       return false;
//     }
//     break;
//
//   }
//
//   return true;
// }

layer_state_t layer_state_set_user(layer_state_t state) {
  keyball_set_scroll_mode(get_highest_layer(state) == 3);
  return state;
}

#ifdef OLED_ENABLE

#include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
  keyball_oled_render_keyinfo();
  keyball_oled_render_ballinfo();
  keyball_oled_render_layerinfo();
}
#endif
