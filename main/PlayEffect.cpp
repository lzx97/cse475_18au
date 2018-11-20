#include "PlayEffect.h"
#include "Debug.h"

constexpr uint8_t PlayEffect::_localWeights[];

uint8_t PlayEffect::getNumRepeats() {
    return 32;
}

void PlayEffect::loop(uint32_t dt) {
    // do nothing
}

const uint8_t* PlayEffect::getLocalWeights() {
    return this->_localWeights;
}

float PlayEffect::getStartleFactor() {
    return 9999999999;
}
