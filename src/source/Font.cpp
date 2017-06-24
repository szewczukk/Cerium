#include "../include/Cerium/Font.hpp"

namespace cerium
{
    Font::Font(const std::string & path, const unsigned int & size)
    {
        TTF_Init();

        font = TTF_OpenFont(path.c_str(), size);
    }


    Font::~Font()
    {
        TTF_CloseFont(font);
        TTF_Quit();
    }
}