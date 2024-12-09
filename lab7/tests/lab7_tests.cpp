#include <gtest/gtest.h>
#include "../include/DungeonEditor.h"
#include "../include/NPCFactory.h"
#include "../include/BattleVisitor.h"
#include <memory>
#include <vector>
#include <thread>

TEST(DungeonEditorTest, AddNPCTest) {
    DungeonEditor editor;
    std::string type = "Elf";
    std::string name = "TestElf";
    double x = 10.0;
    double y = 20.0;

    editor.addNPC(type, name, x, y);
 
    const std::vector<std::shared_ptr<NPC>>& npcs = editor.getNPCs();
    ASSERT_EQ(npcs.size(), 1);
    ASSERT_EQ(npcs[0]->getName(), name);
    ASSERT_EQ(npcs[0]->getX(), x);
    ASSERT_EQ(npcs[0]->getY(), y);
}

TEST(DungeonEditorTest, SaveAndLoadFromFileTest) {
    DungeonEditor editor;
    std::string type = "Elf";
    std::string name = "TestElf";
    double x = 10.0;
    double y = 20.0;
    editor.addNPC(type, name, x, y);
    std::string filename = "test_save.txt";

    editor.saveToFile(filename);
    editor.loadFromFile(filename);
    
    const std::vector<std::shared_ptr<NPC>>& npcs = editor.getNPCs();
    ASSERT_EQ(npcs.size(), 1);
    ASSERT_EQ(npcs[0]->getName(), name);
    ASSERT_EQ(npcs[0]->getX(), x);
    ASSERT_EQ(npcs[0]->getY(), y);
}

TEST(DungeonEditorTest, StartBattleTest) {
    DungeonEditor editor;
    editor.addNPC("Elf", "Elf1", 10.0, 10.0);
    editor.addNPC("Rogue", "Rogue1", 15.0, 15.0);
    double range = 10.0;
    
    editor.startBattle(range);

    const std::vector<std::shared_ptr<NPC>>& npcs = editor.getNPCs();
    ASSERT_EQ(npcs.size(), 1);
    ASSERT_EQ(npcs[0]->getName(), "Elf1");
}

TEST(DungeonEditorTest, MoveNPCTest) {
    DungeonEditor editor;
    editor.addNPC("Elf", "Elf1", 10.0, 10.0);

    std::thread moveThread(&DungeonEditor::moveNPCs, &editor);
    std::this_thread::sleep_for(std::chrono::seconds(1));
    editor.setRunning(false);
    moveThread.join();
    
    const std::vector<std::shared_ptr<NPC>>& npcs = editor.getNPCs();
    ASSERT_EQ(npcs.size(), 1);
    ASSERT_NE(npcs[0]->getX(), 10.0);
    ASSERT_NE(npcs[0]->getY(), 10.0);
}


TEST(DungeonEditorTest, PrintNPCTest) {    
    DungeonEditor editor;
    editor.addNPC("Elf", "Elf1", 10.0, 10.0);

    testing::internal::CaptureStdout();
    editor.printNPCs();
    std::string output = testing::internal::GetCapturedStdout();

    ASSERT_NE(output.find("Elf1"), std::string::npos);
}

TEST(DungeonEditorTest, PrintMapTest) {
    DungeonEditor editor;
    editor.addNPC("Elf", "Elf1", 10.0, 10.0);
    
    testing::internal::CaptureStdout();
    editor.printMap();
    std::string output = testing::internal::GetCapturedStdout();
    
    ASSERT_NE(output.find("Elf1"), std::string::npos);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}