#ifndef _PLAYSOUND_H_
#define _PLAYSOUND_H_

#include "Creature.h"
#include "State.h"

class PlaySound : public State {
    public:
        PlaySound(Creature& creature) : State(creature, "PlaySound", 3) {}
        uint8_t getNumRepeats();
};

#endif
