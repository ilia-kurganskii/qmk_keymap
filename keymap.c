// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

#include "gpio.h"

enum sofle_layers {
    _QWERTY,
    _COLEMAKDH,
    _NAV,
    _SYM,
    _ADJUST,
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_COLEMAKDH,
    KC_D_MUTE,
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND
};

// Left-hand home row mods
#define HOME_A LCTL_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LGUI_T(KC_D)
#define HOME_F LSFT_T(KC_F)

// Right-hand home row mods
#define HOME_J RSFT_T(KC_J)
#define HOME_K RGUI_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SCLN RCTL_T(KC_SCLN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | GESC |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  =   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LOWER| Space| / LTLOW(Tab)    LTRAI(Ent) \  | Bspc | RAISE| RAlt | RGUI |
 *            |      |      | (MO) |      |/       /         \      \   |      | (MO) |      |      |
 *            `----------------------------------'           '------''-------------------------------'
 */
[_QWERTY] = LAYOUT(
    LT(_ADJUST,KC_ESC),    KC_1,       KC_2,       KC_3,       KC_4,       KC_5,                        KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_EQL,
    KC_ESC,    KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,                        KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_BSPC,
    KC_TAB,    HOME_A,     HOME_S,     HOME_D,     HOME_F,     KC_G,                        KC_H,       HOME_J,     HOME_K,     HOME_L,     HOME_SCLN,  KC_QUOT,
    KC_LSFT,   KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,    KC_MUTE, KC_D_MUTE, KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_RSFT,
            KC_LGUI,    KC_LALT,    LT(_SYM,KC_ESC), LT(_NAV,KC_SPC),   KC_TAB,  KC_ENT,    KC_BSPC, LT(_SYM,KC_DEL),        KC_RALT, KC_RGUI
),



[_COLEMAKDH] = LAYOUT(
    _______,  KC_1,       KC_2,       KC_3,       KC_4,       KC_5,                            KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       _______,
    _______,  KC_Q,       KC_W,       KC_F,       KC_P,       KC_B,                            KC_J,       KC_L,       KC_U,       KC_Y,       KC_SCLN,    _______,
    _______,  KC_A,       KC_R,       KC_S,       KC_T,       KC_G,                            KC_M,       KC_N,       KC_E,       KC_I,       KC_O,       _______,
    _______,  KC_Z,       KC_X,       KC_C,       KC_D,       KC_V,     _______,   _______,    KC_K,       KC_H,       KC_COMM,    KC_DOT,     KC_SLSH,    _______,
                          _______,    _______,    _______,    _______,  _______,   _______,    _______,    _______,    _______,    _______
),

/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |  TRN |  TRN |  TRN |  TRN |   %  |-------.    ,-------|   ^  |  TRN |  TRN |  TRN |  TRN |   |  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | Shift|  =   |  -   |  +   |   {  |   }  |-------|    |-------|   [  |   ]  |   ;  |   :  |   \  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 */
[_NAV] = LAYOUT(
  _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                           KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  _______,
  _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______,  _______,
  _______, _______, _______, _______, _______, _______,                         _______,KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, _______, 
  _______, _______, _______, _______, _______, KC_F11, _______,       _______, KC_F12, _______, _______, _______, _______, _______,
                    _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
),

/* SYM
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |   =  |   +  |   -  |   &  |   *  |   /  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|   {  |   [  |   (  |   <  |   '  |   "  |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|   |  |   }  |   ]  |   )  |   >  |   \  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |   :  |   ;  |   ?  |   !  |   `  |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_SYM] = LAYOUT(
  _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                           KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,   _______,
  _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______,   _______,
  _______, KC_1, LCTL_T(KC_2), LALT_T(KC_3), LGUI_T(KC_4), LSFT_T(KC_5), RSFT_T(KC_6), RGUI_T(KC_7), LALT_T(KC_8), RCTL_T(KC_9), KC_0, _______,
  _______, KC_SLSH, KC_GRV, KC_MINS, _______, KC_F11, _______,       _______, KC_F12,  _______, KC_LBRC, KC_RBRC, _______, _______,
                    _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
),



/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | QK_BOOT|      |QWERTY|COLEMAK|      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |MACWIN|      |      |      |-------.    ,-------|      | VOLDO| MUTE | VOLUP|      |      |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      | PREV | PLAY | NEXT |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
  [_ADJUST] = LAYOUT(
  XXXXXXX , XXXXXXX,  XXXXXXX ,  XXXXXXX , XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  QK_BOOT  , XXXXXXX,KC_QWERTY,KC_COLEMAKDH,CG_TOGG,XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX , XXXXXXX,CG_TOGG, XXXXXXX,    XXXXXXX,  XXXXXXX,                     XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,
  XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,  XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
                   _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
  )
};
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_COLEMAKDH:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAKDH);
            }
            return false;
        
        case KC_D_MUTE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_MEH));
                register_code(KC_UP);
            } else {
                unregister_mods(mod_config(MOD_MEH));
                unregister_code(KC_UP);
            }
    }
    return true;
}

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
		} else if (index == 1) {
			switch (get_highest_layer(layer_state)) {
				case _QWERTY:
				case _COLEMAKDH:
					if (clockwise) {
						tap_code(KC_PGDN);
					} else {
						tap_code(KC_PGUP);
					}
				break;
			case _SYM:
			case _NAV:
					if (clockwise) {
						tap_code(KC_DOWN);
					} else {
						tap_code(KC_UP);
					}
				break;
			default:
					if (clockwise) {
						tap_code(KC_WH_D);
					} else {
						tap_code(KC_WH_U);
					}
				break;
		}
    }
    return true;
}

#endif

#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM raw_logo[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,128,128,128,128,128,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,192,192,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,128,224,248,252,254,255,255,255,127, 63, 15,  3,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,255,255,255,224,112,112,112,112,112,112,240,224,192,128,  0,  0,  0,243,243,243,  0,  0, 32,112,112,254,255,255, 48, 48, 48,  0,  0,  0,224,240,240,128,  0,  0,  0,  0,  0,192,240,240, 96,  0,  0,128,192,224,240,240,112,112,112,240,224,224,240,240,  0,  0, 32,112,240,240,224,  0,  0,  0,  0,  0,128,224,240,240, 48,  0,128,192,224,224,240,112,112,112,112,240,224,224,192,  0, 
        0,128,224,240,252,255,255,255,255,255, 63, 15,  7,  1,192,224,248,254,255,255,255,255,127, 31,  7,  1,  0,  0,  0,  0,  0,  0,  0,  0,255,255,255,224,192,128,128,128,128,192,224,255,255,127,  0,  0,  0,255,255,255,  0,  0,  0,  0,  0,255,255,255,128,128,128,  0,  0,  0,  0,  3, 31,127,254,224,192,224,252,127, 31,  3,  0,  0, 31,127,255,255,225,192,192,128,192,192,225,255,255,255,  0,  0,  0,  0,  1, 15, 63,255,252,224,192,252,255, 31,  7,  0,  0,  4, 63,255,255,241,192,192,128,128,192,192,225,255,255, 63, 
        2,  3,  3,  3,  3,  3,  3,  3,  1,  0,  0,  0,  0,  3,  3,  3,  3,  3,  3,  3,  3,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  3,  3,  3,  1,  1,  3,  3,  3,  3,  3,  1,  1,  0,  0,  0,  0,  0,  3,  3,  3,  0,  0,  0,  0,  0,  0,  1,  3,  3,  3,  3,  0,  0,  0,  0,  0,  0,  0,  3,  3,  3,  3,  3,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  3,  3,  3,  3,  1,  3,  3,  3,  0,  0,  0,  0,  0,  0,  0,  1,  3,  3,  3,  3,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  3,  3,  3,  3,  3,  1,  1,  0,  0,
    };
    oled_write_raw_P(raw_logo, sizeof(raw_logo));
}

static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("Ilia\nKurganskii"), false);

    oled_write_ln_P(PSTR(""), false);

	//snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%ld", layer_state)


    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Qwrt"), false);
            break;
        case _COLEMAKDH:
            oled_write_ln_P(PSTR("CmkDH"), false);
            break;

        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
        case _COLEMAKDH:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("Nav"), false);
            break;
        case _SYM:
            oled_write_P(PSTR("Sym"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adj\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return false;
}

#endif

void keyboard_pre_init_user(void) {
    gpio_set_pin_output(24);
    gpio_write_pin_high(24);
}