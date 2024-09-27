ifeq ($(strip $(RGBLIGHT_ENABLE)), yes)
  SRC += rgb_hid.c
  RAW_ENABLE = yes
endif
