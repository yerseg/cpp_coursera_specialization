#include <vector>
#include <iostream>

int GetWorryPeople(const std::vector<bool>& people)
{
    int count = 0;
    for (const auto& p : people)
    {
        if (p)
            count++;
    }
    return count;
}

int main()
{
    int q;
    std::cin >> q;
    std::vector<bool> queue;

    for (size_t i = 0; i < q; ++i)
    {
        std::string str;
        int x;

        std::cin >> str;
        
        if (str == "COME")
        {
            std::cin >> x;
            queue.resize(queue.size() + x, false);
        }
        else if (str == "WORRY")
        {
            std::cin >> x;
            queue[x] = true;
        }
        else if (str == "QUIET")
        {
            std::cin >> x;
            queue[x] = false;
        }
        else if (str == "WORRY_COUNT")
        {
            std::cout << GetWorryPeople(queue) << std::endl;
        }
    }

    return 0;
}