#ifndef CONFIG_H
#define CONFIG_H

#define SERIAL_BAUD				115200

#define MOUNT_POINT				"/sdcard"

#define EEPROM_SIZE				7		// total bytes to use
#define EEPROM_ADDR_FOLDER_NUM	1		// address of `folder_num` in EEPROM
#define EEPROM_ADDR_FRAMESIZE	5		// address of `framesize` in EEPROM
#define EEPROM_ADDR_QUALITY		6		// address of `quality` in EEPROM

// Select camera model
#define CAMERA_MODEL_FREENOVE_ESP32S3
//#define CAMERA_MODEL_SEEED_ESP32S3


#include "sd_led_pins.h"
#include "camera_pins.h"

#endif
