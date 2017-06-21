#ifndef CERIUM_RESOURCE_HPP
#define CERIUM_RESOURCE_HPP

namespace cerium
{
    class Resource
    {
    public:
        /*
            ^[name][use]
            ^[class][Resource]
            ^[description][Processing Resource]
         */
        virtual void use(void) = 0;
    };
}

#endif