#include "../include/Cerium/Costume.hpp"
#include "../include/Cerium/DebugLog.hpp"

namespace cerium
{
    Costume::Costume(const std::string & path)
    {
        std::string filePath = "res/images/" + path;

        surface = IMG_Load(filePath.c_str());

		size.x = (int)surface->w;
		size.y = (int)surface->h;

        if(surface == NULL)
        {
            cerium::DebugLog::add(filePath + " texture loading error!");
        }
    }


    Costume::~Costume()
    {
        SDL_FreeSurface(surface);
    }


	vec2 Costume::getSize(void)
	{
		return size;
	}
}