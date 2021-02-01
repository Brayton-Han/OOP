#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <string>
#include <iomanip>
#include "stopwatch.h"
using namespace std;

//学生信息
struct Student_info
{
    string name;
    int mid, end;
    vector<int> homework;
    double final;
};

//降序排列
bool compare(Student_info &a, Student_info &b)
{
    return a.final > b.final;
}

//计算作业的中位数
double midian(vector<int> hw)
{
    double hw_midian;
    sort(hw.begin(),hw.end());
    hw_midian=(hw[2]+hw[3])/2.0;
    return hw_midian;
}

//计算总成绩
double final(Student_info &student)
{
    double sum;
    sum= 0.4*student.mid + 0.4*student.end + 0.2*midian(student.homework);
    return sum;
}

//主函数
int main()
 {
    int j,hw=0;
    Stopwatch sw;
    Student_info student;
    vector<Student_info> students;
    sw.start();
    while(cin)
    {
        student.homework.clear();
        cin >> student.name;
        if (student.name.size()==0) break;
        cin >> student.mid;
        cin >> student.end;
        while(cin>>hw)
        {
            student.homework.push_back(hw);
        }
        if(!cin.eof()) cin.clear();
        student.final=final(student);
        students.push_back(student);
    }
    sort(students.begin(),students.end(),compare);
    for(auto i=0;i!=students.size();i++)
    {
        cout << students[i].name << " " << setprecision(3) << students[i].final 
        << setprecision(2) << " " << students[i].mid << " " << students[i].end;
        for(j=0;j<6;j++)
        {
            cout << " " << students[i].homework[j];
        }
        cout << endl;
    }
    sw.stop();
    clog << sw.getMilliseconds() << " ms" << endl;
    return 0;
}