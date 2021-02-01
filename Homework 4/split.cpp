#include <algorithm>

#include "split.h"

using namespace std;


static inline bool space(char c)
{
    return (isspace(c) || ispunct(c));
}

static inline bool not_space(char c)
{
    return !space(c);
}

static inline int to_lower(int c)
{
    if (isupper(c))
    {
        return c + 32;
    }
    return c;
}

vector<string> split(const string &str)
{
    vector<string> ret;

    auto i = str.begin();
    while (i != str.end())
    {
        i = find_if(i, str.end(), not_space);
        auto j = find_if(i, str.end(), space);
        if (i != str.end())
        {
            string s = string(i, j);
            transform(s.begin(), s.end(), s.begin(), to_lower);
            ret.push_back(s);
        }
        i = j;
    }

    return ret;
}
