#pragma once

#include <string>



namespace loge {
    struct LogType {
        std::string name;
        std::string value;
    };

    enum LOG_MODE {
        MESSAGE = 0,
        SUCCESS = 1,
        ERROR = 2,
        WARN = 3,
        DEBUG = 4,
    };

    // log functions
    void log(loge::LOG_MODE mode, const std::string& message);
    void message(const std::string& message);
    void success(const std::string& message);
    void error(const std::string& message);
    void warn(const std::string& message);
    void debug(const std::string& message);

    // progress bar
    void progress(int& progress, const std::function<bool()>& shouldExit);

}
