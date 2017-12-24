#ifndef QUOTE_H_INCLUDED
#define QUOTE_H_INCLUDED

using std::cout;
using std::endl;
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

class Disc_quote : public Quote
{
public:
    Disc_quote(const std::string& book = "", double sales_price = 0.0, std::size_t qty = 0, double disc_rate = 0.0): Quote(book, sales_price), quantity(qty), discount(disc_rate) {}
    double net_price(size_t cnt) const = 0;

protected:
    size_t quantity;
    double discount;
};

class Bulk_quote : public Disc_quote
{
public:
    Bulk_quote(const std::string& book = "", double sales_price = 0.0, std::size_t qty = 0, double disc_rate = 0.0): Disc_quote(book, sales_price, qty, disc_rate) {}

    double net_price(size_t cnt) const
    {
        if (cnt > quantity)
            return cnt * (1 - discount) * price;
        else
            return cnt * price;
    }

};

class Limited_quote : public Disc_quote
{
public:
    Limited_quote(const std::string& book = "", double sales_price = 0.0, std::size_t qty = 0, double disc_rate = 0.0): Disc_quote(book, sales_price, qty, disc_rate) {}

    double net_price(size_t cnt) const override
    {
        if (cnt <= quantity)
            return cnt * (1 - discount) * price;
        else
            return quantity * (1 - discount) * price + (cnt - quantity) * price;
    }

};

#endif // QUOTE_H_INCLUDED
