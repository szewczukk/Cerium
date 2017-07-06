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
#include "../include/Cerium/Texture.hpp"
#include "../include/Cerium/TextureSource.hpp"
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

        addProp(new cerium::Texture(this, nullptr, "texture", cerium::ResourceManager::get("texture")->cast_to<cerium::TextureSource>()));
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

        addProp(new cerium::RigidBody(this, nullptr, "rigidBody", 0, 1));
        addProp(new cerium::Button(this, nullptr, "name", {0, 0, 0, 255}, {255}, {255}, {0, 0, 0, 255}, "Exit", cerium::ResourceManager::get("font")->cast_to<cerium::Font>()));
        addProp(new cerium::Scriptable(this, nullptr, "script", "script.lua"));
    }
};

class MyAct : public cerium::Act
{
public:
    MyAct()
    {
        add(new Player("player", nullptr, this));
        add(new Other("other", nullptr, this));
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

int main()
{
    cerium::Window::setSize(size_of_window());
    cerium::Window::setTitle(title_of_window());

    cerium::Window::init();
    cerium::Camera::init();

    cerium::ResourceManager::add("texture", new cerium::TextureSource("texture.png"));
    cerium::ResourceManager::add("timer", new cerium::Clock);
    cerium::ResourceManager::add("font", new cerium::Font("font.ttf", 32));

    cerium::ActManager::add("main", new MyAct);
    cerium::ActManager::setCurrent("main");

    cerium::ResourceManager::add("fpsTimer", new cerium::Clock);
    cerium::ResourceManager::get("fpsTimer")->use();

    bool closed = false;

    int frameNumber = 0;

    while(!closed)
    {
        if(cerium::ResourceManager::get("fpsTimer")->cast_to<cerium::Clock>()->getElapsedTime() >= 1)
        {
            std::cout << "FPS counter: " << frameNumber << std::endl;
            frameNumber = 0;
            cerium::ResourceManager::get("fpsTimer")->use();
        }

        frameNumber++;

        cerium::ResourceManager::get("timer")->use();
        cerium::EventManager::pollEvents();
        cerium::Window::clear();

        if(cerium::ActManager::get("main")->get("other")->getProp("name")->cast_to<cerium::Button>()->isClicked())
        {
            closed = true;
        }
        cerium::ActManager::get("main")->get("player")->getProp("rigidBody")->cast_to<cerium::RigidBody>()->setStanding(
                cerium::ActManager::get("main")->get("player")->getPosition().y > 200);

        cerium::ActManager::updateCurrent(cerium::ResourceManager::get("timer")->cast_to<cerium::Clock>()->getElapsedTime());
        cerium::ActManager::drawCurrent();

        cerium::Window::render();
    }

    return 0;
}