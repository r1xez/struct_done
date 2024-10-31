#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <Windows.h>
#include <string>

enum Colors {
    GREEN = 10,
    BLUE = 11,
    RED = 12,
    YELLOW = 14
};

class Logger {
public:
    static bool is_print_logs;

    static void debug(const std::string& message) {
        log(message, GREEN);
    }

    static void info(const std::string& message) {
        log(message, BLUE);
    }

    static void error(const std::string& message) {
        log(message, RED);
    }

    static void warning(const std::string& message) {
        log(message, YELLOW);
    }

    static void log(const std::string& message, Colors color) {
        if (is_print_logs) {
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole, color);
            std::cout << "LOG: " << message << std::endl;
            SetConsoleTextAttribute(hConsole, 7); 
        }
    }
};


bool Logger::is_print_logs = true;

#endif 
