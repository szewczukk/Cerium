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

	template<class T>
	void l_add_resource_to_manager(const std::string & name, T * resource)
	{
		ResourceManager::add(name, resource);
	}

	template<class T>
	void l_add_child_to_prop(Prop * prop, T * child)
	{
		prop->addChild(child);
	}

	template<class T>
	void l_add_prop_to_person(Person * person, T * prop)
	{
		person->addProp(prop);
	}


	Act * l_getBaseAct(void)
	{
		return bPerson->getBaseAct();
	}

	bool l_isHovered()
	{
		return bPerson->isHovered();
	}

	bool l_isClicked()
	{
		bool a = bPerson->isClicked();
		return a;
	}


	Scriptable::Scriptable(Person * basePerson, Prop * parent, const std::string & name, Script * script)
		: Prop(basePerson, parent, name)
	{
		bPerson = basePerson;
		this->state = &script->state;


		//Scripting THIS element
		sol::table tis = state->create_named_table("this");
		tis.set_function("move", l_move);
		tis.set_function("rotate", l_rotate);

		tis.set_function("setPosition", l_setPosition);
		tis.set_function("setRotation", l_setRotation);
		tis.set_function("setSize", l_setSize);

		tis.set_function("getPosition", l_getPosition);
		tis.set_function("getRotation", l_getRotation);
		tis.set_function("getSize", l_getSize);

		tis.set_function("adddChild", l_addChild);
		tis.set_function("childExist", l_childExist);
		tis.set_function("getChild", l_getChild);

		tis.set_function("getProp", l_getProp);
		tis.set_function("getName", l_getName);

		tis.set_function("getAllChildren", l_getAllChildren);
		tis.set_function("getAllProps", l_getAllProps);

		tis.set_function("addProp", l_addProp);
		tis.set_function("propExist", l_propExist);

		tis.set_function("getParent", l_getParent);
		tis.set_function("getBaseAct", l_getBaseAct);

		tis.set_function("isHovered", l_isHovered);
		tis.set_function("isClicked", l_isClicked);

		tis.set_function("addPropToPerson", sol::overload(
			l_add_prop_to_person<Costumed>,
			l_add_prop_to_person<Scriptable>,
			l_add_prop_to_person<VertexArray>,
			l_add_prop_to_person<Label>,
			l_add_prop_to_person<Button>));

		tis.set_function("addChildToProp", sol::overload(
			l_add_child_to_prop<Costumed>,
			l_add_child_to_prop<Scriptable>,
			l_add_child_to_prop<VertexArray>,
			l_add_child_to_prop<Label>,
			l_add_child_to_prop<Button>));

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

		//Key scripting
		state->set("KEY_LEFT", SDL_SCANCODE_LEFT);
		state->set("KEY_RIGHT", SDL_SCANCODE_RIGHT);
		state->set("KEY_UP", SDL_SCANCODE_UP);
		state->set("KEY_DOWN", SDL_SCANCODE_DOWN);

		state->set("KEY_ESCAPE", SDL_SCANCODE_ESCAPE);
		state->set("KEY_F1", SDL_SCANCODE_F1);
		state->set("KEY_F2", SDL_SCANCODE_F2);
		state->set("KEY_F3", SDL_SCANCODE_F3);
		state->set("KEY_F4", SDL_SCANCODE_F4);
		state->set("KEY_F5", SDL_SCANCODE_F5);
		state->set("KEY_F6", SDL_SCANCODE_F6);
		state->set("KEY_F7", SDL_SCANCODE_F7);
		state->set("KEY_F8", SDL_SCANCODE_F8);
		state->set("KEY_F9", SDL_SCANCODE_F9);
		state->set("KEY_F10", SDL_SCANCODE_F10);
		state->set("KEY_F11", SDL_SCANCODE_F11);
		state->set("KEY_F12", SDL_SCANCODE_F12);

		state->set("KEY_GRAVE", SDL_SCANCODE_GRAVE);
		state->set("KEY_1", SDL_SCANCODE_1);
		state->set("KEY_2", SDL_SCANCODE_2);
		state->set("KEY_3", SDL_SCANCODE_3);
		state->set("KEY_4", SDL_SCANCODE_4);
		state->set("KEY_5", SDL_SCANCODE_5);
		state->set("KEY_6", SDL_SCANCODE_6);
		state->set("KEY_7", SDL_SCANCODE_7);
		state->set("KEY_8", SDL_SCANCODE_8);
		state->set("KEY_9", SDL_SCANCODE_9);
		state->set("KEY_7", SDL_SCANCODE_7);
		state->set("KEY_8", SDL_SCANCODE_8);
		state->set("KEY_9", SDL_SCANCODE_9);
		state->set("KEY_EQUALS", SDL_SCANCODE_EQUALS);
		state->set("KEY_BACKSPACE", SDL_SCANCODE_BACKSPACE);

		state->set("KEY_TAB", SDL_SCANCODE_TAB);
		state->set("KEY_Q", SDL_SCANCODE_Q);
		state->set("KEY_W", SDL_SCANCODE_W);
		state->set("KEY_E", SDL_SCANCODE_E);
		state->set("KEY_R", SDL_SCANCODE_R);
		state->set("KEY_T", SDL_SCANCODE_T);
		state->set("KEY_Y", SDL_SCANCODE_Y);
		state->set("KEY_U", SDL_SCANCODE_U);
		state->set("KEY_I", SDL_SCANCODE_I);
		state->set("KEY_O", SDL_SCANCODE_O);
		state->set("KEY_P", SDL_SCANCODE_P);
		state->set("KEY_LGUI", SDL_SCANCODE_LGUI);
		state->set("KEY_RGUI", SDL_SCANCODE_RIGHTBRACKET);
		state->set("KEY_BACKSLASH", SDL_SCANCODE_BACKSLASH);

		state->set("KEY_CAPSLOCK", SDL_SCANCODE_CAPSLOCK);
		state->set("KEY_A", SDL_SCANCODE_A);
		state->set("KEY_S", SDL_SCANCODE_S);
		state->set("KEY_D", SDL_SCANCODE_D);
		state->set("KEY_F", SDL_SCANCODE_F);
		state->set("KEY_G", SDL_SCANCODE_G);
		state->set("KEY_H", SDL_SCANCODE_H);
		state->set("KEY_J", SDL_SCANCODE_J);
		state->set("KEY_K", SDL_SCANCODE_K);
		state->set("KEY_L", SDL_SCANCODE_L);
		state->set("KEY_SEMICOLON", SDL_SCANCODE_SEMICOLON);
		state->set("KEY_APOSTROPHE", SDL_SCANCODE_APOSTROPHE);
		state->set("KEY_ENTER", SDL_SCANCODE_EXECUTE);

		state->set("KEY_LSHIFT", SDL_SCANCODE_LSHIFT);
		state->set("KEY_Z", SDL_SCANCODE_Z);
		state->set("KEY_X", SDL_SCANCODE_X);
		state->set("KEY_C", SDL_SCANCODE_C);
		state->set("KEY_V", SDL_SCANCODE_V);
		state->set("KEY_B", SDL_SCANCODE_B);
		state->set("KEY_N", SDL_SCANCODE_N);
		state->set("KEY_M", SDL_SCANCODE_M);
		state->set("KEY_COMMA", SDL_SCANCODE_COMMA);
		state->set("KEY_PERIOD", SDL_SCANCODE_PERIOD);
		state->set("KEY_SLASH", SDL_SCANCODE_SEMICOLON);
		state->set("KEY_RSHIFT", SDL_SCANCODE_RSHIFT);

		state->set("KEY_LCTRL", SDL_SCANCODE_LCTRL);
		state->set("KEY_ALT", SDL_SCANCODE_ALTERASE);
		state->set("KEY_SPACE", SDL_SCANCODE_SPACE);
		state->set("KEY_RCTRL", SDL_SCANCODE_RCTRL);

		state->set("MKEY_LEFT", SDL_BUTTON_LEFT);
		state->set("MKEY_RIGHT", SDL_BUTTON_RIGHT);

		//Managers scripting
		sol::table inputManager = state->create_named_table("eventManager");
		inputManager.set_function("isKeyPressed", &EventManager::isKeyPressed);
		inputManager.set_function("isWindowClosed", &EventManager::isWindowClosed);
		inputManager.set_function("isMouseButtonClicked", &EventManager::isMouseButtonClicked);
		inputManager.set_function("closeWindow", &EventManager::closeWindow);
		inputManager.set_function("getMousePosition", &EventManager::getMousePosition);

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
		resourceManager.set_function("add", sol::overload(
			&l_add_resource_to_manager<Script>,
			&l_add_resource_to_manager<Font>,
			&l_add_resource_to_manager<Costume>,
			&l_add_resource_to_manager<Clock>,
			&l_add_resource_to_manager<Music>));
		resourceManager.set_function("remove", &ResourceManager::remove);
		resourceManager.set_function("clear", &ResourceManager::clear);

		//Others
		state->new_usertype<Act>("Act",
			"draw", &Act::draw, "update", &Act::update,
			"add", &Act::add, "remove", &Act::remove,
			"clear", &Act::clear, "exist", &Act::exist, "get", &Act::get,
			"getAllPersons", &Act::getAllPersons, "getAllPersonsWithTag", &Act::getAllPersonsWithTag);

		state->new_usertype<vec2>("vec2", sol::constructors<vec2(float), vec2(float, float)>(),
			"x", &vec2::x, "y", &vec2::y,
			"getLength", &vec2::getLength,
			"normalize", &vec2::normalize, "normalizeSelf", &vec2::normalizeSelf);

		state->new_usertype<vec4>("vec4", sol::constructors<vec4(float), vec4(float, float, float, float)>(),
			"x", &vec4::x, "y", &vec4::y, "z", &vec4::z, "w", &vec4::w,
			"getLength", &vec4::getLength,
			"normalize", &vec4::normalize, "normalizeSelf", &vec4::normalizeSelf);

		//Person scripting
		auto person = state->new_usertype<Person>(
			"Person", sol::constructors<Person(const std::string &, Person*, Act*, const std::string &)>(),
			"setPosition", &Person::setPosition, "setRotation", &Person::setRotation,
			"setSize", &Person::setSize, "move", &Person::move, "rotate", &Person::rotate,
			"getPosition", &Person::getPosition, "getSize", &Person::getSize,
			"getRotation", &Person::getRotation,
			"getName", &Person::getName, 
			"propExist", &Person::propExist, "getProp", &Person::getProp);
		person.set_function("getParent", &Person::getParent);
		person.set_function("getTag", &Person::getTag);
		person.set_function("addChild", &Person::addChild);
		person.set_function("childExist", &Person::childExist);
		person.set_function("getChild", &Person::getChild);
		person.set_function("getAllChildren", &Person::getAllChildren);
		person.set_function("getAllProps", &Person::getAllProps);
		person.set_function("getBaseAct", &Person::getBaseAct);
		person.set_function("isHovered", &Person::isHovered);
		person.set_function("isClicked", &Person::isClicked);

		//Props scripting
		state->new_usertype<Prop>(
			"Prop", sol::constructors<Prop(Person*, Prop*, const std::string &)>(),
			"getName", &Prop::getName, "getPerson", &Prop::getPerson,
			"getParent", &Prop::getParent, "exist", &Prop::exist,
			"addChild", &Prop::addChild, "getChild", &Prop::getChild,
			"getAllChildren", &Prop::getAllChildren);

		state->new_usertype<Button>("Button", sol::constructors<Button(Person *, Prop *, const std::string &, const vec4 &,
			const vec4 &, const vec4 &, const vec4 &, const std::string &, Font *)>(),
			"isHovered", &Button::isHovered, "isClicked", &Button::isClicked,
			"getName", &Button::getName, "getPerson", &Button::getPerson,
			"getParent", &Button::getParent, "exist", &Button::exist,
			"addChild", &Button::addChild, "getChild", &Button::getChild,
			"getAllChildren", &Button::getAllChildren);

		state->new_usertype<Costumed>(
			"Costumed", sol::constructors<Costumed(Person *, Prop *, const std::string &, Costume *)>(),
			"getName", &Costumed::getName, "getPerson", &Costumed::getPerson,
			"getParent", &Costumed::getParent, "exist", &Costumed::exist,
			"addChild", &Costumed::addChild, "getChild", &Costumed::getChild,
			"getAllChildren", &Costumed::getAllChildren, "setTexture", &Costumed::setTexture);

		state->new_usertype<Label>(
			"Label", sol::constructors<Label(Person *, Prop *, const std::string &, Font *, const std::string &, const vec4 &)>(),
			"getName", &Label::getName, "getPerson", &Label::getPerson,
			"getParent", &Label::getParent, "exist", &Label::exist,
			"addChild", &Label::addChild, "getChild", &Label::getChild,
			"getAllChildren", &Label::getAllChildren, "setText", &Label::setText, 
			"setColor", &Label::setColor, "setFont", &Label::setFont);

		state->new_usertype<Scriptable>(
			"Scriptable", sol::constructors<Scriptable(Person *, Prop *, const std::string &, Script *)>(),
			"getName", &Scriptable::getName, "getPerson", &Scriptable::getPerson,
			"getParent", &Scriptable::getParent, "exist", &Scriptable::exist,
			"addChild", &Scriptable::addChild, "getChild", &Scriptable::getChild,
			"getAllChildren", &Scriptable::getAllChildren);

		state->new_usertype<VertexArray>(
			"VertexArray", sol::constructors<VertexArray(Person *, Prop *, const std::string &, const vec4 &)>(),
			"getName", &VertexArray::getName, "getPerson", &VertexArray::getPerson,
			"getParent", &VertexArray::getParent, "exist", &VertexArray::exist,
			"addChild", &VertexArray::addChild, "getChild", &VertexArray::getChild,
			"getAllChildren", &VertexArray::getAllChildren, "setColor", &VertexArray::setColor,
			"setIsTextured", &VertexArray::setIsTextured, "getColor", &VertexArray::getColor,
			"isTextured", &VertexArray::isTextured);

		//Resources scripting
		state->new_usertype<Resource>("Resource", "use", &Resource::use);

		state->new_usertype<Clock>("Clock", "getElapsedTime", &Clock::getElapsedTime, "use", &Clock::use);

		state->new_usertype<Costume>("Costume", sol::constructors<Costume(const std::string &)>());

		state->new_usertype<Font>("Font", sol::constructors<Font(const std::string &, const unsigned int &)>());

		state->new_usertype<Sound>("Sound", sol::constructors<Sound(const std::string &, const int &)>(), "use", &Sound::use);

		state->new_usertype<Script>("Script", sol::constructors<Script(const std::string &)>(), "run", &Script::run);

		state->new_usertype<Music>("Music", sol::constructors<Music(const std::string &, bool, const int &)>(), 
			"halt", &Music::halt, "stop", &Music::stop, "resume", &Music::resume, "use", &Music::use);

		script->state["init"]();
		updatefunction = script->state["update"];
	}


	void Scriptable::update(const float & deltaTime)
	{
		bPerson = basePerson;
		updatefunction(deltaTime);
	}
}