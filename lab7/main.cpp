#include "include/DungeonEditor.h"
#include <iostream>
#include <random>

int main() {
    DungeonEditor editor;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 100.0);

    // Создаем 50 NPC в случайных локациях
    for (int i = 0; i < 50; ++i) {
        std::string type = (i % 3 == 0) ? "Elf" : (i % 3 == 1) ? "Rogue" : "Squirrel";
        editor.addNPC(type, "NPC" + std::to_string(i), dis(gen), dis(gen));
    }

    // Запускаем основной цикл игры
    editor.run();

    return 0;
}