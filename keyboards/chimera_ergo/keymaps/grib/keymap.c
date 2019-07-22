// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include "chimera_ergo.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum chimera_ergo_layers
{
	_QWERTY,
	_VIMISH,
	_YTREWQ,
	_CAPS,
	_A11Y,
	_NUMPAD,
	_SYMBOLS,
	_MACROS,
	_NAV
};
																										
#define KC_LLCT LCTL_T(KC_LBRC)
#define KC_SALT MT(MOD_LALT, KC_SPC)
#define KC_LSPC LT(_CAPS, KC_SPC)
#define KC_RSLA LT(_NUMPAD, KC_BSLS)
#define KC_RENT LCTL_T(KC_ENT)
#define KC_RRCT RGUI_T(KC_RBRC)
#define KC_RQUO SFT_T(KC_QUOT)
#define KC_LQUO SFT_T(KC_GRV)
#define KC_XALT ALT_T(KC_Z)
#define KC_INCL M(0)
#define KC_PULL M(1)
#define KC_PUSH M(2)
#define KC_SCAP M(3)
#define KC_SCOF M(4)
#define KC_CAD LALT(LCTL(KC_DEL))
#define KC_LTAB LT(_VIMISH, KC_TAB)



#define LONGPRESS_DELAY 100
#define LAYER_TOGGLE_DELAY 300



// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define KC_ KC_TRNS 

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = KC_KEYMAP(
  //,----+----+----+----+----+----.     ,----+----+----+----+----+----.
     BSPC, 1  ,2   ,3   ,4   , 5  ,       6  ,7   ,8   ,9   , 0  ,BSPC,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
     LTAB, Q  , W  , E  , R  , T  ,       Y  , U  , I  , O  , P  ,RSLA,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
     LQUO, A  , S  , D  , F  , G  ,       H  , J  , K  , L  ,SCLN,RQUO,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
     LLCT,XALT, X  , C  , V  , B  ,       N  , M  ,COMM,DOT ,SLSH,RRCT,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
                         LSPC,LGUI,      RENT,SALT
  // \------------------+----+----/      \---+----+----+--------------/
  ),
    [_A11Y] = KC_KEYMAP(
  //,----+----+----+----+----+----.     ,----+----+----+----+----+----.
     BSPC, 1  ,2   ,3   ,4   , 5  ,       6  ,7   ,8   ,9   , 0  ,BSPC,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
     LTAB, Q  , W  , E  , R  , T  ,       Y  , U  , I  , O  , P  ,RSLA,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
     LQUO, A  , S  , D  , F  , G  ,       H  , J  , K  , L  ,SCLN,RQUO,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
     LLCT,XALT, X  , C  , V  , B  ,       N  , M  ,COMM,DOT ,SLSH,RRCT,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
                         LSPC,LGUI,      RENT,SALT
  // \------------------+----+----/      \---+----+----+--------------/
  ),	
  [_VIMISH] = KC_KEYMAP(
  //,----+----+----+----+----+----.     ,----+----+----+----+----+----.
     ESC , 1  ,2   ,3   ,4   , 5  ,       6  ,7   ,8   ,9   ,0   ,MINS,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
     LTAB, Q  ,WH_D,MS_U,WH_U, T  ,       Y  ,PGDN,PGUP, O  , P  ,RSLA,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
     LQUO, A  ,MS_L,MS_D,MS_R, G  ,      LEFT,DOWN, UP ,RGHT,SCLN,RQUO,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
     LLCT,ACL0,ACL1,ACL2,BTN4,BTN3,       N  , M  ,COMM,DOT ,SLSH,RRCT,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
                         BTN2,BTN1,      RENT,SALT
  // \------------------+----+----/      \---+----+----+--------------/
  ),
  [_YTREWQ] = KC_KEYMAP(
  //,----+----+----+----+----+----.     ,----+----+----+----+----+----.
     BSPC, 0  ,9   ,8   ,7   , 6  ,       6  ,7   ,8   ,9   , 0  ,BSPC,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
     RSLA, P  , O  , I  , U  , Y  ,       Y  , U  , I  , O  , P , RQUO,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
     RQUO,SCLN, L  , K  , J  , H  ,       H  , J  , K  , L  ,SCLN,RSPC,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
     RRCT,SLSH,DOT ,COMM, M  , N  ,       N  , M  ,COMM,DOT ,SLSH,RRCT,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
                         LSPC,RENT,      RENT,SALT
  // \------------------+----+----/      \---+----+----+--------------/
  ),
  [_NUMPAD] = KC_KEYMAP(
  //,----+----+----+----+----+----.     ,----+----+----+----+----+----.
    VOLD, VOLU,MRWD,MPLY,MFFD,    ,          , 7  , 8  , 9  ,SLSH,    ,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
         ,EXLM,AT  ,LCBR,RCBR,PIPE,          , 4  , 5  , 6  ,ASTR,    ,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
         ,HASH,DLR ,LPRN,RPRN,GRV ,          , 1  , 2  , 3  ,MINS,    ,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
         ,PERC,CIRC,LBRC,RBRC,TILD,          , 0  ,EQL ,DOT ,PLUS,    ,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
                             ,    ,          ,
  // \------------------+----+----/      \---+----+----+--------------/
  ),
  [_CAPS] = KC_KEYMAP(
  //,----+----+----+----+----+----.     ,----+----+----+----+----+----.
         ,UNDS,    ,    ,    ,    ,          ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
         ,    ,    ,AT  ,    ,    ,          ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,          ,    ,    ,    ,COLN,    ,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
     SCOF,    ,    ,    ,    ,    ,          ,    ,    ,    ,    ,SCOF,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
                             ,    ,          ,
  // \------------------+----+----/      \---+----+----+--------------/
  ),

  [_SYMBOLS] = KC_KEYMAP(
  //,----+----+----+----+----+----.     ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,          ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
         ,EXLM, AT ,HASH,DLR ,PERC,      CIRC,AMPR,ASTR,LPRN,RPRN,BSLS,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
      F1 , F2 , F3 , F4 , F5 , F6 ,      TILD,EQL ,UNDS,LCBR,RCBR,    ,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
      F7 , F8 , F9 ,F10 ,F11 ,F12 ,      GRV ,PLUS,MINS,LBRC,RBRC,    ,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
                         PIPE,    ,          ,
  // \------------------+----+----/      \---+----+----+--------------/
  ),

  [_MACROS] = KC_KEYMAP(  
  //,----+----+----+----+----+----.     ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,          ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,          ,    ,INCL,    ,    ,    ,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
         ,    ,    ,CAD ,    ,    ,          ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
     SCAP,    ,    ,    ,    ,    ,          ,    ,PULL,PUSH,    ,    ,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
                             ,    ,          ,    
  // \------------------+----+----/      \---+----+----+--------------/
  ),

  [_NAV] = KC_KEYMAP(  
  //,----+----+----+----+----+----.     ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,          ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,          ,PGUP, UP ,PGDN,PSCR,    ,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,          ,LEFT,DOWN,RGHT,    ,    ,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,          ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
                             ,DEL ,          ,    
  // \------------------+----+----/      \---+----+----+--------------/
  ),


};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch(id) {
    /* include some kind of library or header */
    case 0:
      if (record->event.pressed) {
        SEND_STRING("#include <>");
        return MACRO( T(LEFT), END);
      }
      break;
    case 1:
      if (record->event.pressed) {
        SEND_STRING("git pull");
        return MACRO( T(ENT), END );
      }
      break;
    case 2:
      if (record->event.pressed){
        SEND_STRING("git push");
        return MACRO( T(ENT), END );
      }
      break;
    case 3:
      if (record->event.pressed){
        layer_on(_CAPS);
        register_code(KC_CAPSLOCK);
        unregister_code(KC_CAPSLOCK);
      }
      break;
    case 4:
      if (record->event.pressed){
        layer_off(_CAPS);
        register_code(KC_CAPSLOCK);
        unregister_code(KC_CAPSLOCK);
      }
      break;
  }
  return MACRO_NONE;
};
 

void matrix_scan_user(void) {
    uint8_t layer = biton32(layer_state);
    
    switch (layer) {
    	case _QWERTY:
    	    set_led_green;
    	    break;
        case _CAPS:
	    set_led_white;
	    break;
        case _NUMPAD:
            set_led_blue;
            break;
        case _SYMBOLS:
            set_led_red;
            break;
        case _NAV:
	    set_led_magenta;
	    break;
        case _MACROS:
	    set_led_cyan;
	    break;
       default:
            set_led_green;
            break;
    }
};
