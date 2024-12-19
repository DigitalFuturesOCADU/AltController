#include "AltController.h"

AltController::AltController() {
    Keyboard.begin();
}

void AltController::addKeyPress(int pin, char key, int sensitivity) {
    if (actionCount >= MAX_ACTIONS) return;
    
    KeyAction& action = actions[actionCount++];
    action.pin = pin;
    action.sensitivity = sensitivity;
    action.type = KeyAction::PRESS;
    action.keys[0] = key;
    action.keyCount = 1;
    
    pinMode(pin, INPUT_PULLUP);
}

void AltController::addKeyRelease(int pin, char key, int sensitivity) {
    if (actionCount >= MAX_ACTIONS) return;
    
    KeyAction& action = actions[actionCount++];
    action.pin = pin;
    action.sensitivity = sensitivity;
    action.type = KeyAction::RELEASE;
    action.keys[0] = key;
    action.keyCount = 1;
    
    pinMode(pin, INPUT_PULLUP);
}

void AltController::addMacro(int pin, std::initializer_list<uint8_t> keys, int sensitivity) {
    if (actionCount >= MAX_ACTIONS) return;
    
    KeyAction& action = actions[actionCount++];
    action.pin = pin;
    action.sensitivity = sensitivity;
    action.type = KeyAction::MACRO;
    
    action.keyCount = 0;
    for (auto key : keys) {
        if (action.keyCount < MAX_MACRO_KEYS) {
            action.keys[action.keyCount++] = key;
        }
    }
    
    pinMode(pin, INPUT_PULLUP);
}

void AltController::addPrint(int pin, const char* text, int sensitivity) {
    if (actionCount >= MAX_ACTIONS) return;
    
    KeyAction& action = actions[actionCount++];
    action.pin = pin;
    action.sensitivity = sensitivity;
    action.type = KeyAction::PRINT;
    
    strncpy(action.printStr, text, MAX_PRINT_LENGTH - 1);
    action.printStr[MAX_PRINT_LENGTH - 1] = '\0';
    
    pinMode(pin, INPUT_PULLUP);
}

void AltController::update() {
    unsigned long currentTime = millis();

    for (int i = 0; i < actionCount; i++) {
        KeyAction& action = actions[i];
        bool buttonPressed = !digitalRead(action.pin);

        switch (action.type) {
            case KeyAction::PRESS:
                handlePress(action, buttonPressed, currentTime);
                break;
                
            case KeyAction::RELEASE:
                handleRelease(action, buttonPressed, currentTime);
                break;
                
            case KeyAction::MACRO:
                handleMacro(action, buttonPressed, currentTime);
                break;

            case KeyAction::PRINT:
                handlePrint(action, buttonPressed, currentTime);
                break;
        }
    }
}

void AltController::handlePress(KeyAction& action, bool buttonPressed, unsigned long currentTime) {
    if (buttonPressed && !action.isPressed) {
        Keyboard.press(action.keys[0]);
        action.isPressed = true;
        action.lastPressTime = currentTime;
    }
    
    if (action.isPressed && (currentTime - action.lastPressTime >= action.sensitivity)) {
        Keyboard.release(action.keys[0]);
        action.isPressed = false;
    }
}

void AltController::handleRelease(KeyAction& action, bool buttonPressed, unsigned long currentTime) {
    // Only trigger on initial press
    if (buttonPressed && !action.wasPressed) {
        Keyboard.press(action.keys[0]);
        action.isPressed = true;
        action.lastPressTime = currentTime;
    }
    
    // Release key after sensitivity time
    if (action.isPressed && (currentTime - action.lastPressTime >= action.sensitivity)) {
        Keyboard.release(action.keys[0]);
        action.isPressed = false;
    }
    
    action.wasPressed = buttonPressed;  // Update state
}

void AltController::handleMacro(KeyAction& action, bool buttonPressed, unsigned long currentTime) {
    // Only trigger on initial press
    if (buttonPressed && !action.wasPressed) {
        for (int i = 0; i < action.keyCount; i++) {
            Keyboard.press(action.keys[i]);
        }
        action.isPressed = true;
        action.lastPressTime = currentTime;
    }
    
    // Release keys after sensitivity time
    if (action.isPressed && (currentTime - action.lastPressTime >= action.sensitivity)) {
        Keyboard.releaseAll();
        action.isPressed = false;
    }
    
    action.wasPressed = buttonPressed;  // Update state
}

void AltController::handlePrint(KeyAction& action, bool buttonPressed, unsigned long currentTime) {
    // Only trigger on initial press
    if (buttonPressed && !action.wasPressed) {
        Keyboard.print(action.printStr);
        action.isPressed = true;
    }
    
    action.wasPressed = buttonPressed;  // Update state
}