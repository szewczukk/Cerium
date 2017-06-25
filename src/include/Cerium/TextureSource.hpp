#ifndef CERIUM_TEXTURESOURCE_HPP
#define CERIUM_TEXTURESOURCE_HPP

#include <string>

#include <SDL2/SDL_image.h>

#include "Resource.hpp"

namespace cerium
{
    class Texture;
    class TextureSource : public Resource
    {
    public:
        /*
            ^[name][TextureSource]
            ^[class][TextureSource]
            ^[description][Loading source of Texture]
            ^[argument]<path>[Relative path to Texture]
         */
        TextureSource(const std::string & path); //^header
        /*
            ^[name][~TextureSource]
            ^[class][TextureSource]
            ^[description][Deleting source of Texture]
         */
        ~TextureSource(); //^header

        virtual void use(void) override {};
    private:
        SDL_Surface * surface;

        friend class Texture;
    };
}

#endif