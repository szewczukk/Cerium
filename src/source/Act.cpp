#include "../include/Cerium/Act.hpp"

#include "../include/Cerium/Person.hpp"

namespace cerium
{
    void Act::draw(void)
    {
        for (auto & person : this->persons)
        {
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
            this->persons[person->getName()] = person;
        }
    }


    void Act::remove(const std::string name)
    {
        delete persons[name];
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
        return nullptr;
    }
}