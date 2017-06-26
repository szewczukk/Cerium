#ifndef CERIUM_LABEL_HPP
#define CERIUM_LABEL_HPP

#include <string>

#include <SDL2/SDL_ttf.h>
#include <GL/glew.h>

#include "Prop.hpp"
#include "vec4.hpp"

namespace cerium
{
    class Person;
    class Font;
    class Label : public Prop
    {
    public:
        /*
           ^[name][Label]
           ^[class][Label]
           ^[description][Creating Label]
           ^[argument]<basePerson>[Person where the Label is]
           ^[argument]<parent>[Parent Prop of this Prop]
           ^[argument]<name>[Name of Prop]
           ^[argument]<font>[Pointer to Font]
           ^[argument]<text>[Text of Label]
           ^[argument]<color>[Color of Label]
        */
        Label(Person * basePerson, Prop * parent, const std::string & name, Font * font, const std::string & text, const vec4 & color); //^header
        /*
           ^[name][~Label]
           ^[class][Label]
           ^[description][Deleting Label]
        */
        ~Label(); //^header
        /*
           ^[name][setText]
           ^[class][Label]
           ^[description][Updating text of Label]
           ^[argument]<text>[Text of Label]
        */
        void setText(const std::string & text); //^header
        /*
           ^[name][setColor]
           ^[class][Label]
           ^[description][Updating color of Label]
           ^[argument]<color>[Color of Label]
        */
        void setColor(const vec4 & color); //^header
        /*
           ^[name][setFont]
           ^[class][Label]
           ^[description][Updating font of Label]
           ^[argument]<font>[Pointer to Font]
        */
        void setFont(Font * font); //^header

        virtual void update(const float & deltaTime) override;
        virtual void draw(void) override;
    private:
        GLuint texture;
    private:
        vec4 color;
        Font * font;
        bool changed;
        std::string text;
    };
}

#endif