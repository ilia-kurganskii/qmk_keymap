// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "gpio.h"

// Layer definitions
enum sofle_layers {
    _QWERTY,        // Default QWERTY layout
    _COLEMAKDH,     // Colemak-DH alternative layout
    _NAV,           // Navigation layer with arrow keys and function keys
    _SYM,           // Symbol layer for programming and special characters
    _ADJUST,        // System adjustment layer (layout switching, media controls)
};

// Custom keycode definitions
enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,  // Switch to QWERTY layout
    KC_COLEMAKDH,            // Switch to Colemak-DH layout
    KC_D_MUTE,               // Discord mute (MEH+UP)
    KC_PRVWD,                // Previous word (unused in current config)
    KC_NXTWD,                // Next word (unused in current config)
    KC_LSTRT,                // Line start (unused in current config)
    KC_LEND                  // Line end (unused in current config)
};

// Home row modifiers for left hand (GACS order: GUI, Alt, Ctrl, Shift)
#define HOME_A    LCTL_T(KC_A)     // A key with left Control when held
#define HOME_S    LALT_T(KC_S)     // S key with left Alt when held
#define HOME_D    LGUI_T(KC_D)     // D key with left GUI (Cmd/Win) when held
#define HOME_F    LSFT_T(KC_F)     // F key with left Shift when held

// Home row modifiers for right hand (SCAG order: Shift, Ctrl, Alt, GUI)
#define HOME_J    RSFT_T(KC_J)     // J key with right Shift when held
#define HOME_K    RGUI_T(KC_K)     // K key with right GUI (Cmd/Win) when held
#define HOME_L    LALT_T(KC_L)     // L key with right Alt when held
#define HOME_SCLN RCTL_T(KC_SCLN)  // ; key with right Control when held

// Keymap definitions
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 * QWERTY Base Layer
 * ┌─────────┬─────┬─────┬─────┬─────┬─────┐                    ┌─────┬─────┬─────┬─────┬─────┬─────┐
 * │ ESC/ADJ │  1  │  2  │  3  │  4  │  5  │                    │  6  │  7  │  8  │  9  │  0  │  =  │
 * ├─────────┼─────┼─────┼─────┼─────┼─────┤                    ├─────┼─────┼─────┼─────┼─────┼─────┤
 * │   ESC   │  Q  │  W  │E/SYM│  R  │  T  │                    │  Y  │  U  │I/SYM│  O  │  P  │BSPC │
 * ├─────────┼─────┼─────┼─────┼─────┼─────┤                    ├─────┼─────┼─────┼─────┼─────┼─────┤
 * │   TAB   │A/CTL│S/ALT│D/GUI│F/SFT│  G  │                    │  H  │J/SFT│K/GUI│L/ALT│;/CTL│  '  │
 * ├─────────┼─────┼─────┼─────┼─────┼─────┼─────┐    ┌─────────┼─────┼─────┼─────┼─────┼─────┼─────┤
 * │  SHIFT  │  Z  │  X  │  C  │V/NAV│  B  │MUTE │    │ D_MUTE  │  N  │M/NAV│  ,  │  .  │  /  │SHIFT│
 * └─────────┴─────┴─────┴─────┴─────┴─────┴─────┘    └─────────┴─────┴─────┴─────┴─────┴─────┴─────┘
 *                   ┌─────┬─────┬─────────┬─────────┐┌─────────┬─────────┬─────┬─────┐
 *                   │ GUI │ ALT │ ESC/SYM │ SPC/NAV ││   TAB   │ ENT     │BSPC │ GUI │
 *                   └─────┴─────┴─────────┴─────────┘└─────────┴─────────┴─────┴─────┘
 */
[_QWERTY] = LAYOUT(
    LT(_ADJUST,KC_ESC), KC_1,       KC_2,           KC_3,               KC_4,           KC_5,                               KC_6,       KC_7,               KC_8,           KC_9,       KC_0,           KC_EQL,
    KC_ESC,             KC_Q,       KC_W,           LT(_SYM,KC_E),      KC_R,           KC_T,                               KC_Y,       KC_U,               LT(_SYM,KC_I),  KC_O,       KC_P,           KC_BSPC,
    KC_TAB,             HOME_A,     HOME_S,         HOME_D,             HOME_F,         KC_G,                               KC_H,       HOME_J,             HOME_K,         HOME_L,     HOME_SCLN,      KC_QUOT,
    KC_LSFT,            KC_Z,       KC_X,           KC_C,               LT(_NAV,KC_V),  KC_B,       KC_MUTE,    KC_D_MUTE,  KC_N,       LT(_NAV,KC_M),      KC_COMM,        KC_DOT,     KC_SLSH,        KC_RSFT,
                                    KC_LGUI,        KC_LALT,            LT(_SYM,KC_ESC), LT(_NAV,KC_SPC), KC_TAB, KC_ENT,    KC_BSPC,    LT(_SYM,KC_DEL),    KC_RALT,        KC_RGUI
),

/*
 * COLEMAK-DH Alternative Layout
 * Same structure as QWERTY but with Colemak-DH letter arrangement
 */
[_COLEMAKDH] = LAYOUT(
    _______,    KC_1,       KC_2,       KC_3,       KC_4,       KC_5,                               KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       _______,
    _______,    KC_Q,       KC_W,       KC_F,       KC_P,       KC_B,                               KC_J,       KC_L,       KC_U,       KC_Y,       KC_SCLN,    _______,
    _______,    KC_A,       KC_R,       KC_S,       KC_T,       KC_G,                               KC_M,       KC_N,       KC_E,       KC_I,       KC_O,       _______,
    _______,    KC_Z,       KC_X,       KC_C,       KC_D,       KC_V,       _______,    _______,    KC_K,       KC_H,       KC_COMM,    KC_DOT,     KC_SLSH,    _______,
                            _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
),

/*
 * NAVIGATION Layer
 * ┌─────────┬─────┬─────┬─────┬─────┬─────┐                    ┌─────┬─────┬─────┬─────┬─────┬─────┐
 * │         │ F1  │ F2  │ F3  │ F4  │ F5  │                    │ F6  │ F7  │ F8  │ F9  │ F10 │     │
 * ├─────────┼─────┼─────┼─────┼─────┼─────┤                    ├─────┼─────┼─────┼─────┼─────┼─────┤
 * │         │     │     │     │     │     │                    │     │     │     │     │     │     │
 * ├─────────┼─────┼─────┼─────┼─────┼─────┤                    ├─────┼─────┼─────┼─────┼─────┼─────┤
 * │         │     │     │     │     │     │                    │     │LEFT │DOWN │ UP  │RIGHT│     │
 * ├─────────┼─────┼─────┼─────┼─────┼─────┼─────┐    ┌─────────┼─────┼─────┼─────┼─────┼─────┼─────┤
 * │         │     │     │     │     │ F11 │     │    │         │ F12 │     │     │     │     │     │
 * └─────────┴─────┴─────┴─────┴─────┴─────┴─────┘    └─────────┴─────┴─────┴─────┴─────┴─────┴─────┘
 */
[_NAV] = LAYOUT(
    _______,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,                              KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     _______,
    _______,    _______,    _______,    _______,    _______,    _______,                            _______,    _______,    _______,    _______,    _______,    _______,
    _______,    _______,    _______,    _______,    _______,    _______,                            _______,    KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT,   _______,
    _______,    _______,    _______,    _______,    _______,    KC_F11,     _______,    _______,    KC_F12,     _______,    _______,    _______,    _______,    _______,
                            _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
),

/*
 * SYMBOL Layer
 * ┌─────────┬─────┬─────┬─────┬─────┬─────┐                    ┌─────┬─────┬─────┬─────┬─────┬─────┐
 * │         │ F1  │ F2  │ F3  │ F4  │ F5  │                    │ F6  │ F7  │ F8  │ F9  │ F10 │     │
 * ├─────────┼─────┼─────┼─────┼─────┼─────┤                    ├─────┼─────┼─────┼─────┼─────┼─────┤
 * │         │     │     │     │     │     │                    │     │     │     │     │     │     │
 * ├─────────┼─────┼─────┼─────┼─────┼─────┤                    ├─────┼─────┼─────┼─────┼─────┼─────┤
 * │         │1/CTL│//ALT│`/GUI│-/SFT│     │                    │     │[/SFT│]/GUI│=/ALT│0/CTL│     │
 * ├─────────┼─────┼─────┼─────┼─────┼─────┼─────┐    ┌─────────┼─────┼─────┼─────┼─────┼─────┼─────┤
 * │         │     │     │     │     │ F11 │     │    │         │ F12 │     │  [  │  ]  │  =  │     │
 * └─────────┴─────┴─────┴─────┴─────┴─────┴─────┘    └─────────┴─────┴─────┴─────┴─────┴─────┴─────┘
 */
[_SYM] = LAYOUT(
    _______,    KC_F1,              KC_F2,              KC_F3,              KC_F4,              KC_F5,                              KC_F6,              KC_F7,              KC_F8,              KC_F9,              KC_F10,             _______,
    _______,    _______,            _______,            _______,            _______,            _______,                            _______,            _______,            _______,            _______,            _______,            _______,
    _______,    LCTL_T(KC_1),       LALT_T(KC_SLSH),    LGUI_T(KC_GRV),     LSFT_T(KC_MINS),    _______,                            _______,            RSFT_T(KC_LBRC),    RGUI_T(KC_RBRC),    LALT_T(KC_EQL),     RCTL_T(KC_0),       _______,
    _______,    _______,            _______,            _______,            _______,            KC_F11,     _______,    _______,    KC_F12,             _______,            KC_LBRC,            KC_RBRC,            KC_EQL,             _______,
                                    _______,            _______,            _______,            _______,    _______,    _______,    _______,            _______,            _______,            _______
),

/*
 * ADJUST Layer - System Controls
 * ┌─────────┬─────┬─────┬─────┬─────┬─────┐                    ┌─────┬─────┬─────┬─────┬─────┬─────┐
 * │         │     │     │     │     │     │                    │     │     │     │     │     │     │
 * ├─────────┼─────┼─────┼─────┼─────┼─────┤                    ├─────┼─────┼─────┼─────┼─────┼─────┤
 * │ QK_BOOT │     │QWRTY│CLMAK│CGTOG│     │                    │     │     │     │     │     │     │
 * ├─────────┼─────┼─────┼─────┼─────┼─────┤                    ├─────┼─────┼─────┼─────┼─────┼─────┤
 * │         │     │CGTOG│     │     │     │                    │     │ VOL-│MUTE │ VOL+│     │     │
 * ├─────────┼─────┼─────┼─────┼─────┼─────┼─────┐    ┌─────────┼─────┼─────┼─────┼─────┼─────┼─────┤
 * │         │     │     │     │     │     │     │    │         │     │PREV │PLAY │NEXT │     │     │
 * └─────────┴─────┴─────┴─────┴─────┴─────┴─────┘    └─────────┴─────┴─────┴─────┴─────┴─────┴─────┘
 */
[_ADJUST] = LAYOUT(
    XXXXXXX,    XXXXXXX,    XXXXXXX,        XXXXXXX,        XXXXXXX,    XXXXXXX,                            XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    QK_BOOT,    XXXXXXX,    KC_QWERTY,      KC_COLEMAKDH,   CG_TOGG,    XXXXXXX,                            XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    XXXXXXX,    CG_TOGG,        XXXXXXX,        XXXXXXX,    XXXXXXX,                            XXXXXXX,    KC_VOLD,    KC_MUTE,    KC_VOLU,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    XXXXXXX,    XXXXXXX,        XXXXXXX,        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_MPRV,    KC_MPLY,    KC_MNXT,    XXXXXXX,    XXXXXXX,
                            _______,        _______,        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
)
};

// Custom keycode processing
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
            // Discord mute: MEH (Ctrl+Alt+Shift) + Up Arrow
            if (record->event.pressed) {
                register_mods(mod_config(MOD_MEH));
                register_code(KC_UP);
            } else {
                unregister_mods(mod_config(MOD_MEH));
                unregister_code(KC_UP);
            }
            break;
    }
    return true;
}

#ifdef ENCODER_ENABLE
// Rotary encoder configuration
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // Left encoder: Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        // Right encoder: Layer-dependent scrolling
        switch (get_highest_layer(layer_state)) {
            case _QWERTY:
            case _COLEMAKDH:
                // Base layers: Page Up/Down
                if (clockwise) {
                    tap_code(KC_PGDN);
                } else {
                    tap_code(KC_PGUP);
                }
                break;
                
            case _SYM:
            case _NAV:
                // Symbol/Nav layers: Arrow Up/Down
                if (clockwise) {
                    tap_code(KC_DOWN);
                } else {
                    tap_code(KC_UP);
                }
                break;
                
            default:
                // Other layers: Mouse wheel
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
// OLED display functions

// Custom logo for slave side
static void render_logo(void) {
    static const char PROGMEM raw_logo[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,128,128,128,128,128,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,192,192,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,128,224,248,252,254,255,255,255,127, 63, 15,  3,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,255,255,255,224,112,112,112,112,112,112,240,224,192,128,  0,  0,  0,243,243,243,  0,  0, 32,112,112,254,255,255, 48, 48, 48,  0,  0,  0,224,240,240,128,  0,  0,  0,  0,  0,192,240,240, 96,  0,  0,128,192,224,240,240,112,112,112,240,224,224,240,240,  0,  0, 32,112,240,240,224,  0,  0,  0,  0,  0,128,224,240,240, 48,  0,128,192,224,224,240,112,112,112,112,240,224,224,192,  0,
        0,128,224,240,252,255,255,255,255,255, 63, 15,  7,  1,192,224,248,254,255,255,255,255,127, 31,  7,  1,  0,  0,  0,  0,  0,  0,  0,  0,255,255,255,224,192,128,128,128,128,192,224,255,255,127,  0,  0,  0,255,255,255,  0,  0,  0,  0,  0,255,255,255,128,128,128,  0,  0,  0,  0,  3, 31,127,254,224,192,224,252,127, 31,  3,  0,  0, 31,127,255,255,225,192,192,128,192,192,225,255,255,255,  0,  0,  0,  0,  1, 15, 63,255,252,224,192,252,255, 31,  7,  0,  0,  4, 63,255,255,241,192,192,128,128,192,192,225,255,255, 63,
        2,  3,  3,  3,  3,  3,  3,  3,  1,  0,  0,  0,  0,  3,  3,  3,  3,  3,  3,  3,  3,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  3,  3,  3,  1,  1,  3,  3,  3,  3,  3,  1,  1,  0,  0,  0,  0,  0,  3,  3,  3,  0,  0,  0,  0,  0,  0,  1,  3,  3,  3,  3,  0,  0,  0,  0,  0,  0,  0,  3,  3,  3,  3,  3,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  3,  3,  3,  3,  1,  3,  3,  3,  0,  0,  0,  0,  0,  0,  0,  1,  3,  3,  3,  3,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  3,  3,  3,  3,  3,  1,  1,  0,  0,
    };
    oled_write_raw_P(raw_logo, sizeof(raw_logo));
}

// Status display for master side
static void print_status_narrow(void) {
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("Ilia\nKurganskii"), false);
    oled_write_ln_P(PSTR(""), false);

    // Display current base layout
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
    oled_write_ln_P(PSTR("LAYER"), false);
    
    // Display current active layer
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

// OLED orientation setup
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;  // Rotate master side display
    }
    return rotation;
}

// OLED display task
bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();     // Show status on master side
    } else {
        render_logo();             // Show logo on slave side
    }
    return false;
}
#endif

// GPIO initialization for RGB or other hardware
void keyboard_pre_init_user(void) {
    gpio_set_pin_output(24);       // Set pin 24 as output
    gpio_write_pin_high(24);       // Set pin 24 high (likely for RGB or LED power)
}