/*
  Copy/Paste Example for AltController Library
  
  Cross-platform text editing controller with Windows/Mac support:
  
  Windows Controls (Pins 2-5):
  - Select All (Ctrl+A)
  - Copy (Ctrl+C)
  - Paste (Ctrl+V)
  - Paste in Place (Shift+Insert)
  
  Mac Controls (Pins 6-9):
  - Select All (Cmd+A)
  - Copy (Cmd+C)
  - Paste (Cmd+V)
  - Paste in Place (Cmd+Shift+V)
  
  Navigation/Editing (Both Platforms):
  - Enter
  - Tab
  - Backspace
  - Spacebar
  
  Connection:
  - Connect buttons between the specified pins and ground
  - Internal pullup resistors are used, no external resistors needed
*/

#include <AltController.h>

// Windows pin assignments
const int WIN_SELECT_ALL_PIN = 2;
const int WIN_COPY_PIN = 3;
const int WIN_PASTE_PIN = 4;
const int WIN_PASTE_PLACE_PIN = 5;

// Mac pin assignments
const int MAC_SELECT_ALL_PIN = 6;
const int MAC_COPY_PIN = 7;
const int MAC_PASTE_PIN = 8;
const int MAC_PASTE_PLACE_PIN = 9;

// Common navigation pins
const int ENTER_PIN = 10;
const int TAB_PIN = 11;
const int BACKSPACE_PIN = 12;
const int SPACE_PIN = 13;

// Timing configuration (in milliseconds)
const int MACRO_TIME = 100;    // Longer time for macros
const int SINGLE_TIME = 50;    // Shorter time for single keys

AltController controller;

void setup() {
    // Windows shortcuts
    controller.addMacro(WIN_SELECT_ALL_PIN, {KEY_LEFT_CTRL, 'a'}, MACRO_TIME);    // Windows Select All
    controller.addMacro(WIN_COPY_PIN, {KEY_LEFT_CTRL, 'c'}, MACRO_TIME);         // Windows Copy
    controller.addMacro(WIN_PASTE_PIN, {KEY_LEFT_CTRL, 'v'}, MACRO_TIME);        // Windows Paste
    controller.addMacro(WIN_PASTE_PLACE_PIN, {KEY_LEFT_SHIFT, KEY_INSERT}, MACRO_TIME);  // Windows Paste in Place
    
    // Mac shortcuts
    controller.addMacro(MAC_SELECT_ALL_PIN, {KEY_LEFT_GUI, 'a'}, MACRO_TIME);    // Mac Select All
    controller.addMacro(MAC_COPY_PIN, {KEY_LEFT_GUI, 'c'}, MACRO_TIME);         // Mac Copy
    controller.addMacro(MAC_PASTE_PIN, {KEY_LEFT_GUI, 'v'}, MACRO_TIME);        // Mac Paste
    controller.addMacro(MAC_PASTE_PLACE_PIN, {KEY_LEFT_GUI, KEY_LEFT_SHIFT, 'v'}, MACRO_TIME);  // Mac Paste in Place
    
    // Common single-key actions (same for both platforms)
    controller.addKeyRelease(ENTER_PIN, KEY_RETURN, SINGLE_TIME);      
    controller.addKeyRelease(TAB_PIN, KEY_TAB, SINGLE_TIME);          
    controller.addKeyRelease(BACKSPACE_PIN, KEY_BACKSPACE, SINGLE_TIME);
    controller.addKeyRelease(SPACE_PIN, ' ', SINGLE_TIME);            
}

void loop() {
    controller.update();
}

/* Usage Instructions:

   Windows Users (pins 2-5):
   - Pin 2: Select All (Ctrl+A)
   - Pin 3: Copy (Ctrl+C)
   - Pin 4: Paste (Ctrl+V)
   - Pin 5: Paste in Place (Shift+Insert)

   Mac Users (pins 6-9):
   - Pin 6: Select All (Cmd+A)
   - Pin 7: Copy (Cmd+C)
   - Pin 8: Paste (Cmd+V)
   - Pin 9: Paste in Place (Cmd+Shift+V)

   Common Controls (Both Platforms):
   - Pin 10: Enter
   - Pin 11: Tab
   - Pin 12: Backspace
   - Pin 13: Space

   Note: Mac uses Command key (KEY_LEFT_GUI) instead of Control for shortcuts
*/