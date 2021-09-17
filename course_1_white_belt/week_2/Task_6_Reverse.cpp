#include <vector>

void Reverse(std::vector<int>& numbers)
{
    for (size_t i = 0; i < numbers.size() / 2; ++i)
    {
        auto tmp = numbers[i];
        numbers[i] = numbers[numbers.size() - i - 1];
        numbers[numbers.size() - i - 1] = tmp;
    }
}