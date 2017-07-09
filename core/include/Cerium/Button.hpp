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
        Button(Person * basePerson, Prop * parent, const std::string & name,
               const vec4 & normalTextColor, const vec4 & hoveredTextColor,
               const vec4 & normalBackgroundColor, const vec4 & hoveredBackgroundColor,
               const std::string & text, Font * font);
        bool isHovered();
        bool isClicked();

        virtual void update(const float & deltaTime) override;
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