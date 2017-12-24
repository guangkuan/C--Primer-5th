#ifndef DISC_QUOTE_H_INCLUDED
#define DISC_QUOTE_H_INCLUDED
#include <cstddef>
#include <iostream>
#include <string>
#include <utility>
#include "Quote.h"

class Disc_quote : public Quote {
public:
    Disc_quote()=default;
    Disc_quote(const std::string &book, double price, std::size_t qty, double disc): Quote(book, price), quantity(qty), discount(disc) {}
    double net_price(std::size_t) const = 0;
    // copy-control members
    Disc_quote(const Disc_quote &dq) : Quote(dq), quantity(dq.quantity), discount(dq.discount) {}
    Disc_quote(Disc_quote &&dq) noexcept : Quote(std::move(dq)), quantity(std::move(dq.quantity)), discount(std::move(dq.discount)) {}
    Disc_quote& operator=(const Disc_quote&);
    Disc_quote& operator=(Disc_quote&&) noexcept;
    ~Disc_quote()=default; // virtual by inheritance

protected:
    std::size_t quantity = 0; // purchase size for the discount to apply
    double discount = 0.0; // fractional discount to apply
};

inline Disc_quote& Disc_quote::operator=(const Disc_quote &rhs)
{
    Quote::operator=(rhs);
    quantity = rhs.quantity;
    discount = rhs.discount;
    return *this;
}

inline Disc_quote& Disc_quote::operator=(Disc_quote &&rhs) noexcept
{
    if(this != &rhs)
    {
        Quote::operator=(std::move(rhs));
        quantity = std::move(rhs.quantity);
        discount = std::move(rhs.discount);
    }
    return *this;
}

#endif // DISC_QUOTE_H_INCLUDED
