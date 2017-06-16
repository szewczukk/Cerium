#ifndef CERIUM_EVENTMANAGER_HPP
#define CERIUM_EVENTMANAGER_HPP

#include <SDL2/SDL_events.h>

namespace cerium
{
    class EventManager
    {
    public:
        /*
            ^[name][isWindowClosed]
            ^[class][EventManager]
            ^[description][Returns true if the event of closing window are set]
            ^[returns][true or false]
        */
        static bool isWindowClosed(void); //^header
        /*
            ^[name][pollEvents]
            ^[class][EventManager]
            ^[description][Catching events into event container]
        */
        static void pollEvents(void); //^header
    private:
        static EventManager & instance(void);

        EventManager(void);
        ~EventManager(void);

        EventManager(const EventManager & other) = delete;
        void operator=(const EventManager & other) = delete;
    private:
        SDL_Event * event;
    };
}

#endif