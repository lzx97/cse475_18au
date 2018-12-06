#include "Ambient2.h"
#include "Debug.h"
#include "Midi.h"
#include "Neopixel.h"

constexpr uint8_t Ambient2::_localWeights[];

uint8_t Ambient2::getNumRepeats() {
 return rand() % 5 + 4; // 4 - 8 repeats
}

void Ambient2::loop(uint32_t dt) {
  Midi::setSound(29);
  Neopixel::setLight(6);
}

const uint8_t* Ambient2::getLocalWeights() {
  return this->_localWeights;
}

float Ambient2::getStartleFactor() {
  return 0.001f;
}
