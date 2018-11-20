#ifndef _STARTLE_H_
#define _STARTLE_H_

#include "Creature.h"
#include "State.h"

class Startle : public State {
    public:
        Startle(Creature& creature) : State(creature, "Startle", 6) {}
        uint8_t getNumRepeats();
        void loop(uint32_t dt);
        const uint8_t* getLocalWeights();
        float getStartleFactor();
    private:
        static constexpr uint8_t _localWeights[ACTIVE_STATES + AMBIENT_STATES] = { 0 };
};

#endif
        