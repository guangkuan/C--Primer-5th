#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string &trans(string &word)
{
    for (int p = 0; p < word.size(); p++)/*输入单词标点要用空格隔开才能看出效果。。。。*/
    {
        if (word[p] >= 'A' && word[p] <= 'Z')
        word[p] -= ('A' - 'a');
        else if (word[p] == ',' || word[p] == '.' || word[p] == '(' || word[p] == ')')
        word.erase(p, 1);
    }
    return word;
}
int main(int argc, char *argv[])
{
    ifstream in(argv[1]);
    if (!in)
    {
        cout << "文件无法打开 ！" << endl;
        exit(1);
    }

    vector<string> unique_words;
    string word;
    while(in >> word)
    {
        trans(word);
        if (find(unique_words.begin(), unique_words.end(), word) == unique_words.end())
            unique_words.push_back(word);
    }

    for (const auto &w : unique_words)
        cout << w << " ";
    cout << endl;

    return 0;
}
