CONSOLE_ENABLE = no
COMMAND_ENABLE = no
ORYX_ENABLE = yes
RGB_MATRIX_CUSTOM_KB = yes
SPACE_CADET_ENABLE = no

# Non-ORYX Custom QMK Features
KEY_OVERRIDE_ENABLE = yes
REPEAT_KEY_ENABLE = yes

SRC += features/custom_shift_keys.c
