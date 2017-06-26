#ifndef CERIUM_PROP_HPP
#define CERIUM_PROP_HPP

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
        };
        /*
            ^[name][update]
            ^[class][Prop]
            ^[description][Updating Prop with deltaTime]
            ^[argument]<deltaTime>[DeltaTime of main game clock]
         */
        virtual void update(const float & deltaTime) = 0; //^header
        /*
            ^[name][draw]
            ^[class][Prop]
            ^[description][Abstract class to draw the object into screen]
         */
        virtual void draw(void) = 0; //^header
        /*
            ^[name][getName]
            ^[class][Prop]
            ^[returns][Name of Prop]
         */
        std::string getName() //^header
        {
            return name;
        }
    protected:
        Person * basePerson;
        std::string name;
    };
}

#endif