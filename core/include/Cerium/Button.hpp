#ifndef CERIUM_BUTTON_HPP
#define CERIUM_BUTTON_HPP

#include "VertexArray.hpp"
#include "Label.hpp"
#include "ResourceManager.hpp"
#include "EventManager.hpp"
#include "Prop.hpp"

namespace cerium
{
    class Button : public Prop
    {
    public:
        /*
            ^[name][Button]
            ^[class][Button]
            ^[description][Creating new Label and two vertexArrays as child of Button]
            ^[argument]<basePerson>[Person where the Button is]
            ^[argument]<parent>[Parent of this Button]
            ^[argument]<name>[Name of Button]
            ^[argument]<normalTextColor>[Color of non-hovered text]
            ^[argument]<hoveredTextColor>[Color of hovered text]
            ^[argument]<normalBackgroundColor>[Color of Background of non-hovered button]
            ^[argument]<hoveredBackgroundColor>[Color of Background of hovered button]
            ^[argument]<text>[Text on Button]
            ^[argument]<Font>[Pointer to font]
         */
        Button(Person * basePerson, Prop * parent, const std::string & name, const vec4 & normalTextColor, const vec4 & hoveredTextColor, const vec4 & normalBackgroundColor, const vec4 & hoveredBackgroundColor, const std::string & text, Font * font); //^header
        /*
            ^[name][isHovered]
            ^[class][Button]
            ^[returns][True when the Button is not hovered or False when the Button is hovered]
         */
        bool isHovered(void); //^header
        /*
            ^[name][isClicked]
            ^[class][Button]
            ^[returns][True when the Button is hovered and clicked or False when is not]
         */
        bool isClicked(void); //^header
        /*
            ^[name][update]
            ^[class][Button]
            ^[returns][Updates state of Button (hover & clicked state)]
         */
        virtual void update(const float & deltaTime) override; //^header
    private:
        bool m_isHovered;
        bool m_isClicked;
        vec4 m_normalBackground;
        vec4 m_normalText;
        vec4 m_hoveredBackground;
        vec4 m_hoveredText;
    };
}

#endif