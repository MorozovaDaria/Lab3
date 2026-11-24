#pragma once
#include <string>
#include <iostream>

class LoggingProxy {
public:
    static void log(const std::string& source, const std::string& message) {
        std::cout << "[" << source << "] " << message << std::endl;
    }
};