#include "Active2.h"
#include "Debug.h"
#include "Midi.h"
#include "Neopixel.h"

constexpr uint8_t Active2::_localWeights[];

uint8_t Active2::getNumRepeats() {
 return rand() % 4 + 1; // 1 - 4 repeats
}

void Active2::loop(uint32_t dt) {
  Midi::setSound(21);
  Neopixel::setLight(4);
}

const uint8_t* Active2::getLocalWeights() {
  return this->_localWeights;
}

float Active2::getStartleFactor() {
  return 0.001f;
}
