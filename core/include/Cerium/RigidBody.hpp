#ifndef CERIUM_RIGIDBODY_HPP
#define CERIUM_RIGIDBODY_HPP

#include "Prop.hpp"

namespace cerium
{
	class RigidBody : public Prop
	{
	public:
		RigidBody(Person * basePerson, Prop * parent, const std::string & name, 
			const float & gravityStrength, const std::string & tag);
		
		bool isCollideWithPersonWithName(const std::string & name);

		bool isCollideWithPersonsWithTag(const std::string & tag);

		virtual void update(const float & deltaTime);
	private:
		float gravityStrength;
	};
}

#endif