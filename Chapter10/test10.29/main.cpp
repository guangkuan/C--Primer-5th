#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

int main(int argc(), char *argv[])
{
    ifstream in (argv[1]);
    if(!in)
    {
        cout << "打开文件失败！" << endl;
        exit(1);
    }

    istream_iterator<string> in_iter(in), eof;
    vector<string> words(in_iter, eof);
    /*vector<string> words;
    while(in_iter != eof)
        words.push_back(*(++in_iter));*/

    for(auto word : words)
        cout << word << " ";
    cout << endl;

    return 0;
}
