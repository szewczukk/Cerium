#include "../include/Cerium/Scriptable.hpp"

#include "../include/Cerium/Person.hpp"

#include "../include/Cerium/Camera.hpp"
#include "../include/Cerium/EventManager.hpp"

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

        sol::constructors<sol::types<>, sol::types<float>, sol::types<float, float>> vector_constructors;
        state.new_usertype<vec2>("vec2", vector_constructors,
                                 "x", &vec2::x, "y", &vec2::y,
                                 "getLength", &vec2::getLength,
                                 "normalize", &vec2::normalize, "normalizeSelf", &vec2::normalizeSelf);

        state.set_function("move", l_move);
        state.set_function("rotate", l_rotate);

        state.set_function("setPosition", l_setPosition);
        state.set_function("setRotation", l_setRotation);

        state.set_function("isKeyPressed", &EventManager::isKeyPressed);
        state.set_function("isWindowClosed", &EventManager::isWindowClosed);
        state.set_function("isMouseButtonClicked", &EventManager::isMouseButtonClicked);
        state.set_function("closeWindow", &EventManager::closeWindow);

        sol::table camera = state.create_named_table("camera");
        camera.set_function("setPosition", &Camera::setPosition);

        state["init"]();
    }


    void Scriptable::update(const float & deltaTime)
    {
        bPerson = basePerson;
        state["update"](deltaTime);
    }
}