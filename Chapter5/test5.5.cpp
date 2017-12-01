/*自编失败*/
#include <iostream>

using namespace std;

int main()
{
    string lettergrade;
    int grade,a,b;
    cin >> grade;
    if(grade < 60)
        {
            cout << "E" << endl;
            return -1;
        }
        else
            {
                a = (grade / 10);
                b = grade % 10;
            }
    if (a != 10)
    {
        if(a == 9)/*是“==”不是“=”，低级错误*/
            lettergrade = 'A';
        else if(a == 8)
            lettergrade = 'B';
        else if(a == 7)
            lettergrade = 'C';
        else
            lettergrade = 'D';
    }
    else
        lettergrade = 'S';
    if(b > 7)
        {
            lettergrade = lettergrade + '+';
        }
    else if(b < 3)
        {
            lettergrade = lettergrade + '-';
        }

    cout << lettergrade << endl;

    return 0;
}
