#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    /*�Ա�*/
    /*
    int i;
    vector<int> vInt;
    while(cin >> i)
        vInt.push_back(i);
    for(auto it = vInt.begin(); it != vInt.end(); ++it)
    {
        *it = 2*(*it);
        cout << *it << " ";
    }
    cout << endl;

    return 0;
    */

    vector<int> vInt;
    srand((unsigned) time (NULL));
    for(int i = 0; i < 10; i++)
    {
        vInt.push_back(rand() % 1000);
    }
    cout << "������ɵ�10�������ǣ�" << endl;
    for(auto it = vInt.cbegin(); it != vInt.cend(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    cout << "�������10�������ǣ�" << endl;
    for(auto it = vInt.begin(); it != vInt.end(); it++)
    {
        *it *= 2;
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
