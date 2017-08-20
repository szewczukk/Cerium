#ifndef CERIUM_RIGIDBODY_HPP
#define CERIUM_RIGIDBODY_HPP

#include "Prop.hpp"

#include "vec4.hpp"
#include "vec2.hpp"

namespace cerium
{
	class RigidBody : public Prop
	{
	public:
		RigidBody(Person * basePerson, Prop * parent, const std::string & name, 
			const float & gravityStrength);
		
		bool isCollideWithPersonWithName(const std::string & name);

		bool isCollideWithPersonsWithTag(const std::string & tag);

		void setCustomRectangle(const vec4 & rectangle);

		bool isOnGround();

		void setIsOnGround(const bool & is);

		void applyForce(const vec2 & force);

		virtual void update(const float & deltaTime);
	private:
		float gravityStrength;
		bool onGround;
		vec2 velocity;

		vec4 customRectangle;
	};
}

#endif