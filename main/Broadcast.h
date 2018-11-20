#ifndef _BROADCAST_H_
#define _BROADCAST_H_

#include "Creature.h"
#include "State.h"

class Broadcast : public State {
    public:
        Broadcast(Creature& creature) : State(creature, "Broadcast", 5) {}
        uint8_t getNumRepeats();
        void loop(uint32_t dt);
        const uint8_t* getLocalWeights();
        float getStartleFactor();
    private:
        static constexpr uint8_t _localWeights[ACTIVE_STATES + AMBIENT_STATES] = { 0 };
};

#endif
