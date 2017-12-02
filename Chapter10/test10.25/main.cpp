#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <functional>
#include "make_plural.h"

using namespace std;
using namespace std::placeholders;

bool check_size(const string &s, string::size_type sz)
{
    return s.size() >= sz;
}

void elimDups(vector<string> &words)
{
    sort(words.begin(), words.end());
    auto unique_pos = unique(words.begin(), words.end());
    words.erase(unique_pos, words.end());
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words);
    auto pos = partition(words.begin(), words.end(), bind(check_size, _1, sz));
    auto fuhe = pos - words.begin();
    cout << fuhe << " " << make_plural(fuhe, "word", "s") << "'s length is " << sz << " or longer" << endl;
    for(auto iter = words.begin(); iter != pos; ++iter)
        cout << *iter << " ";
    cout << endl;
}

int main(int argc(), char *argv[])
{
    ifstream in (argv[1]);
    if(!in)
    {
         cout << "打开文件失败 ！" << endl;
         exit(1);
    }

    vector<string> words;
    string word;
    while (in >> word)
        words.push_back(word);
    biggies(words, 6);

    return 0;
}
