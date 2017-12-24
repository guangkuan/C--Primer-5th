#include <iostream>
#include <string>
#include "sp_Blob.h"

using std::cout;
using std::endl;
using std::string;

int main()
{
    vector<string> vs = { "Hello", "World", "!" };
    Blob<string> b3(vs.begin(), vs.end());
    cout << b3.size() << endl;
    for (size_t i = 0; i < b3.size(); ++i)
        cout << b3.at(i) << " ";
    cout << endl << endl;

    string as[3] = { "This", "is", "end" };
    Blob<string> b4(as, as + 3);
    cout << b4.size() << endl;
    for (size_t i = 0; i < b4.size(); ++i)
        cout << b4.at(i) << " ";
    cout << endl << endl;

    return 0;
}
