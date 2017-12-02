#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

string &trans(string &s)
{
    for (int p = 0; p < s.size(); p++)
    {
        if (s[p] >= 'A' && s[p] <= 'Z')
            s[p] -= ('A' - 'a');
        else if (s[p] == ',' || s[p] == '.' || s[p] == '(' || s[p] == ')')
            s.erase(p, 1);
        return s;
    }
}

int main(int argc, char *argv[])
{
    ifstream in (argv[1]);
    if (!in)
    {
        cout << "文件无法打开 ！" << endl;
        exit(1);
    }

    string word;
    map<string, size_t> word_count;
    while (in >> word)
    {
        trans(word);
        auto ret = word_count.insert({word, 1});
        if (!ret.second)
            ++ret.first->second;
    }

    for (const auto &w : word_count)
        cout << w.first << " 出现了 " << w.second << "次" << endl;

    return 0;
}
