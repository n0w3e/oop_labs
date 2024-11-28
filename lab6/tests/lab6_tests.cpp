#include "gtest/gtest.h"
#include "DungeonEditor.h"

TEST(DungeonEditorTest, AddNPC) {
    DungeonEditor editor;
    editor.addNPC("Elf", "Legolas", 100.0, 100.0);
    editor.addNPC("Rogue", "Garrett", 200.0, 200.0);

    testing::internal::CaptureStdout();
    editor.printNPCs();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Legolas"), std::string::npos);
    EXPECT_NE(output.find("Garrett"), std::string::npos);
}

TEST(DungeonEditorTest, SaveAndLoad) {
    DungeonEditor editor;
    editor.addNPC("Elf", "Legolas", 100.0, 100.0);
    editor.addNPC("Rogue", "Garrett", 200.0, 200.0);

    editor.saveToFile("save_from_tests.txt");

    DungeonEditor loadedEditor;
    loadedEditor.loadFromFile("save_from_tests.txt");

    testing::internal::CaptureStdout();
    loadedEditor.printNPCs();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Legolas"), std::string::npos);
    EXPECT_NE(output.find("Garrett"), std::string::npos);
}

TEST(DungeonEditorTest, StartBattle) {
    DungeonEditor editor;
    editor.addNPC("Elf", "Legolas", 100.0, 100.0);
    editor.addNPC("Rogue", "Garrett", 102.0, 102.0);
    editor.addNPC("Squirrel", "Fluffy", 105.0, 105.0);

    editor.startBattle(10.0);

    testing::internal::CaptureStdout();
    editor.printNPCs();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output.find("Legolas"), std::string::npos);
    EXPECT_EQ(output.find("Garrett"), std::string::npos);
    EXPECT_EQ(output.find("Fluffy"), std::string::npos);
}