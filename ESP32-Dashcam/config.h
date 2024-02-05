#ifndef CONFIG_H
#define CONFIG_H


#define DEVICE_NAME		       		"eyESPy32"
#define SERIAL_BAUD				      115200
#define WIFIMGR_TIMEOUT		     	120				// in seconds
#define AUTOSTART_REC	   	    	1
#define AVILENGTH			        	3600				// sec. Files larger than 4Gb can not be stored on a FAT32 volume. To be sure, assume 1 sec = 375 kB

#define MOUNT_POINT			      	"/sdcard"

#define DEBOUNCE_DELAY          50 // Debounce delay in milliseconds

// EEPROM 
#define EEPROM_SIZE				      7		// total bytes to use
#define EEPROM_ADDR_FOLDER_NUM	1		// address of `folder_num` in EEPROM
#define EEPROM_ADDR_FRAMESIZE	  5		// address of `framesize` in EEPROM
#define EEPROM_ADDR_QUALITY		  6		// address of `quality` in EEPROM

// Uncomment your board model if its added, or check "camera_pins.h" and "sd_led_pins.h" for more
#define CAMERA_MODEL_FREENOVE_ESP32S3
//#define CAMERA_MODEL_SEEED_ESP32S3


#include "sd_led_pins.h"
#include "camera_pins.h"

#endif
