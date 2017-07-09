#ifndef CERIUM_DEBUGLOG_HPP
#define CERIUM_DEBUGLOG_HPP

#include <vector>
#include <iostream>
#include <string>
#include <fstream>

namespace cerium
{
    class DebugLog
    {
    public:
        ~DebugLog();
        static void init(void);
        static void add(const std::string & value);
        static void update(void);
    private:
        static DebugLog & instance();

        DebugLog() {};

        void operator=(const DebugLog & other) = delete;
        DebugLog(const DebugLog & other) = delete;
    private:
        std::vector<std::pair<bool, std::string>> log;
        std::ofstream file;
    };
}

#endif