#include "../include/DungeonEditor.h"
#include "../include/NPCFactory.h"
#include "../include/Logger.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <typeinfo>
#include <random>
#include <chrono>
#include <thread>

DungeonEditor::DungeonEditor() : running(true) {}

void DungeonEditor::addNPC(const std::string& type, const std::string& name, double x, double y) {
    std::lock_guard<std::mutex> lock(npcsMutex);
    npcs.push_back(NPCFactory::createNPC(type, name, x, y));
}

void DungeonEditor::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file for saving: " + filename);
    }

    std::lock_guard<std::mutex> lock(npcsMutex);
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

    std::lock_guard<std::mutex> lock(npcsMutex);
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
    std::lock_guard<std::mutex> lock(npcsMutex);
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
    std::lock_guard<std::mutex> lock(npcsMutex);
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

void DungeonEditor::moveNPCs() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-1.0, 1.0);

    while (running) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::lock_guard<std::mutex> lock(npcsMutex);
        for (auto& npc : npcs) {
            double dx = dis(gen);
            double dy = dis(gen);
            npc->setPosition(npc->getX() + dx, npc->getY() + dy);
        }
        cv.notify_all();
    }
}

void DungeonEditor::battleNPCs() {
    while (running) {
        std::unique_lock<std::mutex> lock(npcsMutex);
        cv.wait(lock);
        startBattle(10.0);
    }
}

void DungeonEditor::printMap() {
    std::lock_guard<std::mutex> lock(npcsMutex);
    std::cout << "Map:\n";
    for (const auto& npc : npcs) {
        std::cout << npc->getName() << " at (" << npc->getX() << ", " << npc->getY() << ")\n";
    }
}

void DungeonEditor::run() {
    std::thread moveThread(&DungeonEditor::moveNPCs, this);
    std::thread battleThread(&DungeonEditor::battleNPCs, this);
    std::thread printThread(&DungeonEditor::printMap, this);

    std::this_thread::sleep_for(std::chrono::seconds(30));
    running = false;

    moveThread.join();
    battleThread.join();
    printThread.join();

    std::lock_guard<std::mutex> lock(npcsMutex);
    std::cout << "Survivors:\n";
    printNPCs();
}