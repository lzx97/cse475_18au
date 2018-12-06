#include "Active3.h"
#include "Debug.h"
#include "Midi.h"
#include "Neopixel.h"

constexpr uint8_t Active3::_localWeights[];

uint8_t Active3::getNumRepeats() {
 return rand() % 4 + 1; // 1 - 4 repeats
}

void Active3::loop(uint32_t dt) {
  Midi::setSound(19);
  Neopixel::setLight(5);
}

const uint8_t* Active3::getLocalWeights() {
  return this->_localWeights;
}

float Active3::getStartleFactor() {
  return 0.001f;
}
