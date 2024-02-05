#include "EEPROMHandler.h"
#include <EEPROM.h>

#define EEPROM_MAGIC_NUM        0x6600  // Example magic number
#define EEPROM_MAGIC_ADDR       0       // Address to store the magic number
#define EEPROM_ADDR_FRAMESIZE	  2		    // address of `framesize` in EEPROM
#define EEPROM_ADDR_QUALITY		  4
#define EEPROM_ADDR_CONTRAST    6
#define EEPROM_ADDR_BRIGHTNESS  8
#define EEPROM_ADDR_SATURATION  10
#define EEPROM_ADDR_GAINCEIL    12
#define EEPROM_ADDR_AUTORECORD  14
#define EEPROM_ADDR_AWB         16
#define EEPROM_ADDR_AGC         18
#define EEPROM_ADDR_AEC         20
#define EEPROM_ADDR_HMIRROR     22
#define EEPROM_ADDR_VFLIP       24
#define EEPROM_ADDR_AWB_GAIN    26
#define EEPROM_ADDR_AGC_GAIN    28
#define EEPROM_ADDR_AEC_VALUE   30
#define EEPROM_ADDR_AEC2        32
#define EEPROM_ADDR_DCW         34
#define EEPROM_ADDR_BPC         36
#define EEPROM_ADDR_WPC         38
#define EEPROM_ADDR_RAW_gma     40
#define EEPROM_ADDR_LENC        42
#define EEPROM_ADDR_EFFECT      44
#define EEPROM_ADDR_WB_MODE     46
#define EEPROM_ADDR_AE_LEVEL    48
#define EEPROM_SIZE             50

EEPROMHandler::EEPROMHandler() {
    EEPROM.begin(EEPROM_SIZE);
    initEEPROM();
}

void EEPROMHandler::saveSetting(const char* settingName, short value) {
    short addr = getSettingAddress(settingName);
    if (addr != -1) {
        EEPROM.put(addr, value);
        EEPROM.commit();
    }
}

short EEPROMHandler::loadSetting(const char* settingName) {
    short addr = getSettingAddress(settingName);
    if (addr != -1) {
        int value;
        EEPROM.get(addr, value);
        return value;
    }
    return -1; // Or some default value
}

short EEPROMHandler::getSettingAddress(const char* settingName) {
    // Map setting name to EEPROM address
    // Example:
    if (strcmp(settingName, "framesize") == 0) return EEPROM_ADDR_FRAMESIZE;
    if (strcmp(settingName, "quality") == 0) return EEPROM_ADDR_QUALITY;
    if(!strcmp(settingName, "contrast") == 0) return EEPROM_ADDR_CONTRAST;
    if(!strcmp(settingName, "brightness") == 0) return EEPROM_ADDR_BRIGHTNESS;
    if(!strcmp(settingName, "saturation") == 0) return EEPROM_ADDR_SATURATION;
    if(!strcmp(settingName, "gainceiling") == 0) return EEPROM_ADDR_GAINCEIL;
    if(!strcmp(settingName, "autorecord") == 0) return EEPROM_ADDR_AUTORECORD;
    if(!strcmp(settingName, "awb") == 0) return EEPROM_ADDR_AWB;
    if(!strcmp(settingName, "agc") == 0) return EEPROM_ADDR_AGC;
    if(!strcmp(settingName, "aec") == 0) return EEPROM_ADDR_AEC;
    if(!strcmp(settingName, "hmirror") == 0) return EEPROM_ADDR_HMIRROR;
    if(!strcmp(settingName, "vflip") == 0) return EEPROM_ADDR_VFLIP;
    if(!strcmp(settingName, "awb_gain") == 0) return EEPROM_ADDR_AWB_GAIN;
    if(!strcmp(settingName, "agc_gain") == 0) return EEPROM_ADDR_AGC_GAIN;
    if(!strcmp(settingName, "aec_value") == 0) return EEPROM_ADDR_AEC_VALUE;
    if(!strcmp(settingName, "aec2") == 0) return EEPROM_ADDR_AEC2;
    if(!strcmp(settingName, "dcw") == 0) return EEPROM_ADDR_DCW;
    if(!strcmp(settingName, "bpc") == 0) return EEPROM_ADDR_BPC;
    if(!strcmp(settingName, "wpc") == 0) return EEPROM_ADDR_WPC;
    if(!strcmp(settingName, "raw_gma") == 0) return EEPROM_ADDR_RAW_gma;
    if(!strcmp(settingName, "lenc") == 0) return EEPROM_ADDR_LENC;
    if(!strcmp(settingName, "special_effect") == 0) return EEPROM_ADDR_EFFECT;
    if(!strcmp(settingName, "wb_mode") == 0) return EEPROM_ADDR_WB_MODE;
    if(!strcmp(settingName, "ae_level") == 0) return EEPROM_ADDR_AE_LEVEL;
    // Add other settings here...
    return -1;
}
void EEPROMHandler::initEEPROM() {
    int magicNum;
    EEPROM.get(EEPROM_MAGIC_ADDR, magicNum);
    if (magicNum != EEPROM_MAGIC_NUM) {
        // Magic number not found, initialize EEPROM
        EEPROM.put(EEPROM_MAGIC_ADDR, EEPROM_MAGIC_NUM);
        // Initialize other settings with default values
        EEPROM.put(EEPROM_ADDR_FRAMESIZE, 5);//Resolution//int 0-10 
        EEPROM.put(EEPROM_ADDR_QUALITY, 63);//Quality//int 110,63
        EEPROM.put(EEPROM_ADDR_CONTRAST, 0);//Contrast//int -2,2
        EEPROM.put(EEPROM_ADDR_BRIGHTNESS, 0);//Brightness//int -2,2
        EEPROM.put(EEPROM_ADDR_SATURATION, 0);//Saturation//int -2,2
        EEPROM.put(EEPROM_ADDR_GAINCEIL, 0);//Gain Ceiling//int 0,6
        EEPROM.put(EEPROM_ADDR_AUTORECORD, 0);//Auto Record//bool
        EEPROM.put(EEPROM_ADDR_AWB, 1);//AWB//bool
        EEPROM.put(EEPROM_ADDR_AGC, 1);//AGC//bool
        EEPROM.put(EEPROM_ADDR_AEC, 1);//AEC SENSOR//bool
        EEPROM.put(EEPROM_ADDR_HMIRROR, 0);//bool
        EEPROM.put(EEPROM_ADDR_VFLIP, 0);//bool
        EEPROM.put(EEPROM_ADDR_AWB_GAIN, 1);//AWB Gain//bool
        EEPROM.put(EEPROM_ADDR_AGC_GAIN, 5);//Gain//int 0-30
        EEPROM.put(EEPROM_ADDR_AEC_VALUE, 204);//Exposure//int 0-1200
        EEPROM.put(EEPROM_ADDR_AEC2, 1);//AEC DSP//bool
        EEPROM.put(EEPROM_ADDR_DCW, 1);//bool
        EEPROM.put(EEPROM_ADDR_BPC, 0);//bool
        EEPROM.put(EEPROM_ADDR_WPC, 1);//bool
        EEPROM.put(EEPROM_ADDR_RAW_gma, 1);//bool
        EEPROM.put(EEPROM_ADDR_LENC, 1);//bool
        EEPROM.put(EEPROM_ADDR_EFFECT, 0);//Special Effect//index 0-6
        EEPROM.put(EEPROM_ADDR_WB_MODE, 0);//WB Mode//index 0-4
        EEPROM.put(EEPROM_ADDR_AE_LEVEL, 0);//AE Level//int -2,2

        EEPROM.commit();
    }
}

