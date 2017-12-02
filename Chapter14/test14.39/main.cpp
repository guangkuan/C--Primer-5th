#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class StrLenBetween
{
public:
    StrLenBetween(size_t minLen, size_t maxLen): minLen(minLen), maxLen(maxLen) {}
    bool operator()(const string& str) { return str.length() >= minLen && str.length() <= maxLen; }

private:
    size_t minLen;
    size_t maxLen;
};

class StrNotShorterThan
{
public:
    StrNotShorterThan(size_t len): minLen(len) {}
    bool operator()(const string& str) { return str.length() >= minLen; }

private:
    size_t minLen;
};

void readStr(istream& is, vector<string>& vec)
{
    string word;
    while (is >> word)
    {
        vec.push_back(word);
    }
}

int main()
{
    vector<string> vec;
    readStr(cin, vec);

    StrLenBetween slenBetween(1, 9);
    StrNotShorterThan sNotShorterThan(10);
    cout << "len 1~9: " << count_if(vec.begin(), vec.end(), slenBetween) << endl;
    cout << "len >= 10: " << count_if(vec.begin(), vec.end(), sNotShorterThan) << endl;

    return 0;
}
