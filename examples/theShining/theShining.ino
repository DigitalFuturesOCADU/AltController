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
int WIN_SEARCH_PIN = 2;
int MAC_SPOTLIGHT_PIN = 3;
int ENTER_PIN = 4;
int TYPE_WORD_PIN = 5;
int MESSAGE_PIN = 6;

// Timing configuration (in milliseconds)
int MACRO_TIME = 100;    // For key combinations
int KEY_TIME = 50;       // For single keys
int TYPE_TIME = 200;     // For text typing

AltController controller;

void setup() {
    // Windows key (GUI key)
    controller.addKeyPress(WIN_SEARCH_PIN, KEY_LEFT_GUI, MACRO_TIME);
    
    // Mac Spotlight (Command + Space)
    controller.addMacro(MAC_SPOTLIGHT_PIN, {KEY_LEFT_GUI, ' '}, MACRO_TIME);
    
    // Enter key
    controller.addKeyRelease(ENTER_PIN, KEY_RETURN, KEY_TIME);
    
    // Type "word"
    controller.addPrint(TYPE_WORD_PIN, "word\n", TYPE_TIME);
    
    // Type message and press enter
    controller.addPrint(MESSAGE_PIN, "All work and no play makes Jack a dull boy.\n", TYPE_TIME);
}

void loop() {
    controller.update();
}

