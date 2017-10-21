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

		~RigidBody();

		bool isColliding(void);
		
		bool isCollidingWithPersonWithName(const std::string & name);

		bool isCollidingWithPersonsWithTag(const std::string & tag);

		bool isOnGround(void);

		void setIsOnGround(const bool & is);

		void applyForce(const vec2 & force);

		virtual void update(const float & deltaTime);
	private:
		float gravityStrength;
		bool onGround;
		vec2 velocity;

		vec2 * otherPersonPosition, * otherPersonSize;
	};
}

#endif