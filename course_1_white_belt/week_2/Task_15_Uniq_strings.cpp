#include <iostream>
#include <set>

int main()
{
    std::set<std::string> set;
    int N;
    std::cin >> N;
    
    for (size_t i = 0; i < N; ++i)
    {
        std::string str;
        std::cin >> str;

        set.insert(str);
    }

    std::cout << set.size() << std::endl;

    return 0;
}