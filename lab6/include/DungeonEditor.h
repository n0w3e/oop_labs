#ifndef DUNGEONEDITOR_H
#define DUNGEONEDITOR_H

#include <vector>
#include <memory>
#include <string>
#include "NPC.h"
#include "BattleVisitor.h"
#include "Observers.h"

class DungeonEditor {
public:
    void addNPC(const std::string& type, const std::string& name, double x, double y);
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
    void printNPCs() const;
    void startBattle(double range);

private:
    std::vector<std::shared_ptr<NPC>> npcs;
    std::vector<std::shared_ptr<Observer>> observers;
};

#endif
