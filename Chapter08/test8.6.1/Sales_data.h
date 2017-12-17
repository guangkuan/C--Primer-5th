#ifndef SALES_DATA_H_INCLUDED
#define SALES_DATA_H_INCLUDED
#include <iostream>
#include <string>

struct Sales_data
{									//Ä¬ÈÏÊÇprivate
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0;

	friend std::istream &read(std::istream &is, Sales_data &s);
	friend std::ostream &print(std::ostream &os, const Sales_data &s);
	friend Sales_data add(Sales_data s1, const Sales_data &s2);
public:
	Sales_data() = default;
	Sales_data(const std::string &s) :bookNo(s){}
	Sales_data(const std::string &s, unsigned n, double p) :bookNo(s), units_sold(n), revenue(n*p){}
	Sales_data(std::istream &is)
	{
		read(is, *this);
	}
	std::string isbn() const { return bookNo; }
	Sales_data &combine(const Sales_data &s);
	double avg_price() const;
};
Sales_data &Sales_data::combine(const Sales_data &rhs){
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}
double Sales_data::avg_price()const{
	if (units_sold)
		return revenue / units_sold;
	else
		return 0;
}
std::istream &read(std::istream &is, Sales_data &s)
{
	double price = 0.0;
	is >> s.bookNo >> s.units_sold >> price;
	s.revenue = price * s.units_sold;
	return is;
}
std::ostream &print(std::ostream &os, const Sales_data &s)
{
	os << s.bookNo << "\t" << s.units_sold << "\t" \
	<< s.revenue << "\t" << s.avg_price() << std::endl;
	return os;
}
Sales_data add(const Sales_data lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

#endif // SALES_DATA_H_INCLUDED
