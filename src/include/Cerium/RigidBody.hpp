#ifndef CERIUM_RIGIDBODY_HPP
#define CERIUM_RIGIDBODY_HPP

#include "Prop.hpp"
#include "vec2.hpp"

namespace cerium
{
    class RigidBody : public Prop
    {
    public:
        RigidBody(Person * basePerson, Prop * parent, const std::string & name);

        bool isCollide(RigidBody * other);

        vec2 getPosition();
        vec2 getSize();

        virtual void update(const float & deltaTime) override;
    private:
        vec2 position;
        vec2 size;
    };
}

#endif