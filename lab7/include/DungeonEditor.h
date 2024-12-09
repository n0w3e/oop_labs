#ifndef DUNGEONEDITOR_H
#define DUNGEONEDITOR_H

#include <vector>
#include <memory>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>
#include "NPC.h"
#include "BattleVisitor.h"
#include "Observers.h"

class DungeonEditor {
public:
    DungeonEditor();
    void addNPC(const std::string& type, const std::string& name, double x, double y);
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
    void printNPCs() const;
    void startBattle(double range);
    void moveNPCs();
    void battleNPCs();
    void printMap();
    void run();

    const std::vector<std::shared_ptr<NPC>>& getNPCs() const { return npcs; }
    void setRunning(bool value) { running = value; }

private:
    std::vector<std::shared_ptr<NPC>> npcs;
    std::vector<std::shared_ptr<Observer>> observers;
    mutable std::mutex npcsMutex;
    std::condition_variable cv;
    bool running;
};

#endif