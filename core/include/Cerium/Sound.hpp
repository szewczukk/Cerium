#ifndef CERIUM_SOUNDS_HPP
#define CERIUM_SOUNDS_HPP

#include "Resource.hpp"

#include <SDL2/SDL_mixer.h>

#include <string>

namespace cerium
{
    class Sound : public Resource
    {
    public:
        /*
            ^[name][Sound]
            ^[class][Sound]
            ^[description][Loading sound from res/sounds/ catalogue]
            ^[argument]<path>[Name and extension of sound to load]
         */
        Sound(const std::string & path, const int & volume);
        /*
            ^[name][~Sound]
            ^[class][Sound]
            ^[description][Deleting sound]
         */
        ~Sound();
        /*
            ^[name][use]
            ^[class][Sound]
            ^[description][Playing sound]
         */
        void use(void) override;
    private:
        Mix_Chunk * chunk;
    };
}

#endif