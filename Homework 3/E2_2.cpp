#include<iostream>
#include<algorithm>
#include<string>
#include<ctime>
#include<random>
#include<cstdlib>
using namespace std;

int rand_1()
{
    int mid;
    mid= rand()%31 + 60;
    return mid;
}

int rand_2()
{
    int end;
    end=rand()%36 + 50;
    return end;
}

int rand_3()
{
    int homework;
    homework=rand()%26 + 70;
    return homework;
}

int main()
{
    srand((unsigned)time(NULL));
    string name;
    while(getline(cin,name))
    {
        cout << name << "    " << rand_1() << "  " << rand_2() << "  " << rand_3() 
        << "  " << rand_3() << "  " << rand_3() << "  " << rand_3() << "  " << rand_3() 
        << "  " << rand_3() << endl;
    }
    return 0;
}