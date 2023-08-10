#pragma once
#include <syslog.h>
#include <string>

class Log {
public:
    Log() {
        openlog("my_program", LOG_NDELAY | LOG_PID | LOG_CONS, LOG_USER);
    }

    ~Log() {
        closelog();
    }

    void inf(const std::string& msg) {
        syslog(LOG_INFO, msg.data(), msg.size());
    }

    void warning(const std::string& msg) {
        syslog(LOG_WARNING, msg.data(), msg.size());
    }

    void error(const std::string& msg) {
        syslog(LOG_ERR, msg.data(), msg.size());
    }
};