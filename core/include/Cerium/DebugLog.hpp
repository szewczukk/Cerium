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
        /*
            ^[name][~DebugLog]
            ^[class][DebugLog]
            ^[description][Closing output file]
        */
        ~DebugLog(); //^header
        /*
            ^[name][init]
            ^[class][DebugLog]
            ^[description][Opening file]
        */
        static void init(void); //^header
        /*
            ^[name][add]
            ^[class][DebugLog]
            ^[description][Adding new issue to queue]
         */
        static void add(const std::string & value); //^header
        /*
            ^[name][update]
            ^[class][DebugLog]
            ^[description][Prints and logging all unprinted issues]
         */
        static void update(void); //^header
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