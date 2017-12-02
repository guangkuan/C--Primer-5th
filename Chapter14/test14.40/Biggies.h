#ifndef BIGGIES_H_INCLUDED
#define BIGGIES_H_INCLUDED
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class IsShoter
{
public:
    bool operator()(const string& s1, const string& s2)
    {
        return s1.size() < s2.size();
    }
};

class NotShorterThan
{
public:
    NotShorterThan(int len): minLen(len) {}
    bool operator()(const string& str)
    {
        return str.size() >= minLen;
    }

private:
    int minLen;
};

class PrintString
{
public:
    void operator()(const string& str)
    {
        cout << str << " ";
    }
};

inline string make_plural(size_t ctr, const string &word, const string &ending)
{
    return (ctr > 1) ? word + ending : word;
}

void elimDups(vector<string> &words)
{
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words);

    IsShoter is;
    stable_sort(words.begin(), words.end(), is);

    NotShorterThan nst(sz);
    auto wc = find_if(words.begin(), words.end(), nst);

    auto count = words.end() - wc;
    cout << count << " " << make_plural(count, "word", "s") << " of length " << sz << " or longer" << endl;

    PrintString ps;
    for_each(wc, words.end(), ps);
    cout << endl;
}

#endif // BIGGIES_H_INCLUDED
