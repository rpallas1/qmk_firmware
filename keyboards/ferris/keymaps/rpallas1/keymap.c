#include QMK_KEYBOARD_H

// MacOS macros
#define SC_SHOT SGUI(KC_4)
#define SC_SHOT_APP SGUI(KC_5)
#define SPTL LGUI(KC_SPACE)
#define APP_SWITCH LGUI(KC_TAB)
#define WINDOW_SWITCH LGUI(KC_GRAVE)

// Browser navigation
#define TAB_R LCTL(KC_TAB)
#define TAB_L LCTL(LSFT(KC_TAB))
#define BR_BACK LGUI(KC_LEFT)
#define BR_FWD LGUI(KC_RIGHT)

enum tap_dance_codes {
    /*
     * Single tap: Types a period
     * Hold: Types an exclamation mark
     * Double tap: Types two periods
     * Triple tap: Types three periods
     */
    DANCE_1,

    /*
     * Single tap: Types a comma
     * Hold: Types a hypen/minus
     * Double tap: Types two commas
     * Triple tap: Types three commas
     */
    DANCE_2,

    /*
     * Single tap: Types a slash
     * Hold: Types a dash/underscore
     * Double tap: Types two slashes
     * Triple tap: Types three slashes
     */
    DANCE_3,

    /*
     * Single tap: Types a space
     * Hold: Types an underscore
     * Double tap: Types two spaces
     * Triple tap: Types three spaces
     */
    DANCE_15,

    /*
     * Single tap; Types a dollar sign
     * Hold: Executes CMD+SHIFT+4 (screenshot shortcut on Mac)
     * Double/triple tap: Types multiple dollar signs
     */
    DANCE_31,

    /*
     * Single tap: Types a single quote
     * Hold: Execute CMD+' (special Mac shortcut)
     * Double tap: Types a backtick
     * Triple tap: Types multiple single quotes
     */
    DANCE_32,

    /*
     * Single tap: Types LSFT+5 (%)
     * Hold: Execumtes Command+Shift+5 (screen grab shortcut on Mac)
     * Double/triple tap: Types the character multiple times
     */
    DANCE_33,

    /*
     * Single tap: Types Escape key
     * Hold: ALT+CMD+ESC (force quit on Mac)
     * Double tap: Types Escape twice
     */
    DANCE_54,

    /*
     * Single tap: Types "q"
     * Hold: Types "h"
     * Double/triple tap: Types "q" multiple times
     */
    DANCE_55,

    /*
     * Single tap: Types tab
     * Hold: Types CMD+tab (App switcher on Mac)
     * Double tap: Types tab twice
     */
    DANCE_56,

    /*
     * Single tap: Outputs a Delete key
     * Hold: Outputs CTRL+K (delete line on Mac)
     * Double tap: Outputs two Delete key presses
     * Triple tap: Outputs three Delete key presses
     */
    DANCE_57,

    /*
     * Singe tap: Outputs a backtick/grave accent character
     * Hold: Ouputs Command+Grave, used for switching between windows of the same application on macOS
     * Double tap: Outputs two backtick characters
     * Triple tap: Outputs three backtick characters
     */
    DANCE_58,

    /*
     * Single tap: Outputs a space character
     * Hold: Outputs Command+O, opens the "Open file" dialog in most applications on macOS
     * Double tap: Outputs two spaces
     * Triple tap: Outputs three spaces
     */
    DANCE_59,

    /*
     * Single tap: Outputs a left arrow key press
     * Hold: Outputs Alt+Left, in browsers, this navigates to the previous page
     * Double tap: Outputs two left arrow key presses
     * Triple tap: Outputs three left arrow key presses
     */
    DANCE_60,

    /*
     * Single tap: Outputs a right arrow key press, used for normal cursor navigation to the right
     * Hold: Output CMD+RIGHT (macOS) using LGUI(KC_RIGHT), moves the cursor the the end of the current line
     * Double tap: Outputs two right arrow key presses
     * Triple tap: Outputs three right arrow key presses
     * More than three taps: Outputs additional right arrow key presses
     */
    DANCE_63,

    /*
     * Single tap: Types backslash
     * Hold: Home key (navigation to beginning)
     * Double tap: Types backslash twice
     */
    BKSL_HME,

    /*
     * Single tap: Types pipe
     * Hold: End key (navigation to end)
     * Double tap: Types pipe twice
     */
    PIPE_END,

    // ----- Self defined -----
    /*
     * Single tap: Next track
     * Double tap: Previous track
     */
    PREV_NEXT,

    /*
     * Single tap: Full page screenshot
     * Hold: Open screenshot app
     */
    SCRN_SHOT,
};

enum layers {
    BASE,
    SYM,
    NUM,
    NAV,
    OTHER,
};

enum combos { LU_ESC, FP_WRITE, CD_COLON };

enum custom_keycodes { VIM_SAVE = SAFE_RANGE };

/*
 * Other methods
 * - MT(modifier, key): Momentary toggle, holds the modifier while the key is pressed
 * - OSM(modifier): One shot modifier, holds the modifier until the next key is pressed
 * - TO(layer): Toggle to layer
 */

// 3x5_2 Layout
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Colemak DH Layout
    [BASE] = LAYOUT(KC_Q, KC_W, KC_F, KC_P, KC_B, /*|----|*/ KC_J, KC_L, KC_U, KC_Y, KC_BSPC,
                    // -------
                    KC_A, KC_R, MT(MOD_LALT, KC_S), MT(MOD_LGUI, KC_T), KC_G, /*|----|*/ KC_M, MT(MOD_RGUI, KC_N), MT(MOD_RALT, KC_E), KC_I, KC_O,
                    // -------
                    KC_Z, KC_X, KC_C, KC_D, KC_V, /*|----|*/ KC_K, KC_H, TD(DANCE_2), TD(DANCE_1), TD(DANCE_3),
                    // -------
                    MT(MOD_HYPR, KC_SPACE), OSM(MOD_RCTL), /*|----|*/ OSM(MOD_LSFT), TO(SYM)),

    [SYM] = LAYOUT(KC_ESC, KC_DLR, KC_PERC, KC_PLUS, KC_HASH, /*|----|*/ KC_CIRC, KC_EXLM, KC_AMPR, KC_PIPE, KC_BSPC,
                   // -------
                   KC_TAB, KC_MINS, MT(MOD_LALT, KC_EQL), MT(MOD_LGUI, KC_DQUO), KC_GRAVE, /*|----|*/ KC_BSLS, KC_LCBR, KC_RCBR, KC_ASTR, KC_ENTER,
                   // -------
                   KC_CAPS, KC_SCLN, KC_COLN, KC_QUOTE, KC_AT, /*|----|*/ KC_LBRC, KC_LPRN, KC_RPRN, KC_RBRC, TO(NAV),
                   // -------
                   TO(BASE), MT(MOD_HYPR, KC_SPACE), /*|----|*/ OSM(MOD_LSFT), TO(NUM)),

    [NUM] = LAYOUT(KC_ESC, KC_BRID, KC_BRIU, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, /*|----|*/ KC_PERC, KC_7, KC_8, KC_9, KC_BSPC,
                   // -------
                   KC_TAB, KC_MEDIA_PLAY_PAUSE, KC_PLUS, KC_MINS, KC_DOT, /*|----|*/ KC_EQL, KC_4, KC_5, KC_6, KC_ENTER,
                   // -------
                   TD(PREV_NEXT), KC_MUTE, KC_ASTR, KC_SLSH, TD(SCRN_SHOT), /*|----|*/ KC_0, KC_1, KC_2, KC_3, TO(NAV),
                   // -------
                   TO(BASE), MT(MOD_HYPR, KC_SPACE), /*|----|*/ OSM(MOD_LSFT), TO(SYM)),

    [NAV] = LAYOUT(BR_BACK, BR_FWD, TAB_L, TAB_R, XXXXXXX, /*|----|*/ XXXXXXX, KC_WH_U, KC_WH_D, XXXXXXX, KC_BSPC,
                   // ------
                   OSM(MOD_LSFT), OSM(MOD_LCTL), OSM(MOD_LALT), OSM(MOD_LGUI), XXXXXXX, /*|----|*/ KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_ENTER,
                   // ------
                   XXXXXXX, WINDOW_SWITCH, APP_SWITCH, SPTL, XXXXXXX, /*|----|*/ KC_HOME, XXXXXXX, XXXXXXX, KC_END, MO(OTHER),
                   // ------
                   TO(BASE), MT(MOD_HYPR, KC_SPACE), /*|----|*/ KC_TAB, TO(NUM)),

    // ---- REFERENCE ----
    [5] = LAYOUT(TD(DANCE_54), KC_MS_WH_LEFT, KC_MS_UP, KC_MS_WH_RIGHT, TD(DANCE_55), /*|----|*/ LGUI(KC_LBRC), LCTL(LSFT(KC_TAB)), RCTL(KC_TAB), LGUI(KC_RBRC), KC_TRANSPARENT,
                 // -------
                 TD(DANCE_56), KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, MT(MOD_LGUI, KC_DEL), /*|----|*/ TD(DANCE_60), MT(MOD_RGUI, KC_DOWN), MT(MOD_RALT, KC_UP), TD(DANCE_63), KC_ENTER,
                 // -------
                 TD(DANCE_58), KC_MS_BTN2, KC_MS_WH_UP, KC_MS_WH_DOWN, KC_TRANSPARENT, /*|----|*/ KC_MS_BTN1, KC_MS_ACCEL0, KC_MS_ACCEL1, KC_MS_ACCEL2, TO(OTHER),
                 // -------
                 TO(BASE), KC_LGUI, /*|----|*/ KC_RALT, TO(SYM)),

    /*
     * Only able to get to this layer from NAV (third) layer
     * Sleep/Lock computer
     * Toggle Combo mode
     * Reboot/booload keyboard
     */
    [OTHER] = LAYOUT(QK_RBT, QK_BOOT, XXXXXXX, QK_MAKE, XXXXXXX, /*|----|*/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                     // -------
                     XXXXXXX, XXXXXXX, CM_TOGG, KC_SLEP, XXXXXXX, /*|----|*/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                     // -------
                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, /*|----|*/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                     // -------
                     TO(BASE), OSM(MOD_LSFT), /*|----|*/ OSM(MOD_RCTL), TO(SYM))};

// ----- Combos -----
const uint16_t PROGMEM lu_combo[] = {KC_L, KC_U, COMBO_END};
const uint16_t PROGMEM fp_combo[] = {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM cd_combo[] = {KC_C, KC_D, COMBO_END};

combo_t key_combos[] = {
    [LU_ESC]   = COMBO(lu_combo, KC_ESCAPE),
    [FP_WRITE] = COMBO(fp_combo, VIM_SAVE),
    [CD_COLON] = COMBO(cd_combo, KC_COLN),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case VIM_SAVE:
            if (record->event.pressed) {
                tap_code16(KC_COLON);
                tap_code16(KC_W);
                tap_code16(KC_ENTER);
            }

            return false; // Skip all further processing of this key
        default:
            return true; // Process all other keycodes normally
    }
}

// ----- Tap Dance -----
extern bool g_suspend_state;
#define GET_TAP_KC(dual_role_key) dual_role_key & 0xFF
uint16_t last_keycode  = KC_NO;
uint8_t  last_modifier = 0;

typedef struct {
    bool    is_press_action;
    uint8_t step;
} tap;

enum { SINGLE_TAP = 1, SINGLE_HOLD, DOUBLE_TAP, DOUBLE_HOLD, DOUBLE_SINGLE_TAP, MORE_TAPS };

static tap dance_state = {.is_press_action = true, .step = 0};

void    on_dance_1(tap_dance_state_t *state, void *user_data);
uint8_t dance_1_dance_step(tap_dance_state_t *state);
void    dance_1_finished(tap_dance_state_t *state, void *user_data);
void    dance_1_reset(tap_dance_state_t *state, void *user_data);

void on_dance_1(tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_DOT);
        tap_code16(KC_DOT);
        tap_code16(KC_DOT);
    }
    if (state->count > 3) {
        tap_code16(KC_DOT);
    }
}

uint8_t dance_1_dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed)
            return SINGLE_TAP;
        else
            return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted)
            return DOUBLE_SINGLE_TAP;
        else if (state->pressed)
            return DOUBLE_HOLD;
        else
            return DOUBLE_TAP;
    }
    return MORE_TAPS;
}

void dance_1_finished(tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_1_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP:
            register_code16(KC_DOT);
            break;
        case SINGLE_HOLD:
            register_code16(KC_EXLM);
            break;
        case DOUBLE_TAP:
            register_code16(KC_DOT);
            register_code16(KC_DOT);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_DOT);
            register_code16(KC_DOT);
            break;
    }
}

void dance_1_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP:
            unregister_code16(KC_DOT);
            break;
        case SINGLE_HOLD:
            unregister_code16(KC_EXLM);
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_DOT);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_DOT);
            break;
    }
    dance_state.step = 0;
}

void    on_dance_2(tap_dance_state_t *state, void *user_data);
uint8_t dance_2_dance_step(tap_dance_state_t *state);
void    dance_2_finished(tap_dance_state_t *state, void *user_data);
void    dance_2_reset(tap_dance_state_t *state, void *user_data);

void on_dance_2(tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_COMM);
        tap_code16(KC_COMM);
        tap_code16(KC_COMM);
    }
    if (state->count > 3) {
        tap_code16(KC_COMM);
    }
}

uint8_t dance_2_dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed)
            return SINGLE_TAP;
        else
            return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted)
            return DOUBLE_SINGLE_TAP;
        else if (state->pressed)
            return DOUBLE_HOLD;
        else
            return DOUBLE_TAP;
    }
    return MORE_TAPS;
}

void dance_2_finished(tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_2_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP:
            register_code16(KC_COMM);
            break;
        case SINGLE_HOLD:
            register_code16(KC_MINS);
            break;
        case DOUBLE_TAP:
            register_code16(KC_COMM);
            register_code16(KC_COMM);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_COMM);
            register_code16(KC_COMM);
            break;
    }
}

void dance_2_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP:
            unregister_code16(KC_COMM);
            break;
        case SINGLE_HOLD:
            unregister_code16(KC_MINS);
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_COMM);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_COMM);
            break;
    }
    dance_state.step = 0;
}

void    on_dance_3(tap_dance_state_t *state, void *user_data);
uint8_t dance_3_dance_step(tap_dance_state_t *state);
void    dance_3_finished(tap_dance_state_t *state, void *user_data);
void    dance_3_reset(tap_dance_state_t *state, void *user_data);

void on_dance_3(tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_SLASH);
        tap_code16(KC_SLASH);
        tap_code16(KC_SLASH);
    }
    if (state->count > 3) {
        tap_code16(KC_SLASH);
    }
}

uint8_t dance_3_dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed)
            return SINGLE_TAP;
        else
            return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted)
            return DOUBLE_SINGLE_TAP;
        else if (state->pressed)
            return DOUBLE_HOLD;
        else
            return DOUBLE_TAP;
    }
    return MORE_TAPS;
}

void dance_3_finished(tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_3_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP:
            register_code16(KC_SLASH);
            break;
        case SINGLE_HOLD:
            register_code16(S(KC_MINS));
            break;
        case DOUBLE_TAP:
            register_code16(KC_SLASH);
            register_code16(KC_SLASH);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_SLASH);
            register_code16(KC_SLASH);
            break;
    }
}

void dance_3_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP:
            unregister_code16(KC_SLASH);
            break;
        case SINGLE_HOLD:
            unregister_code16(S(KC_MINS));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_SLASH);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_SLASH);
            break;
    }
    dance_state.step = 0;
}

void    on_dance_15(tap_dance_state_t *state, void *user_data);
uint8_t dance_15_dance_step(tap_dance_state_t *state);
void    dance_15_finished(tap_dance_state_t *state, void *user_data);
void    dance_15_reset(tap_dance_state_t *state, void *user_data);

void on_dance_15(tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_SPACE);
        tap_code16(KC_SPACE);
        tap_code16(KC_SPACE);
    }
    if (state->count > 3) {
        tap_code16(KC_SPACE);
    }
}

uint8_t dance_15_dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed)
            return SINGLE_TAP;
        else
            return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted)
            return DOUBLE_SINGLE_TAP;
        else if (state->pressed)
            return DOUBLE_HOLD;
        else
            return DOUBLE_TAP;
    }
    return MORE_TAPS;
}

void dance_15_finished(tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_15_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP:
            register_code16(KC_SPACE);
            break;
        case SINGLE_HOLD:
            register_code16(KC_UNDS);
            break;
        case DOUBLE_TAP:
            register_code16(KC_SPACE);
            register_code16(KC_SPACE);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_SPACE);
            register_code16(KC_SPACE);
            break;
    }
}

void dance_15_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP:
            unregister_code16(KC_SPACE);
            break;
        case SINGLE_HOLD:
            unregister_code16(KC_UNDS);
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_SPACE);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_SPACE);
            break;
    }
    dance_state.step = 0;
}

void    on_dance_31(tap_dance_state_t *state, void *user_data);
uint8_t dance_31_dance_step(tap_dance_state_t *state);
void    dance_31_finished(tap_dance_state_t *state, void *user_data);
void    dance_31_reset(tap_dance_state_t *state, void *user_data);

void on_dance_31(tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(LSFT(KC_4));
        tap_code16(LSFT(KC_4));
        tap_code16(LSFT(KC_4));
    }
    if (state->count > 3) {
        tap_code16(LSFT(KC_4));
    }
}

uint8_t dance_31_dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed)
            return SINGLE_TAP;
        else
            return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted)
            return DOUBLE_SINGLE_TAP;
        else if (state->pressed)
            return DOUBLE_HOLD;
        else
            return DOUBLE_TAP;
    }
    return MORE_TAPS;
}

void dance_31_finished(tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_31_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP:
            register_code16(LSFT(KC_4));
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(LGUI(LSFT(KC_4))));
            break;
        case DOUBLE_TAP:
            register_code16(LSFT(KC_4));
            register_code16(LSFT(KC_4));
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(LSFT(KC_4));
            register_code16(LSFT(KC_4));
            break;
    }
}

void dance_31_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP:
            unregister_code16(LSFT(KC_4));
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(LGUI(LSFT(KC_4))));
            break;
        case DOUBLE_TAP:
            unregister_code16(LSFT(KC_4));
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(LSFT(KC_4));
            break;
    }
    dance_state.step = 0;
}

void    on_dance_32(tap_dance_state_t *state, void *user_data);
uint8_t dance_32_dance_step(tap_dance_state_t *state);
void    dance_32_finished(tap_dance_state_t *state, void *user_data);
void    dance_32_reset(tap_dance_state_t *state, void *user_data);

void on_dance_32(tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_QUOTE);
        tap_code16(KC_QUOTE);
        tap_code16(KC_QUOTE);
    }
    if (state->count > 3) {
        tap_code16(KC_QUOTE);
    }
}

uint8_t dance_32_dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed)
            return SINGLE_TAP;
        else
            return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted)
            return DOUBLE_SINGLE_TAP;
        else if (state->pressed)
            return DOUBLE_HOLD;
        else
            return DOUBLE_TAP;
    }
    return MORE_TAPS;
}

void dance_32_finished(tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_32_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP:
            register_code16(KC_QUOTE);
            break;
        /* case SINGLE_HOLD: register_code16(LGUI(KC_QUOTE)); break; */
        case DOUBLE_TAP:
            register_code16(KC_GRAVE);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_QUOTE);
            register_code16(KC_QUOTE);
            break;
    }
}

void dance_32_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP:
            unregister_code16(KC_QUOTE);
            break;
        case SINGLE_HOLD:
            unregister_code16(LGUI(KC_QUOTE));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_GRAVE);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_QUOTE);
            break;
    }
    dance_state.step = 0;
}

void    on_dance_33(tap_dance_state_t *state, void *user_data);
uint8_t dance_33_dance_step(tap_dance_state_t *state);
void    dance_33_finished(tap_dance_state_t *state, void *user_data);
void    dance_33_reset(tap_dance_state_t *state, void *user_data);

void on_dance_33(tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(LSFT(KC_5));
        tap_code16(LSFT(KC_5));
        tap_code16(LSFT(KC_5));
    }

    if (state->count > 3) {
        tap_code16(LSFT(KC_5));
    }
}

uint8_t dance_33_dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed)
            return SINGLE_TAP;
        else
            return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted)
            return DOUBLE_SINGLE_TAP;
        else if (state->pressed)
            return DOUBLE_HOLD;
        else
            return DOUBLE_TAP;
    }
    return MORE_TAPS;
}

void dance_33_finished(tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_33_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP:
            register_code16(LSFT(KC_5));
            break;
        case SINGLE_HOLD:
            register_code16(LGUI(LSFT(KC_5)));
            break;
        case DOUBLE_TAP:
            register_code16(LSFT(KC_5));
            register_code16(LSFT(KC_5));
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(LSFT(KC_5));
            register_code16(LSFT(KC_5));
            break;
    }
}

void dance_33_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP:
            unregister_code16(LSFT(KC_5));
            break;
        case SINGLE_HOLD:
            unregister_code16(LGUI(LSFT(KC_5)));
            break;
        case DOUBLE_TAP:
            unregister_code16(LSFT(KC_5));
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(LSFT(KC_5));
            break;
    }
    dance_state.step = 0;
}

void    on_dance_54(tap_dance_state_t *state, void *user_data);
uint8_t dance_54_dance_step(tap_dance_state_t *state);
void    dance_54_finished(tap_dance_state_t *state, void *user_data);
void    dance_54_reset(tap_dance_state_t *state, void *user_data);

void on_dance_54(tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_ESCAPE);
        tap_code16(KC_ESCAPE);
        tap_code16(KC_ESCAPE);
    }
    if (state->count > 3) {
        tap_code16(KC_ESCAPE);
    }
}

uint8_t dance_54_dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed)
            return SINGLE_TAP;
        else
            return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted)
            return DOUBLE_SINGLE_TAP;
        else if (state->pressed)
            return DOUBLE_HOLD;
        else
            return DOUBLE_TAP;
    }
    return MORE_TAPS;
}

void dance_54_finished(tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_54_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP:
            register_code16(KC_ESCAPE);
            break;
        case SINGLE_HOLD:
            register_code16(LALT(LGUI(KC_ESCAPE)));
            break;
        case DOUBLE_TAP:
            register_code16(KC_ESCAPE);
            register_code16(KC_ESCAPE);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_ESCAPE);
            register_code16(KC_ESCAPE);
            break;
    }
}

void dance_54_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP:
            unregister_code16(KC_ESCAPE);
            break;
        case SINGLE_HOLD:
            unregister_code16(LALT(LGUI(KC_ESCAPE)));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_ESCAPE);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_ESCAPE);
            break;
    }
    dance_state.step = 0;
}

void    on_dance_55(tap_dance_state_t *state, void *user_data);
uint8_t dance_55_dance_step(tap_dance_state_t *state);
void    dance_55_finished(tap_dance_state_t *state, void *user_data);
void    dance_55_reset(tap_dance_state_t *state, void *user_data);

void on_dance_55(tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_Q);
        tap_code16(KC_Q);
        tap_code16(KC_Q);
    }
    if (state->count > 3) {
        tap_code16(KC_Q);
    }
}

uint8_t dance_55_dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed)
            return SINGLE_TAP;
        else
            return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted)
            return DOUBLE_SINGLE_TAP;
        else if (state->pressed)
            return DOUBLE_HOLD;
        else
            return DOUBLE_TAP;
    }
    return MORE_TAPS;
}

void dance_55_finished(tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_55_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP:
            register_code16(KC_Q);
            break;
        case SINGLE_HOLD:
            register_code16(KC_H);
            break;
        case DOUBLE_TAP:
            register_code16(KC_Q);
            register_code16(KC_Q);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_Q);
            register_code16(KC_Q);
            break;
    }
}

void dance_55_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP:
            unregister_code16(KC_Q);
            break;
        case SINGLE_HOLD:
            unregister_code16(KC_H);
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_Q);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_Q);
            break;
    }
    dance_state.step = 0;
}

void    on_dance_56(tap_dance_state_t *state, void *user_data);
uint8_t dance_56_dance_step(tap_dance_state_t *state);
void    dance_56_finished(tap_dance_state_t *state, void *user_data);
void    dance_56_reset(tap_dance_state_t *state, void *user_data);

void on_dance_56(tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_TAB);
        tap_code16(KC_TAB);
        tap_code16(KC_TAB);
    }
    if (state->count > 3) {
        tap_code16(KC_TAB);
    }
}

uint8_t dance_56_dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed)
            return SINGLE_TAP;
        else
            return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted)
            return DOUBLE_SINGLE_TAP;
        else if (state->pressed)
            return DOUBLE_HOLD;
        else
            return DOUBLE_TAP;
    }
    return MORE_TAPS;
}

void dance_56_finished(tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_56_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP:
            register_code16(KC_TAB);
            break;
        case SINGLE_HOLD:
            register_code16(LGUI(KC_TAB));
            break;
        case DOUBLE_TAP:
            register_code16(KC_TAB);
            register_code16(KC_TAB);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_TAB);
            register_code16(KC_TAB);
            break;
    }
}

void dance_56_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP:
            unregister_code16(KC_TAB);
            break;
        case SINGLE_HOLD:
            unregister_code16(LGUI(KC_TAB));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_TAB);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_TAB);
            break;
    }
    dance_state.step = 0;
}

void    on_dance_57(tap_dance_state_t *state, void *user_data);
uint8_t dance_57_dance_step(tap_dance_state_t *state);
void    dance_57_finished(tap_dance_state_t *state, void *user_data);
void    dance_57_reset(tap_dance_state_t *state, void *user_data);

void on_dance_57(tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_DELETE);
        tap_code16(KC_DELETE);
        tap_code16(KC_DELETE);
    }
    if (state->count > 3) {
        tap_code16(KC_DELETE);
    }
}

uint8_t dance_57_dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed)
            return SINGLE_TAP;
        else
            return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted)
            return DOUBLE_SINGLE_TAP;
        else if (state->pressed)
            return DOUBLE_HOLD;
        else
            return DOUBLE_TAP;
    }
    return MORE_TAPS;
}

void dance_57_finished(tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_57_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP:
            register_code16(KC_DELETE);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_K));
            break;
        case DOUBLE_TAP:
            register_code16(KC_DELETE);
            register_code16(KC_DELETE);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_DELETE);
            register_code16(KC_DELETE);
            break;
    }
}

void dance_57_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP:
            unregister_code16(KC_DELETE);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_K));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_DELETE);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_DELETE);
            break;
    }
    dance_state.step = 0;
}

void    on_dance_58(tap_dance_state_t *state, void *user_data);
uint8_t dance_58_dance_step(tap_dance_state_t *state);
void    dance_58_finished(tap_dance_state_t *state, void *user_data);
void    dance_58_reset(tap_dance_state_t *state, void *user_data);

void on_dance_58(tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_GRAVE);
        tap_code16(KC_GRAVE);
        tap_code16(KC_GRAVE);
    }
    if (state->count > 3) {
        tap_code16(KC_GRAVE);
    }
}

uint8_t dance_58_dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed)
            return SINGLE_TAP;
        else
            return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted)
            return DOUBLE_SINGLE_TAP;
        else if (state->pressed)
            return DOUBLE_HOLD;
        else
            return DOUBLE_TAP;
    }
    return MORE_TAPS;
}

void dance_58_finished(tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_58_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP:
            register_code16(KC_GRAVE);
            break;
        case SINGLE_HOLD:
            register_code16(LGUI(KC_GRAVE));
            break;
        case DOUBLE_TAP:
            register_code16(KC_GRAVE);
            register_code16(KC_GRAVE);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_GRAVE);
            register_code16(KC_GRAVE);
            break;
    }
}

void dance_58_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP:
            unregister_code16(KC_GRAVE);
            break;
        case SINGLE_HOLD:
            unregister_code16(LGUI(KC_GRAVE));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_GRAVE);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_GRAVE);
            break;
    }
    dance_state.step = 0;
}

void    on_dance_59(tap_dance_state_t *state, void *user_data);
uint8_t dance_59_dance_step(tap_dance_state_t *state);
void    dance_59_finished(tap_dance_state_t *state, void *user_data);
void    dance_59_reset(tap_dance_state_t *state, void *user_data);

void on_dance_59(tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_SPACE);
        tap_code16(KC_SPACE);
        tap_code16(KC_SPACE);
    }
    if (state->count > 3) {
        tap_code16(KC_SPACE);
    }
}

uint8_t dance_59_dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed)
            return SINGLE_TAP;
        else
            return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted)
            return DOUBLE_SINGLE_TAP;
        else if (state->pressed)
            return DOUBLE_HOLD;
        else
            return DOUBLE_TAP;
    }
    return MORE_TAPS;
}

void dance_59_finished(tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_59_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP:
            register_code16(KC_SPACE);
            break;
        case SINGLE_HOLD:
            register_code16(LGUI(KC_O));
            break;
        case DOUBLE_TAP:
            register_code16(KC_SPACE);
            register_code16(KC_SPACE);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_SPACE);
            register_code16(KC_SPACE);
            break;
    }
}

void dance_59_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP:
            unregister_code16(KC_SPACE);
            break;
        case SINGLE_HOLD:
            unregister_code16(LGUI(KC_O));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_SPACE);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_SPACE);
            break;
    }
    dance_state.step = 0;
}

void    on_dance_60(tap_dance_state_t *state, void *user_data);
uint8_t dance_60_dance_step(tap_dance_state_t *state);
void    dance_60_finished(tap_dance_state_t *state, void *user_data);
void    dance_60_reset(tap_dance_state_t *state, void *user_data);

void on_dance_60(tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_LEFT);
        tap_code16(KC_LEFT);
        tap_code16(KC_LEFT);
    }
    if (state->count > 3) {
        tap_code16(KC_LEFT);
    }
}

uint8_t dance_60_dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed)
            return SINGLE_TAP;
        else
            return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted)
            return DOUBLE_SINGLE_TAP;
        else if (state->pressed)
            return DOUBLE_HOLD;
        else
            return DOUBLE_TAP;
    }
    return MORE_TAPS;
}

void dance_60_finished(tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_60_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP:
            register_code16(KC_LEFT);
            break;
        case SINGLE_HOLD:
            register_code16(LGUI(KC_LEFT));
            break;
        case DOUBLE_TAP:
            register_code16(KC_LEFT);
            register_code16(KC_LEFT);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_LEFT);
            register_code16(KC_LEFT);
            break;
    }
}

void dance_60_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP:
            unregister_code16(KC_LEFT);
            break;
        case SINGLE_HOLD:
            unregister_code16(LGUI(KC_LEFT));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_LEFT);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_LEFT);
            break;
    }
    dance_state.step = 0;
}

void    on_dance_63(tap_dance_state_t *state, void *user_data);
uint8_t dance_63_dance_step(tap_dance_state_t *state);
void    dance_63_finished(tap_dance_state_t *state, void *user_data);
void    dance_63_reset(tap_dance_state_t *state, void *user_data);

void on_dance_63(tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_RIGHT);
        tap_code16(KC_RIGHT);
        tap_code16(KC_RIGHT);
    }
    if (state->count > 3) {
        tap_code16(KC_RIGHT);
    }
}

uint8_t dance_63_dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed)
            return SINGLE_TAP;
        else
            return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted)
            return DOUBLE_SINGLE_TAP;
        else if (state->pressed)
            return DOUBLE_HOLD;
        else
            return DOUBLE_TAP;
    }
    return MORE_TAPS;
}

void dance_63_finished(tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_63_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP:
            register_code16(KC_RIGHT);
            break;
        case SINGLE_HOLD:
            register_code16(LGUI(KC_RIGHT));
            break;
        case DOUBLE_TAP:
            register_code16(KC_RIGHT);
            register_code16(KC_RIGHT);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_RIGHT);
            register_code16(KC_RIGHT);
            break;
    }
}

void dance_63_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP:
            unregister_code16(KC_RIGHT);
            break;
        case SINGLE_HOLD:
            unregister_code16(LGUI(KC_RIGHT));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_RIGHT);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_RIGHT);
            break;
    }
    dance_state.step = 0;
}

void    on_bksl_hme(tap_dance_state_t *state, void *user_data);
uint8_t bksl_hme_dance_step(tap_dance_state_t *state);
void    bksl_hme_finished(tap_dance_state_t *state, void *user_data);
void    bksl_hme_reset(tap_dance_state_t *state, void *user_data);

void on_bksl_hme(tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_BSLS);
        tap_code16(KC_BSLS);
        tap_code16(KC_BSLS);
    }
    if (state->count > 3) {
        tap_code16(KC_BSLS);
    }
}

uint8_t bksl_hme_dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed)
            return SINGLE_TAP;
        else
            return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted)
            return DOUBLE_SINGLE_TAP;
        else if (state->pressed)
            return DOUBLE_HOLD;
        else
            return DOUBLE_TAP;
    }
    return MORE_TAPS;
}

void bksl_hme_finished(tap_dance_state_t *state, void *user_data) {
    dance_state.step = bksl_hme_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP:
            register_code16(KC_BSLS);
            break;
        case SINGLE_HOLD:
            register_code16(KC_HOME);
            break;
        case DOUBLE_TAP:
            register_code16(KC_BSLS);
            register_code16(KC_BSLS);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_BSLS);
            register_code16(KC_BSLS);
            break;
    }
}

void bksl_hme_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP:
            unregister_code16(KC_BSLS);
            break;
        case SINGLE_HOLD:
            unregister_code16(KC_HOME);
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_BSLS);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_BSLS);
            break;
    }
    dance_state.step = 0;
}

void    on_pipe_end(tap_dance_state_t *state, void *user_data);
uint8_t pipe_end_dance_step(tap_dance_state_t *state);
void    pipe_end_finished(tap_dance_state_t *state, void *user_data);
void    pipe_end_reset(tap_dance_state_t *state, void *user_data);

void on_pipe_end(tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_PIPE);
        tap_code16(KC_PIPE);
        tap_code16(KC_PIPE);
    }
    if (state->count > 3) {
        tap_code16(KC_PIPE);
    }
}

uint8_t pipe_end_dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed)
            return SINGLE_TAP;
        else
            return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted)
            return DOUBLE_SINGLE_TAP;
        else if (state->pressed)
            return DOUBLE_HOLD;
        else
            return DOUBLE_TAP;
    }
    return MORE_TAPS;
}

void pipe_end_finished(tap_dance_state_t *state, void *user_data) {
    dance_state.step = pipe_end_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP:
            register_code16(KC_PIPE);
            break;
        case SINGLE_HOLD:
            register_code16(KC_END);
            break;
        case DOUBLE_TAP:
            register_code16(KC_PIPE);
            register_code16(KC_PIPE);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_PIPE);
            register_code16(KC_PIPE);
            break;
    }
}

void pipe_end_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP:
            unregister_code16(KC_PIPE);
            break;
        case SINGLE_HOLD:
            unregister_code16(KC_END);
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_PIPE);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_PIPE);
            break;
    }
    dance_state.step = 0;
}

void    on_prev_next(tap_dance_state_t *state, void *user_data);
uint8_t prev_next_dance_step(tap_dance_state_t *state);
void    prev_next_finished(tap_dance_state_t *state, void *user_data);
void    prev_next_reset(tap_dance_state_t *state, void *user_data);

void on_prev_next(tap_dance_state_t *state, void *user_data) {
    if (state->count >= 3) {
        tap_code16(KC_MPRV);
    }
}

uint8_t prev_next_dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed)
            return SINGLE_TAP;
        else
            return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted)
            return DOUBLE_SINGLE_TAP;
        else if (state->pressed)
            return DOUBLE_HOLD;
        else
            return DOUBLE_TAP;
    }
    return MORE_TAPS;
}

void prev_next_finished(tap_dance_state_t *state, void *user_data) {
    dance_state.step = prev_next_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP:
            tap_code16(KC_MNXT);
            break;
        case SINGLE_HOLD:
        case DOUBLE_TAP:
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_MPRV);
            break;
    }
}

void prev_next_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    dance_state.step = 0;
}

void    on_scrn_shot(tap_dance_state_t *state, void *user_data);
uint8_t scrn_shot_dance_step(tap_dance_state_t *state);
void    scrn_shot_finished(tap_dance_state_t *state, void *user_data);
void    scrn_shot_reset(tap_dance_state_t *state, void *user_data);

void on_scrn_shot(tap_dance_state_t *state, void *user_data) {
    if (state->count >= 3) {
        tap_code16(SC_SHOT);
    }
}

uint8_t scrn_shot_dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed)
            return SINGLE_TAP;
        else
            return SINGLE_HOLD;
    }
    return MORE_TAPS;
}

void scrn_shot_finished(tap_dance_state_t *state, void *user_data) {
    switch (scrn_shot_dance_step(state)) {
        case SINGLE_TAP:
            tap_code16(SC_SHOT);
            break;
        case SINGLE_HOLD:
            tap_code16(SC_SHOT_APP);
            break;
    }
}

void scrn_shot_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    dance_state.step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
    [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),     [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),     [DANCE_3] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_3, dance_3_finished, dance_3_reset),     [DANCE_15] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_15, dance_15_finished, dance_15_reset), [DANCE_31] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_31, dance_31_finished, dance_31_reset), [DANCE_32] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_32, dance_32_finished, dance_32_reset), [DANCE_33] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_33, dance_33_finished, dance_33_reset), [DANCE_54] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_54, dance_54_finished, dance_54_reset),     [DANCE_55] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_55, dance_55_finished, dance_55_reset),     [DANCE_56] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_56, dance_56_finished, dance_56_reset),
    [DANCE_57] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_57, dance_57_finished, dance_57_reset), [DANCE_58] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_58, dance_58_finished, dance_58_reset), [DANCE_59] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_59, dance_59_finished, dance_59_reset), [DANCE_60] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_60, dance_60_finished, dance_60_reset), [DANCE_63] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_63, dance_63_finished, dance_63_reset), [BKSL_HME] = ACTION_TAP_DANCE_FN_ADVANCED(on_bksl_hme, bksl_hme_finished, bksl_hme_reset), [PIPE_END] = ACTION_TAP_DANCE_FN_ADVANCED(on_pipe_end, pipe_end_finished, pipe_end_reset), [SCRN_SHOT] = ACTION_TAP_DANCE_FN_ADVANCED(on_scrn_shot, scrn_shot_finished, scrn_shot_reset), [PREV_NEXT] = ACTION_TAP_DANCE_FN_ADVANCED(on_prev_next, prev_next_finished, prev_next_reset),
};
