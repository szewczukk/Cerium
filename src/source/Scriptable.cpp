#include "../include/Cerium/Scriptable.hpp"

#include "../include/Cerium/Person.hpp"

#include "../include/Cerium/Camera.hpp"
#include "../include/Cerium/EventManager.hpp"
#include "../include/Cerium/Act.hpp"
#include "../include/Cerium/ActManager.hpp"
#include "../include/Cerium/Window.hpp"
#include "../include/Cerium/Resource.hpp"
#include "../include/Cerium/Font.hpp"
#include "../include/Cerium/Texture.hpp"
#include "../include/Cerium/Clock.hpp"

#include <fstream>

namespace cerium
{
    Person * bPerson;

    void l_move(const vec2 & relativePosition)
    {
        bPerson->move(relativePosition);
    }


    void l_setPosition(const vec2 & position)
    {
        bPerson->setPosition(position);
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


    Scriptable::Scriptable(Person * basePerson, Prop * parent, const std::string & name, const std::string & path)
            : Prop(basePerson, parent, name)
    {
        bPerson = basePerson;

        std::ifstream file(path.c_str());
        std::string content;
        std::string line;
        while(std::getline(file, line))
        {
            content += line + "\n";
        }

        file.close();

        state.open_libraries(sol::lib::base);
        state.script(content);

        state.set_function("move", l_move);
        state.set_function("rotate", l_rotate);

        state.set_function("setPosition", l_setPosition);
        state.set_function("setRotation", l_setRotation);

        state.set_function("getPosition", l_getPosition);

        state.set("KEY_LEFT", SDL_SCANCODE_LEFT);
        state.set("KEY_RIGHT", SDL_SCANCODE_RIGHT);
        state.set("KEY_UP", SDL_SCANCODE_UP);
        state.set("KEY_ESCAPE", SDL_SCANCODE_ESCAPE);
        state.set("KEY_DOWN", SDL_SCANCODE_DOWN);

        sol::table inputManager = state.create_named_table("inputManager");
        inputManager.set_function("isKeyPressed", &EventManager::isKeyPressed);
        inputManager.set_function("isWindowClosed", &EventManager::isWindowClosed);
        inputManager.set_function("isMouseButtonClicked", &EventManager::isMouseButtonClicked);
        inputManager.set_function("closeWindow", &EventManager::closeWindow);

        sol::table camera = state.create_named_table("camera");
        camera.set_function("move", &Camera::move);
        camera.set_function("setCameraPosition", &Camera::setPosition);

        sol::table actManager = state.create_named_table("ActManager");
        actManager.set_function("get", &ActManager::get);
        actManager.set_function("add", &ActManager::add);
        actManager.set_function("remove", &ActManager::remove);
        actManager.set_function("exist", &ActManager::exist);
        actManager.set_function("setCurrent", &ActManager::setCurrent);
        actManager.set_function("clear", &ActManager::clear);

        sol::table window = state.create_named_table("Window");
        window.set_function("setTitle", &Window::setTitle);
        window.set_function("setSize", &Window::setSize);
        window.set_function("getSize", &Window::getSize);
        window.set_function("getTitle", &Window::getTitle);
        window.set_function("init", &Window::init);

        sol::constructors<sol::types<>, sol::types<float>, sol::types<float, float>> vector_constructors;
        state.new_usertype<vec2>("vec2", vector_constructors,
                                 "x", &vec2::x, "y", &vec2::y,
                                 "getLength", &vec2::getLength, "normalize", &vec2::normalize, "normalizeSelf", &vec2::normalizeSelf);

        sol::constructors<sol::types<std::string, Person*, Act*>> person_constructor;
        auto person = state.new_usertype<Person>("Person", person_constructor,
                                   "setPosition", &Person::setPosition, "setRotation", &Person::setRotation,
                                   "setSize", &Person::setSize, "move", &Person::move, "rotate", &Person::rotate,
                                   "getPosition", &Person::getPosition, "getSize", &Person::getSize, "getRotation", &Person::getRotation,
                                   "getName", &Person::getName, "addProp", &Person::addProp,
                                   "propExist", &Person::propExist, "getProp", &Person::getProp);
        person.set_function("getParent", &Person::getParent);
        person.set_function("addChild", &Person::addChild);
        person.set_function("childExist", &Person::childExist);
        person.set_function("getChild", &Person::getChild);

        state.new_usertype<Act>("Act",
                                "draw", &Act::draw, "update", &Act::update,
                                "add", &Act::add, "remove", &Act::remove,
                                "clear", &Act::clear, "exist", &Act::exist, "get", &Act::get);

        sol::constructor_list <sol::types<Person*, Prop*, const std::string &>> propConstructors;
        auto prop = state.new_usertype<Prop>("Prop", propConstructors,
                                 "getName", &Prop::getName, "getPerson", &Prop::getPerson,
                                 "getParent", &Prop::getParent, "exist", &Prop::exist,
                                 "addChild", &Prop::addChild, "getChild", &Prop::getChild);

        auto resource = state.new_usertype<Resource>("Resource", "use", &Resource::use);

        state["init"]();
    }


    void Scriptable::update(const float & deltaTime)
    {
        bPerson = basePerson;
        state["update"](deltaTime);
    }
}