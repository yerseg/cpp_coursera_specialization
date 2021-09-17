#include <iostream>
#include <vector>
#include <map>

int main()
{
    size_t currentNumber = 1;
    int Q;
    std::cin >> Q;

    std::map<std::vector<std::string>, uint32_t> buses;

    for (int i = 0; i < Q; ++i)
    {
        int N;
        std::cin >> N;
        std::vector<std::string> stops(N);
        for (int j = 0; j < N; ++j)
        {
            std::cin >> stops[j];
        }

        if (!buses.count(stops))
        {
            buses[stops] = currentNumber;
            std::cout << "New bus " << currentNumber << std::endl;
            ++currentNumber;
        }
        else
        {
            std::cout << "Already exists for " << buses[stops] << std::endl;
        }
    }

    return 0;
}