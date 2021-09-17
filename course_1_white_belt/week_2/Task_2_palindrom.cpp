#include <iostream>

bool IsPalindrom(const std::string& str)
{
    for (size_t i = 0; i < str.size() / 2; ++i)
    {
        if (str[i] != str[str.size() - 1 - i])
            return false;
    }
    return true;
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