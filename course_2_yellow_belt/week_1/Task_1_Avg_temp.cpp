#include <iostream>
#include <cstdint>
#include <vector>
#include <sstream>

int main()
{
    uint32_t N;
    std::cin >> N;
    std::vector<int64_t> temperature(N);
    int64_t avgTemp = 0;

    for (size_t i = 0; i < N; ++i)
    {
        int64_t temp;
        std::cin >> temp;
        temperature[i] = temp;
        avgTemp += temp;
    }

    avgTemp /= N;

    std::stringstream stream;
    int answer = 0;

    for (size_t i = 0; i < N; ++i)
    {
        if (temperature[i] > avgTemp)
        {
            answer++;
            stream << i << ' ';
        }
    }
    std::cout << answer << std::endl << stream.str() << std::endl;

    return 0;
}