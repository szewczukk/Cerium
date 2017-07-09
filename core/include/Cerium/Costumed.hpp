#ifndef CERIUM_TEXTURE_HPP
#define CERIUM_TEXTURE_HPP

#include <GL/glew.h>
#include <SDL2/SDL_surface.h>

#include <string>

#include "Prop.hpp"

namespace cerium
{
    class Person;
    class Costume;
    class Costumed : public Prop
    {
    public:
        /*
            ^[name][Costumed]
            ^[class][Costumed]
            ^[description][Creating Costumed by source]
            ^[argument]<basePerson>[Person where the Label is]
            ^[argument]<parent>[Parent Prop of this Prop]
            ^[argument]<name>[Name of Prop]
            ^[argument]<source>[Source of Costumed]
         */
        Costumed(Person * basePerson, Prop * parent, const std::string & name, Costume * source); //^header
        /*
            ^[name][~Costumed]
            ^[class][Costumed]
            ^[description][Deleting Costumed]
         */
        ~Costumed(); //^header

        virtual void draw(void) override;
    private:
        GLuint texture;
    };
}

#endif