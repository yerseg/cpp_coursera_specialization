#include <iostream>
#include <map>

bool IsAnagrams(const std::string& s1, const std::string& s2)
{
    std::map<char, int> counter1, counter2;
    for (const auto& c : s1)
    {
        ++counter1[c];
    }
    for (const auto &c : s2)
    {
        ++counter2[c];
    }
    return counter1 == counter2;
}

int main()
{
    int N;
    std::cin >> N;

    std::string s1, s2;
    for (size_t i = 0; i < N; ++i)
    {
        std::cin >> s1 >> s2;
        if (IsAnagrams(s1, s2))
        {
            std::cout << "YES" << std::endl;
        }
        else 
        {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}