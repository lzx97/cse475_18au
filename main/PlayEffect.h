#ifndef _PLAYEFFECT_H_
#define _PLAYEFFECT_H_

#include "Creature.h"
#include "State.h"

class PlayEffect : public State {
    public:
        PlayEffect(Creature& creature) : State(creature, "PlayEffect", 4) {}
        uint8_t getNumRepeats();
        void loop(uint32_t dt);
        const uint8_t* getLocalWeights();
        float getStartleFactor();
    private:
        static constexpr uint8_t _localWeights[ACTIVE_STATES + AMBIENT_STATES] = { 0 };
};

#endif
