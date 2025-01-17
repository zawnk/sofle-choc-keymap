#include QMK_KEYBOARD_H

enum layers {
    _QWERTY,
    _GAMING,
    _NAV,
};

#include "oled.c"
#include "encoder.c"

enum combo_events {
	COMBO_TOGGLE_LAYERS,
	COMBO_COPY_SHORTCUT,
	COMBO_PASTE_SHORTCUT,
};

// Combo definitions
const uint16_t PROGMEM combo_toggle_layers[] = {LT(_NAV, KC_ENT), LT(_NAV, KC_DEL), COMBO_END};
const uint16_t PROGMEM combo_copy_shortcut[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM combo_paste_shortcut[] = {KC_X, KC_V, COMBO_END};

combo_t key_combos[] = {
    [COMBO_TOGGLE_LAYERS] = COMBO(combo_toggle_layers, TG(_GAMING)),
	[COMBO_COPY_SHORTCUT] = COMBO(combo_copy_shortcut, KC_COPY),
	[COMBO_PASTE_SHORTCUT] = COMBO(combo_paste_shortcut, KC_PASTE),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWERTY] = LAYOUT( \
	  KC_ESC,			KC_1,			KC_2,    		KC_3,			KC_4,			KC_5,                     				KC_6,		KC_7,			KC_8,			KC_9,			KC_0,					XXXXXXX, \
	  KC_GRV,			KC_Q,			KC_W,    		KC_E,			KC_R,			KC_T,									KC_Y,		KC_U,			KC_I,			KC_O,			KC_P,					KC_EQUAL, \
	  LCTL_T(KC_TAB),	LGUI_T(KC_A),	RALT_T(KC_S),	LCTL_T(KC_D),	LSFT_T(KC_F),	KC_G,									KC_H,		RSFT_T(KC_J),	RCTL_T(KC_K),	RALT_T(KC_L),	RGUI_T(KC_SEMICOLON),	KC_QUOTE, \
	  KC_LSFT,  		KC_Z,			KC_X,			KC_C,			KC_V,			KC_B, KC_MUTE,   KC_MEDIA_PLAY_PAUSE,	KC_N,		KC_M,			KC_COMM,		KC_DOT,			KC_SLSH,				MO(_NAV), \
														KC_NO, KC_NO, KC_NO, KC_SPC, LT(_NAV, KC_ENT),   LT(_NAV, KC_DEL), KC_BACKSPACE, KC_NO, KC_NO, KC_NO \
    ),
	[_GAMING] = LAYOUT( \
	  KC_ESC,			KC_TRNS,		KC_TRNS,    	KC_TRNS,		KC_TRNS,		KC_TRNS,                     			KC_TRNS,	KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,			KC_TRNS, \
	  KC_TAB,			KC_TRNS,		KC_TRNS,    	KC_TRNS,		KC_TRNS,		KC_TRNS,								KC_TRNS,	KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,			KC_TRNS, \
	  KC_LCTL,			KC_A,			KC_S,			KC_D,			KC_F,			KC_G,									KC_TRNS,	KC_J,			KC_K,			KC_L,			KC_SEMICOLON,		KC_TRNS, \
	  KC_LSFT,  		KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS, KC_TRNS,   KC_PRINT_SCREEN,	KC_TRNS,	KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS,			KC_TRNS, \
															KC_TRNS, KC_TRNS, KC_LALT, KC_TRNS, KC_TRNS,	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS \
    ),
	[_NAV] = LAYOUT( \
	  KC_TRNS,			KC_F1,			KC_F2,    		KC_F3,			KC_F4,			KC_F5,                     				KC_F6,		KC_F7,			KC_F8,			KC_F9,			KC_F10,			KC_F11, \
	  KC_TRNS,			KC_LBRC,		KC_P7,    		KC_P8,			KC_P9,			KC_RBRC,								MS_BTN1,	MS_LEFT,		MS_UP,			MS_DOWN,		MS_RGHT,		KC_F12, \
	  KC_TRNS,			KC_BSLS,		KC_P4,			KC_P5,			KC_P6,			KC_EQUAL,								MS_BTN2,	KC_LEFT,		KC_UP,			KC_DOWN,		KC_RIGHT,		KC_TRNS, \
	  KC_TRNS,  		KC_NO,			KC_P1,			KC_P2,			KC_P3,			KC_MINUS, KC_TRNS,  KC_TRNS,			MS_BTN3,	MS_WHLL,		MS_WHLU,		MS_WHLD,		MS_WHLR,		KC_TRNS, \
																KC_TRNS, KC_P0, KC_TRNS, KC_TRNS, KC_ENT,   KC_DEL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS \
    )
};