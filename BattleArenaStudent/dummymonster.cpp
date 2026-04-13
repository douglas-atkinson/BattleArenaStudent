#include "monster.h"
#include "dummymonster.h"
#include "position.h"
#include "worldstate.h"
#include "random.h"

DummyMonster::DummyMonster(const std::string& name, int hitPoints, int strength, int accuracy, int agility, 
    int defense, const Position& position, const std::array<std::string, 6>& portrait)
    : Monster(name, hitPoints, strength, accuracy, agility, defense, position, portrait) {}

AttackResult DummyMonster::attack(Combatant& target) {
    AttackResult result;
    return result;
}

bool DummyMonster::move(const WorldState& world) {
    return false;
}
