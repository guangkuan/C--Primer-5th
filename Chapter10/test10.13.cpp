#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool huafen(const string &s1)
{
    if(s1.size() >= 5)
        return true;
    else
        return false;
}

int main()
{
    string s;
    vector<string> vString;
    while(getline(cin, s))
        vString.push_back(s);
    auto iter1 = partition(vString.begin(), vString.end(), huafen);
    for(auto iter = vString.begin(); iter != iter1; ++iter)
        cout << *iter << " " ;
    cout << endl;

    return 0;
}


/*#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

inline void output_words(vector<string>::iterator beg, vector<string>::iterator end)
{
    for(auto iter = beg; iter != end; ++iter)
        cout << *iter << " ";
    cout << endl;
}

bool five_or_more(const string &s1)
{
    return s1.size() >= 5;
}

int main()
{
    vector<string> words;
    string word;
    while(cin >> word)
        words.push_back(word);
    cout << "输入的所有字符串为：" << endl;
    output_words(words.begin(), words.end());

    auto iter = partition(words.begin(), words.end(), five_or_more);
    cout << "长度超出5的字符串有：" << endl;
    output_words(words.begin(), iter);

    return 0;
}*/
