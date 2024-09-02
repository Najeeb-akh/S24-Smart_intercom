//  this is for lock firebase time and audio


/*************************************************/
/*                                                         WIFI CONNECTION                                                                         */
/*************************************************/
//this code makes the speaker make noise when pressing akey on the keypad
#include <Adafruit_Keypad.h> // Correct inclusion of the library
#include <Arduino.h>
#include <driver/i2s.h>
#include <math.h>
#include <ezOutput.h>
// WiFi and Firebase setup
#include <ESP32Firebase.h>
#define _SSID "ICST"          // Your WiFi SSID
#define _PASSWORD "arduino123"    // Your WiFi Password

#define UNLOCK_TIME 3000 // in milliseconds

#define RELAY_PIN   32 // ESP32 pin GPIO27 connected to the solenoid lock relay
//ezOutput relay(RELAY_PIN);

// Define the pins for RGB LED (assuming common cathode)
const int redPin = 13;    // Red pin

// define your specific keypad here via PID
#define KEYPAD_PID3845


const String password = "1234"; // change your password here
String input_password;

// define your pins here
#define R4   15 //brown wire
#define R3   4  //red wire
#define R2   5  //orange
#define R1   18   //yellow wire 
#define C1   23 //white wire
#define C2   22 //purple wire
#define C3   21  //blue wire
#define C4   19  //green wire

// /* 2. Define the API Key */
// #define API_KEY "AIzaSyAHANIi3AEgVl8ir3Cs5ePn6qJLWD9LY1Y"

// /* 3. Define the RTDB URL */
// #define DATABASE_URL "https://console.firebase.google.com/u/0/project/smartdoorbell-7e38f/database/smartdoorbell-7e38f-default-rtdb/data/~2F" //<databaseName>.firebaseio.com or <databaseName>.<region>.firebasedatabase.app
//https://console.firebase.google.com/u/0/project/smartdoorbell-7e38f/database/smartdoorbell-7e38f-default-rtdb/data/~2F
#define REFERENCE_URL "https://smartdoorbell-7e38f-default-rtdb.firebaseio.com/"
//https://console.firebase.google.com/u/0/project/smartdoorbell-7e38f/database/smartdoorbell-7e38f-default-rtdb/data/~2F"
#define FIREBASE_AUTH "AIzaSyAHANIi3AEgVl8ir3Cs5ePn6qJLWD9LY1Y"

Firebase firebase(REFERENCE_URL);

void firebaseSetup() {
  Serial.println("Connecting to WIFI: Pending...");
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(1000);
  WiFi.begin(_SSID, _PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    //freeplay();
    delay(10);
    //Serial.print("-");
  }
  Serial.println("Connected to WIFI");
}

int firebaseReadLock() {
  int lck = firebase.getInt("lck");

  return lck;
}


// Keymap for 4x4 Keypad
char keys[4][4] = {
  {'1','2','3', 'A'},
  {'4','5','6', 'B'},
  {'7','8','9', 'C'},
  {'*','0','#', 'D'}
};
//////audio defines 


// Define I2S pins
#define I2S_NUM         I2S_NUM_0
#define I2S_BCK_PIN     26
#define I2S_WS_PIN      27
#define I2S_DATA_PIN    25
#define SAMPLE_RATE     44100
#define PI              3.14159265358979323846

static float phase = 0;
size_t bytes_written;
int16_t samples[64];
int frequency = 700;

// Row and column pins for 3x4 Keypad
byte rowPins[4] = { R1, R2, R3, R4 };
byte colPins[4] = { C1, C2, C3 , C4 };

// Initialize an instance of class Adafruit_Keypad
Adafruit_Keypad customKeypad = Adafruit_Keypad(makeKeymap(keys), rowPins, colPins, 4, 4);

unsigned long lastLockCheckTime = 0; // Variable to keep track of the last lock check time
const unsigned long lockCheckInterval = 10000; // Check the lock every 5 seconds

//helper function for dynamically generating audio samples


void generateSamples(int16_t* samples, int sample_count, int frequency) {
    for (int i = 0; i < sample_count; i++) {
        samples[i] = (int16_t)(32767 * sin(phase));
        phase += 2 * PI * frequency / SAMPLE_RATE;
        if (phase >= 2 * PI) {
            phase -= 2 * PI;
        }
    }
}


// hard-coded passwords
void setup() {
  // pinMode(27, OUTPUT) ;
  pinMode(RELAY_PIN, OUTPUT);
  //pinMode(redPin, OUTPUT);
  Serial.begin(9600);  // Adjusted for ESP32
  //input_password.reserve(32);
  customKeypad.begin();
  digitalWrite(RELAY_PIN, HIGH);
  Serial.println("Connecting to WIFI: Pending...");
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(1000);
  WiFi.begin(_SSID, _PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    //freeplay();
    delay(10);
    Serial.print("-");
  }
  Serial.println("Connected to WIFI");


  

  // I2S configuration
  i2s_config_t i2s_config = {
    .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_TX),  // Master, TX only
    .sample_rate = SAMPLE_RATE,
    .bits_per_sample = I2S_BITS_PER_SAMPLE_16BIT,
    .channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT,
    .communication_format = I2S_COMM_FORMAT_I2S_MSB,
    .intr_alloc_flags = 0, // default interrupt priority
    .dma_buf_count = 8,
    .dma_buf_len = 64,
    .use_apll = false,
    .tx_desc_auto_clear = true,
    .fixed_mclk = 0
  };

  // I2S pin configuration
  i2s_pin_config_t pin_config = {
    .bck_io_num = I2S_BCK_PIN,
    .ws_io_num = I2S_WS_PIN,
    .data_out_num = I2S_DATA_PIN,
    .data_in_num = I2S_PIN_NO_CHANGE
  };

  // Install and start I2S driver
  i2s_driver_install(I2S_NUM, &i2s_config, 0, NULL);
  i2s_set_pin(I2S_NUM, &pin_config);
  i2s_zero_dma_buffer(I2S_NUM);

}

void loop() {
  
  for (int i = 0; i < 64; i++) 
  {
    samples[i] = (int16_t)(32767 * sin(phase));
    phase += 2 * PI * frequency / SAMPLE_RATE;
    if (phase >= 2 * PI) {
      phase -= 2 * PI;
    }
  }

  // Check lock status every 5 seconds
  unsigned long currentTime = millis();
  if (currentTime - lastLockCheckTime >= lockCheckInterval) {
    lastLockCheckTime = currentTime;
    int lock = firebase.getInt("lock");
    Serial.println(lock);
    
    if(lock > 1) {
      digitalWrite(RELAY_PIN, LOW); // Unlock the door
      int j=0;
      generateSamples(samples, 64,700);
      while(j<500){
      i2s_write(I2S_NUM, samples, sizeof(samples), &bytes_written, portMAX_DELAY);
      j++;
      }
      delay(1000);
      digitalWrite(RELAY_PIN, HIGH); // Lock the door
      firebase.setInt("lock", 1);
    }
  
  }
  unsigned long currentTime2 = millis();
  unsigned int lastLockCheckTime2 = 0 ; 
  if (currentTime2 - lastLockCheckTime2 >= 2000) {
    lastLockCheckTime2 = currentTime2;
  // Continuously watch the keypad
  customKeypad.tick();
  if(customKeypad.available()){
    keypadEvent e = customKeypad.read();
    char key = (char)e.bit.KEY;
    
    if (e.bit.EVENT == KEY_JUST_PRESSED) {
      Serial.print(key);
      Serial.println(" pressed");
      if (key == '*') {
        input_password = ""; // reset the input password
        
      } else if (key == '#') 
      {
        
        if(input_password == password)
        {
          // note to self: take care of the beeping sequence later ***
          generateSamples(samples, 64,9000);
          digitalWrite(RELAY_PIN, LOW); // Unlock the door
          int j=0;
          frequency = 2000;
          while(j<200){
          i2s_write(I2S_NUM, samples, sizeof(samples), &bytes_written, portMAX_DELAY);
          j++;
          }  
          delay(1000);
          digitalWrite(RELAY_PIN, HIGH); // Lock the door
        }
        else
        {
          Serial.println("Invalid Password => Try again");
        }

        input_password = ""; // reset the input password


      }else {
      input_password += key; // append new character to input password string
      }

      // if (key == 'A') 
      // {
      //   // note to self: take care of the beeping sequence later ***
      //   generateSamples(samples, 64,9000);
      //   digitalWrite(RELAY_PIN, LOW); // Unlock the door
      //   int j=0;
      //   frequency = 2000;
      //   while(j<200){
      //   i2s_write(I2S_NUM, samples, sizeof(samples), &bytes_written, portMAX_DELAY);
      //   j++;
      //   }  
      //   delay(1000);
      //   digitalWrite(RELAY_PIN, HIGH); // Lock the door
      // }
    }
  }
  }
}
















