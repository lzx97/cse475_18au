#ifndef _START_H_
#define _START_H_

#include "Creature.h"
#include "State.h"

class Start : public State {
    public:
        Start(Creature& creature) : State(creature, "Start", 2) {}
        uint8_t getNumRepeats();
        void loop(uint32_t dt);
        const uint8_t* getLocalWeights();
        float getStartleFactor();
    private:
        static constexpr uint8_t _localWeights[ACTIVE_STATES + AMBIENT_STATES] = { 0 };
};

#endif
