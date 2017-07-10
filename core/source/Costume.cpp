#include "../include/Cerium/Costume.hpp"
#include "../include/Cerium/DebugLog.hpp"

namespace cerium
{
    Costume::Costume(const std::string & path)
    {
        IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF | IMG_INIT_WEBP);

        std::string filePath = "res/images/" + path;

        surface = IMG_Load(filePath.c_str());

        if(surface == NULL)
        {
            cerium::DebugLog::add(filePath + " texture loading error!");
        }

        IMG_Quit();
    }


    Costume::~Costume()
    {
        SDL_FreeSurface(surface);
    }
}