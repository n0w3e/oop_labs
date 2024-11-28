#ifndef NPC_H
#define NPC_H

#include <string>
#include <memory>

class BattleVisitor;

class NPC {
public:
    NPC(const std::string& name, double x, double y);
    virtual ~NPC() = default;

    virtual void accept(BattleVisitor& visitor) = 0;

    double getX() const;
    double getY() const;
    const std::string& getName() const;

protected:
    std::string name;
    double x, y;
};

class Elf : public NPC {
public:
    using NPC::NPC;
    void accept(BattleVisitor& visitor) override;
};

class Rogue : public NPC {
public:
    using NPC::NPC;
    void accept(BattleVisitor& visitor) override;
};

class Squirrel : public NPC {
public:
    using NPC::NPC;
    void accept(BattleVisitor& visitor) override;
};

#endif
