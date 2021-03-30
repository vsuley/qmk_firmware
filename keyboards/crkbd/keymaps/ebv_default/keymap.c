/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

// Keycodes that can get too long for proper formatting.
#define CAD LCTL(LALT(KC_DEL))
#define MUTE KC__MUTE
#define VOLUP KC__VOLUP
#define VOLDOWN KC__VOLDOWN


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum crkbd_layers {
  _BASE,
  _NUMS,
  _SYMS,
  _SYST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x6_3(
       KC_TAB,     KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                    KC_Y,     KC_U,     KC_I,     KC_O,    KC_P,  KC_BSPC,
      KC_LSFT,     KC_A,     KC_S,     KC_D,     KC_F,     KC_G,                    KC_H,     KC_J,     KC_K,     KC_L, KC_SCLN,  KC_QUOT,
      KC_LCTL,     KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,                    KC_N,     KC_M,  KC_COMM,   KC_DOT, KC_SLSH,   KC_ESC,
                                    KC_LGUI,MO(_NUMS),   KC_SPC,                  KC_ENT,MO(_SYMS),  KC_RALT

  ),

  [_NUMS] = LAYOUT_split_3x6_3(
KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
KC_LSFT,    KC_INS,    KC_HOME,    KC_UP,    KC_END,   KC_PGUP,    KC_PLUS,    KC_MINS,    KC_ASTR,    KC_SLSH,   KC_EQL,    KC_BSLS,
KC_LCTL,    KC_DEL,    KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_PGDN,    XXXXXXX,    XXXXXXX,    KC_COMM ,   KC_DOT,    XXXXXXX,    KC_ESC,
            KC_LGUI,    _______,    KC_SPC,    KC_ENT,    MO(_SYST),    KC_RALT
  ),

  [_SYMS] = LAYOUT_split_3x6_3(
KC_TAB,    KC_EXLM,    KC_AT,    KC_HASH,    KC_DLR,    KC_PERC,    KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_LPRN,    KC_RPRN,    KC_DEL,
KC_LSFT,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_MINS,    KC_EQL,    KC_BSLS,    KC_LBRC,    KC_RBRC,    KC_GRV,
KC_LCTL,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_UNDS,    KC_PLUS,    KC_PIPE,    KC_LCBR,    KC_RCBR,    KC_TILD,
            KC_LGUI,    MO(_SYST),    KC_SPC,    KC_ENT,    _______,   KC_RALT
  ),

  [_SYST] = LAYOUT_split_3x6_3(
XXXXXXX,    KC_MUTE,    KC_VOLD ,   KC_VOLU,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX ,   EEP_RST ,   RESET ,   CAD,
RGB_TOG,    RGB_HUI,    RGB_SAI,    RGB_VAI,    XXXXXXX,    XXXXXXX,    KC_F1,    KC_F2,    KC_F3 ,   KC_F4 ,   KC_F5,    KC_F6,
RGB_MOD,    RGB_HUD ,   RGB_SAD ,   RGB_VAD ,   XXXXXXX ,   XXXXXXX,    KC_F7,    KC_F8 ,   KC_F9 ,   KC_F10 ,   KC_F11 ,   KC_F12,
            KC_LGUI,    _______,    KC_SPC,    KC_ENT,    _______,    KC_RALT
  )
};

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_master) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}
/*
#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8
#define L_CPNK 16

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (biton32(layer_state)) {
        case L_BASE:
            oled_write_ln_P(PSTR("Colemak"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Numbers"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Symbols"), false);
            break;
        case L_CPNK:
            oled_write_ln_P(PSTR("Cyberpunk"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("System"), false);
            break;
    }
} */

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (biton32(layer_state)) {
        case _BASE:
            oled_write_ln_P(PSTR("Base"), false);
            break;
        case _NUMS:
            oled_write_ln_P(PSTR("Numbers"), false);
            break;
        case _SYMS:
            oled_write_ln_P(PSTR("Symbols"), false);
            break;
        case _SYST:
            oled_write_ln_P(PSTR("System"), false);
            break;
        default:
            oled_write_ln_P(PSTR("????"), false);
    }
}

char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

void oled_task_user(void) {
    if (is_master) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_DRIVER_ENABLE

#ifdef RGBLIGHT_LAYERS
#define HSV_DARKGREEN 85, 255, 100
#define HSV_DARKBLUE 170, 255, 100
#define HSV_DARKRED 10, 255, 50
#define HSV_DARKYELLOW1 20, 255, 40
#define HSV_DARKYELLOW2 18, 255, 100

const rgblight_segment_t PROGMEM l_cpnk_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    {7, 20, HSV_PURPLE}
);

const rgblight_segment_t PROGMEM l_nums_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    {7, 20, HSV_GREEN}
);

const rgblight_segment_t PROGMEM l_syms_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    {7, 20, HSV_BLUE}
);

const rgblight_segment_t PROGMEM l_syst_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    {7, 20, HSV_RED}
);


const rgblight_segment_t* const PROGMEM light_layers[] = RGBLIGHT_LAYERS_LIST(
    l_nums_lights,
    l_syms_lights,
    l_syst_lights
);

void keyboard_post_init_user(void) {
    rgblight_layers = light_layers;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, _NUMS));
    rgblight_set_layer_state(2, layer_state_cmp(state, _SYMS));
    rgblight_set_layer_state(3, layer_state_cmp(state, _SYST));
    return state;
}
#endif
