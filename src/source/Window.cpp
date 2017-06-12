#include "../include/Cerium/Window.hpp"

namespace cerium
{
    Window & Window::instance(void)
    {
        static Window window;
        return window;
    }


    Window::Window(void)
    {
        m_title = "Default Cerium Window";
        m_size = {800, 600};
    }


    Window::~Window(void)
    {
        SDL_GL_DeleteContext(m_context);
        SDL_DestroyWindow(m_window);
    }


    void Window::setSize(const vec2 & size)
    {
        instance().m_size = size;
    }


    void Window::setTitle(const std::string & title)
    {
        instance().m_title = title;
    }


    vec2 Window::getSize(void)
    {
        return instance().m_size;
    }


    std::string Window::getTitle(void)
    {
        return instance().m_title;
    }


    void Window::clear(void)
    {
        glClearColor(0.5f, 0.2f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }


    void Window::render(void)
    {
        SDL_GL_SwapWindow(instance().m_window);
    }


    void Window::init(void)
    {
        SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);

        instance().m_window = SDL_CreateWindow(instance().m_title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                               (int) instance().m_size.x, (int) instance().m_size.y,
                                               SDL_WINDOW_OPENGL);
        instance().m_context = SDL_GL_CreateContext(instance().m_window);

        glewExperimental = GL_TRUE;
        glewInit();
    }
}