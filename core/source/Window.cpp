#include "../include/Cerium/Window.hpp"

#include "../include/Cerium/ResourceManager.hpp"
#include "../include/Cerium/ShaderProgram.hpp"

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


    void Window::clear(void)
    {
        glClearColor(0.5f, 0.2f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }


    void Window::render(void)
    {
        SDL_GL_SwapWindow(instance().window);
    }


    void Window::init(void)
    {
        SDL_Init(SDL_INIT_EVERYTHING);

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

        glewExperimental = GL_TRUE;
        glewInit();

        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        cerium::ResourceManager::add("spriteShader", new cerium::ShaderProgram("spriteVertexShader.glsl", "spriteFragmentShader.glsl"));
    }
}