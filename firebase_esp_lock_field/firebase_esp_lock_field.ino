/*************************************************/
/*                                                         WIFI CONNECTION                                                                         */
/*************************************************/

// WiFi and Firebase setup
#include <ESP32Firebase.h>
#define _SSID "ICST"          // Your WiFi SSID
#define _PASSWORD "arduino123"    // Your WiFi Password

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

// String firebaseReadSong(int songNum) {
//   String songStr = "/songs/song" + String(songNum);
//   String song = firebase.getString(songStr);
//   Serial.print("Song is:");
//   Serial.println(song);
//   return song;
// }


void setup() {
  // pinMode(27, OUTPUT) ;
  Serial.begin(9600);
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


  // while (!Serial) { // needed to keep leonardo/micro from starting too fast!
  //   delay(10);
  // }
 

  // firebaseSetup();
}


/***************************************************************************************************************************************************/
/*                                                                loop                                                                             */
/***************************************************************************************************************************************************/

void loop() {
  Serial.println("here");
  Serial.println("here2222");
  int lock = firebase.getInt("lock");
  Serial.println(lock);

  return;
}
