#include <vector>

std::vector<int> Reversed(const std::vector<int> &_numbers)
{
    std::vector<int> numbers(_numbers.size());
    for (size_t i = 0; i < _numbers.size(); ++i)
    {
        numbers[i] = _numbers[_numbers.size() - i - 1];
    }
    return numbers;
}