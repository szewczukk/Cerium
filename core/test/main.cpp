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
#include "../include/Cerium/DebugLog.hpp"

#include "../include/Cerium/Script.hpp"

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
        addProp(new cerium::Scriptable(this, nullptr, "script", cerium::ResourceManager::get("playerScript")->cast_to<cerium::Script>()));
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

        addProp(new cerium::Scriptable(this, nullptr, "script", cerium::ResourceManager::get("script")->cast_to<cerium::Script>()));
        addProp(new cerium::Button(this, nullptr, "button", {0, 0, 0, 255}, {255}, {255}, {0, 0, 0, 255}, "Exit",
                                   cerium::ResourceManager::get("font")->cast_to<cerium::Font>()));
    }
};

rapidxml::file <> file("settings.xml");
rapidxml::xml_document<> settings;


cerium::vec2 size_of_window()
{
    rapidxml::xml_node <> * size = settings.first_node("settings")->first_node("size");

    int width = atoi(size->first_attribute("width")->value());
    int height = atoi(size->first_attribute("height")->value());
    return { (float)width, (float)height};
}


std::string title_of_window()
{
    rapidxml::xml_node <> * caption = settings.first_node("settings")->first_node("caption");

    return caption->first_attribute("title")->value();
}


bool is_debug_mode()
{
    std::string value = settings.first_node("settings")->first_attribute("debug_mode")->value();
    return value == "True";
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
        else if (type == "script")
        {
            cerium::ResourceManager::add(name, new cerium::Script(d->first_attribute("path")->value()));
        }
    }
}


void load_scenes()
{
    rapidxml::file<> file("scenes.xml");
}


int main()
{
    settings.parse<0>(file.data());

    bool debug_mode = is_debug_mode();

    std::cout << debug_mode << std::endl;

    cerium::Window::setSize(size_of_window());
    cerium::Window::setTitle(title_of_window());

    cerium::Window::init();
    cerium::Camera::init();

    cerium::DebugLog::init();

    load_resources();

    int frames = 0;

    if (debug_mode)
    {
        cerium::ResourceManager::add("fpsTimer", new cerium::Clock);
        cerium::ResourceManager::get("fpsTimer")->use();
    }

    cerium::ActManager::add("main");
    cerium::ActManager::get("main")->add(new Player("player", nullptr, cerium::ActManager::get("main")));
    cerium::ActManager::get("main")->add(new Other("other", nullptr, cerium::ActManager::get("main")));

    cerium::ActManager::setCurrent("main");

    while(!cerium::EventManager::isWindowClosed())
    {
        if(debug_mode)
        {
            frames++;
            if(cerium::ResourceManager::get("fpsTimer")->cast_to<cerium::Clock>()->getElapsedTime() > 1)
            {
                std::cout << "FPS " << frames << std::endl;
                frames = 0;
                cerium::ResourceManager::get("fpsTimer")->use();
            }
        }

        cerium::ResourceManager::get("timer")->use();
        cerium::EventManager::pollEvents();
        cerium::Window::clear();

        cerium::ActManager::get("main")->get("player")->getProp("rigidBody")->cast_to<cerium::RigidBody>()->setStanding(
                cerium::ActManager::get("main")->get("player")->getPosition().y > 200);

        cerium::ActManager::updateCurrent(cerium::ResourceManager::get("timer")->cast_to<cerium::Clock>()->getElapsedTime());
        cerium::ActManager::drawCurrent();

        cerium::DebugLog::update();

        cerium::Window::render();
    }

    return 0;
}