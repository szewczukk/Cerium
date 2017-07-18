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
            ^[argument]<parent>[Parent of this Person]
            ^[argument]<baseAct>[Act where the Person is]
         */
        Person(const std::string & name, Person * parent, Act * baseAct); //^header
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
        /*
            ^[name][propExist]
            ^[class][Person]
            ^[description][Checking is Prop with given name exist]
            ^[argument]<name>[Name of Prop to check existing]
            ^[returns][true if Prop exist or false if it isn't]
        */
        bool propExist(const std::string & name); //^header
        /*
            ^[name][getProp]
            ^[class][Person]
            ^[argument]<name>[Name of Prop to check existing]
            ^[returns][Pointer to Prop with given name]
        */
        Prop * getProp(const std::string & name); //^header
        /*
            ^[name][getParent]
            ^[class][Person]
            ^[returns][Pointer to parent Person]
        */
        Person * getParent(void); //^header
        /*
            ^[name][addChild]
            ^[class][Person]
            ^[description][Adding new Person child]
            ^[argument]<person>[Person to add as child]
        */
        void addChild(Person * person); //^header
        /*
            ^[name][childExist]
            ^[class][Person]
            ^[description][Checking is child with given name exist]
            ^[argument]<name>[Name of children to check existing]
        */
        bool childExist(const std::string & name); //^header
        /*
            ^[name][getChild]
            ^[class][Person]
            ^[argument]<name>[Name of children to returning]
            ^[returns][Pointer to child with given name]
        */
        Person * getChild(const std::string & name); //^header
        /*
            ^[name][cast_to]
            ^[class][Person]
            ^[returns][Pointer to this object casted to given type]
        */
        template<typename T>
                T* cast_to(void); //^header
        /*
            ^[name][getAllChildren]
            ^[class][Act]
            ^[description][Getting all Children]
        */
        std::vector<std::pair<std::string, Person*>> getAllChildren(void); //^header
        /*
            ^[name][getAllProps]
            ^[class][Act]
            ^[description][Getting all Props]
        */
        std::vector<std::pair<std::string, Prop*>> getAllProps(void); //^header
    protected:
        vec2 position;
        vec2 size;
        Act* baseAct;
        Person * parent;
        float rotation;
        std::string name;
        std::vector<std::pair<std::string, Prop*>> props;
        std::vector<std::pair<std::string, Person*>> children;
    };
}

#endif