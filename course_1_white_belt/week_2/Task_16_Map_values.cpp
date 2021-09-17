std::set<std::string> BuildMapValuesSet(const std::map<int, std::string> &map)
{
    std::set<std::string> set; 
    for (const auto& pair : map)
    {
        set.insert(pair.second);
    }

    return set;
}