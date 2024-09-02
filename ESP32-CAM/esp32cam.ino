// // #include <WiFi.h>
// // #include <HTTPClient.h>
// // #include <ESP32Firebase.h>

// // #include <WiFiClientSecure.h>
// // #include <Base64.h>
// // #include <SPIFFS.h>

// // //#include <FirebaseJson.h>  
// // #define _SSID "Dorms163-5"          // Your WiFi SSID
// // #define _PASSWORD "16351635"    // Your WiFi Password


// // // /* 3. Define the RTDB URL */
// // #define DATABASE_URL "https://console.firebase.google.com/u/0/project/smartdoorbell-7e38f/database/smartdoorbell-7e38f-default-rtdb/data/~2F" //<databaseName>.firebaseio.com or <databaseName>.<region>.firebasedatabase.app
// // //https://console.firebase.google.com/u/0/project/smartdoorbell-7e38f/database/smartdoorbell-7e38f-default-rtdb/data/~2F
// // #define REFERENCE_URL "https://smartdoorbell-7e38f-default-rtdb.firebaseio.com/"
// // //https://console.firebase.google.com/u/0/project/smartdoorbell-7e38f/database/smartdoorbell-7e38f-default-rtdb/data/~2F"
// // #define FIREBASE_AUTH "AIzaSyAHANIi3AEgVl8ir3Cs5ePn6qJLWD9LY1Y"


// // /*******     here is the firebase and wifi connection *******/
// // Firebase firebase(REFERENCE_URL);

// // void firebaseSetup() {
// //   Serial.println("Connecting to WIFI: Pending...");
// //   WiFi.mode(WIFI_STA);
// //   WiFi.disconnect();
// //   delay(1000);
// //   WiFi.begin(_SSID, _PASSWORD);

// //   while (WiFi.status() != WL_CONNECTED) {
// //     //freeplay();
// //     delay(10);
// //     //Serial.print("-");
// //   }
// //   Serial.println("Connected to WIFI");
// // }

// // int firebaseReadLock() {
// //   int lck = firebase.getInt("lck");

// //   return lck;
// // }


// // int firebaseReadTime() {
// //  int time = firebase.getInt("time");

// //   return time;
// // }



// // /*******    end of firebase and wifi connection *******/



// // void listSPIFFSFiles() {
// //   Serial.println("Listing files in SPIFFS:");
// //   File root = SPIFFS.open("/");
// //   File file = root.openNextFile();
// //   while (file) {
// //     Serial.print("FILE: ");
// //     Serial.println(file.name());
// //     file = root.openNextFile();
// //   }
// //   Serial.println("Done listing files.");
// // }


// // void setup() {
// //   Serial.begin(9600);  // Adjusted for ESP32
// //   WiFi.mode(WIFI_STA);
// //   //WiFi.disconnect();
// //   delay(1000);
// //   WiFi.begin(_SSID, _PASSWORD);
// //   Serial.print("CONNECTING TO WIFI");
// //   while (WiFi.status() != WL_CONNECTED) {
// //     delay(5);
// //     Serial.print(".");
// //   }
// //   Serial.println("");
// //   Serial.println("Connected to WIFI");

  
// //   if (!SPIFFS.begin(true)) {
// //     Serial.println("An error occurred while mounting SPIFFS");
// //     return;
// //   }

// //   listSPIFFSFiles();

  
// //   // Test string upload
// //   if (sendTestString()) {
// //     Serial.println("Test string sent to Firebase successfully.");
// //   } else {
// //     Serial.println("Failed to send test string.");
// //   }
  

// //   // Open the root directory
// //   File root = SPIFFS.open("/");

// //   // Open the first file in the directory
// //   File file = root.openNextFile();

// //   // Loop through all the files
// //   while (file) {
// //     Serial.print("FILE: ");
// //     Serial.println(file.name());  // Print the file name
// //     if (sendWavFile(file.name())) {
// //       Serial.println("WAV file sent to Firebase successfully.");
// //     } else {
// //       Serial.println("Failed to send WAV file.");
// //     }
// //     file = root.openNextFile();   // Move to the next file
// //   }


// //   // // Check if file exists
// //   // if (SPIFFS.exists("/start_message.wav")) {
// //   //   Serial.println("WAV file exists. Proceeding to send...");
// //   //   // Read, encode, and send the WAV file to Firebase Realtime Database
// //   //   if (sendWavFile("/start_message.wav")) {
// //   //     Serial.println("WAV file sent to Firebase successfully.");
// //   //   } else {
// //   //     Serial.println("Failed to send WAV file.");
// //   //   }
// //   // } else {
// //   //   Serial.println("WAV file does not exist in SPIFFS.");
// //   // }
// // }


// // void loop() {}




// // bool sendTestString() {
// //   String testPath = "/ICST/TestString";
// //   String testValue = "This is a test";
// //   bool success = false;
// //   Serial.println("Sending test string...");
// //   firebase.setString("/images/image/image", testValue);
// //   if (firebase.getString("/images/image/image") != "") {
// //     Serial.println("Test string uploaded successfully.");
// //     success = true;

// //   } else {
// //     Serial.println("Failed to upload test string.");
// //     //Serial.printf("Error: %s\n", result.error().message().c_str());
// //   }
// //   return success;
// // }

// // bool sendWavFile(const char* filename) {
// //   File file = SPIFFS.open(filename, FILE_READ);
// //   if (!file) {
// //     Serial.println("Failed to open img file for reading");
// //     return false;
// //   }

// //   Serial.println("WAV file opened successfully.");
// //   size_t fileSize = file.size();
// //   Serial.printf("WAV file size: %d bytes\n", fileSize);

// //   // Open the root directory
// //   File root = SPIFFS.open("/");

// //   // Open the first file in the directory
// //   File file = root.openNextFile();

// //   // Loop through all the files
// //   while (file) {
// //     Serial.print("FILE: ");
// //     Serial.println(file.name());  // Print the file name
// //     if (sendWavFile(file.name())) {
// //       Serial.println("WAV file sent to Firebase successfully.");
// //     } else {
// //       Serial.println("Failed to send WAV file.");
// //     }
// //     file = root.openNextFile();   // Move to the next file
// //   }


// //   // Reset file pointer to the beginning
// //   file.seek(0, SeekSet);

// //   const size_t bufferSize = 512 * 8;
// //   uint8_t buffer[bufferSize];
// //   size_t bytesRead;
// //   size_t chunkIndex = 0;

// //   Serial.println("Reading and encoding img file...");

// //   while ((bytesRead = file.read(buffer, bufferSize)) > 0) {
// //     Serial.printf("Read %d bytes from img file at position %d\n", bytesRead, file.position());

// //     if (bytesRead > 0) {
// //       String encodedChunk = base64::encode(buffer, bytesRead);
// //       String path = String("/images/image/chunk") + chunkIndex;

// //       // Try to set data to Firebase and log the result
// //       //bool success = Database.set<String>(client, path.c_str(), encodedChunk);
// //       firebase.setString(path.c_str(),encodedChunk);
      
// //       if (firebase.getString(path.c_str()) != "") {
// //         Serial.printf("Chunk %d uploaded successfully\n", chunkIndex);
// //         chunkIndex++;
// //       } else {
// //         Serial.printf("Failed to upload chunk %d\n", chunkIndex);
// //         //Serial.printf("Error: %s\n", result.error().message().c_str());
// //         file.close();
// //         return false;
// //       }
// //     } else {
// //       Serial.println("No data read from file.");
// //     }

// //     delay(100);  // Small delay to avoid overwhelming the server
// //   }

// //   if (chunkIndex == 0) {
// //     Serial.println("No chunks were processed.");
// //   }

// //   Serial.println("Finished reading and encoding WAV file.");
// //   file.close();

// //   // Fallback test read
// //   file = SPIFFS.open(filename, FILE_READ);
// //   if (!file) {
// //     Serial.println("Failed to reopen WAV file for reading");
// //     return false;
// //   }
// //   Serial.println("Reopened WAV file for fallback read test.");
// //   bytesRead = file.read(buffer, bufferSize);
// //   Serial.printf("Fallback read %d bytes from WAV file\n", bytesRead);
// //   file.close();

// //   return true;
// // }




#include <WiFi.h>
#include <ESP32Firebase.h>
#include <WiFiClientSecure.h>
#include <Base64.h>
#include <SPIFFS.h>
#include "esp_camera.h"

// WiFi credentials
#define _SSID "ICST"
#define _PASSWORD "arduino123"

// Firebase configuration
#define REFERENCE_URL "https://smartdoorbell-7e38f-default-rtdb.firebaseio.com/"
#define FIREBASE_AUTH "AIzaSyAHANIi3AEgVl8ir3Cs5ePn6qJLWD9LY1Y"

// Firebase object
Firebase firebase(REFERENCE_URL);

// Camera settings (adjust based on your ESP32 CAM module)
#define PWDN_GPIO_NUM    32
#define RESET_GPIO_NUM   -1
#define XCLK_GPIO_NUM     0
#define SIOD_GPIO_NUM    26
#define SIOC_GPIO_NUM    27
#define Y9_GPIO_NUM      35
#define Y8_GPIO_NUM      34
#define Y7_GPIO_NUM      39
#define Y6_GPIO_NUM      36
#define Y5_GPIO_NUM      21
#define Y4_GPIO_NUM      19
#define Y3_GPIO_NUM      18
#define Y2_GPIO_NUM       5
#define VSYNC_GPIO_NUM   25
#define HREF_GPIO_NUM    23
#define PCLK_GPIO_NUM    22

void setup() {
  Serial.begin(115200);
  
  // Initialize WiFi
  Serial.println("Connecting to WIFI...");
  WiFi.begin(_SSID, _PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected to WIFI");

  // Initialize camera
  camera_config_t config;
  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer = LEDC_TIMER_0;
  config.pin_d0 = Y2_GPIO_NUM;
  config.pin_d1 = Y3_GPIO_NUM;
  config.pin_d2 = Y4_GPIO_NUM;
  config.pin_d3 = Y5_GPIO_NUM;
  config.pin_d4 = Y6_GPIO_NUM;
  config.pin_d5 = Y7_GPIO_NUM;
  config.pin_d6 = Y8_GPIO_NUM;
  config.pin_d7 = Y9_GPIO_NUM;
  config.pin_xclk = XCLK_GPIO_NUM;
  config.pin_pclk = PCLK_GPIO_NUM;
  config.pin_vsync = VSYNC_GPIO_NUM;
  config.pin_href = HREF_GPIO_NUM;
  config.pin_sscb_sda = SIOD_GPIO_NUM;
  config.pin_sscb_scl = SIOC_GPIO_NUM;
  config.pin_pwdn = PWDN_GPIO_NUM;
  config.pin_reset = RESET_GPIO_NUM;
  config.xclk_freq_hz = 20000000;
  config.pixel_format = PIXFORMAT_JPEG;
  config.frame_size = FRAMESIZE_QVGA; // Reduced frame size
  config.jpeg_quality = 12; // Lower quality for less memory use
  config.fb_count = 1;      // Use only 1 frame buffer

  // Initialize camera
  if (esp_camera_init(&config) != ESP_OK) {
    Serial.println("Camera init failed");
    return;
  }
  
  // Capture and send an image
  while (captureAndSendImage()) {
    Serial.println("Image sent to Firebase successfully.");
  
  }
}

void loop() {
  // Keep the loop empty for now
}

bool captureAndSendImage() {
  camera_fb_t * fb = esp_camera_fb_get();
  if (!fb) {
    Serial.println("Camera capture failed");
    return false;
  }

  // Encode image to Base64
  String encodedImage = base64::encode(fb->buf, fb->len);
  
  // Create Firebase path for the image
  String path = "chunk";

  // Send encoded image to Firebase
  firebase.setString(path.c_str(), encodedImage);

  // Check if upload was successful
  bool success = firebase.getString(path.c_str()) != "";
  esp_camera_fb_return(fb); // Return the framebuffer
  yield();
  return success;
}




// #include <WiFi.h>
// #include <ESP32Firebase.h>
// #include <WiFiClientSecure.h>
// #include <Base64.h>
// #include <SPIFFS.h>
// #include "esp_camera.h"
// #include "esp_system.h"
// #include "soc/soc.h"
// #include "soc/rtc_cntl_reg.h"
// // // WiFi credentials
// // #define _SSID "ICST"
// // #define _PASSWORD "arduino123"

// #define _SSID "Dorms163-5"          // Your WiFi SSID
// #define _PASSWORD "16351635"    // Your WiFi Password
// // Firebase configuration
// #define REFERENCE_URL "https://smartdoorbell-7e38f-default-rtdb.firebaseio.com/"
// #define FIREBASE_AUTH "AIzaSyAHANIi3AEgVl8ir3Cs5ePn6qJLWD9LY1Y"

// // Firebase object
// Firebase firebase(REFERENCE_URL);

// // Camera settings (adjust based on your ESP32 CAM module)
// #define PWDN_GPIO_NUM    32
// #define RESET_GPIO_NUM   -1
// #define XCLK_GPIO_NUM     0
// #define SIOD_GPIO_NUM    26
// #define SIOC_GPIO_NUM    27
// #define Y9_GPIO_NUM      35
// #define Y8_GPIO_NUM      34
// #define Y7_GPIO_NUM      39
// #define Y6_GPIO_NUM      36
// #define Y5_GPIO_NUM      21
// #define Y4_GPIO_NUM      19
// #define Y3_GPIO_NUM      18
// #define Y2_GPIO_NUM       5
// #define VSYNC_GPIO_NUM   25
// #define HREF_GPIO_NUM    23
// #define PCLK_GPIO_NUM    22

// void setup() {
//   Serial.begin(115200);
  
//   // Initialize WiFi
//   Serial.println("Connecting to WIFI...");
//   WiFi.begin(_SSID, _PASSWORD);
//   while (WiFi.status() != WL_CONNECTED) {
//     delay(500);
//     Serial.print(".");
//   }
//   Serial.println("Connected to WIFI");
//   //WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0);
//   // Initialize camera
//   camera_config_t config;
//   config.ledc_channel = LEDC_CHANNEL_0;
//   config.ledc_timer = LEDC_TIMER_0;
//   config.pin_d0 = Y2_GPIO_NUM;
//   config.pin_d1 = Y3_GPIO_NUM;
//   config.pin_d2 = Y4_GPIO_NUM;
//   config.pin_d3 = Y5_GPIO_NUM;
//   config.pin_d4 = Y6_GPIO_NUM;
//   config.pin_d5 = Y7_GPIO_NUM;
//   config.pin_d6 = Y8_GPIO_NUM;
//   config.pin_d7 = Y9_GPIO_NUM;
//   config.pin_xclk = XCLK_GPIO_NUM;
//   config.pin_pclk = PCLK_GPIO_NUM;
//   config.pin_vsync = VSYNC_GPIO_NUM;
//   config.pin_href = HREF_GPIO_NUM;
//   config.pin_sscb_sda = SIOD_GPIO_NUM;
//   config.pin_sscb_scl = SIOC_GPIO_NUM;
//   config.pin_pwdn = PWDN_GPIO_NUM;
//   config.pin_reset = RESET_GPIO_NUM;
//   config.xclk_freq_hz = 35000000;
//   config.pixel_format = PIXFORMAT_JPEG;
//   config.frame_size = FRAMESIZE_QVGA; // Adjusted frame size
//   config.jpeg_quality = 12; // Adjusted quality for balance
//   config.fb_count = 1; // Use only 1 frame buffer
//   //camera_config.fb_location = CAMERA_FB_IN_PSRAM;
  
  
  
//   if (esp_camera_init(&config) != ESP_OK) {
//     Serial.println("Camera init failed");
//     return;
//   }
//   else
//   {
//      Serial.println("Camera init sucess");

//   } 
  
//  ///while(true){
  
//   //}
// }

// void loop () {
//   camera_fb_t * fb = esp_camera_fb_get();
//   esp_camera_fb_return(fb);
//   fb = esp_camera_fb_get(); 
//   if(!fb) {
//     Serial.println("Camera capture failed");
//     esp_camera_fb_return(fb);
//     return;
//   }
//   // Get fb->buf and/or fb->len here
//   esp_camera_fb_return(fb); 
// }

// bool captureAndSendImage() {
//   camera_fb_t * fb = esp_camera_fb_get();
//   if (!fb) {
//     Serial.println("Camera capture failed");
//     return false;
//   }

//   sensor_t *s = esp_camera_sensor_get();
//   if(!s)
//   {
//     s->set_whitebal(s, 0);  // Disable automatic white balance
//     s->set_brightness(s, 0);  // Default brightness
//     s->set_contrast(s, 0);  // Default contrast
//   }

//   // Encode image to Base64
//   String encodedImage = base64::encode(fb->buf, fb->len);

//   // // Split the encoded image into chunks
//   // const size_t chunkSize = fb->len; // Adjust chunk size as needed
//   // size_t totalChunks = 1;
//   // //(encodedImage.length() + chunkSize - 1) / chunkSize;

//   // for (size_t i = 0; i < totalChunks; i++) {
//   //   String chunk = encodedImage.substring(i * chunkSize, (i + 1) * chunkSize);
//   String path = String("chunk");
    
//   //   // Send chunk to Firebase
//     if (firebase.setString(path.c_str(), encodedImage)) {
//       Serial.printf("Chunk %d uploaded successfully\n");
//     } else {
//       Serial.printf("Failed to upload chunk %d\n");
//       esp_camera_fb_return(fb); // Return the framebuffer
//       //yield();
//       return false;
//     }

//     //delay(100);  // Small delay to avoid overwhelming the server
//     //yield();     // Allow other tasks to run
//   //}

//   esp_camera_fb_return(fb); // Return the framebuffer
//   return true;
// }
