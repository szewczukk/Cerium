#include "../include/Cerium/ActManager.hpp"

#include "../include/Cerium/Act.hpp"
#include "../include/Cerium/DebugLog.hpp"

namespace cerium
{
    Act * ActManager::get(const std::string & name)
    {
        for(auto & act : instance().acts)
        {
            if (act.first == name) return act.second;
        }
        cerium::DebugLog::add(name + " act can't be returned");
        return nullptr;
    }


    void ActManager::updateCurrent(const float & deltaTime)
    {
        instance().currentAct->update(deltaTime);
    }


    void ActManager::drawCurrent(void)
    {
        instance().currentAct->draw();
    }


    void ActManager::add(const std::string & name)
    {
        if(!exist(name))
        {
            instance().acts.push_back(std::pair<std::string, Act*>(name, new Act));
            return;
        }
        cerium::DebugLog::add(name + " act already exists");
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
        for (auto & act : instance().acts)
        {
            if (act.first == name) delete act.second;
        }
        DebugLog::add(name + " act cannot be founded to remove");
    }


    bool ActManager::exist(const std::string & name)
    {
        for(auto & act : instance().acts)
        {
            if (act.first == name) return true;
        }
        return false;
    }


    void ActManager::setCurrent(const std::string & name)
    {
        for(auto & act : instance().acts)
        {
            if(act.first == name)
            {
                instance().currentAct = act.second;
                return;
            }
        }
        DebugLog::add(name + " act cannot be founded to set current");
    }


    ActManager & ActManager::instance()
    {
        static ActManager actManager;
        return actManager;
    }


    std::vector<std::pair<std::string, Act*>> ActManager::getAllActs()
    {
        return instance().acts;
    }
}