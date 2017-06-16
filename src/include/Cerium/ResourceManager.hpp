#ifndef CERIUM_RESOURCEMANAGER_HPP
#define CERIUM_RESOURCEMANAGER_HPP

#include <string>
#include <unordered_map>

namespace cerium
{
    class Resource {};
    class ResourceManager
    {
    public:
        /*
            ^[name][get]
            ^[class][ResourceManager]
            ^[description][Returns Resource with given name and template]
            ^[argument]<name>[Name of resource to storage]
            ^[returns][Resource by name and template]
        */
        template <class T> static Resource * get(const std::string & name); //^header
        /*
            ^[name][add]
            ^[class][ResourceManager]
            ^[description][Adding resource into storage and name]
            ^[argument]<name>[Name of resource to storage]
            ^[argument]<resource>[Pointer to resource]
        */
        static void add(const std::string & name, Resource * resource); //^header
        /*
            ^[name][remove]
            ^[class][ResourceManager]
            ^[description][Adding resource into storage and name]
            ^[argument]<name>[Name of resource to storage]
        */
        static void remove(const std::string & name);
        /*
            ^[name][exist]
            ^[class][ResourceManager]
            ^[description][Checking existing of Resource with given name]
            ^[argument]<name>[Name of resource to storage]
        */
        static bool exist(const std::string & name);
        /*
            ^[name][clear]
            ^[class][ResourceManager]
            ^[description][Deleting all Resources]
        */
        static void clear(void);
    private:
        static ResourceManager & instance();

        ResourceManager() {};
        ~ResourceManager() {};

        ResourceManager(const ResourceManager & other) = delete;
        void operator=(const ResourceManager & other) = delete;
    private:
        std::unordered_map<std::string, Resource *> resources;
    };
}

#endif