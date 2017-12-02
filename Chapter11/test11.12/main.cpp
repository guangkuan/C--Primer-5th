#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
    ifstream in (argv[1]);
    if (!in)
    {
        cout << "文件无法打开 ！" << endl;
        exit(1);
    }

    string word;
    int a;
    vector<pair<string, int>> vp;
    while (in >> word && in >> a)
        vp.push_back(pair<string, int>(word, a));

    for (const auto &d : vp)
        cout << d.first << " " << d.second << endl;

    return 0;
}
