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
		this->gravityStrength = gravityStrength;
		basePerson->isRigided = true;
		isOnGround = false;
	}


	void RigidBody::update(const float & deltaTime)
	{
		for (auto & person : basePerson->baseAct->getAllPersons())
		{
			if (!isOnGround)
			{
				if (person.second->isRigided)
				{
					if (abs(basePerson->getPosition().x - person.second->getPosition().x) * 2 < (basePerson->getSize().x + person.second->getSize().x) &&
						abs(basePerson->getPosition().y - person.second->getPosition().y) * 2 < (basePerson->getSize().y + person.second->getSize().y))
						isOnGround = true;
					else
						isOnGround = false;
				}
				else
					isOnGround = false;
			}
		}

		if (!isOnGround)
			basePerson->move({ 0, gravityStrength * deltaTime});
	}


	bool RigidBody::isCollideWithPersonWithName(const std::string & name)
	{
		vec2 otherPersonPosition, otherPersonSize;

		if (basePerson->getBaseAct()->get(name)->isRigided)
		{
			otherPersonPosition = basePerson->getBaseAct()->get(name)->getPosition();
			otherPersonSize = basePerson->getBaseAct()->get(name)->getSize();

			if (abs(basePerson->getPosition().x - otherPersonPosition.x) * 2 < (basePerson->getSize().x + otherPersonSize.x) &&
				abs(basePerson->getPosition().y - otherPersonPosition.y) * 2 < (basePerson->getSize().y + otherPersonSize.y))
				return true;
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

				if (abs(basePerson->getPosition().x - otherPersonPosition.x) * 2 < (basePerson->getSize().x + otherPersonSize.x) &&
					abs(basePerson->getPosition().y - otherPersonPosition.y) * 2 < (basePerson->getSize().y + otherPersonSize.y))
					return true;
			}
		}
		return false;
	}
}