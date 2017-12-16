#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    const int sz = 10;
    int a[sz];
    srand((unsigned) time (NULL));
    cout << "Show the strings" << endl;
    for(auto &val : a)
    {
        val = rand() % 100;
        cout << val << " ";
    }
    cout << endl;
    vector<int> vInt(begin(a),end(a));
    cout << "the numebers in vector are" << endl;
    for(auto val : vInt)
        cout << val << " ";
    cout << endl;

    return 0;
}
