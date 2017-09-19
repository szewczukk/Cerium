#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "../include/Cerium/Window.hpp"

#include "../include/Cerium/ResourceManager.hpp"
#include "../include/Cerium/ShaderProgram.hpp"
#include "../include/Cerium/DebugLog.hpp"

namespace cerium
{
    Window & Window::instance(void)
    {
        static Window window;
        return window;
    }


    Window::Window(void)
    {
        title = "Default Cerium Window";
        size = {800, 600};
    }


    Window::~Window(void)
    {
        SDL_GL_DeleteContext(context);
        SDL_DestroyWindow(window);
    }


    void Window::setSize(const vec2 & size)
    {
        instance().size = size;
    }


    void Window::setTitle(const std::string & title)
    {
        instance().title = title;
    }


    vec2 Window::getSize(void)
    {
        return instance().size;
    }


    std::string Window::getTitle(void)
    {
        return instance().title;
    }


    void Window::clear(const float & r, const float & g, const float & b)
    {
        glClearColor(r, g, b, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }


    void Window::render(void)
    {
        SDL_GL_SwapWindow(instance().window);
    }


    void Window::init(void)
    {
        SDL_Init(SDL_INIT_EVERYTHING);
        Mix_Init(MIX_INIT_MP3 | MIX_INIT_OGG);
        Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
        IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF | IMG_INIT_WEBP);
        TTF_Init();

        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

        SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
        SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
        SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
        SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);

        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
        SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 4);

        instance().window = SDL_CreateWindow(instance().title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                               (int) instance().size.x, (int) instance().size.y,
                                               SDL_WINDOW_OPENGL);
        instance().context = SDL_GL_CreateContext(instance().window);

        if(instance().window == NULL)
        {
            cerium::DebugLog::add("Window creation error!");
        }
        if(instance().context == NULL)
        {
            cerium::DebugLog::add("Context creation error!");
        }

        glewExperimental = GL_TRUE;
        if(glewInit() != GLEW_OK)
        {
            cerium::DebugLog::add("GLEW initialization error!");
        }

        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    }
}