#include "../include/Cerium/vec2.hpp"
#include "../include/Cerium/Window.hpp"
#include "../include/Cerium/EventManager.hpp"
#include "../include/Cerium/Act.hpp"
#include "../include/Cerium/VertexArray.hpp"
#include "../include/Cerium/Scriptable.hpp"
#include "../include/Cerium/Camera.hpp"
#include "../include/Cerium/ActManager.hpp"
#include "../include/Cerium/ResourceManager.hpp"
#include "../include/Cerium/ShaderProgram.hpp"
#include "../include/Cerium/Person.hpp"
#include "../include/Cerium/Clock.hpp"
#include "../include/Cerium/Costumed.hpp"
#include "../include/Cerium/Costume.hpp"
#include "../include/Cerium/Font.hpp"
#include "../include/Cerium/Label.hpp"

#include "../include/Cerium/Button.hpp"
#include "../include/Cerium/RigidBody.hpp"

#include <rapidxml.hpp>
#include <rapidxml_utils.hpp>

class Player : public cerium::Person
{
public:
    Player(const std::string & name, cerium::Person * parent, cerium::Act * baseAct) : cerium::Person(name, parent, baseAct)
    {
        setPosition({150, 0});
        setSize({64});
        setRotation(0);

        addProp(new cerium::Costumed(this, nullptr, "texture", cerium::ResourceManager::get("texture")->cast_to<cerium::Costume>()));
        addProp(new cerium::RigidBody(this, nullptr, "rigidBody", 1, 1));
        addProp(new cerium::VertexArray(this, nullptr, "vertexArray", {1.0, 0.0, 1.0, 1.0}, true));
        addProp(new cerium::Scriptable(this, nullptr, "script", "player.lua"));
    }
};

class Other : public cerium::Person
{
public:
    Other(const std::string & name, cerium::Person * parent, cerium::Act * baseAct) : cerium::Person(name, parent, baseAct)
    {
        setPosition({10});
        setSize({64});
        setRotation(0);

        addProp(new cerium::Scriptable(this, nullptr, "script", "script.lua"));
        addProp(new cerium::Button(this, nullptr, "button", {0, 0, 0, 255}, {255}, {255}, {0, 0, 0, 255}, "Exit",
                                   cerium::ResourceManager::get("font")->cast_to<cerium::Font>()));
    }
};

cerium::vec2 size_of_window()
{
    rapidxml::file <> file("settings.xml");
    rapidxml::xml_document<> settings;
    settings.parse<0>(file.data());

    rapidxml::xml_node <> * size = settings.first_node("settings")->first_node("size");

    int width = atoi(size->first_attribute("width")->value());
    int height = atoi(size->first_attribute("height")->value());
    return { (float)width, (float)height};
}

std::string title_of_window()
{
    rapidxml::file <> file("settings.xml");
    rapidxml::xml_document<> settings;
    settings.parse<0>(file.data());

    rapidxml::xml_node <> * caption = settings.first_node("settings")->first_node("caption");

    return caption->first_attribute("title")->value();
}

void load_resources()
{
    rapidxml::file<> file("data.xml");
    rapidxml::xml_document<> document;
    document.parse<0>(file.data());

    rapidxml::xml_node<> * root = document.first_node("data");

    for(rapidxml::xml_node<> * d = root->first_node("resource"); d; d = d->next_sibling("resource"))
    {
        std::string name = d->first_attribute("name")->value();
        std::string type = d->first_attribute("type")->value();

        if(type == "costume")
        {
            cerium::ResourceManager::add(name, new cerium::Costume(d->first_attribute("path")->value()));
        }
        else if (type == "clock")
        {
            cerium::ResourceManager::add(name, new cerium::Clock);
        }
        else if (type == "font")
        {
            cerium::ResourceManager::add(name, new cerium::Font(d->first_attribute("path")->value(),
                                                                static_cast<unsigned int>(atoi(d->first_attribute("size")->value()))));
        }
    }
}

int main()
{
    cerium::Window::setSize(size_of_window());
    cerium::Window::setTitle(title_of_window());

    cerium::Window::init();
    cerium::Camera::init();

    load_resources();

    cerium::ActManager::add("main");
    cerium::ActManager::get("main")->add(new Player("player", nullptr, cerium::ActManager::get("main")));
    cerium::ActManager::get("main")->add(new Other("other", nullptr, cerium::ActManager::get("main")));

    cerium::ActManager::setCurrent("main");;

    while(!cerium::EventManager::isWindowClosed())
    {
        cerium::ResourceManager::get("timer")->use();
        cerium::EventManager::pollEvents();
        cerium::Window::clear();

        cerium::ActManager::get("main")->get("player")->getProp("rigidBody")->cast_to<cerium::RigidBody>()->setStanding(
                cerium::ActManager::get("main")->get("player")->getPosition().y > 200);

        cerium::ActManager::updateCurrent(cerium::ResourceManager::get("timer")->cast_to<cerium::Clock>()->getElapsedTime());
        cerium::ActManager::drawCurrent();

        cerium::Window::render();
    }

    return 0;
}