#include "SendState.h"
#include "Debug.h"

constexpr uint8_t SendState::_localWeights[];

uint8_t SendState::getNumRepeats() {
    return 32;
}
