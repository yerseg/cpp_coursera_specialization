#include <iostream>
#include <map>
#include <functional>

////////////////////////////////////////////////////////////////////////////
///  Реализуйте шаблонную функцию GetRefStrict, которая на вход принимает: 
///  map и значение ключа k. Если элемент по ключу k в коллекции отсутствует, 
///  то функция должна бросить исключение runtime_error, 
///  иначе вернуть ссылку на элемент в коллекции.

template <typename Key, typename Value>
Value& GetRefStrict(std::map<Key, Value>& map, const Key& key)
{
    try
    {
        return map.at(key);
    }
    catch(const std::out_of_range& ex)
    {
        throw std::runtime_error(ex.what());
    }
}

int main()
{
    using namespace std;

    map<int, string> m = {{0, "value"}};
    string &item = GetRefStrict(m, 0);
    item = "newvalue";
    cout << m[0] << endl; // выведет newvalue
    return 0;
}