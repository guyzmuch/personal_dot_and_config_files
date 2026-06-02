#include QMK_KEYBOARD_H
#include "keymap_bepo.h"

enum layers {
    BASE = 0,
    FN_NUM = 1,
};

#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* BASE — Bépo (layer 0 in Configurator) */
    [BASE] = LAYOUT_ergodox(
        // left hand — rows 1–4 + bottom row + thumb
        KC_ESC,   BP_DQUO,  BP_LDAQ,  BP_RDAQ,  BP_LPRN,  BP_RPRN,  KC_DEL,
        KC_TAB,   BP_B,     BP_EACU,  BP_P,     BP_O,     BP_EGRV,  KC_BSPC,
        KC_LSFT,  BP_A,     BP_U,     BP_I,     BP_E,     BP_COMM,
        KC_LCTL,  BP_AGRV,  BP_Y,     BP_X,     BP_DOT,   BP_K,     KC_ENT,
        KC_LCTL,  KC_LALT,  BP_DLR,   KC_LEFT,  KC_RGHT,
                                              LCTL(BP_C),  LCTL(BP_V),
                                                              KC_LGUI,
                                               KC_SPC,  KC_LSFT,  MO(FN_NUM),
        // right hand
        KC_DEL,   BP_AT,    BP_PLUS,  BP_MINS,  BP_SLSH,  BP_ASTR,  BP_EQL,
        KC_BSPC,  BP_DCIR,  BP_V,     BP_D,     BP_L,     BP_J,     BP_Z,
                 BP_C,     BP_T,     BP_S,     BP_R,     BP_N,     BP_M,
        KC_ENT,    BP_QUOT,  BP_Q,     BP_G,     BP_H,     BP_F,     BP_W,
                        KC_UP,    KC_DOWN,  BP_PERC,  KC_RALT,  KC_RCTL,
        KC_HOME,  KC_END,
        KC_PGUP,
        KC_PGDN,  KC_RSFT,  KC_SPC
    ),

    /* FN_NUM — F-keys, media, numpad (layer 1) */
    [FN_NUM] = LAYOUT_ergodox(
        // left hand
        _______,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    _______,
        _______,   XXXXXXX,  KC_VOLD,  KC_VOLU,  KC_MUTE,  XXXXXXX,  _______,
        _______,  XXXXXXX,  KC_MPRV,  KC_MNXT,  KC_MPLY,  XXXXXXX,
        _______,  XXXXXXX,  KC_BRID,  KC_BRIU,  KC_SYRQ,  XXXXXXX,  _______,
        _______,  _______,  _______,   _______,  _______,
                                              _______,  _______,
                                                              AS_TOGG,
                                               _______,  _______,  TO(BASE),
        // right hand
        _______,   KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_NUM,
        _______,  KC_PSLS,  KC_P7,    KC_P8,    KC_P9,    KC_PMNS,  KC_PENT,
                 KC_PAST,  KC_P4,    KC_P5,    KC_P6,    KC_PPLS,  KC_PENT,
                 _______,  BP_DOT,  KC_P1,    KC_P2,    KC_P3,    BP_PERC,  KC_PENT,
                          KC_P0,    XXXXXXX,   XXXXXXX,  _______,  _______,
        _______,  _______,
        _______,
        _______,  _______,  _______
    ),
};
