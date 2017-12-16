#include <iostream>
#include <vector>

using namespace std;

int main()
{
    /*第一种*/
    /*vector<int> vInt;
    for (int i = 0; i<10; ++i)
        vInt.push_back(42);
    for (auto mem : vInt)
        cout << mem << endl;
    return 0 ;*/


    /*第二种*/
    /*vector<int> vInt = {42,42,42,42,42,42,42,42,42,42};
    for (auto mem : vInt)
        cout << mem << endl;
    return 0 ;*/


    /*第三种*/
    /*vector<int> vInt (10,42);
    for (auto mem : vInt)
        cout << mem << endl;
    return 0 ;*/


    /*第四种*/
    /*vector<int> vInt = {42,42,42,42,42,42,42,42,42,42};
    for (auto mem : vInt)
        cout << mem << endl;
    return 0 ;*/


    /*第五种*/
    vector<int> vInt(10);
    for (auto &i : vInt)
        i = 42;
    for (auto mem : vInt)
        cout << mem << endl;
    return 0 ;
}
