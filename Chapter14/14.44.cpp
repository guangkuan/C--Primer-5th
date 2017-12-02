#include <iostream>
#include <map>
#include <algorithm>
#include <functional>

using namespace std;

map<string, function<int (int, int)>> binOps = {
    {"+", plus<int>()},
    {"-", minus<int>()},
    {"*", multiplies<int>()},
    {"/", divides<int>()},
    {"%", modulus<int>()}
};

int main()
{
    int a, b;
    string op;
    cout << "依次输入左端运算数字、运算方式、右端运算数字" << endl;
    cin >> a >> op >> b;
    cout << binOps[op](a, b) << endl;

    return 0;
}
