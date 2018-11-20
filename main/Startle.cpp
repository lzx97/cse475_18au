#include "Startle.h"
#include "Debug.h"

constexpr uint8_t Startle::_localWeights[];

uint8_t Startle::getNumRepeats() {
    return 32;
}

void Startle::loop(uint32_t dt) {
    // do nothing
}

const uint8_t* Startle::getLocalWeights() {
    return this->_localWeights;
}

float Startle::getStartleFactor() {
    return 9999999999;
}
