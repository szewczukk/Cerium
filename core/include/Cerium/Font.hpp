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
        /*
            ^[name][Font]
            ^[class][Font]
            ^[description][Creating TTF font]
            ^[argument]<path>[Relative path to TTF]
            ^[argument]<size>[Size of Font]
         */
        Font(const std::string & path, const unsigned int & size); //^header
        /*
           ^[name][~Font]
           ^[class][Font]
           ^[description][Deleting TTF font]
        */
        ~Font(); //^header
        /*
            ^[name][use]
            ^[class][Font]
            ^[description][Does nothing.]
         */
        virtual void use(void) override {}; //^header
    private:
        TTF_Font * font;

        friend class Label;
    };
}

#endif