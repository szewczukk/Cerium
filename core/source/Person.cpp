#include "../include/Cerium/Person.hpp"

#include "../include/Cerium/Act.hpp"
#include "../include/Cerium/Prop.hpp"
#include "../include/Cerium/DebugLog.hpp"

namespace cerium
{
    Person::Person(const std::string & name, Person * parent, Act * baseAct, const std::string & tag)
    {
        this->name = name;
        this->baseAct = baseAct;
        this->parent = parent;

		this->isTextured = false;
		this->isRigided = false;
    }


    void Person::draw(void)
    {
        for (auto & prop : this->props)
        {
            prop.second->draw();
        }
    }


    void Person::update(const float & deltaTime)
    {
        for (auto & prop : this->props)
        {
            prop.second->update(deltaTime);
        }
    }


    void Person::setPosition(const vec2 & position)
    {
        this->position = position;
    }


    void Person::setRotation(const float & rotation)
    {
        this->rotation = rotation;
    }


    void Person::setSize(const vec2 & size)
    {
        this->size = size;
    }


    void Person::move(const vec2 & relative)
    {
        setPosition(this->position + relative);
    }


    void Person::rotate(const float & relative)
    {
        setRotation(this->rotation + relative);
    }


    vec2 Person::getPosition()
    {
        return position;
    }


    float Person::getRotation()
    {
        return rotation;
    }


    vec2 Person::getSize()
    {
        return size;
    }


    std::string Person::getName()
    {
        return name;
    }

	std::string Person::getTag()
	{
		return tag;
	}


    void Person::addProp(Prop * component)
    {
        props.push_back(std::pair<std::string, Prop*>(component->getName(), component));
    }


    bool Person::propExist(const std::string & name)
    {
        for(auto & prop : props)
        {
            if(prop.first == name) return true;
        }
        return false;
    }


    Prop * Person::getProp(const std::string & name)
    {
        for(auto & prop : props)
        {
            if(prop.first == name) return prop.second;
        }
        cerium::DebugLog::add(name + " prop from " + this->name + " cont't be returned");
        return nullptr;
    }


    Person * Person::getParent(void)
    {
        return parent;
    }


    void Person::addChild(Person * person)
    {
        if(!childExist(person->getName()))
        {
            children.push_back(std::pair<std::string, Person*>(person->getName(), person));
            return;
        }
        cerium::DebugLog::add(name + " child from " + this->name + " already exists");
    }


    bool Person::childExist(const std::string & name)
    {
        for(auto & child : children)
        {
            if(child.first == name) return true;
        }
        return false;
    }


    Person * Person::getChild(const std::string & name)
    {
        for(auto & child : children)
        {
            if(child.first == name) return child.second;
        }
        cerium::DebugLog::add(name + " child from " + this->name + " can't be returned");
        return nullptr;
    }

    template<typename T>
    T* Person::cast_to(void)
    {
        return dynamic_cast<T>(this);
    }


    std::vector<std::pair<std::string, Person*>> Person::getAllChildren(void)
    {
        return children;
    }


    std::vector<std::pair<std::string, Prop*>> Person::getAllProps(void)
    {
        return props;
    }


	bool Person::isCollideWithPersonWithName(const std::string & name)
	{
		vec2 otherPersonPosition, otherPersonSize;

		otherPersonPosition = baseAct->get(name)->getPosition();
		otherPersonSize = baseAct->get(name)->getSize();

		if (position >= otherPersonPosition && position <= otherPersonPosition + size)
			return true;

		return false;
	}


	bool Person::isCollideWithPersonsWithTag(const std::string & tag)
	{
		vec2 otherPersonPosition, otherPersonSize;

		for (int i = 0; i < baseAct->getAllPersonsWithTag(tag).size(); i++)
		{
			otherPersonPosition = baseAct->getAllPersonsWithTag(tag)[i]->getPosition();
			otherPersonSize = baseAct->getAllPersonsWithTag(tag)[i]->getSize();

			if (position >= otherPersonPosition &&
				position <= otherPersonPosition + size)
				return true;
		}
		return false;
	}


	Act * Person::getBaseAct(void)
	{
		return baseAct;
	}
}