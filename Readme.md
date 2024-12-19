# AltController Library

Provides a simple wrapper for the Arduino Keyboard library to combine simple keypresses, macros, and writing text.
Created for Physical Computing Project 1

## Basic Usage

```cpp
#include <AltController.h>

AltController controller;

void setup() {
    // Create different types of key actions
    controller.addKeyPress(2, 'a', 50);                    // Hold 'a' while pressed
    controller.addKeyRelease(3, 'b', 90);                  // Single press 'b'
    controller.addMacro(4, {KEY_LEFT_CTRL, 'c'}, 100);    // Ctrl+C combination
    controller.addPrint(5, "Hello\n", 150);               // Type "Hello" + Enter
}

void loop() {
    controller.update();
}
```

## Core Functions

- `addKeyPress(pin, key, sensitivity)`: Key remains pressed while button is held
- `addKeyRelease(pin, key, sensitivity)`: Single key press per button press
- `addMacro(pin, {keys}, sensitivity)`: Key combination (e.g., Ctrl+C)
- `addPrint(pin, text, sensitivity)`: Types the specified text string
- `update()`: Must be called in loop() to process all buttons

## Examples

### 1. Controller
A gamepad-style controller with:
- WASD keys
- Arrow keys
- Spacebar
- Enter key

### 2. CopyPaste
Text editing shortcuts:
- Select All (Ctrl+A)
- Copy (Ctrl+C)
- Paste (Ctrl+V)
- Paste in Place (Shift+Insert)
- Navigation keys (Enter, Tab, Backspace, Space)

### 3. WebControl
Web browser control with:
- Tab management (Next, Previous, New)
- Navigation (Arrows, Page Up/Down)
- Quick URL access
- Basic controls (Enter, Space)

### 4. Photoshop
Cross-platform Photoshop launcher:
- Windows/Mac search
- Application launch
- New document creation

## Key Reference

### Modifier Keys
| Key | Description |
|-----|-------------|
| KEY_LEFT_CTRL  | Left Control |
| KEY_LEFT_SHIFT | Left Shift |
| KEY_LEFT_ALT   | Left Alt (Option on Mac) |
| KEY_LEFT_GUI   | Windows/Command key |
| KEY_RIGHT_CTRL | Right Control |
| KEY_RIGHT_SHIFT| Right Shift |
| KEY_RIGHT_ALT  | Right Alt (AltGr/Option) |
| KEY_RIGHT_GUI  | Windows/Command key |

### Special Keys
| Key | Description |
|-----|-------------|
| KEY_TAB        | Tab |
| KEY_CAPS_LOCK  | Caps Lock |
| KEY_BACKSPACE  | Backspace |
| KEY_RETURN     | Enter/Return |
| KEY_MENU       | Menu |
| KEY_INSERT     | Insert |
| KEY_DELETE     | Delete |
| KEY_HOME       | Home |
| KEY_END        | End |
| KEY_PAGE_UP    | Page Up |
| KEY_PAGE_DOWN  | Page Down |

### Arrow Keys
| Key | Description |
|-----|-------------|
| KEY_UP_ARROW    | Up Arrow |
| KEY_DOWN_ARROW  | Down Arrow |
| KEY_LEFT_ARROW  | Left Arrow |
| KEY_RIGHT_ARROW | Right Arrow |

### Function Keys
| Key Range | Description |
|-----------|-------------|
| KEY_F1 through KEY_F12  | Standard Function Keys |
| KEY_F13 through KEY_F24 | Extended Function Keys |

### Control Keys
| Key | Description |
|-----|-------------|
| KEY_PRINT_SCREEN | Print Screen/SysRq |
| KEY_SCROLL_LOCK  | Scroll Lock |
| KEY_PAUSE        | Pause/Break |

### Numeric Keypad
| Key | Description |
|-----|-------------|
| KEY_NUM_LOCK    | Num Lock |
| KEY_KP_SLASH    | Keypad / |
| KEY_KP_ASTERISK | Keypad * |
| KEY_KP_MINUS    | Keypad - |
| KEY_KP_PLUS     | Keypad + |
| KEY_KP_ENTER    | Keypad Enter |
| KEY_KP_0 to KEY_KP_9 | Keypad Numbers |
| KEY_KP_DOT      | Keypad . |



## License

This library is released under the [MIT License](LICENSE).

