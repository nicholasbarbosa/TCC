#include "camera_pins.h"
#include "esp_camera.h"
#include <WiFi.h>
#include <HTTPClient.h>

const char *urlAPI = "http://192.168.1.9:8000";
//const char *urlAPI = "http://192.168.1.106:8000";
HTTPClient http;

const char *ssid = "tchucas";
const char *password = "#10N20S30M40";

//const char *ssid = "dpi-mestrado";
//const char *password = "DLrVk89XYj";

int label = 0;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando-se à rede Wi-Fi...");
  }

  Serial.println("Conectado à rede Wi-Fi!");

  http.begin(urlAPI);
  http.addHeader("Content-Type", "application/json");
  http.addHeader("Content-Type", "multipart/form-data");

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
  config.frame_size = FRAMESIZE_UXGA;
  config.jpeg_quality = 10;
  config.fb_count = 2;

  esp_err_t err = esp_camera_init(&config);

  if (err != ESP_OK) {
    Serial.printf("Falha ao inicializar a câmera 0x%x", err);
    return;
  }

  Serial.print("Endereço IP do ESP32: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  delay(5000);
  camera_fb_t *fb = esp_camera_fb_get();

  if (!fb) {
      Serial.println("Falha ao capturar a imagem");
  } else {
      Serial.println("Imagem capturada");

      http.addHeader("Content-Type", "image/jpeg");
      http.addHeader("Content-Length", String(fb->len));
      http.addHeader("Connection", "close");
      http.addHeader("User-Agent", "ESP32-CAM");

      http.sendRequest("POST", (uint8_t*)fb->buf, fb->len);

      String response = http.getString();

      Serial.println(response);

      esp_camera_fb_return(fb);
    }
}
