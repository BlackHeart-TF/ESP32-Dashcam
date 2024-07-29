#if defined(CAMERA_MODEL_FREENOVE_ESP32S3)
  #define LED_IS_NEOPIXEL	
  #define LED_PIN					48
  #define IGNITION_PIN    46
  #define SD_CLK          39
  #define SD_CMD          38
  #define SD_D0           40

#elif defined(CAMERA_MODEL_SEEED_ESP32S3)
  #define LED_PIN					LED_BUILTIN
  #define IGNITION_PIN    1
  #define SD_CS           21
  #define SD_CLK          7
  #define SD_CMD          9
  #define SD_D0           8

#elif defined(CAMERA_MODEL_M5STACK_UNITCAM_S3)
  #define LED_PIN					14
  #define IGNITION_PIN    0
  #define SD_CS           9
  #define SD_CLK          39
  #define SD_CMD          38
  #define SD_D0           40
#else
  #error "Camera model not selected"
#endif