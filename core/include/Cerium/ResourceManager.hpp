#ifndef CERIUM_RESOURCEMANAGER_HPP
#define CERIUM_RESOURCEMANAGER_HPP

#include "Resource.hpp"

#include <string>
#include <vector>

namespace cerium
{
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
        static Resource * get(const std::string & name); //^header
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
        static void remove(const std::string & name); //^header
        /*
            ^[name][exist]
            ^[class][ResourceManager]
            ^[description][Checking existing of Resource with given name]
            ^[argument]<name>[Name of resource to storage]
        */
        static bool exist(const std::string & name); //^header
        /*
            ^[name][clear]
            ^[class][ResourceManager]
            ^[description][Deleting all Resources]
        */
        static void clear(void); //^header
    private:
        static ResourceManager & instance();

        ResourceManager() {};
        ~ResourceManager();

        ResourceManager(const ResourceManager & other) = delete;
        void operator=(const ResourceManager & other) = delete;
    private:
        std::vector<std::pair<std::string, Resource*>> resources;
    };
}

#endif