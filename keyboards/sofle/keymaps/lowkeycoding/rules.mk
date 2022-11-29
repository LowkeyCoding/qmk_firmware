OLED_ENABLE = yes
NKRO_ENABLE = yes
OLED_DRIVER = SSD1306
ENCODER_ENABLE = yes
EXTRAKEY_ENABLE = yes
UNICODEMAP_ENABLE = no
MOUSEKEY_ENABLE = no 
SRC += features/custom_shift_keys.c
EXTRAFLAGS += -flto -Os -finline-limit=0