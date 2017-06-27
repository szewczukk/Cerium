#ifndef CERIUM_BUTTON_HPP
#define CERIUM_BUTTON_HPP

#include "VertexArray.hpp"
#include "Label.hpp"
#include "ResourceManager.hpp"
#include "EventManager.hpp"
#include "Prop.hpp"

#include <iostream>

namespace cerium
{
    class Button : public Prop
    {
    public:
        Button(Person * basePerson, Prop * parent, const std::string & name,
               const vec4 & normalTextColor, const vec4 & hoveredTextColor,
               const vec4 & normalBackgroundColor, const vec4 & hoveredBackgroundColor,
               const std::string & text, Font * font) : Prop(basePerson, parent, name)
        {
            addChild(new VertexArray(basePerson, this, "background", normalBackgroundColor, false));
            addChild(new VertexArray(basePerson, this, "text", {255}, true));
            addChild(new Label(basePerson, this, "label", font, text, normalTextColor));

            this->m_normalBackground = normalBackgroundColor;
            this->m_normalText = normalTextColor;
            this->m_hoveredBackground = hoveredBackgroundColor;
            this->m_hoveredText = hoveredTextColor;
            this->m_isClicked = false;
            this->m_isHovered = false;
        }
        virtual void update(const float & deltaTime) override
        {
            Prop::update(deltaTime);

            SDL_Point p;
            p.x = (int)EventManager::getMousePosition().x;
            p.y = (int)EventManager::getMousePosition().y;

            SDL_Rect r;
            r.x = (int)getPerson().getPosition().x;
            r.y = (int)getPerson().getPosition().y;
            r.w = (int)getPerson().getSize().x;
            r.h = (int)getPerson().getSize().y;

            if(SDL_PointInRect(&p, &r))
            {
                dynamic_cast<VertexArray*>(getChild("background"))->setColor(m_hoveredBackground);
                dynamic_cast<Label*>(getChild("label"))->setColor(m_hoveredText);
                m_isHovered = true;
                m_isClicked = EventManager::isMouseButtonClicked(SDL_BUTTON_LEFT);
            } else {
                dynamic_cast<VertexArray*>(getChild("background"))->setColor(m_normalBackground);
                dynamic_cast<Label*>(getChild("label"))->setColor(m_normalText);
                m_isHovered = false;
            }
        }
        bool isHovered()
        {
            return m_isHovered;
        }
        bool isClicked()
        {
            return m_isClicked;
        }
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