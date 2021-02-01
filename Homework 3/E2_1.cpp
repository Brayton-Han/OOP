#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

vector<string> read(istream &in)
{
    vector<string> name;
    string line;
    while(getline(in,line))
    {
        if( line.length()>=10 && line.length()<=12 )
        name.push_back(line);
    }
    return name;
}

int main()
{
    int i;
    vector<string> name;
    name=read(cin);
    sort(name.begin(), name.end());
    for(i=0; i<20000; i++)
    {
        cout << name[i] <<endl;
    }
    return 0;
}