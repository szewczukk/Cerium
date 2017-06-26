#ifndef CERIUM_PROP_HPP
#define CERIUM_PROP_HPP

#include <map>

namespace cerium
{
    class Person;
    class Prop
    {
    public:
        /*
            ^[name][Prop]
            ^[class][Prop]
            ^[description][Setting pointer to Person where the Prop is]
            ^[argument]<basePerson>[Person where the Prop is]
         */
        Prop(Person * basePerson, const std::string & name)
        {
            this->basePerson = basePerson;
            this->name = name;
        }
        /*
            ^[name][update]
            ^[class][Prop]
            ^[description][Updating Prop with deltaTime]
            ^[argument]<deltaTime>[DeltaTime of main game clock]
         */
        virtual void update(const float & deltaTime) //^header
        {
            for(auto & child : children)
            {
                child.second->update(deltaTime);
            }
        }
        /*
            ^[name][draw]
            ^[class][Prop]
            ^[description][Abstract class to draw the object into screen]
         */
        virtual void draw(void) //^header
        {
            for(auto & child : children)
            {
                child.second->draw();
            }
        }
        /*
            ^[name][getName]
            ^[class][Prop]
            ^[returns][Name of Prop]
         */
        std::string getName(void) //^header
        {
            return name;
        }
        /*
            ^[name][getParent]
            ^[class][Prop]
            ^[returns][Person where the Prop is]
         */
        Person & getParent(void) //^header
        {
            return *basePerson;
        }
        /*
            ^[name][exist]
            ^[class][Prop]
            ^[description][Check existing of Prop with given name]
            ^[argument]<name>[Name of Prop to check existing]
            ^[returns][True when the Prop with given name exist or False when it isn't]
         */
        bool exist(const std::string & name) //^header
        {
            for(auto & child : children)
            {
                if(child.first == name) return true;
            }
            return false;
        }
        /*
            ^[name][addChild]
            ^[class][Prop]
            ^[description][Adding new prop as child]
            ^[argument]<prop>[Pointer to Prop to add]
         */
        void addChild(Prop * prop) //^header
        {
            if(!exist(prop->getName()))
            {
                children[prop->getName()] = prop;
            }
        }
        /*
            ^[name][getChildren]
            ^[class][Prop]
            ^[argument]<name>[Name of Prop to return]
            ^[returns][Pointer to children with given name]
         */
        Prop * getChildren(const std::string & name) //^header
        {
            for(auto & child : children)
            {
                if(child.first == name) return child.second;
            }
            return nullptr;
        }
    protected:
        Person * basePerson;
        std::string name;
        std::map<std::string, Prop*> children;
    };
}

#endif