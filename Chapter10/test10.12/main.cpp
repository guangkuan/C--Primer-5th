#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "Sales_data.h"

using namespace std;

inline bool compareIsbn(Sales_data &lhs, Sales_data &rhs)
{
    return lhs.isbn() < rhs.isbn();
}

int main(int argc, char *argv[])
{
    if(argc != 2)
        {
            cerr << "请给出文件名" << endl;
            return -1;
        }
        ifstream in(argv[1]);
        if(!in)
        {
            cerr << "无法打开输入文件" << endl;
            return -1;
        }

    vector<Sales_data> sds;
    Sales_data sd;
    while(read(in, sd))
        sds.push_back(sd);

    sort(sds.begin(), sds.end(), compareIsbn);

    for(const auto &s : sds)
    {
        print(cout, s);
        cout << endl;
    }

    return 0;
}
