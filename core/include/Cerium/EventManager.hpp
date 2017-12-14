#ifndef CERIUM_EVENTMANAGER_HPP
#define CERIUM_EVENTMANAGER_HPP

#include <SDL_events.h>

#include "vec2.hpp"

namespace cerium
{
    class EventManager
    {
    public:
        /*
            ^[name][isWindowClosed]
            ^[class][EventManager]
            ^[description][Returns true when the event of closing window are set]
            ^[returns][true or false]
        */
        static bool isWindowClosed(void); //^header
        /*
            ^[name][isKeyPressed]
            ^[class][EventManager]
            ^[description][Returns true when the key was pressed]
            ^[returns][true or false]
        */
        static bool isKeyPressed(const int & code); //^header
        /*
            ^[name][getMousePosition]
            ^[class][EventManager]
            ^[description][Returns relative to window position of mouse]
            ^[returns][position as vec2]
        */
        static vec2 getMousePosition(void); //^header
        /*
            ^[name][getRelativeMousePosition]
            ^[class][EventManager]
            ^[description][Returns relative to window relative to previous position of mouse]
            ^[returns][relative position as vec2]
        */
        static vec2 getRelativeMousePosition(void); //^header
        /*
            ^[name][pollEvents]
            ^[class][EventManager]
            ^[description][Catching events into event container]
        */
        static void pollEvents(void); //^header
        /*
            ^[name][isMouseButtonClicked]
            ^[class][EventManager]
            ^[description][Checking is the key with given id was pressed]
            ^[argument]<key>[Id of key to check]
            ^[returns][True when key was pressed or false when it isn't]
        */
        static bool isMouseButtonClicked(int key); //^header
        /*
            ^[name][closeWindow]
            ^[class][EventManager]
            ^[description][Pushing SDL_CLOSED event to container]
        */
        static void closeWindow(void); //^header
    private:
        static EventManager & instance(void);

        EventManager(void);

        EventManager(const EventManager & other) = delete;
        void operator=(const EventManager & other) = delete;
    private:
        SDL_Event event;
    };
}

#endif