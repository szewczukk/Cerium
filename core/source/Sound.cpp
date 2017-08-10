#include "../include/Cerium/Sound.hpp"

#include "../include/Cerium/DebugLog.hpp"

namespace cerium
{
    Sound::Sound(const std::string & path, const int & volume)
    {
        std::string filePath = "res/sounds/" + path;

		Mix_VolumeChunk(chunk, volume);
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