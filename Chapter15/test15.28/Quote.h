#ifndef QUOTE_H_INCLUDED
#define QUOTE_H_INCLUDED
#include <string>

class Quote
{
public:
    Quote() = default;
    Quote(const std::string& book = "", double sales_price = 0.0): bookNo(book), price(sales_price) {}
    std::string isbn() const { return bookNo; }
    virtual double net_price(std::size_t n) const { return n * price; }
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
    Bulk_quote(const std::string& book = "", double sales_price = 0.0, std::size_t qty = 0, double disc = 0.0): Quote(book, sales_price), min_qty(qty), discount(disc) { }

    double net_price(size_t cnt) const override
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



#endif // QUOTE_H_INCLUDED
