#include "Broadcast.h"
#include "Debug.h"

constexpr uint8_t Broadcast::_localWeights[];

uint8_t Broadcast::getNumRepeats() {
    return 32;
}
