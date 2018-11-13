#ifndef _PLAYEFFECT_H_
#define _PLAYEFFECT_H_

#include "Creature.h"
#include "State.h"

class PlayEffect : public State {
    public:
        PlayEffect(Creature& creature) : State(creature, "PlayEffect", 4) {}
        uint8_t getNumRepeats();
};

#endif
