#include <iostream>
#include <map>
#include <algorithm>

int main()
{
    std::map<std::string, std::string> capitals;

    int Q;
    std::cin >> Q;

    for (size_t i = 0; i < Q; ++i)
    {
        std::string command;
        std::cin >> command;

        if (command == "CHANGE_CAPITAL")
        {
            std::string country, new_capital;
            std::cin >> country >> new_capital;
            if (capitals.find(country) == capitals.end())
            {
                std::cout << "Introduce new country " << country << " with capital " << new_capital << std::endl;
            }
            else if (capitals[country] == new_capital)
            {
                std::cout << "Country " << country << " hasn't changed its capital" << std::endl;
            }
            else
            {
                std::cout << "Country " << country << " has changed its capital from " << capitals[country] << " to " << new_capital << std::endl;
            }

            capitals[country] = new_capital;
        }
        else if (command == "RENAME")
        {
            std::string old_country_name, new_country_name;
            std::cin >> old_country_name >> new_country_name;

            if (capitals.find(new_country_name) != capitals.end() ||
                new_country_name == old_country_name ||
                capitals.find(old_country_name) == capitals.end())
            {
                std::cout << "Incorrect rename, skip" << std::endl;
            }
            else
            {
                capitals[new_country_name] = capitals[old_country_name];
                capitals.erase(old_country_name);
                std::cout << "Country " << old_country_name << " with capital " << capitals[new_country_name] << " has been renamed to " << new_country_name << std::endl;
            }
        }
        else if (command == "ABOUT")
        {
            std::string country;
            std::cin >> country;
            if (capitals.find(country) == capitals.end())
            {
                std::cout << "Country " << country << " doesn't exist" << std::endl;
            }
            else
            {
                std::cout << "Country " << country << " has capital " << capitals[country] << std::endl;
            }
        }
        else if (command == "DUMP")
        {
            if (capitals.empty())
            {
                std::cout << "There are no countries in the world" << std::endl;
            }
            else
            {

                for (const auto& pair : capitals)
                {
                    std::cout << pair.first << "/" << pair.second << " ";
                }
                std::cout << std::endl;
            }
        }
    }

    return 0;
}