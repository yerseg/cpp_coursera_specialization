#include <iostream>
#include <unordered_set>
#include <map>

int main()
{
    size_t Q;
    std::cin >> Q;

    std::map<std::string, std::unordered_set<std::string>> dict;
    std::string request;
    std::string word1, word2;

    for (size_t i = 0; i < Q; ++i)
    {
        std::cin >> request;

        if (request == "ADD")
        {
            std::cin >> word1 >> word2;
            dict[word1].insert(word2);
            dict[word2].insert(word1);
        }
        else if (request == "COUNT")
        {
            std::cin >> word1;
            std::cout << dict[word1].size() << std::endl;
        }
        else if (request == "CHECK")
        {
            std::cin >> word1 >> word2;
            if (dict[word1].count(word2))
                std::cout << "YES" << std::endl;
            else
                std::cout << "NO" << std::endl;
        }
    }

    return 0;
}