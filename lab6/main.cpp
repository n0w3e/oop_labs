#include "DungeonEditor.h"
#include <iostream>

void showMenu() {
    std::cout << "1. Add NPC\n";
    std::cout << "2. Save to file\n";
    std::cout << "3. Load from file\n";
    std::cout << "4. Print NPCs\n";
    std::cout << "5. Start battle\n";
    std::cout << "6. Exit\n";
}

int main() {
    DungeonEditor editor;
    bool running = true;

    while (running) {
        showMenu();
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string type, name;
                double x, y;
                std::cout << "Enter NPC type (Elf, Rogue, Squirrel): ";
                std::cin >> type;
                std::cout << "Enter NPC name: ";
                std::cin >> name;
                std::cout << "Enter x and y coordinates: ";
                std::cin >> x >> y;
                editor.addNPC(type, name, x, y);
                break;
            }
            case 2: {
                std::string filename;
                std::cout << "Enter filename: ";
                std::cin >> filename;
                editor.saveToFile(filename);
                break;
            }
            case 3: {
                std::string filename;
                std::cout << "Enter filename: ";
                std::cin >> filename;
                editor.loadFromFile(filename);
                break;
            }
            case 4:
                editor.printNPCs();
                break;
            case 5: {
                double range;
                std::cout << "Enter battle range: ";
                std::cin >> range;
                editor.startBattle(range);
                break;
            }
            case 6:
                running = false;
                break;
            default:
                std::cout << "Invalid choice, try again.\n";
        }
    }

    return 0;
}
