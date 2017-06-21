#ifndef CERIUM_TEXTURE_HPP
#define CERIUM_TEXTURE_HPP

#include <GL/glew.h>

#include "Prop.hpp"

namespace cerium
{
    class Person;
    class TextureSource;
    class Texture : public Prop
    {
    public:
        Texture(Person * basePerson, TextureSource * source);
        ~Texture();

        virtual void update(const float & deltaTime) override;
        virtual void draw(void) override;
    private:
        GLuint texture;
    };
}

#endif