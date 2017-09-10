#include "../include/Cerium/RigidBody.hpp"

#include "../include/Cerium/Act.hpp"
#include "../include/Cerium/Person.hpp"
#include "../include/Cerium/DebugLog.hpp"

#include <memory>

namespace cerium
{
	RigidBody::RigidBody(Person * basePerson, Prop * parent, const std::string & name, const float & gravityStrength)
		: Prop(basePerson, parent, name, "RigidBody")
	{
		this->velocity = { 0 };
		this->gravityStrength = gravityStrength;
		basePerson->isRigided = true;
		onGround = false;
	}

	RigidBody::~RigidBody()
	{
		delete otherPersonPosition, otherPersonSize;
	}


	void RigidBody::update(const float & deltaTime)
	{
		if (gravityStrength > 0)
		{
			if (isCollideWithPersonsWithTag("collideable") && velocity.y > 0)
				onGround = true;
			else
				onGround = false;

			if (!onGround)
				velocity.y += gravityStrength;
			else
				velocity.y = 0;
		}

		basePerson->move(velocity * deltaTime);
	}


	bool RigidBody::isCollideWithPersonWithName(const std::string & name)
	{
		if (basePerson->getBaseAct()->get(name)->isRigided)
		{
			otherPersonPosition = &basePerson->getBaseAct()->get(name)->getPosition();
			otherPersonSize = &basePerson->getBaseAct()->get(name)->getSize();

			if (abs(basePerson->getPosition().x - otherPersonPosition->x) * 2 < (basePerson->getSize().x + otherPersonSize->x) &&
				abs(basePerson->getPosition().y - otherPersonPosition->y) * 2 < (basePerson->getSize().y + otherPersonSize->y))
				return true;
		}
		else
			DebugLog::add(name + " hasn't RigidBody!");
		return false;
	}


	bool RigidBody::isCollideWithPersonsWithTag(const std::string & tag)
	{
		for (auto & person : basePerson->getBaseAct()->getAllPersonsWithTag(tag))
		{
			if (person->isRigided)
			{
				otherPersonPosition = &person->getPosition();
				otherPersonSize = &person->getSize();

				if (abs(basePerson->getPosition().x - otherPersonPosition->x) * 2 < (basePerson->getSize().x + otherPersonSize->x) &&
					abs(basePerson->getPosition().y - otherPersonPosition->y) * 2 < (basePerson->getSize().y + otherPersonSize->y))
				{
					return true;
				}
			}
		}
		return false;
	}


	bool RigidBody::isOnGround(void)
	{
		return onGround;
	}


	void RigidBody::setIsOnGround(const bool & is)
	{
		onGround = is;
	}


	void RigidBody::applyForce(const vec2 & force)
	{
		velocity += force;
	}
}