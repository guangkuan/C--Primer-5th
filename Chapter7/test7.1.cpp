#include <iostream>
#include <string>
struct Sales_data
{
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0;
};
int main()
{
	using namespace std;
	Sales_data total;
	if (cin >> total.bookNo >> total.units_sold >> total.revenue)
	{
		Sales_data trans;
		while (cin >> trans.bookNo >> trans.units_sold >> trans.revenue)
		{
			if (total.bookNo == trans.bookNo)
			{
				total.units_sold+=trans.units_sold;
				total.revenue += trans.revenue;
			}
			else
			{
				cout << total.bookNo << "\t" << total.units_sold << "\t" << total.revenue << endl;
				total = trans;
			}
		}
		cout << total.bookNo << "\t" << total.units_sold << "\t" << total.revenue << endl;
	}
	else
	{
		cout << "NO data?!" << endl;
		return -1;
	}
	system("pause");
	return 0;
}
/*#include <iostream>
#include "Sales_data.h"
using namespace std;

int main()
{
    cout << "" << endl;
    Sales_data total;
    if(cin >> total)
    {
        Sales_data trans;
        while(cin >> trans)
        {
            if(total.isbn() == trans.isbn())
                total += trans;
            else
            {
                cout << total << endl;
                total = trans;
            }
        }
        cout << total << endl;
    }
    else
    {
        cerr << "" << endl;
        return -1;
    }
    return 0;
}*/
