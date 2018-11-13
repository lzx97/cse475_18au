#ifndef _SENDSTATE_H_
#define _SENDSTATE_H_

#include "Creature.h"
#include "State.h"

class SendState : public State {
    public:
        SendState(Creature& creature) : State(creature, "SendState", 7) {}
        uint8_t getNumRepeats();
};

#endif
