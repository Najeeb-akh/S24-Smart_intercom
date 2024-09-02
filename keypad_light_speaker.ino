//this code makes the speaker make noise when pressing akey on the keypad
#include <Adafruit_Keypad.h> // Correct inclusion of the library
#include <Arduino.h>
#include <driver/i2s.h>
#include <math.h>

// Define the pins for RGB LED (assuming common cathode)
const int redPin = 13;    // Red pin

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

// Define I2S pins
#define I2S_NUM         I2S_NUM_0
#define I2S_BCK_PIN     26
#define I2S_WS_PIN      27
#define I2S_DATA_PIN    25
#define SAMPLE_RATE     44100
#define PI              3.14159265358979323846

//connect pins :
//Vin -> 3v3
//GND -> GND
//SD + GAIN are unconnected
//DIN -> D25
//BCLK -> D26
//LRC -> D27

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
   pinMode(redPin, OUTPUT);
  Serial.begin(115200);  // Adjusted for ESP32
  customKeypad.begin();


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
   static float phase = 0;
  size_t bytes_written;
  int16_t samples[64];
  customKeypad.tick();
  while(customKeypad.available()) {
    keypadEvent e = customKeypad.read();
    char key = (char)e.bit.KEY;
    Serial.print(key);
    if (e.bit.EVENT == KEY_JUST_PRESSED) {
      Serial.println(" pressed");
       // Generate a 1kHz sine wave
      for (int i = 0; i < 64; i++) {
         samples[i] = (int16_t)(32767 * sin(phase));
         phase += 2 * PI * 5000 / SAMPLE_RATE;
         setColor(255, 0, 0);   // Red
         if (phase >= 2 * PI) {
            phase -= 2 * PI;
        }
      }
  i2s_write(I2S_NUM, samples, sizeof(samples), &bytes_written, portMAX_DELAY);
    } else if (e.bit.EVENT == KEY_JUST_RELEASED) {
      Serial.println(" released");
      for (int i = 0; i < 64; i++) {
        samples[i] = (int16_t)(32767 * sin(phase));
        phase += 2 * PI * 5000 / SAMPLE_RATE;
        setColor(0, 0, 0);   // Red
        if (phase >= 2 * PI) {
              phase -= 2 * PI;
        }
      }
  i2s_write(I2S_NUM, samples, sizeof(samples), &bytes_written, portMAX_DELAY);
    }
  }

  delay(10);
}




// Function to set RGB color based on PWM values (0-255)
void setColor(int redValue, int greenValue, int blueValue) {
  analogWrite(redPin, redValue); 
}
