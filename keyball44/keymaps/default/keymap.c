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

#define VOL_UP KC_KB_VOLUME_UP
#define VOL_DN KC_KB_VOLUME_DOWN
#define SF_BS MT(MOD_RSFT, KC_BSPC)
#define CAG_BIT MOD_BIT(KC_LCTL) | MOD_BIT(KC_LALT) | MOD_BIT(KC_LGUI)
#define LCAG_NAV LT(NAV, KC_NO)
#define GUI_BSPC MT(MOD_RGUI, KC_BSPC)
#define NUM_SPC LT(NUM,KC_SPC)

// enum custom_keycodes {
//     SCRL_TOG = KEYBALL_SAFE_RANGE,
// };

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [BASE] = LAYOUT_universal( // BASE
//╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮   ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮
      KC_TAB    ,    KC_Q     ,    KC_W     ,    KC_F     ,    KC_P     ,    KC_G     ,        KC_J     ,    KC_L     ,    KC_U     ,    KC_Y     ,   KC_QUOT   ,    QK_REP   ,
//├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
      KC_ESC    ,    KC_A     ,    KC_R     ,    KC_S     ,    KC_T     ,    KC_D     ,        KC_H     ,    KC_N     ,    KC_E     ,    KC_I     ,     KC_O    ,    KC_ENT   ,
//├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
      CW_TOGG   ,    KC_Z     ,    KC_X     ,    KC_C     ,    KC_V     ,    KC_B     ,        KC_K     ,    KC_M     ,   KC_COMM   ,    KC_DOT   ,   KC_SLSH   ,    KC_UNDS  ,
//╰─────────────┴─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┴─────────────┴─────────────╯
                    TO(GAME)  ,   XXXXXXX   ,OSM(MOD_LALT),   NUM_SPC   ,OSM(MOD_LSFT),      GUI_BSPC   ,   LCAG_NAV  ,   XXXXXXX   ,   XXXXXXX   ,   TO(BASE)
//              ╰─────────────┴─────────────┴─────────────┴─────────────┴─────────────╯   ╰─────────────┴─────────────╯                           ╰─────────────╯
  ),

  [NAV] = LAYOUT_universal( // NAV
//╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮   ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮
      RGB_RMOD  ,   RGB_MOD   ,    KC_F7    ,    KC_F8    ,    KC_F9    ,   KC_F10    ,       KC_BRMD   ,   KC_BRMU   ,   KC_VOLU   ,   KC_VOLD   ,   XXXXXXX   ,   QK_BOOT   ,
//├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
      RGB_HUD   ,   RGB_HUI   ,    KC_F4    ,    KC_F5    ,    KC_F6    ,   KC_F11    ,       KC_LEFT   ,   KC_DOWN   ,    KC_UP    ,   KC_RGHT   ,   XXXXXXX   ,   XXXXXXX   ,
//├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
      RGB_TOG   ,   XXXXXXX   ,    KC_F1    ,    KC_F2    ,    KC_F3    ,   KC_F12    ,       XXXXXXX   ,   KC_BTN4   ,   KC_BTN5   ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,
//╰─────────────┴─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┴─────────────┴─────────────╯
                    XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,       KC_BSPC   ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX
//              ╰─────────────┴─────────────┴─────────────┴─────────────┴─────────────╯   ╰─────────────┴─────────────╯                           ╰─────────────╯
  ),

  [NUM] = LAYOUT_universal( // NUM
//╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮   ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮
      XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,       XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,
//├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
      XXXXXXX   ,    KC_6     ,    KC_4     ,     KC_2    ,    KC_0     ,   XXXXXXX   ,       XXXXXXX   ,     KC_1    ,     KC_3    ,     KC_5    ,     KC_7    ,   XXXXXXX   ,
//├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
      XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,    KC_8     ,   XXXXXXX   ,       XXXXXXX   ,     KC_9    ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,
//╰─────────────┴─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┴─────────────┴─────────────╯
                    XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,       KC_BSPC   ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX
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
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case LCAG_NAV:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    register_mods(CAG_BIT);
                }
                return false;
            }
            break;
        case OSM(MOD_LSFT):
            if (!record->tap.count) {
                if (record->event.pressed) {
                    register_mods(MOD_BIT(KC_LCTL));
                } else {
                    unregister_mods(MOD_BIT(KC_LCTL));
                }
                return false;
            }
        case OSM(MOD_LALT):
            if (!record->tap.count) {
                if (record->event.pressed) {
                    layer_on(SYM);
                } else {
                    layer_off(SYM);
                }
                return false;
            }
    }

    return true;
}

void post_process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (keycode != LCAG_NAV &&
        keycode != OSM(MOD_LSFT) &&
        keycode != NUM_SPC &&
        (get_mods() & (CAG_BIT)) == (CAG_BIT)) {
        unregister_mods(CAG_BIT);
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 3
    keyball_set_scroll_mode(get_highest_layer(state) == 3);
    return state;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif
