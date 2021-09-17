#include <iostream>
#include <algorithm>

int main()
{
    std::string str;
    char f = 'f';
    std::cin >> str;
    auto currentIter = std::find(str.begin(), str.end(), f);
    if (currentIter == str.end())
    {
        std::cout << -2;
    }
    else 
    {
        auto nextIter = std::find(++currentIter, str.end(), f);
        if (nextIter == str.end())
        {
            std::cout << -1;
        }
        else
        {
            std::cout << std::distance(str.begin(), nextIter);
        }
    }
    return 0;
}