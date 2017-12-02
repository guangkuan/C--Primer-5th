#ifndef SALES_DATA_H_INCLUDED
#define SALES_DATA_H_INCLUDED
#include <string>
struct Sales_data
{
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0;

	std::string isbn(){ return bookNo; }
	Sales_data &combine(Sales_data &s);
	double avg_price()const;
};
Sales_data &Sales_data::combine(Sales_data &s)
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

#endif // SALES_DATA_H_INCLUDED
