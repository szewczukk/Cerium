#include "../include/Cerium/vec2.hpp"
#include "../include/Cerium/Window.hpp"
#include "../include/Cerium/EventManager.hpp"
#include "../include/Cerium/Act.hpp"
#include "../include/Cerium/VertexArray.hpp"
#include "../include/Cerium/Prop.hpp"
#include "../include/Cerium/Act.hpp"
#include "../include/Cerium/Camera.hpp"
#include "../include/Cerium/ActManager.hpp"
#include "../include/Cerium/ResourceManager.hpp"
#include "../include/Cerium/ShaderProgram.hpp"
#include "../include/Cerium/Person.hpp"

#include <rapidxml.hpp>
#include <rapidxml_utils.hpp>

#include <iostream>

class Player : public cerium::Person
{
public:
    Player(cerium::Act & baseAct) : cerium::Person(baseAct)
    {
        setPosition({10});
        setSize({64});
        addProp(new cerium::VertexArray(this));
    }

    virtual void draw(void) override
    {
        cerium::Person::draw();
    }

    virtual void update(const float & deltaTime) override
    {
        cerium::Person::update(deltaTime);

        if(cerium::EventManager::isKeyPressed(SDL_SCANCODE_LEFT)) move({-1, 0});
        if(cerium::EventManager::isKeyPressed(SDL_SCANCODE_RIGHT)) move({ 1, 0});
    }

    virtual void setPosition(const cerium::vec2 & position) override
    {
        cerium::Person::setPosition(position);
    }

    virtual void setRotation(const float & position) override
    {
        cerium::Person::setRotation(position);
    }
    virtual void setSize(const cerium::vec2 & size) override
    {
        cerium::Person::setSize(size);
    }
};

class MyAct : public cerium::Act
{
public:
    MyAct()
    {
        add("player", new Player(*this));
    }
    virtual void update(const float & deltaTime) override
    {
        cerium::Act::update(deltaTime);
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

int main()
{
    cerium::Window::setSize(size_of_window());
    cerium::Window::setTitle("Cerium");

    cerium::Window::init();

    cerium::ActManager::add("main", new MyAct);

    cerium::ResourceManager::add("shader", new cerium::ShaderProgram("vertexShader.glsl", "fragmentShader.glsl"));

    cerium::Camera::init();

    std::cout << cerium::Window::getSize() << std::endl;
    while(!cerium::EventManager::isWindowClosed())
    {
        cerium::EventManager::pollEvents();
        cerium::Window::clear();

        cerium::ResourceManager::get("shader")->use();

        cerium::Camera::update(dynamic_cast<cerium::ShaderProgram*>(cerium::ResourceManager::get("shader")));

        cerium::ActManager::get("main")->update(1.6);
        cerium::ActManager::get("main")->draw();

        cerium::Window::render();
    }

    return 0;
}