#include "../include/Cerium/RigidBody.hpp"

#include "../include/Cerium/Act.hpp"
#include "../include/Cerium/Person.hpp"
#include "../include/Cerium/DebugLog.hpp"

namespace cerium
{
	RigidBody::RigidBody(Person * basePerson, Prop * parent, const std::string & name, 
		const float & gravityStrength)
		: Prop(basePerson, parent, name)
	{
		this->velocity = { 0 };
		this->gravityStrength = gravityStrength;
		basePerson->isRigided = true;
		onGround = false;
		customRectangle = {0};
	}


	void RigidBody::update(const float & deltaTime)
	{
		if (gravityStrength > 0)
		{
			for (auto & person : basePerson->baseAct->getAllPersons())
			{
				if (basePerson->getName() != person.second->getName())
				{
					if (person.second->isRigided)
					{
						if (isCollideWithPersonWithName(person.second->getName()) && velocity.y > 0)
							onGround = true;
						else
							onGround = false;
					}
				}
			}

			if (!onGround)
				velocity.y += gravityStrength;
			else
				velocity.y = 0;

			basePerson->move(velocity * deltaTime);
		}
	}


	bool RigidBody::isCollideWithPersonWithName(const std::string & name)
	{
		vec2 otherPersonPosition, otherPersonSize;

		if (basePerson->getBaseAct()->get(name)->isRigided)
		{
			otherPersonPosition = basePerson->getBaseAct()->get(name)->getPosition();
			otherPersonSize = basePerson->getBaseAct()->get(name)->getSize();

			if (customRectangle.w > 0)
			{
				if (abs(customRectangle.x - otherPersonPosition.x) * 2 < (customRectangle.z + otherPersonSize.x) &&
					abs(customRectangle.y - otherPersonPosition.y) * 2 < (customRectangle.w + otherPersonSize.y))
					return true;
			}
			else
			{
				if (abs(basePerson->getPosition().x - otherPersonPosition.x) * 2 < (basePerson->getSize().x + otherPersonSize.x) &&
					abs(basePerson->getPosition().y - otherPersonPosition.y) * 2 < (basePerson->getSize().y + otherPersonSize.y))
					return true;
			}
		}
		else
			DebugLog::add(name + " hasn't RigidBody!");
		return false;
	}


	bool RigidBody::isCollideWithPersonsWithTag(const std::string & tag)
	{
		vec2 otherPersonPosition, otherPersonSize;

		for (auto & person : basePerson->getBaseAct()->getAllPersonsWithTag(tag))
		{
			if (person->isRigided)
			{
				otherPersonPosition = person->getPosition();
				otherPersonSize = person->getSize();
				if (customRectangle.w > 0)
				{
					if (abs(customRectangle.x - otherPersonPosition.x) * 2 < (customRectangle.z + otherPersonSize.x) &&
						abs(customRectangle.y - otherPersonPosition.y) * 2 < (customRectangle.w + otherPersonSize.y))
						return true;
				}
				else
				{
					if (abs(basePerson->getPosition().x - otherPersonPosition.x) * 2 < (basePerson->getSize().x + otherPersonSize.x) &&
						abs(basePerson->getPosition().y - otherPersonPosition.y) * 2 < (basePerson->getSize().y + otherPersonSize.y))
						return true;
				}
			}
		}
		return false;
	}


	void RigidBody::setCustomRectangle(const vec4 & rectangle)
	{
		customRectangle = rectangle;
	}


	bool RigidBody::isOnGround()
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