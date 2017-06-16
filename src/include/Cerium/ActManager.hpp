#ifndef CERIUM_ACTMANAGER_HPP
#define CERIUM_ACTMANAGER_HPP

#include <unordered_map>

namespace cerium
{
    class Act;
    class ActManager
    {
    public:
        /*
            ^[name][getAct]
            ^[class][ActManager]
            ^[argument]<name>[Name of Act to return]
            ^[description][Returns Act by given name]
            ^[returns][Pointer to Act with given name]
        */
        static Act * getAct(const std::string & name); //^header
        /*
            ^[name][add]
            ^[class][ActManager]
            ^[argument]<name>[Name of Act]
            ^[argument]<act>[Reference to Act to store]
            ^[description][Adding new Act to storage with given name]
        */
        static void add(const std::string & name, Act & act); //^header
        /*
            ^[name][remove]
            ^[class][ActManager]
            ^[argument]<name>[Name of Act to remove]
            ^[description][Removing Act with given name]
        */
        static void remove(const std::string & name); //^header
        /*
            ^[name][clear]
            ^[class][ActManager]
            ^[description][Removing all Acts in ActManager]
        */
        static void clear(void); //^header
    private:
        static ActManager & instance();

        ActManager();
        ActManager(const ActManager & other) = delete;
        void operator=(const ActManager & other) = delete;
    private:
        std::unordered_map<std::string, Act*> acts;
    };
}

#endif