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
        Button(Person * basePerson, Prop * parent, const std::string & name) : Prop(basePerson, parent, name)
        {
            addChild(new VertexArray(basePerson, this, "background", {255}, false));
            addChild(new VertexArray(basePerson, this, "text", {255}, true));
            addChild(new Label(basePerson, this, "label", dynamic_cast<Font*>(ResourceManager::get("font")), "Button", {0}));
        }
        virtual void update(const float & deltaTime) override
        {
            Prop::update(deltaTime);

            SDL_Point p;
            p.x = EventManager::getMousePosition().x;
            p.y = EventManager::getMousePosition().y;

            SDL_Rect r;
            r.x = getPerson().getPosition().x;
            r.y = getPerson().getPosition().y;
            r.w = getPerson().getSize().x;
            r.h = getPerson().getSize().y;

            if(SDL_PointInRect(&p, &r))
            {
                dynamic_cast<VertexArray*>(getChild("background"))->setColor({0, 0, 0, 255});
                dynamic_cast<Label*>(getChild("label"))->setColor({255});
            } else {
                dynamic_cast<VertexArray*>(getChild("background"))->setColor({255});
                dynamic_cast<Label*>(getChild("label"))->setColor({0});
            }
        }
    };
}

#endif