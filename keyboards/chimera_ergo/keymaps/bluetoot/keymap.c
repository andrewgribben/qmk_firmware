// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include "chimera_ergo.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum chimera_ergo_layers
{
	_START,
	_VIMISH,
	_YTREWQ,
	_NUMPAD,

};
																										

#define KC_GCOM M(0)
#define KC_PULL M(1)
#define KC_PUSH M(2)
#define KC_GADD M(3)
#define KC_UHOM M(4)


#define KC_L0 MO(_VIMISH)
#define KC_L2 TO(_VIMISH)
#define KC_L1 OSL(_YTREWQ)
#define KC_L4 TO(_NUMPAD)
#define KC_L5 OSL(_NUMPAD)
#define KC_RESET TO(_START)


#define LONGPRESS_DELAY 100
#define LAYER_TOGGLE_DELAY 300

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define KC_ KC_TRNS 

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


  [_START] = KC_KEYMAP(
  //,----+----+----+----+----+----.     ,----+----+----+----+----+----.
     L0, 1  ,2   ,3   ,4   , 5  ,       6  ,7   ,8   ,9   , 0  ,BSPC,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
     TAB, Q  , W  , E  , R  , T  ,       Y  , U  , I  , O  , P  ,BSLS,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
     LSFT, A  , S  , D  , F  , G  ,       H  , J  , K  , L  ,SCLN, RSFT,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
     LCTL, Z,   X  , C  , V  , B  ,         N  , M  ,COMM,DOT ,SLSH,QUOT,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
                         SPC, LGUI,      ENT,SPC
  // \------------------+----+----/      \---+----+----+--------------/
),
  [_VIMISH] = KC_KEYMAP(
  //,----+----+----+----+----+----.     ,----+----+----+----+----+----.
     RESET,L1, L2,    ,  L4,   L5,      VOLD,VOLU,MPLY,MRWD,MFFD,ESC,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
     GRV ,   ,WH_D,MS_U,WH_U,PIPE,           ,PGDN,PGUP,    ,    ,LBRC,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
     LSFT ,   ,MS_L,MS_D,MS_R,TILD,       LEFT,DOWN,UP ,RGHT,SCLN,RBRC,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
     LCTL,LALT,   ,  C  ,BTN4,BTN3,         ,    ,COMM,DOT ,SLSH,QUOT,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
                         BTN2,BTN1,      ENT,SPC
  // \------------------+----+----/      \---+----+----+--------------/
  ),

  [_YTREWQ] = KC_KEYMAP(
  //,----+----+----+----+----+----.     ,----+----+----+----+----+----.
     BSPC, 0  ,9   ,8   ,7   , 6  ,         , ,   ,   ,  , ,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
     BSLS, P  , O  , I  , U  , Y  ,         , ,   ,   ,  , ,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
     QUOT,SCLN, L  , K  , J  , H  ,       ,   ,   ,   ,,,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
     RSFT,SLSH,DOT ,COMM, M  , N  ,       ,   ,, ,,,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
                         SPC,ENT,      ,
  // \------------------+----+----/      \---+----+----+--------------/
  ),

  [_NUMPAD] = KC_KEYMAP(
  //,----+----+----+----+----+----.     ,----+----+----+----+----+----.
    RESET,GADD,GCOM,PULL,PUSH,UHOM,          , 7  , 8  , 9  ,SLSH,    ,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
         ,EXLM, AT ,HASH,DLR ,PERC,          , 4  , 5  , 6  ,ASTR,    ,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
      F1 , F2 , F3 , F4 , F5 , F6,           , 1  , 2  , 3  ,MINS,    ,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
      F7 , F8 , F9 ,F10 ,F11 ,F12 ,          , 0  ,EQL ,DOT ,PLUS,    ,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
                         PIPE,GRV,        ENT,SPC
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
        SEND_STRING("git commit -m");
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
        SEND_STRING("git add .");
        return MACRO( T(ENT), END );
      }
      break;
    case 4:
      if (record->event.pressed){
        SEND_STRING("cd ~/");
        return MACRO( T(ENT), END );
      }
      break;


  }
  return MACRO_NONE;
};
 

void matrix_scan_user(void) {
    uint8_t layer = biton32(layer_state);
    
    switch (layer) {
    	case _START:
    	    set_led_magenta;
    	    break;
        case _NUMPAD:
            set_led_blue;
            break;
        case _YTREWQ:
            set_led_red;
            break;
        case _VIMISH:
	    set_led_cyan;
	    	break;
       default:
            set_led_magenta;
            break;
    }
};
