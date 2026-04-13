#include "combatant.h"
#include "hero.h"
#include "attackresult.h"
#include "herotitle.h"
#include "position.h"
#include "movementresult.h"
#include <cctype>

Hero::Hero(const std::string& name, HeroTitle title, int hitPoints, int strength, int accuracy, 
           int agility, int defense, const Position& position, 
           const std::array<std::string, 6>& portrait)
    : Combatant(name, hitPoints, strength, accuracy, agility, defense, position, portrait),
    title(title), level(1), victories(0) {}

MovementResult Hero::moveByPlayerCommand(char command, const WorldState& world) {
    
    return MovementResult::Blocked;
}

AttackResult Hero::attack(Combatant& target) {
    
}

std::string Hero::speak() const {
    return "";
}

HeroTitle Hero::getTitle() const {
    return HeroTitle::Knight;
}

std::string Hero::getTitleString() const {
    return "";
}

int Hero::getLevel() const {
    return 0;
}

int Hero::getVictories() const {
    return 0;
}

void Hero::recordVictory() {
    
}
