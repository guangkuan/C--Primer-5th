#include <cstddef>
#include <string>
#include <iostream>
#include <unordered_set>
#include <functional>
#include "Sales_data.h"

using std::size_t;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::unordered_multiset;
using std::hash;

Sales_data::Sales_data(std::istream &is): Sales_data()
{
    is >> *this;
}

std::istream& operator>>(std::istream &is, Sales_data &item)
{
    double price = 0.0;
    is >> item.bookNo >> item.units_sold >> price;
    if (is)
        item.revenue = price * item.units_sold;
    else
        item = Sales_data();
    return is;
}

std::ostream& operator<<(std::ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
    return os;
}

Sales_data& Sales_data::operator=(const std::string& isbn)
{
    bookNo = isbn;
    return *this;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum += rhs;
    return sum;
}

Sales_data& Sales_data::operator+=(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

int main()
{
    unordered_multiset<Sales_data> SDset;
    Sales_data item;
    while (cin >> item)
    {
        SDset.insert(item);
    }
    cout << SDset.size() << endl;
    for (auto sd : SDset)
        cout << sd << endl;

    return 0;
}
