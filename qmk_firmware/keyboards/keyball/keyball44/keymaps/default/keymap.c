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

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default
  [0] = LAYOUT_universal(
    KC_NO   , KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                                        KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     , KC_BSPC   ,
    KC_NO   , KC_A     , KC_S     , LT(1, KC_D)     , LT(2, KC_F)     , KC_G     ,                                        KC_H     , KC_J     , KC_K     , KC_L     , KC_ESC  , KC_ENT  ,
    KC_NO   , KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     ,                                        KC_N     , KC_M     , KC_NO  , KC_NO   , KC_NO  , KC_TAB  ,
              KC_NO,KC_NO,KC_LSFT     ,KC_LCTL,KC_LALT,                  OSL(1),KC_SPC, KC_NO,     KC_NO  , KC_NO
  ),

  [1] = LAYOUT_universal(
    _______ ,  KC_1    , KC_2    , KC_3     , KC_4    , KC_5    ,                                         KC_6    , KC_7    , KC_8    , KC_9    , KC_0   , _______   ,
    _______ ,  KC_NO   , KC_UP   , KC_NO    , KC_NO  , KC_MINUS ,                                         KC_CIRC  , KC_AT  , KC_LBRC    , KC_RBRC  , KC_BSLS , _______   ,
    _______ ,  KC_LEFT , KC_DOWN , KC_RIGHT , KC_NO , KC_SCLN   ,                                         KC_COLON  , KC_COMMA  , KC_DOT  , KC_SLSH  , KC_MINUS , _______  ,
                  _______  , _______ , _______  ,         _______  , _______  ,                   _______  , _______  , _______       , _______  , _______
  ),

  [2] = LAYOUT_universal(
    _______ , KC_NO         , KC_NO               , KC_NO                , KC_NO , KC_NO ,                                         KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , _______  ,
    _______ , LGUI(KC_UP)   , LGUI(LCTL(KC_LEFT)) , LGUI(LCTL(KC_RIGHT)) , KC_NO , KC_NO ,                                         KC_MS_BTN1  , KC_MS_BTN2  , KC_LNG1, KC_LNG2  , KC_NO  , _______  ,
    _______ , LGUI(KC_DOWN) , KC_NO               , KC_NO                , KC_NO , KC_NO ,                                        KC_NO,KC_NO, KC_NO   ,KC_NO,KC_NO,_______,
                  _______     , _______  , _______  ,         _______  , _______  ,                   _______   , _______  , _______       , _______  , _______
  ),

  [3] = LAYOUT_universal(
    _______  , KC_NO   , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,                                        KC_NO  , KC_NO  , KC_NO  , KC_NO , KC_NO , _______  ,
    _______  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO ,                                        KC_NO  , KC_NO  , KC_NO  , KC_NO , KC_NO  , _______  ,
    _______ , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO ,                                        KC_NO  , KC_NO , KC_NO , KC_NO  , KC_NO  , _______ ,
                  _______  , _______  , _______  ,        _______  , _______  ,                   _______  , _______  , _______       , _______  , _______
  ),
};
// clang-format on

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
