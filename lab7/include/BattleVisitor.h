#ifndef BATTLEVISITOR_H
#define BATTLEVISITOR_H

#include <memory>
#include <vector>
#include "NPC.h"

class BattleVisitor {
public:
    explicit BattleVisitor(double range);
    void visit(std::shared_ptr<NPC> attacker, std::shared_ptr<NPC> target);
    const std::vector<std::shared_ptr<NPC>>& getKilledNPCs() const;

private:
    double range;
    std::vector<std::shared_ptr<NPC>> killedNPCs;
};

#endif