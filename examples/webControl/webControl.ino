/*
  Web Control Example for AltController Library
  
  Cross-platform web browser controller with Windows/Mac support:
  
  Windows Controls:
  - New Tab (Ctrl+Tab) on pin 0
  - New Window (Ctrl+N) on pin 1
  - Previous Tab (Ctrl+Shift+Tab) on pin 2
  
  Mac Controls:
  - New Tab (Cmd+Tab) on pin 3
  - New Window (Cmd+N) on pin 4
  - Previous Tab (Cmd+Shift+Tab) on pin 5
  
  Navigation (Both Platforms):
  - Enter on pin 6
  - Spacebar on pin 7
  - Down Arrow on pin 8
  - Up Arrow on pin 9
  - Page Down on pin 10
  - Page Up on pin 11
  
  Quick URL:
  
  - https://ocadu.ca on pin 12
  
  Connection:
  - Connect buttons between the specified pins and ground
  - Internal pullup resistors are used, no external resistors needed
*/

#include <AltController.h>

// Windows pin assignments
int WIN_NEXT_TAB_PIN = 0;
int WIN_NEW_TAB_PIN = 1;
int WIN_PREV_TAB_PIN = 2;

// Mac pin assignments
int MAC_NEXT_TAB_PIN = 3;
int MAC_NEW_TAB_PIN = 4;
int MAC_PREV_TAB_PIN = 5;

// Common navigation pins
int ENTER_PIN = 6;
int SPACE_PIN = 7;
int DOWN_PIN = 8;
int UP_PIN = 9;
int PGDOWN_PIN = 10;
int PGUP_PIN = 11;

int URL_PIN = 12;

// Timing configuration (in milliseconds)
int MACRO_TIME = 100;    // For key combinations
int KEY_TIME = 50;       // For single keys
int PRINT_TIME = 250;    // For URL printing

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
    
    controller.addPrint(URL_PIN, "https://ocadu.ca\n", PRINT_TIME);    // \n adds Enter key press
}

void loop() {
    controller.update();
}

