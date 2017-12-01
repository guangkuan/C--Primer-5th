#include <iostream>
#include <string>

using namespace std;

int main()
{
    string finalgrade;
    int grade;
    cout << "输入你想查阅的分数：" << endl;
    while(cin >> grade && grade >= 0 && grade <= 100)
    {
        finalgrade = (grade > 90) ? "high pass" : (grade > 75) ? "low pass" : (grade > 60) ? "pass" : "die";
        cout << "查询结果为：" << finalgrade << " " ;
        cout << endl;
    }
    cout << endl;

    return 0;
}
