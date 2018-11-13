#ifndef _AMBIENT_H_
#define _AMBIENT_H_

#include "Creature.h"
#include "State.h"

class Ambient : public State {
    public:
        Ambient(Creature& creature, char* const name) : State(creature, name) {}
        uint8_t getNumRepeats();
        uint8_t getId();
};

#endif

