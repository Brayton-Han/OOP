// Author: Vincent Wang
// Date  : 2020/3/16 updated by wangxp@fudan.edu.cn
// Purpose:
//	    简单的Stopwatch类测试程序

#include <vector>
#include <iostream>
#include <iomanip>
#include "stopwatch.h"

using namespace std;

int main()
{
    const vector<int> sets{100, 1000,10000,100000};    // Features of C++11: uniform initialization
    const int times = 5;                                // Why const?
    Stopwatch sw;

    for(auto N: sets)                                   // Features of C++11: auto
    {
        for(auto idx=0; idx<times; ++idx)
        {
            sw.start();
            // Computing start
            auto sum = 0;
            for(auto i=0; i<N; i++)
            {
                sum += i;
                for(auto j=0; j<N; j++)
                    sum+=j;
            }
            // Computing stop
            sw.stop();
            cout << "N="<< N <<"  idx="<< idx+1 << " " << sw.getMilliseconds() << "ms" << endl;
        }
    }

    return 0;
}
