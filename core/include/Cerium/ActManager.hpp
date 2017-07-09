#ifndef CERIUM_ACTMANAGER_HPP
#define CERIUM_ACTMANAGER_HPP

#include <vector>
#include <string>

namespace cerium
{
    class Act;
    class ActManager
    {
    public:
        /*
            ^[name][get]
            ^[class][ActManager]
            ^[argument]<name>[Name of Act to return]
            ^[description][Returns Act by given name]
            ^[returns][Pointer to Act with given name]
        */
        static Act * get(const std::string & name); //^header
        /*
            ^[name][add]
            ^[class][ActManager]
            ^[argument]<name>[Name of Act]
            ^[description][Adding new Act to storage with given name]
        */
        static void add(const std::string & name); //^header
        /*
            ^[name][updateCurrent]
            ^[class][ActManager]
            ^[argument]<deltaTime>[DeltaTime of main game clock]
            ^[description][Updating current scene setted by setCurrent method]
        */
        static void updateCurrent(const float & deltaTime); //^header
        /*
            ^[name][drawCurrent]
            ^[class][ActManager]
            ^[description][Drawing current scene setted by setCurrent method]
        */
        static void drawCurrent(void); //^header
        /*
            ^[name][remove]
            ^[class][ActManager]
            ^[argument]<name>[Name of Act to remove]
            ^[description][Removing Act with given name]
        */
        static void remove(const std::string & name); //^header
        /*
            ^[name][exist]
            ^[class][ActManager]
            ^[description][Checking all stored Acts and searching the Act with given name]
            ^[returns][True if Act with given name exist or False if it isn't]
        */
        static bool exist(const std::string & name); //^header
        /*
            ^[name][setCurrent]
            ^[class][ActManager]
            ^[description][Setting current act]
        */
        static void setCurrent(const std::string & name); //^header
        /*
            ^[name][clear]
            ^[class][ActManager]
            ^[description][Removing all Acts in ActManager]
        */
        static void clear(void); //^header
    private:
        static ActManager & instance();

        ActManager() {};
        ActManager(const ActManager & other) = delete;
        void operator=(const ActManager & other) = delete;
    private:
        std::vector<std::pair<std::string, Act*>> acts;
        Act * currentAct;
    };
}

#endif