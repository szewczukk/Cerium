#ifndef CERIUM_RESOURCE_HPP
#define CERIUM_RESOURCE_HPP

class Resource
{
public:
    /*
        ^[name][use]
        ^[class][Resource]
        ^[description][Using Processing Resource]
     */
    virtual void use(void) = 0;
};

#endif