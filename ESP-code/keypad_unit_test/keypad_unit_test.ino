// Use this example with the Adafruit Keypad products.
// You'll need to know the Product ID for your keypad.
// Here's a summary:
//   * PID3844 4x4 Matrix Keypad
//   * PID3845 3x4 Matrix Keypad
//   * PID1824 3x4 Phone-style Matrix Keypad
//   * PID1332 Membrane 1x4 Keypad
//   * PID419  Membrane 3x4 Matrix Keypad

#include "Adafruit_Keypad.h"

// define your specific keypad here via PID
#define KEYPAD_PID3844
// define your pins here
//can ignore ones that don't apply
#define C1    14 //d2 // gpio 14
#define C2    27 //d4 // 27
#define C3    26 //d5 //26
#define C4    25 //d18 //25
#define R1    33 //d19 //33
#define R2    32 //d15 //32
#define R3    12 //d23 //35
#define R4    13       //34

// #define R1    33 //d2 // gpio 14
// #define R2    27  //d4 // 27
// #define R3    35  //d5 //26
// #define R4     25//d18 //25
// #define C1    14  //d19 //33
// #define C2     32//d15 //32
// #define C3     26//d23 //18
// #define C4       34    //19
// leave this import after the above configuration
#include "keypad_config.h"

//initialize an instance of class NewKeypad
Adafruit_Keypad customKeypad = Adafruit_Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);
  customKeypad.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  customKeypad.tick();

  while(customKeypad.available()){
    keypadEvent e = customKeypad.read();
    Serial.print((char)e.bit.KEY);
    if(e.bit.EVENT == KEY_JUST_PRESSED) Serial.println(" pressed");
    else if(e.bit.EVENT == KEY_JUST_RELEASED) Serial.println(" released");
  }

  delay(10);
}