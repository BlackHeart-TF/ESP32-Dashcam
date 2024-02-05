// ErrorLights.cpp

#include "error_lights.h"

ErrorLights::ErrorLights(uint8_t pin) : _pin(pin), _component((ErrorComponent)0), _flashes(0), _lastFlashTime(0), _isOn(false), _flashCount(0),_inPause(false)
#ifdef LED_IS_NEOPIXEL
, _strip(1, pin, NEO_GRB + NEO_KHZ800),_color(0)
#endif
{
}

void ErrorLights::begin() {
  Serial.println("Starting Light Control loop");
#ifdef LED_IS_NEOPIXEL
    Serial.println("LED is NeoPixel");
    _strip.begin();
    _strip.show(); // Initialize all pixels to 'off'
#else
    pinMode(_pin, OUTPUT);
#endif
}
#ifdef LED_IS_NEOPIXEL
uint32_t ErrorLights::getColorForComponent(ErrorComponent component) {
    switch(component) {
        case ErrorComponent::SD: return 0x000099; // Blue
        case ErrorComponent::Camera: return 0xFF0000; // Red
        case ErrorComponent::WiFi: return 0x00FF00; // Green
        // ... Add more cases as needed
        default: return 0; // No color
    }
}
#endif
void ErrorLights::setStatus(ErrorComponent component, uint8_t flashes) {
  Serial.print("Setting status to: ");Serial.print((int)component);Serial.print(" Flashes: ");Serial.println(flashes);
#ifdef LED_IS_NEOPIXEL
    _color = ErrorLights::getColorForComponent(component);
#endif
    _component = component;
    _flashes = flashes;
    _flashCount = 0;
    _lastFlashTime = millis();
}



void ErrorLights::update() {
    unsigned long currentTime = millis();

    // If in the flashing phase
    if (!_inPause && _flashes > 0 && currentTime - _lastFlashTime >= 500) {
        _lastFlashTime = currentTime;
        _isOn = !_isOn;

        // After completing the number of flashes, enter pause mode
        if (_flashCount >= _flashes) {
            _inPause = true;
            _flashCount = 0;
            _lastFlashTime = currentTime;
            _isOn = false;
        }

        if (_isOn) {
            _flashCount++;
#ifdef LED_IS_NEOPIXEL
            _strip.setPixelColor(0, _color);
            _strip.show();
#else
            analogWrite(_pin, 255); // Turn on basic LED
#endif
        } else {
#ifdef LED_IS_NEOPIXEL
            _strip.setPixelColor(0, 0);
            _strip.show();
#else
            analogWrite(_pin, 0); // Turn off basic LED
#endif
        }

        
  
    }

    // If in the pause phase
    if (_inPause && currentTime - _lastFlashTime >= 2000) { // Longer pause for 2 seconds
        _inPause = false;
        _lastFlashTime = currentTime;
    }
}


#ifndef LED_IS_NEOPIXEL
void ErrorLights::analogWrite(uint8_t pin, uint8_t val) {
    // Implement PWM functionality if needed
}
#endif
