#include "../include/Cerium/RigidBody.hpp"

#include "../include/Cerium/Act.hpp"
#include "../include/Cerium/Person.hpp"

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

		otherPersonPosition = basePerson->getBaseAct()->get(name)->getPosition();
		otherPersonSize = basePerson->getBaseAct()->get(name)->getSize();

		if (basePerson->getPosition() >= otherPersonPosition &&
			basePerson->getPosition() <= otherPersonPosition + otherPersonSize)
			return true;
		return false;
	}


	bool RigidBody::isCollideWithPersonsWithTag(const std::string & tag)
	{
		vec2 otherPersonPosition, otherPersonSize;

		for (int i = 0; i < basePerson->getBaseAct()->getAllPersonsWithTag(tag).size(); i++)
		{
			otherPersonPosition = basePerson->getBaseAct()->getAllPersonsWithTag(tag)[i]->getPosition();
			otherPersonSize = basePerson->getBaseAct()->getAllPersonsWithTag(tag)[i]->getSize();

			if (basePerson->getPosition() >= otherPersonPosition &&
				basePerson->getPosition() <= otherPersonPosition + otherPersonSize)
				return true;
		}
		return false;
	}
}