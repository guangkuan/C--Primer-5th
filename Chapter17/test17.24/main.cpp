#include <iostream>
#include <fstream>
#include <string>
#include <regex>

using std::cout;
using std::endl;
using std::cerr;
using std::ifstream;
using std::string;
using std::regex;
using std::smatch;

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        cerr << "请给出文件名" << endl;
        return -1;
    }
    ifstream cin(argv[1]);
    if(!cin)
    {
        cerr << "无法打开输入文件" << endl;
        return -1;
    }

    string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
    regex r(phone);
    smatch m;
    string s;
    string fmt = "$2.$5.$7";

    while (getline(cin, s))
        cout << regex_replace(s, r, fmt) << endl;

    return 0;
}
