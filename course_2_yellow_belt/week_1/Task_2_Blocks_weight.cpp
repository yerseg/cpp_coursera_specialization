#include <iostream>
#include <cstdint>

int main()
{
    uint64_t N;
    uint64_t R;
    std::cin >> N >> R;
    uint64_t answer = 0;

    for (size_t i = 0; i < N; ++i)
    {
        uint64_t W, H, D;
        std::cin >> W >> H >> D;
        answer += W * H * D * R;
    }

    std::cout << answer << std::endl;

    return 0;
}