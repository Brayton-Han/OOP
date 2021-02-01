#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <numeric>
#include "stopwatch.h"

using namespace std;

using Container = vector<double>;

istream& read_vec (istream& in,Container& vec);
double reckon_avg(const Container& vec);
double reckon_avg_2(Container vec);
int statistic_avg(const Container& vec, double avg);
int statistic_avg_2(Container vec, double avg);
int test_213();

int main()
{
    test_213();
    return 0;
}

int test_213()
{
    // 1. read vec integers & record IO time... too slow
    Stopwatch sw_io;
    Container vec;
    //vec.reserve(400000000);   // to test pre-allocate is effetive or not
    sw_io.start();
    read_vec(cin,vec);
    sw_io.stop();
    cout.setf(ios::fixed);
    cout << setprecision(3) << " io_time=" << setw(4) << sw_io.getMilliseconds() << "us"  <<"\n";

    // 2. run & record time.
    const int times = 5;
    int navgcnt,navgcnt2;
    double avg,avg1,avg2;
    double sw_t1, sw_t2, sw_t3, sw_t4;
    Stopwatch sw;
    for(int idx=0; idx<times; ++idx){
        sw.start();
        avg = reckon_avg(vec);
        sw.stop();
        sw_t1 = sw.getMilliseconds();

        sw.start();
        avg2 = reckon_avg_2(vec);
        sw.stop();
        sw_t2 = sw.getMilliseconds();

        sw.start();
        navgcnt = statistic_avg(vec, avg1);
        sw.stop();
        sw_t3 = sw.getMilliseconds();

        sw.start();
        navgcnt2 = statistic_avg_2(vec, avg2);
        sw.stop();
        sw_t4 = sw.getMilliseconds();

        cout.setf(ios::fixed);
        cout << setprecision(5)
                    << "idx="<< setw(2) << idx+1 << " rrr_time=" << setw(4) << sw_t1 << "us" 
                    << " vva_time=" << setw(5) << sw_t2 << "us"
                    << " b1c1 avg=" << avg << "  avgcnt=" << navgcnt << endl;

        cout << setprecision(5)
                    << "idx="<< setw(2) << idx+1 << " rrr_time=" << setw(4) <<  sw_t3 << "us" 
                    << " vva_time=" << setw(5) << sw_t4 << "us"
                    << " b2c2 avg=" << avg2 << "  avgcnt=" << navgcnt2 << endl;

    }

    return 0;
}

istream& read_vec(istream& in,Container& vec)
{
    double value;
    while(in>>value){
        vec.push_back(value);
    }

    return in;
}

double reckon_avg(const Container& vec)
{
    double sum = accumulate(begin(vec), end(vec), 0.0);
    return sum/vec.size();
}

double reckon_avg_2(Container vec)
{
    double sum = accumulate(begin(vec), end(vec), 0.0);
    return sum/vec.size();
}

int statistic_avg(const Container& vec, double avg)
{
    avg = reckon_avg(vec);
    int a = int(avg+0.5),n=0;
    for(int i=0; i<1000000; i++)
    {
        if(vec[i] == a)
        n++;
    }
    return n;
}

int statistic_avg_2(Container vec, double avg)
{
    avg = reckon_avg_2(vec);
    int a = int(avg+0.5),n=0;
    for(int i=0; i<1000000; i++)
    {
        if(vec[i]==a)
        n++;
    }
    return n;
}
