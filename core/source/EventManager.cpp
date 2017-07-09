#include "../include/Cerium/EventManager.hpp"

namespace cerium
{
    bool EventManager::isWindowClosed(void)
    {
        return instance().event.type == SDL_QUIT;
    }


    bool EventManager::isKeyPressed(const int & code)
    {
        return SDL_GetKeyboardState(NULL)[code] != 0;
    }


    void EventManager::pollEvents(void)
    {
        SDL_PollEvent(&instance().event);
    }


    EventManager & EventManager::instance(void)
    {
        static EventManager eventManager;
        return eventManager;
    }


    EventManager::EventManager(void)
    {
        event = SDL_Event();
    }


    vec2 EventManager::getMousePosition(void)
    {
        int x, y;
        SDL_GetMouseState(&x, &y);
        return {(float)x, (float)y};
    }


    vec2 EventManager::getRelativeMousePosition(void)
    {
        int x, y;
        SDL_GetRelativeMouseState(&x, &y);
        return {(float)x, (float)y};
    }


    bool EventManager::isMouseButtonClicked(int key)
    {
        return (instance().event.type == SDL_MOUSEBUTTONDOWN && instance().event.button.button == key);
    }


    void EventManager::closeWindow(void)
    {
        instance().event.type = SDL_QUIT;
    }
}