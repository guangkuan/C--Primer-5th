#include <iostream>
#include <string>

using namespace std;

int main()
{
    string finalgrade;
    int grade;
    cout << "����������ĵķ�����" << endl;
    while(cin >> grade && grade >= 0 && grade <= 100)
    {
        finalgrade = (grade > 90) ? "high pass" : (grade > 75) ? "low pass" : (grade > 60) ? "pass" : "die";
        cout << "��ѯ���Ϊ��" << finalgrade << " " ;
        cout << endl;
    }
    cout << endl;

    return 0;
}
