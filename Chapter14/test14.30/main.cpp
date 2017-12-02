#include <iostream>
#include "ConstStrBlobPtr.h"

using namespace std;

int main()
{
    const StrBlob b = { "WORLD", "of", "WARCRAFT" };
    for (auto it = b.begin(); neq(it, b.end()); it.incr())
        cout << it.deref() << endl;

    return 0;
}
