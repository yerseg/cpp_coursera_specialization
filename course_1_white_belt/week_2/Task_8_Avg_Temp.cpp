#include <vector>
#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    int sum = 0;
    std::vector<int> vec(n);
    for (auto& v : vec)
    {
        std::cin >> v;
        sum += v;
    }
    int avg = sum / n;
    std::vector<int> idx;
    for (size_t i = 0; i < n; ++i)
    {
        if (vec[i] > avg)
        {
            idx.push_back(i);
        }
    }
    std::cout << idx.size() << std::endl;
    for (auto& i : idx)
    {
        std::cout << i << ' ';
    }
    return 0;
}