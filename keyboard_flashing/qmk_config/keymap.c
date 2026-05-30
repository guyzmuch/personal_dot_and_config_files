#include QMK_KEYBOARD_H

// Déclaration des layers
enum layers {
    BASE = 0,    // Layer de base (bépo)
    FN_NUM = 1,  // Layer Fn/num (fonctions + numpad)
    MAC = 2      // Layer Mac
};

// --- Macros personnalisées ---
#define AS_UP AS_UP              // Autoshift (nécessite AUTOSHIFT_ENABLE dans config.h)
#define CMD_LEFT  LGUI(KC_LEFT)   // Cmd + ← (début de ligne Mac)
#define CMD_RIGHT LGUI(KC_RIGHT)  // Cmd + → (fin de ligne Mac)
#define MIC_TOG   LGUI(LALT(KC_M)) // Raccourci universel Mac pour mute/unmute le micro (Cmd+Option+M)
#define DOT_MAC   S(KC_DOT)      // Maj + . pour forcer un point (au lieu de la virgule Mac)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* =========================================================================
     * LAYER BASE (0) - Bépo + MO(FN_NUM) sur le pouce droit
     * =========================================================================
     */
    [BASE] = LAYOUT_ergodox(
        // Main gauche
        KC_ESC,   KC_TAB,  KC_B,    KC_EACU, KC_P,    KC_O,    KC_DEL,
        KC_UP,    KC_A,    KC_U,    KC_I,    KC_E,    KC_COMM,
        KC_LCTL,  KC_AGRV, KC_Y,    KC_X,    KC_DOT,  KC_K,
        KC_LCTL,  KC_LGUI, KC_DLR,  KC_LEFT, KC_RGHT, _______,
        KC_LCTL,  KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,

        // Main droite
        KC_DEL,   KC_AT,   KC_PLUS, KC_MINS, KC_SLSH, KC_ASTR, KC_EQL,
        KC_HOME,  KC_V,    KC_D,    KC_L,    KC_J,    KC_Z,
        KC_END,   KC_C,    KC_T,    KC_S,    KC_R,    KC_N,    KC_M,
        _______,  KC_PERC, KC_RGUI, _______, _______, _______,
        MO(FN_NUM), KC_END, KC_PGUP, KC_PGDN  // <-- MO(FN_NUM) ici : maintient pour activer temporairement FN_NUM
    ),

    /* =========================================================================
     * LAYER FN_NUM (1) - Numpad + point accessible
     * =========================================================================
     */
    [FN_NUM] = LAYOUT_ergodox(
        // Main gauche
        KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_DEL,
        KC_TAB,   KC_GRV,  KC_LEFT, KC_MPLY, KC_MPRV, KC_MNXT,
        KC_LCTL,  KC_BRMD, KC_BRIU, KC_SYSRQ, KC_BSPC, _______,
        KC_LCTL,  KC_DLR,  KC_LEFT, KC_RGHT,  _______, _______,
        KC_LCTL,  KC_LGUI, KC_LALT, AS_UP,    KC_BSPC,

        // Main droite
        KC_DEL,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_NLCK,
        KC_HOME,  KC_SLSH, KC_7,    KC_8,    KC_9,    KC_MINS,
        KC_END,   KC_ASTR, KC_4,    KC_5,    KC_6,    KC_PLUS,
        _______,  KC_0,    DOT_MAC, KC_COMM, _______, _______,  // <-- DOT_MAC pour un point (au lieu de virgule)
        KC_HOME,  KC_END,  KC_PGUP, KC_PGDN
    )
};