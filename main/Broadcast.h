#ifndef _BROADCAST_H_
#define _BROADCAST_H_

#include "Creature.h"
#include "State.h"

class Broadcast : public State {
    public:
        Broadcast(Creature& creature) : State(creature, "Broadcast", 5) {}
        uint8_t getNumRepeats();
};

#endif
