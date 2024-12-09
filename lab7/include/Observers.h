#ifndef OBSERVERS_H
#define OBSERVERS_H

#include <string>
#include <memory>

class Observer {
public:
    virtual ~Observer() = default;
    virtual void update(const std::string& message) = 0;
};

class ConsoleObserver : public Observer {
public:
    void update(const std::string& message) override;
};

class FileObserver : public Observer {
public:
    explicit FileObserver(const std::string& filename);
    void update(const std::string& message) override;

private:
    std::string filename;
};

#endif