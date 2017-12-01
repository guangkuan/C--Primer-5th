#include <iostream>

using namespace std;

int main()
{
    int grade,a,b;
    string lettergrade,level,papper;
    cin >> grade;
    a = grade / 10;
    b = grade % 10;
    papper = (a < 6) ? 'F'
        : (a == 10) ? 'A++'
            : (a == 9) ? 'A'
                : (a == 8) ? 'B'
                    : (a == 7) ? 'C' : 'D';
    level = (b > 7) ? '+' : (b < 3) ? '-' : ' ';
    lettergrade = papper + level;
    cout << "³É¼¨µÈ¼¶£º" << endl;
    cout << lettergrade << endl;

    return 0;
}
