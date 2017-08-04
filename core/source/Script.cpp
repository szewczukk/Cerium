#include "../include/Cerium/Script.hpp"
#include "../include/Cerium/DebugLog.hpp"

namespace cerium
{
    Script::Script(const std::string & path)
    {
        std::string filePath = "res/scripts/" + path;

        std::ifstream file(filePath.c_str());
        std::string content;
        std::string line;
        if(file.is_open())
        {
            while(std::getline(file, line))
            {
                content += line + "\n";
            }
        }
        else
        {
            cerium::DebugLog::add(filePath + " script can't be founded");
        }

        file.close();

        state.open_libraries(sol::lib::base);
        state.script(content);
    }


	void Script::run(std::string & name)
	{
		state[name]();
	}
}