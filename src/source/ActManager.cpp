#include "../include/Cerium/ActManager.hpp"

#include "../include/Cerium/Act.hpp"

namespace cerium
{
    Act * ActManager::get(const std::string & name)
    {
        for(auto & act : instance().acts)
        {
            if (act.first == name) return act.second;
        }
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
        }
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
            if(act.first == name) instance().currentAct = act.second;
        }
    }


    ActManager & ActManager::instance()
    {
        static ActManager actManager;
        return actManager;
    }
}