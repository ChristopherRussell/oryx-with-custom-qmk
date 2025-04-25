#include QMK_KEYBOARD_H
#include "version.h"
#include "i18n.h"
#include "features/custom_shift_keys.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
};

////////////////////////////////////////////////////////////
// Custom shift keys definition
////////////////////////////////////////////////////////////

const custom_shift_key_t custom_shift_keys[] = {
    {KC_COMM, KC_QUES},  // , -> ?
    {KC_DOT,  KC_EXLM},  // . -> !
    {KC_UNDS, KC_MINS},  // _ -> -
    {KC_DQUO, KC_QUOT},  // " -> '
    {UK_EURO, UK_POUND}, // € -> £
};

uint8_t NUM_CUSTOM_SHIFT_KEYS = sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);
//
////////////////////////////////////////////////////////////

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_7,           KC_5,           KC_3,           KC_1,           KC_9,                                           KC_8,           KC_0,           KC_2,           KC_4,           KC_6,           KC_TRANSPARENT, 
    TO(4),          KC_Q,           KC_W,           KC_F,           KC_P,           KC_B,                                           KC_J,           KC_L,           KC_U,           KC_Y,           KC_UNDS,        UK_PND,         
    KC_TRANSPARENT, KC_A,           KC_R,           KC_S,           KC_T,           KC_G,                                           KC_M,           KC_N,           KC_E,           KC_I,           KC_O,           KC_BSPC,        
    TO(2),          KC_Z,           KC_X,           KC_C,           KC_D,           KC_V,                                           KC_K,           KC_H,           KC_COMMA,       KC_DOT,         KC_DQUO,        TO(3),          
                                                    OSL(5),         KC_LEFT_SHIFT,                                  KC_SPACE,       TO(1)
  ),
  [1] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_BSLS,        KC_CIRC,        KC_AT,          KC_AMPR,        KC_PERC,                                        KC_RBRC,        KC_SCLN,        KC_LBRC,        KC_RCBR,        KC_LCBR,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_SLASH,       KC_PLUS,        KC_MINUS,       KC_EQUAL,       KC_ASTR,                                        KC_RPRN,        KC_COLN,        KC_LPRN,        KC_UNDS,        UK_HASH,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_LABK,        KC_RABK,        KC_PIPE,        KC_TILD,        KC_GRAVE,                                       UK_EURO,        KC_DLR,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, TO(0)
  ),
  [2] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_BSLS,        KC_CIRC,        KC_AT,          KC_AMPR,        KC_PERC,                                        KC_RBRC,        KC_SCLN,        KC_LBRC,        KC_RCBR,        KC_LCBR,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_SLASH,       KC_PLUS,        KC_MINUS,       KC_EQUAL,       KC_ASTR,                                        KC_RPRN,        KC_COLN,        KC_LPRN,        KC_UNDS,        UK_HASH,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_7,           KC_5,           KC_3,           KC_1,           KC_9,                                           KC_8,           KC_0,           KC_2,           KC_4,           KC_6,           KC_TRANSPARENT, 
    TO(0),          KC_LABK,        KC_RABK,        KC_PIPE,        KC_TILD,        KC_GRAVE,                                       UK_EURO,        KC_DLR,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [3] = LAYOUT_voyager(
    KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,                                          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,         
    KC_TRANSPARENT, KC_NO,          RGB_MODE_FORWARD,RGB_VAD,        RGB_VAI,        KC_NO,                                          KC_NO,          KC_AUDIO_VOL_UP,KC_AUDIO_VOL_DOWN,KC_AUDIO_MUTE,  KC_NO,          KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,KC_NO,                                          KC_NO,          KC_MEDIA_PREV_TRACK,KC_MEDIA_PLAY_PAUSE,KC_MEDIA_NEXT_TRACK,KC_MEDIA_STOP,  KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          TO(0),          
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [4] = LAYOUT_voyager(
    KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,                                          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,         
    TO(0),          KC_NO,          KC_NO,          OSM(MOD_MEH),   OSM(MOD_HYPR),  KC_DELETE,                                      TO(0),          KC_MS_WH_LEFT,  KC_MS_WH_DOWN,  KC_MS_WH_UP,    KC_MS_WH_RIGHT, KC_TRANSPARENT, 
    KC_TRANSPARENT, OSM(MOD_LALT),  OSM(MOD_LGUI),  OSM(MOD_LSFT),  OSM(MOD_LCTL),  KC_ESCAPE,                                      KC_MS_BTN3,     KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_UP,       KC_MS_RIGHT,    KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_PC_UNDO,     KC_PC_CUT,      KC_PC_COPY,     KC_NO,          KC_PC_PASTE,                                    KC_NO,          OSM(MOD_LCTL),  OSM(MOD_LSFT),  OSM(MOD_LGUI),  OSM(MOD_LALT),  KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_MS_BTN1,                                     KC_MS_BTN2,     KC_TRANSPARENT
  ),
  [5] = LAYOUT_voyager(
    KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,                                          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,         
    KC_TRANSPARENT, KC_NO,          KC_NO,          OSM(MOD_MEH),   OSM(MOD_HYPR),  KC_DELETE,                                      KC_NO,          KC_END,         KC_PGDN,        KC_PAGE_UP,     KC_HOME,        KC_TRANSPARENT, 
    KC_TRANSPARENT, OSM(MOD_LALT),  OSM(MOD_LGUI),  OSM(MOD_LSFT),  OSM(MOD_LCTL),  KC_ESCAPE,                                      KC_TAB,         KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_PC_UNDO,     KC_PC_CUT,      KC_PC_COPY,     KC_NO,          KC_PC_PASTE,                                    KC_NO,          OSM(MOD_LCTL),  OSM(MOD_LSFT),  OSM(MOD_LGUI),  OSM(MOD_LALT),  KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_ENTER,       KC_TRANSPARENT
  ),
};



extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245} },

    [1] = { {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255} },

    [2] = { {212,167,222}, {212,167,222}, {212,167,222}, {212,167,222}, {212,167,222}, {212,167,222}, {212,167,222}, {212,167,222}, {212,167,222}, {212,167,222}, {212,167,222}, {212,167,222}, {212,167,222}, {212,167,222}, {212,167,222}, {212,167,222}, {212,167,222}, {212,167,222}, {212,167,222}, {212,167,222}, {212,167,222}, {212,167,222}, {212,167,222}, {212,167,222}, {212,167,222}, {212,167,222}, {212,167,222}, {212,167,222}, {212,167,222}, {212,167,222}, {212,167,222}, {212,167,222}, {212,167,222}, {212,167,222}, {212,167,222}, {212,167,222}, {212,167,222}, {212,167,222}, {212,167,222}, {212,167,222}, {212,167,222}, {212,167,222}, {212,167,222}, {212,167,222}, {212,167,222}, {212,167,222}, {212,167,222}, {212,167,222}, {212,167,222}, {212,167,222}, {212,167,222}, {212,167,222} },

    [3] = { {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255} },

    [4] = { {17,199,211}, {17,199,211}, {17,199,211}, {17,199,211}, {17,199,211}, {17,199,211}, {17,199,211}, {17,199,211}, {17,199,211}, {17,199,211}, {17,199,211}, {17,199,211}, {17,199,211}, {17,199,211}, {17,199,211}, {17,199,211}, {17,199,211}, {17,199,211}, {17,199,211}, {17,199,211}, {17,199,211}, {17,199,211}, {17,199,211}, {17,199,211}, {17,199,211}, {17,199,211}, {17,199,211}, {17,199,211}, {17,199,211}, {17,199,211}, {17,199,211}, {17,199,211}, {17,199,211}, {17,199,211}, {17,199,211}, {17,199,211}, {17,199,211}, {17,199,211}, {17,199,211}, {17,199,211}, {17,199,211}, {17,199,211}, {17,199,211}, {17,199,211}, {17,199,211}, {17,199,211}, {17,199,211}, {17,199,211}, {17,199,211}, {17,199,211}, {17,199,211}, {17,199,211} },
    
    [5] = { {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (keyboard_config.disable_layer_led) { return false; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
    case 4:
      set_layer_color(4);
      break;
    case 5:
      set_layer_color(5);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_custom_shift_keys(keycode, record)) { return false; }
  
  switch (keycode) {
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}

////////////////////////////////////////////////////////////
// Non-ORYX Custom QMK Features
////////////////////////////////////////////////////////////
//
// ------------------------------------------------------------
// One-Shot Stuff
// ------------------------------------------------------------
// Callum layout was an initial inspiration. I found this blog post mentioning
// improvements:
//
// https://blog.ffff.lt/posts/callum-layers/
//
// It seems that there was a change made to QMK sometime between the blog 
// post and the current time that changes the default OSM behaviourin a OSL.
//
// https://github.com/qmk/qmk_firmware/issues/22566
//
// Where KoFish proposes this solution to get the old behaviour. Note, this
// does NOT let you chain like: OSL(1) -> OSL(4) -> OSM(Shift) -> <key in layer 2>
// instead you return to the base layer after the OSM key is released.
//
// I am using this to cancel the one-shot layer when the OSM key is pressed,
// so that I can do OSL -> OSM -> <key in original layer>
void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    // only on key-down, only for OSM keys, and only if an OSL is live:
    if ( record->event.pressed
      && IS_QK_ONE_SHOT_MOD(keycode)
      && is_oneshot_layer_active()
    ) {
        // nuke the layer so that the _next_ tap is on the base layer
        clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
    }
}

// ------------------------------------------------------------
// Key Override Stuff
// ------------------------------------------------------------
//
// This causes shift-backspace to send the delete key.
const key_override_t delete_key_override = 
    ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
// Pass a null-terminated array of key overrides to be used.
const key_override_t **key_overrides = (const key_override_t *[]){
	&delete_key_override,
	NULL
};
