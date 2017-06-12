#include "../include/Cerium/EventManager.hpp"

namespace cerium
{
    bool EventManager::isWindowClosed(void)
    {
        return instance().m_event->type == SDL_QUIT;
    }


    void EventManager::pollEvents(void)
    {
        SDL_PollEvent(instance().m_event);
    }


    EventManager & EventManager::instance(void)
    {
        static EventManager eventManager;
        return eventManager;
    }


    EventManager::EventManager(void)
    {
        m_event = new SDL_Event;
    }


    EventManager::~EventManager(void)
    {
        delete m_event;
    }
}