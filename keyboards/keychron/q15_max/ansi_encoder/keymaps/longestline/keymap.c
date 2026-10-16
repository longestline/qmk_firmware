/* Copyright 2024 ~ 2026 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "keychron_common.h"

enum layers {
    MAC_BASE,
    WIN_BASE,
    MAC_FN1,
    WIN_FN1,
    FN2,
};

#define FN1_MAC MO(MAC_FN1)
#define FN1_WIN MO(WIN_FN1)

// Layout read from the keyboard's Launcher settings, so reflashing keeps it.
// MAC_BASE is Dvorak with home row mods. The key left of the left space bar
// holds FN2, whose home row has { [ ( ` on the left and ~ ) ] } on the right.
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_66(
        KC_MUTE,      KC_1,         KC_2,         KC_3,         KC_4,         KC_5,         KC_6,         KC_7,         KC_8,         KC_9,         KC_0,         KC_MINS,      KC_BSPC,      MS_BTN1,
        KC_TAB,       KC_QUOT,      KC_COMM,      KC_DOT,       KC_P,         KC_Y,         KC_F,         KC_G,         KC_C,         KC_R,         KC_L,         KC_SLSH,      KC_EQL,       KC_BSLS,
        KC_ESC,       LCTL_T(KC_A), LOPT_T(KC_O), LCMD_T(KC_E), LSFT_T(KC_U), KC_I,         KC_D,         RSFT_T(KC_H), RCMD_T(KC_T), ROPT_T(KC_N), RCMD_T(KC_S), KC_MINS,      KC_ENT,
        KC_LSFT,      KC_SCLN,      KC_Q,         KC_J,         KC_K,         KC_X,         KC_B,         KC_M,         KC_W,         KC_V,         KC_Z,         KC_RSFT,      KC_UP,        KC_DEL,
        KC_LCTL,      KC_LOPTN,     KC_LCMMD,     MO(FN2),      KC_SPC,       KC_SPC,       FN1_MAC,      MO(FN2),      KC_LEFT,      KC_DOWN,      KC_RGHT),

    [WIN_BASE] = LAYOUT_ansi_66(
        KC_MUTE,      KC_1,         KC_2,         KC_3,         KC_4,         KC_5,         KC_6,         KC_7,         KC_8,         KC_9,         KC_0,         KC_MINS,      KC_BSPC,      KC_MUTE,
        KC_ESC,       KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,         KC_Y,         KC_U,         KC_I,         KC_O,         KC_P,         KC_LBRC,      KC_RBRC,      KC_BSLS,
        KC_CAPS,      KC_A,         KC_S,         KC_D,         KC_F,         KC_G,         KC_H,         KC_J,         KC_K,         KC_L,         KC_SCLN,      KC_QUOT,      KC_ENT,
        KC_LSFT,      KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,         KC_N,         KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,      KC_RSFT,      KC_UP,        KC_DEL,
        KC_LCTL,      KC_LGUI,      KC_LALT,      _______,      KC_SPC,       KC_SPC,       FN1_WIN,      MO(FN2),      KC_LEFT,      KC_DOWN,      KC_RGHT),

    [MAC_FN1] = LAYOUT_ansi_66(
        UG_TOGG,      KC_BRID,      KC_BRIU,      KC_MCTRL,     KC_LNPAD,     UG_VALD,      UG_VALU,      KC_MPRV,      KC_MPLY,      KC_MNXT,      _______,      _______,      KC_EQL,       UG_TOGG,
        KC_GRV,       BT_HST1,      BT_HST2,      BT_HST3,      P2P4G,        _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,
        UG_TOGG,      UG_NEXT,      UG_VALU,      UG_HUEU,      UG_SATU,      UG_SPDU,      _______,      _______,      _______,      _______,      _______,      _______,      _______,
        _______,      UG_PREV,      UG_VALD,      UG_HUED,      UG_SATD,      UG_SPDD,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,
        _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______),

    [WIN_FN1] = LAYOUT_ansi_66(
        UG_TOGG,      KC_BRID,      KC_BRIU,      KC_TASK,      KC_FILE,      UG_VALD,      UG_VALU,      KC_MPRV,      KC_MPLY,      KC_MNXT,      _______,      _______,      KC_EQL,       UG_TOGG,
        KC_GRV,       BT_HST1,      BT_HST2,      BT_HST3,      P2P4G,        _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,
        UG_TOGG,      UG_NEXT,      UG_VALU,      UG_HUEU,      UG_SATU,      UG_SPDU,      _______,      _______,      _______,      _______,      _______,      _______,      _______,
        _______,      UG_PREV,      UG_VALD,      UG_HUED,      UG_SATD,      UG_SPDD,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,
        _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______),

    [FN2] = LAYOUT_ansi_66(
        _______,      KC_F1,        KC_F2,        KC_F3,        KC_F4,        KC_F5,        KC_F6,        KC_F7,        KC_F8,        KC_F9,        KC_F10,       KC_F11,       KC_F12,       _______,
        KC_TILD,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,
        _______,      KC_LCBR,      KC_LBRC,      KC_LPRN,      KC_GRV,       _______,      _______,      KC_TILD,      KC_RPRN,      KC_RBRC,      KC_RCBR,      _______,      _______,
        _______,      _______,      _______,      _______,      _______,      BAT_LVL,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,
        _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______)
};

// clang-format on
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][2][2] = {
    [MAC_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(MS_WHLD, MS_WHLU)},
    [WIN_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [MAC_FN1]  = {ENCODER_CCW_CW(UG_VALD, UG_VALU), ENCODER_CCW_CW(UG_VALD, UG_VALU)},
    [WIN_FN1]  = {ENCODER_CCW_CW(UG_VALD, UG_VALU), ENCODER_CCW_CW(UG_VALD, UG_VALU)},
    [FN2]      = {ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)},
};

#endif // ENCODER_MAP_ENABLE

enum combos {
    GC_BSPC,
    OCOMM_AT,
    CR_DEL,
};

// Combo keys must match the keymap exactly, so O is listed as its mod-tap.
const uint16_t PROGMEM gc_combo[]    = {KC_G, KC_C, COMBO_END};
const uint16_t PROGMEM ocomm_combo[] = {LOPT_T(KC_O), KC_COMM, COMBO_END};
const uint16_t PROGMEM cr_combo[]    = {KC_C, KC_R, COMBO_END};

combo_t key_combos[] = {
    [GC_BSPC]  = COMBO(gc_combo, KC_BSPC),
    [OCOMM_AT] = COMBO(ocomm_combo, KC_AT),
    [CR_DEL]   = COMBO(cr_combo, KC_DEL),
};

// "cr" is a common roll in Dvorak (across, describe), so C + R only fires
// when no other key was pressed in the CR_IDLE_MS before it.
#define CR_IDLE_MS 150

static uint16_t last_press_time;
static uint16_t prev_press_time;

bool pre_process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        prev_press_time = last_press_time;
        last_press_time = record->event.time;
    }
    return true;
}

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    // Only the combo's first key is checked; the second always follows closely.
    if (combo_index == CR_DEL && combo->state == 0) {
        return TIMER_DIFF_16(record->event.time, prev_press_time) >= CR_IDLE_MS;
    }
    return true;
}
