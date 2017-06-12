#include "../include/Cerium/vec2.hpp"
#include "../include/Cerium/Window.hpp"
#include "../include/Cerium/EventManager.hpp"

#include <iostream>

int main()
{
    std::cout << cerium::Window::getSize() << std::endl;

    cerium::Window::setSize({1024, 768});
    cerium::Window::setTitle("Cerium");

    std::cout << cerium::Window::getSize() << std::endl;

    cerium::Window::init();

    while(!cerium::EventManager::isWindowClosed())
    {
        cerium::EventManager::pollEvents();
    }

    return 0;
}