# 6k_keypad

QMK firmware for the [6k keypad](https://github.com/souffle17/6k-keypad)

Holding down a key while plugging it in will set the keypad to one of 6 keymaps.

1. F13-F18
2. F19-F24
3. WASD
4. Arrow keys
5. Mouse control
6. Media playback

* Keyboard Maintainer: [souffle17](https://github.com/souffle17)
* Hardware Supported: [6k keypad](https://github.com/souffle17/6k-keypad)
* Hardware Availability: [6k keypad](https://github.com/souffle17/6k-keypad)

Make example for this keyboard (after setting up your build environment):

    make 6k_keypad:default

Flashing example for this keyboard:

    make 6k_keypad:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 2 ways:

* **Bootmagic reset**: Hold down the top left and top right keys and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB
