#ifndef _START_H_
#define _START_H_

#include "Creature.h"
#include "State.h"

class Start : public State {
    public:
        Start(Creature& creature) : State(creature, "Start", 2) {}
        uint8_t getNumRepeats();
};

#endif
