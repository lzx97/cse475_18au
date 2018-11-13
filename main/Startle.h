#ifndef _STARTLE_H_
#define _STARTLE_H_

#include "Creature.h"
#include "State.h"

class Startle : public State {
    public:
        Startle(Creature& creature) : State(creature, "Startle") {}
        uint8_t getNumRepeats();
        uint8_t getId();
};

#endif
        