#include <iostream>

int Factorial(int x)
{
    if (x <= 0)
        return 1;
    int res = 1;
    for (size_t i = 1; i <= x; ++i)
    {
        res *= i;
    }
    return res;
}

int main()
{
    int x;
    std::cin >> x;
    std::cout << Factorial(x);
    return 0;
}