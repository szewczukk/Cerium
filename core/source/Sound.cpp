#include "../include/Cerium/Sound.hpp"

#include "../include/Cerium/DebugLog.hpp"

namespace cerium
{
    Sound::Sound(std::string &path)
    {
        std::string filePath = "res/sounds/" + path;

        chunk = Mix_LoadWAV(filePath.c_str());
    }


    Sound::~Sound()
    {
        Mix_FreeChunk(chunk);
    }


    void Sound::use(void)
    {
        Mix_PlayChannel(-1, chunk, 0);
    }
}