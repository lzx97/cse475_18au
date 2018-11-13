#include "PlaySound.h"
#include "Debug.h"

constexpr uint8_t PlaySound::_localWeights[];

uint8_t PlaySound::getNumRepeats() {
    return 32;
}