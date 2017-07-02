#include "../include/Cerium/RigidBody.hpp"

#include "../include/Cerium/Person.hpp"

namespace cerium
{
    RigidBody::RigidBody(Person* basePerson, Prop *parent,  const std::string &name) : Prop(basePerson, parent, name)
    {

    }


    bool RigidBody::isCollide(RigidBody * other)
    {
        return (getPosition().x < other->getPosition().x + other->getSize().y &&
                getPosition().x + getSize().x > other->getPosition().x &&
                getPosition().y < other->getPosition().y + other->getSize().y &&
                getPosition().y + getSize().y > other->getPosition().y);
    }


    vec2 RigidBody::getPosition(void)
    {
        return position;
    }


    vec2 RigidBody::getSize(void)
    {
        return size;
    }



    void RigidBody::setVelocity(const vec2 & velocity)
    {
        this->velocity = velocity;
    }


    vec2 RigidBody::getVelocity(void)
    {
        return velocity;
    }


    void RigidBody::update(const float &deltaTime)
    {
        size = getPerson().getSize();
        position = getPerson().getPosition();

        getPerson().move(velocity);
    }
}