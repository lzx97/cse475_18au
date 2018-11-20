#include "Start.h"
#include "Debug.h"

constexpr uint8_t Start::_localWeights[];

uint8_t Start::getNumRepeats() {
    return 32;
}

void Start::loop(uint32_t dt) {
    // do nothing
}

const uint8_t* Start::getLocalWeights() {
    return this->_localWeights;
}

float Start::getStartleFactor() {
    return 9999999999;
}


