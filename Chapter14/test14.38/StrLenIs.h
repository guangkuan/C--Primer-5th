#ifndef STRLENIS_H_INCLUDED
#define STRLENIS_H_INCLUDED
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class StrLenIs
{
public:
    StrLenIs(int len): len(len) {}
    bool operator()(const string& str) { return str.length() == len; }

private:
    int len;
};

void readStr(istream& is, vector<string>& vec)
{
    string word;
    while (is >> word)
    {
        vec.push_back(word);
    }
}

#endif // STRLENIS_H_INCLUDED
