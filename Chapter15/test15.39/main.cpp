#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "my_TextQuery.h"
#include "my_Query_base.h"

using namespace std;

void runQueries(ifstream& infile)
{
    TextQuery tq(infile);
    while (true)
    {
        cout << "Enter word to look for, or q to quit: ";
        string s;
        if (!(cin >> s) || s == "q")
            break;
        print(cout, tq.query(s)) << endl;
    }
}

//int main()
//{
//    std::ifstream file("fanwen.txt");
//    TextQuery tQuery(file);
//    Query q = Query("fieryzzz")  | Query("wind");
//    cout << q.eval(tQuery);
//    return 0;
//}

int main()
{
    ifstream file("fanwen.txt");
    TextQuery tQuery(file);
    Query q = Query("hair") | Query("Alice");
    print(cout, q.eval(tQuery));
    return 0;
}
