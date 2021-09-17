#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>

int main()
{
    std::map<std::string, std::vector<std::string>> stops;
    std::map<std::string, std::vector<std::string>> buses;

    int Q;
    std::cin >> Q;

    for (size_t i = 0; i < Q; ++i)
    {
        std::string command;
        std::cin >> command;

        if (command == "NEW_BUS")
        {
            std::string bus;
            int stops_count;
            std::cin >> bus >> stops_count;
            
            std::string stop;
            for (size_t j = 0; j < stops_count; ++j)
            {
                std::cin >> stop;
                buses[bus].push_back(stop);
                stops[stop].push_back(bus);
            }

        }
        else if (command == "BUSES_FOR_STOP")
        {
            std::string stop;
            std::cin >> stop;
            if (stops.find(stop) == stops.end())
            {
                std::cout << "No stop" << std::endl;
            }
            else 
            {
                for (const auto& elem : stops[stop])
                {
                    std::cout << elem << " ";
                }
                std::cout << std::endl;
            }
        }
        else if (command == "STOPS_FOR_BUS")
        {
            std::string bus;
            std::cin >> bus;
            if (buses.find(bus) == buses.end())
            {
                std::cout << "No bus" << std::endl;
            }
            else
            {
                for (const auto& el : buses[bus])
                {
                    std::cout << "Stop " << el << ": ";
                    if (stops[el].size() == 1 && stops[el].front() == bus)
                    {
                        std::cout << "no interchange" << std::endl;
                    }
                    else
                    {
                        for (const auto& b : stops[el])
                        {
                            if (b != bus)
                                std::cout << b << " ";
                        }
                        std::cout << std::endl;
                    }
                }
                std::cout << std::endl;
            }
        }
        else if (command == "ALL_BUSES")
        {
            if (buses.empty())
            {
                std::cout << "No buses" << std::endl;
            }
            else
            {
                for (const auto& bus : buses)
                {
                    std::cout << "Bus " << bus.first << ": ";
                    for (const auto& stop : bus.second)
                    {
                        std::cout << stop << " ";
                    }
                    std::cout << std::endl;
                }
            }
        }
    }

    return 0;
}