/*
  Basic Start Point for AltController Library
  
  *Includes
  -Adding the Library to the file
  -Creating an AltController variable (You only need one of these for all the inputs)
  -Running the .update() function in the loop. No need to change this

  *What you need to figure out
  1) What kind of input do you want to add? See : https://github.com/DigitalFuturesOCADU/AltController
  --.addKeyPress()
  --.addKeyRelease()
  --.addMacro()
  --.addPrint()
  --Each of these commands require the same 3 parameters
  --(PIN NUMBER,"What you want it to trigger", SENSITIVITY)
  --For Example:
  ---controller.addKeyPress(2, 'w', 50);  // w key attached to pin 2 with sensitivity of 50
  ---controller.addKeyRelease(6, KEY_RETURN, 100);  // ENTER attached to pin 6 with sensitivity of 100
  ---controller.addMacro(8, {KEY_LEFT_CTRL, 'c'}, 100);  // Windows Copy attached to pin 8 with sensitivity of 100
  ---controller.addMacro(9, {KEY_LEFT_GUI, 'v'}, 100);   // Mac Paste attached to pin 9 with sensitivity of 100
  ---controller.addPrint(12, "https://arduino.cc\n", 150);  // URL attached to pin 12 with sensitivity of 150
  2) Which Pin Number is it attached to?
  --Connect 1 Jumper to the Pin
  --Connect 1 Jumper to GND (Multiple pins can share the same ground)
  3) What do you want it to trigger (See 1) for examples
  4) Set the Sensitivity (How often it is checking the status of the pin)
  -This value will vary greatly based on the object and the behaviour you want

  *All of these should be added inside setup()

  *To upload the code, you must put it into bootloader mode
  -Double-tap the Reset button on the Arduino
  -Select the Correct port
  -Hit the upload button




*/

#include <AltController.h> //add the AltController library

//Add variables for the Pin Numbers and Sensitivity here




AltController controller;

void setup() 
{
//Add the commands here  

}

void loop() 
{
    controller.update();
}