#include "../include/Cerium/EventManager.hpp"

namespace cerium
{
    bool EventManager::isWindowClosed(void)
    {
        return instance().event->type == SDL_QUIT;
    }


    bool EventManager::isKeyPressed(const int & code)
    {
        if(SDL_GetKeyboardState(NULL)[code]) return true;
        return false;
    }


    void EventManager::pollEvents(void)
    {
        SDL_PollEvent(instance().event);
    }


    EventManager & EventManager::instance(void)
    {
        static EventManager eventManager;
        return eventManager;
    }


    EventManager::EventManager(void)
    {
        event = new SDL_Event;
    }


    EventManager::~EventManager(void)
    {
        delete event;
    }
}