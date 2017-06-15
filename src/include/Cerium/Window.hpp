#ifndef CERIUM_WINDOW_HPP
#define CERIUM_WINDOW_HPP

#include <string>

#include <SDL2/SDL.h>
#include <GL/glew.h>

#include "vec2.hpp"

namespace cerium
{
    class Window
    {
    public:
        /*
            ^[name][setSize]
            ^[class][Window]
            ^[argument]<size>[Size of Window]
            ^[description][Setting size of Window by given vector]
        */
        static void setSize(const vec2 & size); //^header
        /*
            ^[name][setTitle]
            ^[class][Window]
            ^[argument]<title>[Title of Window]
            ^[description][Setting title of Window by given string]
        */
        static void setTitle(const std::string & title); //^header
        /*
            ^[name][getSize]
            ^[class][Window]
            ^[description][Getting size of Window as vector]
            ^[returns][Size of Window as vector]
        */
        static vec2 getSize(void); //^header
        /*
            ^[name][getTitle]
            ^[class][Window]
            ^[description][Getting title of Window as string]
            ^[returns][Title of Window as string]
        */
        static std::string getTitle(void); //^header
        /*
            ^[name][init]
            ^[class][Window]
            ^[description][Initializing libraries, interfaces and more]
        */
        static void init(void); //^header
        /*
            ^[name][clear]
            ^[class][Window]
            ^[description][Clearing window back buffer]
        */
        static void clear(void); //^header
        /*
            ^[name][render]
            ^[class][Window]
            ^[description][Rendering front buffer, swapping buffers]
        */
        static void render(void); //^header
    private:
        Window(void);
        ~Window(void);

        Window(const Window & other) = delete;
        void operator=(const Window & other) = delete;

        static Window & instance(void);
    private:
        SDL_Window * window;
        SDL_GLContext context;

        std::string title;
        vec2 size;
    };
}

#endif