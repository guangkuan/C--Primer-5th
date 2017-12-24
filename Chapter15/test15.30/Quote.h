#ifndef QUOTE_H_INCLUDED
#define QUOTE_H_INCLUDED
#include <cstddef>
#include <iostream>
#include <string>
#include <utility>

class Quote {
public:
    Quote()=default;
    Quote(const std::string &book, double sales_price) : bookNo(book), price(sales_price) {}
    std::string isbn() const { return bookNo; }
    // return the total sales price for the specified number of items
    // derived class will override and apply different discount algorithms
    virtual double net_price(std::size_t n) const { return n * price; }
    virtual void debug() const;
    // copy control members
    Quote(const Quote &q) : bookNo(q.bookNo), price(q.price) {}
    Quote(Quote &&q) noexcept : bookNo(std::move(q.bookNo)), price(std::move(q.price)) {}
    Quote& operator=(const Quote&);
    Quote& operator=(Quote&&) noexcept;
    virtual ~Quote() = default; // dynamic binding for the destructor
    // virtual function to return a dynamically allocated copy of itself
    // these members use reference qualifiers
    virtual Quote* clone() const & { return new Quote(*this); }
    virtual Quote* clone() && { return new Quote(std::move(*this)); }

private:
    std::string bookNo; // ISBN number of this item

protected:
    double price = 0.0; // normal, undiscounted price
};
// calculate and print the price for the given number of copies, applying any discount
double print_total(std::ostream &os, const Quote &item, std::size_t n)
{
    // depending on the type of the object bound to the item parameter
    // calls either Quote::net_price or Bulk_quote::net_price
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() // calls Quote::isbn
       << " # sold: " << n << " total due: " << ret << std::endl;
    return ret;
}

inline void Quote::debug() const
{
    std::cout << "std::string bookNo\n"
              << "double price\n"
              << std::endl;
}

inline Quote& Quote::operator=(const Quote &rhs)
{
    // self-assignment is safe, we don't need to worry about it
    bookNo = rhs.bookNo;
    price = rhs.price;
    return *this;
}

inline Quote& Quote::operator=(Quote &&rhs) noexcept
{
    if(this != &rhs)
    {
        bookNo = std::move(rhs.bookNo);
        price = std::move(rhs.price);
    }
    return *this;
}

#endif // QUOTE_H_INCLUDED
