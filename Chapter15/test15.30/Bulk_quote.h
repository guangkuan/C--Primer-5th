#ifndef BULK_QUOTE_H_INCLUDED
#define BULK_QUOTE_H_INCLUDED
#include <cstddef>
#include <iostream>
#include <string>
#include "Disc_quote.h"

class Bulk_quote : public Disc_quote { // Bulk_quote inherits from Quote
public:
    // inherited constructor
    using Disc_quote::Disc_quote;
    Bulk_quote()=default;
    // overrides the base version in order to implement the bulk purchase discount policy
    double net_price(std::size_t) const override;
    void debug() const override;
    // copy-control members
    Bulk_quote(const Bulk_quote &bq) : Disc_quote(bq) {}
    Bulk_quote(Bulk_quote &&bq) noexcept : Disc_quote(std::move(bq)) {}
    Bulk_quote& operator=(const Bulk_quote&);
    Bulk_quote& operator=(Bulk_quote&&) noexcept;
    ~Bulk_quote()=default; // virtual by inheritance
    virtual Bulk_quote* clone() const & { return new Bulk_quote(*this); }
    virtual Bulk_quote* clone() && { return new Bulk_quote(std::move(*this)); }
};
// if the specified number of items are purchased, use the discounted price
double Bulk_quote::net_price(std::size_t cnt) const
{
    if (cnt >= quantity)
        return cnt * (1 - discount) * price;
    else
        return cnt * price;
}

inline void Bulk_quote::debug() const
{
    std::cout << "std::string bookNo\n"
              << "double price\n"
              << "std::size_t min_qty\n"
              << "double discount\n"
              << std::endl;
}

inline Bulk_quote& Bulk_quote::operator=(const Bulk_quote &rhs)
{
    Disc_quote::operator=(rhs);
    return *this;
}

inline Bulk_quote& Bulk_quote::operator=(Bulk_quote &&rhs) noexcept
{
    if(this != &rhs)
        Disc_quote::operator=(std::move(rhs));
    return *this;
}

#endif // BULK_QUOTE_H_INCLUDED
