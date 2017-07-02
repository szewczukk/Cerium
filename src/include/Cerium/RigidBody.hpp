#ifndef CERIUM_RIGIDBODY_HPP
#define CERIUM_RIGIDBODY_HPP

#include "Prop.hpp"
#include "vec2.hpp"

namespace cerium
{
    class RigidBody : public Prop
    {
    public:
        /*
            ^[name][RigidBody]
            ^[class][RigidBody]
            ^[description][Setting 0 as value of attributes of vector]
            ^[argument]<basePerson>[Person where the RigidBody is]
            ^[argument]<parent>[Parent Prop of RigidBody]
            ^[argument]<name>[Name of Prop]
        */
        RigidBody(Person * basePerson, Prop * parent, const std::string & name); //^header
        /*
            ^[name][isCollide]
            ^[class][RigidBody]
            ^[description][Checking is the RigidBody collides with other]
            ^[argument]<other>[Pointer to other RigidBody]
            ^[returns][True if the RigidBodies collides with BoundingBox or false when they aren't]
        */
        bool isCollide(RigidBody * other); //^header
        /*
            ^[name][getPosition]
            ^[class][RigidBody]
            ^[description][Returns Position where the RigidBody is]
            ^[returns][Position of RigidBody]
        */
        vec2 getPosition(void); //^header
        /*
            ^[name][getSize]
            ^[class][RigidBody]
            ^[description][Returns size of RigidBody]
            ^[returns][Size of RigidBody]
        */
        vec2 getSize(void); //^header
        /*
            ^[name][setVelocity]
            ^[class][RigidBody]
            ^[description][Setting velocity of RigidBody]
            ^[argument]<velocity>[Velocity of RigidBody]
        */
        void setVelocity(const vec2 & velocity); //^header
        /*
            ^[name][getVelocity]
            ^[class][RigidBody]
            ^[returns][Velocity of RigidBody]
        */
        vec2 getVelocity(void);
        /*
            ^[name][update]
            ^[class][RigidBody]
            ^[description][Setting position and size as position and size of basePerson, moving basePerson by velocity]
        */
        virtual void update(const float & deltaTime) override; //^header
    private:
        vec2 position;
        vec2 size;
        vec2 velocity;
    };
}

#endif