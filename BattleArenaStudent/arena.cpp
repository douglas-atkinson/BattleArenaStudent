#include <vector>
#include <memory>
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <set>
#include <utility>
#include "arena.h"
#include "hero.h"
#include "monster.h"

Arena::Arena(Hero hero, std::vector<std::unique_ptr<Monster>> monsters, int rows, int cols)
    : hero(std::move(hero)), monsters(std::move(monsters)), rows(rows), cols(cols) {
    validateStartState();
    assignSymbols();
}

void Arena::runBattle() {
    
}

WorldState Arena::buildWorldStateForHero() const {
    return {};
}

WorldState Arena::buildWorldStateForMonster(const Monster* activeMonster) const {
    return {};
}

bool Arena::isBattleOver() const {
    return false;
}

bool Arena::heroWon() const {
    return false;
}

void Arena::processHeroTurn() {
    
}

void Arena::processMonsterTurn(Monster& monster) {
    
}

Monster* Arena::findAdjacentMonsterToHero() {
    return nullptr;
}

bool Arena::areOrthogonallyAdjacent(const Combatant& a, const Combatant& b) const {
    return 0;
}

void Arena::removeDeadMonsters() {

}

void Arena::printBattleState() const {
    std::cout << "\n========================================\n";
    std::cout << "Current Battle State\n";
    std::cout << "========================================\n";

    std::cout << "Hero: " << hero.getName() << '\n';
    std::cout << "Position: (" << hero.getPosition().row
        << ", " << hero.getPosition().col << ")\n";
    std::cout << "HP: " << hero.getHitPoints()
        << " / " << hero.getMaxHitPoints() << '\n';
    std::cout << "Level: " << hero.getLevel() << '\n';
    std::cout << "Victories: " << hero.getVictories() << '\n';
    std::cout << "Status: " << (hero.isAlive() ? "Alive" : "Dead") << "\n\n";

    std::cout << "Monsters:\n";

    if (monsters.empty()) {
        std::cout << "None\n";
    }
    else {
        for (size_t i = 0; i < monsters.size(); ++i) {
            const Monster& monster = *monsters[i];

            std::cout << i + 1 << ". " << monster.getName() << '\n';
            std::cout << "   Position: (" << monster.getPosition().row
                << ", " << monster.getPosition().col << ")\n";
            std::cout << "   HP: " << monster.getHitPoints()
                << " / " << monster.getMaxHitPoints() << '\n';
            std::cout << "   Status: "
                << (monster.isAlive() ? "Alive" : "Dead") << "\n\n";
        }
    }
}

void Arena::assignSymbols() {
    std::vector<char> pool = {
        '@', 'A', 'B', 'C', 'D', 'E', 'F',
        'G', 'H', 'I', 'J', 'K', 'L'
    };

    int index = 0;

    hero.setSymbol(pool[index++]);

    for (auto& monster : monsters) {
        if (index < pool.size()) {
            monster->setSymbol(pool[index++]);
        }
        else {
            monster->setSymbol('?'); // fallback
        }
    }
}

void Arena::validateStartState() const {
    validateArenaDimensions();
    validateHeroPosition();
    validateNoNullMonsters();
    validateMonsterPositions();
    validateNoOverlappingCombatants();
}

void Arena::validateArenaDimensions() const {
    if (rows <= 0 || cols <= 0) {
        throw std::invalid_argument("Arena dimensions must be greater than 0.");
    }
}

void Arena::validateHeroPosition() const {
    const Position pos = hero.getPosition();
    if (!inBounds(pos.row, pos.col)) {
        throw std::invalid_argument("Hero's position must be within Arena boundaries");
    }
}

void Arena::validateNoNullMonsters() const {
    for (const auto& monster : monsters) {
        if (monster == nullptr) {
            throw std::invalid_argument("Pointer to Monster cannot be null");
        }
    }
}

void Arena::validateMonsterPositions() const {
    for (const auto& monster : monsters) {
        const Position pos = monster->getPosition();
        if (!inBounds(pos.row, pos.col)) {
            throw std::invalid_argument("Monster's position must be within Arena boundaries");
        }
    }

}

void Arena::validateNoOverlappingCombatants() const {
    std::set<std::pair<int, int>> occupied;

    const Position heroPos = hero.getPosition();
    occupied.insert({ heroPos.row, heroPos.col });

    for (const auto& monster : monsters) {
        const Position pos = monster->getPosition();

        if (!occupied.insert({ pos.row, pos.col }).second) {
            throw std::invalid_argument("Two combatants cannot occupy the same starting position.");
        }
    }
}

bool Arena::inBounds(int row, int col) const {
    return (row >= 0 && row < rows && col >= 0 && col < cols);
}
