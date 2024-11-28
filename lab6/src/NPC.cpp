#include "NPC.h"
#include "BattleVisitor.h"

NPC::NPC(const std::string& name, double x, double y) : name(name), x(x), y(y) {}

double NPC::getX() const {
    return x;
}

double NPC::getY() const {
    return y;
}

const std::string& NPC::getName() const {
    return name;
}

void Elf::accept(BattleVisitor& visitor) {
    visitor.visit(std::make_shared<Elf>(*this), nullptr);
}

void Rogue::accept(BattleVisitor& visitor) {
    visitor.visit(std::make_shared<Rogue>(*this), nullptr);
}

void Squirrel::accept(BattleVisitor& visitor) {
    visitor.visit(std::make_shared<Squirrel>(*this), nullptr);
}

