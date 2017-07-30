#ifndef CERIUM_PROP_HPP
#define CERIUM_PROP_HPP

#include <vector>
#include <string>

namespace cerium
{
    class Button;
    class Person;
    class Prop
    {
    public:
        /*
            ^[name][Prop]
            ^[class][Prop]
            ^[description][Setting pointer to Person where the Prop is]
            ^[argument]<basePerson>[Person where the Prop is]
            ^[argument]<parent>[Parent Prop of this Prop]
            ^[argument]<name>[Name of Prop]
         */
        Prop(Person * basePerson, Prop * parent, const std::string & name)
        {
            this->basePerson = basePerson;
            this->name = name;
            this->parent = parent;
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
            ^[name][getPerson]
            ^[class][Prop]
            ^[returns][Person where the Prop is]
         */
        Person & getPerson(void) //^header
        {
            return *basePerson;
        }
        /*
            ^[name][getParent]
            ^[class][Prop]
            ^[returns][Parent of thi prop]
         */
        Prop & getParent(void) //^header
        {
            return *parent;
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
                children.push_back(std::pair<std::string, Prop*>(prop->getName(), prop));
            }
        }
        /*
            ^[name][getChild]
            ^[class][Prop]
            ^[argument]<name>[Name of Prop to return]
            ^[returns][Pointer to children with given name]
         */
        Prop * getChild(const std::string & name) //^header
        {
            for(auto & child : children)
            {
                if(child.first == name) return child.second;
            }
            return nullptr;
        }
        /*
            ^[name][cast_to]
            ^[class][Resource]
            ^[description][Casting this object to other, given type]
            ^[returns][Casted object]
         */
        template<typename T>
                T* cast_to(void) //^header
        {
			return dynamic_cast<T*>(this);
        }

        std::vector<std::pair<std::string, Prop*>> getAllChildren(void)
        {
            return children;
        }
    protected:
        Person * basePerson;
        Prop * parent;
        std::string name;
        std::vector<std::pair<std::string, Prop*>> children;
    };
}

#endif