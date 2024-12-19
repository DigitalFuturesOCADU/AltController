#ifndef ALT_CONTROLLER_H
#define ALT_CONTROLLER_H

#include <Keyboard.h>
#include <initializer_list>

class AltController {
private:
    static const int MAX_ACTIONS = 20;  // Maximum number of key actions
    static const int MAX_MACRO_KEYS = 5;  // Maximum keys in a macro combination
    static const int MAX_PRINT_LENGTH = 100;  // Maximum length for printed strings
    
    struct KeyAction {
        int pin;
        bool isPressed = false;
        bool wasPressed = false;
        bool processedFlag = false;
        unsigned long lastPressTime = 0;
        int sensitivity;  // Press duration in ms
        uint8_t keys[MAX_MACRO_KEYS];  // Array to store multiple keys for macros
        int keyCount = 0;  // Number of keys in the combination
        char printStr[MAX_PRINT_LENGTH];  // Buffer for print string
        enum Type {
            PRESS,    // Hold while pressed (like 'w')
            RELEASE,  // Single press, no repeat (like 'a')
            MACRO,    // Combination of keys (like ctrl+c)
            PRINT     // Print a string
        } type;
    };

    KeyAction actions[MAX_ACTIONS];
    int actionCount = 0;

    void handlePress(KeyAction& action, bool buttonPressed, unsigned long currentTime);
    void handleRelease(KeyAction& action, bool buttonPressed, unsigned long currentTime);
    void handleMacro(KeyAction& action, bool buttonPressed, unsigned long currentTime);
    void handlePrint(KeyAction& action, bool buttonPressed, unsigned long currentTime);

public:
    AltController();
    void addKeyPress(int pin, char key, int sensitivity = 50);
    void addKeyRelease(int pin, char key, int sensitivity = 10);
    void addMacro(int pin, std::initializer_list<uint8_t> keys, int sensitivity = 10);
    void addPrint(int pin, const char* text, int sensitivity = 10);
    void update();
};

#endif