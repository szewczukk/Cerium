#include "../include/Cerium/Scriptable.hpp"

#include "../include/Cerium/Person.hpp"

#include "../include/Cerium/Camera.hpp"
#include "../include/Cerium/EventManager.hpp"
#include "../include/Cerium/Act.hpp"
#include "../include/Cerium/ActManager.hpp"
#include "../include/Cerium/Window.hpp"
#include "../include/Cerium/Resource.hpp"
#include "../include/Cerium/Font.hpp"
#include "../include/Cerium/Costume.hpp"
#include "../include/Cerium/Costumed.hpp"
#include "../include/Cerium/Clock.hpp"
#include "../include/Cerium/Script.hpp"
#include "../include/Cerium/Music.hpp"
#include "../include/Cerium/Sound.hpp"
#include "../include/Cerium/ResourceManager.hpp"
#include "../include/Cerium/Button.hpp"

namespace cerium
{
	Person * bPerson;


	std::vector<std::pair<std::string, Person*>> l_getAllChildren(void)
	{
		return bPerson->getAllChildren();
	}


	std::vector<std::pair<std::string, Prop*>> l_getAllProps(void)
	{
		return bPerson->getAllProps();
	}


	void l_addChild(Person * child)
	{
		bPerson->addChild(child);
	}


	bool l_childExist(const std::string & name)
	{
		return bPerson->childExist(name);
	}


	Person * l_getChild(const std::string & name)
	{
		return bPerson->getChild(name);
	}


	Person * l_getParent(void)
	{
		return bPerson->getParent();
	}


	void l_addProp(Prop * component)
	{
		return bPerson->addProp(component);
	}


	bool l_propExist(const std::string & name)
	{
		return bPerson->propExist(name);
	}


	std::string l_getName(void)
	{
		return bPerson->getName();
	}


	void l_move(const vec2 & relativePosition)
	{
		bPerson->move(relativePosition);
	}


	void l_setPosition(const vec2 & position)
	{
		bPerson->setPosition(position);
	}


	void l_setSize(const vec2 & size)
	{
		bPerson->setSize(size);
	}


	void l_rotate(const float & angle)
	{
		bPerson->rotate(angle);
	}


	void l_setRotation(const float & angle)
	{
		bPerson->setRotation(angle);
	}


	vec2 l_getPosition(void)
	{
		return bPerson->getPosition();
	}


	vec2 l_getSize(void)
	{
		return bPerson->getSize();
	}


	float l_getRotation(void)
	{
		return bPerson->getRotation();
	}


	Prop * l_getProp(const std::string & name)
	{
		return bPerson->getProp(name);
	}


	Button * l_cast_to_button(Prop * p)
	{
		return dynamic_cast<Button*>(p);
	}


	Label * l_cast_to_label(Prop * p)
	{
		return dynamic_cast<Label*>(p);
	}


	Costumed * l_cast_to_costumed(Prop * p)
	{
		return dynamic_cast<Costumed*>(p);
	}


	Scriptable * l_cast_to_scriptable(Prop * p)
	{
		return dynamic_cast<Scriptable*>(p);
	}

	VertexArray * l_cast_to_vertexArray(Prop * p)
	{
		return dynamic_cast<VertexArray*>(p);
	}


	Sound * l_cast_to_sound(Resource * r)
	{
		return dynamic_cast<Sound*>(r);
	}


	Script * l_cast_to_script(Resource * r)
	{
		return dynamic_cast<Script*>(r);
	}


	Clock * l_cast_to_clock(Resource * r)
	{
		return dynamic_cast<Clock*>(r);
	}

	Font * l_cast_to_font(Resource * r)
	{
		return dynamic_cast<Font*>(r);
	}

	Music * l_cast_to_music(Resource * r)
	{
		return dynamic_cast<Music*>(r);
	}


	Costume * l_cast_to_costume(Resource * r)
	{
		return dynamic_cast<Costume*>(r);
	}


	Scriptable::Scriptable(Person * basePerson, Prop * parent, const std::string & name, Script * script)
		: Prop(basePerson, parent, name)
	{
		this->state = &script->state;

		bPerson = basePerson;

		state->set_function("move", l_move);
		state->set_function("rotate", l_rotate);

		state->set_function("setPosition", l_setPosition);
		state->set_function("setRotation", l_setRotation);
		state->set_function("setSize", l_setSize);

		state->set_function("getPosition", l_getPosition);
		state->set_function("getRotation", l_getRotation);
		state->set_function("getSize", l_getSize);

		state->set_function("adddChild", l_addChild);
		state->set_function("childExist", l_childExist);
		state->set_function("getChild", l_getChild);

		state->set_function("getProp", l_getProp);
		state->set_function("getName", l_getName);

		state->set_function("getAllChildren", l_getAllChildren);
		state->set_function("getAllProps", l_getAllProps);

		state->set_function("addProp", l_addProp);
		state->set_function("propExist", l_propExist);

		state->set_function("getParent", l_getParent);

		state->set_function("cast_to_button", l_cast_to_button);
		state->set_function("cast_to_label", l_cast_to_label);
		state->set_function("cast_to_costumed", l_cast_to_costumed);
		state->set_function("cast_to_scriptable", l_cast_to_scriptable);
		state->set_function("cast_to_vertex_array", l_cast_to_vertexArray);

		state->set_function("cast_to_sound", l_cast_to_sound);
		state->set_function("cast_to_costume", l_cast_to_costume);
		state->set_function("cast_to_script", l_cast_to_script);
		state->set_function("cast_to_clock", l_cast_to_clock);
		state->set_function("cast_to_font", l_cast_to_font);
		state->set_function("cast_to_music", l_cast_to_music);

		state->set("KEY_LEFT", SDL_SCANCODE_LEFT);
		state->set("KEY_RIGHT", SDL_SCANCODE_RIGHT);
		state->set("KEY_UP", SDL_SCANCODE_UP);
		state->set("KEY_ESCAPE", SDL_SCANCODE_ESCAPE);
		state->set("KEY_DOWN", SDL_SCANCODE_DOWN);

		sol::table inputManager = state->create_named_table("eventManager");
		inputManager.set_function("isKeyPressed", &EventManager::isKeyPressed);
		inputManager.set_function("isWindowClosed", &EventManager::isWindowClosed);
		inputManager.set_function("isMouseButtonClicked", &EventManager::isMouseButtonClicked);
		inputManager.set_function("closeWindow", &EventManager::closeWindow);

		sol::table camera = state->create_named_table("camera");
		camera.set_function("move", &Camera::move);
		camera.set_function("setPosition", &Camera::setPosition);
		camera.set_function("setSize", &Camera::setSize);
		camera.set_function("getPosition", &Camera::getPosition);
		camera.set_function("getSize", &Camera::getSize);

		sol::table actManager = state->create_named_table("actManager");
		actManager.set_function("get", &ActManager::get);
		actManager.set_function("add", &ActManager::add);
		actManager.set_function("remove", &ActManager::remove);
		actManager.set_function("exist", &ActManager::exist);
		actManager.set_function("setCurrent", &ActManager::setCurrent);
		actManager.set_function("clear", &ActManager::clear);
		actManager.set_function("getAllActs", &ActManager::getAllActs);

		sol::table window = state->create_named_table("window");
		window.set_function("setTitle", &Window::setTitle);
		window.set_function("setSize", &Window::setSize);
		window.set_function("getSize", &Window::getSize);
		window.set_function("getTitle", &Window::getTitle);

		sol::table resourceManager = state->create_named_table("resourceManager");
		resourceManager.set_function("get", &ResourceManager::get);
		resourceManager.set_function("add", sol::overload(ResourceManager::add<Script>, 
			ResourceManager::add<Font>, 
			ResourceManager::add<Costume>, 
			ResourceManager::add<Clock>,
			ResourceManager::add<Music>));
		resourceManager.set_function("remove", &ResourceManager::remove);
		resourceManager.set_function("clear", &ResourceManager::clear);

		sol::constructors<sol::types<>, sol::types<float>, sol::types<float, float>> vector2_constructors;
		state->new_usertype<vec2>("vec2", vector2_constructors,
			"x", &vec2::x, "y", &vec2::y,
			"getLength", &vec2::getLength,
			"normalize", &vec2::normalize, "normalizeSelf", &vec2::normalizeSelf);

		sol::constructors<sol::types<>, sol::types<float>, sol::types<float, float, float, float>> vector4_constructors;
		state->new_usertype<vec4>("vec4", vector4_constructors,
			"x", &vec4::x, "y", &vec4::y, "z", &vec4::z, "w", &vec4::w,
			"getLength", &vec4::getLength,
			"normalize", &vec4::normalize, "normalizeSelf", &vec4::normalizeSelf);

		sol::constructors<sol::types<std::string, Person*, Act*>> person_constructor;
		auto person = state->new_usertype<Person>("Person", person_constructor,
			"setPosition", &Person::setPosition, "setRotation", &Person::setRotation,
			"setSize", &Person::setSize, "move", &Person::move, "rotate", &Person::rotate,
			"getPosition", &Person::getPosition, "getSize", &Person::getSize,
			"getRotation", &Person::getRotation,
			"getName", &Person::getName, "addProp", &Person::addProp,
			"propExist", &Person::propExist, "getProp", &Person::getProp);
		person.set_function("getParent", &Person::getParent);
		person.set_function("addChild", &Person::addChild);
		person.set_function("childExist", &Person::childExist);
		person.set_function("getChild", &Person::getChild);
		person.set_function("getAllChildren", &Person::getAllChildren);
		person.set_function("getAllProps", &Person::getAllProps);

		state->new_usertype<Act>("Act",
			"draw", &Act::draw, "update", &Act::update,
			"add", &Act::add, "remove", &Act::remove,
			"clear", &Act::clear, "exist", &Act::exist, "get", &Act::get,
			"getAllPersons", &Act::getAllPersons);

		sol::constructor_list <sol::types<Person*, Prop*, const std::string &>> propConstructors;
		auto prop = state->new_usertype<Prop>("Prop", propConstructors,
			"getName", &Prop::getName, "getPerson", &Prop::getPerson,
			"getParent", &Prop::getParent, "exist", &Prop::exist,
			"addChild", &Prop::addChild, "getChild", &Prop::getChild,
			"getAllChildren", &Prop::getAllChildren);

		state->new_usertype<Button>("Button", "isHovered", &Button::isHovered, "isClicked", &Button::isClicked);

		state->new_usertype<Resource>("Resource", "use", &Resource::use);

		state->new_usertype<Clock>("Clock", "getElapsedTime", &Clock::getElapsedTime, "use", &Clock::use);

		sol::constructor_list<sol::types<std::string>> costume_constructors;
		state->new_usertype<Costume>("Costume", costume_constructors);

		sol::constructor_list<sol::types<std::string, unsigned int>> font_costructors;
		state->new_usertype<Font>("Font", font_costructors);

		sol::constructor_list<sol::types<std::string>> sound_constructors;
		state->new_usertype<Sound>("Sound", sound_constructors, "use", &Sound::use);

		sol::constructor_list<sol::types<std::string>> script_constructors;
		state->new_usertype<Script>("Script", script_constructors);

		sol::constructor_list<sol::types<std::string, bool, int>> music_constructors;
		state->new_usertype<Music>("Music", music_constructors, "halt", &Music::halt, 
									"stop", &Music::stop, "resume", &Music::resume, "use", &Music::use);

		script->state["init"]();
		updatefunction = script->state["update"];
	}


	void Scriptable::update(const float & deltaTime)
	{
		bPerson = basePerson;
		updatefunction(deltaTime);
	}
}