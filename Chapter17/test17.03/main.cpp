#include <iostream>
#include <fstream>
#include <string>
#include "my_TextQuery.h"

using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::string;

void runQueries(ifstream &infile)
{
    TextQuery tq(infile);
    while(true)
    {
        cout << "enter word to look for, or q to quit: ";
        string s;
        if(!(cin >> s) || s == "q")
            break;
        print(cout, tq.query(s)) << endl;
    }
}

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        cout << "文件无法打开！" << endl;
        return -1;
    }

    ifstream infile(argv[1]);
    runQueries(infile);
    return 0;
}
