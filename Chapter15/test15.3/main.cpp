#include <iostream>
#include "Quote.h"

using namespace std;

double print_total(ostream& os, const Quote& item, size_t n)
{
    double ret = item.net_price(n);
    os << "ISN: " << item.isbn() << " # sold: " << n << " total due: " << ret << endl;
    return ret;
}

int main()
{
    Quote basic("abc", 5.5);
    Bulk_quote bulk("abc", 5.5, 10, 0.2);
    Quote* pQuote = &bulk;
    Quote& rQuote = bulk;
    print_total(cout, basic, 20);
    print_total(cout, bulk, 20);
    print_total(cout, *pQuote, 20);
    print_total(cout, rQuote, 20);
    return 0;
}
