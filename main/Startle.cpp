#include "Startle.h"
#include "Debug.h"

constexpr uint8_t Startle::_localWeights[];

uint8_t Startle::getNumRepeats() {
    return 255;
}

uint8_t Startle::getId() {
  return 0;
}

