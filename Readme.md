# AltController Library

Arduino library for creating custom keyboard controllers. Build custom shortcut panels, gaming controllers, or macro boards using simple buttons with internal pullup resistors.


## Quick Start

```cpp
#include <AltController.h>

AltController controller;

void setup() {
    // Gaming key (hold to use)
    controller.addKeyPress(2, 'w', 50);
    
    // Action key (single press)
    controller.addKeyRelease(3, KEY_RETURN, 100);
    
    // Shortcut (key combination)
    controller.addMacro(4, {KEY_LEFT_CTRL, 'c'}, 100);
    
    // Text entry
    controller.addPrint(5, "Hello World\n", 150);
}

void loop() {
    controller.update();
}
```

## Core Functions

### addKeyPress(pin, key, sensitivity)
Holds down a key while the button is pressed.

```cpp
//These execute continuously, useful for game controls and movement
controller.addKeyPress(2, 'w', 50);  // w key attached to pin 2 with sensitivity of 50
controller.addKeyPress(3, KEY_LEFT_SHIFT, 50);  // SHIFT key attached to pin 3 with sensitivity of 50
controller.addKeyPress(4, KEY_DOWN_ARROW, 25);  // DOWN Arrow attached to pin 4 with sensitivity of 25
```

### addKeyRelease(pin, key, sensitivity)
Single key press per button press. Won't repeat until released.

```cpp
// Execute once, better for exectuting the key singularly
controller.addKeyRelease(5, ' ', 90);  // Spacebar attached to pin 5 with sensitivity of 90
controller.addKeyRelease(6, KEY_RETURN, 100);  // ENTER attached to pin 6 with sensitivity of 100
controller.addKeyRelease(7, KEY_TAB, 75);  // TAB attached to pin 7 with sensitivity of 90
```

### addMacro(pin, {keys}, sensitivity)
Execute key combinations.

```cpp
// Cross-platform shortcuts
controller.addMacro(8, {KEY_LEFT_CTRL, 'c'}, 100);  // Windows Copy attached to pin 8 with sensitivity of 100
controller.addMacro(9, {KEY_LEFT_GUI, 'v'}, 100);   // Mac Paste attached to pin 9 with sensitivity of 100
controller.addMacro(10, {KEY_LEFT_CTRL, KEY_LEFT_SHIFT, 't'}, 100);  // Reopen tab attached to pin 10 with sensitivity of 100
```

### addPrint(pin, text, sensitivity)
Type specified text strings.

```cpp
// Quick text entry
controller.addPrint(11, "user@email.com", 150);  // Email address attached to pin 11 with sensitivity of 150
controller.addPrint(12, "https://arduino.cc\n", 150);  // URL attached to pin 12 with sensitivity of 150
controller.addPrint(13, "Thank you!\n", 150);  // Thank you message attached to pin 13 with sensitivity of 150
```

## Example Projects

### 1. Gaming Controller
```cpp
// WASD + Arrow keys + Space + Enter
controller.addKeyPress(2, 'w', 25);           // Forward
controller.addKeyPress(3, 'a', 25);           // Left
controller.addKeyPress(4, 's', 25);           // Back
controller.addKeyPress(5, 'd', 25);           // Right
controller.addKeyPress(6, KEY_UP_ARROW, 25);  // Camera up
...
```

### 2. Copy/Paste Panel (Cross-Platform)
```cpp
// Windows shortcuts
controller.addMacro(2, {KEY_LEFT_CTRL, 'a'}, 100);  // Select All
controller.addMacro(3, {KEY_LEFT_CTRL, 'c'}, 100);  // Copy
controller.addMacro(4, {KEY_LEFT_CTRL, 'v'}, 100);  // Paste

// Mac shortcuts
controller.addMacro(5, {KEY_LEFT_GUI, 'a'}, 100);   // Select All
controller.addMacro(6, {KEY_LEFT_GUI, 'c'}, 100);   // Copy
controller.addMacro(7, {KEY_LEFT_GUI, 'v'}, 100);   // Paste
```

### 3. Web Browser Control
```cpp
// Tab management
controller.addMacro(2, {KEY_LEFT_CTRL, KEY_TAB}, 100);  // Next tab (Windows)
controller.addMacro(3, {KEY_LEFT_GUI, KEY_TAB}, 100);   // Next tab (Mac)
controller.addPrint(4, "https://arduino.cc\n", 150);    // Quick URL
```

### 4. Photoshop Shortcuts
```cpp
// Launch and new document
controller.addMacro(2, {KEY_LEFT_GUI, ' '}, 100);    // Mac Spotlight
controller.addPrint(3, "photoshop\n", 150);          // Type app name
controller.addMacro(4, {KEY_LEFT_CTRL, 'n'}, 100);   // New doc (Windows)
controller.addMacro(5, {KEY_LEFT_GUI, 'n'}, 100);    // New doc (Mac)
```

## Key Reference

### Modifier Keys
| Windows | Mac | Key Code |
|---------|-----|----------|
| Ctrl | Command | KEY_LEFT_CTRL / KEY_LEFT_GUI |
| Shift | Shift | KEY_LEFT_SHIFT |
| Alt | Option | KEY_LEFT_ALT |
| Win | Command | KEY_LEFT_GUI |

### Navigation Keys
| Key | Code |
|-----|------|
| Arrow Keys | KEY_UP_ARROW, KEY_DOWN_ARROW, KEY_LEFT_ARROW, KEY_RIGHT_ARROW |
| Page Control | KEY_PAGE_UP, KEY_PAGE_DOWN, KEY_HOME, KEY_END |
| Editing | KEY_BACKSPACE, KEY_DELETE, KEY_INSERT, KEY_TAB, KEY_RETURN |
| Function | KEY_F1 through KEY_F24 |

## Timing Guidelines
- 25-50ms: Fast response (gaming)
- 75-100ms: Standard (shortcuts)
- 150ms+: Text entry

## Hardware Setup
- MAKE A BUTTON between pins and ground
- Uses internal pullup resistors
- No external resistors needed
- Compatible with most momentary switches

