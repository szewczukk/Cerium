#include "../include/Cerium/RigidBody.hpp"

#include "../include/Cerium/Act.hpp"
#include "../include/Cerium/Person.hpp"
#include "../include/Cerium/DebugLog.hpp"

namespace cerium
{
	RigidBody::RigidBody(Person * basePerson, Prop * parent, const std::string & name, 
		const float & gravityStrength, const std::string & tag)
		: Prop(basePerson, parent, name)
	{
		basePerson->isRigided = true;
	}


	void RigidBody::update(const float & deltaTime)
	{

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