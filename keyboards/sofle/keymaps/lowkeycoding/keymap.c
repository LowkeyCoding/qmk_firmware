#include QMK_KEYBOARD_H
#include "animation.h"
#include "keymap_danish.h"
#include "shift_keys.h"

enum sofle_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_LOWER,
    KC_RAISE,
    NEW_SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * QWERTY
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Bspc |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  |   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
     * |------+------+------+------+------+------| MUTE  |    |  END  |------+------+------+------+------+------|
     * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | LGUI | LAlt | LCTR |LOWER | /Space  /       \Enter \  |RAISE | RCTR | RAlt | RGUI |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */

    [_QWERTY] = LAYOUT(
        DK_GRV, DK_1, DK_2, DK_3, DK_4, DK_5,                   DK_6, DK_7, DK_8, DK_9, DK_0, KC_BSPC,
        KC_ESC, DK_Q, DK_W, DK_E, DK_R, DK_T,                   DK_Y, DK_U, DK_I, DK_O, DK_P, DK_BSLS,
        KC_TAB, DK_A, DK_S, DK_D, DK_F, DK_G,                   DK_H, DK_J, DK_K, DK_L, DK_SCLN, DK_QUOT,
        KC_LSFT, DK_Z, DK_X, DK_C, DK_V, DK_B, KC_MUTE,     KC_END, DK_N, DK_M, DK_COMM, DK_DOT, DK_SLSH, KC_RSFT,
        KC_LGUI, KC_LALT, KC_LCTL, KC_LOWER, KC_SPC,   KC_ENT, KC_RAISE, KC_RCTL, KC_RALT, KC_RGUI),

    /* LOWER
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  |  F10 | F11  | F12  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | ESC  |      |      |      |      |      |                    |      |      |      |      |      | Bspc |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | CAPS |  =   |  -   |  +   |   {  |   }  |-------.    ,-------|   [  |   ]  |   (  |   )  |      | Tab  |
     * |------+------+------+------+------+------| MUTE  |    | HOME  |------+------+------+------+------+------|
     * | Shift|  !   |  @   |  #   |   $  |   %  |-------|    |-------|      |      |      |      |      | Shift|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | LGUI | LAlt | LCTR |LOWER | /Space  /       \Enter \  | WIN  | RCTR | RAlt | RGUI |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    [_LOWER] = LAYOUT(
        KC_F1, KC_F2, KC_F3, KC_F5, KC_F5, KC_F6,                                              KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
        KC_ESC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC,
        KC_CAPS, DK_EQL, DK_MINS, DK_PLUS, DK_LCBR, DK_RCBR,                          DK_LBRC, DK_RBRC, DK_LPRN, DK_RPRN, XXXXXXX, KC_TAB,
        KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE,     KC_HOME, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RSFT, 
        KC_LGUI, KC_LALT, KC_LCTL, KC_LOWER, KC_SPC,                                       KC_ENT, MAGIC_HOST_NKRO, KC_RCTL, KC_RALT, KC_RGUI),
    /* RAISE
     * ,----------------------------------------.                     ,-----------------------------------------.
     * | Esc  |      |      |      |      |      |                    |      |      |      |      |      | Bspc |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  | Ins  | PRTSC|  Æ   |      |      |                    |      |      |  Up  |  Ø   |      | Del  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Caps |  Å   |      |      |      |      |-------.    ,-------|      | Left | Down | Rigth|      |      |
     * |------+------+------+------+------+------| MUTE  |    | HOME  |------+------+------+------+------+------|
     * | Shift| Undo |  Cut | Copy | Paste|      |-------|    |-------|      |      |      |      |      | Shift|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | LGUI | LAlt | LCTR | LNX  | /Space  /       \Enter \  |RAISE | RCTR | RAlt | RGUI |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'            '------''---------------------------'
     */
    [_RAISE] = LAYOUT(
        KC_ESC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC,
        KC_TAB, KC_INS, KC_PSCR, DK_AE, XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX, KC_UP, DK_OSTR, XXXXXXX, KC_DEL,
        KC_CAPS, DK_ARNG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,
        KC_LSFT, KC_UNDO, KC_CUT, KC_COPY, KC_PASTE, XXXXXXX, KC_MUTE,      KC_HOME, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX, KC_RSFT, 
        KC_LGUI, KC_LALT, KC_LCTL, MAGIC_UNHOST_NKRO, KC_SPC,                             KC_ENT, KC_RAISE, KC_RCTL, KC_RALT, KC_RGUI),
};

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_custom_shift_keys(keycode, record)) { return false; }
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
            } else {
                layer_off(_LOWER);
            }
            return false;
        case KC_RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
            } else {
                layer_off(_RAISE);
            }
            return false;
        case KC_COPY:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_C);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_C);
            }
            return false;
        case KC_PASTE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_V);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_V);
            }
            return false;
        case KC_CUT:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_X);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_X);
            }
            return false;
            break;
        case KC_UNDO:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_Z);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_Z);
            }
            return false;
    }
    return true;
}
static int c_frame      = 0;
bool       first_render = 1;

static void render_anim(void) {
    if (first_render) {
        oled_write_raw_P(frame, ANIM_SIZE);
        first_render = 0;
    } else {
        change_frame_bytewise(c_frame);
    }
    c_frame = c_frame + 1 > IDLE_FRAMES ? 0 : c_frame + 1;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_anim();
        // oled_set_cursor(0,12);
        // sprintf(wpm_str, "WPM\n%03d", get_current_wpm());
        // oled_write(wpm_str, false);
    } else {
        // print_status_narrow();
    }
    return true;
}

#endif

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return true;
}

#endif