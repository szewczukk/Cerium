#ifndef CERIUM_PROP_HPP
#define CERIUM_PROP_HPP

namespace cerium
{
    class Prop
    {
    public:
        /*
            ^[name][update]
            ^[class][Prop]
            ^[description][Updating Prop with deltaTime]
            ^[argument]<deltaTime>[DeltaTime of main game clock]
         */
        virtual void update(const float & deltaTime) = 0; //^header
        /*
            ^[name][draw]
            ^[class][Prop]
            ^[description][Abstract class to draw the object into screen]
         */
        virtual void draw(void) = 0; //^header
    };
}

#endif