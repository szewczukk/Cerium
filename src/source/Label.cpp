#include "../include/Cerium/Label.hpp"

#include "../include/Cerium/Font.hpp"

namespace cerium
{
    Label::Label(Person * basePerson, Font * font, const std::string & text, float r, float g, float b, float a) : Prop(basePerson)
    {
        SDL_Surface * surface = TTF_RenderText_Blended(font->font, text.c_str(), {r, g, b, a});

        glGenBuffers(1, &texture);

        glBindTexture(GL_TEXTURE_2D, texture);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

        int colorMode = GL_RGB;
        if (surface->format->BytesPerPixel == 4)
            colorMode = GL_RGBA;

        glTexImage2D(GL_TEXTURE_2D, 0, colorMode, surface->w, surface->h, 0, colorMode, GL_UNSIGNED_BYTE, surface->pixels);
        glGenerateMipmap(GL_TEXTURE_2D);

        SDL_FreeSurface(surface);

        glBindTexture(GL_TEXTURE_2D, 0);
    }


    Label::~Label()
    {
        glDeleteTextures(1, &texture);
    }


    void Label::update(const float & deltaTime)
    {

    }


    void Label::draw(void)
    {
        glActiveTexture(GL_TEXTURE_2D);

        glBindTexture(GL_TEXTURE_2D, texture);
    }
}