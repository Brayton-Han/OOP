#include <iostream>
#include <map>
#include <vector>
#include <assert.h>

#include "ns_common.h"
#include "split.h"

using namespace std;

namespace EXP4 {

using VNS = std::map<std::string, int>;
static const int REPORT_INTERVAL = 20000;
static VNS vns; 

void create(std::istream& in)
{
    string line;
    int count = 0;
    while(getline(in, line))
    {
        vector<string> parts = split(line);
        assert(parts.size() == 2);
        string hostname =parts[0];
        IPAddress ipaddress = std::stoi(parts[1]);
        if (!contain(hostname))
        {
            insert(hostname,ipaddress);
            ++count;
        }
        if (count%REPORT_INTERVAL == 0) cout << ".";
    }
    cout<<"done!\n";
}

bool contain(const HostName& hn)
{
    return vns[hn];
}

void insert(const HostName& hn, const IPAddress& ipa)
{
    vns.insert({hn,ipa});
}

bool remove(const HostName& hn)
{
    if(vns[hn])
    {
        vns.erase(hn);
        return 0;
    }
    else
    {
        return 1;
    }
}

IPAddress lookup(const HostName& hn)
{
    return vns[hn];
}

};