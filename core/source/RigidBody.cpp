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
		basePerson->isRigided = true;
		isOnGround = false;
	}


	void RigidBody::update(const float & deltaTime)
	{
		for (auto & person : basePerson->baseAct->getAllPersons())
		{
			if (isOnGround)
				break;

			if (person.second->isRigided)
			{
				if (basePerson->getPosition() >= person.second->getPosition() &&
					basePerson->getPosition() <= person.second->getPosition() + person.second->getSize())
				{
					isOnGround = true;
				}
				else
				{
					isOnGround = false;
				}
			}
		}

		if (!isOnGround)
			basePerson->move({ 0, 22 });
	}


	bool RigidBody::isCollideWithPersonWithName(const std::string & name)
	{
		vec2 otherPersonPosition, otherPersonSize;

		if (basePerson->getBaseAct()->get(name)->isRigided)
		{
			otherPersonPosition = basePerson->getBaseAct()->get(name)->getPosition();
			otherPersonSize = basePerson->getBaseAct()->get(name)->getSize();

			if (basePerson->getPosition() >= otherPersonPosition &&
				basePerson->getPosition() <= otherPersonPosition + otherPersonSize)
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

				if (basePerson->getPosition() >= otherPersonPosition &&
					basePerson->getPosition() <= otherPersonPosition + otherPersonSize)
					return true;
			}
		}
		return false;
	}
}