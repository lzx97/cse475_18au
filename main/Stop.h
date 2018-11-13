#ifndef _STOP_H_
#define _STOP_H_

#include "Creature.h"
#include "State.h"

class Stop : public State {
    public:
        Stop(Creature& creature) : State(creature, "Stop", 1) {}
        uint8_t getNumRepeats();
};

#endif
