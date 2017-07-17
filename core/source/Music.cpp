#include "../include/Cerium/Music.hpp"
#include "../include/Cerium/DebugLog.hpp"

namespace cerium
{
    Music::Music(const std::string &path, const bool & looped)
    {
        this->looped = looped;

        Mix_Init(MIX_INIT_MP3 | MIX_INIT_OGG);
        Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);

        std::string filePath = "res/music/" + path;

        Mix_VolumeMusic(50);
        music = Mix_LoadMUS(filePath.c_str());

        if(music == NULL || music == nullptr)
        {
            DebugLog::add(filePath + " music loading error");
        }

        Mix_Quit();
    }


    Music::~Music()
    {
        Mix_FreeMusic(music);
    }


    void Music::halt(void)
    {
        Mix_HaltMusic();
    }


    void Music::resume(void)
    {
        Mix_ResumeMusic();
    }


    void Music::stop(void)
    {
        Mix_PauseMusic();
    }


    void Music::use()
    {
        if(!Mix_PlayingMusic())
        {
            Mix_PlayMusic(music, (int)looped);
        }
    }
}