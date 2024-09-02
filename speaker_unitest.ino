#include <Arduino.h>
#include <driver/i2s.h>
#include <math.h>

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


void setup() {
  Serial.begin(115200);

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

  // Generate a 1kHz sine wave
  for (int i = 0; i < 64; i++) {
    samples[i] = (int16_t)(32767 * sin(phase));
    phase += 2 * PI * 1000 / SAMPLE_RATE;
    if (phase >= 2 * PI) {
      phase -= 2 * PI;
    }
  }

  i2s_write(I2S_NUM, samples, sizeof(samples), &bytes_written, portMAX_DELAY);
}
