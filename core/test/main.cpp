#include "../include/Cerium/vec2.hpp"
#include "../include/Cerium/Window.hpp"
#include "../include/Cerium/EventManager.hpp"
#include "../include/Cerium/Act.hpp"
#include "../include/Cerium/VertexArray.hpp"
#include "../include/Cerium/Scriptable.hpp"
#include "../include/Cerium/Camera.hpp"
#include "../include/Cerium/ActManager.hpp"
#include "../include/Cerium/ResourceManager.hpp"
#include "../include/Cerium/ShaderProgram.hpp"
#include "../include/Cerium/Person.hpp"
#include "../include/Cerium/Clock.hpp"
#include "../include/Cerium/Costumed.hpp"
#include "../include/Cerium/Costume.hpp"
#include "../include/Cerium/Font.hpp"
#include "../include/Cerium/Label.hpp"

#include "../include/Cerium/Button.hpp"
#include "../include/Cerium/RigidBody.hpp"
#include "../include/Cerium/DebugLog.hpp"

#include "../include/Cerium/Script.hpp"

#include <rapidxml.hpp>
#include <rapidxml_utils.hpp>

cerium::vec2 size_of_window()
{
    rapidxml::file <> file("settings.xml");
    rapidxml::xml_document<> settings;
    settings.parse<0>(file.data());

    rapidxml::xml_node <> * size = settings.first_node("settings")->first_node("size");

    int width = atoi(size->first_attribute("width")->value());
    int height = atoi(size->first_attribute("height")->value());
    return { (float)width, (float)height};
}


std::string title_of_window()
{
    rapidxml::file <> file("settings.xml");
    rapidxml::xml_document<> settings;
    settings.parse<0>(file.data());

    rapidxml::xml_node <> * caption = settings.first_node("settings")->first_node("caption");

    return caption->first_attribute("title")->value();
}


bool is_debug_mode()
{
    rapidxml::file <> file("settings.xml");
    rapidxml::xml_document<> settings;
    settings.parse<0>(file.data());

    std::string value = settings.first_node("settings")->first_attribute("debug_mode")->value();
    return value == "True";
}


void load_resources()
{
    rapidxml::file<> file("data.xml");
    rapidxml::xml_document<> document;
    document.parse<0>(file.data());

    rapidxml::xml_node<> * root = document.first_node("data");

    for(rapidxml::xml_node<> * d = root->first_node("resource"); d; d = d->next_sibling("resource"))
    {
        std::string name = d->first_attribute("name")->value();
        std::string type = d->first_attribute("type")->value();

        if(type == "costume")
        {
            cerium::ResourceManager::add(name, new cerium::Costume(d->first_attribute("path")->value()));
        }
        else if (type == "clock")
        {
            cerium::ResourceManager::add(name, new cerium::Clock);
        }
        else if (type == "font")
        {
            cerium::ResourceManager::add(name, new cerium::Font(d->first_attribute("path")->value(),
                                                                static_cast<unsigned int>(atoi(d->first_attribute("size")->value()))));
        }
        else if (type == "script")
        {
            cerium::ResourceManager::add(name, new cerium::Script(d->first_attribute("path")->value()));
        }
    }
}


void load_scenes(const cerium::vec4 & normalTextColor, const cerium::vec4 & hoveredTextColor,
                 const cerium::vec4 & normalBackgroundColor, const cerium::vec4 & hoveredBackgroundColor)
{
    rapidxml::file<> file("scenes.xml");
    rapidxml::xml_document<> document;
    document.parse<0>(file.data());

    rapidxml::xml_node <> * root = document.first_node("scenes");
    for(rapidxml::xml_node <> * scene = root->first_node("scene"); scene; scene=scene->next_sibling("scene"))
    {
        std::string sceneName = scene->first_attribute("name")->value();
        cerium::ActManager::add(sceneName);
        cerium::Act * act = cerium::ActManager::get(sceneName);

        std::string isCurrent = scene->first_attribute("current")->value();
        if(isCurrent == "True") cerium::ActManager::setCurrent(sceneName);

        for(rapidxml::xml_node <> * person = scene->first_node("person"); person; person=person->next_sibling("person"))
        {
            std::string personName = person->first_attribute("name")->value();
            cerium::vec2 position = {(float)atof(person->first_attribute("x")->value()), (float)atof(person->first_attribute("y")->value())};
            cerium::vec2 size = {(float)atof(person->first_attribute("w")->value()), (float)atof(person->first_attribute("h")->value())};
            float angle = (float)atof(person->first_attribute("angle")->value());

            act->add(new cerium::Person(personName, nullptr, act));
            cerium::Person * per = act->get(personName);

            per->setPosition(position);
            per->setSize(size);
            per->setRotation(angle);

            for(rapidxml::xml_node <> * prop = person->first_node("prop"); prop; prop=prop->next_sibling("prop"))
            {
                std::string type = prop->first_attribute("type")->value();
                std::string name = prop->first_attribute("name")->value();

                if(type == "costumed")
                {
                    std::string costumeName = prop->first_attribute("costume_name")->value();
                    per->addProp(new cerium::Costumed(per, nullptr, name, cerium::ResourceManager::get(costumeName)->cast_to<cerium::Costume>()));
                }
                else if (type == "rigidBody")
                {
                    float gravityScale = atoi(prop->first_attribute("gravity_scale")->value());
                    float mass = atoi(prop->first_attribute("mass")->value());
                    per->addProp(new cerium::RigidBody(per, nullptr, name, gravityScale, mass));
                }
                else if (type == "vertexArray")
                {
                    cerium::vec4 color = {(float)atof(prop->first_attribute("r")->value()),
                                          (float)atof(prop->first_attribute("g")->value()),
                                          (float)atof(prop->first_attribute("b")->value()),
                                          (float)atof(prop->first_attribute("a")->value())};
                    std::string texturedValue = prop->first_attribute("textured")->value();
                    bool textured = texturedValue == "True";

                    per->addProp(new cerium::VertexArray(per, nullptr, name, color, textured));
                }
                else if (type == "scriptable")
                {
                    std::string scriptName = prop->first_attribute("script")->value();
                    per->addProp(new cerium::Scriptable(per, nullptr, name, cerium::ResourceManager::get(scriptName)->cast_to<cerium::Script>()));
                }
                else if (type == "label")
                {
                    std::string fontName = prop->first_attribute("font")->value();
                    std::string text = prop->first_attribute("text")->value();
                    cerium::vec4 color = {(float)atof(prop->first_attribute("r")->value()),
                                          (float)atof(prop->first_attribute("g")->value()),
                                          (float)atof(prop->first_attribute("b")->value()),
                                          (float)atof(prop->first_attribute("a")->value())};
                    per->addProp(new cerium::Label(per, nullptr, name, cerium::ResourceManager::get(fontName)->cast_to<cerium::Font>(), text, color));
                }
                else if (type == "button")
                {
                    std::string fontName = prop->first_attribute("font")->value();
                    std::string text = prop->first_attribute("text")->value();
                    per->addProp(new cerium::Button(per, nullptr, name, normalTextColor, hoveredTextColor, normalBackgroundColor, hoveredBackgroundColor, text,
                                                    cerium::ResourceManager::get(fontName)->cast_to<cerium::Font>()));
                }
            }
        }
    }
}


void getColorsOfUI(cerium::vec4 & normalTextColor, cerium::vec4 & hoveredTextColor,
                   cerium::vec4 & normalBackgroundColor, cerium::vec4 & hoveredBackgroundColor)
{
    rapidxml::file <> file("settings.xml");
    rapidxml::xml_document<> settings;
    settings.parse<0>(file.data());

    rapidxml::xml_node<> * uiNode = settings.first_node("settings")->first_node("ui");

    rapidxml::xml_node<> * normalText = uiNode->first_node("normalText");
    normalTextColor = {(float)atof(normalText->first_attribute("r")->value()),
                                    (float)atof(normalText->first_attribute("g")->value()),
                                    (float)atof(normalText->first_attribute("b")->value()),
                                    (float)atof(normalText->first_attribute("a")->value())};

    rapidxml::xml_node<> * hoveredText = uiNode->first_node("hoveredText");
    hoveredTextColor = {(float)atof(hoveredText->first_attribute("r")->value()),
                        (float)atof(hoveredText->first_attribute("g")->value()),
                        (float)atof(hoveredText->first_attribute("b")->value()),
                        (float)atof(hoveredText->first_attribute("a")->value())};

    rapidxml::xml_node<> * normalBackground = uiNode->first_node("normalBackground");
    normalBackgroundColor = {(float)atof(normalBackground->first_attribute("r")->value()),
                             (float)atof(normalBackground->first_attribute("g")->value()),
                             (float)atof(normalBackground->first_attribute("b")->value()),
                             (float)atof(normalBackground->first_attribute("a")->value())};

    rapidxml::xml_node<> * hoveredBackground = uiNode->first_node("hoveredBackground");
    hoveredBackgroundColor = {(float)atof(hoveredBackground->first_attribute("r")->value()),
                              (float)atof(hoveredBackground->first_attribute("g")->value()),
                              (float)atof(hoveredBackground->first_attribute("b")->value()),
                              (float)atof(hoveredBackground->first_attribute("a")->value())};
}


int main()
{
    bool debug_mode = is_debug_mode();

    cerium::Window::setSize(size_of_window());
    cerium::Window::setTitle(title_of_window());

    cerium::Window::init();
    cerium::Camera::init();

    cerium::DebugLog::init();

    load_resources();
    cerium::ResourceManager::add("shader", new cerium::ShaderProgram("vertexShader.glsl", "fragmentShader.glsl"));

    int frames = 0;

    if (debug_mode)
    {
        cerium::ResourceManager::add("fpsTimer", new cerium::Clock);
        cerium::ResourceManager::get("fpsTimer")->use();
    }

    cerium::vec4 normalTextColor;
    cerium::vec4 hoveredTextColor;
    cerium::vec4 normalBackgroundColor;
    cerium::vec4 hoveredBackgroundColor;

    getColorsOfUI(normalTextColor, hoveredTextColor, normalBackgroundColor, hoveredBackgroundColor);

    load_scenes(normalTextColor, hoveredTextColor, normalBackgroundColor, hoveredBackgroundColor);

    while(!cerium::EventManager::isWindowClosed())
    {
        if(debug_mode)
        {
            frames++;
            if(cerium::ResourceManager::get("fpsTimer")->cast_to<cerium::Clock>()->getElapsedTime() > 1)
            {
                std::cout << "FPS " << frames << std::endl;
                frames = 0;

                cerium::ResourceManager::get("fpsTimer")->use();
            }
        }

        cerium::ResourceManager::get("timer")->use();
        cerium::EventManager::pollEvents();
        cerium::Window::clear();

        cerium::ActManager::updateCurrent(cerium::ResourceManager::get("timer")->cast_to<cerium::Clock>()->getElapsedTime());
        cerium::ActManager::drawCurrent();

        cerium::DebugLog::update();

        cerium::Window::render();
    }

    return 0;
}