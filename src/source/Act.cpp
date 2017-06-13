#include "../include/Cerium/Act.hpp"

#include "../include/Cerium/Person.hpp"

namespace cerium
{
    void Act::draw(void)
    {
        for (auto & person : m_persons)
        {
            person.second->draw();
        }
    }


    void Act::update(const float & deltaTime)
    {
        for (auto & person : m_persons)
        {
            person.second->update(deltaTime);
        }
    }


    void Act::add(const std::string & name, Person & person)
    {
        if(!exist(name))
        {
            m_persons[name] = &person;
        }
    }


    void Act::remove(const std::string name)
    {
        for(auto & person : m_persons)
        {
            if(person.first == name) delete person.second;
        }
    }


    void Act::clear(void)
    {
        for(auto & person : m_persons)
        {
            delete person.second;
        }
    }


    bool Act::exist(const std::string & name)
    {
        for(auto & person : m_persons)
        {
            if(person.first == name) return true;
        }
        return false;
    }


    Person * Act::get(const std::string & name)
    {
        for(auto & person : m_persons)
        {
            if(person.first == name) return person.second;
        }
        return nullptr;
    }
}