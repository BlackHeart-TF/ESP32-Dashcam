#define SERIAL_BAUD				115200

#define MOUNT_POINT				"/sdcard"

#define EEPROM_SIZE				7		// total bytes to use
#define EEPROM_ADDR_FOLDER_NUM	1		// address of `folder_num` in EEPROM
#define EEPROM_ADDR_FRAMESIZE	5		// address of `framesize` in EEPROM
#define EEPROM_ADDR_QUALITY		6		// address of `quality` in EEPROM

//#define LED_IS_NEOPIXEL				// uncomment for neopixel driver, else regular gpio

//#if defined(CAMERA_MODEL_FREENOVE_ESP32S3)
#define LED_IS_NEOPIXEL	
#define LED_PIN					48
#define IGNITION_PIN    19
#define SD_CLK          39
#define SD_CMD          38
#define SD_D0           40
// #elif defined(CAMERA_MODEL_SEEED_ESP32S3)
// #define LED_PIN					LED_BUILTIN
// #define IGNITION_PIN    19
// #define SD_CLK          7
// #define SD_CMD          9
// #define SD_D0           8
// #else
//   #error "Camera model not selected"
// #endif
