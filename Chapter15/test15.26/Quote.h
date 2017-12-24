#ifndef QUOTE_H_INCLUDED
#define QUOTE_H_INCLUDED
#include <string>
#include <iostream>

using namespace std;

class Quote
{
public:
    friend ostream &operator<<(ostream&, Quote&);

    Quote() = default;
    Quote(const std::string& book = "", double sales_price = 0.0): bookNo(book), price(sales_price)
    {
        cout << "Quote constructor is running" << endl;
    }
    virtual ~Quote()
    {
        cout << "Quote destructor is running" << endl;
    }

    std::string isbn() const { return bookNo; }
    virtual double net_price(std::size_t n) const { return n * price; }
    virtual void debug()
    {
        cout << "bookNo = " << bookNo << " price = " << price << endl;
    }

private:
    std::string bookNo;

protected:
    double price = 0.0;
};

ostream& operator<<(ostream& os, Quote& q)
{
    os << "\tUsing operator << (ostream&, Quote&);" << endl;
    return os;
}

class Bulk_quote : public Quote
{
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string& book = "", double sales_price = 0.0, std::size_t qty = 0, double disc = 0.0): Quote(book, sales_price), min_qty(qty), discount(disc)
    {
        cout << "Bulk_constructor is running" << endl;
    }
    ~Bulk_quote()
    {
        cout << "Bulk_quote destructor is running" << endl;
    }

    double net_price(size_t cnt) const
    {
        if (cnt > min_qty)
            return cnt * (1 - discount) * price;
        else
            return cnt * price;
    }

private:
    size_t min_qty;
    double discount;
};

ostream& operator<<(ostream& os, Bulk_quote& bq)
{
    os << "\tUsing operator<<(ostream&, Bulk_quote&)" << endl;
    return os;
}

#endif // QUOTE_H_INCLUDED
