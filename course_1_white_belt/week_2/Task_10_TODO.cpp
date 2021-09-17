#include <iostream>
#include <vector>

void Next(int &month)
{
    month++;
    if (month == 12)
        month = 0;
}

int main()
{
    std::vector<int> year = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    std::vector<std::vector<std::string>> toDo(year[0]);
    int month = 0;

    int q;
    std::cin >> q;

    for (size_t i = 0; i < q; ++i)
    {
        std::string str;
        int day;
        std::cin >> str;

        if (str == "ADD")
        {
            std::string lol;
            std::cin >> day >> lol;
            toDo[day - 1].push_back(lol);
        }
        else if (str == "DUMP")
        {
            std::cin >> day;
            if (!toDo[day - 1].empty())
            {
                std::cout << toDo[day - 1].size() << ' ';
                for (auto t : toDo[day - 1])
                {
                    std::cout << t << " ";
                }
                std::cout << std::endl;
            }
            else
            {
                std::cout << 0 << std::endl;
            }
            
        }
        else if (str == "NEXT")
        {
            Next(month);
            if (year[month] >= toDo.size())
            {
                toDo.resize(year[month]);
            }
            else
            {
                for (size_t i = 0; i < toDo.size() - year[month]; ++i)
                {
                    toDo[year[month] - 1].insert(toDo[year[month] - 1].end(), toDo[toDo.size() - i - 1].begin(), toDo[toDo.size() - i - 1].end());
                }
                toDo.resize(year[month]);
            }
        }
    }
    return 0;
}