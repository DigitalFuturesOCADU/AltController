/*
  Word Automation Example for AltController Library
  
  Features:
  - Windows Search (Windows + 'word' + Enter) on pin 2
  - Mac Spotlight (Command + Space) on pin 3
  - Enter key on pin 4
  - Type 'word' on pin 5
  - Type custom message on pin 6
  
  Connection:
  - Connect buttons between the specified pins and ground
  - Internal pullup resistors are used, no external resistors needed
*/

#include <AltController.h>

// Pin assignments
const int WIN_SEARCH_PIN = 2;
const int MAC_SPOTLIGHT_PIN = 3;
const int ENTER_PIN = 4;
const int TYPE_WORD_PIN = 5;
const int MESSAGE_PIN = 6;

// Timing configuration (in milliseconds)
const int MACRO_TIME = 100;    // For key combinations
const int KEY_TIME = 50;       // For single keys
const int TYPE_TIME = 150;     // For text typing

AltController controller;

void setup() {
    // Windows key (GUI key)
    controller.addKeyPress(WIN_SEARCH_PIN, KEY_LEFT_GUI, MACRO_TIME);
    
    // Mac Spotlight (Command + Space)
    controller.addMacro(MAC_SPOTLIGHT_PIN, {KEY_LEFT_GUI, ' '}, MACRO_TIME);
    
    // Enter key
    controller.addKeyRelease(ENTER_PIN, KEY_RETURN, KEY_TIME);
    
    // Type "word"
    controller.addPrint(TYPE_WORD_PIN, "word", TYPE_TIME);
    
    // Type message and press enter
    controller.addPrint(MESSAGE_PIN, "All work and no play makes Jack a dull boy.\n", TYPE_TIME);
}

void loop() {
    controller.update();
}

/* Usage Instructions:

   For Windows:
   1. Press Windows key (pin 2)
   2. Press Type Word (pin 5)
   3. Press Enter (pin 4)

   For Mac:
   1. Press Mac Spotlight (pin 3)
   2. Press Type Word (pin 5)
   3. Press Enter (pin 4)

   After Word opens:
   - Press Message (pin 6) to type message with automatic Enter
*/