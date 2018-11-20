#include "PlaySound.h"
#include "Debug.h"

constexpr uint8_t PlaySound::_localWeights[];

uint8_t PlaySound::getNumRepeats() {
    return 32;
}

void PlaySound::loop(uint32_t dt) {
    // do nothing
}

const uint8_t* PlaySound::getLocalWeights() {
    return this->_localWeights;
}

float PlaySound::getStartleFactor() {
    return 9999999999;
}
