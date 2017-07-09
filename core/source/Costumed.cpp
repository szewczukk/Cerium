#include "../include/Cerium/Costumed.hpp"

#include "../include/Cerium/Person.hpp"
#include "../include/Cerium/Costume.hpp"

namespace cerium
{
    Costumed::Costumed(Person * basePerson, Prop * parent, const std::string & name, Costume * source) : Prop(basePerson, parent, name)
    {
        glGenTextures(1, &texture);

        glBindTexture(GL_TEXTURE_2D, texture);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

        GLenum colorMode = GL_RGB;
        if (source->surface->format->BytesPerPixel == 4)
            colorMode = GL_RGBA;

        glTexImage2D(GL_TEXTURE_2D, 0, colorMode, source->surface->w, source->surface->h, 0, colorMode, GL_UNSIGNED_BYTE, source->surface->pixels);

        glBindTexture(GL_TEXTURE_2D, 0);
    }


    Costumed::~Costumed()
    {
        glDeleteTextures(1, &texture);
    }

    void Costumed::draw(void)
    {
        glBindTexture(GL_TEXTURE_2D, texture);
    }
}