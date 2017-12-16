#ifndef SALES_DATA_H_INCLUDED
#define SALES_DATA_H_INCLUDED
#include <iostream>
#include <string>

struct Sales_data
{									//Ä¬ÈÏÊÇprivate
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;

public:
	Sales_data() = default;
	Sales_data(const std::string &s) :bookNo(s){}
	Sales_data(const std::string &s, unsigned n, double p) :bookNo(s), units_sold(n), revenue(n*p){}
	std::string isbn(){ return bookNo; }
	Sales_data &combine(const Sales_data &s);
	double avg_price()const;
};
Sales_data &Sales_data::combine(const Sales_data &s)
{
	units_sold += s.units_sold;
	revenue += s.revenue;
	return *this;
}
double Sales_data::avg_price()const
{
	if (units_sold)
		return revenue / units_sold;
	else
		return 0;
}
Sales_data add(Sales_data s1, const Sales_data &s2)
{
	s1.combine(s2);
	return s1;
}

#endif // SALES_DATA_H_INCLUDED
