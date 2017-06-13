#ifndef CERIUM_ACT_HPP
#define CERIUM_ACT_HPP

#include <unordered_map>
#include <iostream>

namespace cerium
{
    class Person;
    class Act
    {
    public:
        /*
            ^[name][draw]
            ^[class][Act]
            ^[description][Draws all the persons in Act]
        */
        void draw(void);
        /*
            ^[name][update]
            ^[class][Act]
            ^[description][Updates all the persons in Act]
            ^[argument]<deltaTime>[DeltaTime of main game clock]
        */
        virtual void update(const float & deltaTime);
        /*
            ^[name][add]
            ^[class][Act]
            ^[description][Adding new person with given name]
            ^[argument]<name>[Name of new Person]
            ^[argument]<person>[Reference to Person]
        */
        void add(const std::string & name, Person & person);
        /*
            ^[name][remove]
            ^[class][Act]
            ^[description][Removing person with given name]
            ^[argument]<name>[Name of Person to remove]
        */
        void remove(const std::string name);
        /*
            ^[name][clear]
            ^[class][Act]
            ^[description][Removing all Persons]
        */
        void clear(void);
        /*
            ^[name][exist]
            ^[class][Act]
            ^[description][Checking existing of Person with given name]
            ^[argument]<name>[Name of Person to remove]
        */
        bool exist(const std::string & name);
        /*
            ^[name][get]
            ^[class][Act]
            ^[description][Getting Person from Act with given name]
            ^[argument]<name>[Name of Person to remove]
            ^[returns][Pointer to Person with given name]
        */
        Person * get(const std::string & name);
    protected:
        std::unordered_map<std::string, Person*> m_persons;
    };
}

#endif