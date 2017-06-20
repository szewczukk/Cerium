#ifndef CERIUM_PERSON_HPP
#define CERIUM_PERSON_HPP

#include <vector>
#include <iostream>

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
            ^[argument]<name>[Name of Person]
            ^[argument]<baseAct>[Act where the Person is]
         */
        Person(const std::string & name, Act & baseAct); //^header
        /*
            ^[name][draw]
            ^[class][Person]
            ^[description][Abstract class to draw the object into screen]
        */
        void draw(void); //^header
        /*
            ^[name][update]
            ^[class][Person]
            ^[description][Abstract class to update the object with deltaTime]
            ^[argument]<deltaTime>[DeltaTime of main game clock]
        */
        void update(const float & deltaTime); //^header
        /*
            ^[name][setPosition]
            ^[class][Person]
            ^[description][Setting position of Person]
            ^[argument]<position>[Position in which the Person have to be]
        */
        void setPosition(const vec2 & position); //^header
        /*
            ^[name][setRotation]
            ^[class][Person]
            ^[description][Setting rotation of Person]
            ^[argument]<rotation>[Rotation of Person in degrees]
        */
        void setRotation(const float & rotation); //^header
        /*
            ^[name][size]
            ^[class][Person]
            ^[description][Setting size of Person where x is width and y is height]
            ^[argument]<size>[Size of Person as vector]
        */
        void setSize(const vec2 & size); //^header
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
            ^[name][getPosition]
            ^[class][Person]
            ^[returns][Position of Person]
        */
        vec2 getPosition(); //^header
        /*
            ^[name][getSize]
            ^[class][Person]
            ^[returns][Size of Person]
        */
        vec2 getSize(); //^header
        /*
            ^[name][getRotation]
            ^[class][Person]
            ^[returns][Rotation of Person]
        */
        float getRotation(); //^header
        /*
            ^[name][getName]
            ^[class][Person]
            ^[returns][Name of Person]
        */
        std::string getName(); //^header
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
        std::string name;
    };
}

#endif