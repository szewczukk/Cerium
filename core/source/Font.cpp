#include "../include/Cerium/Font.hpp"
#include "../include/Cerium/DebugLog.hpp"

namespace cerium
{
    Font::Font(const std::string & path, const unsigned int & size)
    {
        std::string filePath = "res/fonts/" + path;

        font = TTF_OpenFont(filePath.c_str(), size);

        if(font == NULL)
        {
            cerium::DebugLog::add(filePath + " font loading error!");
        }
    }


    Font::~Font()
    {
        TTF_CloseFont(font);
    }
}