#ifndef _STOP_H_
#define _STOP_H_

#include "Creature.h"
#include "State.h"

class Stop : public State {
    public:
        Stop(Creature& creature) : State(creature, "Stop", 1) {}
        uint8_t getNumRepeats();
        void loop(uint32_t dt);
        const uint8_t* getLocalWeights();
        float getStartleFactor();
    private:
        static constexpr uint8_t _localWeights[ACTIVE_STATES + AMBIENT_STATES] = { 0 };
};

#endif
