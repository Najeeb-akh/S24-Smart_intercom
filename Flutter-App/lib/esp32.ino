// // #include <ESP32Firebase.h>
// // #include <WiFi.h>
// // #include <Adafruit_Keypad.h> // Correct inclusion of the library
// // #include <Arduino.h>
// // #include <driver/i2s.h>
// // #include <math.h>
// // #include <ezOutput.h>
// // #include <ArduinoJson.h>
// // #include <time.h>

// // // WiFi and Firebase setup:

// // //#include <FirebaseJson.h>  
// // #define _SSID "ICST"          // Your WiFi SSID
// // #define _PASSWORD "arduino123"    // Your WiFi Password

// // #define UNLOCK_TIME 3000 // in milliseconds

// // // /* 2. Define the API Key */
// // // #define API_KEY "AIzaSyAHANIi3AEgVl8ir3Cs5ePn6qJLWD9LY1Y"

// // // /* 3. Define the RTDB URL */
// // #define DATABASE_URL "https://console.firebase.google.com/u/0/project/smartdoorbell-7e38f/database/smartdoorbell-7e38f-default-rtdb/data/~2F" //<databaseName>.firebaseio.com or <databaseName>.<region>.firebasedatabase.app
// // //https://console.firebase.google.com/u/0/project/smartdoorbell-7e38f/database/smartdoorbell-7e38f-default-rtdb/data/~2F
// // #define REFERENCE_URL "https://smartdoorbell-7e38f-default-rtdb.firebaseio.com/"
// // //https://console.firebase.google.com/u/0/project/smartdoorbell-7e38f/database/smartdoorbell-7e38f-default-rtdb/data/~2F"
// // #define FIREBASE_AUTH "AIzaSyAHANIi3AEgVl8ir3Cs5ePn6qJLWD9LY1Y"


// // const String password = "123"; // change your password here
// // String input_password;




// // // Define the pins for RGB LED green and red and blue
// // const int redPin = 13;    // Red pin red wire
// // const int greenPin = 12;    // Green pin green wire
// // const int bluePin = 14;    // blue pin blue wire





// // /***     here is the keypad configoration code ***/


// // // define your specific keypad here via PID
// // #define KEYPAD_PID3845


// // // define your pins here for keypad
// // #define R4   15 //brown wire
// // #define R3   4  //red wire
// // #define R2   5  //orange
// // #define R1   18   //yellow wire 
// // #define C1   23 //white wire
// // #define C2   22 //purple wire
// // #define C3   21  //blue wire
// // #define C4   19  //green wire

// // // Keymap for 4x4 Keypad
// // char keys[4][4] = {
// //   {'1','2','3', 'A'},
// //   {'4','5','6', 'B'},
// //   {'7','8','9', 'C'},
// //   {'*','0','#', 'D'}
// // };

// // // Row and column pins for 3x4 Keypad
// // byte rowPins[4] = { R1, R2, R3, R4 };
// // byte colPins[4] = { C1, C2, C3 , C4 };

// // // Initialize an instance of class Adafruit_Keypad
// // Adafruit_Keypad customKeypad = Adafruit_Keypad(makeKeymap(keys), rowPins, colPins, 4, 4);



// // bool lockStatus = false; // false means unlocked, true means locked

// // /***     end of keypad configoration    ***/




// // /***     here is the implifier configoration code and sound functions ***/


// // // Define I2S pins for implifier and speaker
// // #define I2S_NUM         I2S_NUM_0
// // #define I2S_BCK_PIN     26
// // #define I2S_WS_PIN      27
// // #define I2S_DATA_PIN    25
// // #define SAMPLE_RATE     44100
// // #define PI              3.141592


// // //sound functions

// // //sound when a key is pressed 
// // void KeyPressedSound() //sound when any key is pressed
// // {
// //   static float phase = 0;
// //   size_t bytes_written;
// //   int16_t samples[64];
// //    // Generate a 1kHz sine wave
// //   for (int i = 0; i < 64; i++) {
// //          samples[i] = (int16_t)(32767 * sin(phase));
// //          phase += 2 * PI * 5000 / SAMPLE_RATE;
// //          if (phase >= 2 * PI) {
// //             phase -= 2 * PI;
// //         }
// //       }
// //       int j = 0;
// //       while(j<200){
// //         //i2s_write(I2S_NUM, samples, sizeof(samples), &bytes_written, portMAX_DELAY);
// //         j++;
// //       }
// // }


// // //when input is empty and user presses #
// // void EmptyPasswordSound() 
// // {
// //   analogWrite(bluePin, 0); //blue light off
// //   analogWrite(greenPin, 0); //blue light off
// //   analogWrite(redPin, 255); //red light on
// //   Serial.println("empty password");
// //   static float phase = 0;
// //   size_t bytes_written;
// //   int16_t samples[64];
// //    // Generate a cossine wave
// //   for (int i = 0; i < 64; i++) {
// //          samples[i] = (int16_t)(10000000 * cos(phase));
// //          phase += 2 * PI * 5000 / SAMPLE_RATE;
// //          if (phase >= 2 * PI) {
// //             phase -= 2 * PI;
// //         }
// //       }
// //       int j = 0;
// //       while(j<1000){
// //         //i2s_write(I2S_NUM, samples, sizeof(samples), &bytes_written, portMAX_DELAY);
// //         j++;
// //       }
// //       analogWrite(redPin, 0); //red light off
// // }


// // //sound when password is correct
// // void CorrectPasswordSound() 
// // {
// //   static float phase = 0;
// //   size_t bytes_written;
// //   int16_t samples[64];
// //    // Generate a 1kHz sine wave
// //   for (int i = 0; i < 64; i++) {
// //          samples[i] = (int16_t)(32767 * sin(phase));
// //          phase += 2 * PI * 5000 / SAMPLE_RATE;
// //          if (phase >= 2 * PI) {
// //             phase -= 2 * PI;
// //         }
// //       }
// //       int j = 0;
// //       while(j<1900){
// //         //i2s_write(I2S_NUM, samples, sizeof(samples), &bytes_written, portMAX_DELAY);
// //         j++;
// //       }
// // }

// // void WrongPasswordSound() //sound when password is incorrect
// // {
// //   static float phase = 0;
// //   size_t bytes_written;
// //   int16_t samples[64];
// //    // Generate a 1kHz sine wave
// //   for (int i = 0; i < 64; i++) {
// //          samples[i] = (int16_t)(32767 * sin(phase));
// //          phase += 2 * PI * 5000 / SAMPLE_RATE;
// //          if (phase >= 2 * PI) {
// //             phase -= 2 * PI;
// //         }
// //       }
// //       // make beeping sound 5 times
// //       for (int k = 0; k < 5; k++) {
// //           int j=0;
// //           analogWrite(redPin, 255); //red light on
// //           while(j<200){
// //              //i2s_write(I2S_NUM, samples, sizeof(samples), &bytes_written, portMAX_DELAY);
// //             j++;
// //           }
// //           analogWrite(redPin, 0); //red light off
// //           delay(300);
// //         }
      
// // }


// //     //lights flickering when * is pressed to reset the password
// // void resetpassword()
// //     {

// //       analogWrite(greenPin, 255); //green light on
// //       analogWrite(redPin, 255); //red light on
// //       analogWrite(bluePin, 255); //blue light on

// //       input_password = ""; // reset the input password

// //       //generate first sine wave
// //       static float phase1 = 0;
// //       size_t bytes_written1;
// //       int16_t samples1[64];
// //       // Generate a 1kHz sine wave
// //       for (int i = 0; i < 64; i++) {
// //          samples1[i] = (int16_t)(32767 * sin(phase1));
// //          phase1 += 2 * PI * 5000 / SAMPLE_RATE;
// //          if (phase1 >= 2 * PI) {
// //             phase1 -= 2 * PI;
// //         }
// //       }


// //       //generate second cosine wave
// //       static float phase2 = 0;
// //       size_t bytes_written2;
// //       int16_t samples2[64];
// //       // Generate a xkHz sine wave
// //       for (int i = 0; i < 64; i++) {
// //          samples2[i] = (int16_t)(100000 * cos(phase2));
// //          phase2 += 2 * PI * 5000 / SAMPLE_RATE;
// //          if (phase2 >= 2 * PI) {
// //             phase2 -= 2 * PI;
// //         }
// //       }


// //       // make beeping sound 3 times
// //       for (int k = 0; k < 3; k++) {
// //           if(k%2 == 0)
// //           {
// //             int j1=0;
// //             analogWrite(greenPin, 255); //green light on
// //             analogWrite(redPin, 255); //red light on
// //             analogWrite(bluePin, 255); //blue light on
// //             while(j1<100){
// //               //i2s_write(I2S_NUM, samples1, sizeof(samples1), &bytes_written1, portMAX_DELAY);
// //               j1++;
// //             }
// //             analogWrite(redPin, 0); //red light off
// //             delay(50);
// //             }
// //           else
// //           {
// //             int j2=0;
// //             analogWrite(bluePin, 0); //blue light off
// //             analogWrite(redPin, 0); //red light off
// //             analogWrite(greenPin, 255); //green light on
// //             while(j2<100){
// //               //i2s_write(I2S_NUM, samples2, sizeof(samples2), &bytes_written2, portMAX_DELAY);
// //               j2++;
// //             }
// //             delay(50);
// //           }
// //         }
// //         analogWrite(greenPin, 0); //green light off
// //         analogWrite(bluePin, 0); //blue light off
// //         analogWrite(redPin, 0); //red light off
// //         //Serial.println("password has been reset");
// //     }



  

// // /***     end of implifier and sound functions ***/

// // #define RELAY_PIN   33 
// // void opendoor()
// // {
// //           analogWrite(redPin, 0); //turn red light off
// //           analogWrite(bluePin, 0); //turn blue light off
// //           //Serial.println("password is correct");
// //           analogWrite(greenPin, 255); //light green color
// //           digitalWrite(RELAY_PIN, LOW); // Unlock the door
// //           //Serial.println("door open");
// //           CorrectPasswordSound();
// //           delay(5000);
// //           digitalWrite(RELAY_PIN, HIGH); // Lock the door
// //           //Serial.println("door closed");
// //           analogWrite(greenPin, 0); //turn off green light
// // }


// // void donotopendoor()
// // {
// //           //Serial.print(input_password);
// //           //Serial.println(" is invalid , please Try again");
// //           analogWrite(bluePin, 0); //turn blue light off
// //           analogWrite(greenPin, 0); //turn blue light off
// //           analogWrite(redPin, 0); //turn red light off
// //           WrongPasswordSound();
// //           resetpassword();
// // }



// // /***     end of relay code and functions ***/



// // /***     here is the firebase and wifi connection ***/
// // Firebase firebase(REFERENCE_URL);

// // void firebaseSetup() {
// //   Serial.println("Connecting to WIFI: Pending...");
// //   WiFi.mode(WIFI_STA);
// //   //WiFi.disconnect();
// //   //delay(1000);
// //   WiFi.begin(_SSID, _PASSWORD);

// //   while (WiFi.status() != WL_CONNECTED) {
// //     //freeplay();
// //     delay(10);
// //     //Serial.print("-");
// //   }
// //   Serial.println("Connected to WIFI");
// // }

// // int firebaseReadLock() {

// //   return firebase.getInt("lck");
// // }


// // /***    end of firebase and wifi connection ***/

// // unsigned long lastLockCheckTime = 0; // Variable to keep track of the last lock check time
// // const unsigned long lockCheckInterval = 6000; // Check the lock every 5 seconds
// // void checklock(void* param) // function to check the lock value in firebase
// // {
// //    while(true){
// //    if(lockStatus == false)
// //       unsigned long currentTime = millis();
// //       if (currentTime - lastLockCheckTime >= lockCheckInterval) {
// //       lastLockCheckTime = currentTime;
// //       int lock = firebase.getInt("lock");
// //       if(lock > 1) {
// //         opendoor();
// //         firebase.setInt("lock", 1);
// //       }
// //     }
// //     else{
// //        Serial.print("lock in use");
// //     }
// //     vTaskDelay(1000 / portTICK_PERIOD_MS);
// //   }
// //    //vTaskDelete(NULL);
// // }



// // void checkPassword(String input_password)
// // {
// //   String path = "/tempPas"+ input_password + "/expiry";
// //   if(firebase.getInt(path) > firebase.getInt("time") || input_password == password)
// //   {
// //     Serial.println("password is correct. Unlocking...");
// //     lockStatus = false;
// //     opendoor();
// //   }

// //   input_password = "";
// //   vTaskDelete(NULL);

// // }

// // void handle_keypad(){
// //   while (true)
// //   {
// //   analogWrite(bluePin, 0);
// //   analogWrite(redPin, 0);
// //   analogWrite(greenPin, 0); 
// //   customKeypad.tick();
// //   keypadEvent e = customKeypad.read();
// //   char key = (char)e.bit.KEY;
// //   if (e.bit.EVENT == KEY_JUST_PRESSED) {
// //       analogWrite(bluePin, 255); //blue light on when pressed
// //       if (key != '*')
// //             KeyPressedSound(); //any time a key is pressed it makes a sound
// //       Serial.print(key);
// //       if(key == '#')
// //       {
// //         xTaskCreate(checkPassword, "Check Password", 4096, NULL, 1, NULL);
        
// //       }
// //       //Serial.println(" pressed");
// //       else if (key == '*') {
// //         resetpassword();

// //       }
// //       else {
// //         donotopendoor(); 
// //       }

// //       // if(input_password == "") {
// //       //     EmptyPasswordSound();
// //       // } 
// //       // else { donotopendoor(); }
        
// // }
// // else {
// //       input_password += key; // append new character to input password string
// //       Serial.print("password till now is : ");
// //       Serial.println(input_password);
// //       }
// //       analogWrite(redPin, 0); //turn of blue light
// //     // } else if (e.bit.EVENT == KEY_JUST_RELEASED) {
// //     //   Serial.print(key);
// //     //   Serial.println(" released");
// //     // }
  
// //     vTaskDelay(50 / portTICK_PERIOD_MS); // Small delay to avoid busy waiting
// //   }
// //   //checklock();
// //   //handledoorbell();

// // }


// // void setup() {
// //   Serial.begin(9600);  // Adjusted for ESP32
// //   customKeypad.begin();
// //   pinMode(redPin, OUTPUT); 
// //   pinMode(greenPin, OUTPUT); 
// //   pinMode(bluePin, OUTPUT); 
// //   pinMode(RELAY_PIN, OUTPUT);
// //   digitalWrite(RELAY_PIN, HIGH);
// //   WiFi.mode(WIFI_STA);
// //   delay(1000);
// //   WiFi.begin(_SSID, _PASSWORD);
// //   Serial.print("CONNECTING TO WIFI");
// //   while (WiFi.status() != WL_CONNECTED) {
// //     delay(5);
// //     Serial.print(".");
// //   }
// //   Serial.println("");
// //   Serial.println("Connected to WIFI");
  
// //   // I2S configuration
// //   i2s_config_t i2s_config = {
// //     .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_TX),  // Master, TX only
// //     .sample_rate = SAMPLE_RATE,
// //     .bits_per_sample = I2S_BITS_PER_SAMPLE_16BIT,
// //     .channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT,
// //     .communication_format = I2S_COMM_FORMAT_I2S_MSB,
// //     .intr_alloc_flags = 0, // default interrupt priority
// //     .dma_buf_count = 8,
// //     .dma_buf_len = 64,
// //     .use_apll = false,
// //     .tx_desc_auto_clear = true,
// //     .fixed_mclk = 0
// //   };

// //   // I2S pin configuration
// //   i2s_pin_config_t pin_config = {
// //     .bck_io_num = I2S_BCK_PIN,
// //     .ws_io_num = I2S_WS_PIN,
// //     .data_out_num = I2S_DATA_PIN,
// //     .data_in_num = I2S_PIN_NO_CHANGE
// //   };
// //   Serial.println("I2S protocol configured");

// //   // Install and start I2S driver
// //   i2s_driver_install(I2S_NUM, &i2s_config, 0, NULL);
// //   i2s_set_pin(I2S_NUM, &pin_config);
// //   i2s_zero_dma_buffer(I2S_NUM);
// //   Serial.println("I2S driver installed");
  
// //   xTaskCreate(checklock, "Check Lock", 4096, NULL, 1, NULL);
// //   xTaskCreate(handle_keypad, "Handle Keypad", 4096, NULL, 1, NULL);
  
// //   //xTaskCreate(handledoorbell , "handledoorbell" , 50000 , NULL , 5 , NULL);
// //   //handledoorbell
// // }




// // void loop() {
 
// // }







// // #include <ESP32Firebase.h>
// // #include <WiFi.h>
// // #include <Adafruit_Keypad.h> // Correct inclusion of the library
// // #include <Arduino.h>
// // #include <driver/i2s.h>
// // #include <math.h>
// // #include <ezOutput.h>
// // #include <ArduinoJson.h>
// // #include <time.h>

// // // WiFi and Firebase setup:

// // //#include <FirebaseJson.h>  
// // #define _SSID "ICST"          // Your WiFi SSID
// // #define _PASSWORD "arduino123"    // Your WiFi Password

// // #define UNLOCK_TIME 3000 // in milliseconds

// // // /* 2. Define the API Key */
// // // #define API_KEY "AIzaSyAHANIi3AEgVl8ir3Cs5ePn6qJLWD9LY1Y"

// // // /* 3. Define the RTDB URL */
// // #define DATABASE_URL "https://console.firebase.google.com/u/0/project/smartdoorbell-7e38f/database/smartdoorbell-7e38f-default-rtdb/data/~2F" //<databaseName>.firebaseio.com or <databaseName>.<region>.firebasedatabase.app
// // //https://console.firebase.google.com/u/0/project/smartdoorbell-7e38f/database/smartdoorbell-7e38f-default-rtdb/data/~2F
// // #define REFERENCE_URL "https://smartdoorbell-7e38f-default-rtdb.firebaseio.com/"
// // //https://console.firebase.google.com/u/0/project/smartdoorbell-7e38f/database/smartdoorbell-7e38f-default-rtdb/data/~2F"
// // #define FIREBASE_AUTH "AIzaSyAHANIi3AEgVl8ir3Cs5ePn6qJLWD9LY1Y"


// // const String password = "123"; // change your password here
// // String input_password;




// // // Define the pins for RGB LED green and red and blue
// // const int redPin = 13;    // Red pin red wire
// // const int greenPin = 12;    // Green pin green wire
// // const int bluePin = 14;    // blue pin blue wire





// // /***     here is the keypad configoration code ***/


// // // define your specific keypad here via PID
// // #define KEYPAD_PID3845


// // // define your pins here for keypad
// // #define R4   15 //brown wire
// // #define R3   4  //red wire
// // #define R2   5  //orange
// // #define R1   18   //yellow wire 
// // #define C1   23 //white wire
// // #define C2   22 //purple wire
// // #define C3   21  //blue wire
// // #define C4   19  //green wire

// // // Keymap for 4x4 Keypad
// // char keys[4][4] = {
// //   {'1','2','3', 'A'},
// //   {'4','5','6', 'B'},
// //   {'7','8','9', 'C'},
// //   {'*','0','#', 'D'}
// // };

// // // Row and column pins for 3x4 Keypad
// // byte rowPins[4] = { R1, R2, R3, R4 };
// // byte colPins[4] = { C1, C2, C3 , C4 };

// // // Initialize an instance of class Adafruit_Keypad
// // Adafruit_Keypad customKeypad = Adafruit_Keypad(makeKeymap(keys), rowPins, colPins, 4, 4);



// // bool lockStatus = false; // false means unlocked, true means locked

// // /***     end of keypad configoration    ***/




// // /***     here is the implifier configoration code and sound functions ***/


// // // Define I2S pins for implifier and speaker
// // #define I2S_NUM         I2S_NUM_0
// // #define I2S_BCK_PIN     26
// // #define I2S_WS_PIN      27
// // #define I2S_DATA_PIN    25
// // #define SAMPLE_RATE     44100
// // #define PI              3.141592


// // //sound functions

// // //sound when a key is pressed 
// // void KeyPressedSound() //sound when any key is pressed
// // {
// //   static float phase = 0;
// //   size_t bytes_written;
// //   int16_t samples[64];
// //    // Generate a 1kHz sine wave
// //   for (int i = 0; i < 64; i++) {
// //          samples[i] = (int16_t)(32767 * sin(phase));
// //          phase += 2 * PI * 5000 / SAMPLE_RATE;
// //          if (phase >= 2 * PI) {
// //             phase -= 2 * PI;
// //         }
// //       }
// //       int j = 0;
// //       while(j<200){
// //         //i2s_write(I2S_NUM, samples, sizeof(samples), &bytes_written, portMAX_DELAY);
// //         j++;
// //       }
// // }


// // //when input is empty and user presses #
// // void EmptyPasswordSound() 
// // {
// //   analogWrite(bluePin, 0); //blue light off
// //   analogWrite(greenPin, 0); //blue light off
// //   analogWrite(redPin, 255); //red light on
// //   Serial.println("empty password");
// //   static float phase = 0;
// //   size_t bytes_written;
// //   int16_t samples[64];
// //    // Generate a cossine wave
// //   for (int i = 0; i < 64; i++) {
// //          samples[i] = (int16_t)(10000000 * cos(phase));
// //          phase += 2 * PI * 5000 / SAMPLE_RATE;
// //          if (phase >= 2 * PI) {
// //             phase -= 2 * PI;
// //         }
// //       }
// //       int j = 0;
// //       while(j<1000){
// //         //i2s_write(I2S_NUM, samples, sizeof(samples), &bytes_written, portMAX_DELAY);
// //         j++;
// //       }
// //       analogWrite(redPin, 0); //red light off
// // }


// // //sound when password is correct
// // void CorrectPasswordSound() 
// // {
// //   static float phase = 0;
// //   size_t bytes_written;
// //   int16_t samples[64];
// //    // Generate a 1kHz sine wave
// //   for (int i = 0; i < 64; i++) {
// //          samples[i] = (int16_t)(32767 * sin(phase));
// //          phase += 2 * PI * 5000 / SAMPLE_RATE;
// //          if (phase >= 2 * PI) {
// //             phase -= 2 * PI;
// //         }
// //       }
// //       int j = 0;
// //       while(j<1900){
// //         //i2s_write(I2S_NUM, samples, sizeof(samples), &bytes_written, portMAX_DELAY);
// //         j++;
// //       }
// // }

// // void WrongPasswordSound() //sound when password is incorrect
// // {
// //   static float phase = 0;
// //   size_t bytes_written;
// //   int16_t samples[64];
// //    // Generate a 1kHz sine wave
// //   for (int i = 0; i < 64; i++) {
// //          samples[i] = (int16_t)(32767 * sin(phase));
// //          phase += 2 * PI * 5000 / SAMPLE_RATE;
// //          if (phase >= 2 * PI) {
// //             phase -= 2 * PI;
// //         }
// //       }
// //       // make beeping sound 5 times
// //       for (int k = 0; k < 5; k++) {
// //           int j=0;
// //           analogWrite(redPin, 255); //red light on
// //           while(j<200){
// //              //i2s_write(I2S_NUM, samples, sizeof(samples), &bytes_written, portMAX_DELAY);
// //             j++;
// //           }
// //           analogWrite(redPin, 0); //red light off
// //           delay(300);
// //         }
      
// // }


// //     //lights flickering when * is pressed to reset the password
// // void resetpassword()
// //     {

// //       analogWrite(greenPin, 255); //green light on
// //       analogWrite(redPin, 255); //red light on
// //       analogWrite(bluePin, 255); //blue light on

// //       input_password = ""; // reset the input password

// //       //generate first sine wave
// //       static float phase1 = 0;
// //       size_t bytes_written1;
// //       int16_t samples1[64];
// //       // Generate a 1kHz sine wave
// //       for (int i = 0; i < 64; i++) {
// //          samples1[i] = (int16_t)(32767 * sin(phase1));
// //          phase1 += 2 * PI * 5000 / SAMPLE_RATE;
// //          if (phase1 >= 2 * PI) {
// //             phase1 -= 2 * PI;
// //         }
// //       }


// //       //generate second cosine wave
// //       static float phase2 = 0;
// //       size_t bytes_written2;
// //       int16_t samples2[64];
// //       // Generate a xkHz sine wave
// //       for (int i = 0; i < 64; i++) {
// //          samples2[i] = (int16_t)(100000 * cos(phase2));
// //          phase2 += 2 * PI * 5000 / SAMPLE_RATE;
// //          if (phase2 >= 2 * PI) {
// //             phase2 -= 2 * PI;
// //         }
// //       }


// //       // make beeping sound 3 times
// //       for (int k = 0; k < 3; k++) {
// //           if(k%2 == 0)
// //           {
// //             int j1=0;
// //             analogWrite(greenPin, 255); //green light on
// //             analogWrite(redPin, 255); //red light on
// //             analogWrite(bluePin, 255); //blue light on
// //             while(j1<100){
// //               //i2s_write(I2S_NUM, samples1, sizeof(samples1), &bytes_written1, portMAX_DELAY);
// //               j1++;
// //             }
// //             analogWrite(redPin, 0); //red light off
// //             delay(50);
// //             }
// //           else
// //           {
// //             int j2=0;
// //             analogWrite(bluePin, 0); //blue light off
// //             analogWrite(redPin, 0); //red light off
// //             analogWrite(greenPin, 255); //green light on
// //             while(j2<100){
// //               //i2s_write(I2S_NUM, samples2, sizeof(samples2), &bytes_written2, portMAX_DELAY);
// //               j2++;
// //             }
// //             delay(50);
// //           }
// //         }
// //         analogWrite(greenPin, 0); //green light off
// //         analogWrite(bluePin, 0); //blue light off
// //         analogWrite(redPin, 0); //red light off
// //         //Serial.println("password has been reset");
// //     }



  

// // /***     end of implifier and sound functions ***/

// // #define RELAY_PIN   33 
// // void opendoor()
// // {
// //           analogWrite(redPin, 0); //turn red light off
// //           analogWrite(bluePin, 0); //turn blue light off
// //           //Serial.println("password is correct");
// //           analogWrite(greenPin, 255); //light green color
// //           digitalWrite(RELAY_PIN, LOW); // Unlock the door
// //           //Serial.println("door open");
// //           CorrectPasswordSound();
// //           delay(5000);
// //           digitalWrite(RELAY_PIN, HIGH); // Lock the door
// //           //Serial.println("door closed");
// //           analogWrite(greenPin, 0); //turn off green light
// // }


// // void donotopendoor()
// // {
// //           //Serial.print(input_password);
// //           //Serial.println(" is invalid , please Try again");
// //           analogWrite(bluePin, 0); //turn blue light off
// //           analogWrite(greenPin, 0); //turn blue light off
// //           analogWrite(redPin, 0); //turn red light off
// //           WrongPasswordSound();
// //           resetpassword();
// // }



// // /***     end of relay code and functions ***/



// // /***     here is the firebase and wifi connection ***/
// // Firebase firebase(REFERENCE_URL);

// // void firebaseSetup() {
// //   Serial.println("Connecting to WIFI: Pending...");
// //   WiFi.mode(WIFI_STA);
// //   //WiFi.disconnect();
// //   //delay(1000);
// //   WiFi.begin(_SSID, _PASSWORD);

// //   while (WiFi.status() != WL_CONNECTED) {
// //     //freeplay();
// //     delay(10);
// //     //Serial.print("-");
// //   }
// //   Serial.println("Connected to WIFI");
// // }

// // // int firebaseReadLock() {

// // //   return firebase.getInt("lck");
// // // }

// // // Example function to read and cache data to minimize Firebase operations
// // int readCachedData(String path) {
// //   static int cachedValue = -1;
// //   static unsigned long lastFetchTime = 0;
// //   const unsigned long cacheDuration = 10000; // 10 seconds

// //   if (millis() - lastFetchTime > cacheDuration) {
// //     // Read from Firebase and update cache
// //     cachedValue = firebase.getInt(path);
// //     lastFetchTime = millis();
// //   }

// //   return cachedValue;
// // }

// // // Example function to set data with reduced frequency
// // void setFirebaseData(String path, int value) {
// //   static int lastSetValue = -1;
// //   if (value != lastSetValue) {
// //     firebase.setInt(path, value);
// //     lastSetValue = value;
// //   }
// // }


// // /***    end of firebase and wifi connection ***/

// // unsigned long lastLockCheckTime = 0; // Variable to keep track of the last lock check time
// // const unsigned long lockCheckInterval = 6000; // Check the lock every 5 seconds
// // unsigned int currentTime = millis();


// // void checklock(void *parameter) // function to check the lock value in firebase
// // {
// //    while(true){
// //     //Serial.print(lockStatus);

// //    if(lockStatus == false)
// //    {  
// //       // if (currentTime - lastLockCheckTime >= lockCheckInterval) {
// //       // lastLockCheckTime = currentTime;
// //       Serial.print("lock in use");
// //       int lock = readCachedData("lock");
// //       if(lock > 1) {
// //         opendoor();
// //         Serial.print("lock in use");
// //         setFirebaseData("lock", 1);
// //       }
// //       //}
// //     }

// //     // else{
// //     //    Serial.print("lock in use");
// //     // }
// //     vTaskDelay(400 / portTICK_PERIOD_MS);
// //   }
// //    //vTaskDelete(NULL);
// // }



// // void checkPassword(void *parameter)
// // {
// //   String path = "/tempPas"+ input_password + "/expiry";
// //   int x =0;
// //   x = readCachedData(path);
// //   int t=0;
// //   // t =firebase.getInt("time");
// //   // if(x > t)
// //   // {
// //   //   Serial.println("password is correct. Unlocking...");
// //   //   lockStatus = true;
// //   //   opendoor();
// //   // }

// //   // input_password = "";
// //   vTaskDelete(NULL);

// // }

// // void handle_keypad(void *parameter){
// //   while (true)
// //   {
// //   analogWrite(bluePin, 0);
// //   analogWrite(redPin, 0);
// //   analogWrite(greenPin, 0); 
// //   customKeypad.tick();
// //   keypadEvent e = customKeypad.read();
// //   char key = (char)e.bit.KEY;
// //   if (e.bit.EVENT == KEY_JUST_PRESSED) {
// //       analogWrite(bluePin, 255); //blue light on when pressed
// //       if(key == '#')
// //       {
// //         KeyPressedSound();
// //         xTaskCreate(checkPassword, "Check Password", 4096, NULL, 1, NULL);
        
// //       }
// //       //Serial.println(" pressed");
// //       else if (key == '*') {
// //         resetpassword();

// //       }
// //       else {
// //         KeyPressedSound();
// //         input_password += key;
// //       }

// //       // if(input_password == "") {
// //       //     EmptyPasswordSound();
// //       // } 
// //       // else { donotopendoor(); }
        
// // }else {
// //       analogWrite(redPin, 0); //turn of blue light
// //       //input_password += key; // append new character to input password string
      
// //       //Serial.print("password till now is : ");
      
// //       }
      
// //     // } else if (e.bit.EVENT == KEY_JUST_RELEASED) {
// //     //   Serial.print(key);
// //     //   Serial.println(" released");
// //     // }
// //     vTaskDelay(50 / portTICK_PERIOD_MS); // Small delay to avoid busy waiting
// //     //Serial.println(input_password);

// //   }
// //   vTaskDelete(NULL);
 
// //   //checklock();
// //   //handledoorbell();

// // }


// // void setup() {
// //   Serial.begin(9600);  // Adjusted for ESP32
// //   customKeypad.begin();
// //   pinMode(redPin, OUTPUT); 
// //   pinMode(greenPin, OUTPUT); 
// //   pinMode(bluePin, OUTPUT); 
// //   pinMode(RELAY_PIN, OUTPUT);
// //   digitalWrite(RELAY_PIN, HIGH);
// //   WiFi.mode(WIFI_STA);
// //   delay(1000);
// //   WiFi.begin(_SSID, _PASSWORD);
// //   Serial.print("CONNECTING TO WIFI");
// //   while (WiFi.status() != WL_CONNECTED) {
// //     delay(5);
// //     Serial.print(".");
// //   }
// //   Serial.println("");
// //   Serial.println("Connected to WIFI");
  
// //   // I2S configuration
// //   i2s_config_t i2s_config = {
// //     .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_TX),  // Master, TX only
// //     .sample_rate = SAMPLE_RATE,
// //     .bits_per_sample = I2S_BITS_PER_SAMPLE_16BIT,
// //     .channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT,
// //     .communication_format = I2S_COMM_FORMAT_I2S_MSB,
// //     .intr_alloc_flags = 0, // default interrupt priority
// //     .dma_buf_count = 8,
// //     .dma_buf_len = 64,
// //     .use_apll = false,
// //     .tx_desc_auto_clear = true,
// //     .fixed_mclk = 0
// //   };

// //   // I2S pin configuration
// //   i2s_pin_config_t pin_config = {
// //     .bck_io_num = I2S_BCK_PIN,
// //     .ws_io_num = I2S_WS_PIN,
// //     .data_out_num = I2S_DATA_PIN,
// //     .data_in_num = I2S_PIN_NO_CHANGE
// //   };
// //   Serial.println("I2S protocol configured");

// //   // Install and start I2S driver
// //   i2s_driver_install(I2S_NUM, &i2s_config, 0, NULL);
// //   i2s_set_pin(I2S_NUM, &pin_config);
// //   i2s_zero_dma_buffer(I2S_NUM);
// //   Serial.println("I2S driver installed");
  
// //   xTaskCreate(handle_keypad, "Handle Keypad", 2048, NULL, 2, NULL);
  
// //   xTaskCreate(checklock, "Check Lock", 4096, NULL, 1, NULL);
  
// //   //xTaskCreate(handledoorbell , "handledoorbell" , 50000 , NULL , 5 , NULL);
// //   //handledoorbell
// // }




// // void loop() {
 
// // }







// #include <ESP32Firebase.h>
// #include <WiFi.h>
// #include <Adafruit_Keypad.h>
// #include <Arduino.h>
// #include <driver/i2s.h>
// #include <math.h>
// #include <ezOutput.h>
// #include <ArduinoJson.h>
// #include <time.h>
// #include <FirebaseClient.h>

// #define _SSID "ICST"          // Your WiFi SSID
// #define _PASSWORD "arduino123"    // Your WiFi Password

// #define UNLOCK_TIME 3000 // in milliseconds
// #define DATABASE_URL "https://smartdoorbell-7e38f-default-rtdb.firebaseio.com/"
// #define FIREBASE_AUTH "AIzaSyAHANIi3AEgVl8ir3Cs5ePn6qJLWD9LY1Y"

// // Keypad configuration
// #define KEYPAD_PID3845
// #define R4 15
// #define R3 4
// #define R2 5
// #define R1 18
// #define C1 23
// #define C2 22
// #define C3 21
// #define C4 19

// // Keymap for 4x4 Keypad
// char keys[4][4] = {
//   {'1','2','3', 'A'},
//   {'4','5','6', 'B'},
//   {'7','8','9', 'C'},
//   {'*','0','#', 'D'}
// };

// // Row and column pins for 3x4 Keypad
// byte rowPins[4] = { R1, R2, R3, R4 };
// byte colPins[4] = { C1, C2, C3 , C4 };

// // Initialize an instance of class Adafruit_Keypad
// Adafruit_Keypad customKeypad = Adafruit_Keypad(makeKeymap(keys), rowPins, colPins, 4, 4);

// const String password = "123"; // change your password here
// String input_password;

// const int redPin = 13;    // Red pin
// const int greenPin = 12;    // Green pin
// const int bluePin = 14;    // Blue pin
// #define RELAY_PIN 33 

// // Define I2S pins for amplifier and speaker
// #define I2S_NUM I2S_NUM_0
// #define I2S_BCK_PIN 26
// #define I2S_WS_PIN 27
// #define I2S_DATA_PIN 25
// #define SAMPLE_RATE 44100
// #define PI 3.141592

// //Firebase firebase(DATABASE_URL);

// unsigned long lastLockCheckTime = 0; 
// const unsigned long lockCheckInterval = 3000; // Check the lock every 3 seconds
// unsigned long lastFirebaseOperation = 0;
// const unsigned long firebaseOperationInterval = 10000; // Cache Firebase data every 10 seconds

// bool lockStatus = false; // false means unlocked, true means locked



// void KeyPressedSound() {
//   static float phase = 0;
//   size_t bytes_written;
//   int16_t samples[64];
//   for (int i = 0; i < 64; i++) {
//     samples[i] = (int16_t)(32767 * sin(phase));
//     phase += 2 * PI * 5000 / SAMPLE_RATE;
//     if (phase >= 2 * PI) {
//       phase -= 2 * PI;
//     }
//   }
//   int j = 0;
//   while(j < 200) {
//     j++;
//   }
// }

// void EmptyPasswordSound() {
//   analogWrite(bluePin, 0);
//   analogWrite(greenPin, 0);
//   analogWrite(redPin, 255);
//   Serial.println("empty password");
//   static float phase = 0;
//   size_t bytes_written;
//   int16_t samples[64];
//   for (int i = 0; i < 64; i++) {
//     samples[i] = (int16_t)(10000000 * cos(phase));
//     phase += 2 * PI * 5000 / SAMPLE_RATE;
//     if (phase >= 2 * PI) {
//       phase -= 2 * PI;
//     }
//   }
//   int j = 0;
//   while(j < 1000) {
//     j++;
//   }
//   analogWrite(redPin, 0);
// }

// void CorrectPasswordSound() {
//   static float phase = 0;
//   size_t bytes_written;
//   int16_t samples[64];
//   for (int i = 0; i < 64; i++) {
//     samples[i] = (int16_t)(32767 * sin(phase));
//     phase += 2 * PI * 5000 / SAMPLE_RATE;
//     if (phase >= 2 * PI) {
//       phase -= 2 * PI;
//     }
//   }
//   int j = 0;
//   while(j < 1900) {
//     j++;
//   }
// }

// void WrongPasswordSound() {
//   static float phase = 0;
//   size_t bytes_written;
//   int16_t samples[64];
//   for (int i = 0; i < 64; i++) {
//     samples[i] = (int16_t)(32767 * sin(phase));
//     phase += 2 * PI * 5000 / SAMPLE_RATE;
//     if (phase >= 2 * PI) {
//       phase -= 2 * PI;
//     }
//   }
//   for (int k = 0; k < 5; k++) {
//     int j = 0;
//     analogWrite(redPin, 255);
//     while(j < 200) {
//       j++;
//     }
//     analogWrite(redPin, 0);
//     delay(300);
//   }
// }

// void resetpassword() {
//   analogWrite(greenPin, 255);
//   analogWrite(redPin, 255);
//   analogWrite(bluePin, 255);
//   input_password = "";

//   static float phase1 = 0;
//   size_t bytes_written1;
//   int16_t samples1[64];
//   for (int i = 0; i < 64; i++) {
//     samples1[i] = (int16_t)(32767 * sin(phase1));
//     phase1 += 2 * PI * 5000 / SAMPLE_RATE;
//     if (phase1 >= 2 * PI) {
//       phase1 -= 2 * PI;
//     }
//   }

//   static float phase2 = 0;
//   size_t bytes_written2;
//   int16_t samples2[64];
//   for (int i = 0; i < 64; i++) {
//     samples2[i] = (int16_t)(32767 * sin(phase2));
//     phase2 += 2 * PI * 5000 / SAMPLE_RATE;
//     if (phase2 >= 2 * PI) {
//       phase2 -= 2 * PI;
//     }
//   }
// }



// void setup() {
//   Serial.begin(9600);
//   customKeypad.begin();
//   pinMode(redPin, OUTPUT); 
//   pinMode(greenPin, OUTPUT); 
//   pinMode(bluePin, OUTPUT); 
//   pinMode(RELAY_PIN, OUTPUT);
//   digitalWrite(RELAY_PIN, HIGH);

//   WiFi.mode(WIFI_STA);
//   WiFi.begin(_SSID, _PASSWORD);
//   Serial.print("CONNECTING TO WIFI");
//   while (WiFi.status() != WL_CONNECTED) {
//     delay(5);
//     Serial.print(".");
//   }
//   Serial.println("");
//   Serial.println("Connected to WIFI");

//   // I2S configuration
//   i2s_config_t i2s_config = {
//     .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_TX), 
//     .sample_rate = SAMPLE_RATE,
//     .bits_per_sample = I2S_BITS_PER_SAMPLE_16BIT,
//     .channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT,
//     .communication_format = I2S_COMM_FORMAT_I2S_MSB,
//     .intr_alloc_flags = 0, 
//     .dma_buf_count = 8,
//     .dma_buf_len = 64,
//     .use_apll = false,
//     .tx_desc_auto_clear = true,
//     .fixed_mclk = 0
//   };

//   i2s_pin_config_t pin_config = {
//     .bck_io_num = I2S_BCK_PIN,
//     .ws_io_num = I2S_WS_PIN,
//     .data_out_num = I2S_DATA_PIN,
//     .data_in_num = I2S_PIN_NO_CHANGE
//   };
//   i2s_driver_install(I2S_NUM, &i2s_config, 0, NULL);
//   i2s_set_pin(I2S_NUM, &pin_config);
//   i2s_zero_dma_buffer(I2S_NUM);
// }

// void loop() {
//   unsigned long currentMillis = millis();

//   // Handle keypad input
//   customKeypad.tick();
//   keypadEvent e = customKeypad.read();
//   char key = (char)e.bit.KEY;
//   if (e.bit.EVENT == KEY_JUST_PRESSED) {
//     analogWrite(bluePin, 255);
//     if(key == '#') {
//       KeyPressedSound();
//       // Check password
//       checkPassword();
//     } else if (key == '*') {
//       resetpassword();
//     } else {
//       KeyPressedSound();
//       input_password += key;
//     }
//   } else {
//     analogWrite(bluePin, 0);
//   }

//   // Handle Firebase operations
    
//     int lock = readCachedData("lock");
//     // maybe shoud read from lock status 
    
//     if (lock > 1) {
//       // door is accupied by rem
//       //show red color
//       analogWrite(redPin, 255);
//       opendoor();
//       Serial.println("DOOR OPENED REMOTELY");
//       setFirebaseData("lock", 1);
//     }
  

//   // Optionally, handle other tasks here

// }

// void checkPassword() {
//   if (input_password == password) {
//     CorrectPasswordSound();
//     opendoor();
//     input_password = "";
//   } else {
//     WrongPasswordSound();
//     input_password = "";
//   }
// }

// void opendoor() {
//   digitalWrite(RELAY_PIN, LOW);
//   delay(UNLOCK_TIME);
//   digitalWrite(RELAY_PIN, HIGH);
//   //delay(500);
// }

// void setFirebaseData(String path, int value) {
//   firebase.setInt(path, value);
// }

// int readCachedData(String path) {
//   if (millis() - lastFirebaseOperation >= firebaseOperationInterval) {
//     lastFirebaseOperation = millis();
//     if (firebase.getInt(path) > 0) {
//       return firebase.getInt(path);
//     }
//   }
//   return 0;
// }



#include <ESP32Firebase.h>
#include <WiFi.h>
#include <WiFiAP.h>
#include <WiFiClient.h>
#include <WiFiGeneric.h>
#include <WiFiMulti.h>
#include <WiFiSTA.h>
#include <WiFiScan.h>
#include <WiFiServer.h>
#include <WiFiType.h>
#include <WiFiUdp.h>
#include <Adafruit_Keypad.h> // Correct inclusion of the library
#include <Arduino.h>
#include <driver/i2s.h>
#include <math.h>
#include <ezOutput.h>
#include <ArduinoJson.h>
#include <time.h>
#include <FirebaseClient.h>

// WiFi and Firebase setup:

//#include <FirebaseJson.h>  
#define _SSID "ICST"          // Your WiFi SSID
#define _PASSWORD "arduino123"    // Your WiFi Password

#define UNLOCK_TIME 3000 // in milliseconds

// /* 2. Define the API Key */
// #define API_KEY "AIzaSyAHANIi3AEgVl8ir3Cs5ePn6qJLWD9LY1Y"

// /* 3. Define the RTDB URL */
#define DATABASE_URL "https://console.firebase.google.com/u/0/project/smartdoorbell-7e38f/database/smartdoorbell-7e38f-default-rtdb/data/~2F" //<databaseName>.firebaseio.com or <databaseName>.<region>.firebasedatabase.app
//https://console.firebase.google.com/u/0/project/smartdoorbell-7e38f/database/smartdoorbell-7e38f-default-rtdb/data/~2F
#define REFERENCE_URL "https://smartdoorbell-7e38f-default-rtdb.firebaseio.com/"
//https://console.firebase.google.com/u/0/project/smartdoorbell-7e38f/database/smartdoorbell-7e38f-default-rtdb/data/~2F"
#define FIREBASE_AUTH "AIzaSyAHANIi3AEgVl8ir3Cs5ePn6qJLWD9LY1Y"

#define DATABASE_SECRET "AIzaSyAFFmEbQA4_s2ilpv90l0v516sc4BiurZc"


FirebaseApp app;
RealtimeDatabase Database;
AsyncResult result;
LegacyToken dbSecret(DATABASE_SECRET);

void update_lock_firebase()
{
  if (LittleFS.exists("/lock.txt")) {
    Serial.println("file exists. Proceeding to send...");
    // Read, encode, and send the WAV file to Firebase Realtime Database
    if (sendWavFile("/recording.wav")) {
      displayMessage("Message is sent", 2 * 1000,1);
      Serial.println("WAV file sent to Firebase successfully.");
    } else {
      Serial.println("Failed to send WAV file.");
    }
  } else {
    Serial.println("WAV file does not exist in LittleFS.");
  }
}

const String password = "123"; // change your password here
String input_password;




// Define the pins for RGB LED green and red and blue
const int redPin = 13;    // Red pin red wire
const int greenPin = 12;    // Green pin green wire
const int bluePin = 14;    // blue pin blue wire





/***     here is the keypad configoration code ***/


// define your specific keypad here via PID
#define KEYPAD_PID3845


// define your pins here for keypad
#define R4   15 //brown wire
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


/***     end of keypad configoration    ***/




/***     here is the implifier configoration code and sound functions ***/


// Define I2S pins for implifier and speaker
#define I2S_NUM         I2S_NUM_0
#define I2S_BCK_PIN     26
#define I2S_WS_PIN      27
#define I2S_DATA_PIN    25
#define SAMPLE_RATE     44100
#define PI              3.14159265358979323846


//connect pins for implifier :
//Vin -> 3v3 red wire
//GND -> GND brown wire
//SD + GAIN are unconnected
//DIN -> D25 purple wire
//BCLK -> D26 grey
//LRC -> D27 orange wire

//sound functions

//sound when a key is pressed 
void KeyPressedSound() //sound when any key is pressed
{
  static float phase = 0;
  size_t bytes_written;
  int16_t samples[64];
   // Generate a 1kHz sine wave
  for (int i = 0; i < 64; i++) {
         samples[i] = (int16_t)(32767 * sin(phase));
         phase += 2 * PI * 5000 / SAMPLE_RATE;
         if (phase >= 2 * PI) {
            phase -= 2 * PI;
        }
      }
      int j = 0;
      while(j<200){
        //i2s_write(I2S_NUM, samples, sizeof(samples), &bytes_written, portMAX_DELAY);
        j++;
      }
}


//when input is empty and user presses #
void EmptyPasswordSound() 
{
  analogWrite(bluePin, 0); //blue light off
  analogWrite(greenPin, 0); //blue light off
  analogWrite(redPin, 255); //red light on
  Serial.println("empty password");
  static float phase = 0;
  size_t bytes_written;
  int16_t samples[64];
   // Generate a cossine wave
  for (int i = 0; i < 64; i++) {
         samples[i] = (int16_t)(10000000 * cos(phase));
         phase += 2 * PI * 5000 / SAMPLE_RATE;
         if (phase >= 2 * PI) {
            phase -= 2 * PI;
        }
      }
      int j = 0;
      while(j<1000){
        //i2s_write(I2S_NUM, samples, sizeof(samples), &bytes_written, portMAX_DELAY);
        j++;
      }
      analogWrite(redPin, 0); //red light off
}


//sound when password is correct
void CorrectPasswordSound() 
{
  static float phase = 0;
  size_t bytes_written;
  int16_t samples[64];
   // Generate a 1kHz sine wave
  for (int i = 0; i < 64; i++) {
         samples[i] = (int16_t)(32767 * sin(phase));
         phase += 2 * PI * 5000 / SAMPLE_RATE;
         if (phase >= 2 * PI) {
            phase -= 2 * PI;
        }
      }
      int j = 0;
      while(j<1900){
        //i2s_write(I2S_NUM, samples, sizeof(samples), &bytes_written, portMAX_DELAY);
        j++;
      }
}

void WrongPasswordSound() //sound when password is incorrect
{
  static float phase = 0;
  size_t bytes_written;
  int16_t samples[64];
   // Generate a 1kHz sine wave
  for (int i = 0; i < 64; i++) {
         samples[i] = (int16_t)(32767 * sin(phase));
         phase += 2 * PI * 5000 / SAMPLE_RATE;
         if (phase >= 2 * PI) {
            phase -= 2 * PI;
        }
      }
      // make beeping sound 5 times
      for (int k = 0; k < 5; k++) {
          int j=0;
          analogWrite(redPin, 255); //red light on
          while(j<200){
             //i2s_write(I2S_NUM, samples, sizeof(samples), &bytes_written, portMAX_DELAY);
            j++;
          }
          analogWrite(redPin, 0); //red light off
          delay(300);
        }
      
    }


    //lights flickering when * is pressed to reset the password
    void resetpassword()
    {

      analogWrite(greenPin, 255); //green light on
      analogWrite(redPin, 255); //red light on
      analogWrite(bluePin, 255); //blue light on

      input_password = ""; // reset the input password

      //generate first sine wave
      static float phase1 = 0;
      size_t bytes_written1;
      int16_t samples1[64];
      // Generate a 1kHz sine wave
      for (int i = 0; i < 64; i++) {
         samples1[i] = (int16_t)(32767 * sin(phase1));
         phase1 += 2 * PI * 5000 / SAMPLE_RATE;
         if (phase1 >= 2 * PI) {
            phase1 -= 2 * PI;
        }
      }


      //generate second cosine wave
      static float phase2 = 0;
      size_t bytes_written2;
      int16_t samples2[64];
      // Generate a xkHz sine wave
      for (int i = 0; i < 64; i++) {
         samples2[i] = (int16_t)(100000 * cos(phase2));
         phase2 += 2 * PI * 5000 / SAMPLE_RATE;
         if (phase2 >= 2 * PI) {
            phase2 -= 2 * PI;
        }
      }


      // make beeping sound 3 times
      for (int k = 0; k < 3; k++) {
          if(k%2 == 0)
          {
            int j1=0;
            analogWrite(greenPin, 255); //green light on
            analogWrite(redPin, 255); //red light on
            analogWrite(bluePin, 255); //blue light on
            while(j1<100){
              //i2s_write(I2S_NUM, samples1, sizeof(samples1), &bytes_written1, portMAX_DELAY);
              j1++;
            }
            analogWrite(redPin, 0); //red light off
            delay(50);
            }
          else
          {
            int j2=0;
            analogWrite(bluePin, 0); //blue light off
            analogWrite(redPin, 0); //red light off
            analogWrite(greenPin, 255); //green light on
            while(j2<100){
              //i2s_write(I2S_NUM, samples2, sizeof(samples2), &bytes_written2, portMAX_DELAY);
              j2++;
            }
            delay(50);
          }
        }
        analogWrite(greenPin, 0); //green light off
        analogWrite(bluePin, 0); //blue light off
        analogWrite(redPin, 0); //red light off
        Serial.println("password has been reset");
    }



  

/***     end of implifier and sound functions ***/




/***     here is the relay code and functions ***/
//relay:
#define RELAY_PIN   33 // ESP32 pin GPIO33 connected to the solenoid lock relay in1
//ezOutput relay(RELAY_PIN);
//realay wiring configoration
//VCC -> 3v3 red wire
//IN1-> D33 orange wire
//GND->GND brown wire

void opendoor()
{
          analogWrite(redPin, 0); //turn red light off
          analogWrite(bluePin, 0); //turn blue light off
          Serial.println("password is correct");
          analogWrite(greenPin, 255); //light green color
          digitalWrite(RELAY_PIN, LOW); // Unlock the door
          Serial.println("door open");
          CorrectPasswordSound();
          delay(5000);
          digitalWrite(RELAY_PIN, HIGH); // Lock the door
          Serial.println("door closed");
          analogWrite(greenPin, 0); //turn off green light
}


void donotopendoor()
{
          Serial.print(input_password);
          Serial.println(" is invalid , please Try again");
          analogWrite(bluePin, 0); //turn blue light off
          analogWrite(greenPin, 0); //turn blue light off
          analogWrite(redPin, 0); //turn red light off
          WrongPasswordSound();
          resetpassword();
}



/***     end of relay code and functions ***/



/***     here is the firebase and wifi connection ***/
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


int firebaseReadTime() {
 int time = firebase.getInt("time");

  return time;
}



/***    end of firebase and wifi connection ***/

unsigned long lastLockCheckTime = 0; // Variable to keep track of the last lock check time
const unsigned long lockCheckInterval = 6000; // Check the lock every 5 seconds
void checklock(void* param) // function to check the lock value in firebase
{
   while(true){
   unsigned long currentTime = millis();
  if (currentTime - lastLockCheckTime >= lockCheckInterval) {
    lastLockCheckTime = currentTime;
    int lock = firebase.getInt("lock");
    Serial.print("lock's value is: ");
    Serial.println(lock);
    if(lock > 1) {
      opendoor();
      firebase.setInt("lock", 1);
    }
   }
   }
   vTaskDelete(NULL);
}

// Firebase credentials and database URL

//#define DATABASE_URL "https://smartdoorbell-7e38f-default-rtdb.firebaseio.com/"
//FirebaseData firebase(DATABASE_URL);
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// NTP server to request epoch time
// const char* ntpServer = "0.pool.ntp.org";

// Variable to save current epoch time

// Function that gets current epoch time
// unsigned long getTime() {
//   time_t now;
//   struct tm timeinfo;
//   if (!getLocalTime(&timeinfo)) {
//     Serial.println("Failed to obtain time");
//     return(0);
//   }
//   time(&now);
//   return now;
// }

bool extract_codes(const char *input, const char *password, size_t size, char *extracted_code, long long *expiry_time) {
    const char *code_keyword = "\"code\":\"";
    const char *expiry_keyword = "\"expiry\":";
    char *position = strstr(input, code_keyword);

    while (position != NULL) {
        position += strlen(code_keyword);  // Move past the "code":" part
        int i = 0;

        // Extract code until the closing quotation mark
        while (position[i] != '"' && position[i] != '\0') {
            extracted_code[i] = position[i];
            i++;
        }
        extracted_code[i] = '\0';  // Null-terminate the string

        // Move past the closing quotation mark
        position += i + 1;
        
        if (strncmp(extracted_code, password, strlen(extracted_code)) == 0) {
           
          // Extract the expiry time
          char *expiry_position = strstr(position, expiry_keyword);
          if (expiry_position != NULL) {
              expiry_position += strlen(expiry_keyword);  // Move past the "expiry": part
              *expiry_time = strtoll(expiry_position, NULL, 10); // Convert expiry to long long

            
          } else {
              *expiry_time = 0; // Default value if expiry time not found
          }
          return true;
        }
      // Move to the next occurrence
      position = strstr(position, code_keyword);
    }
    return false;
}


bool checkPassword(String input_password) {
  String pass = firebase.getString("tempPass");
  const char* pass_char = pass.c_str();
  const char* input_password_char = input_password.c_str();

  char extracted_code[1000];
  long long expiry_time = 0;
  if(extract_codes(pass_char, input_password_char, input_password.length(), extracted_code, &expiry_time))
  {
    // check if the password is still valid
    //time_t current_time = time(NULL); // Get current time
    //Serial.println(current_time);
    //unsigned long currentTime2 = millis();
    //Serial.println(currentTime2);
    
    Serial.println(expiry_time);
    Serial.println(firebaseReadTime());
    
    if (expiry_time > firebaseReadTime()) {
        Serial.println("Valid code: ");
        Serial.println(extracted_code);
        return true;
    } else {
        Serial.println("Code expired");
        return false;
    }
  
  }
  else{
    return false;
  }
  Serial.print(pass);
}




void setup() {
  Serial.begin(9600);  // Adjusted for ESP32
  customKeypad.begin();
  pinMode(redPin, OUTPUT); 
  pinMode(greenPin, OUTPUT); 
  pinMode(bluePin, OUTPUT); 
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH);
  WiFi.mode(WIFI_STA);
  delay(1000);
  WiFi.begin(_SSID, _PASSWORD);
  Serial.print("CONNECTING TO WIFI");
  while (WiFi.status() != WL_CONNECTED) {
    delay(5);
    Serial.print(".");
  }
  Serial.println("");
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
  Serial.println("I2S protocol configured");

  // Install and start I2S driver
  i2s_driver_install(I2S_NUM, &i2s_config, 0, NULL);
  i2s_set_pin(I2S_NUM, &pin_config);
  i2s_zero_dma_buffer(I2S_NUM);
  Serial.println("I2S driver installed");
  xTaskCreate(checklock , "Check lock" , 5000 , NULL , 1 , NULL);
  //xTaskCreate(handledoorbell , "handledoorbell" , 50000 , NULL , 5 , NULL);
  //handledoorbell
}





void loop() {
  //Turn off all lights (just to be sure)
  analogWrite(bluePin, 0);
  analogWrite(redPin, 0);
  analogWrite(greenPin, 0); 
  customKeypad.tick();
  keypadEvent e = customKeypad.read();
  char key = (char)e.bit.KEY;
  if (e.bit.EVENT == KEY_JUST_PRESSED) {
      analogWrite(bluePin, 255); //blue light on when pressed
      if (key != '*')
            KeyPressedSound(); //any time a key is pressed it makes a sound
      Serial.print(key);
      Serial.println(" pressed");
      if (key == '*') {
        resetpassword();
      } else if (key == '#') 
      {
        if(input_password == password)
        {
          opendoor();
        }
        else if(checkPassword(input_password))
        {
          opendoor();
        }
        else 
        {
          if(input_password == "") {
          EmptyPasswordSound();
          } 
          else { donotopendoor(); }
        }
       input_password = ""; // reset the input password
     }else {
      input_password += key; // append new character to input password string
      Serial.print("password till now is : ");
      Serial.println(input_password);
      }
      analogWrite(bluePin, 0); //turn of blue light
    } else if (e.bit.EVENT == KEY_JUST_RELEASED) {
      Serial.print(key);
      Serial.println(" released");
    }
  //checklock();
  //handledoorbell();
}