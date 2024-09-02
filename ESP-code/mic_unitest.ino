#include <Arduino.h>
#include <driver/i2s.h>

// Define I2S pins
#define I2S_NUM         I2S_NUM_0
#define I2S_BCK_PIN     26
#define I2S_WS_PIN      25
#define I2S_DATA_PIN    22
#define SAMPLE_RATE     44100

void setup() {
  Serial.begin(115200);
  Serial.println("Setup starting...");

  // I2S configuration
  i2s_config_t i2s_config = {
    .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_RX),  // Master, RX only
    .sample_rate = SAMPLE_RATE,
    .bits_per_sample = I2S_BITS_PER_SAMPLE_16BIT,
    .channel_format = I2S_CHANNEL_FMT_ONLY_LEFT,          // Only one channel (mono)
    .communication_format = I2S_COMM_FORMAT_I2S,
    .intr_alloc_flags = 0, // default interrupt priority
    .dma_buf_count = 8,
    .dma_buf_len = 64,
    .use_apll = false,
    .tx_desc_auto_clear = false,
    .fixed_mclk = 0
  };

  // I2S pin configuration
  i2s_pin_config_t pin_config = {
    .bck_io_num = I2S_BCK_PIN,
    .ws_io_num = I2S_WS_PIN,
    .data_out_num = I2S_PIN_NO_CHANGE,
    .data_in_num = I2S_DATA_PIN
  };

  // Install and start I2S driver
  if (i2s_driver_install(I2S_NUM, &i2s_config, 0, NULL) != ESP_OK) {
    Serial.println("Failed to install I2S driver");
    while (true);
  }
  if (i2s_set_pin(I2S_NUM, &pin_config) != ESP_OK) {
    Serial.println("Failed to set I2S pins");
    while (true);
  }
  i2s_zero_dma_buffer(I2S_NUM);

  Serial.println("Setup complete.");
}

void loop() {
  int16_t samples[64];
  size_t bytes_read;

  // Read data from I2S
  if (i2s_read(I2S_NUM, samples, sizeof(samples), &bytes_read, portMAX_DELAY) == ESP_OK) {
    Serial.print("Bytes read: ");
    Serial.println(bytes_read);

    // Print the sample values to the Serial Monitor
    for (int i = 0; i < bytes_read / sizeof(int16_t); i++) {
      Serial.println(samples[i]);
    }
  } else {
    Serial.println("Failed to read from I2S");
  }

  delay(1000); // Delay 1 second
}