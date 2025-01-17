# AltController Library

The AltController library simplifies the creation of custom keyboard inputs for Arduino by creating a wrapper for the [Keyboard](https://docs.arduino.cc/language-reference/en/functions/usb/Keyboard/) library.
 It allows the simple creation of different types of inputs that can be polled at different rates.

- Keypress continuously sends the letter/button as if the key is held down
- KeyReleasse sends the letter/button once when the connection has been made then released
- Macro sends combinations of keys from a single pin simliar to KeyReleasse
- Print types words or phrases using the KeyReleasse behavior

## Table of Contents
- [Installation](#installation)
- [Basic Usage](#basic-usage)
- [Core Functions](#core-functions)
    - [Sensitivity](#sensitivity)
    - [addKeyPress](#addkeypresspin-key-sensitivity)
    - [addKeyRelease](#addkeyreleasepin-key-sensitivity)
    - [addMacro](#addmacropin-keys-sensitivity)
    - [addPrint](#addprintpin-text-sensitivity)
- [Example Projects](#example-projects)
    - [Uploading Example Projects](#uploading-example-projects)
    - [Simple Controller](#1-simple-controller)
    - [Copy/Paste Panel](#2-copypaste-panel)
    - [Web Browser Control](#3-web-browser-control)
    - [Photoshop Shortcuts](#4-photoshop-shortcuts)
    - [The Shining](#5-the-shining)
- [Key Reference](#key-reference)
    - [Modifier Keys](#modifier-keys)
    - [Special Keys](#special-keys)
    - [Arrow Keys](#arrow-keys)
    - [Function Keys](#function-keys)
    - [Control Keys](#control-keys)
    - [Numeric Keypad](#numeric-keypad)
- [Hardware Setup](#hardware-setup)

## Installation
The library can be installed directly from the Arduino Library Manager

## Basic Usage

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

### Sensitivity
All of the functions include a 'sensitivity' parameter that controls how often the pin is being checked.

Lower Value = Faster Response

If you are experiencing double/triple key triggers, try making the value larger.


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

### Uploading Example Projects
Uploading Keyboard Emulation code to an Arduino is slightly different that typical code. 

1. Double Tap the Reset Button to put the board into Bootloader mode. If this is successful, the onboard LED will begin pulsing.
2. Select the Arduino from the device list in the IDE. This is required because it has a different serial port than when it is acting as a keyboard.
3. Upload the code.

### 1. Simple Controller
This example provides typical key inputs for game controls : W,A,S,D + Arrow Keys + Spacebar + Enter

Connect wires the the corresponding pins + Gnd and test with existing games. Works for both Mac & PC

![Simple Controller Breadboard](wiring%20diagrams/simpleController_bb.png)


```cpp
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

```

### 2. Copy/Paste Panel 
This example provides simple control of macros for Mac and PC. Rather than pressing the combination of keys as you would on a standard keyboard, the action is tied to a single pin. touch the wire to ground to activate the particular action. 

Try it out within any text editor. The same code is used for both Mac & PC, but there are different wiring patterns since the commands are different.

![Copy/Paste Panel Breadboard](wiring%20diagrams/copyPaste_Mac_bb.png)
![Copy/Paste Panel Breadboard](wiring%20diagrams/copyPaste_PC_bb.png)

```cpp
    // Windows shortcuts
    controller.addMacro(WIN_SELECT_ALL_PIN, {KEY_LEFT_CTRL, 'a'}, MACRO_TIME);    // Select All
    controller.addMacro(WIN_COPY_PIN, {KEY_LEFT_CTRL, 'c'}, MACRO_TIME);         // Copy
    controller.addMacro(WIN_PASTE_PIN, {KEY_LEFT_CTRL, 'v'}, MACRO_TIME);        // Paste
    controller.addMacro(WIN_PASTE_PLACE_PIN, {KEY_LEFT_SHIFT, KEY_INSERT}, MACRO_TIME);  // Paste in Place
    
    // Mac shortcuts
    controller.addMacro(MAC_SELECT_ALL_PIN, {KEY_LEFT_GUI, 'a'}, MACRO_TIME);    // Select All
    controller.addMacro(MAC_COPY_PIN, {KEY_LEFT_GUI, 'c'}, MACRO_TIME);         //  Copy
    controller.addMacro(MAC_PASTE_PIN, {KEY_LEFT_GUI, 'v'}, MACRO_TIME);        //  Paste
    controller.addMacro(MAC_PASTE_PLACE_PIN, {KEY_LEFT_GUI, KEY_LEFT_SHIFT, 'v'}, MACRO_TIME);  //  Paste in Place
    
    // Common single-key actions (same for both platforms)
    controller.addKeyRelease(ENTER_PIN, KEY_RETURN, SINGLE_TIME);     //Enter 
    controller.addKeyRelease(TAB_PIN, KEY_TAB, SINGLE_TIME);          //Tab
    controller.addKeyRelease(BACKSPACE_PIN, KEY_BACKSPACE, SINGLE_TIME); //Backspace
    controller.addKeyRelease(SPACE_PIN, ' ', SINGLE_TIME); //Spacebar
```

### 3. Web Browser Control
This example provides typical inputs for controlling a Web Browser. Rather than using key combinations, the action is tied to a single pin. Just connect the corresponding wire to ground.

The same code is used for Mac & PC, but wiring is different as the commands are different
![Web Control Panel Breadboard](wiring%20diagrams/webControl_Mac_bb.png)
![Web Control Panel Breadboard](wiring%20diagrams/webControl_PC_bb.png)

```cpp
    // Windows tab management macros
    controller.addMacro(WIN_NEXT_TAB_PIN, {KEY_LEFT_CTRL, KEY_TAB}, MACRO_TIME);// Windows next tab
    controller.addMacro(WIN_NEW_TAB_PIN, {KEY_LEFT_CTRL, 't'}, MACRO_TIME); // Windows new tab
    controller.addMacro(WIN_PREV_TAB_PIN, {KEY_LEFT_CTRL, KEY_LEFT_SHIFT, KEY_TAB}, MACRO_TIME); // Windows prev tab
    
    // Mac tab management macros
    controller.addMacro(MAC_NEXT_TAB_PIN, {KEY_LEFT_GUI, KEY_LEFT_ALT, KEY_RIGHT_ARROW}, MACRO_TIME); // Mac next tab
    controller.addMacro(MAC_NEW_TAB_PIN, {KEY_LEFT_GUI, 't'}, MACRO_TIME);// Mac new tab
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
```

### 4. Photoshop Shortcuts
This example provides methods to Open Photoshop and create a new file. 

On Mac the sequence is
1. Trigger Spotlight Search : Pin 3
2. Type out photoshop and press enter : Pin 5
3. Create a new document : Pin 7

On Windows the sequence is
1. Trigger Windows Search : Pin 2
2. Type out photoshop and press enter : Pin 5
3. Create a new document : Pin 6

![Photoshop Shortcuts Breadboard](wiring%20diagrams/photoshop_Mac_bb.png)
![Photoshop Shortcuts Breadboard](wiring%20diagrams/photoshop_PC_bb.png)
```cpp
    // Windows key (GUI key)
    controller.addKeyPress(WIN_SEARCH_PIN, KEY_LEFT_GUI, MACRO_TIME);
    
    // Mac Spotlight (Command + Space)
    controller.addMacro(MAC_SPOTLIGHT_PIN, {KEY_LEFT_GUI, ' '}, MACRO_TIME);
    
    // Enter key
    controller.addKeyRelease(ENTER_PIN, KEY_RETURN, KEY_TIME);
    
    // Type "photoshop"
    controller.addPrint(TYPE_PS_PIN, "photoshop\n", TYPE_TIME);
    
    // New Document shortcuts for both platforms
    controller.addMacro(WIN_NEW_DOC_PIN, {KEY_LEFT_CTRL, 'n'}, MACRO_TIME);  // Windows: Ctrl+N
    controller.addMacro(MAC_NEW_DOC_PIN, {KEY_LEFT_GUI, 'n'}, MACRO_TIME);   // Mac: Cmd+N

```
### 5. The Shining
[This example allows you to re-enact this scene from The Shining](https://www.youtube.com/watch?v=4lQ_MjU4QHw)

On Mac the sequence is
1. Trigger Spotlight Search : Pin 3
2. Type out word and press enter : Pin 5
3. Type out the phrase : Pin 6

On Windows the sequence is
1. Trigger Spotlight Search : Pin 2
2. Type out word and press enter : Pin 5
3. Type out the phrase : Pin 6

![The Shining Shortcuts Breadboard](wiring%20diagrams/theShining_Mac_bb.png)
![The Shining Shortcuts Breadboard](wiring%20diagrams/theShining_PC_bb.png)

```cpp
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

```

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



## Hardware Setup
- MAKE A BUTTON between pins and ground
- Uses internal pullup resistors
- No external resistors needed
- Compatible with most momentary switches

