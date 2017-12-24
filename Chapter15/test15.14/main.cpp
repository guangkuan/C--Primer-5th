#include <iostream>
#include "base.h"

using namespace std;

int main()
{
    base bobj("abc");
    derived dobj("def", 2);
    base* bp1 = &bobj;
    base* bp2 = &dobj;
    base& br1 = bobj;
    base& br2 = dobj;

    bobj.print(cout);
    dobj.print(cout);
    bp1->name();
    bp2->name();
    br1.print(cout);
    br2.print(cout);

    return 0;
}
