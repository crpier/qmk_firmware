# QMK Firmware
This is my fork of qmk_firmware for my keyboard: a ZSA Voyager.
My layout is in the directory `keyboards/zsa/voyager/keymaps/based_vim`
The formatting in the files is applied by hand, so that it's easy to read for humans.

## Core tenets

* **Everything** needs to be documented.
* Comments also describe the keyboard layout using ASCII art.
* Comments and ASCII art must be kept up to date.
* Do **not** make changes outside beyond the scope of the prompt.
* Do **not** use automated formatting tools.

## Style

All key variable names should be at most 7 characters.
Builtin keycodes from QMK should always have an alias that is at most 7 characters.

## Testing

Test changes using:
```
qmk compile -km based_vim -kb zsa/voyager
```
