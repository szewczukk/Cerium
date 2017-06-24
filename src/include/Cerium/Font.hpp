#ifndef CERIUM_FONT_HPP
#define CERIUM_FONT_HPP

#include <SDL2/SDL_ttf.h>

#include <string>

#include "Resource.hpp"

namespace cerium
{
    class Label;
    class Font : public Resource
    {
    public:
        Font(const std::string & path, const unsigned int & size);
        ~Font();

        virtual void use(void) override {};
    private:
        TTF_Font * font;

        friend class Label;
    };
}

#endif