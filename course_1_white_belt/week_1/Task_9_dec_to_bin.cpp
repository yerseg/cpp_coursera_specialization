#include <iostream>
#include <vector>

int main()
{
    int N;
    std::cin >> N;
    std::vector<int> vec;
    while (N)
    {
        vec.push_back(N % 2);
        N /= 2;
    }
    for (size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[vec.size() - 1 - i];
    }
    return 0;
}