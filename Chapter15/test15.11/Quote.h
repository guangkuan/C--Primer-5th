#ifndef QUOTE_H_INCLUDED
#define QUOTE_H_INCLUDED
#include <string>

using std::cout;
using std::endl;
class Quote
{
public:
    Quote() = default;
    Quote(const std::string& book, double sales_price): bookNo(book), price(sales_price) {}
    std::string isbn() const { return bookNo; }
    virtual double net_price(std::size_t n) const { return n * price; }
    virtual void debug()
    {
        cout << "bookNo = " << bookNo << " price = " << price << endl;
    }
    virtual ~Quote() = default;

private:
    std::string bookNo;

protected:
    double price = 0.0;
};

class Bulk_quote : public Quote
{
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string& book = "", double sales_price = 0, std::size_t qty = 0, double disc_rate = 0): Quote(book, sales_price), min_qty(qty), discount(disc_rate) { }

    double net_price(size_t cnt) const
    {
        if (cnt > min_qty)
            return cnt * (1 - discount) * price;
        else
            return cnt * price;
    }

    virtual void debug()
    {
        Quote::debug();//»Ø±ÜÐéº¯Êý
        cout << "min_qty = " << min_qty << " discount = " << discount << endl;
    }

private:
    size_t min_qty;
    double discount;

};

//class Limited_quote : public Quote
//{
//public:
//    Limited_quote() = default;
//    Limited_quote(const std::string& book, double sales_price, std::size_t qty, double disc): Quote(book, sales_price), min_qty(qty), discount(disc) { }
//
//    double net_price(size_t cnt) const override
//    {
//        if (cnt <= min_qty)
//            return cnt * (1 - discount) * price;
//        else
//            return min_qty * (1 - discount) * price + (cnt - min_qty) * price;
//    }
//
//private:
//    size_t min_qty = 0;
//    double discount = 0.0;
//};

#endif // QUOTE_H_INCLUDED
