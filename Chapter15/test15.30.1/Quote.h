#ifndef QUOTE_H_INCLUDED
#define QUOTE_H_INCLUDED
#include <iostream>
#include <string>

using namespace std;

class Quote
{
public:
    Quote() = default;
    Quote(const std::string& book, double sales_price): bookNo(book), price(sales_price) {}
    std::string isbn() const { return bookNo; }
    virtual double net_price(std::size_t n) const { return n * price; }
    virtual ~Quote() = default;
    //double print_total(ostream &, const Quote&, size_t);

private:
    std::string bookNo;

protected:
    double price = 0.0;
};

double print_total(ostream &os, const Quote& item, size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN" << item.isbn() << " # sold: " << n << "total due: " << ret << endl;
    return ret;
}

class Bulk_quote : public Quote
{
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string& book, double sales_price, std::size_t qty, double disc): Quote(book, sales_price), min_qty(qty), discount(disc) { }

    double net_price(size_t cnt) const override
    {
        if (cnt >= min_qty)
            return cnt * (1 - discount) * price;
        else
            return cnt * price;
    }

private:
    size_t min_qty = 0;
    double discount = 0.0;

};

class Limited_quote : public Quote
{
public:
    Limited_quote() = default;
    Limited_quote(const std::string& book, double sales_price, std::size_t qty, double disc): Quote(book, sales_price), min_qty(qty), discount(disc) { }

    double net_price(size_t cnt) const override
    {
        if (cnt <= min_qty)
            return cnt * (1 - discount) * price;
        else
            return min_qty * (1 - discount) * price + (cnt - min_qty) * price;
    }

private:
    size_t min_qty = 0;
    double discount = 0.0;
};

#endif // QUOTE_H_INCLUDED
