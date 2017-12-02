#include <iostream>
#include <vector>
#include "ReadString.h"

using namespace std;

void ReadString::testReadString()
{
    ReadString rs;
    vector<string> vec;
    while (true)
    {
        string line = rs();
        if (!line.empty())
        {
            vec.push_back(line);
        }
        else
        {
            break;
        }
    }
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
