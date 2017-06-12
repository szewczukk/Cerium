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
            ^[name][instance]
            ^[class][Window]
            ^[returns][Static copy of Window instance]
        */
        static Window & instance(void);
        /*
            ^[name][setSize]
            ^[class][Window]
            ^[argument]<size>[Size of Window]
            ^[description][Setting size of Window by given vector]
        */
        static void setSize(const vec2 & size);
        /*
            ^[name][setTitle]
            ^[class][Window]
            ^[argument]<title>[Title of Window]
            ^[description][Setting title of Window by given string]
        */
        static void setTitle(const std::string & title);
        /*
            ^[name][getSize]
            ^[class][Window]
            ^[description][Getting size of Window as vector]
            ^[returns][Size of Window as vector]
        */
        static vec2 getSize(void);
        /*
            ^[name][getTitle]
            ^[class][Window]
            ^[description][Getting title of Window as string]
            ^[returns][Title of Window as string]
        */
        static std::string getTitle(void);
/*
            ^[name][init]
            ^[class][Window]
            ^[description][Initializing libraries, interfaces and more]
        */
        static void init(void);
    private:
        ~Window(void);
        Window(void);
    private:
        SDL_Window * m_window;
        SDL_GLContext m_context;

        std::string m_title;
        vec2 m_size;
    };
}

#endif