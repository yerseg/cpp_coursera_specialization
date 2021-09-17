#include <map>
#include <vector>
#include <tuple>

using namespace std;

enum class Lang
{
    DE,
    FR,
    IT
};

struct Region
{
    string std_name;
    string parent_std_name;
    map<Lang, string> names;
    int64_t population;
};

bool operator<(const Region& lhs, const Region& rhs)
{
    return tie(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population) <
        tie(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);
}

int FindMaxRepetitionCount(const vector<Region>& regions)
{
    size_t answer = 0;

    map<Region, size_t> regionsCount;
    for (const auto& region : regions)
    {
        const auto& tmp = ++regionsCount[region];
        if (tmp > answer) 
            answer = tmp;
    }

    return answer;
}

int main()
{
    return 0;
}