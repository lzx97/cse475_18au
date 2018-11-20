#include "SendState.h"
#include "Debug.h"

constexpr uint8_t SendState::_localWeights[];

uint8_t SendState::getNumRepeats() {
    return 32;
}

void SendState::loop(uint32_t dt) {
    // do nothing
}

const uint8_t* SendState::getLocalWeights() {
    return this->_localWeights;
}

float SendState::getStartleFactor() {
    return 9999999999;
}
