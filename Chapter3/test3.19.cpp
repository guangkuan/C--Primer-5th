#include <iostream>
#include <vector>

using namespace std;

int main()
{
    /*��һ��*/
    /*vector<int> vInt;
    for (int i = 0; i<10; ++i)
        vInt.push_back(42);
    for (auto mem : vInt)
        cout << mem << endl;
    return 0 ;*/


    /*�ڶ���*/
    /*vector<int> vInt = {42,42,42,42,42,42,42,42,42,42};
    for (auto mem : vInt)
        cout << mem << endl;
    return 0 ;*/


    /*������*/
    /*vector<int> vInt (10,42);
    for (auto mem : vInt)
        cout << mem << endl;
    return 0 ;*/


    /*������*/
    /*vector<int> vInt = {42,42,42,42,42,42,42,42,42,42};
    for (auto mem : vInt)
        cout << mem << endl;
    return 0 ;*/


    /*������*/
    vector<int> vInt(10);
    for (auto &i : vInt)
        i = 42;
    for (auto mem : vInt)
        cout << mem << endl;
    return 0 ;
}
