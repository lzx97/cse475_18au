#ifndef _PLAYSOUND_H_
#define _PLAYSOUND_H_

#include "Creature.h"
#include "State.h"

class PlaySound : public State {
    public:
        PlaySound(Creature& creature) : State(creature, "PlaySound", 3) {}
        uint8_t getNumRepeats();
        void loop(uint32_t dt);
        const uint8_t* getLocalWeights();
        float getStartleFactor();
    private:
        static constexpr uint8_t _localWeights[ACTIVE_STATES + AMBIENT_STATES] = { 0 };
};

#endif
