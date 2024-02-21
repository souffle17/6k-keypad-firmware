// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

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
        KC_MS_BTN1,    KC_MS_UP,    KC_MS_BTN2,
        KC_MS_LEFT,    KC_MS_DOWN,    KC_MS_RIGHT
    ),
    [6] = LAYOUT_ortho_2x3(
        KC_AUDIO_VOL_UP,    KC_MEDIA_PREV_TRACK,    KC_MEDIA_NEXT_TRACK,
        KC_AUDIO_VOL_DOWN,    KC_MEDIA_PLAY_PAUSE,    KC_MEDIA_STOP
    )
};

void bootmagic_lite(void) {
    matrix_scan();
    wait_ms(DEBOUNCE * 2);
    matrix_scan();

    if (matrix_get_row(0) & (1 << 0) && matrix_get_row(0) & (1 << 2)) {
        layer_on(0);
    }
    else if (matrix_get_row(0) & (1 << 0)) {
        layer_on(1);
    }
    else if (matrix_get_row(0) & (1 << 1)) {
        layer_on(2);
    }
    else if (matrix_get_row(0) & (1 << 2)) {
        layer_on(3);
    }
    else if (matrix_get_row(1) & (1 << 0)) {
        layer_on(4);
    }
    else if (matrix_get_row(1) & (1 << 1)) {
        layer_on(5);
    }
    else if (matrix_get_row(1) & (1 << 2)) {
        layer_on(6);
    }
    else {
        layer_on(1);
    }
}
