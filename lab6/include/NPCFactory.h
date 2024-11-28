#ifndef NPCFACTORY_H
#define NPCFACTORY_H

#include <memory>
#include <string>
#include "NPC.h"

class NPCFactory {
public:
    static std::shared_ptr<NPC> createNPC(const std::string& type, const std::string& name, double x, double y);
};

#endif
