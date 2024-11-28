#include "Logger.h"
#include <fstream>

void Logger::logToFile(const std::string& message, const std::string& filename) {
    std::ofstream file(filename, std::ios::app);
    if (file.is_open()) {
        file << message << std::endl;
    }
}
