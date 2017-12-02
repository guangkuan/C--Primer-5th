#include <iostream>
#include <fstream>
#include <list>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

string &trans(string &s)
{
    for (int p = 0; p < s.size(); p++)
    {
        if(s[p] >= 'A' && s[p] <= 'Z')
            s[p] -= ('A' - 'a');
        else if (s[p] == ',' || s[p] == '.' || s[p] == '(' || s[p] == ')')
                s.erase(p, 1);
    }
    return s;
}
int main(int argc, char *argv[])
{
    ifstream in (argv[1]);
    if (!in)
    {
        cout << "无法打开文件 ！" << endl;
        exit(1);
    }

    map<string, list<int>> cunci;
    string line;
    string word;
    int linenum = 0;
    while (getline(in, line))
    {
        linenum++;
        istringstream cun(line);
        while (cun >> word)
        {
            trans(word);
            cunci[word].push_back(linenum);
        }
    }

    for (const auto &w : cunci)
    {
        cout << w.first << "所在行：";
        for (const auto &i : w.second)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}
