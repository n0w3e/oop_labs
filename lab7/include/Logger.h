#ifndef LOGGER_H
#define LOGGER_H

#include <string>

class Logger {
public:
    static void logToFile(const std::string& message, const std::string& filename);
};

#endif