#include <GL/glew.h>
#include "../include/Cerium/Act.hpp"

#include "../include/Cerium/Person.hpp"
#include "../include/Cerium/ResourceManager.hpp"
#include "../include/Cerium/ShaderProgram.hpp"
#include "../include/Cerium/Camera.hpp"
#include "../include/Cerium/DebugLog.hpp"

namespace cerium
{
    void Act::draw(void)
    {
        for (auto & person : this->persons)
        {
            ResourceManager::get("shader")->use();
            cerium::Camera::update(cerium::ResourceManager::get("shader")->cast_to<cerium::ShaderProgram>());

            person.second->draw();
        }
    }


    void Act::update(const float & deltaTime)
    {
        for (auto & person : this->persons)
        {
            person.second->update(deltaTime);
        }
    }


    void Act::add(Person * person)
    {
        if(!exist(person->getName()))
        {
            persons.push_back(std::pair<std::string, Person*>(person->getName(), person));
            return;
        }
        cerium::DebugLog::add(person->getName() + " already exists");
    }


    void Act::remove(const std::string name)
    {
        for (auto & person : persons)
        {
            if (person.first == name) delete person.second;
        }
    }


    void Act::clear(void)
    {
        for(auto & person : this->persons)
        {
            delete person.second;
        }
    }


    bool Act::exist(const std::string & name)
    {
        for(auto & person : this->persons)
        {
            if(person.first == name) return true;
        }
        return false;
    }


    Person * Act::get(const std::string & name)
    {
        for(auto & person : this->persons)
        {
            if(person.first == name) return person.second;
        }
        cerium::DebugLog::add(name + " person can't be returned");
        return nullptr;
    }
}