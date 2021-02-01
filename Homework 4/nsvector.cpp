#include <vector>
#include <iostream>
#include <algorithm>
#include <assert.h>

#include "ns_common.h"
#include "split.h"

using namespace std;

namespace EXP4 {

using VNS = std::vector< std::pair<std::string, int> >;
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
    VNS::iterator it;
    find_if(vns.begin(), vns.end(), judge(it, hn));
    return it==vns.end();
}

void insert(const HostName& hn, const IPAddress& ipa)
{
    vns.push_back(make_pair(hn, ipa));
}

bool remove(const HostName& hn)
{
    VNS::iterator i=vns.begin();
    find_if(i, vns.end(), judge(i, hn));
    if(i==vns.end())
        return 1;
    else
    {
        vns.erase(i);
        return 0;
    }
}

IPAddress lookup(const HostName& hn)
{
    VNS::iterator iter=vns.begin();
    find_if(iter, vns.end(), judge(iter, hn));
    return iter->second;
}

bool judge(VNS::iterator& ite,const HostName& hn)
{
    return ite->first==hn;
}

};