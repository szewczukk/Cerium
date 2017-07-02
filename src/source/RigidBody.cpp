#include "../include/Cerium/RigidBody.hpp"

#include "../include/Cerium/Person.hpp"

namespace cerium
{
    RigidBody::RigidBody(Person * basePerson, Prop * parent, const std::string & name, const float & gravityScale, const float  & mass) : Prop(basePerson, parent, name)
    {
        this->gravityScale = gravityScale;
        this->mass = mass;
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

        velocity += vec2(0, gravityScale) * deltaTime * mass;

        getPerson().move(velocity * deltaTime);
    }
}