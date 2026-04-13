#include <algorithm>
#include <cmath>
#include "combatant.h"
#include "random.h"
#include "worldstate.h"

Combatant::Combatant(const std::string& name, int hitPoints, int strength, int accuracy, 
                    int agility, int defense, const Position& position, 
                    const std::array<std::string, 6>& portrait)
    : name(name), hitPoints(std::max(1, hitPoints)), maxHitPoints(std::max(1, hitPoints)), 
      strength(std::max(1, strength)), accuracy(std::max(1, accuracy)), agility(std::max(1, agility)),
      defense(std::max(1, defense)), position(position),
      portrait(portrait) { }


bool Combatant::isAlive() const {
    return false;
}

void Combatant::takeDamage(int amount) {
    
}

int Combatant::calculateHitChance(const Combatant& target) const {
    return 0;
}

bool Combatant::attackHits(const Combatant& target) const {
    return false;
}

int Combatant::calculateDamage(const Combatant& target) const {
    return 0;
}

bool Combatant::tryMoveTo(const Position& desiredPosition, const WorldState& world) {
    return false;
}

const std::string& Combatant::getName() const {
    return "";
}

int Combatant::getHitPoints() const {
    return 0;
}

int Combatant::getMaxHitPoints() const {
    return 0;
}

int Combatant::getStrength() const {
    return 0;
}

int Combatant::getAccuracy() const {
    return 0;
}

int Combatant::getAgility() const {
    return 0;
}

int Combatant::getDefense() const {
    return 0;
}

char Combatant::getSymbol() const {
    return 0;
}

const Position& Combatant::getPosition() const {
    return {};
}

void Combatant::setPosition(const Position& newPosition) {
    
}

void Combatant::setSymbol(const char symbol) {
    
}

const std::array<std::string, 6>& Combatant::getPortrait() const {
    return {};
}

AttackResult Combatant::performBasicAttack(Combatant& target) {
    AttackResult result;

    return result;
}

bool Combatant::isOrthogonallyAdjacent(const Combatant& other) const {
    return false;
}