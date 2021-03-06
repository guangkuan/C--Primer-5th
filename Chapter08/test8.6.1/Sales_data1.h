#ifndef SALES_DATA1_H_INCLUDED
#define SALES_DATA1_H_INCLUDED
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class Sales_data{
public:
    friend istream &read(istream &, Sales_data &);//一个友元函数read,便于Sales_data类直接访问
    friend ostream &print(ostream &os, const Sales_data &item);
    Sales_data() = default;//默认构造函数
    Sales_data(const std::string &s) : bookNo(s){ }
    Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p*n){ }
    Sales_data(std::istream &is){
        read(is,*this);
    }


    string isbn() const {return bookNo;}
    Sales_data& combine(const Sales_data&);
    double avg_price() const;

private:
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);

double Sales_data::avg_price() const{
    if (units_sold)
        return revenue/units_sold;
    else
        return 0;
}

Sales_data& Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

istream &read(istream &is, Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

ostream &print(ostream &os, const Sales_data &item){
    os << item.isbn() << " " << item.units_sold << " "
       << item.revenue << " " << item.avg_price();
    return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs){
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

/*
Sales_data::Sales_data(std::istream &is)
{
    read(is,*this);
}
*/

#endif // SALES_DATA1_H_INCLUDED
