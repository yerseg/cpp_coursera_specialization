#include <iostream>
#include <vector>

bool IsPalindrom(const std::string &str)
{
    for (size_t i = 0; i < str.size() / 2; ++i)
    {
        if (str[i] != str[str.size() - 1 - i])
            return false;
    }
    return true;
}

std::vector<std::string> PalindromFilter(std::vector<std::string>& words, int minLength)
{
    std::vector<std::string> toRet;
    for (auto word : words)
    {
        if (word.size() >= minLength && IsPalindrom(word))
            toRet.push_back(word);
    }
    return toRet;
}

int main()
{
    std::string x;
    std::cin >> x;
    if (IsPalindrom(x))
        std::cout << "true";
    else
        std::cout << "false";
    return 0;
}