// ErrorLights.h

#ifndef ERRORLIGHTS_H
#define ERRORLIGHTS_H

#include <Arduino.h>
#include "config.h"
#ifdef LED_IS_NEOPIXEL
#include <Adafruit_NeoPixel.h>
#endif

enum class ErrorComponent {
    None,
    SD,      // Associated with 2 flashes or Blue color
    Camera,  // Associated with 3 flashes or Red color
    WiFi     // Associated with 4 flashes or Green color
    // ... Add more components as needed
};

class ErrorLights {
public:
    ErrorLights(uint8_t pin);
    void begin();
    void setStatus(ErrorComponent color, uint8_t flashes);
    void update();

private:
    uint8_t _pin;
    ErrorComponent _component;
    uint8_t _flashes;
    unsigned long _lastFlashTime;
    bool _isOn;
    uint8_t _flashCount;
    bool _inPause;

#ifdef LED_IS_NEOPIXEL
    uint32_t _color;
    Adafruit_NeoPixel _strip;
    uint32_t getColorForComponent(ErrorComponent component);
#else
    void analogWrite(uint8_t pin, uint8_t val);
#endif
};

#endif
