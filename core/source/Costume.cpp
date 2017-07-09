#include "../include/Cerium/Costume.hpp"

namespace cerium
{
    Costume::Costume(const std::string & path)
    {
        IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF | IMG_INIT_WEBP);

        std::string filePath = "res/images/" + path;

        surface = IMG_Load(filePath.c_str());

        IMG_Quit();
    }


    Costume::~Costume()
    {
        SDL_FreeSurface(surface);
    }
}