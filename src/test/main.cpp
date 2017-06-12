#include "../include/Cerium/vec2.hpp"
#include "../include/Cerium/Window.hpp"
#include "../include/Cerium/EventManager.hpp"

#include <iostream>

int main()
{
    cerium::Window::setSize({1024, 768});
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