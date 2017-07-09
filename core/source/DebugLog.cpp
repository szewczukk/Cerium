#include "../include/Cerium/DebugLog.hpp"

namespace cerium
{
    void DebugLog::init(void)
    {
        instance().file.open("log.txt");
    }


    DebugLog & DebugLog::instance()
    {
        static DebugLog debugLog;
        return debugLog;
    }


    void DebugLog::add(const std::string & value)
    {
        instance().log.push_back(std::pair<bool, std::string>(false, value));
    }


    void DebugLog::update(void)
    {
        for(auto & pair : instance().log)
        {
            if(!pair.first)
            {
                std::cout << pair.second << std::endl;
                instance().file << pair.second;

                pair.first = true;
            }
        }
    }


    DebugLog::~DebugLog()
    {
        file.close();
    }
}