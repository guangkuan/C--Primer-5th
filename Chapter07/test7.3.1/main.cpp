#include <iostream>
#include "Sales_data.h"

using namespace std;

int main()
{
    cout << "�����뽻�׼�¼��ISBN��������ԭ�ۡ�ʵ���ۼۣ��� " << endl;
    Sales_data total;
    if(cin >> total.bookNo >> total.units_sold >> total.sellingprice >> total.saleprice)
    {
        Sales_data trans;
        while(cin >> trans.bookNo >> trans.units_sold >> trans.sellingprice >> trans.saleprice)
        {
            if(total.isbn() == trans.isbn())
                total.combine(trans);
            else
            {
                cout << total.bookNo << " " << total.units_sold << " "
                << total.sellingprice << " " << total.saleprice << " " << total.discount << endl;
                total = trans;
            }
        }
        cout << total.bookNo << " " << total.units_sold << " "
                << total.sellingprice << " " << total.saleprice << " " << total.discount << endl;
    }
    else
    {
        cerr << "No data?!" << endl;
        return -1;
    }

    return 0;
}
