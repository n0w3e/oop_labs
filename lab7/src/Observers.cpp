#include "Observers.h"
#include "Logger.h"
#include <iostream>

void ConsoleObserver::update(const std::string& message) {
    std::cout << message << std::endl;
}

FileObserver::FileObserver(const std::string& filename) : filename(filename) {}

void FileObserver::update(const std::string& message) {
    Logger::logToFile(message, filename);
}