// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

typedef union {
  uint32_t raw;
  struct {
    uint16_t     key_layer :16;
  };
} user_config_t;

user_config_t user_config;

enum custom_keycodes {
    KC_CTRL_C = SAFE_RANGE,
    KC_CTRL_V,
    KC_CTRL_X,
    KC_CTRL_Z,
    KC_CTRL_Y,
    KC_CTRL_A,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case KC_CTRL_X:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTL("x"));
        }
        break;
    case KC_CTRL_C:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTL("c"));
        }
        break;
    case KC_CTRL_V:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTL("v"));
        }
        break;
    case KC_CTRL_Z:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTL("z"));
        }
        break;
    case KC_CTRL_Y:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTL("y"));
        }
        break;
    case KC_CTRL_A:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTL("a"));
        }
        break;
    }
    return true;
};

void keyboard_post_init_user(void) {
    layer_on(user_config.key_layer);
}

void bootmagic_lite(void) {
    matrix_scan();
    wait_ms(DEBOUNCE * 2);
    matrix_scan();

    user_config.raw = eeconfig_read_user();

    if (user_config.key_layer == 0) {
        user_config.key_layer = 1;
    }

    //type safety
    uint16_t layer = user_config.key_layer;

    if (matrix_get_row(0) & (1 << 0) && matrix_get_row(0) & (1 << 1) && matrix_get_row(0) & (1 << 2)) {
        layer = 0;
    }
    else if (matrix_get_row(0) & (1 << 0) && matrix_get_row(0) & (1 << 1)) {
        layer = 7;
    }
    else if (matrix_get_row(0) & (1 << 0) && matrix_get_row(0) & (1 << 2)) {
        layer = 8;
    }
    else if (matrix_get_row(0) & (1 << 0)) {
        layer = 1;
    }
    else if (matrix_get_row(0) & (1 << 1)) {
        layer = 2;
    }
    else if (matrix_get_row(0) & (1 << 2)) {
        layer = 3;
    }
    else if (matrix_get_row(1) & (1 << 0)) {
        layer = 4;
    }
    else if (matrix_get_row(1) & (1 << 1)) {
        layer = 5;
    }
    else if (matrix_get_row(1) & (1 << 2)) {
        layer = 6;
    }
    else if (user_config.key_layer > 8){
        layer = 1;
    }

    if (user_config.key_layer != layer) {
        user_config.key_layer = layer;
        eeconfig_update_user(user_config.raw); 
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┐
     * │ 1 │ 2 │ 3 │
     * ├───┼───┼───┤
     * │ 4 │ 5 │ 6 │
     * └───┴───┴───┘
     */
    [0] = LAYOUT_ortho_2x3(
        QK_BOOT,    QK_BOOT,    QK_BOOT,
        QK_BOOT,    QK_BOOT,    QK_BOOT
    ),
    [1] = LAYOUT_ortho_2x3(
        KC_F13,    KC_F14,    KC_F15,
        KC_F16,    KC_F17,    KC_F18
    ),
    [2] = LAYOUT_ortho_2x3(
        KC_F19,    KC_F20,    KC_F21,
        KC_F22,    KC_F23,    KC_F24
    ),
    [3] = LAYOUT_ortho_2x3(
        KC_Q,    KC_W,    KC_E,
        KC_A,    KC_S,    KC_D
    ),
    [4] = LAYOUT_ortho_2x3(
        KC_BACKSPACE,    KC_UP,    KC_SPACE,
        KC_LEFT,    KC_DOWN,    KC_RIGHT
    ),
    [5] = LAYOUT_ortho_2x3(
        KC_CTRL_A,    KC_CTRL_Z,    KC_CTRL_Y,
        KC_CTRL_X,    KC_CTRL_C,    KC_CTRL_V
    ),
    [6] = LAYOUT_ortho_2x3(
        KC_AUDIO_VOL_UP,    KC_MEDIA_PREV_TRACK,    KC_MEDIA_NEXT_TRACK,
        KC_AUDIO_VOL_DOWN,    KC_MEDIA_PLAY_PAUSE,    KC_MEDIA_STOP
    ),
    [7] = LAYOUT_ortho_2x3(
        KC_MS_BTN1,    KC_MS_UP,    KC_MS_BTN2,
        KC_MS_LEFT,    KC_MS_DOWN,    KC_MS_RIGHT
    ),
    [8] = LAYOUT_ortho_2x3(
        KC_MS_WH_UP,    KC_PAGE_UP,    KC_HOME,
        KC_MS_WH_DOWN,    KC_PAGE_DOWN,    KC_END
    ),
};