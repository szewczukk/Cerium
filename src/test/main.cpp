#include "../include/Cerium/vec2.hpp"
#include "../include/Cerium/Window.hpp"

#include <iostream>

int main()
{
    auto & w = cerium::Window::instance();

    std::cout << w.getSize() << std::endl;

    w.setSize({1024, 768});
    w.setTitle("Cerium");

    std::cout << w.getSize() << std::endl;

    w.init();

    return 0;
}