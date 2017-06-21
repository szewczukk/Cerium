#include "../include/Cerium/Texture.hpp"

#include "../include/Cerium/Person.hpp"
#include "../include/Cerium/TextureSource.hpp"

namespace cerium
{
    Texture::Texture(Person * basePerson, TextureSource * source) : Prop(basePerson)
    {
        glGenBuffers(1, &texture);

        glBindTexture(GL_TEXTURE_2D, texture);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, source->surface->w, source->surface->h, 0, GL_BGRA, GL_UNSIGNED_BYTE, source->surface->pixels);
        glGenerateMipmap(GL_TEXTURE_2D);

        glBindTexture(GL_TEXTURE_2D, 0);
    }


    Texture::~Texture()
    {
        glDeleteTextures(1, &texture);
    }


    void Texture::update(const float & deltaTime)
    {

    }


    void Texture::draw(void)
    {
        glActiveTexture(GL_TEXTURE_2D);

        glBindTexture(GL_TEXTURE_2D, texture);
    }
}