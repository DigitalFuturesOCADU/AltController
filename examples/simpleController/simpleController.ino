/*
  Controller Example for AltController Library
  
  This example creates a gamepad-style controller using:
  - WASD keys for primary movement (pins 2,3,4,5)
  - Arrow keys for secondary movement (pins 6,7,8,9)
  - Spacebar for jump/action (pin 10)
  - Enter for select/start (pin 11)
  
  Connection:
  - Connect buttons between the specified pins and ground
  - Internal pullup resistors are used, no external resistors needed
  
  Button Layout:
       [W]        [↑]
    [A][S][D]  [←][↓][→]
    
    [SPACE]     [ENTER]
*/

#include <AltController.h>

// Pins for WASD keys
const int W_PIN = 2;
const int A_PIN = 3;
const int S_PIN = 4;
const int D_PIN = 5;

// Pins for Arrow keys
const int UP_PIN = 6;
const int LEFT_PIN = 7;
const int DOWN_PIN = 8;
const int RIGHT_PIN = 9;

// Pins for action keys
const int SPACE_PIN = 10;
const int ENTER_PIN = 11;

// Timing configuration (in milliseconds)
const int KEY_HOLD_TIME = 25;    // Quick response for movement keys
const int ACTION_HOLD_TIME = 50; // Slightly longer for action buttons

AltController controller;

void setup() {
    // Configure WASD keys
    controller.addKeyPress(W_PIN, 'w', KEY_HOLD_TIME);
    controller.addKeyPress(A_PIN, 'a', KEY_HOLD_TIME);
    controller.addKeyPress(S_PIN, 's', KEY_HOLD_TIME);
    controller.addKeyPress(D_PIN, 'd', KEY_HOLD_TIME);
    
    // Configure Arrow keys
    controller.addKeyPress(UP_PIN, KEY_UP_ARROW, KEY_HOLD_TIME);
    controller.addKeyPress(LEFT_PIN, KEY_LEFT_ARROW, KEY_HOLD_TIME);
    controller.addKeyPress(DOWN_PIN, KEY_DOWN_ARROW, KEY_HOLD_TIME);
    controller.addKeyPress(RIGHT_PIN, KEY_RIGHT_ARROW, KEY_HOLD_TIME);
    
    // Configure action keys
    controller.addKeyPress(SPACE_PIN, ' ', ACTION_HOLD_TIME);          // Spacebar
    controller.addKeyPress(ENTER_PIN, KEY_RETURN, ACTION_HOLD_TIME);   // Enter
}

void loop() 
{
    controller.update();
}