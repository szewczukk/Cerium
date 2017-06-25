#include "../include/Cerium/TextureSource.hpp"

namespace cerium
{
    TextureSource::TextureSource(const std::string & path)
    {
        IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF | IMG_INIT_WEBP);

        surface = IMG_Load(path.c_str());

        IMG_Quit();
    }

    TextureSource::~TextureSource()
    {
        SDL_FreeSurface(surface);
    }
}