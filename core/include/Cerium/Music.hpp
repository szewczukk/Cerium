#ifndef CERIUM_MUSIC_HPP
#define CERIUM_MUSIC_HPP

#include <string>

#include <SDL2/SDL_mixer.h>

#include "Resource.hpp"

namespace cerium
{
    class Music : public Resource
    {
    public:
        /*
            ^[name][Music]
            ^[class][Music]
            ^[description][Loading music from res/music/ catalogue]
            ^[argument]<path>[Name and extension of file placed in res/music/]
            ^[argument]<looped>[Is the Music must to play in loop?]
            ^[argument]<volume>[Volume of music]
          */
        Music(const std::string & path, const bool & looped, const int & volume); //header
        /*
            ^[name][~Music]
            ^[class][Music]
            ^[description][Destroying music]
         */
        ~Music(); //header
        /*
            ^[name][halt]
            ^[class][Music]
            ^[description][Halting music]
         */
        void halt(void);
        /*
            ^[name][stop]
            ^[class][Music]
            ^[description][Stopping music]
         */
        void stop(void); //header
        /*
            ^[name][resume]
            ^[class][Music]
            ^[description][Resumes music]
         */
        void resume(void); //header
        /*
            ^[name][use]
            ^[class][Music]
            ^[description][Plays music]
         */
        void use(void) override; //header
    private:
        Mix_Music * music;
        bool looped;
    };
}

#endif