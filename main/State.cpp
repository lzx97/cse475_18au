#include "Creature.h"
#include "State.h"

#include <cmath>

State::State(Creature& creature, char* const name, const uint8_t id) : _creature(creature), _id(id) {
  strncpy(_name, name, MAX_NAME_LEN);
  _name[MAX_NAME_LEN] = 0;
};

uint8_t State::getId() {
  return _id;
}

char* State::getName() {
  return _name;
}

void State::playSound(uint8_t sound_idx) {
  // TODO: implement
}

void State::playEffect(uint8_t effect_idx) {
  // TODO: implement
}

bool State::rxPlaySound(uint8_t len, uint8_t* payload) {
  // TODO: implement
}

bool State::rxPlayEffect(uint8_t len, uint8_t* payload) {
  // TODO: implement
}

bool State::rxStartle(int8_t rssi, uint8_t len, uint8_t* payload) {
  float x = (GLOBALS.STARTLE_DECAY - rssi)/GLOBALS.STARTLE_DECAY;
  float sigma = 1/(1 + exp(-x));
  float decay = sigma * getStartleFactor();
  
  uint8_t strength = payload[0];
  strength = strength * decay;

  if (strength > GLOBALS.STARTLE_THRESHOLD) {
    Serial.println(F("Startled"));
  }
  else {
    Serial.println(F("Not Startled"));
  }
  return true;
}

void State::txStartle(uint8_t strength, uint8_t id) {
  Creature::tx(PID_STARTLE, BROADCAST_ADDR, 2, {strength, id});
}

State* State::transition() {
  // TODO: implement
  return Creature::createState(PID_BROADCAST_STATES);
}

void State::PIR() {
  // TODO: implement
}

void State::startled(uint8_t strength, uint8_t id) {
  // TODO: implement
}

int8_t* State::getGlobalWeights() {
  return _globalWeights;
}
