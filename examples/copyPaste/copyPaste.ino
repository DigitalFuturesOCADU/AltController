/*
  Copy/Paste Example for AltController Library
  
  Text editing controller with common shortcuts:
  - Select All (Ctrl+A) on pin 2
  - Copy (Ctrl+C) on pin 3
  - Paste (Ctrl+V) on pin 4
  - Paste in Place (Shift+Insert) on pin 5
  - Navigation/Editing:
    - Enter on pin 6
    - Tab on pin 7
    - Backspace on pin 8
    - Spacebar on pin 9
  
  Connection:
  - Connect buttons between the specified pins and ground
  - Internal pullup resistors are used, no external resistors needed
*/

#include <AltController.h>

// Pin assignments
const int SELECT_ALL_PIN = 2;
const int COPY_PIN = 3;
const int PASTE_PIN = 4;
const int PASTE_PLACE_PIN = 5;
const int ENTER_PIN = 6;
const int TAB_PIN = 7;
const int BACKSPACE_PIN = 8;
const int SPACE_PIN = 9;

// Timing configuration (in milliseconds)
const int MACRO_TIME = 100;    // Longer time for macros
const int SINGLE_TIME = 50;    // Shorter time for single keys

AltController controller;

void setup() {
    // Configure macro shortcuts
    controller.addMacro(SELECT_ALL_PIN, {KEY_LEFT_CTRL, 'a'}, MACRO_TIME);  // Select All
    controller.addMacro(COPY_PIN, {KEY_LEFT_CTRL, 'c'}, MACRO_TIME);        // Copy
    controller.addMacro(PASTE_PIN, {KEY_LEFT_CTRL, 'v'}, MACRO_TIME);       // Paste
    controller.addMacro(PASTE_PLACE_PIN, {KEY_LEFT_SHIFT, KEY_INSERT}, MACRO_TIME);  // Paste in Place
    
    // Configure single-key actions
    controller.addKeyRelease(ENTER_PIN, KEY_RETURN, SINGLE_TIME);       // Enter
    controller.addKeyRelease(TAB_PIN, KEY_TAB, SINGLE_TIME);           // Tab
    controller.addKeyRelease(BACKSPACE_PIN, KEY_BACKSPACE, SINGLE_TIME); // Backspace
    controller.addKeyRelease(SPACE_PIN, ' ', SINGLE_TIME);             // Spacebar
}

void loop() {
    controller.update();
}