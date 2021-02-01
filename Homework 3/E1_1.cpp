#include<iostream>
#include<random>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include"stopwatch.h"
using namespace std;

double getnum()
{
    int a;
    double b;
    a=rand()%1000;
    b=a/1000.0;
    return b;
}

int main()
{
    srand((unsigned)time(NULL));
    int i,j,N;
    double x,y,pi;
    Stopwatch sw;
    cin >> N;
    sw.start();
    for(i=0,j=0;i<N;++i)
    {
        x=getnum();
        y=getnum();
        if(x*x+y*y<=1)
           j++;
    }
    pi=4*j/double(N);
    sw.stop();
    cout << pi << endl;
    cout << sw.getMilliseconds() << endl;
}