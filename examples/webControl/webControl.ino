/*
  Web Control Example for AltController Library
  
  Cross-platform web browser controller with Windows/Mac support:
  
  Windows Controls:
  - Next Tab (Ctrl+Tab) on pin 2
  - New Tab (Ctrl+N) on pin 3
  - Previous Tab (Ctrl+Shift+Tab) on pin 4
  
  Mac Controls:
  - Next Tab (Cmd+Tab) on pin 5
  - New Tab (Cmd+N) on pin 6
  - Previous Tab (Cmd+Shift+Tab) on pin 7
  
  Navigation (Both Platforms):
  - Enter on pin 8
  - Spacebar on pin 9
  - Down Arrow on pin 10
  - Up Arrow on pin 11
  - Page Down on pin 12
  - Page Up on pin 13
  
  Quick URLs:
  - https://df.show on pin A0
  - https://ocadu.ca on pin A1
  
  Connection:
  - Connect buttons between the specified pins and ground
  - Internal pullup resistors are used, no external resistors needed
*/

#include <AltController.h>

// Windows pin assignments
const int WIN_NEXT_TAB_PIN = 2;
const int WIN_NEW_TAB_PIN = 3;
const int WIN_PREV_TAB_PIN = 4;

// Mac pin assignments
const int MAC_NEXT_TAB_PIN = 5;
const int MAC_NEW_TAB_PIN = 6;
const int MAC_PREV_TAB_PIN = 7;

// Common navigation pins
const int ENTER_PIN = 8;
const int SPACE_PIN = 9;
const int DOWN_PIN = 10;
const int UP_PIN = 11;
const int PGDOWN_PIN = 12;
const int PGUP_PIN = 13;
const int URL1_PIN = A0;
const int URL2_PIN = A1;

// Timing configuration (in milliseconds)
const int MACRO_TIME = 100;    // For key combinations
const int KEY_TIME = 50;       // For single keys
const int PRINT_TIME = 250;    // For URL printing

AltController controller;

void setup() {
    // Windows tab management macros
    controller.addMacro(WIN_NEXT_TAB_PIN, {KEY_LEFT_CTRL, KEY_TAB}, MACRO_TIME);               // Windows next tab
    controller.addMacro(WIN_NEW_TAB_PIN, {KEY_LEFT_CTRL, 't'}, MACRO_TIME);                    // Windows new tab
    controller.addMacro(WIN_PREV_TAB_PIN, {KEY_LEFT_CTRL, KEY_LEFT_SHIFT, KEY_TAB}, MACRO_TIME); // Windows prev tab
    
    // Mac tab management macros
    controller.addMacro(MAC_NEXT_TAB_PIN, {KEY_LEFT_GUI, KEY_LEFT_ALT, KEY_RIGHT_ARROW}, MACRO_TIME);                // Mac next tab
    controller.addMacro(MAC_NEW_TAB_PIN, {KEY_LEFT_GUI, 't'}, MACRO_TIME);                     // Mac new tab
    controller.addMacro(MAC_PREV_TAB_PIN, {KEY_LEFT_GUI, KEY_LEFT_ALT, KEY_LEFT_ARROW}, MACRO_TIME);  // Mac prev tab
    
    // Navigation keys (same for both platforms)
    controller.addKeyRelease(ENTER_PIN, KEY_RETURN, KEY_TIME);
    controller.addKeyRelease(SPACE_PIN, ' ', KEY_TIME);
    controller.addKeyRelease(DOWN_PIN, KEY_DOWN_ARROW, KEY_TIME);
    controller.addKeyRelease(UP_PIN, KEY_UP_ARROW, KEY_TIME);
    controller.addKeyRelease(PGDOWN_PIN, KEY_PAGE_DOWN, KEY_TIME);
    controller.addKeyRelease(PGUP_PIN, KEY_PAGE_UP, KEY_TIME);
    
    // URL shortcuts (same for both platforms)
    controller.addPrint(URL1_PIN, "https://df.show\n", PRINT_TIME);     // \n adds Enter key press
    controller.addPrint(URL2_PIN, "https://ocadu.ca\n", PRINT_TIME);    // \n adds Enter key press
}

void loop() {
    controller.update();
}

/* Usage Instructions:

   For Windows:
   Use pins 2-4 for tab management:
   - Pin 2: Next Tab (Ctrl+Tab)
   - Pin 3: New Tab (Ctrl+N)
   - Pin 4: Previous Tab (Ctrl+Shift+Tab)

   For Mac:
   Use pins 5-7 for tab management:
   - Pin 5: Next Tab (Cmd+Option+right arrow)
   - Pin 6: New Tab (Cmd+N)
   - Pin 7: Previous Tab (Cmd+Option+left arrow)

   Common Controls (Both Platforms):
   - Pin 8: Enter
   - Pin 9: Space
   - Pin 10: Down Arrow
   - Pin 11: Up Arrow
   - Pin 12: Page Down
   - Pin 13: Page Up
   - Pin A0: Open df.show
   - Pin A1: Open ocadu.ca
*/