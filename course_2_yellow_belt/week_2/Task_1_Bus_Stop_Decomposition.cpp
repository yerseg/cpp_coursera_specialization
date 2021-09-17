#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

enum class QueryType
{
    NewBus,
    BusesForStop,
    StopsForBus,
    AllBuses
};

struct Query
{
    QueryType type;
    string bus;
    string stop;
    vector<string> stops;
};

istream &operator>>(istream &is, Query &q)
{
    string queryField;
    cin >> queryField;
    
    if (queryField == "NEW_BUS")
    {
        q.type = QueryType::NewBus;
        cin >> q.bus;

        size_t stopCount = 0;
        cin >> stopCount;

        q.stops.resize(stopCount);

        for (size_t i = 0; i < stopCount; ++i)
        {
            cin >> q.stops[i];
        }
    }
    else if (queryField == "BUSES_FOR_STOP")
    {
        q.type = QueryType::BusesForStop;  
        cin >> q.stop;  
    }
    else if (queryField == "STOPS_FOR_BUS")
    {
        q.type = QueryType::StopsForBus;
        cin >> q.bus;
    }
    else if (queryField == "ALL_BUSES")
    {
        q.type = QueryType::AllBuses;
    }
    else
    {
        throw std::runtime_error("Unknown query type!");
    }
    
    return is;
}

struct BusesForStopResponse
{
    bool isNotExist;
    vector<string> buses;
};

ostream &operator<<(ostream &os, const BusesForStopResponse &r)
{
    if (r.isNotExist)
    {
        os << "No stop" << endl; 
    }
    else
    {
        for (const auto &bus : r.buses)
        {
            os << bus << ' ';
        }
        os << endl;
    }
    
    return os;
}

struct StopsForBusResponse
{
    bool isNotExist; 
    vector<pair<string, vector<string>>> stopsToBuses;
};

ostream &operator<<(ostream &os, const StopsForBusResponse &r)
{
    if (r.isNotExist)
    {
        os << "No bus" << endl;
    }
    else
    {
        for (const auto &[stop, buses] : r.stopsToBuses)
        {
            os << "Stop " << stop << ": ";

            for (const auto &bus : buses)
            {
                os << bus << " ";
            }

            os << endl;
        }
    }
    
    return os;
}

struct AllBusesResponse
{
    bool isNotExist;
    map<string, vector<string>> busesToStop;
};

ostream &operator<<(ostream &os, const AllBusesResponse &r)
{
    if (r.isNotExist)
    {
        os << "No buses" << endl;
    }
    else
    {
        for (const auto &[bus, stops] : r.busesToStop)
        {
            os << "Bus " << bus << ": ";

            for (const auto &stop : stops)
            {
                os << stop << " ";
            }

            os << endl;
        }
    }
    
    return os;
}

class BusManager
{
public:
    void AddBus(const string &bus, const vector<string> &stops)
    {
        m_busesToStops[bus] = stops;
        
        for (const auto& stop : stops)
        {
            m_stopsToBuses[stop].push_back(bus);
        }
    }

    BusesForStopResponse GetBusesForStop(const string &stop) const
    {
        BusesForStopResponse response;
        response.isNotExist = true;

        if (m_stopsToBuses.count(stop))
        {   
            response.buses = m_stopsToBuses.at(stop);
            response.isNotExist = false;
        }

        return response;
    }

    StopsForBusResponse GetStopsForBus(const string &bus) const
    {
        StopsForBusResponse response; 
        response.isNotExist = true;

        if (m_busesToStops.count(bus))
        {
            for (const auto& stop : m_busesToStops.at(bus))
            {
                if (m_stopsToBuses.at(stop).size() == 1)
                {
                    response.isNotExist = false;
                    vector<string> message = { "no interchange" };
                    response.stopsToBuses.emplace_back(stop, message);
                }
                else
                {
                    response.isNotExist = false;
                    vector<string> busesForStop;

                    for (const string &otherBus : m_stopsToBuses.at(stop))
                    {
                        if (bus != otherBus)
                        {
                            busesForStop.push_back(otherBus);
                        }
                    }

                    response.stopsToBuses.emplace_back(make_pair(stop, busesForStop));
                }
            }
        }

        return response;
    }

    AllBusesResponse GetAllBuses() const
    {
        AllBusesResponse response;
        response.isNotExist = true;

        if (!m_busesToStops.empty())
        {
            response.isNotExist = false;
            response.busesToStop = m_busesToStops;
        }

        return response;
    }

    map<string, vector<string>> m_busesToStops;
    map<string, vector<string>> m_stopsToBuses;
};

// Не меняя тела функции main, реализуйте функции и классы выше

int main()
{
    int query_count;
    Query q;

    cin >> query_count;

    BusManager bm;
    for (int i = 0; i < query_count; ++i)
    {
        cin >> q;
        switch (q.type)
        {
        case QueryType::NewBus:
            bm.AddBus(q.bus, q.stops);
            break;
        case QueryType::BusesForStop:
            cout << bm.GetBusesForStop(q.stop) << endl;
            break;
        case QueryType::StopsForBus:
            cout << bm.GetStopsForBus(q.bus) << endl;
            break;
        case QueryType::AllBuses:
            cout << bm.GetAllBuses() << endl;
            break;
        }
    }

    return 0;
}