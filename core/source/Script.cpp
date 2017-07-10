#include "../include/Cerium/Script.hpp"

namespace cerium
{
    Script::Script(const std::string & path)
    {
        std::string filePath = "res/scripts/" + path;

        std::ifstream file(filePath.c_str());
        std::string content;
        std::string line;
        while(std::getline(file, line))
        {
            content += line + "\n";
        }

        file.close();

        state.open_libraries(sol::lib::base);
        state.script(content);
    }
}