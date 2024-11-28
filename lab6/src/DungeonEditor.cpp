#include "DungeonEditor.h"
#include "NPCFactory.h"
#include "Logger.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <typeinfo>

void DungeonEditor::addNPC(const std::string& type, const std::string& name, double x, double y) {
    npcs.push_back(NPCFactory::createNPC(type, name, x, y));
}

void DungeonEditor::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file for saving: " + filename);
    }

    for (const auto& npc : npcs) {
        std::string type;
        if (dynamic_cast<Elf*>(npc.get())) {
            type = "Elf";
        } else if (dynamic_cast<Rogue*>(npc.get())) {
            type = "Rogue";
        } else if (dynamic_cast<Squirrel*>(npc.get())) {
            type = "Squirrel";
        } else {
            throw std::runtime_error("Unknown NPC type encountered during save.");
        }
        file << type << " " << npc->getName() << " " << npc->getX() << " " << npc->getY() << "\n";
    }
}

void DungeonEditor::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file for loading: " + filename);
    }

    npcs.clear();

    std::string type, name;
    double x, y;
    while (file >> type >> name >> x >> y) {
        try {
            npcs.push_back(NPCFactory::createNPC(type, name, x, y));
        } catch (const std::invalid_argument& e) {
        }
    }
}

void DungeonEditor::printNPCs() const {
    for (const auto& npc : npcs) {
        std::string type;
        if (dynamic_cast<Elf*>(npc.get())) {
            type = "Elf";
        } else if (dynamic_cast<Rogue*>(npc.get())) {
            type = "Rogue";
        } else if (dynamic_cast<Squirrel*>(npc.get())) {
            type = "Squirrel";
        } else {
            type = "Unknown";
        }

        std::cout << npc->getName() << " (" << type << ") at (" << npc->getX() << ", " << npc->getY() << ")\n";
    }
}

void DungeonEditor::startBattle(double range) {
    BattleVisitor visitor(range);
    for (const auto& npc1 : npcs) {
        for (const auto& npc2 : npcs) {
            if (npc1 != npc2) {
                visitor.visit(npc1, npc2);
            }
        }
    }

    auto killedNPCs = visitor.getKilledNPCs();
    npcs.erase(
        std::remove_if(npcs.begin(), npcs.end(),
                       [&killedNPCs](const std::shared_ptr<NPC>& npc) {
                           return std::find(killedNPCs.begin(), killedNPCs.end(), npc) != killedNPCs.end();
                       }),
        npcs.end());
}
