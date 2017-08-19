#ifndef CERIUM_RIGIDBODY_HPP
#define CERIUM_RIGIDBODY_HPP

#include "Prop.hpp"

namespace cerium
{
	class RigidBody : public Prop
	{
	public:
		RigidBody(Person * basePerson, Prop * parent, const std::string & name, 
			const float & gravityStrength);
		
		bool isCollideWithPersonWithName(const std::string & name);

		bool isCollideWithPersonsWithTag(const std::string & tag);

		bool isOnGround();

		void setIsOnGround(const bool & is);

		virtual void update(const float & deltaTime);
	private:
		float gravityStrength;
		bool onGround;
	};
}

#endif