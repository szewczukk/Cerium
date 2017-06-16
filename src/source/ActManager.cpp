#include "../include/Cerium/ActManager.hpp"

#include "../include/Cerium/Act.hpp"

namespace cerium
{
    ActManager::ActManager()
    {

    }


    Act * ActManager::get(const std::string & name)
    {
        for(auto & act : instance().acts)
        {
            if (act.first == name) return act.second;
        }
    }


    void ActManager::add(const std::string & name, Act * act)
    {
        instance().acts[name] = act;
    }


    void ActManager::clear(void)
    {
        for (auto & act : instance().acts)
        {
            delete act.second;
        }
    }


    void ActManager::remove(const std::string & name)
    {
        delete instance().acts[name];
    }


    ActManager & ActManager::instance()
    {
        static ActManager actManager;
        return actManager;
    }
}