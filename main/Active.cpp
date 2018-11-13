#include "Active.h"
#include "Debug.h"

constexpr uint8_t Active::_localWeights[];

uint8_t Active::getNumRepeats() {
    return 255;
}

uint8_t Active::getId() {
  return 0;
}

