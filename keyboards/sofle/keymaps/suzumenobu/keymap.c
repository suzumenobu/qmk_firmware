#include QMK_KEYBOARD_H

enum sofle_layers {
  /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
  _QWERTY,
  _GAMING,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum custom_keycodes {
  KC_QWERTY = SAFE_RANGE,
  KC_GAMING,
  KC_LOWER,
  KC_RAISE,
  KC_ADJUST,
  KC_PRVWD,
  KC_NXTWD,
  KC_LSTRT,
  KC_LEND,
  KC_DLINE,
  KC_BSPC_DEL,
  KC_LAYER
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
		     _______,                       KC_F13,               KC_F14,    KC_F15,      KC_F20,    _______,                                                        KC_MEDIA_PREV_TRACK,    KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK,    KC_MEDIA_SELECT,    _______,  _______,
		     KC_ESC,                       KC_Q,               KC_W,    KC_E,      KC_R,    KC_T,                                                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC_DEL,
		     KC_TAB,   MT(MOD_LGUI, KC_A), MT(MOD_LALT, KC_S), MT(MOD_LSFT, KC_D), MT(MOD_LCTL, KC_F),                 KC_G,    KC_H,    MT(MOD_RCTL, KC_J), MT(MOD_RSFT, KC_K), MT(MOD_LALT, KC_L), MT(MOD_RGUI, KC_SCLN),  KC_QUOT,
		     KC_GRV,                      KC_Z,               KC_X,    KC_C,    KC_V,    KC_B, KC_GAMING,                                                       KC_MUTE, KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_BSLS,
                     _______,KC_LEFT_BRACKET, KC_RIGHT_BRACKET, KC_LOWER, KC_SPC,                                                     KC_ENT,  KC_RAISE, KC_LPRN, KC_RPRN, KC_PRINT_SCREEN
		     ),


  [_GAMING] = LAYOUT(
		     KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_BSPC_DEL,
		     KC_ESC,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_GRV,
		     KC_TAB,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L, KC_UP,  KC_QUOT,
		     KC_LAYER,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_GAMING,     KC_MUTE,KC_N,    KC_M, KC_COMM,  KC_LEFT, KC_DOWN,  KC_RIGHT,
		     KC_LGUI,KC_LALT,KC_LSFT, KC_LCTL, KC_SPC,      KC_ENT,  KC_RAISE, KC_RBRC, KC_MINS, KC_EQL
		     ),

  [_LOWER] = LAYOUT(
		    _______,      _______,    _______,    _______,    _______,   _______,                       _______,   _______,   _______,   _______,  _______,  _______,
		    _______,      KC_F1,      KC_F2,      KC_F3,      KC_F4, KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
		    _______,      KC_1,       KC_2,       KC_3,       KC_4, KC_5,                       KC_6,   KC_7,   KC_8,   KC_9,  KC_0,  KC_F12,
		    KC_CAPS_LOCK, XXXXXXX,    KC_MINUS,   KC_EQUAL,   KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE, _______,       _______, KC_LEFT_BRACKET, KC_RIGHT_BRACKET, KC_DEL, KC_END, KC_PGDN, XXXXXXX,
                    CG_TOGG, KC_RALT, _______, KC_RCTL, _______,       _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
		    ),

  [_RAISE] = LAYOUT(
		    _______, _______ , _______ , _______ , _______ , _______,                           QK_DYNAMIC_MACRO_RECORD_START_1,  QK_DYNAMIC_MACRO_RECORD_START_2  , QK_DYNAMIC_MACRO_RECORD_STOP,  _______ ,  _______ ,_______,
		    _______,  KC_INS,  KC_PSCR,   KC_APP,  XXXXXXX, XXXXXXX,                        KC_PGUP, KC_PRVWD,   KC_UP, KC_NXTWD,KC_MEDIA_PLAY_PAUSE, KC_BSPC,
		    _______, KC_LALT,  KC_LCTL,  KC_DEL,  XXXXXXX, KC_CAPS,                       KC_LEFT,  KC_DOWN, KC_UP, KC_RGHT,  KC_DEL, KC_BSPC,
		    _______,KC_UNDO, KC_CUT, KC_COPY, KC_PASTE, XXXXXXX,  _______,       _______,  XXXXXXX, KC_LSTRT, XXXXXXX, KC_LEND,   _______, _______,
		    _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
		    ),
  /* ADJUST
   * ,-----------------------------------------.                    ,-----------------------------------------.
   * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
   * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
   * | QK_BOOT|      |QWERTY|      |      |      |                    |      |      |      |      |      |      |
   * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
   * |      |      |MACWIN|      |      |      |-------.    ,-------|      | VOLDO| MUTE | VOLUP|      |      |
   * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
   * |      |      |      |      |      |      |-------|    |-------|      | PREV | PLAY | NEXT |      |      |
   * `-----------------------------------------/       /     \      \-----------------------------------------'
   *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
   *            |      |      |      |      |/       /         \      \ |      |      |      |      |
   *            `----------------------------------'           '------''---------------------------'
   */
  [_ADJUST] = LAYOUT(
		     XXXXXXX , XXXXXXX,  XXXXXXX ,  XXXXXXX , XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		     QK_BOOT, XXXXXXX,KC_QWERTY,XXXXXXX,CG_TOGG,XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		     XXXXXXX , XXXXXXX,CG_TOGG, XXXXXXX,    QK_BOOT,  XXXXXXX,                     XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,
		     XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,  XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
		     _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
		     )
};
// clang-format on

#ifdef OLED_ENABLE

/* 32 * 32 logo */
static void render_logo(void) {
  static const char PROGMEM arch_logo[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf8, 0xfc, 0xe0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xf8, 0xf8, 0xf3, 0xe7, 0xef, 0xff, 0xff, 0xff, 0xfe, 0xf8, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xe0, 0xf0, 0xfc, 0xff, 0xff, 0xff, 0x1f, 0x07, 0x03, 0x03, 0x03, 0x03, 0x07, 0x1f, 0xff, 0xff, 0xff, 0xfc, 0x78, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x18, 0x1e, 0x0f, 0x0f, 0x0f, 0x07, 0x07, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x07, 0x07, 0x0f, 0x0e, 0x0c, 0x1c, 0x18, 0x20, 0x00, 0x00};
  oled_write_raw_P(arch_logo, sizeof(arch_logo));
}

/* 32 * 14 os logos */

static const char PROGMEM arch_logo[] = {};

/* Smart Backspace Delete */

bool            shift_held = false;
static uint16_t held_shift = 0;

/* KEYBOARD PET START */

/* settings */
#    define MIN_WALK_SPEED 10
#    define MIN_RUN_SPEED 40

/* advanced settings */
#    define ANIM_FRAME_DURATION 200 // how long each frame lasts in ms
#    define ANIM_SIZE 96            // number of bytes in array. If you change sprites, minimize for adequate firmware size. max is 1024

/* timers */
uint32_t anim_timer = 0;

/* current frame */
uint8_t current_frame = 0;

/* status variables */
int   current_wpm = 0;
led_t led_usb_state;

bool isSneaking = false;
bool isJumping  = false;
bool showedJump = true;

/* logic */
static void render_luna(int LUNA_X, int LUNA_Y) {
  /* Sit */
  static const char PROGMEM sit[2][ANIM_SIZE] = {/* 'sit1', 32x22px */
    {
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c, 0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x68, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x06, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28, 0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },

    /* 'sit2', 32x22px */
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c, 0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x90, 0x08, 0x18, 0x60, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x0e, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28, 0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};

  /* Walk */
  static const char PROGMEM walk[2][ANIM_SIZE] = {/* 'walk1', 32x22px */
    {
      0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x10, 0x90, 0x90, 0x90, 0xa0, 0xc0, 0x80, 0x80, 0x80, 0x70, 0x08, 0x14, 0x08, 0x90, 0x10, 0x10, 0x08, 0xa4, 0x78, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x08, 0xfc, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x18, 0xea, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x03, 0x06, 0x18, 0x20, 0x20, 0x3c, 0x0c, 0x12, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },

    /* 'walk2', 32x22px */
    {
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x20, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x28, 0x10, 0x20, 0x20, 0x20, 0x10, 0x48, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x20, 0xf8, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x03, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x10, 0x30, 0xd5, 0x20, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e, 0x02, 0x1c, 0x14, 0x08, 0x10, 0x20, 0x2c, 0x32, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    }};

  /* Run */
  static const char PROGMEM run[2][ANIM_SIZE] = {/* 'run1', 32x22px */
    {
      0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x08, 0xc8, 0xb0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x40, 0x40, 0x3c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0xc4, 0xa4, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x58, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x09, 0x04, 0x04, 0x04, 0x04, 0x02, 0x03, 0x02, 0x01, 0x01, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00,
    },

    /* 'run2', 32x22px */
    {
      0x00, 0x00, 0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x78, 0x28, 0x08, 0x10, 0x20, 0x30, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 0xb0, 0x50, 0x55, 0x20, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x1e, 0x20, 0x20, 0x18, 0x0c, 0x14, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    }};

  /* Bark */
  static const char PROGMEM bark[2][ANIM_SIZE] = {/* 'bark1', 32x22px */
    {
      0x00, 0xc0, 0x20, 0x10, 0xd0, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x3c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x48, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },

    /* 'bark2', 32x22px */
    {
      0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x40, 0x2c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x48, 0x28, 0x2a, 0x10, 0x0f, 0x20, 0x4a, 0x09, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    }};

  /* Sneak */
  static const char PROGMEM sneak[2][ANIM_SIZE] = {/* 'sneak1', 32x22px */
    {
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x40, 0x40, 0x80, 0x00, 0x80, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x21, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x04, 0x04, 0x04, 0x03, 0x01, 0x00, 0x00, 0x09, 0x01, 0x80, 0x80, 0xab, 0x04, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x02, 0x06, 0x18, 0x20, 0x20, 0x38, 0x08, 0x10, 0x18, 0x04, 0x04, 0x02, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00,
    },

    /* 'sneak2', 32x22px */
    {
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xa0, 0x20, 0x40, 0x80, 0xc0, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x41, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x02, 0x04, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x04, 0x00, 0x40, 0x40, 0x55, 0x82, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e, 0x04, 0x18, 0x10, 0x08, 0x10, 0x20, 0x28, 0x34, 0x06, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
    }};

  /* animation */
  void animate_luna(void) {
    /* jump */
    if (isJumping || !showedJump) {
      /* clear */
      oled_set_cursor(LUNA_X, LUNA_Y + 2);
      oled_write("     ", false);

      oled_set_cursor(LUNA_X, LUNA_Y - 1);

      showedJump = true;
    } else {
      /* clear */
      oled_set_cursor(LUNA_X, LUNA_Y - 1);
      oled_write("     ", false);

      oled_set_cursor(LUNA_X, LUNA_Y);
    }

    /* switch frame */
    current_frame = (current_frame + 1) % 2;

    /* current status */
    if (led_usb_state.caps_lock) {
      oled_write_raw_P(bark[current_frame], ANIM_SIZE);

    } else if (isSneaking) {
      oled_write_raw_P(sneak[current_frame], ANIM_SIZE);

    } else if (current_wpm <= MIN_WALK_SPEED) {
      oled_write_raw_P(sit[current_frame], ANIM_SIZE);

    } else if (current_wpm <= MIN_RUN_SPEED) {
      oled_write_raw_P(walk[current_frame], ANIM_SIZE);

    } else {
      oled_write_raw_P(run[current_frame], ANIM_SIZE);
    }
  }

#    if OLED_TIMEOUT > 0
  /* the animation prevents the normal timeout from occuring */
  if (last_input_activity_elapsed() > OLED_TIMEOUT && last_led_activity_elapsed() > OLED_TIMEOUT) {
    oled_off();
    return;
  } else {
    oled_on();
  }
#    endif

  /* animation timer */
  if (timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
    anim_timer = timer_read32();
    animate_luna();
  }
}

/* KEYBOARD PET END */

static void print_logo_narrow(void) {
  render_logo();

  /* wpm counter */
  uint8_t n = get_current_wpm();
  char    wpm_str[4];
  oled_set_cursor(0, 14);
  wpm_str[3] = '\0';
  wpm_str[2] = '0' + n % 10;
  wpm_str[1] = '0' + (n /= 10) % 10;
  wpm_str[0] = '0' + n / 10;
  oled_write(wpm_str, false);

  oled_set_cursor(0, 15);
  oled_write(" wpm", false);
}

static void print_status_narrow(void) {
  /* Print current mode */
  oled_set_cursor(0, 0);
  oled_write_raw_P(arch_logo, sizeof(arch_logo));

  oled_set_cursor(0, 3);

  switch (get_highest_layer(default_layer_state)) {
  case _QWERTY:
    oled_write("QWRTY", false);
    break;
  case _GAMING:
    oled_write("GAMES", false);
    break;
  default:
    oled_write("UNDEF", false);
  }

  oled_set_cursor(0, 5);

  /* Print current layer */
  oled_write("LAYER", false);

  oled_set_cursor(0, 6);

  switch (get_highest_layer(layer_state)) {
  case _QWERTY:
    oled_write("Base ", false);
    break;
  case _GAMING:
    oled_write("Games", false);
    break;
  case _RAISE:
    oled_write("Raise", false);
    break;
  case _LOWER:
    oled_write("Lower", false);
    break;
  case _ADJUST:
    oled_write("Adj  ", false);
    break;
  default:
    oled_write("Undef", false);
  }

  /* caps lock */
  oled_set_cursor(0, 8);
  oled_write("CPSLK", led_usb_state.caps_lock);

  /* KEYBOARD PET RENDER START */

  render_luna(0, 13);

  /* KEYBOARD PET RENDER END */
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  return OLED_ROTATION_270;
}

bool oled_task_user(void) {
  /* KEYBOARD PET VARIABLES START */

  current_wpm   = get_current_wpm();
  led_usb_state = host_keyboard_led_state();

  /* KEYBOARD PET VARIABLES END */

  if (is_keyboard_master()) {
    print_status_narrow();
  } else {
    print_logo_narrow();
  }
  return false;
}

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case KC_QWERTY:
    if (record->event.pressed) {
      set_single_persistent_default_layer(_QWERTY);
    }
    return false;
  case KC_GAMING:
    if (record->event.pressed) {
      if (get_highest_layer(default_layer_state) == _QWERTY) {
	set_single_persistent_default_layer(_GAMING);
      } else if (get_highest_layer(default_layer_state) == _GAMING) {
	set_single_persistent_default_layer(_QWERTY);
      }
    }
    return false;
  case KC_LOWER:
    if (record->event.pressed) {
      layer_on(_LOWER);
      update_tri_layer(_LOWER, _RAISE, _ADJUST);
    } else {
      layer_off(_LOWER);
      update_tri_layer(_LOWER, _RAISE, _ADJUST);
    }
    return false;
  case KC_RAISE:
    if (record->event.pressed) {
      layer_on(_RAISE);
      update_tri_layer(_LOWER, _RAISE, _ADJUST);
    } else {
      layer_off(_RAISE);
      update_tri_layer(_LOWER, _RAISE, _ADJUST);
    }
    return false;
  case KC_ADJUST:
    if (record->event.pressed) {
      layer_on(_ADJUST);
    } else {
      layer_off(_ADJUST);
    }
    return false;
  case KC_PRVWD:
    if (record->event.pressed) {
      if (keymap_config.swap_lctl_lgui) {
	register_mods(mod_config(MOD_LALT));
	register_code(KC_LEFT);
      } else {
	register_mods(mod_config(MOD_LCTL));
	register_code(KC_LEFT);
      }
    } else {
      if (keymap_config.swap_lctl_lgui) {
	unregister_mods(mod_config(MOD_LALT));
	unregister_code(KC_LEFT);
      } else {
	unregister_mods(mod_config(MOD_LCTL));
	unregister_code(KC_LEFT);
      }
    }
    break;
  case KC_NXTWD:
    if (record->event.pressed) {
      if (keymap_config.swap_lctl_lgui) {
	register_mods(mod_config(MOD_LALT));
	register_code(KC_RIGHT);
      } else {
	register_mods(mod_config(MOD_LCTL));
	register_code(KC_RIGHT);
      }
    } else {
      if (keymap_config.swap_lctl_lgui) {
	unregister_mods(mod_config(MOD_LALT));
	unregister_code(KC_RIGHT);
      } else {
	unregister_mods(mod_config(MOD_LCTL));
	unregister_code(KC_RIGHT);
      }
    }
    break;
  case KC_LSTRT:
    if (record->event.pressed) {
      if (keymap_config.swap_lctl_lgui) {
	/* CMD-arrow on Mac, but we have CTL and GUI swapped */
	register_mods(mod_config(MOD_LCTL));
	register_code(KC_LEFT);
      } else {
	register_code(KC_HOME);
      }
    } else {
      if (keymap_config.swap_lctl_lgui) {
	unregister_mods(mod_config(MOD_LCTL));
	unregister_code(KC_LEFT);
      } else {
	unregister_code(KC_HOME);
      }
    }
    break;
  case KC_LEND:
    if (record->event.pressed) {
      if (keymap_config.swap_lctl_lgui) {
	/* CMD-arrow on Mac, but we have CTL and GUI swapped */
	register_mods(mod_config(MOD_LCTL));
	register_code(KC_RIGHT);
      } else {
	register_code(KC_END);
      }
    } else {
      if (keymap_config.swap_lctl_lgui) {
	unregister_mods(mod_config(MOD_LCTL));
	unregister_code(KC_RIGHT);
      } else {
	unregister_code(KC_END);
      }
    }
    break;
  case KC_DLINE:
    if (record->event.pressed) {
      register_mods(mod_config(MOD_LCTL));
      register_code(KC_BSPC);
    } else {
      unregister_mods(mod_config(MOD_LCTL));
      unregister_code(KC_BSPC);
    }
    break;
  case KC_COPY:
    if (record->event.pressed) {
      register_mods(mod_config(MOD_LCTL));
      register_code(KC_C);
    } else {
      unregister_mods(mod_config(MOD_LCTL));
      unregister_code(KC_C);
    }
    return false;
  case KC_PASTE:
    if (record->event.pressed) {
      register_mods(mod_config(MOD_LCTL));
      register_code(KC_V);
    } else {
      unregister_mods(mod_config(MOD_LCTL));
      unregister_code(KC_V);
    }
    return false;
  case KC_CUT:
    if (record->event.pressed) {
      register_mods(mod_config(MOD_LCTL));
      register_code(KC_X);
    } else {
      unregister_mods(mod_config(MOD_LCTL));
      unregister_code(KC_X);
    }
    return false;
    break;
  case KC_UNDO:
    if (record->event.pressed) {
      register_mods(mod_config(MOD_LCTL));
      register_code(KC_Z);
    } else {
      unregister_mods(mod_config(MOD_LCTL));
      unregister_code(KC_Z);
    }
    return false;

    /* Smart Backspace Delete */

  case KC_RSFT:
  case KC_LSFT:
    shift_held = record->event.pressed;
    held_shift = keycode;
    break;
  case KC_BSPC_DEL:
    if (record->event.pressed) {
      if (shift_held) {
	unregister_code(held_shift);
	register_code(KC_DEL);
      } else {
	register_code(KC_BSPC);
      }
    } else {
      unregister_code(KC_DEL);
      unregister_code(KC_BSPC);
      if (shift_held) {
	register_code(held_shift);
      }
    }
    return false;

    /* LAYER */

  case KC_LAYER:
    if (record->event.pressed) {
      if (shift_held) {
	if (record->event.pressed) {
	  if (get_highest_layer(default_layer_state) == _QWERTY) {
	    set_single_persistent_default_layer(_GAMING);
	  } else if (get_highest_layer(default_layer_state) == _GAMING) {
	    set_single_persistent_default_layer(_QWERTY);
	  }
	}
      } else {
	layer_on(_LOWER);
	update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
    } else {
      layer_off(_LOWER);
      update_tri_layer(_LOWER, _RAISE, _ADJUST);
    }
    return false;

    /* KEYBOARD PET STATUS START */

  case KC_LCTL:
  case KC_RCTL:
    if (record->event.pressed) {
      isSneaking = true;
    } else {
      isSneaking = false;
    }
    break;
  case KC_SPC:
    if (record->event.pressed) {
      isJumping  = true;
      showedJump = false;
    } else {
      isJumping = false;
    }
    break;

    /* KEYBOARD PET STATUS END */
  }
  return true;
}

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) {
    if (!clockwise) {
      register_code(KC_LGUI);

      register_code(KC_U);
      unregister_code(KC_U);

      unregister_code(KC_LGUI);
    } else {
      register_code(KC_LSFT);
      register_code(KC_LGUI);

      register_code(KC_U);
      unregister_code(KC_U);

      unregister_code(KC_LGUI);
      unregister_code(KC_LSFT);
    }
  } else if (index == 1) {
    tap_code(clockwise ? KC_KB_VOLUME_DOWN : KC_KB_VOLUME_UP);
  }
  return false;
}

#endif
