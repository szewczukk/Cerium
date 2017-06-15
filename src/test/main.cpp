#include "../include/Cerium/vec2.hpp"
#include "../include/Cerium/Window.hpp"
#include "../include/Cerium/EventManager.hpp"
#include "../include/Cerium/Act.hpp"

#include <rapidxml.hpp>
#include <rapidxml_utils.hpp>

#include <iostream>

cerium::vec2 size_of_window()
{
    rapidxml::file <> file("settings.xml");
    rapidxml::xml_document<> settings;
    settings.parse<0>(file.data());

    rapidxml::xml_node <> * size = settings.first_node("settings")->first_node("size");

    int width = atoi(size->first_attribute("width")->value());
    int height = atoi(size->first_attribute("height")->value());
    return {width, height};
}

int main()
{
    cerium::Window::setSize(size_of_window());
    cerium::Window::setTitle("Cerium");

    cerium::Window::init();

    std::cout << cerium::Window::getSize() << std::endl;
    while(!cerium::EventManager::isWindowClosed())
    {
        cerium::EventManager::pollEvents();
        cerium::Window::clear();

        cerium::Window::render();
    }

    return 0;
}