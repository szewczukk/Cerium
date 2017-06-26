#ifndef CERIUM_TEXTURE_HPP
#define CERIUM_TEXTURE_HPP

#include <GL/glew.h>
#include <SDL2/SDL_surface.h>

#include <string>

#include "Prop.hpp"

namespace cerium
{
    class Person;
    class TextureSource;
    class Texture : public Prop
    {
    public:
        /*
            ^[name][Texture]
            ^[class][Texture]
            ^[description][Creating Texture by source]
            ^[argument]<basePerson>[Person where the Label is]
            ^[argument]<parent>[Parent Prop of this Prop]
            ^[argument]<name>[Name of Prop]
            ^[argument]<source>[Source of Texture]
         */
        Texture(Person * basePerson, Prop * parent, const std::string & name, TextureSource * source); //^header
        /*
            ^[name][~Texture]
            ^[class][Texture]
            ^[description][Deleting Texture]
         */
        ~Texture(); //^header

        virtual void update(const float & deltaTime) override {};
        virtual void draw(void) override;
    private:
        GLuint texture;
    };
}

#endif