#include <iostream>
#include <memory>
#include "DebugDelete.h"

using namespace std;

int main()
{
    double* p = new double;
    DebugDelete d;
    d(p);

    int* ip = new int;
    DebugDelete()(ip);

    unique_ptr<int, DebugDelete> uip(new int, DebugDelete());
    unique_ptr<string, DebugDelete> usp(new string, DebugDelete());

    return 0;
}
