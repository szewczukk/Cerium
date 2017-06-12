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
        static Window & instance(void);

        static void setSize(const vec2 & size);
        static void setTitle(const std::string & title);

        static vec2 getSize(void);
        static std::string getTitle(void);

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