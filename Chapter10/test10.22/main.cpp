#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include "make_plural.h"

using namespace std;

inline void output_word(vector<string> &words)
{
    for(auto iter = words.begin(); iter != words.end(); ++iter)
        cout << *iter << " ";
    cout << endl;
}

bool shorter(const string &word)
{
    return word.size() <= 6;
}

void elimDups(vector<string> words)
{
    sort(words.begin(), words.end());
    auto uninque_pos = unique(words.begin(), words.end());
    words.erase(uninque_pos, words.end());
}

void huafen(vector<string> &words, vector<string>::size_type sz)
{
    output_word(words);
    elimDups(words);
    auto wz = count_if(words.begin(), words.end(), shorter);
    cout << wz << " " << make_plural(wz, "word", "s") << "'s length is " << sz << " or shorter" << endl;
}

int main(int argc, char *argv[])
{
    ifstream in (argv[1]);
    if(!in)
    {
        cout << "打开文件失败！" << endl;
        exit(1);
    }

    vector<string> words;
    string word;
    while (in >> word)
        words.push_back(word);
    huafen(words, 6);

    return 0;
}
