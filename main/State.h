#ifndef _STATE_H_
#define _STATE_H_

#include <cinttypes>

#include "Creature.h"

class Creature;

#define ACTIVE_STATES 3
#define AMBIENT_STATES 3

class State {
 public:
  // TODO: call set_globals with defaults in impl.

  State(Creature& creature) : _creature(creature) {};
  virtual State(const State&) = delete;
  virtual State& operator=(State const&) = delete;
 protected:
  virtual void loop(uint32_t dt);
  virtual State* transition();

  // Packet receivers
  virtual void rx_set_globals(uint8_t* payload);
  virtual void rx_stop();
  virtual void rx_start(uint8_t mode);
  virtual void rx_play_sound(uint8_t sound_idx);
  virtual void rx_play_effect(uint8_t effect_idx);
  virtual void rx_broadcast_states(uint8_t* states);
  virtual void rx_startle(uint8_t strength, uint8_t id);

  // Packet transmitters
  virtual void tx_entered_state(uint8_t old_state, uint8_t state);
  virtual void tx_startle(uint8_t strength);

  // Event handlers
  // Called when PIR pin goes from LOW to HIGH.
  virtual void PIR();
  // Called when this creature is startled. Should set
  virtual void startled();
  // Called when a sound should be played
  virtual void playSound(uint8_t sound_idx, bool broadcast);
  // Called when an effect should be displayed
  virtual void playEffect(uint8_t effect_idx, bool broadcast);

  // Returns a valid state in case a creature broadcasts an invalid state value
  uint8_t get_creature_state(uint8_t creature) {
    uint8_t creature_state = _creature._creature_states[creature];
    if (creature_state == 0xFF || creature_state = 0x00) {
      return creature_state;
    } else if (creature_state % 2 == 0 && creature_state > ACTIVE_STATES * 2) {
      return 2;
    } else if (creature_state % 2 == 1 && creature_state > AMBIENT_STATES * 2 - 1) {
      return 1;
    } else {
      return creature_state;
    }
  }

 private:
  static uint8_t const* _localWeights;    // should be size ACTIVE_STATES + AMBIENT_STATES

  static uint8_t const* _globalWeights;   // should be size ACTIVE_STATES + AMBIENT_STATES

  static uint8_t  _startleDecay;          // How quickly this state's decay

  static float _startle_factor;           // Relative speed & threshold of startle for this class.
                                          // 1.0 = default. 2.0 -> 2x faster/more, 0.5 -> 2x slower/less

  static const uint8_t _state_id;         // Please name this accordingly, 1 and increasing odd for ambient,
                                          // 2 and increasing even for active. Dont repeat state numbers.

  uint8_t _repeat_state;
  const Creature& _creature;
};

class Wait : public State;

#endif  // _STATE_H_
