#include <Adafruit_Keypad.h> // Correct inclusion of the library

// define your specific keypad here via PID
#define KEYPAD_PID3845

// define your pins here
#define R4   2 //brown wire
#define R3   4  //red wire
#define R2   5  //orange
#define R1   18   //yellow wire 
#define C1   23 //white wire
#define C2   22 //purple wire
#define C3   21  //blue wire
#define C4   19  //green wire

// Keymap for 4x4 Keypad
char keys[4][4] = {
  {'1','2','3', 'A'},
  {'4','5','6', 'B'},
  {'7','8','9', 'C'},
  {'*','0','#', 'D'}
};

// Row and column pins for 3x4 Keypad
byte rowPins[4] = { R1, R2, R3, R4 };
byte colPins[4] = { C1, C2, C3 , C4 };

// Initialize an instance of class Adafruit_Keypad
Adafruit_Keypad customKeypad = Adafruit_Keypad(makeKeymap(keys), rowPins, colPins, 4, 4);

void setup() {
  Serial.begin(115200);  // Adjusted for ESP32
  customKeypad.begin();
}

void loop() {
  customKeypad.tick();
  while(customKeypad.available()) {
    keypadEvent e = customKeypad.read();
    char key = (char)e.bit.KEY;
    Serial.print(key);
    if (e.bit.EVENT == KEY_JUST_PRESSED) {
      Serial.println(" pressed");
    } else if (e.bit.EVENT == KEY_JUST_RELEASED) {
      Serial.println(" released");
    }
  }

  delay(10);
}
