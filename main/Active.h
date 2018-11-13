#ifndef _ACTIVE_H_
#define _ACTIVE_H_

#include "Creature.h"
#include "State.h"

class Active : public State {
    public:
        Active(Creature& creature, char* const name) : State(creature, name) {}
        uint8_t getNumRepeats();
        uint8_t getId();

};

#endif
