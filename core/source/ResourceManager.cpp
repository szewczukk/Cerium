#include "../include/Cerium/ResourceManager.hpp"
#include "../include/Cerium/DebugLog.hpp"

namespace cerium
{
    Resource * ResourceManager::get(const std::string & name)
    {
        for(auto & resource : instance().resources)
        {
            if(resource.first == name)
            {
                return resource.second;
            }
        }
        cerium::DebugLog::add(name + " resource can't be returned");
        return nullptr;
    }


	template<class T>
    void ResourceManager::add(const std::string & name, T * resource)
    {
        if(!exist(name))
        {
            instance().resources.push_back(std::pair<std::string, Resource*>(name, resource));
            return;
        }
        cerium::DebugLog::add(name + " resource already exists");
    }


    bool ResourceManager::exist(const std::string & name)
    {
        for(auto & resource : instance().resources)
        {
            if(resource.first == name) return true;
        }
        return false;
    }


    void ResourceManager::remove(const std::string & name)
    {
        for(auto & resource : instance().resources)
        {
            if(resource.first == name)
            {
                delete resource.second;
                return;
            }
        }
        cerium::DebugLog::add(name + " resource can't be removed");
    }


    void ResourceManager::clear(void)
    {
		instance().resources.clear();
    }


    ResourceManager::~ResourceManager()
    {
        clear();
    }


    ResourceManager & ResourceManager::instance()
    {
        static ResourceManager resourceManager;
        return resourceManager;
    }
}