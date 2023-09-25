#include "../include/loge/loge.hpp"

#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <functional>

const std::string RESET_COLOR = "\033[0m";
const std::string RED_COLOR = "\033[31m";
const std::string GREEN_COLOR = "\033[32m";
const std::string YELLOW_COLOR = "\033[33m";


loge::LogType MESSAGE_TYPE = {.name = "LOG", .value = RESET_COLOR};
loge::LogType SUCCESS_TYPE = {.name = "SUCCESS", .value = GREEN_COLOR};
loge::LogType ERROR_TYPE = {.name = "ERROR", .value = RED_COLOR};
loge::LogType WARN_TYPE = {.name = "WARN", .value = YELLOW_COLOR};
loge::LogType DEBUG_TYPE = {.name = "DEGUB", .value = YELLOW_COLOR};

const loge::LogType COLOR_MAP[] = {
    MESSAGE_TYPE,
    SUCCESS_TYPE,
    ERROR_TYPE,
    WARN_TYPE,
    DEBUG_TYPE
};

// mutex for logging
std::mutex mtx;

void loge::log(loge::LOG_MODE mode, const std::string& message) {
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << COLOR_MAP[mode].value 
        << "[" << COLOR_MAP[mode].name << "]" 
        << message 
        << RESET_COLOR << std::endl;
}


void loge::message(const std::string& message) {
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << MESSAGE_TYPE.value 
        << "[" << MESSAGE_TYPE.name << "]" 
        << message 
        << RESET_COLOR << std::endl;
}

void loge::success(const std::string& message) {
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << SUCCESS_TYPE.value 
        << "[" << SUCCESS_TYPE.name << "]" 
        << message 
        << RESET_COLOR << std::endl;
}

void loge::error(const std::string& message) {
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << ERROR_TYPE.value 
        << "[" << ERROR_TYPE.name << "]" 
        << message 
        << RESET_COLOR << std::endl;
}

void loge::warn(const std::string& message) {
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << WARN_TYPE.value 
        << "[" << WARN_TYPE.name << "]" 
        << message 
        << RESET_COLOR << std::endl;
}


void loge::debug(const std::string& message) {
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << DEBUG_TYPE.value 
        << "[" << DEBUG_TYPE.name << "]" 
        << message 
        << RESET_COLOR << std::endl;
}

void progress(int& progress, const std::function<bool()>& shouldExit) {
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << "[";

    while (!shouldExit()) {
        for (int i = 0; i < 50; ++i) {
            if (i < progress / 2) {
                std::cout << GREEN_COLOR << "=";
            } else {
                std::cout << " ";
            }
        }

        std::cout << "] " << progress << "%" << RESET_COLOR << "\r";
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << std::endl;
}

