#include "Sales_data.h"
#include <iostream>

std::istream &read(std::istream &is, Sales_data &s);
std::ostream &print(std::ostream &os, const Sales_data &s);
int main()
{
	using namespace std;
	Sales_data total;
	if (read(cin, total))
	{
		Sales_data trans;
		while (read(cin, trans))
		{
			if (total.isbn() == trans.isbn())
				total.combine(trans);
			else
			{
				print(cout, total);
				total = trans;
			}
		}
		print(cout, total) << endl;
	}
	else
	{
		cerr << "No data?!" << endl;
		return -1;
	}
	system("pause");
	return 0;
}
std::istream &read(std::istream &is, Sales_data &s)
{
	is >> s.bookNo >> s.units_sold >> s.revenue;
	return is;
}
std::ostream &print(std::ostream &os, const Sales_data &s)
{
	os << s.bookNo << "\t" << s.units_sold << "\t" << s.revenue << std::endl;
	return os;
}
