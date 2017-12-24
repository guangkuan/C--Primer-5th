#include <iostream>
#include "Quote.h"

using namespace std;

int main()
{
    Quote base("C++ Primer", 128.0);
    Bulk_quote bulk("Core Python Programming", 89, 5, 0.19);
    cout << base << endl;
    cout << bulk << endl;

    return 0;
}
