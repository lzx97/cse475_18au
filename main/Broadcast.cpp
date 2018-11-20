#include "Broadcast.h"
#include "Debug.h"

constexpr uint8_t Broadcast::_localWeights[];

uint8_t Broadcast::getNumRepeats() {
    return 32;
}

void Broadcast::loop(uint32_t dt) {
    // do nothing
}

const uint8_t* Broadcast::getLocalWeights() {
    return this->_localWeights;
}

float Broadcast::getStartleFactor() {
    return 9999999999;
}
