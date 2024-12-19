/*
  Web Control Example for AltController Library
  
  Web browser controller with common shortcuts:
  - Tab Management:
    - Next Tab (Ctrl+Tab) on pin 2
    - New Tab (Ctrl+N) on pin 3
    - Previous Tab (Ctrl+Shift+Tab) on pin 4
  - Navigation:
    - Enter on pin 5
    - Spacebar on pin 6
    - Down Arrow on pin 7
    - Up Arrow on pin 8
    - Page Down on pin 9
    - Page Up on pin 10
  - Quick URLs:
    - https://df.show on pin 11
    - https://ocadu.ca on pin 12
  
  Connection:
  - Connect buttons between the specified pins and ground
  - Internal pullup resistors are used, no external resistors needed
*/

#include <AltController.h>

// Pin assignments
const int NEXT_TAB_PIN = 2;
const int NEW_TAB_PIN = 3;
const int PREV_TAB_PIN = 4;
const int ENTER_PIN = 5;
const int SPACE_PIN = 6;
const int DOWN_PIN = 7;
const int UP_PIN = 8;
const int PGDOWN_PIN = 9;
const int PGUP_PIN = 10;
const int URL1_PIN = 11;
const int URL2_PIN = 12;

// Timing configuration (in milliseconds)
const int MACRO_TIME = 100;    // For key combinations
const int KEY_TIME = 50;       // For single keys
const int PRINT_TIME = 150;    // For URL printing

AltController controller;

void setup() {
    // Tab management macros
    controller.addMacro(NEXT_TAB_PIN, {KEY_LEFT_CTRL, KEY_TAB}, MACRO_TIME);            // Next tab
    controller.addMacro(NEW_TAB_PIN, {KEY_LEFT_CTRL, 'n'}, MACRO_TIME);                 // New tab
    controller.addMacro(PREV_TAB_PIN, {KEY_LEFT_CTRL, KEY_LEFT_SHIFT, KEY_TAB}, MACRO_TIME);  // Previous tab
    
    // Navigation keys
    controller.addKeyRelease(ENTER_PIN, KEY_RETURN, KEY_TIME);
    controller.addKeyRelease(SPACE_PIN, ' ', KEY_TIME);
    controller.addKeyRelease(DOWN_PIN, KEY_DOWN_ARROW, KEY_TIME);
    controller.addKeyRelease(UP_PIN, KEY_UP_ARROW, KEY_TIME);
    controller.addKeyRelease(PGDOWN_PIN, KEY_PAGE_DOWN, KEY_TIME);
    controller.addKeyRelease(PGUP_PIN, KEY_PAGE_UP, KEY_TIME);
    
    // URL shortcuts
    controller.addPrint(URL1_PIN, "https://df.show\n", PRINT_TIME);     // \n adds Enter key press
    controller.addPrint(URL2_PIN, "https://ocadu.ca\n", PRINT_TIME);    // \n adds Enter key press
}

void loop() {
    controller.update();
}