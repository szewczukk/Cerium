#include "../include/Cerium/Button.hpp"

#include "../include/Cerium/Person.hpp"

namespace cerium
{
    Button::Button(Person * basePerson, Prop * parent, const std::string & name,
                   const vec4 & normalTextColor, const vec4 & hoveredTextColor,
                   const vec4 & normalBackgroundColor, const vec4 & hoveredBackgroundColor,
                   const std::string & text, Font * font)
                   : Prop(basePerson, parent, name)
    {
        addChild(new VertexArray(basePerson, this, "background", normalBackgroundColor, false));
        addChild(new Label(basePerson, this, "label", font, text, normalTextColor));
        addChild(new VertexArray(basePerson, this, "text", {255}, true));

        this->m_normalBackground = normalBackgroundColor;
        this->m_normalText = normalTextColor;
        this->m_hoveredBackground = hoveredBackgroundColor;
        this->m_hoveredText = hoveredTextColor;
        this->m_isClicked = false;
        this->m_isHovered = false;
    }


    void Button::update(const float & deltaTime)
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
			if (!m_isHovered)
			{
				dynamic_cast<VertexArray*>(getChild("background"))->setColor(m_hoveredBackground);
				dynamic_cast<Label*>(getChild("label"))->setColor(m_hoveredText);
				m_isHovered = true;
			}
			else
			{
				m_isClicked = EventManager::isMouseButtonClicked(SDL_BUTTON_LEFT);
			}
        } 
		else 
		{
			if (m_isHovered)
			{
				dynamic_cast<VertexArray*>(getChild("background"))->setColor(m_normalBackground);
				dynamic_cast<Label*>(getChild("label"))->setColor(m_normalText);
				m_isHovered = false;
				m_isClicked = false;
			}
        }
    }


    bool Button::isHovered()
    {
        return m_isHovered;
    }


    bool Button::isClicked()
    {
        return m_isClicked;
    }
}