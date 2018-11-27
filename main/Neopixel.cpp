#include "Neopixel.h"
#include "Debug.h"

// Initialize fixed list of light gestures.
constexpr void (*Neopixel::LIGHTS[])(uint32_t);

uint8_t Neopixel::_currentIdx = 0;
uint32_t Neopixel::_lastLoop = 0;
Adafruit_NeoPixel_ZeroDMA Neopixel::_strip = Adafruit_NeoPixel_ZeroDMA(NEOPIXEL_COUNT, NEOPIXEL_PIN, NEO_GRBW);

void Neopixel::setup() {
  _strip.begin();
  _strip.setBrightness(5);
  _strip.show();
}

void Neopixel::loop() {
  uint32_t thisLoop = millis();
  uint32_t dt;
  if (_lastLoop) {
    dt = thisLoop - _lastLoop;
  } else {
    dt = 0;
  }
  _lastLoop = thisLoop;
  Serial.print("Current dt: ");
  Serial.println(dt);
  if (LIGHTS[_currentIdx] != nullptr) {
    LIGHTS[_currentIdx](dt);
  }
}

void Neopixel::setLight(uint8_t lightIdx) {
  // lightIdx soundIdx. Anything outside of the bounds of the array is 0.
  if (lightIdx >= sizeof(LIGHTS) / sizeof(void*)) {
    lightIdx = 0;
  }

  if (_currentIdx != lightIdx) {
    dprint(F("Next light: "));
    dprintln(lightIdx);

    _strip.clear();
    _strip.show();

    _currentIdx = lightIdx;
    _lastLoop = 0;
  }
}

uint8_t Neopixel::getLight() {
  return _currentIdx;
}

void Neopixel::rainbow(uint32_t dt) {
  static uint8_t offset = 0;
  static uint32_t rainbowColors[NEOPIXEL_COUNT] = {16711680, 13578240, 10444800, 7311360, 4177920, 1044480, 56865, 44625,
                                                   32385, 20145, 7905, 1179885, 4325565, 7471245, 10616925, 13762605};

  if (dt > 50) {
    for (uint8_t pix = 0; pix < NEOPIXEL_COUNT; pix++) {
      _strip.setPixelColor((pix + offset) % NEOPIXEL_COUNT, rainbowColors[pix]);
    }
    _strip.show();
    offset++;
  }
}


void Neopixel::RunningLights(uint32_t dt) {
  static uint8_t offset = 0;

  uint8_t red = 0xff;
  uint8_t green = 0xff;
  uint8_t blue = 0x00;

  for (int j = 0; j < _strip.numPixels() * 2; j++)
  {
    offset++;
    for (int i = 0; i < _strip.numPixels(); i++) {
      _strip.setPixelColor(i, ((sin(i + offset) * 127 + 128) / 255)*red,
                          ((sin(i + offset) * 127 + 128) / 255)*green,
                          ((sin(i + offset) * 127 + 128) / 255)*blue);
    }

    _strip.show();
    delay(150);
  }
    
}


void Neopixel::Strobe(uint32_t dt) {

  uint8_t red = 0x00;
  uint8_t green = 0xff;
  uint8_t blue = 0xff;

  uint8_t strobeCount = 10;
  for (int j = 0; j < strobeCount; j++) {
    setAll(red, green, blue);
    _strip.show();
    delay(50);
    setAll(0, 0, 0);
    _strip.show();
    delay(50);
  }

  delay(500);
}

void Neopixel::setAll(uint8_t red, uint8_t green, uint8_t blue) {
  for (int i = 0; i < _strip.numPixels(); i++ ) {
    _strip.setPixelColor(i, _strip.Color(red, green, blue));
  }
  _strip.show();
}

