#include "../include/Cerium/RigidBody.hpp"

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
}