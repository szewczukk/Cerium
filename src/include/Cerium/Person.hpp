#ifndef CERIUM_PERSON_HPP
#define CERIUM_PERSON_HPP

#include <vector>

#include "vec2.hpp"

namespace cerium
{
    class Act;
    class Prop;
    class Person
    {
    public:
        /*
            ^[name][Person]
            ^[class][Person]
            ^[description][Constructor in which we assign Act in which the object is]
            ^[argument]<baseAct>[Act where the Person is]
         */
        Person(Act & baseAct); //^header
        /*
            ^[name][draw]
            ^[class][Person]
            ^[description][Abstract class to draw the object into screen]
        */
        virtual void draw(void) = 0; //^header
        /*
            ^[name][update]
            ^[class][Person]
            ^[description][Abstract class to update the object with deltaTime]
            ^[argument]<deltaTime>[DeltaTime of main game clock]
        */
        virtual void update(const float & deltaTime); //^header
        /*
            ^[name][setPosition]
            ^[class][Person]
            ^[description][Setting position of Person]
            ^[argument]<position>[Position in which the Person have to be]
        */
        virtual void setPosition(const vec2 & position); //^header
        /*
            ^[name][setRotation]
            ^[class][Person]
            ^[description][Setting rotation of Person]
            ^[argument]<rotation>[Rotation of Person in degrees]
        */
        virtual void setRotation(const float & rotation); //^header
        /*
            ^[name][size]
            ^[class][Person]
            ^[description][Setting size of Person where x is width and y is height]
            ^[argument]<size>[Size of Person as vector]
        */
        virtual void setSize(const vec2 & size); //^header
        /*
            ^[name][move]
            ^[class][Person]
            ^[description][Moving the Person by the given value in vector]
            ^[argument]<relative>[Relative position as vector]
        */
        void move(const vec2 & relative); //^header
        /*
            ^[name][rotate]
            ^[class][Person]
            ^[description][Rotating the Person by the given value in vector]
            ^[argument]<relative>[Relative rotation]
        */
        void rotate(const float & relative); //^header
        /*
            ^[name][addProp]
            ^[class][Person]
            ^[description][Adding new Prop to Person]
            ^[argument]<component>[Pointer to Prop to add]
        */
        void addProp(Prop * component); //^header
    protected:
        vec2 position;
        vec2 size;
        Act* baseAct;
        float rotation;
        std::vector<Prop*> props;
    };
}

#endif