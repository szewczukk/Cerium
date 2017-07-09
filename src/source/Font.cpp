#include "../include/Cerium/Font.hpp"

namespace cerium
{
    Font::Font(const std::string & path, const unsigned int & size)
    {
        TTF_Init();

        std::string filePath = "res/fonts/" + path;

        font = TTF_OpenFont(filePath.c_str(), size);
    }


    Font::~Font()
    {
        TTF_CloseFont(font);
        TTF_Quit();
    }
}