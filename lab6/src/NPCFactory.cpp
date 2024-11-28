#include "NPCFactory.h"
#include <stdexcept>

std::shared_ptr<NPC> NPCFactory::createNPC(const std::string& type, const std::string& name, double x, double y) {
    if (type == "Elf") {
        return std::make_shared<Elf>(name, x, y);
    } else if (type == "Rogue") {
        return std::make_shared<Rogue>(name, x, y);
    } else if (type == "Squirrel") {
        return std::make_shared<Squirrel>(name, x, y);
    } else {
        throw std::invalid_argument("Unknown NPC type: " + type);
    }
}
