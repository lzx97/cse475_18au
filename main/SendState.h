#ifndef _SENDSTATE_H_
#define _SENDSTATE_H_

#include "Creature.h"
#include "State.h"

class SendState : public State {
    public:
        SendState(Creature& creature) : State(creature, "SendState", 7) {}
        uint8_t getNumRepeats();
        void loop(uint32_t dt);
        const uint8_t* getLocalWeights();
        float getStartleFactor();
    private:
        static constexpr uint8_t _localWeights[ACTIVE_STATES + AMBIENT_STATES] = { 0 };
};

#endif
