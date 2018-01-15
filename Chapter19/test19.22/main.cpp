#include <iostream>
#include "Sales_data.h"
#include "Token.h"

using namespace std;

int main()
{
    string s = "this is a string";
    Sales_data item("978-7-121-20038-0", 12, 128.0);
    int i = 12;
    char c = 'c';
    double d = 1.28;

    Token tkn;
    tkn = i;
    cout << tkn << endl;
    tkn = c;
    cout << tkn << endl;
    tkn = d;
    cout << tkn << endl;
    tkn = s;
    cout << tkn << endl;
    tkn = item;
    cout << tkn << endl << endl;

    Token tkn2 = tkn;
    cout << tkn2 << endl;
    tkn2 = s;
    cout << tkn2 << endl;
    tkn2 = tkn;
    cout << tkn2 << endl;
    tkn2 = c;
    cout << tkn2 << endl;

    //²âÊÔÒÆ¶¯¹¹Ôì£¬¿½±´

    return 0;
}
