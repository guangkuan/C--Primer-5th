#include <iostream>
#include <string>
using namespace std;

class Sales_data
{
    friend std::istream &read(std::istream &is,Sales_data &item);
    friend std::ostream &print(std::ostream &os,const Sales_data &item);
public:
    Sales_data(const string &book,unsigned num,double sellp,double salep)
    :bookNo(book),units_sold(num),sellingprice(sellp),saleprice(salep)
    {
        if(sellingprice)
            discount = saleprice / sellingprice;
        cout << "�ù��캯���������:"  << book << " ������:"
        << num << " ԭ��:" << sellp << " ʵ���ۼ��ĸ���Ϣ:" << salep <<endl;
    }
    Sales_data() : Sales_data(" ",0,0,0)
    {
        cout << "�ù��캯����������κ���Ϣ" << endl;
    }
    Sales_data(const string &book) : Sales_data(book,0,0,0)
    {
        cout << "�ù��캯�����������Ϣ" << endl;
    }
    Sales_data(std::istream &is) : Sales_data("terrible book") /*�ȷ��أ��Ҳ�Ĺ��캯����ִ�����������Ĺ��캯��*/
    {
        read(is,*this);
        cout << "�ù��캯�������û��������Ϣ" << endl;
    }
private:
    std::string bookNo;
    unsigned units_sold = 0;
    double sellingprice = 0.0;
    double saleprice = 0.0;
    double discount = 0.0;
};

std::istream &read(std::istream &is,Sales_data &item)
{
    is >> item.bookNo >> item.units_sold >> item.sellingprice >> item.saleprice;
    return is;
}

std::ostream &print(std::ostream &os,const Sales_data &item)
{
    os << item.bookNo << " " << item.units_sold << " " << item.sellingprice
    << " " << item.saleprice << " " << item.discount;
    return os;
}

int main()
{
    Sales_data first("978-7-121-15535-2",85,128,109);
    Sales_data second;
    Sales_data third("666-7-121-66666-2");
    Sales_data last(cin);

    return 0;
}
