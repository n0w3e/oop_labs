#include "../include/BattleVisitor.h"
#include <cmath>
#include <iostream>
#include <typeinfo>

BattleVisitor::BattleVisitor(double range) : range(range) {}

void BattleVisitor::visit(std::shared_ptr<NPC> attacker, std::shared_ptr<NPC> target) {
    if (!attacker || !target) return;

    double distance = std::sqrt(std::pow(attacker->getX() - target->getX(), 2) +
                                std::pow(attacker->getY() - target->getY(), 2));
    if (distance > range) return;

    if (typeid(*attacker) == typeid(Elf) && typeid(*target) == typeid(Rogue)) {
        std::cout << attacker->getName() << " (Elf) убивает " << target->getName() << " (Rogue)\n";
        killedNPCs.push_back(target);
    } else if (typeid(*attacker) == typeid(Rogue) && typeid(*target) == typeid(Squirrel)) {
        std::cout << attacker->getName() << " (Rogue) убивает " << target->getName() << " (Squirrel)\n";
        killedNPCs.push_back(target);
    } else if (typeid(*attacker) == typeid(Squirrel) && typeid(*target) == typeid(Elf)) {
        std::cout << attacker->getName() << " (Squirrel) убивает " << target->getName() << " (Elf)\n";
        killedNPCs.push_back(target);
    }
}

const std::vector<std::shared_ptr<NPC>>& BattleVisitor::getKilledNPCs() const {
    return killedNPCs;
}