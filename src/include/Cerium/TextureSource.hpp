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
        TextureSource(const std::string & path);
        ~TextureSource();

        virtual void use(void) override;
    private:
        SDL_Surface * surface;

        friend class Texture;
    };
}

#endif