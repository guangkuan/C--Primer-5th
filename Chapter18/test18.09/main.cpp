#include "Sales_data.h"
#include <stdexcept>

class out_of_stock: public std::runtime_error
{
public:
    explicit out_of_stock(const std::string& s): std::runtime_error(s) {}
};

class isbn_mismatch: public std::logic_error
{
public:
    explicit isbn_mismatch(const std::string& s): std::logic_error(s) {}
    isbn_mismatch(const std::string& s, const std::string& lhs, const std::string& rhs): std::logic_error(s), left(lhs), right(rhs) {}
    const std::string left, right;
};

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

Sales_data& Sales_data::operator-=(const Sales_data& rhs)
{
    if (isbn() != rhs.isbn())
        throw isbn_mismatch("wrong isbns", isbn(), rhs.isbn());
    units_sold -= rhs.units_sold;
    revenue -= rhs.revenue;
    return *this;
}


int main()
{
    Sales_data item1, item2, sum;
    while (std::cin >> item1 >> item2)
    {
        try
        {
            sum = item1 + item2;
            std::cout << sum << std::endl;
        }
        catch (const isbn_mismatch& e)
        {
            std::cerr << e.what() << ": left isbn(" << e.left << ") right isbn(" << e.right << ")" << std::endl;
        }
    }

//    //不处理异常
//    Sales_data item1, item2, sum;
//    while (cin >> item1 >> item2)
//    {
//        sum = item1 + item2;
//        return sum;
//    }
}
