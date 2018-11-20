#include "Stop.h"
#include "Debug.h"

constexpr uint8_t Stop::_localWeights[];

uint8_t Stop::getNumRepeats() {
    return 32;
}


void Stop::loop(uint32_t dt) {
    // do nothing
}

const uint8_t* Stop::getLocalWeights() {
    return this->_localWeights;
}

float Stop::getStartleFactor() {
    return 9999999999;
}