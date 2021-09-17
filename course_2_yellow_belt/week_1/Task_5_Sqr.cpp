#include <iostream>
#include <vector>
#include <map>

//////////////////////////////////////////////////////////////////////////////////
///  Реализуйте шаблонную функцию Sqr, которая работает не только для чисел, 
///  но и для контейнеров.Функция должна возвращать копию исходного контейнера, 
///  модифицировав его следующим образом :
///    * для vector элементы нужно возвести в квадрат;
///    * для map в квадрат нужно возвести только значения, но не ключи;
///    * для pair в квадрат нужно возвести каждый элемент пары.
///  

/// Способ с ОПЕРАТОРАМИ однозначно ПЛОХОЙ, но рабочий :)
/// Лучше конечно было обойтись только различными шаблонами функции Sqr

template <typename T>
std::vector<T> operator*(std::vector<T> &lhs, const std::vector<T> &rhs);

template <typename T, typename U>
std::pair<T, U> operator*(std::pair<T, U> &lhs, const std::pair<T, U> &rhs);

template <typename Key, typename Value>
std::map<Key, Value> operator*(std::map<Key, Value> &lhs, const std::map<Key, Value> &rhs);

template <typename T>
T Sqr(T x);

template <typename T>
std::vector<T> operator*(std::vector<T> &lhs, const std::vector<T> &rhs)
{
    for (auto& x : lhs)
        x = x * x;
    
    return lhs;
}

template <typename T, typename U>
std::pair<T, U> operator*(std::pair<T, U> &lhs, const std::pair<T, U> &rhs)
{
    lhs.first = lhs.first * lhs.first;
    lhs.second = lhs.second * lhs.second;

    return lhs;
}

template <typename Key, typename Value>
std::map<Key, Value> operator*(std::map<Key, Value> &lhs, const std::map<Key, Value> &rhs)
{
    for (auto& [key, value] : lhs)
    {
        value = value * value;
    }

    return lhs;
}

template <typename T>
T Sqr(T x)
{
    return x * x;
}

using namespace std;

int main()
{
    // Пример вызова функции
    vector<int> v = {1, 2, 3};
    cout << "vector:";
    for (int x : Sqr(v))
    {
        cout << ' ' << x;
    }
    cout << endl;

    map<int, pair<int, int>> map_of_pairs = {
        {4, {2, 2}},
        {7, {4, 3}}};
    cout << "map of pairs:" << endl;
    for (const auto &x : Sqr(map_of_pairs))
    {
        cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
    }

    return 0;
}