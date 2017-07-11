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
        virtual void use(void) = 0; //^header
        /*
            ^[name][cast_to]
            ^[class][Resource]
            ^[description][Casting this object to other, given type]
            ^[returns][Casted object]
         */
        template<typename T>
            T* cast_to(void) //^header
        {
            return dynamic_cast<T*>(this);
        }
    };
}

#endif